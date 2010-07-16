package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;


/**
 * Represents a text annotation (comment or pragma) or a list of keyed values.
 * Internally, an annotation is a single string <i>or</i> a map of
 * keys to values.  There is no restriction on the type or content of the
 * keys and values.  Compiler passes are free to use annotations as they see
 * fit, although annotations used by multiple passes should be well-documented.
 *
 * By default, annotations are printed as a multi-line comment. They can also
 * be printed as pragmas.  If the text value of the annotation has been set,
 * the text is printed, otherwise the list of keyed values is printed.
 */

public class PreAnnotation extends Declaration
{
  private static Method class_print_method;

  /** Useful for passing to setPrintMethod or setClassPrintMethod. */
  public static final Method print_as_comment_method;
  /** Useful for passing to setPrintMethod or setClassPrintMethod. */
  public static final Method print_as_pragma_method;
  /** Useful for passing to setPrintMethod or setClassPrintMethod. */
  public static final Method print_raw_method;

  static
  {
    Class<?>[] params = new Class<?>[2];

    try {
      params[0] = PreAnnotation.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
      print_as_comment_method = params[0].getMethod("printAsComment", params);
      print_as_pragma_method = params[0].getMethod("printAsPragma", params);
      print_raw_method = params[0].getMethod("printRaw", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  protected HashMap<Object,Object> map;
  protected String text;

  /**
   * Creates an empty annotation.
   */
  public PreAnnotation()
  {
    object_print_method = class_print_method;

    map = new HashMap<Object,Object>(4);
		parent = null;
    children = null;
    text = null;
  }

  /**
   * Creates a text annotation.
   *
   * @param text The text to be used as a comment or pragma.
   */
  public PreAnnotation(String text)
  {
    object_print_method = class_print_method;

    map = new HashMap<Object,Object>(1);
    children = null;
    this.text = text;
  }

  public void add(Object key, Object value)
  {
    map.put(key, value);
  }

  /**
   * Prints an annotation to a stream.
   *
   * @param note The annotation to print.
   * @param stream The stream on which to print the annotation.
   */
  public static void defaultPrint(PreAnnotation note, OutputStream stream)
  {
    printAsComment(note, stream);
  }

  public boolean equals(Object o)
  {
    try {
      PreAnnotation a = (PreAnnotation)o;
      return toString().equals(a.toString());
    } catch (ClassCastException e) {
      return false;
    }
  }

  public List<IDExpression> getDeclaredSymbols()
  {
    return new LinkedList<IDExpression>();
  }

  /**
   * Provides access to the annotation map.
   */
  public Map<Object,Object> getMap()
  {
    return map;
  }

  public String getText()
  {
    return text;
  }

  public int hashCode()
  {
    return toString().hashCode();
  }

  /**
   * Prints an annotation as a multi-line comment.
   *
   * @param note The annotation to print.
   * @param stream The stream on which to print the annotation.
   */
  public static void printAsComment(PreAnnotation note, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.println("/*");
    if (note.text != null)
      p.println(note.text);
    else
      p.println(note.map.toString());
    p.print("*/");
  }

  /**
   * Prints an annotation as a single-line pragma.
   *
   * @param note The annotation to print.
   * @param stream The stream on which to print the annotation.
   */
  public static void printAsPragma(PreAnnotation note, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("#pragma ");
    if (note.text != null)
      p.print(note.text);
		else
      p.print(note.map.toString());
  }

  /**
   * Prints an annotation's contents without enclosing them in comments.
   *
   * @param note The annotation to print.
   * @param stream The stream on which to print the annotation.
   */
  public static void printRaw(PreAnnotation note, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (note.text != null)
    {
      p.print(note.text);
      p.print(" ");
    }
    else
      p.print(note.map.toString());
  }

	/**
	 * Returns a string for this annotation following the object print method.
	 * @return a string
	 */
	public String toString()
	{
		StringBuilder str = new StringBuilder(80);

		if ( object_print_method == print_raw_method )
		{
			if ( text != null )
				str.append(text);
			else
				str.append(map.toString());
		}
		else if ( object_print_method == print_as_comment_method ||
		object_print_method.getName().equals("defaultPrint") )
		{
			str.append("/*\n");
			if ( text != null )
				str.append(text+"\n");
			else
				str.append(map.toString()+"\n");
			str.append("*/");
		}
		else if ( object_print_method == print_as_pragma_method )
		{
    	str.append("#pragma ");
	    if (text != null)
				str.append(text);
			else
				str.append(map.toString());
		}
		else 
		{ 
			/* defaultPrint case : do not print PreAnnotation */
		}
		return str.toString();
	}

  /**
   * Unsupported - this object has no children.
   */
  public void setChild(int index, Traversable t)
  {
    throw new UnsupportedOperationException();
  }

  /**
   * Overrides the class print method, so that all subsequently
   * created objects will use the supplied method.
   *
   * @param m The new print method.
   */
  static public void setClassPrintMethod(Method m)
  {
    class_print_method = m;
  }

  /**
   * Sets the text of the annotation.
   *
   * @param text The text to be used as a comment or pragma.
   */
  public void setText(String text)
  {
    this.text = text;
  }
}
