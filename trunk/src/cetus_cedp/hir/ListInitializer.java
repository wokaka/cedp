package cetus.hir;

import java.io.*;
import java.util.*;

public class ListInitializer extends Initializer
{
  public ListInitializer(List<Object> values)
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
    p.print(" = { ");
    Tools.printListWithCommas(children, stream);
    p.print(" } ");
  }

	public String toString()
	{
		return (" = { " + Tools.listToString(children, ", ") + " } ");
	}
}
