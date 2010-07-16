package cetus.hir;

import java.io.*;
//import java.lang.reflect.*;
import java.util.*;

/**
 * AnnotationDeclaration is used for stand-alone annotations in non-executable
 * code section, e.g., under TranslationUnit.
 */
public class AnnotationDeclaration extends Declaration
{
/*
	private static Method class_print_method;

	static
	{
		Class<?>[] params = new Class<?>[2];
		try {
			params[0] = AnnotationDeclaration.class;
			params[1] = OutputStream.class;
			class_print_method = params[0].getMethod("defaultPrint", params);
		} catch ( NoSuchMethodException ex ) {
			throw new InternalError();
		}
	}
*/

	/**
	 * Constructs an empty annotation declaration.
	 */
	public AnnotationDeclaration()
	{
		super();
	}

	/**
	 * Constructs a new annotation declaration with the given annotation.
	 */
	public AnnotationDeclaration(Annotation annotation)
	{
		super();
		annotate(annotation);
	}

	/**
	 * Returns null; unused abstract method.
	 */
	public List<IDExpression> getDeclaredSymbols() { return new LinkedList<IDExpression>(); }

	/**
	 * Prints this annotation declaration.
	 */
	public static void defaultPrint
			(AnnotationDeclaration adecl, OutputStream stream)
	{
		PrintStream p = new PrintStream(stream);
		p.print(adecl.toString());
	}

	/**
	 * Sets the class print method with the specified method.
	 */
/*
	public static void setClassPrintMethod(Method m)
	{
		class_print_method = m;
	}
*/
	/**
	 * Returns the string representation of this annotation declaration.
	 */
	public String toString()
	{
		return "";
	}
}
