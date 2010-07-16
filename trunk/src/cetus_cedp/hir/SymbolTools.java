package cetus.hir;

import java.util.*;


public final class SymbolTools
{
  /**
   * Makes links from all {@link IDExpression} objects in the program to
   * their corresponding declarators while generating warnings if there is
   * any undeclared variables or functions. This method is called with the
   * whole program, before any Cetus passes by default and provides a short cut
   * to the declaration point, which enables faster access to the declaration
   * when necessary. Pass writers can call this routine after changing a certain
   * part of the program, e.g., a specific program section within a scope, to
   * reflect the change due to new insertion of declaration.
   *
   * @param tr the input cetus IR.
   */
	public static void linkSymbol(Traversable tr)
	{
		double timer = Tools.getTime();

		DepthFirstIterator iter = new DepthFirstIterator(tr);

		while ( iter.hasNext() )
		{
			Object o = iter.next();

			// Set symbols in the symbol table keys first.
			if ( o instanceof SymbolTable )
				setTableSymbols((SymbolTable)o);
			// Add enumerations in the table.
			else if ( o instanceof Enumeration )
				putEnumeration((Enumeration)o);

			if ( o instanceof Identifier )
				searchAndLink((Identifier)o);
		}

		timer = Tools.getTime(timer);

		Tools.printStatus("[LinkSymbol] "+Double.toString(timer)+" seconds\n", 1);
//		Tools.printStatus("[LinkSymbol] "+String.format(new String("%.2f seconds\n"),timer), 1);
	}

	public static void searchAndLink(Identifier id)
	{
		String id_name = id.getName();

		// These cases are skipped intentionally.
		if ( id.getParent() instanceof Declarator || // it is a Symbol object.
		id_name.equals("") ||                        // void Symbol.
		id_name.equals("__PRETTY_FUNCTION__") ||     // gcc keyword.
		id_name.equals("__FUNCTION__") ||            // gcc keyword.
		id_name.startsWith("__builtin") )            // gcc keyword.
			return;

		Declaration decls = searchDeclaration(id);

		if ( decls == null )
			return;

		// Lookup the symbol object in the declaration and add links.
		if ( decls instanceof Procedure )
			id.setSymbol((Symbol)decls);
		else if ( decls instanceof VariableDeclaration )
		{
			Declarator decl = null;
			for ( Object child : decls.getChildren() )
				if ( id.equals( ((Declarator)child).getSymbol() ) )
				{
					decl = (Declarator)child;
					if ( decl instanceof NestedDeclarator )
						decl = ((NestedDeclarator)decl).getDeclarator();
					id.setSymbol(decl);
					break;
				}
		}
	}

	// Put each enumerated members in the table.
	private static void putEnumeration(Enumeration en)
	{
		Traversable t = en.getParent();
		while ( t != null && !(t instanceof SymbolTable) )
			t = t.getParent();
		Map<IDExpression, Declaration> symtab = ((SymbolTable)t).getTable();
		for ( Object child : en.getChildren() )
			symtab.put(((VariableDeclarator)child).getSymbol(), en);
	}

	// Add symbol reference in the symbol table keys.
	private static void setTableSymbols(SymbolTable st)
	{
		Map<IDExpression, Declaration> symtab = st.getTable();
		if ( symtab == null )
			return;

		for ( IDExpression id : symtab.keySet() )
		{
		  /*
			if ( !(o instanceof IDExpression ) )
				continue;
			IDExpression id = (IDExpression)o;
			*/
			if ( id.getSymbol() != null )
				continue;
			Traversable decl = symtab.get(id);
			if ( decl instanceof VariableDeclaration )
				for ( Object child : decl.getChildren() )
					if ( child instanceof Declarator && child instanceof Symbol &&
					id.equals(((Declarator)child).getSymbol()) )
					id.setSymbol((Symbol)child);
			else if ( decl instanceof Symbol )
				id.setSymbol((Symbol)decl);
		}
	}

	// Returns the type of an expression
  private static List<Specifier> getType(Traversable e)
  {
		if ( !(e instanceof Expression) )
			return null;

    if ( e instanceof Identifier )
		{
			Symbol var = ((Identifier)e).getSymbol();
      return (var==null)? null: var.getTypeSpecifiers();
		}

		else if ( e instanceof AccessExpression )
			return getType(((AccessExpression)e).getRHS());

    else if ( e instanceof ArrayAccess )
      return getType(((ArrayAccess)e).getArrayName());

		else if ( e instanceof ConditionalExpression )
		{
			ConditionalExpression ce = (ConditionalExpression)e;
			List<Specifier> specs = getType(ce.getTrueExpression());
			if ( specs == null || specs.get(0) == Specifier.VOID )
				return getType(ce.getFalseExpression());
			else
				return specs;
		}

    else if ( e instanceof FunctionCall )
      return getType(((FunctionCall)e).getName());

    else if ( e instanceof Typecast )
      return ((Typecast)e).getSpecifiers();

		else if ( e instanceof CommaExpression )
		{
			List<Traversable> children = e.getChildren();
			return getType( children.get(children.size()-1) );
		}

		else
		{
			for ( Object child : e.getChildren() )
			{
				List<Specifier> child_type = getType((Expression)child);
				if ( child_type != null )
					return child_type;
			}
			return null;
		}
  }

	// findDeclaration with an arbitrary starting point and a target id.
	private static Declaration findDeclaration(Traversable tr, IDExpression id)
	{
		Traversable t = tr;
		while ( t != null && !(t instanceof SymbolTable) )
			t = t.getParent();
		return ((t==null)? null: Tools.findSymbol((SymbolTable)t, id));
	}

  // Serach for declaration of the identifier
  private static Declaration searchDeclaration(Identifier id)
  {
    Declaration ret = null;
    Traversable parent = id.getParent();

		// Broken IR
		if ( parent == null )
			return null;

		// AccessExpression handling.
    if ( parent instanceof AccessExpression &&
    ((AccessExpression)parent).getRHS() == id )
		{
			List<Specifier> specs = getType(((AccessExpression)parent).getLHS());
			Declaration cdecl = findUserDeclaration(id, specs);
			if ( cdecl instanceof ClassDeclaration ) {
				Tools.println("Found class type", 4);
				ret = ((ClassDeclaration)cdecl).findSymbol(id);
			}
		}
		// __builtin__offsetof handling.
		else if ( parent instanceof OffsetofExpression &&
		((OffsetofExpression)parent).getExpression() == id )
		{
			List<Specifier> specs = ((OffsetofExpression)parent).getSpecifiers();
			Declaration cdecl = findUserDeclaration(id, specs);
			if ( cdecl instanceof ClassDeclaration )
				ret = ((ClassDeclaration)cdecl).findSymbol(id);
		}
    else
		{
      ret = id.findDeclaration();
			// This code section only deals with a situation that name conflicts
			// in a scope; e.g.) { int a = b; float b; ... }
			if ( ret instanceof VariableDeclaration )
			{
				Traversable t1 = Tools.getAncestorOfType(id, Statement.class);
				Traversable t2 = Tools.getAncestorOfType(ret, Statement.class);
				if ( t1 != null && t2 != null && t1.getParent() == t2.getParent() )
				{
					List<Traversable> children = t1.getParent().getChildren();
					if ( children.indexOf(t1) < children.indexOf(t2) )
						ret = findDeclaration(t1.getParent().getParent(), id);
				}
			}
		}

		// Prints out warning for undeclared functions/symbols.
    if ( ret == null )
		{
      if ( parent instanceof FunctionCall &&
        ((FunctionCall)parent).getName() == id )
        System.err.print("[WARNING] Function without declaration ");
      else
        System.err.print("[WARNING] Undeclared symbol ");

			System.err.println(id+" from "+parent);
    }
    return ret;
  }

  // Find the body of user-defined class declaration
  private static Declaration findUserDeclaration(Traversable tr, List<Specifier> specs)
  {
    if ( specs == null )
      return null;

    // Find the leading user specifier
    UserSpecifier uspec = null;
    for ( Object o: specs )
		{
      if ( o instanceof UserSpecifier )
			{
        uspec = (UserSpecifier)o;
        break;
      }
		}

    if ( uspec == null )
      return null;

    // Find declaration for the user specifier
		Declaration ret = findDeclaration(tr, uspec.getIDExpression());

		// Handles identifier that shares the same name with its type;
		// e.g. typedef struct {} foo; foo foo;
		if ( ret instanceof VariableDeclaration &&
		((VariableDeclaration)ret).getSpecifiers() == specs )
		{
			Traversable t = Tools.getAncestorOfType(ret, SymbolTable.class);
			ret = findDeclaration(t.getParent(), uspec.getIDExpression());
		}
		
    // Keep searching through the chain ( i.e. typedef, etc )
    if ( ret instanceof VariableDeclaration ) {
      return findUserDeclaration(tr,((VariableDeclaration)ret).getSpecifiers());
    }

		// Differentiate prototype and actual declaration (forward declaration)
		if ( ret instanceof ClassDeclaration &&
			((ClassDeclaration)ret).getTable().isEmpty() )
		{
			IDExpression class_name = ((ClassDeclaration)ret).getName();
			Traversable t = ret.getParent();
			while ( t != null )
			{
				if ( t instanceof SymbolTable )
					for ( Object child : t.getChildren() )
						if ( child instanceof ClassDeclaration &&
						((ClassDeclaration)child).getName().equals(class_name) &&
						!((ClassDeclaration)child).getTable().isEmpty() )
						{
							ret = (Declaration)child;
							break;
						}
				t = t.getParent();
			}
		}
    return ret;
  }

}
