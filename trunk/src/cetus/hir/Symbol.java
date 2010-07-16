package cetus.hir;

import java.util.*;

/**
 * An IR object that implements Symbol interface is identified as a unique
 * symbol in the program. Every {@link IDExpression} object has a link to
 * its corresponding Symbol object and can access the attributes of the symbol
 * object.
 */
public interface Symbol
{
	/**
	 * Returns a list of type specifiers.
	 * 
	 * @return the list of type specifiers.
	 */
	List<Specifier> getTypeSpecifiers();

	/**
	 * Returns a list of array specifiers.
	 *
	 * @return the list of array specifiers.
	 */
	List<Specifier> getArraySpecifiers();

	/**
	 * Returns the name of the symbol.
	 *
	 * @return the name of the symbol.
	 */
	String getSymbolName();
}
