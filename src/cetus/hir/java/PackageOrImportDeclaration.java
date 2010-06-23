package cetus.hir.java;

import cetus.hir.*;
import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class PackageOrImportDeclaration extends Declaration
{
  private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = PackageOrImportDeclaration.class;
      params[1] = PrintWriter.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private IDExpression expr;
  private List specifier;

  public PackageOrImportDeclaration()
  {
      super();
  }
  
  public PackageOrImportDeclaration(Specifier spec, IDExpression expr)
  {
      super();
      object_print_method = class_print_method;
      this.specifier = new LinkedList();
      this.specifier.add(spec);
      this.expr = expr;

      if(expr != null)
            addChild(expr);
  }

  public PackageOrImportDeclaration(List spec, IDExpression expr)
  {
      super();
      object_print_method = class_print_method;
      this.specifier = spec;
      this.expr = expr;

      if(expr != null)
            addChild(expr);
  }

  public void AddSpecifier(Specifier spec)
  {
      if(specifier == null)
              specifier = new LinkedList();
      specifier.add(spec);
  }
  
  protected void addChild(Traversable t)
  {
    if (t.getParent() != null)
      throw new NotAnOrphanException(this.getClass().getName());
    children.add(t);
    t.setParent(this);
  }
  
  public static void defaultPrint(PackageOrImportDeclaration d, PrintWriter o)
  {
      if(d.specifier != null){
        for(int i=0; i<d.specifier.size(); i++){
            if(d.specifier.get(i) == Specifier.PACKAGE)
                o.print("package ");
            else if(d.specifier.get(i) == Specifier.IMPORT)
                o.print("import ");
            else if(d.specifier.get(i) == Specifier.STATIC)
                o.print("static ");
        }
      }
      
    d.expr.print(o);
    o.print(";");
  }

  public List getDeclaredIDs()
  {
    return new LinkedList();
  }
}
