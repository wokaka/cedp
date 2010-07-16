package cetus.hir;

import java.io.*;
import java.util.*;

public class ConstructorInitializer extends Initializer
{
  public ConstructorInitializer(List<? extends Traversable> values)
  {
    for (Object o : values)
    {
      children.add((Traversable)o);
      ((Traversable)o).setParent(this);
    }
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("(");
    Tools.printListWithCommas(children, stream);
    p.print(")");
  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		str.append("(");
		str.append(Tools.listToString(children, ", "));
		str.append(")");

		return str.toString();
	}
}
