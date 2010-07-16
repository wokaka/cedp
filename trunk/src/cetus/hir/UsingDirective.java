package cetus.hir;

import java.util.*;

public class UsingDirective extends Declaration
{

  public List<IDExpression> getDeclaredSymbols()
  {
    return new LinkedList<IDExpression>();
  }

	public String toString()
	{
		return "";
	}
}
