package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class QualifiedID extends IDExpression
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = QualifiedID.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  public QualifiedID(List<IDExpression> id_expr_list)
  {
    super(false);

    object_print_method = class_print_method;
    children.addAll(id_expr_list);
  }

  public QualifiedID(boolean global, List<IDExpression> id_expr_list)
  {
    super(global);

    object_print_method = class_print_method;
    children.addAll(id_expr_list);
  }

  /**
   * This method returns the list of IDs in the qualified ID
   */
  public LinkedList<IDExpression> getIDExpressionList()
  {
    LinkedList<IDExpression> ret = new LinkedList<IDExpression>();
    for(int i = 0; i < children.size(); i++)
      ret.add((IDExpression)children.get(i));
    return ret;
  }

  public Object clone()
  {
    QualifiedID o = (QualifiedID)super.clone();
    return o;
  }

  /**
   * Prints an identifier to a stream.
   *
   * @param ident The identifier to print.
   * @param stream The stream on which to print the identifier.
   */
  public static void defaultPrint(QualifiedID ident, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (ident.typename)
      p.print("typename ");

    if (ident.global)
      p.print("::");

    Tools.printListWithSeparator(ident.children, stream, "::");
  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		if ( typename )
			str.append("typename ");

		if ( global )
			str.append("::");

		str.append(Tools.listToString(children, "::"));

		return str.toString();
	}
}
