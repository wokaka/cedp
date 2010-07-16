package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a nested declarator that may appear
 * as part of another declarator.
 */
public class NestedDeclarator extends Declarator implements Symbol
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = NestedDeclarator.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }
  private boolean has_param=false; 
  private void initialize(Declarator nested_decl, List<Declaration> params)
  {
    object_print_method = class_print_method;
	trailing_specs = new LinkedList<Specifier>();
    if (nested_decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(nested_decl);
    nested_decl.setParent(this);
	if(params != null){
		has_param = true;
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
  }

  public NestedDeclarator(Declarator nested_decl)
  {
    super(1);
    initialize(nested_decl, null);
  }

  public NestedDeclarator(Declarator nested_decl, List<Declaration> params)
  {
    super(params == null ? 1:1 + params.size());
    initialize(nested_decl, params);
  }

  public NestedDeclarator(List<Specifier> leading_specs, Declarator nested_decl, List<Declaration> params)
  {
    super(params == null ? 1:1 + params.size());
    initialize(nested_decl, params);
    this.leading_specs.addAll(leading_specs);
  }

  public NestedDeclarator(Specifier spec, Declarator nested_decl, List<Declaration> params)
  {
    super(params == null ? 1:1 + params.size());
    initialize(nested_decl, params);
    leading_specs.add(spec);
  }
  public NestedDeclarator(List<Specifier> leading_specs, Declarator nested_decl, List<Declaration> params, List<Specifier> trailing_specs)
  {
  	super(params == null ? 1:1 + params.size());
    initialize(nested_decl, params);
    this.leading_specs.addAll(leading_specs);
    this.trailing_specs.addAll(trailing_specs);
  }
  public void addParameter(Declaration decl)
  {
  	has_param = true;
    if (decl.getParent() != null)
      throw new NotAnOrphanException();
	if(getInitializer() == null)
    	children.add(decl);
    else
    	children.add(children.size()-1,decl);
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

  public Object clone()
  {
    NestedDeclarator d = (NestedDeclarator)super.clone();
    Declarator id  = (Declarator)getDeclarator().clone();
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
    d.has_param = has_param; 
    d.leading_specs = (new ChainedList<Specifier>()).addAllLinks(leading_specs);
    d.trailing_specs = (new ChainedList<Specifier>()).addAllLinks(trailing_specs);
    return d;
  }

  /**
   * Prints a nested declarator to a stream.
   *
   * @param dec The declarator to print.
   * @param stream The stream on which to print the declarator.
   */
  public static void defaultPrint(NestedDeclarator dec, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    Tools.printListWithSeparator(dec.leading_specs, stream, " ");
    p.print("(");
    dec.getDeclarator().print(stream);
    p.print(")");
	if(dec.has_param){
		if (dec.children.size() > 1)
	    {
	      List<Traversable> tmp = (new ChainedList<Traversable>()).addAllLinks(dec.children);
	      // remove Initializer
	      if(dec.getInitializer() != null)
	      	tmp.remove(tmp.size()-1);
	      // remove Declarator
	      tmp.remove(0);
	      p.print("(");
	      if(!tmp.isEmpty())
	      	Tools.printListWithCommas(tmp, stream);
	      p.print(")");
	    }
	    else
	      p.print("( )");
    }
    Tools.printListWithSeparator(dec.trailing_specs, stream, " ");
    if(dec.getInitializer() != null)
    	dec.getInitializer().print(stream);
  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		str.append(Tools.listToString(leading_specs, " "));
		str.append("(");
		str.append(getDeclarator().toString());
		str.append(")");

		if ( has_param )
		{
			if ( children.size() > 1 )
			{
	      List<Traversable> tmp = (new ChainedList<Traversable>()).addAllLinks(children);
	      // remove Initializer
	      if( getInitializer() != null )
	      	tmp.remove(tmp.size()-1);
	      // remove Declarator
	      tmp.remove(0);
				str.append("(");
	      if( !tmp.isEmpty() )
					str.append(Tools.listToString(tmp, ", "));
				str.append(")");
			}
			else
				str.append("( )");
		}
		str.append(Tools.listToString(trailing_specs, " "));
		if ( getInitializer() != null )
			str.append(getInitializer().toString());

		return str.toString();
	}

  public Declarator getDeclarator()
  {
    return (Declarator)children.get(0);
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
    return getDeclarator().getDirectDeclarator();
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
  public Initializer getInitializer()
  {
  	if(!children.isEmpty())
    if (children.get(children.size()-1) instanceof Initializer)
      return (Initializer)children.get(children.size()-1);
    
    return null;
  }
  
  public void setInitializer(Initializer init)
  {
    if (getInitializer() != null)
    {
      getInitializer().setParent(null);
      
      if (init != null)
      {
        children.set(children.size()-1,init);
        init.setParent(this);
      }
     
    }
    else
    {
      if (init != null)
      {
        children.add(init);
        init.setParent(this);
      }
     
    }
  }

	// Symbol interface
	public String getSymbolName()
	{
		//return getDirectDeclarator().toString();
		return getSymbol().toString();
	}

	public List<Specifier> getTypeSpecifiers()
	{
		Traversable t = this;
		while ( !(t instanceof Declaration) )
			t = t.getParent();
		List<Specifier> ret = new LinkedList<Specifier>();
		if ( t instanceof VariableDeclaration )
			ret.addAll(((VariableDeclaration)t).getSpecifiers());
		else if ( t instanceof Enumeration )
			ret.add(new UserSpecifier(new Identifier(
				"enum "+((Enumeration)t).getDeclaredSymbols().get(0))));
		else
			return null;
		ret.addAll(leading_specs);

		return ret;
	}

	public List<Specifier> getArraySpecifiers()
	{
		return trailing_specs;
	}

	public boolean isProcedure()
	{
		return has_param;
	}

}
