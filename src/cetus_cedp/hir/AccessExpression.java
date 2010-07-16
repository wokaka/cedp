package cetus.hir;

import java.io.*;
//import java.lang.reflect.*;

public class AccessExpression extends BinaryExpression
{
/*
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = AccessExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }
*/

  /**
   * Creates an assignment expression.
   *
   * @param lhs The lefthand expression.
   * @param op An assignment operator.
   * @param rhs The righthand expression.
   */
  public AccessExpression(Expression lhs, AccessOperator op, Expression rhs)
  {
    super(lhs, op, rhs);
    setParens(false);
    rhs.setParens(false);
  }

  public Object clone()
  {
    return super.clone();
  }

  /**
   * Prints an assignment expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(AccessExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("(");
    ((Printable)expr.children.get(0)).print(stream);
    expr.op.print(stream);
    ((Printable)expr.children.get(1)).print(stream);
    p.print(")");
  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		if ( needs_parens )
			str.append("(");

		str.append(children.get(0).toString());
		str.append(op.toString());
		str.append(children.get(1).toString());

		if ( needs_parens )
			str.append(")");

		return str.toString();
	}

  /**
   * Returns the operator of the expression.
   *
   * @return the operator.
   */
  public BinaryOperator getOperator()
  {
    return op;
  }

  /**
   * Overrides the class print method, so that all subsequently
   * created objects will use the supplied method.
   *
   * @param m The new print method.
   */
/*
  static public void setClassPrintMethod(Method m)
  {
    class_print_method = m;
  }
*/

  /**
   * Sets the operator for the expression.
   *
   * @param op The operator.
   */
  public void setOperator(AccessOperator op)
  {
    this.op = op;
  }

	// Returns a symbol object.
	public Symbol getSymbol()
	{
		return new AccessSymbol(this);
	}
}
