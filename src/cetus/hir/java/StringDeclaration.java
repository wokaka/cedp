package cetus.hir.java;

import cetus.hir.Declaration;
import cetus.hir.NameID;
import cetus.hir.NotAnOrphanException;
import cetus.hir.PrintTools;
import cetus.hir.Traversable;
import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Represents expressions separated by the comma
 * operator in C or C++.  The entire expression evaluates
 * to the last expression in the list.
 */
public class StringDeclaration extends Declaration
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = StringDeclaration.class;
      params[1] = PrintWriter.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  public String str;
  
  public StringDeclaration(String s)
  {
      super();
      str = s;
  }

  /**
  * Constructs a comma expression from the specified list of expressions.
  *
  * @param expr_list the list of new expressions.
  * @throws IllegalArgumentException if <b>expr_list</b> is a singleton or null.
  * @throws NotAnOrphanException if an element of <b>expr_list</b> has a parent
  * object.
  */
  public StringDeclaration(List expr_list)
  {
    super();
    object_print_method = class_print_method;

    if (expr_list == null || expr_list.size() < 1 /* allow one element list, different from CommaExpression */)
      throw new IllegalArgumentException();

    for(Traversable expr : (List<Traversable>)expr_list)
      if(expr != null)
           addChild(expr);
  }

  /**
  * Inserts a new expression at the end of the expression list.
  *
  * @param expr the new expression to be inserted.
  * @throws IllegalArgumentException if <b>expr</b> is null.
  * @throws NotAnOrphanException if <b>expr</b> has a parent object.
  */
  protected void addChild(Traversable t)
  {
    if (t.getParent() != null)
      throw new NotAnOrphanException(this.getClass().getName());
    children.add(t);
    t.setParent(this);
  }

  @Override
  public StringDeclaration clone()
  {
    StringDeclaration o = (StringDeclaration)super.clone();
    return o; 
  }

  /**
   * Prints a CommaExpression to a stream.
   *
   * @param e The expression to print.
   * @param o The writer on which to print the expression.
   */
  public static void defaultPrint(StringDeclaration e, PrintWriter o)
  {
    if(e.str != null)
        o.print(e.str);
    else
      PrintTools.printList(e.children, o);
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

  @Override
  public List getDeclaredIDs()
  {
      List list = new LinkedList();

      if(str != null){
          list.add(new NameID(str));
      }
      else{
          for(int i=0; i<children.size(); i++){
              list.add(new NameID(children.get(i).toString()));
          }
      }
      
      return list;
  }

  public String toString()
  {
      if(str != null)
        return str;

      String buffer = "";
      for(int i=0; i<children.size(); i++){
          buffer += children.get(i).toString() + " ";
      }
      return buffer;
  }
}
