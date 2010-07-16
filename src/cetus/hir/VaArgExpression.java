package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class VaArgExpression extends Expression implements Intrinsic
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = VaArgExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private LinkedList<Specifier> specs;

  public VaArgExpression(Expression expr, List<Specifier> pspecs)
  {
    object_print_method = class_print_method;

    children.add(expr);
    expr.setParent(this);

    specs = new LinkedList<Specifier>();
    specs.addAll(pspecs);

  }

/*
  public Object clone()
  {
    SizeofExpression o = (SizeofExpression)super.clone();
    return o;
  }
*/
  /**
   * Prints a __builtin_va_arg expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(VaArgExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("__builtin_va_arg");

    p.print("(");
    expr.getExpression().print(stream);
    p.print(",");
    Tools.printListWithSeparator(expr.specs, stream, " ");
    p.print(")");
  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		str.append("__builtin_va_arg");
		str.append("(");
		str.append(getExpression().toString());
		str.append(",");
		str.append(Tools.listToString(specs, " "));
		str.append(")");

		return str.toString();
	}

  /**
   * Returns the expression.
   *
   * @return the expression or null if this sizeof operator is
   *   being applied to a type.
   */
  public Expression getExpression()
  {
      return (Expression)children.get(0);
  }

	/**
	 * Returns the type argument which is also the type of return value.
	 *
	 * @return the list of specifiers.
	 */
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
