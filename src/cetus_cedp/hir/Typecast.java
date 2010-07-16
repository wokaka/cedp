package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class Typecast extends Expression
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = Typecast.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  public static class Cast
  {
    private static String[] name =
      { "", "dynamic_cast", "static_cast",
        "reinterpret_cast", "const_cast" };

    private int value;

    public Cast(int value)
    {
      this.value = value;
    }

    public void print(OutputStream stream)
    {
      PrintStream p = new PrintStream(stream);
      p.print(name[value]);
    }
  }

  public static final Cast NORMAL  = new Cast(0);
  public static final Cast DYNAMIC = new Cast(1);
  public static final Cast STATIC  = new Cast(2);
  public static final Cast REINTERPRET = new Cast(3);
  public static final Cast CONST = new Cast(4);

  private Cast kind;
  private LinkedList<Specifier> specs;

  /**
   * Create a normal typecast.
   *
   * @param specs A list of type specifiers.
   * @param expr The expression to cast.
   */
  public Typecast(List<Specifier> specs, Expression expr)
  {
    object_print_method = class_print_method;

    kind = NORMAL;
    this.specs = (new ChainedList<Specifier>()).addAllLinks(specs);

    children.add(expr);
    expr.setParent(this);
  }

  /**
   * Create a special typecast.
   *
   * @param kind One of <var>NORMAL, DYNAMIC, STATIC, REINTERPRET,</var> or <var>CONST</var>.
   * @param specs A list of type specifiers.
   * @param expr The expression to cast.
   */
  public Typecast(Cast kind, List<Specifier> specs, Expression expr)
  {
    object_print_method = class_print_method;

    this.kind = kind;
    this.specs = (new ChainedList<Specifier>()).addAllLinks(specs);

    children.add(expr);
    expr.setParent(this);
  }

  public Typecast(Cast kind, Specifier spec, List<Expression> expr_list)
  {
    object_print_method = class_print_method;

    this.kind = kind;
    this.specs = (new ChainedList<Specifier>()).addLink(spec);

    for (Expression o : expr_list)
    {
      children.add(o);
      o.setParent(this);
    }
  }

  /**
   * Prints a typecast expression to a stream.
   *
   * @param cast The cast to print.
   * @param stream The stream on which to print the cast.
   */
  public static void defaultPrint(Typecast cast, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (cast.needs_parens)
      p.print("(");

    if (cast.kind == NORMAL)
    {
      if (cast.children.size() == 1)
      {
        p.print("(");
        Tools.printListWithSeparator(cast.specs, stream, " ");
        p.print(")");
        ((Printable)cast.children.get(0)).print(stream);
      }
      else
      {
        Tools.printListWithSeparator(cast.specs, stream, " ");
        p.print("(");
        Tools.printListWithSeparator(cast.children, stream, ",");
        p.print(")"); 
      }
    }
    else
    {
      cast.kind.print(stream);
      p.print("<");
      Tools.printList(cast.specs, stream);
      p.print(">(");
      ((Printable)cast.children.get(0)).print(stream);
      p.print(")");
    }

    if (cast.needs_parens)
      p.print(")");
  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

    if ( needs_parens )
			str.append("(");

    if ( kind == NORMAL )
    {
      if ( children.size() == 1 )
      {
				str.append("(");
        str.append(Tools.listToString(specs, " "));
        str.append(")");
				str.append(children.get(0).toString());
      }
      else
      {
				str.append(Tools.listToString(specs, " "));
				str.append("(");
				str.append(Tools.listToString(children, ","));
				str.append(")");
      }
    }
    else
    {
			str.append(kind.toString());
			str.append("<");
			str.append(Tools.listToString(specs, ""));
			str.append(">(");
			str.append(children.get(0).toString());
			str.append(")");
    }

    if ( needs_parens )
			str.append(")");

		return str.toString();
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

	public List<Specifier> getSpecifiers()
	{
		return specs;
	}
}
