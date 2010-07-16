package cetus.hir;

import java.io.*;

import java.lang.reflect.*;
/**
 * RangeExpression represents a symbolic range with a lower bound
 * expression and an upper bound expression. RangeAnalysis uses RangeExpression
 * to compute a valid value ranges of variables at program points.
 */
public class RangeExpression extends Expression
{

	private static Method class_print_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try
		{
      params[0] = RangeExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    }
		catch (NoSuchMethodException e)
		{
      throw new InternalError();
    }
  }

	/**
	 * Constructs a range expression with the given lower and upper bounds.
	 *
	 * @param lb the lower bound expression.
	 * @param ub the upper bound expression.
	 */
	public RangeExpression(Expression lb, Expression ub)
	{
		super(2);
		object_print_method = class_print_method;
		children.add(lb);
		children.add(ub);
		lb.setParent(this);
		ub.setParent(this);
	}

	/**
	 * Default print method
	 */
	public static void defaultPrint(RangeExpression range, OutputStream stream)
	{
		PrintStream p = new PrintStream(stream);

		p.print("[");
		range.getLB().print(stream);
		p.print(":");
		range.getUB().print(stream);
		p.print("]");
	}

	/**
	 * Returns the string representation of the range expression.
	 */
	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		str.append("[");
		str.append(getLB().toString());
		str.append(":");
		str.append(getUB().toString());
		str.append("]");

		return str.toString();
	}
	
	/**
	 * Checks if the given object is equal to this range expression.
	 *
	 * @param o the object to be compared.
	 */
	public boolean equals(Object o)
	{
		if ( !(o instanceof RangeExpression) )
			return false;
		return ( toString().equals(o.toString()) );
	}

	/**
	 * Compares the given expression with this range expression.
	 * @return 0 if they are equal, -1 otherwise.
	 */
	public int compareTo(Expression e)
	{
		return ( equals(e) )? 0: -1;
	}

	/**
	 * Sets the lower bound with the given expression.
	 * @param lb the new lower bound.
	 */
	public void setLB(Expression lb)
	{
		children.set(0,lb);
		lb.setParent(this);
	}

	/**
	 * Sets the upper bound with the given expression.
	 * @param ub the new upper bound
	 */
	public void setUB(Expression ub)
	{
		children.set(1,ub);
		ub.setParent(this);
	}

	/**
	 * Returns the lower bound of this range expression.
	 */
	public Expression getLB()
	{
		return (Expression)children.get(0);
	}

	/**
	 * Returns the upper bound of this range expression.
	 */
	public Expression getUB()
	{
		return (Expression)children.get(1);
	}


	/**
	 * Checks if this range expression has a lower bound greater than the upper
	 * bound. The comparison is possible only for literals and infinity
	 * expression.
	 */
	public boolean isEmpty()
	{
		Expression lb = getLB(), ub = getUB();
		return (
			lb instanceof InfExpression && ((InfExpression)lb).sign() > 0 ||
			ub instanceof InfExpression && ((InfExpression)ub).sign() < 0 ||
			lb instanceof IntegerLiteral && ub instanceof IntegerLiteral &&
				((IntegerLiteral)lb).getValue() > ((IntegerLiteral)ub).getValue() );
	}

	/**
	 * Checks if this range expression does not have any closed bounds.
	 */
	public boolean isOmega()
	{
		Expression lb = getLB(), ub = getUB();
		return (
			lb instanceof InfExpression && ((InfExpression)lb).sign() < 0 &&
			ub instanceof InfExpression && ((InfExpression)ub).sign() > 0);
	}


	/**
	 * Returns true if neither lb nor ub is infinity.
	 */
	public boolean isBounded()
	{
		Expression lb = getLB(), ub = getUB();
		return (!(lb instanceof InfExpression) && !(ub instanceof InfExpression));
	}


	/**
	 * Converts an arbitrary expression to a range expression by setting the same
	 * lower bound and upper bound.
	 */
	public static RangeExpression toRange(Expression e)
	{
		if ( e instanceof RangeExpression )
			return (RangeExpression)e.clone();
		return new RangeExpression((Expression)e.clone(), (Expression)e.clone());
	}


	/**
	 * Converts this range expression to a non-range expression if the lower bound
	 * is equal to the upper bound.
	 */
	public Expression toExpression()
	{
		if ( getLB().toString().equals(getUB().toString()) )
			return getLB();
		else
			return this;
	}

	/**
	 * Returns a new instanceof omega expression which is [-inf:inf].
	 * @return a new omega expression.
	 */
	public static Expression getOmega()
	{
		return new RangeExpression(new InfExpression(-1), new InfExpression(1));
	}
}
