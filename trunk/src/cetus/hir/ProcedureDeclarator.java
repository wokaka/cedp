package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a declarator for a Procedure in
 * a VariableDeclaration.
 */
public class ProcedureDeclarator extends Declarator implements Symbol
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = ProcedureDeclarator.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private ExceptionSpecification espec;

  private void initialize(IDExpression direct_decl, List<Declaration> params)
  {
    object_print_method = class_print_method;
    trailing_specs = new LinkedList<Specifier>();

    if (direct_decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(direct_decl);
    direct_decl.setParent(this);
/*
    Iterator iter = params.iterator();
    while (iter.hasNext())
    {
      Declaration decl = (Declaration)iter.next();

      if (decl.getParent() != null)
        throw new NotAnOrphanException();

      children.add(decl);
      decl.setParent(this);
    }
*/
		for(Declaration decl : params)
		{
      if (decl.getParent() != null)
        throw new NotAnOrphanException();

      children.add(decl);
      decl.setParent(this);
		}
  }

  public ProcedureDeclarator(IDExpression direct_decl, List<Declaration> params)
  {
    super(1 + params.size());
    initialize(direct_decl, params);
  }

  public ProcedureDeclarator(IDExpression direct_decl, List<Declaration> params, List<Specifier> trailing_specs)
  {
    super(1 + params.size());
    initialize(direct_decl, params);
    this.trailing_specs.addAll(trailing_specs); 
  }

  public ProcedureDeclarator(List<Specifier> leading_specs, IDExpression direct_decl, List<Declaration> params)
  {
    super(1 + params.size());
    initialize(direct_decl, params);
    this.leading_specs.addAll(leading_specs);
  }

  public ProcedureDeclarator(List<Specifier> leading_specs, IDExpression direct_decl,
    List<Declaration> params, List<Specifier> trailing_specs, ExceptionSpecification espec)
  {
    super(1 + params.size());
    initialize(direct_decl, params);
    this.leading_specs.addAll(leading_specs);
    this.trailing_specs.addAll(trailing_specs);
    this.espec = espec;
  }

  public void addParameter(Declaration decl)
  {
    if (decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(decl);
    decl.setParent(this);
  }

  public void addParameterBefore(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref);

    if (index == -1)
      throw new IllegalArgumentException();

    if (decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(index, decl);
    decl.setParent(this);
  }

  public void addParameterAfter(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref);

    if (index == -1)
      throw new IllegalArgumentException();

    if (decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(index + 1, decl);
    decl.setParent(this);
  }

  /* **AP**
    Adding method for removing parameters from declarator list
  */
  public void removeParameter(Declaration decl)
  {
    int index = Tools.indexByReference(children, decl);

    if (index == -1)
      throw new IllegalArgumentException();

    decl.setParent(null);
    children.remove(decl);
  }


  public Object clone()
  {
    ProcedureDeclarator d = (ProcedureDeclarator)super.clone();
    IDExpression id  = (IDExpression)getDirectDeclarator().clone();
    d.children.add(id);	
    id.setParent(d);
    if (children.size() > 1)
    {
      List<Traversable> tmp = (new ChainedList<Traversable>()).addAllLinks(children);
      tmp.remove(0);
      Iterator<Traversable> iter = tmp.iterator();
      while (iter.hasNext())
      {
         Declaration decl = (Declaration)iter.next();

         decl = (Declaration)decl.clone();
         d.children.add(decl);
         decl.setParent(d);
     }
      
    }
    d.leading_specs = (new ChainedList<Specifier>()).addAllLinks(leading_specs);
    d.trailing_specs = (new ChainedList<Specifier>()).addAllLinks(trailing_specs);
    d.espec = espec;

    return d;
  }

  /**
   * Prints a procedure declarator to a stream.
   *
   * @param dec The declarator to print.
   * @param stream The stream on which to print the declarator.
   */
  public static void defaultPrint(ProcedureDeclarator dec, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    Tools.printList(dec.leading_specs, stream);

	dec.getDirectDeclarator().print(stream);
   
    if (dec.children.size() > 1)
    {
      List<Traversable> tmp = (new ChainedList<Traversable>()).addAllLinks(dec.children);
      tmp.remove(0);
      p.print("(");
      Tools.printListWithCommas(tmp, stream);
      p.print(")");
    }
	else
		p.print("(  )");
    Tools.printListWithSeparator(dec.trailing_specs, stream, " ");

    

  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		str.append(Tools.listToString(leading_specs, ""));
		str.append(getDirectDeclarator().toString());

		if ( children.size() > 1 )
		{
      List<Traversable> tmp = (new ChainedList<Traversable>()).addAllLinks(children);
      tmp.remove(0);
			str.append("(" + Tools.listToString(tmp, ", ") + ")");
		}
		else
			str.append("(  )");

		str.append(Tools.listToString(trailing_specs, " "));

		return str.toString();
	}

  public IDExpression getDirectDeclarator()
  {
    return (IDExpression)children.get(0);
  }

  public List<Declaration> getParameters()
  {
    List<Declaration> tmp = new ChainedList<Declaration>();
    for(int i = 1; i < children.size(); i++)
      tmp.add((Declaration)children.get(i));
    return tmp;
  }

  /**
   * Returns the symbol declared by this declarator.
   */
  public IDExpression getSymbol()
  {
    return getDirectDeclarator();
  }

  /**
   * Overrides the class print method, so that all subsequently
   * created objects will use the supplied method.
   *
   * @param m The new print method.
   */
  static public void setClassPrintMethod(Method m)
  {
    class_print_method = m;
  }

	// Symbol interface
	public String getSymbolName()
	{
		return getDirectDeclarator().toString();
	}

	public List<Specifier> getTypeSpecifiers()
	{
		Traversable t = this;
		while ( !(t instanceof Declaration) )
			t = t.getParent();
		List<Specifier> ret = new LinkedList<Specifier>();
		if ( t instanceof VariableDeclaration )
			ret.addAll(((VariableDeclaration)t).getSpecifiers());
		else
			return null;
		ret.addAll(leading_specs);

		return ret;
	}

	public List<Specifier> getArraySpecifiers()
	{
		return null;
	}
}
