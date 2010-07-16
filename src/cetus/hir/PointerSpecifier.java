package cetus.hir;

import java.io.*;
import java.util.*;

/** Represents a C or C++ pointer. */
public class PointerSpecifier extends Specifier
{
  /** * */
  public static final PointerSpecifier UNQUALIFIED = new PointerSpecifier();

  /** * const */
  public static final PointerSpecifier CONST =
    new PointerSpecifier((new ChainedList<Specifier>()).addLink(Specifier.CONST));

  /** * volatile */
  public static final PointerSpecifier VOLATILE =
    new PointerSpecifier((new ChainedList<Specifier>()).addLink(Specifier.VOLATILE));

  /** * const volatile */
  public static final PointerSpecifier CONST_VOLATILE =
    new PointerSpecifier((new ChainedList<Specifier>()).addLink(Specifier.CONST).addLink(Specifier.VOLATILE));

  private List<Specifier> qualifiers;

  private PointerSpecifier()
  {
    qualifiers = null;
  }

  private PointerSpecifier(List<Specifier> qualifiers)
  {
    this.qualifiers = qualifiers;
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("*");
    Tools.printList(qualifiers, stream);
    p.print(" ");
  }

	public String toString()
	{
		return ("*" + Tools.listToString(qualifiers, "") + " ");
	}
}
