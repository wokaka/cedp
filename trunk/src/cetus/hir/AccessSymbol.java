package cetus.hir;

import java.util.*;

/**
 * AccessSymbol represents a list of symbols collected from each identifier
 * in an {@link AccessExpression} object. We keep a list of symbols since the
 * attributes of AccessExpression objects may vary case by case.
 */
public class AccessSymbol extends LinkedList<Symbol> implements Symbol
{
	private String name;
        private static final long serialVersionUID = 1; /* avoids gcc 4.3 warning */

	/**
	 * Constructs an access symbol from the given access expression.
	 *
	 * @param ae the access expression.
	 */
	public AccessSymbol(AccessExpression ae)
	{
		Symbol lhs = Tools.getSymbolOf(ae.getLHS());
		Symbol rhs = Tools.getSymbolOf(ae.getRHS());

		if ( lhs instanceof AccessSymbol )
			addAll((AccessSymbol)lhs);
		else
			add(lhs);

		if ( rhs instanceof AccessSymbol )
			addAll((AccessSymbol)rhs);
		else
			add(rhs);

		name = ae.toString();
	}

	/**
	 * Returns the type of the access symbol which is collected from the last
	 * element of the list.
	 *
	 * @return the list of type specifiers.
	 */
	public List<Specifier> getTypeSpecifiers()
	{
		return get(size()-1).getTypeSpecifiers();
	}

	/**
	 * Returns the array specifiers of the access symbol.
	 *
	 * @return the list of array specifiers.
	 */
	public List<Specifier> getArraySpecifiers()
	{
		return get(size()-1).getArraySpecifiers();
	}

	/**
	 * Returns the string name of the access symbol.
	 *
	 * @return the string name.
	 */
	public String getSymbolName()
	{
		return name;
	}
}
