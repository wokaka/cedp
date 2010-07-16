package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import cetus.analysis.*;

/**
 * Class for MIN() MAX() expressions - these are equivalent to conditional
 * expressions.
 */
public class MinMaxExpression extends Expression
{
	private static Method class_print_method;

	// MIN:true, MAX:false
	private boolean ismin;

	// Default print method
  static
  {
    try {
			class_print_method = MinMaxExpression.class.getMethod("defaultPrint",
				new Class[] {MinMaxExpression.class, OutputStream.class} );
    } catch (NoSuchMethodException ex) {
      throw new InternalError();
    }
  }


	/**
	 * Prints out MIN/MAX expressions.
	 */
	public static void defaultPrint(MinMaxExpression minmax, OutputStream stream)
	{
		PrintStream p = new PrintStream(stream);

		p.print((minmax.ismin)? "MIN(": "MAX(");

		int i=0;
		for ( Object child : minmax.children )
		{
			if ( i++ > 0 )
				p.print(",");
			((Expression)child).print(stream);
		}

		p.print(")");
	}


	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		if ( ismin )
			str.append("MIN(");
		else
			str.append("MAX(");

		str.append(Tools.listToString(children, ","));
		str.append(")");

		return str.toString();
	}


	/**
   * Constructor with predefined min/max operator.
   * @param ismin true if the operator is MIN, false otherwise
   */	
	public MinMaxExpression(boolean ismin)
	{
		super(2);
		object_print_method = class_print_method;
		this.ismin = ismin;
	}


	/**
   * Constructor with two operands.
   * @param ismin true if the operator is MIN, false otherwise
   * @param lhs   the first operand
   * @param rhs   the second operand
   */
	public MinMaxExpression(boolean ismin, Expression lhs, Expression rhs)
	{
		this(ismin);
		children.add(lhs);
		children.add(rhs);
		lhs.setParent(this);
		rhs.setParent(this);
	}


	/**
   * Returns true if this is a MIN expression.
   * @return true if this is a MIN expression, false otherwise
   */
	public boolean isMin()
	{
		return ismin;
	}


	/**
   * Sets the expression type.
   * @param ismin true for MIN, false for MAX
   */
	public void setMin(boolean ismin)
	{
		this.ismin = ismin;
	}


	/**
   * Adds an operand to the existing expression.
   * @param e the new operand to be appended
   */
	public void add(Expression e)
	{
		children.add(e);
		e.setParent(this);
	}


	/**
   * Negates the expression by switching the operator and the signs of the
   * operands.
   * @return the negated expression
   */
	public Expression negate()
	{
		MinMaxExpression ret = new MinMaxExpression(!ismin);
		for ( Object o : children )
			ret.add(NormalExpression.subtract(new IntegerLiteral(0), (Expression)o));
		return ret;
	}


	/**
   * Checks if this expression is a MIN expression having at least one operand
   * with positive value.
   * @return true/false
   */
	public boolean isPosMax()
	{
		if ( ismin )
			return false;

		for ( Object o: children )
			if ( o instanceof IntegerLiteral && ((IntegerLiteral)o).getValue() > 0 )
				return true;

		return false;
	}


	/**
   * Checks if this expression is a MIN expression having at least one operand
   * with negative value.
   * @return true/false
   */
	public boolean isNegMin()
	{
		if ( !ismin )
			return false;

		for ( Object o: children )
			if ( o instanceof IntegerLiteral && ((IntegerLiteral)o).getValue() < 0 )
				return true;

		return false;
	}


	// Return a non-minmax expression if comparison is handy
	// Only IntegerLiteral and Inf are captured
	private Expression resolve()
	{
		long prev=0, curr=0;

		for ( Object o: children )
		{
			if ( !(o instanceof IntegerLiteral) && !(o instanceof InfExpression) )
				return this;

			if ( o instanceof IntegerLiteral )
				curr = ((IntegerLiteral)o).getValue();
			else
				//curr = (((InfExpression)o).isMinus())? Long.MIN_VALUE: Long.MAX_VALUE;
				curr = (((InfExpression)o).sign()<0)? Long.MIN_VALUE: Long.MAX_VALUE;

			if ( o==children.get(0) || curr<prev && ismin || curr>prev && !ismin )
				prev = curr;
		}

		if ( prev == Long.MIN_VALUE || prev == Long.MAX_VALUE )
			//return new InfExpression(prev==Long.MIN_VALUE);
			return new InfExpression((prev<0)?-1:1);
		else
			return new IntegerLiteral(prev);
	}


	/**
   * Simplifies a MinMaxExpression as much as possible by removing duplicates
   * and by matching special cases.
   * @return A simplified expression
   */
	// Remove duplicates and matches MIN(MAX(a,b),a)
	public Expression simplify()
	{
		Set<Object> unique_children = new TreeSet<Object>(); // TreeSet uses compareTo method.

		for ( Object child : children )
			unique_children.add(child);

		// Only one unique child
		if ( unique_children.size() == 1 )
			return (Expression)children.get(0);

		MinMaxExpression ret = new MinMaxExpression(ismin);
		for ( Object child : unique_children )
			ret.add((Expression)child);

		if ( ret.children.size() == 2 )
		{
		// Match simplifiable cases
		Expression e1 = (Expression)ret.children.get(0);
		Expression e2 = (Expression)ret.children.get(1);

		if ( e1 instanceof MinMaxExpression && e1.getChildren().size() == 2 &&
			((MinMaxExpression)e1).isMin() != ret.isMin() &&
			(e2.equals(e1.getChildren().get(0))||e2.equals(e1.getChildren().get(1))) )
			return e2;

		else if ( e2 instanceof MinMaxExpression && e2.getChildren().size() == 2 &&
			((MinMaxExpression)e2).isMin() != ret.isMin() &&
			(e1.equals(e2.getChildren().get(0))||e1.equals(e2.getChildren().get(1))) )
			return e1;
		}

		return ret.resolve();
	}


	/**
   * Compares MinMaxExpression to another expression.
   */
	public int compareTo(Expression e)
	{
		if ( e instanceof MinMaxExpression )
		{
			if ( ismin == ((MinMaxExpression)e).ismin )
				return super.compareTo(e);
			else
				return -1;
		}
		else
			return -1;
	}


	/**
   * Compares MinMaxExpression to an integer value.
   * @param num an integer value
   * @return Integer object if comparison is possible, null otherwise
   */
	public Integer compareTo(int num)
	{
		for ( Object o: children )
		{
			if ( o instanceof IntegerLiteral )
			{
				if ( ismin && ((IntegerLiteral)o).getValue() < num )
					return new Integer(-1);
				else if ( !ismin && ((IntegerLiteral)o).getValue() > num )
					return new Integer(1);
			}
		}
		return null;
	}


	/**
   * Converts MinMaxExpression to an equivalent conditional expression.
   * @return the converted conditional expression
   */
	public Expression toConditionalExpression()
	{
		Expression ret = (Expression)((Expression)children.get(0)).clone();

		//BinaryOperator rel = ismin?
		//	BinaryOperator.COMPARE_LE: BinaryOperator.COMPARE_GE;

		for ( int i=1; i<children.size(); ++i )
		{
			ret = new ConditionalExpression(
				new BinaryExpression(
					(Expression)ret.clone(),
					(ismin? BinaryOperator.COMPARE_LE: BinaryOperator.COMPARE_GE),
					(Expression)((Expression)children.get(i)).clone() ),
				(Expression)ret.clone(),
				(Expression)((Expression)children.get(i)).clone() );
		}

		return ret;
	}
}
