package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Base class for all statements. 
 * Statement is the base class of numerous specific statement classes.
 * Use the Java instanceof operator to determine the specific
 * type of a Statement.
 */
public abstract class Statement implements Cloneable, Traversable, Annotatable
{
  protected Method object_print_method;

  protected Traversable parent;
  protected LinkedList<Traversable> children;

  protected int line_number = -1;

	protected List<Annotation> annotations;

  /** Constructor for derived classes. */
  protected Statement()
  {
    parent = null;
    children = new LinkedList<Traversable>();
		annotations = null;
  }

  /**
   * Constructor for derived classes that preallocates
   * space for multiple children.
   *
   * @param size The expected number of children for this statement.
   */
  @SuppressWarnings("unused")
  protected Statement(int size)
  {
    parent = null;
    children = new LinkedList<Traversable>();
		annotations = null;
  }

  public Object clone()
  {
    Statement o = null;

    try {
      o = (Statement)super.clone();
    } catch (CloneNotSupportedException e) {
      throw new InternalError();
    }

    o.object_print_method = object_print_method;
    o.parent = null;

    if (children != null)
    {
      o.children = new LinkedList<Traversable>();
      Iterator<Traversable> iter = children.iterator();
      while (iter.hasNext())
      {
        Traversable new_child = null;
        Object tmp = iter.next();

        if (tmp instanceof Statement)
          new_child = (Statement)((Statement)tmp).clone();
        else if (tmp instanceof Expression)
          new_child = (Expression)((Expression)tmp).clone();
        else if (tmp instanceof Declaration)
          new_child = (Declaration)((Declaration)tmp).clone();
        else
        {
          System.err.println(tmp.getClass().toString());
        }

        new_child.setParent(o);
        o.children.add(new_child);
      }
    }
    else
      o.children = null;

		// Clone annotations after removing shallow copies.
		o.annotations = null;
		List<Annotation> notes = getAnnotations();
		if ( notes != null )
			for ( Annotation note : notes )
				o.annotate( (Annotation)note.clone() );

    return o;
  }

  /**
   * Detaches this statement from it's parent, if it has one.
   */
  public void detach()
  {
    if (parent != null)
    {
      parent.removeChild(this);
      setParent(null);
    }    
  }

  public List<Traversable> getChildren()
  {
    return children;
  }

  public Traversable getParent()
  {
    return parent;
  }

  /**
   * Returns the procedure in which this statement is located.
   *
   * @return the procedure in which this statement is located,
   *   or null if it is not in a procedure.  It is possible for
   *   a {@link DeclarationStatement DeclarationStatement} to be
   *   located somewhere other than a procedure.
   */
  public Procedure getProcedure()
  {
    Traversable p = getParent();

    while (p != null)
    {
      if (p instanceof Procedure)
        return (Procedure)p;
      else
        p = p.getParent();
    } 

    return null;
  }

  public void print(OutputStream stream)
  {
    if (object_print_method == null)
      return;

    Object[] args = new Object[2];
    args[0] = this;
    args[1] = stream;

    try {
      object_print_method.invoke(null, args);
    } catch (IllegalAccessException e) {
      throw new InternalError(); 
    } catch (InvocationTargetException e) {
      throw new InternalError();
    }
  }

  /**
   * Removes a specific child of this statement;
   * some statements do not support this method.
   *
   * @param child The child to remove.
   */
  public void removeChild(Traversable child)
  {
    throw new UnsupportedOperationException("This statement does not support removal of arbitrary children.");
  }

  public void setChild(int index, Traversable t)
  {
    /* The omission of parent checks and modifications is
       intentional here. */
    children.set(index, t);
    t.setParent(this);
  }

  public void setParent(Traversable t)
  {
    parent = t;
  }

  /**
   * Overrides the print method for this object only.
   *
   * @param m The new print method.
   */
  public void setPrintMethod(Method m)
  {
    object_print_method = m;
  }

  /**
   * Swaps two statements on the IR tree.  If neither
   * this statement nor <var>stmt</var> has a parent,
   * then this function has no effect.  Otherwise,
   * each statement ends up with the other's parent.
   *
   * @param stmt The statement with which to swap this statement.
   * @throws IllegalArgumentException if <var>stmt</var> is null.
   * @throws IllegalStateException if the types of the statements
   *   are such that they would create inconsistent IR when swapped.
   */
  public void swapWith(Statement stmt)
  {
    if (stmt == null)
      throw new IllegalArgumentException();

    if (this == stmt)
      /* swap with self does nothing */
      return;

    /* The rest of this must be done in a very particular order.
       Be EXTREMELY careful changing it. */

    Traversable this_parent = this.parent;
    Traversable stmt_parent = stmt.parent;

    int this_index = -1, stmt_index = -1;

    if (this_parent != null)
    {
      this_index = Tools.indexByReference(this_parent.getChildren(), this);
      if (this_index == -1)
        throw new IllegalStateException();
    }

    if (stmt_parent != null)
    {
      stmt_index = Tools.indexByReference(stmt_parent.getChildren(), stmt);
      if (stmt_index == -1)
        throw new IllegalStateException();
    }

    /* detach both so setChild won't complain */
    stmt.parent = null; this.parent = null;

    if (this_parent != null)
      this_parent.setChild(this_index, stmt);

    if (stmt_parent != null)
      stmt_parent.setChild(stmt_index, this);
  }

  /**
   * Sets the line number of this statement
   * This function is to be used only for parser development
   *
   * @param line The line number 
   */
  public void setLineNumber(int line)
  {
    line_number = line;
  }

	/**
	 * Returns a string representation of this statement; every child class
	 * should implement this method.
	 */
	public abstract String toString();

/*
	public abstract String toString();

  public String toString()
  {
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    print(new PrintStream(baos));
    return baos.toString();
  }

	public String toString() throws InternalError
	{
		throw new InternalError(
			"[Error] Unknown statement tried to invoke toString()");
	}
*/

  /**
   * Returns the line number of this statement if the
   * statement was present in the original source file.
   * Line numbers are not available for statements that
   * are added by compiler passes.
   *
   * @return the line number of this statement.
   */
  public int where()
  {
    /* TODO - add code for returning the line number and
       (probably) throwing an exception if the line number
       is unknown */
    // line_number # is -1 if not defined
    return line_number;
  }

  /**
   * Verifies three properties of this object:
   * (1) All children are not null, (2) the parent object has this
   * object as a child, (3) all children have this object as the parent.
   *
   * @throws IllegalStateException if any of the properties are not true.
   */
  public void verify() throws IllegalStateException
  {
    if (parent != null && !parent.getChildren().contains(this))
      throw new IllegalStateException("parent does not think this is a child");

    if (children != null)
    {
      if (children.contains(null))
        throw new IllegalStateException("a child is null");
/*
      Iterator<Traversable> iter = children.iterator();
      while (iter.hasNext())
      {
        Traversable child = iter.next();

        if (child.getParent() != this)
          throw new IllegalStateException("a child does not think this is the parent");

        if (child instanceof Statement)
          ((Statement)child).verify();
      }
*/
			for(Traversable child : children)
			{
        if (child.getParent() != this)
          throw new IllegalStateException("a child does not think this is the parent");

        if (child instanceof Statement)
          ((Statement)child).verify();
			}
    }
  }

	public void annotate(Annotation annotation)
	{
		annotation.attach(this);
		if ( annotations == null )
			annotations = new LinkedList<Annotation>();
		annotations.add(annotation);
	}

	public void annotateAfter(Annotation annotation)
	{
		annotation.setPosition(Annotation.AFTER);
		annotate(annotation);
	}

	public void annotateBefore(Annotation annotation)
	{
		annotation.setPosition(Annotation.BEFORE);
		annotate(annotation);
	}

	public List<Annotation> getAnnotations()
	{
		return annotations;
	}

	public <T extends Annotation> List<T> getAnnotations(Class<T> type)
	{
		if ( annotations == null )
			return null;
		List<T> ret = new LinkedList<T>();
		for ( Annotation annotation : annotations )
			if ( type.isAssignableFrom(annotation.getClass()) )
				ret.add(type.cast(annotation));
		return ret;
	}

	public boolean
			containsAnnotation(Class<? extends Annotation> type, String key)
	{
		return (getAnnotation(type, key) != null);
	}

	public <T extends Annotation> T getAnnotation(Class<T> type, String key)
	{
		List<T> annotations = getAnnotations(type);
		if ( annotations == null )
			return null;
		for ( T annotation : annotations )
			if ( annotation.containsKey(key) )
				return annotation;
		return null;
	}

	public List<Annotation> getAnnotations(int position)
	{
		if ( annotations == null )
			return null;
		List<Annotation> ret = new LinkedList<Annotation>();
		for ( Annotation annotation : annotations )
			if ( annotation.position == position )
				ret.add(annotation);
		return ret;
	}

	public void removeAnnotations()
	{
		annotations = null;
	}

	public void removeAnnotations(Class<?> type)
	{
		if ( annotations == null )
			return;
		Iterator<Annotation> iter = annotations.iterator();
		while ( iter.hasNext() )
			if ( type.isAssignableFrom(iter.next().getClass()) )
				iter.remove();
	}

	public String annotationToString(int position)
	{
		if ( annotations == null )
			return "";
		List<Annotation> filtered = getAnnotations(position);
		return Tools.collectionToString(filtered, "\n");
	}

	public String toAnnotatedString()
	{
		StringBuilder str = new StringBuilder(80);
		String next = annotationToString(Annotation.BEFORE);
		str.append(next);

		next = this.toString();
		if ( str.length()>0 && next.length()>0 )
			str.append("\n");
		str.append(next);

		next = annotationToString(Annotation.WITH);
		if ( next.length() > 0 )
			str.append(" "+next);

		next = annotationToString(Annotation.AFTER);
		if ( str.length()>0 && next.length()>0 )
			str.append("\n");
		str.append(next);

		return str.toString();
	}

}
