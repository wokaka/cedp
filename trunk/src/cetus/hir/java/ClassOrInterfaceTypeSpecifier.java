package cetus.hir.java;

import cetus.hir.*;
import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** This class is no longer supported. */
public class ClassOrInterfaceTypeSpecifier extends Specifier
{
  private Expression expr;
  private List type_id;

  public ClassOrInterfaceTypeSpecifier(Expression expr)
  {
    this.expr = expr;
    this.type_id = null;
  }

  public ClassOrInterfaceTypeSpecifier(List type_id)
  {
    this.expr = null;
    this.type_id = type_id;
  }

  public void print(PrintWriter o)
  {
    if (expr != null)
      expr.print(o);
    else
      PrintTools.printListWithSpace(type_id, o);
  }
}
