package cetus.hir;

import java.io.*;

import java.lang.reflect.*;



/**
 * Class InfExpression expresses infinity states of values.
 */
public class InfExpression extends Expression
{
	private static Method class_print_method;

	// Sign of the expression
	private int sign;

	static
	{
    try {
			class_print_method = InfExpression.class.getMethod("defaultPrint",
				new Class[] {InfExpression.class, OutputStream.class} );
    } catch ( NoSuchMethodException ex ) {
      throw new InternalError();
    }
	}


/**
 * Constructor
 * @param sign the sign of the infinity expression
 */
	public InfExpression(int sign)
	{
		super();
		object_print_method = class_print_method;
		this.sign = sign;
	}

/**
 * Clone method
 */
	public Object clone()
	{
		InfExpression o = (InfExpression)super.clone();
		o.sign = sign;
		return o;
	}

/**
 * Default print method
 */
	public static void defaultPrint(InfExpression inf, OutputStream stream)
	{
		PrintStream p = new PrintStream(stream);
		if ( inf.sign < 0 )
			p.print("-INF");
		else
			p.print("+INF");
	}

/**
 * Converts the expression to String
 */
	public String toString()
	{
		if ( sign < 0 )
			return "-INF";
		else
			return "+INF";
	}

	// InfExpression is not comparable to any objects
	public boolean equals(Object o)
	{
		if ( o instanceof InfExpression )
			return toString().equals(o.toString());
		else
			return false;
	}

	// InfExpression is not comparable to any objects
	public int compareTo(Expression e)
	{
		if ( equals(e) )
			return 0;
		else
			return toString().compareTo(e.toString());
	}

/**
 * Returns the sign of the infinity expression
 */
	public int sign()
	{
		return sign;
	}

}
