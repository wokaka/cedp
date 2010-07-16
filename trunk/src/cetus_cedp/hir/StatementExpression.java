package cetus.hir;

import java.io.*;
import java.lang.reflect.*;

/**
 * This is a GCC extension.
 */
public class StatementExpression extends Expression
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = StatementExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  public StatementExpression(CompoundStatement stmt)
  {
    object_print_method = class_print_method;

    children.add(stmt);
    stmt.setParent(this);
  }

  public static void defaultPrint(StatementExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("(");
    expr.getStatement().print(stream);
    p.print(")");
  }

	public String toString()
	{
		return ("(" + getStatement().toString() + ")");
	}

  public CompoundStatement getStatement()
  {
    return (CompoundStatement)children.get(0);
  }
}
