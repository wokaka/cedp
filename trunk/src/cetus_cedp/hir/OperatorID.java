package cetus.hir;

import java.io.*;

/**
 * C++ overloaded operator IDs.
 */
public class OperatorID extends IDExpression
{
  private String name;

  public OperatorID(String name)
  {
    super(false);
    this.name = name;
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("operator " + name);
  }

	public String toString()
	{
		return ("operator " + name);
	}
}
