package cetus.hir;

import java.io.*;
//import java.lang.reflect.*;
//import java.util.*;

/**
 * BitfieldSpecifier represents the bit field declared in a structure.
 */
public class BitfieldSpecifier extends Specifier
{
	private Expression bit;

	/**
	 * Constructs a bit field specifier from the given bit expression.
	 */
	public BitfieldSpecifier(Expression e)
	{
		bit = e;
	}

	/**
	 * Prints the specifier to the output stream.
	 *
	 * @param stream the output stream.
	 */
	public void print(OutputStream stream)
	{
		PrintStream p = new PrintStream(stream);

		p.print(" : ");
		bit.print(stream);
	}

	/**
	 * Returns the string for the bit field.
	 *
	 * @return the string.
	 */
	public String toString()
	{
		return (" : "+bit.toString());
	}

}
