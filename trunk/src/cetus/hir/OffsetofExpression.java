package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class OffsetofExpression extends Expression implements Intrinsic
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = OffsetofExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private LinkedList<Specifier> specs;

  public OffsetofExpression(List<Specifier> pspecs, Expression expr)
  {
    object_print_method = class_print_method;

    children.add(expr);
    expr.setParent(this);

    specs = new LinkedList<Specifier>();
    specs.addAll(pspecs);

  }

  /**
   * Prints a __builtin_offsetof expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(OffsetofExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("__builtin_offsetof");

    p.print("(");
    Tools.printListWithSeparator(expr.specs, stream, " ");
    p.print(",");
    expr.getExpression().print(stream);
    p.print(")");
  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		str.append("__builtin_offsetof");
		str.append("(");
		str.append(Tools.listToString(specs, " "));
		str.append(",");
		str.append(getExpression().toString());
		str.append(")");

		return str.toString();
	}

  /**
   * Returns the expression.
   *
   * @return the expression that is the second parameter
   * to this function (member-designator)
   */
  public Expression getExpression()
  {
      return (Expression)children.get(0);
  }

	public List<Specifier> getSpecifiers()
	{
		return specs;
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
