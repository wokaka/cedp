package cetus.analysis;

import cetus.hir.*;

import java.util.*;

/**
 * Provides tools for querying information related to For Loop objects
 *
 */
public class LoopTools {

	// Flag for checking if all loops are named.
	private static boolean is_loop_named=false;

	/**
	 * Constructor
	 * @return
	 */
	public LoopTools()
	{

	}

	/*
	 * Use the following static functions only with **ForLoops** that are identified
	 * as **CANONICAL** using **isCanonical**
	 * getIncrementExpression(loop)
	 * getIndexVariable(loop)
	 * getLowerBoundExpression(loop)
	 * getUpperBoundExpression(loop)
	 */

	/**
	 * Get the expression that represents the actual increment value for the loop.
	 * This might be an integer constant or a symbolic value
	 */
	public static Expression getIncrementExpression(Loop loop)
	{
		Expression loopInc = null;

		if (loop instanceof ForLoop)
		{
			ForLoop for_loop = (ForLoop)loop;
			/* determine the step */
			Expression step_expr = for_loop.getStep();
			if (step_expr instanceof AssignmentExpression)
			{
				Expression rhs = NormalExpression.simplify(((AssignmentExpression)step_expr).getRHS());

				if (((AssignmentExpression)step_expr).getOperator().equals(AssignmentOperator.NORMAL) && 
						rhs instanceof BinaryExpression)
				{
					if (((BinaryExpression)rhs).getOperator().equals(BinaryOperator.ADD))
						loopInc = ((BinaryExpression)(rhs)).getLHS();
					else if (((BinaryExpression)rhs).getOperator().equals(BinaryOperator.SUBTRACT))
						loopInc = NormalExpression.multiply(new IntegerLiteral(-1),
								((BinaryExpression)rhs).getLHS());
				}
				else if (((AssignmentExpression)step_expr).getOperator().equals(AssignmentOperator.ADD))
				{
					loopInc = rhs;
				}
				else if (((AssignmentExpression)step_expr).getOperator().equals(AssignmentOperator.SUBTRACT))
				{
					loopInc = NormalExpression.multiply(new IntegerLiteral(-1), rhs);
				}
			}
			else if (step_expr instanceof UnaryExpression)
			{
				UnaryExpression uexpr = (UnaryExpression)step_expr;

				UnaryOperator op = uexpr.getOperator();
				if (op == UnaryOperator.PRE_INCREMENT ||
						op == UnaryOperator.POST_INCREMENT)
					loopInc = new IntegerLiteral(1);
				else
					loopInc = new IntegerLiteral(-1);
			}		 
		}
		return loopInc;
	}
	
	/**
	 * Get loop increment expression and check if it is an integer constant
	 */
	public static boolean isIncrementConstant(Loop loop)
	{
		Expression inc = getIncrementExpression(loop);
		
		if (inc instanceof IntegerLiteral)
			return true;
		
		return false;
	}
	
	/**
	 * Get loop index variable, if loop is canonical
	 */
	public static Expression getIndexVariable(Loop loop)
	{
		Expression indexVar = null;

		/* Handle for loops here */
		if (loop instanceof ForLoop)
		{
			/* determine the name of the index variable */
			ForLoop for_loop = (ForLoop)loop;
			Expression step_expr = for_loop.getStep();

			if (step_expr instanceof AssignmentExpression)
			{
				indexVar = (Expression)((AssignmentExpression)step_expr).getLHS().clone();
			}
			else if (step_expr instanceof UnaryExpression)
			{
				UnaryExpression uexpr = (UnaryExpression)step_expr;

				indexVar = (Expression)uexpr.getExpression().clone();
			}
		}
		/* Handle other loop types */
		else
		{
		}

		return indexVar;
	}

	/**
	 * Returns a simplified lower bound expression for the loop 
	 */
	public static Expression getLowerBoundExpression(Loop loop)
	{
		Expression lb = null;

		if (loop instanceof ForLoop)
		{
			ForLoop for_loop = (ForLoop)loop;
			/* determine lower bound for index variable of this loop */
			Statement stmt = for_loop.getInitialStatement();
			if (stmt instanceof ExpressionStatement)
			{
				Expression rhs = ((AssignmentExpression)
										((ExpressionStatement)stmt).getExpression()).getRHS();
				lb = NormalExpression.simplify(rhs);
			}
			else if (stmt instanceof DeclarationStatement) { /* Error */ }
		}
		return lb;
	}

	/**
	 * Check if the lower bound expression is an integer constant
	 * @param loop
	 * @return
	 */
	public static boolean isLowerBoundConstant(Loop loop)
	{
		Expression lb;

		lb = getLowerBoundExpression(loop);
		if (lb instanceof IntegerLiteral) 
				return true;
		
		return false;
	}
	
	/**
	 * Returns a simplified upper bound expression for the loop
	 * @param loop
	 * @return
	 */
	public static Expression getUpperBoundExpression(Loop loop)
	{
		Expression ub = null;

		if (loop instanceof ForLoop)
		{
			ForLoop for_loop = (ForLoop)loop;
			/* determine upper bound for index variable of this loop */
			BinaryExpression cond_expr = (BinaryExpression)for_loop.getCondition();
			Expression rhs = cond_expr.getRHS();
			Expression step_size = getIncrementExpression(loop);

			BinaryOperator cond_op = cond_expr.getOperator();
			if (cond_op.equals(BinaryOperator.COMPARE_LT))
			{
				ub = Symbolic.subtract(rhs, step_size);
			}
			else if ((cond_op.equals(BinaryOperator.COMPARE_LE)) ||
					(cond_op.equals(BinaryOperator.COMPARE_GE)))
			{
				ub = Symbolic.simplify(rhs);
			}
			else if (cond_op.equals(BinaryOperator.COMPARE_GT))
			{
				ub = Symbolic.add(rhs, step_size);
			}
		}
		return ub;
	}

	/**
	 * Check if loop upper bound is an integer constant
	 */
	public static boolean isUpperBoundConstant(Loop loop)
	{
		Expression ub;

		ub = getUpperBoundExpression(loop);
		if (ub instanceof IntegerLiteral) 
			return true;
		
		return false;
	}
	
	/**
	 * Calculate the loop nest of this loop
	 */
	public static LinkedList<Loop> calculateLoopNest(Loop loop)
	{
		LinkedList<Loop> loopNest = new LinkedList<Loop>();

		loopNest.add(loop);	
		Traversable t = ((ForLoop)loop).getParent();

		while (t != null)
		{
			if (t instanceof ForLoop)
			{
				loopNest.addFirst((Loop)t);
			}

			t = t.getParent();
		}
		return loopNest;
	}

	/**
	 * Get common enclosing loops for loop1 and loop2
	 */
	public static LinkedList<Loop> getCommonNest(Loop loop1, Loop loop2)
	{
		LinkedList<Loop> commonNest = new LinkedList<Loop>();
		LinkedList<Loop> nest1 = calculateLoopNest(loop1);
		LinkedList<Loop> nest2 = calculateLoopNest(loop2);
		
		for (Loop l1 : nest1)
		{
			if (nest2.contains(l1))
				commonNest.addLast(l1);
		}	

		return commonNest;	
	}

	/**
	 * Check if loop is canonical, FORTRAN DO Loop format
	 */
	/*
	 * Following checks are performed:
	 * - Initial statement contains assignment expression for loop index
	 * - Simple conditional expression
	 * - index variable increment with positive stride
	 * - check if index variable is invariant within loop body
	 */
	public static boolean isCanonical (Loop loop)
	{
		if (loop instanceof ForLoop)
		{
			ForLoop forloop = (ForLoop) loop;
			Identifier index_variable = null;

			//check initial statement and obtain index variable for loop
			index_variable = isInitialAssignmentExpression(forloop);
			if (index_variable == null)
			{
				return false;
			}
			//check loop condition based on index variable obtained
			if (checkLoopCondition(forloop, index_variable)==null)
			{
				return false;
			}	
			//check loop step
			if ((checkIncrementExpression(forloop, index_variable)) == 0)
			{
				return false;
			}
			//check index invariant
			if ((isIndexInvariant(forloop, index_variable)) == false)
			{
				return false;
			}
		}
		else if (loop instanceof WhileLoop)
			return false;
		else if (loop instanceof DoLoop)
			return false;

		// in the future it should handle other loops
		return true;
	}
	
	static private Identifier isInitialAssignmentExpression (Loop loop)
	{
		Statement init_stmt = ((ForLoop)loop).getInitialStatement();
		if (init_stmt instanceof ExpressionStatement)
		{
			Expression exp = ((ExpressionStatement)init_stmt).getExpression();
			if (exp instanceof AssignmentExpression)
			{
				AssignmentExpression assignment_exp = (AssignmentExpression)exp;
				AssignmentOperator op = assignment_exp.getOperator();
				if (op.equals(AssignmentOperator.NORMAL))
				{
					Expression lhs = NormalExpression.simplify(assignment_exp.getLHS());
					//Expression rhs = NormalExpression.simplify(assignment_exp.getRHS());
					if (lhs instanceof Identifier)
					{
						return((Identifier) lhs);
					}
				}
			}
		}
		return null;
	}
	
	static private Expression checkLoopCondition (Loop loop, Identifier induction_variable)
	{
		Expression loopbound = null;
		Expression cond_exp = ((ForLoop)loop).getCondition();
		if (cond_exp instanceof BinaryExpression)
		{
			BinaryExpression bin_condexp = (BinaryExpression)cond_exp;

			BinaryOperator operator = bin_condexp.getOperator();

			Expression lhs = NormalExpression.simplify(bin_condexp.getLHS());
			Expression rhs = NormalExpression.simplify(bin_condexp.getRHS());

			//if ((operator.equals(BinaryOperator.COMPARE_LT)) ||
			//		(operator.equals(BinaryOperator.COMPARE_LE)))
			if ((operator.equals(BinaryOperator.COMPARE_LT)) ||
					(operator.equals(BinaryOperator.COMPARE_LE)) ||
					(operator.equals(BinaryOperator.COMPARE_GT)) ||
					(operator.equals(BinaryOperator.COMPARE_GE)))
			{
				if (lhs.equals(induction_variable))
				{
					loopbound = (Expression) rhs.clone();
				}
			}
		}
		return loopbound;
	}

	static private int checkIncrementExpression (Loop loop, Identifier id)
	{
		int increasing = 1;
		int decreasing = -1;
		int indeterminate = 0;

		Expression exp = ((ForLoop)loop).getStep();
		if (exp instanceof UnaryExpression)
		{
			UnaryExpression unary_exp = (UnaryExpression)exp;
			if ((unary_exp.getOperator().equals(UnaryOperator.POST_INCREMENT) ||
					unary_exp.getOperator().equals(UnaryOperator.PRE_INCREMENT)) 
					&& unary_exp.getExpression().equals(id))
				return increasing;
			else if ((unary_exp.getOperator().equals(UnaryOperator.POST_DECREMENT) ||
					unary_exp.getOperator().equals(UnaryOperator.PRE_DECREMENT)) 
					&& unary_exp.getExpression().equals(id))
				return decreasing;
			else
				return indeterminate;
		}
		else if (exp instanceof AssignmentExpression)
		{
			AssignmentExpression assign_exp = (AssignmentExpression) exp;
			if (!assign_exp.getLHS().equals(id))
			{
				return indeterminate;
			}
			if (assign_exp.getOperator().equals(AssignmentOperator.NORMAL))
			{
				if (assign_exp.getRHS() instanceof BinaryExpression)
				{
					BinaryExpression bin_exp = (BinaryExpression)assign_exp.getRHS();
					if (bin_exp.getOperator().equals(BinaryOperator.ADD))
					{
						/* Simplify the LHS and RHS of the binary expression to 
						 * accurately state whether we have a canonical increment
						 * expression or not
						 */
						Expression rhs = NormalExpression.simplify(bin_exp.getRHS());
						Expression lhs = NormalExpression.simplify(bin_exp.getLHS());
						if ((lhs instanceof Identifier) && ((Identifier)lhs).equals(id))
							return increasing;
						else if ((rhs instanceof Identifier) && ((Identifier)rhs).equals(id))
							return increasing;
						else
							return indeterminate;
					}
					else if (bin_exp.getOperator().equals(BinaryOperator.SUBTRACT))
					{
						/* Simplify the LHS and RHS of the binary expression to 
						 * accurately state whether we have a canonical increment
						 * expression or not
						 */
						Expression rhs = NormalExpression.simplify(bin_exp.getRHS());
						Expression lhs = NormalExpression.simplify(bin_exp.getLHS());
						if ((lhs instanceof Identifier) && ((Identifier)lhs).equals(id))
							return decreasing;
						else if ((rhs instanceof Identifier) && ((Identifier)rhs).equals(id))
							return decreasing;
						else
							return indeterminate;
					}
				}
			}
			else if (assign_exp.getOperator().equals(AssignmentOperator.ADD))
			{
				Expression lhs = NormalExpression.simplify(assign_exp.getLHS());
				if ((lhs instanceof Identifier) && ((Identifier)lhs).equals(id))
					return increasing;
			}
			else if (assign_exp.getOperator().equals(AssignmentOperator.SUBTRACT))
			{
				Expression lhs = NormalExpression.simplify(assign_exp.getLHS());
				if ((lhs instanceof Identifier) && ((Identifier)lhs).equals(id))
					return decreasing;
			}
		}
		return indeterminate;
	}

	/**
	 * Checks if loop body contains a function call
	 */
	public static boolean containsFunctionCall (Loop loop)
	{
		if (loop instanceof ForLoop)
			return (Tools.containsClass(loop.getBody(), FunctionCall.class));
		else
			return true;
	}

	/**
	 * Check if the loop contains a function call that can be
	 * tested for data dependences/that can be eventually parallelized
	 */
	public static boolean containsOnlyParallelizableCall(Loop loop)
	{
		boolean only_parallelizable_call = false;

		List<FunctionCall> fc_list = Tools.getFunctionCalls(loop);
		Set<String> parallelizable_calls = new HashSet<String>(Arrays.asList(
					"sqrt","log","fabs"
		));

		for ( FunctionCall fc : fc_list ) {
			if ( Tools.getSideEffectSymbols(fc).isEmpty() )
				only_parallelizable_call = true;
			else
				only_parallelizable_call = false;
			if ( Tools.isStdLibCall(fc) )
				only_parallelizable_call = false;
			if ( parallelizable_calls.contains((fc.getName()).toString()) )
				only_parallelizable_call = true;

			if ( !only_parallelizable_call )
				break;
		}

		return only_parallelizable_call;
	}

	/**
	 * Check if this loop and inner loops form a perfect nest
	 */
	public static boolean isPerfectNest(Loop loop)
	{
		boolean pnest = false;
		List<Traversable> children;
		Object o = null;
		Statement stmt = loop.getBody();
		
		FlatIterator iter = new FlatIterator(stmt);
		if (iter.hasNext())
		{
			boolean skip = false;
			do
			{
				o = iter.next(Statement.class);
				
				if (o instanceof AnnotationStatement)
					skip = true;
				else
					skip = false;
				
			} while ((skip) && (iter.hasNext()));
			
			if (o instanceof ForLoop)
			{
				pnest = (isPerfectNest((Loop)o));
				
				/* The ForLoop contains additional statements after the end
				 * of the first ForLoop. This is interpreted as
				 * a non-perfect nest for dependence testing
				 */
				if (iter.hasNext())
					pnest = false;
			}
			else if (o instanceof CompoundStatement)
			{
				children = ((Statement)o).getChildren();
				Statement s = (Statement)children.get(0);
				if (s instanceof ForLoop)
					pnest = (isPerfectNest((Loop)s));
				else
					pnest = false;
			}
			else if (containsLoop(loop))
			{
				Tools.println("Loop is not perfectly nested", 8);
				pnest = false;
			}
			else
			{
				Tools.println("Loop is perfectly nested", 8);
				pnest = true;
			}
			
		}
		return pnest;
	}
	
	/**
	 * Check if loop body contains another loop
	 */
	public static boolean containsLoop(Loop loop)
	{
		/* Test whether a ForLoop contains another ForLoop */
		if (loop instanceof ForLoop)
			return (Tools.containsClass(loop.getBody(), ForLoop.class));
		else
			return true;
	}
	
	/**
	 * Check if the index variable is defined within the loop body
	 */
	public static boolean isIndexInvariant(Loop loop, Identifier id)
	{
		/* Get def set for loop body */
		Set<Expression> def_set = Tools.getDefSet(loop.getBody());
		if (def_set.contains(id))
				return false;
		
		return true;
	}

	/**
	 * Check if the given expression is loop invariant
	 */
	public static boolean isLoopInvariant(Loop loop, Expression e)
	{
		/* Get def set for loop including loop header statement */
		Set<Symbol> head_def_set = Tools.getDefSymbol(((ForLoop)loop).getStep());
		Set<Symbol> body_def_set = Tools.getDefSymbol(loop.getBody());
		
		Set<Symbol> accessed_set = Tools.getAccessedSymbols(e);
		for (Symbol s : accessed_set)
		{
			if (head_def_set.contains(s) || body_def_set.contains(s))
				return false;
		}
		
		return true;
	}
	
	/**
	 * Check for scalars that are not privatizable or reduction variables
	 */
	public static boolean scalarDependencePossible(Loop l)
	{
		/* SCALAR DEPENDENCE CHECK
		 * -----------------------
		 * Currently, test if for loops contain scalar
		 * variables in their def set that are not marked private or reduction. These scalars 
		 * may cause dependences that we don't currently test for.
		 */
		Set<Symbol> def_symbols = Tools.getDefSymbol(l.getBody());
		for (Symbol sym : def_symbols)
		{
			/* If the variable is a scalar that is written to, and not marked private 
			 * or reduction
			 */
			if ((Tools.isScalar(sym)) &&
					(!(isPrivate(sym, l)) &&
					 !(isReduction(sym, l)))) {
					/* If the symbol is a pointer, check if all the definitions for this
					 * pointer are array accesses, if not then scalar dependence is possible
					 * if yes, array data dependence testing will handle it i.e. return false */
					if (Tools.isPointer(sym)) {
						Set<Expression> def_set = Tools.getDefSet(l.getBody());
						for (Expression def : def_set)
						{
							if (sym.equals(Tools.getSymbolOf(def))) {
								if (def instanceof ArrayAccess)
									continue;
								else
									return true;
							}
						}
					}
					/* if it isn't a pointer, scalar dependence does exist */
					else
						return true;
			}
		}
		return false;
	}
	
	/**
	 * Checks whether this loop contains any inner loops 
	 */
	public static boolean isInnermostLoop(Loop loop)
	{
		if (containsLoop(loop))
			return false;
		else
			return true;
	}

	/**
	 * Checks whether this loop is enclosed by any outer loops 
	 */
	public static boolean isOutermostLoop(Loop loop)
	{
		if (loop instanceof ForLoop)
		{
			ForLoop for_loop = (ForLoop)loop;
			Traversable t = for_loop.getParent();
			
			while (t != null)
			{
				if (t instanceof ForLoop)
					return false;
				else
					t = t.getParent();
			}
		}
		return true;
	}

	/**
	 * Get the outermost loop for the nest that surrounds the input loop
	 */
	public static Loop getOutermostLoop(Loop loop)
	{
		Loop return_loop = null;
		if (loop instanceof ForLoop)
		{
			if (isOutermostLoop(loop))
				return_loop = loop;
			else
			{
				ForLoop for_loop = (ForLoop)loop;
				Traversable t = for_loop.getParent();
			
				while (t != null)
				{
					if (t instanceof ForLoop)
					{
						if (isOutermostLoop((Loop)t))
							return_loop = (Loop)t;
						else
							t = t.getParent();
					}
					else
					{
						t = t.getParent();
					}
				}
			}
		}
		return return_loop;
	}

	/**
	 * Check whether the loop contains control constructs that cause it to terminate
	 * before the loop condition is reached
	 * Check only at one nesting level, no need to check for control flow constructs
	 * in nested loops
	 */
	public static boolean containsControlFlowModifier(Loop loop)
	{
		boolean ret_val = false;
		
		if (loop instanceof ForLoop)
		{
			DepthFirstIterator iter = new DepthFirstIterator(loop.getBody());
			iter.pruneOn(Loop.class);
			
			while (iter.hasNext())
			{
				Object o = iter.next();
				if ((o instanceof GotoStatement) ||
						(o instanceof BreakStatement) ||
						(o instanceof Label) ||
						(o instanceof ReturnStatement))
					ret_val = true;
			}
			return ret_val;
		}
		else
			return true;
	}

	/**
	 * Check if the loop contains only a break statement
	 * modifier
	 */
	public static boolean containsBreakStatement(Loop loop)
	{
                boolean ret_val = false;

                if (loop instanceof ForLoop)
                {
                        DepthFirstIterator iter = new DepthFirstIterator(loop.getBody());
                        iter.pruneOn(Loop.class);

                        while (iter.hasNext())
                        {
                                Object o = iter.next();
				if ( o instanceof BreakStatement ) {
                                        ret_val = true;
					break;
				}
                        }
                        return ret_val;
                }
                else
                        return false;
	}

        public static boolean containsControlFlowModifierOtherThanBreakStmt(Loop loop)
        {
                boolean ret_val = false;
                
                if (loop instanceof ForLoop)
                {
                        DepthFirstIterator iter = new DepthFirstIterator(loop.getBody());
                        iter.pruneOn(Loop.class); 
                        
                        while (iter.hasNext())
                        {
                                Object o = iter.next();
                                if ((o instanceof GotoStatement) ||
                                                (o instanceof Label) ||
                                                (o instanceof ReturnStatement))
                                        ret_val = true;
                        }
                        return ret_val;
                }
                else
                        return true;
        }

	/**
	 * Calculate the nest of loops enclosed within the given loop
	 */
	public static LinkedList<Loop> calculateInnerLoopNest(Loop enclosing_loop)
	{
		LinkedList<Loop> ret_nest = new LinkedList<Loop>();
		DepthFirstIterator dfs_iter = new DepthFirstIterator(enclosing_loop);
		for(;;)
		{
			Loop l = null;
			try {
				l = dfs_iter.next(Loop.class);
				ret_nest.add(l);
			}
			catch (NoSuchElementException e) {
				break;
			}
		}
		return ret_nest;
	}

	/**
	 * Returns the loop name inserted by Cetus.
	 * @param loop the loop.
	 * @return the loop name if one exists, null otherwise.
	 */
	public static String getLoopName(Statement loop)
	{
		PragmaAnnotation note = loop.getAnnotation(PragmaAnnotation.class, "name");
		return (note==null)? null: (String)note.get("name");
	}

	/**
	 * Adds a unique loop name to each for loop.
	 * @param prog the input program.
	 */
	public static void addLoopName(Program program)
	{
		if ( !is_loop_named )
			addLoopName(program, "", null);
		is_loop_named = true;
	}

	/* Adds a unique loop name to each for loop - recursive call */
	private static void addLoopName
	(Traversable tr, String header, LinkedList<Integer> nums)
	{
		@SuppressWarnings("unused")
		Map<Statement, PragmaAnnotation> names =
			new HashMap<Statement, PragmaAnnotation>();

		FlatIterator iter = new FlatIterator(tr);

		while ( iter.hasNext() )
		{
			Traversable t = iter.next();

			if ( t == null )
				continue;
			else if ( t instanceof Procedure )
			{
				LinkedList<Integer> init_nums =
					new LinkedList<Integer>(Arrays.asList(new Integer(0)));
				addLoopName(t, header+((Procedure)t).getName(), init_nums);
			}
			else if ( t instanceof ForLoop )
			{
				Statement loop = (Statement)t;
				String my_name = header+"#"+Tools.listToString(nums, "#");
				PragmaAnnotation note = new PragmaAnnotation("loop");
				note.put("name", my_name);
				loop.annotate(note);
				nums.add(new Integer(0));
				addLoopName(t, header, nums);
				nums.removeLast();
				nums.set(nums.size()-1, nums.getLast()+1);
			}
			else if ( t.getChildren() != null )
				addLoopName(t, header, nums);
		}
	}

	/**
	 * Check if the input symbol is marked as private to the loop by the Privatization pass.
	 * ArrayPrivatization MUST be run before using this test
	 * @param s the symbol which needs to be checked as private to loop or not
	 * @param l the loop with respect to which private property needs to be checked
	 * @return true if private, else false
	 */
	public static boolean isPrivate(Symbol s, Loop l)
	{
		boolean ret = false;
		Set<Symbol> private_set = new HashSet<Symbol>();
		CetusAnnotation note = null;
		note = ((Annotatable)l).getAnnotation(CetusAnnotation.class, "private");
		if (note != null) {
			Set<Symbol> private_symbols = (note.get("private"));
			private_set.addAll(private_symbols);
		}
		note = ((Annotatable)l).getAnnotation(CetusAnnotation.class, "lastprivate");
		if (note != null) {
			Set<Symbol> last_private_symbols = (note.get("lastprivate"));
			private_set.addAll(last_private_symbols);
		}
		note = ((Annotatable)l).getAnnotation(CetusAnnotation.class, "firstprivate");
		if (note != null) {
			Set<Symbol> first_private_symbols = (note.get("firstprivate"));
			private_set.addAll(first_private_symbols);
		}
		
		if (private_set.contains(s))
			ret = true;
		else
			ret = false;
		
		return ret;
	}
	
	/**
	 * Check if the input symbol is marked as reduction for the loop by the Reduction pass.
	 * Reduction Analysis MUST be run before using this test
	 * @param s the symbol which needs to be checked as reduction variable or not
	 * @param l the loop with respect to which reduction property needs to be checked
	 * @return true if reduction variable, else false
	 */
	@SuppressWarnings("unchecked")
	public static boolean isReduction(Symbol s, Loop l)
	{
		boolean ret = false;
		Set<Symbol> reduction_set = new HashSet<Symbol>();
		CetusAnnotation note = ((Annotatable)l).getAnnotation(CetusAnnotation.class, "reduction");
		if (note != null) {
			Map<String, Set<Expression>> m = (Map<String, Set<Expression>>)(note.get("reduction"));
			for (String op : m.keySet())
			{
				Set<Expression> ts = m.get(op);
				for (Expression re: ts)
				{
					reduction_set.add(Tools.getSymbolOf(re));
				}
			}
		}
		if (reduction_set.contains(s))
			ret = true;
		else
			ret = false;
		
		return ret;
	}
	
	/**
	 * Checks the eligibility of a certain loop for data dependence testing
	 * Eligibility checks can be added or removed to increase the scope of dependence testing
	 * @param loop
	 * @return
	 */
	public static boolean checkDataDependenceEligibility(Loop loop)
	{
		/* Checks whether the loop is in a conventional
		 * Fortran type do loop format. Symbolic values are allowed in loop header statement */
		if (isCanonical(loop)==false)
		{
			Tools.println("Loop is not canonical", 4);
			return false;
		}
		/* One of the checks to see that the loop body contains 
		 * no side-effects */
		if (containsFunctionCall(loop)==true)
		{
			if (containsOnlyParallelizableCall(loop)==false) {
				Tools.println("Loop can have side-effects", 4);
				return false;
			}
		}
		/* Deal only with perfectly nested loops */
		/*if (isPerfectNest(loop)==false)
		{
			Tools.println("Loop does not contain a perfect nest", 4);
			return false;
		}*/
		if (containsControlFlowModifierOtherThanBreakStmt(loop)==true)
		{
			Tools.println("Loop contains control flow modifiers", 4);
			return false;
		}
		if (isIncrementEligible(loop)==false)
		{
			Tools.println("Loop contains indeterminate symbolic increment", 4);
			return false;
		}
		return true;
	}
	
	/**
	 * Returns true if the loop increment is an integer constant value. If symbolic, uses
	 * range information to determine if it is an integer constant value or not
	 * @param loop the loop whose increment needs to be checked
	 * @return true if increment is an integer constant value
	 */
	public static boolean isIncrementEligible(Loop loop)
	{
		boolean eligible_inc = true;
		if (isIncrementConstant(loop)==false)
		{
			RangeDomain loop_range = RangeAnalysis.getRangeDomain((ForLoop)loop);
			Expression curr_inc = getIncrementExpression(loop);
			Set<Symbol> loop_stmt_symbols = loop_range.getSymbols();
			Expression new_inc = loop_range.substituteForward(curr_inc, loop_stmt_symbols);
			if (!(new_inc instanceof IntegerLiteral))
				eligible_inc = false;
			else
				eligible_inc = true;
		}
		return eligible_inc;
	}
	
	/**
	 * Get symbol of loop index, index variable is identified from step expression for loop
	 * @return Symbol for the loop index variable
	 */
	public static Symbol getLoopIndexSymbol(Loop loop)
	{
		Expression indexVar = getIndexVariable(loop);
		return Tools.getSymbolOf(indexVar);
	}
	
	/**
	 * Replaces symbolic values in loop lower bound with information obtained from
	 * range analysis. If symbolic bound has a constant value, that value is the new
	 * lower bound. In case of a range expression, the lowerbound of the range is 
	 * conservatively used as the lowerbound for the loop. If the symbolic value
	 * has an indeterminate value, the minimum possible value for Long is assigned
	 * to the lower bound
	 * @param loop the loop whose symbolic lower bound is to be replaced
	 * @param loop_rd the range domain representing ranges for all vars in the loop statement
	 * @return the expression for the new lowerbound with constant value
	 */
	public static Expression replaceSymbolicLowerBound(Loop loop, RangeDomain loop_rd)
	{
		Expression new_lb = null;
		long EXTREME_VALUE = Integer.MIN_VALUE;
		Identifier index = (Identifier)getIndexVariable(loop);
		if (checkIncrementExpression(loop, index)==1)
			EXTREME_VALUE = Integer.MIN_VALUE;
		else if (checkIncrementExpression(loop, index)==-1)
			EXTREME_VALUE = Integer.MAX_VALUE;	
		Set<Symbol> loop_stmt_symbols = loop_rd.getSymbols();
		Expression curr_lb = getLowerBoundExpression(loop);
		new_lb = loop_rd.expandSymbols(curr_lb, loop_stmt_symbols);
		if (new_lb instanceof RangeExpression)
		{
			Expression lb_of_range = ((RangeExpression)new_lb).getLB();
			if (lb_of_range instanceof IntegerLiteral)
				new_lb = lb_of_range;
			else
				new_lb = new IntegerLiteral(EXTREME_VALUE);
		}
		else //if(new_lb instanceof Expression)
		{
			new_lb = new IntegerLiteral(EXTREME_VALUE);
		}		
		return new_lb;
	}
	
	/**
	 * Replaces symbolic values in loop lower bound with information obtained from
	 * range analysis. If symbolic bound has a constant value, that value is the new
	 * lower bound. In case of a range expression, the lowerbound of the range is 
	 * conservatively used as the lowerbound for the loop. If the symbolic value
	 * has an indeterminate value, the minimum possible value for Long is assigned
	 * to the lower bound
	 * @param loop the loop whose symbolic lower bound is to be replaced
	 * @return the expression for the new lowerbound with constant value
	 */
	public static Expression replaceSymbolicLowerBound(Loop loop)
	{
		RangeDomain loop_range = RangeAnalysis.getRangeDomain((Statement)loop);
		
		return (replaceSymbolicLowerBound(loop, loop_range));
	}
	
	/**
	 * Replaces symbolic values in loop upper bound with information obtained from
	 * range analysis. If symbolic bound has a constant value, that value is the new
	 * upper bound. In case of a range expression, the upperbound of the range is 
	 * conservatively used as the upperbound for the loop. If the symbolic value
	 * has an indeterminate value, the maximum possible value for Long is assigned
	 * to the upper bound
	 * @param loop the loop whose symbolic upper bound is to be replaced
	 * @param loop_rd the range domain representing ranges for all vars in the loop statement
	 * @return the expression for the new upperbound with constant value
	 */
	public static Expression replaceSymbolicUpperBound(Loop loop, RangeDomain loop_rd)
	{
		Expression new_ub = null;
		long EXTREME_VALUE = Integer.MAX_VALUE;
		Identifier index = (Identifier)getIndexVariable(loop);
		if (checkIncrementExpression(loop, index)==1)
			EXTREME_VALUE = Integer.MAX_VALUE;
		else if (checkIncrementExpression(loop, index)==-1)
			EXTREME_VALUE = Integer.MIN_VALUE;	
		Set<Symbol> loop_stmt_symbols = loop_rd.getSymbols();
		Expression curr_ub = getUpperBoundExpression(loop);
		new_ub = loop_rd.expandSymbols(curr_ub, loop_stmt_symbols);
		if (new_ub instanceof RangeExpression)
		{
			Expression ub_of_range = ((RangeExpression)new_ub).getUB();
			if (ub_of_range instanceof IntegerLiteral)
				new_ub = ub_of_range;
			else
				new_ub = new IntegerLiteral(EXTREME_VALUE);
		}
		else //if(new_ub instanceof Expression)
		{
			new_ub = new IntegerLiteral(EXTREME_VALUE);
		}		
		return new_ub;
	}
	
	/**
	 * Replaces symbolic values in loop upper bound with information obtained from
	 * range analysis. If symbolic bound has a constant value, that value is the new
	 * upper bound. In case of a range expression, the upperbound of the range is 
	 * conservatively used as the upperbound for the loop. If the symbolic value
	 * has an indeterminate value, the maximum possible value for Long is assigned
	 * to the upper bound
	 * @param loop the loop whose symbolic upper bound is to be replaced
	 * @return the expression for the new upperbound with constant value
	 */
	public static Expression replaceSymbolicUpperBound(Loop loop)
	{
		RangeDomain loop_range = RangeAnalysis.getRangeDomain((Statement)loop);
		
		return (replaceSymbolicUpperBound(loop, loop_range));
	}
	
	public static List<Loop> extractOutermostDependenceTestEligibleLoops(Traversable t)
	{
		LinkedList<Loop> eligible_loops = new LinkedList<Loop>();
		/* Iterate depth-first over all loops including the enclosing loop
		 * Identify all nests eligible for testing, including arbitrarily nested loops */
		LinkedList<Loop> tested_loops = new LinkedList<Loop>();
		DepthFirstIterator iter = new DepthFirstIterator(t);
		while (iter.hasNext()) {
			Object o = iter.next();
			if (o instanceof Loop) {
				Loop loop = (Loop)o;
				boolean nest_eligible = false;
				if (tested_loops.contains(loop))
					continue;
				else {
					LinkedList<Loop> nest = LoopTools.calculateInnerLoopNest(loop);
					for (Loop l : nest) {
						nest_eligible = LoopTools.checkDataDependenceEligibility(l);
						if (nest_eligible == false)
							break;
					}
					if (nest_eligible) {
						tested_loops.addAll(nest);
						eligible_loops.add(loop);
					}
				}
			}
		}		
		return eligible_loops;
	}

	/**
	 * Returns the control structure of the specified loop in string.
	 * 
	 * @param loop the given loop.
	 * @return the string for the control structure.
	 */
	public static String toControlString(Loop loop)
	{
		StringBuilder str = new StringBuilder(80);
		if ( loop instanceof ForLoop )
		{
			ForLoop forloop = (ForLoop)loop;
			Statement init = forloop.getInitialStatement();
			Expression condition = forloop.getCondition();
			Expression step = forloop.getStep();
			str.append("for (");
			if ( init != null )
				str.append(init.toString());
			if ( condition != null )
				str.append(" "+condition.toString());
			str.append("; ");
			if ( step != null )
				str.append(step.toString());
			str.append(")");
		}
		else if ( loop instanceof WhileLoop )
		{
			str.append("while (");
			str.append(loop.getCondition());
			str.append(")");
		}
		else if ( loop instanceof DoLoop )
		{
			str.append("do..while (");
			str.append(loop.getCondition());
			str.append(")");
		}
		return str.toString();
	}
}
