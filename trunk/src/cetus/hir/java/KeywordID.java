package cetus.hir.java;

import cetus.hir.*;
import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * C++ overloaded operator IDs. This class is no longer supported.
 */
public class KeywordID extends IDExpression
{
  private String name;

  public KeywordID(String name)
  {
    super(false);
    this.name = name;
  }

  public void print(PrintWriter o)
  {
    o.print("" + name);
  }

  @Override
  public boolean equals(Object o)
  {
    return (
        super.equals(o) &&
        name.equals(((KeywordID)o).name)
    );
  }
}
