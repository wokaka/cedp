package cetus.hir;

import java.io.*;
//import java.lang.reflect.*;
import java.util.*;

/**
 * Represents an array specifier, for example the bracketed
 * parts of <var>int array[20][30];</var>
 */
public class ArraySpecifier extends Specifier
{
  /** The unbounded specifier [] */
  public static final ArraySpecifier UNBOUNDED = new ArraySpecifier();

  private List<Expression> dimensions;

  public ArraySpecifier()
  {
    dimensions = new LinkedList<Expression>();
    dimensions.add(null);
  }

  public ArraySpecifier(Expression expr)
  {
    dimensions = new LinkedList<Expression>();
    dimensions.add(expr);
  }
  
  public ArraySpecifier(List<Expression> dimensions)
  {
    setDimensions(dimensions);
  }

  /**
   * Gets the nth dimension of this array specifier.
   *
   * @param n The position of the dimension.
   * @throws IndexOutOfBoundsException if there is no expression at that position.
   * @return the nth dimension, which may be null.  A null dimension occurs
   *   for example with int array[][8].
   */
  public Expression getDimension(int n)
  {
    return dimensions.get(n);
  }

  /**
   * Returns the number of index expressions used in this array specifier.
   *
   * @return the number of index expressions.
   */
  public int getNumDimensions()
  {
    return dimensions.size();
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
/*
    Iterator iter = dimensions.iterator();
    while (iter.hasNext())
    {
      p.print("[");

      Object o = iter.next();
      if (o != null)
        ((Printable)o).print(stream);

      p.print("]");
    }
*/
		for(Expression o : dimensions)
		{
      p.print("[");
      if (o != null)
        o.print(stream);
      p.print("]");
		}
  }

	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		for ( Object o : dimensions )
		{
			str.append("[");
			if ( o != null )
				str.append(o.toString());
			str.append("]");
		}

		return str.toString();
	}

  /**
   * Sets the nth dimension of this array specifier.
   *
   * @param n The position of the dimension.
   * @param expr The expression defining the size of the dimension.
   * @throws IndexOutOfBoundsException if there is no dimension at that position.
   */
  public void setDimension(int n, Expression expr)
  {
    dimensions.set(n, expr);
  }

  /**
   * Set the list of dimension expressions.
   *
   * @param dimensions A list of expressions.
   */
  public void setDimensions(List<Expression> dimensions)
  {
    if (dimensions == null)
      throw new IllegalArgumentException();

    this.dimensions = new LinkedList<Expression>();
    this.dimensions.addAll(dimensions);
/*    Iterator<Expression> iter = dimensions.iterator();
    while (iter.hasNext())
    {
      this.dimensions.add(iter.next());
    }
*/
  }
}
