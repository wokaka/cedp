/**
	* AliasAnalysis pass performs a conservative flow-insensitive alias
	* analysis for the whole program.
  * It scans the program and creates an alias_map for a program
  * that contains a <Symbol, Set<Symbol>> pair. 
	*/ 

package cetus.analysis;

import java.util.*;
import cetus.hir.*;
import cetus.exec.*;

/**
	* This analysis pass performs flow-insensitive anlias analysis 
	* and creates an alias map for the program.
	*/

public class AliasAnalysis extends AnalysisPass
{
	private int debug_level;
	private boolean no_alias = false;

	private int alias_level;
	private static final int ARGUMENT_ALIAS = 1;
	private static final int ARGUMENT_NO_ALIAS = 2;
	private static final int ARGUMENT_NO_ALIAS_GLOBAL = 3;

	/**
		* A symbol to alias set map
		*/
	private Map<Symbol, HashSet<Symbol>> alias_map;

//	private boolean everything_is_aliased;

	private Set<Symbol> all_aliased_set;

	private HashSet<Symbol> all_set;

	public AliasAnalysis(Program program)
	{
		super(program);
		alias_map = new HashMap<Symbol, HashSet<Symbol>>();
		all_aliased_set = new HashSet<Symbol>();
		debug_level = Integer.valueOf(Driver.getOptionValue("verbosity")).intValue();
		all_set = new HashSet<Symbol>();
		all_set.add(null);

		if ( Driver.getOptionValue("no-alias") != null )
		{
			no_alias = true;
		}
//		everything_is_aliased = false;

		if ( Driver.getOptionValue("argument-noalias") != null )
			alias_level = ARGUMENT_NO_ALIAS;
		else if ( Driver.getOptionValue("argument-noalias-global") != null )
			alias_level = ARGUMENT_NO_ALIAS_GLOBAL;
		else // DEFAULT
			alias_level = ARGUMENT_ALIAS;
	}

	public String getPassName() { return new String("[AliasAnalysis]"); }

	public void start()
	{
		if (no_alias) return;

		if (debug_level > 1) System.out.println("[AliasAnalysis] Start");

		DepthFirstIterator iter = new DepthFirstIterator(program);

		while(iter.hasNext())
		{
			Object obj = iter.next();

			if (obj instanceof AssignmentExpression)
			{
				AssignmentExpression assign_expr = (AssignmentExpression)obj;

				/*
					change it to getDefSet()
					Set<Expression> defSet = Tools.getDefSet(assign_expr);
				 */
				Expression lhs_expr = assign_expr.getLHS();
				Expression rhs_expr = assign_expr.getRHS();
				Symbol lhs_symbol = Tools.getSymbolOf(lhs_expr);

				if (debug_level > 2) System.out.println("lhs:" + lhs_expr.toString());
				/**
					* If lhs is a pointer type and rhs is either pointer type or array type,
					* add this assignment expression into the alias map
					*/
				if (Tools.isPointer(lhs_expr))
				{
					{
						if (lhs_symbol == null)
							System.out.println("lhs symbol null: " + assign_expr.toString());

						boolean pointer_arithmetic = true;

						Symbol rhs_symbol;
						Expression my_rhs_expr = rhs_expr;
						if (rhs_expr instanceof UnaryExpression)		// check for "p = &x;"
						{
							if (((UnaryExpression)rhs_expr).getOperator() == UnaryOperator.ADDRESS_OF)
							{
								my_rhs_expr = ((UnaryExpression)rhs_expr).getExpression();
								rhs_symbol = Tools.getSymbolOf(my_rhs_expr);
								if (rhs_symbol == null)
								{
									Tools.print("\n[AliasAnalysis] Cannot find symbol in: ", 1);
									Tools.println(assign_expr.toString(), 1);
								}
								else
								{	
									add_this_alias_pair(lhs_symbol, rhs_symbol);
									pointer_arithmetic = false;
								}
							}
						}
						else 
						{
							if (rhs_expr instanceof Typecast)		// remove Typecast
							{
								List<Traversable> list = rhs_expr.getChildren();
								my_rhs_expr = (Expression)list.get(0);			
							}
	
							if (isFunctionCall(my_rhs_expr))
							{
								FunctionCall fcall = (FunctionCall)my_rhs_expr;
								if (isMallocCall(fcall))
								{
									pointer_arithmetic = false;
								}
								else 	
								{
									Set<Symbol> return_symbols = Tools.getSideEffectSymbols(fcall);
									for (Symbol r_symbol : return_symbols)
									{
										add_this_alias_pair(lhs_symbol, r_symbol);
									}
									pointer_arithmetic = false;
								}
							}
							else if (isNull(my_rhs_expr))		
							{ // p = NULL; --> p = (void *)0; after preprocessing
								pointer_arithmetic = false;
							}
							else
							{
								rhs_symbol = Tools.getSymbolOf(my_rhs_expr);
								if (rhs_symbol != null)
								{	
									if (Tools.isPointer(rhs_symbol) || Tools.isArray(rhs_symbol))
									{
										add_this_alias_pair(lhs_symbol, rhs_symbol);
										pointer_arithmetic = false;
									}
								}
							}
						}

						if (pointer_arithmetic)
						{
							if (debug_level > 0) {
								System.out.println("\nPointer Arithmetic! :" + assign_expr.toString());
								System.out.println("  (LHS: " + lhs_expr.getClass().getName() + ")");
								System.out.println("  (RHS: " + rhs_expr.getClass().getName() + ")");
							}
							all_aliased_set.add(lhs_symbol);
						}
					}
				}
			}
		}

		/* Adding conservative inter-procedural alias analysis depending on the level of alias information
		 * demanded by the user via command line
		 * ARGUMENT_ALIAS = Arguments(parameters) may alias each other and may alias global storage
		 * ARGUMENT_NO_ALIAS = Arguments(parameters) do not alias each other but may alias global storage
		 * ARGUMENT_NO_ALIAS_GLOBAL = Arguments(parameters) do no alias each other and do not alias global storage
		 */
		if (alias_level != ARGUMENT_NO_ALIAS_GLOBAL) {
			DepthFirstIterator bfs_iter = new DepthFirstIterator(program);
			bfs_iter.pruneOn(Procedure.class);
			while ( bfs_iter.hasNext() )
			{
				Object o = bfs_iter.next();
				if ( o instanceof Procedure )
				{
					Procedure proc = (Procedure)o;
					List<Declaration> parameters = proc.getParameters();
					HashSet<Symbol> parameter_symbols = new HashSet<Symbol>();
					for (Declaration d : parameters) {
						DepthFirstIterator dfs_iter = new DepthFirstIterator(d);
						while(dfs_iter.hasNext())
						{
							Object o1 = dfs_iter.next();
							if ( o1 instanceof Symbol && 
								(Tools.isPointer((Symbol)o1) ||
								 Tools.isArray((Symbol)o1)) )
								parameter_symbols.add((Symbol)o1);
						}
					}
					/* Create a set of symbols that are global to the procedure
					 * OR are passed into the procedure as pointers 
					 * This should be the set to which every pointer passed in must be 
					 * aliased to */
					HashSet<Symbol> global_symbol_set = new HashSet<Symbol>();
					/* Get the set of symbols accessed within the traversable */
					Set<Symbol> accessed_symbols = Tools.getAccessedSymbols(proc);
					for (Symbol s : accessed_symbols) {
						if (Tools.isGlobal(s,proc) && 
							(Tools.isPointer(s) || Tools.isArray(s)))
							global_symbol_set.add(s);
					}
					if (alias_level != ARGUMENT_NO_ALIAS) {
						for (Symbol s : parameter_symbols) {
								global_symbol_set.add(s);
						}
					}
	
					for (Symbol key : parameter_symbols) {
						HashSet<Symbol> alias_set = new HashSet<Symbol>(global_symbol_set);
						alias_set.remove(key);
						for (Symbol value : alias_set)
							add_this_alias_pair(key, value);
					}
				}
			}
		}

		if (debug_level > 1) System.out.println("[AliasAnalysis] Done");

	}	/* end of start function */

	private void add_this_alias_pair(Symbol lsymbol, Symbol rsymbol)
	{
		if (debug_level > 1)
		{
			System.out.println("lsymbol: " + lsymbol.getSymbolName());
			System.out.println("rsymbol: " + rsymbol.getSymbolName());
		}

		HashSet<Symbol> lset = alias_map.get(lsymbol);
		HashSet<Symbol> rset = alias_map.get(rsymbol);

		HashSet<Symbol> merged_set = new HashSet<Symbol>();
		if (lset != null) merged_set.addAll(lset);
		if (rset != null) merged_set.addAll(rset);

		merged_set.add(lsymbol);
		merged_set.add(rsymbol);

		alias_map.remove(lsymbol);
		alias_map.remove(rsymbol);

		alias_map.put(lsymbol, merged_set);
		alias_map.put(rsymbol, merged_set);
	}

	private boolean isFunctionCall(Expression expr)
	{
		if (debug_level > 2)
		{
			System.out.println("isMallocCall: " + expr.toString());
			System.out.println("  expr: " + expr.getClass().getName());
		}
			
		if (expr instanceof FunctionCall)
		{
			return true;
		}
		return false;
	}

	private boolean isMallocCall(FunctionCall fcall)
	{
		if (fcall.getName().toString().equals("malloc"))
			return true;
		else
			return false;
	}

	private boolean isNull(Expression expr)
	{
		Tools.println("isNull: " + expr.toString(), 8);
		Tools.println("  expr: " + expr.getClass().getName(), 8);
		if ((expr instanceof IntegerLiteral) && (expr.toString().equals("0")))
			return true;

		return false;
	}

	/**
		* Returns the alias set for the given input symbol, which includes the 
		* input symbol itself.
		* Current implementation is flow-insentitive that the stmt input is 
		* ignored; user can provide a null for this.
		*/
        @SuppressWarnings("unused")
	public Set<Symbol> get_alias_set(Statement cur_stmt, Symbol symbol)
	{
		if (no_alias)
			return null;
		else if (all_aliased_set.contains(symbol))
			return all_set;
		else
			return alias_map.get(symbol);
	}

	public void displayAliasMap()
	{
		if (debug_level < 2) return;

		System.out.println("****** alias_map ******");
		for ( Symbol sym : alias_map.keySet() )
		{
			System.out.print("key: " + sym.getSymbolName() + " = {");
			int count = 0;
			for ( Symbol alias_sym : alias_map.get(sym) )
			{
				if (++count > 1)
				{
					System.out.print(", " + alias_sym.getSymbolName());
				}
			}
			System.out.println("}");
		}
	}

	/**
		* Returns true if Symbol a is aliased to Symbol b
		* Current implementation is flow-insentitive that the stmt input is 
		* ignored; user can provide a null for this.
		*/
        @SuppressWarnings("unused")
	public boolean isAliased(Statement stmt, Symbol a, Symbol b)
	{
		if (no_alias)
			return false;
		else {
			HashSet<Symbol> alias_set = alias_map.get(a);
			if (!all_aliased_set.isEmpty())
			{
				if (alias_set == null)
					return all_aliased_set.contains(a);
				else
					return (all_aliased_set.contains(a) || alias_set.contains(b));	
			}
			else
			{
				if (alias_set == null)
					return false;
				else
					return alias_set.contains(b);	
			}
		}
	}

	/**
		* Returns true if the given Symbol, a, is aliased to any symbol in the
		* set of Symbols, bset.
		* Current implementation is flow-insentitive that the stmt input is 
		* ignored; user can provide a null for this.
		*/
	public boolean isAliased(Statement stmt, Symbol a, Set<Symbol> bset)
	{
		if (no_alias)
			return false;
		else
		{
			for (Symbol sym : bset)
			{
				if (isAliased(stmt, a, sym)) return true; 
			}
		}
		return false;
	}
}


