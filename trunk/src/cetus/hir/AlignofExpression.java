package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class AlignofExpression extends Expression implements Intrinsic
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = AlignofExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private LinkedList<Specifier> specs;

  public AlignofExpression(Expression expr)
  {
    object_print_method = class_print_method;

    specs = null;

    children.add(expr);
    expr.setParent(this);
  }

  public AlignofExpression(List<Specifier> pspecs)
  {
    object_print_method = class_print_method;
// This part breaks in 176.gcc
/*
    if (!Tools.verifyHomogeneousList(specs, Specifier.class))
      throw new IllegalArgumentException();
*/

    specs = new LinkedList<Specifier>();
    specs.addAll(pspecs);
  }

  /**
   * Prints an alignof expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(AlignofExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("__alignof__ ");

    if (expr.specs != null)
    {
      p.print("(");
      Tools.printListWithSeparator(expr.specs, stream, " ");
      p.print(")");
    }
    else
    {
      expr.getExpression().print(stream);
    }
  }


	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		str.append("__alignof__ ");
		if ( specs != null )
			str.append("("+Tools.listToString(specs, " ")+")");
		else
			str.append(getExpression().toString());

		return str.toString();
	}


  /**
   * Returns the expression.
   *
   * @return the expression or null if this alignof operator is
   *   being applied to a type.
   */
  public Expression getExpression()
  {
    if (specs == null)
      return (Expression)children.get(0);
    else
      return null;
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
}
