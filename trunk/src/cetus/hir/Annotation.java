package cetus.hir;

import java.util.*;

/**
 * Annotation is the base class of any annotation type used in Cetus.
 * Unlike the implementation in the past versions of Cetus, this class is
 * separated from the IR tree to clarify usage of annotations along with
 * their associated IR (either Declaration or Statement).
 */
public abstract class Annotation extends HashMap<String, Object>
{
	// Possible printed position relative to the associated IR
	protected static final int BEFORE = -1; // before the IR
	protected static final int WITH   = 0;  // with the IR (no line breaking)
	protected static final int AFTER  = 1;  // after the IR

	protected int position; // The relative position from the IR

	protected Annotatable ir; // The annotatable object having this annotation.

	protected boolean skip_print; // Used when turning off printing. 

	/**
	 * Constructs a new annotation.
	 */
	protected Annotation()
	{
		super();
		position = BEFORE;
		ir = null;
		skip_print = false;
	}

 	/**
 	 * Returns the annotated value with the specified key.
 	 * @param key the given string key.
 	 * @return the annotated value or null (if not present).
 	 */
 	@SuppressWarnings("unchecked")
 	public <T> T get(String key)
 	{
 		return (T)super.get(key);
 	}

	/**
	 * Sets the relative position from the associated IR as the given position.
	 * @param position the new position.
	 */
	public void setPosition(int position)
	{
		this.position = position;
	}

	/**
	 * Returns a string representation of the annotation. All child classes
	 * of Annotation should implement their own toString() method.
	 * @return the string representation.
	 */
	public abstract String toString();

	/**
	 * Returns the string representation of this annotation if the given
	 * position is equal to the position of this annotation.
	 */
	public String toString(int position)
	{
		if ( this.position == position )
			return toString();
		else
			return "";
	}

	/**
	 * Returns a clone of this annotation object.
	 * @return a cloned annotation.
	 */
	@SuppressWarnings("unchecked")
	public Object clone()
	{
		Annotation o = (Annotation)super.clone(); // super is cloneable.

		// Overwrite shallow copies.
		/* for now just use the shallow copy.
		clear();
		for ( String key : keySet() )
			o.put( (String)key.clone(), get(key).clone() );
		*/
		o.position = this.position;
		o.skip_print = this.skip_print;
		// ir are overwritten only by annotatable.annotate().

		return o;
	}

	/**
 	 * Attaches a link from this annotation to the specified IR.
 	 * Declaration and Statement implement the Annotatable interface.
 	 * @param ir the associated Cetus IR.
 	 */
 	public void attach(Annotatable ir)
 	{
		this.ir = ir;
 	}

	/**
	 * Sets the skip_print field.
	 */
	public void setSkipPrint(boolean skip_print)
	{
		this.skip_print = skip_print;
	}

	/**
	 * Returns the annotatable object that contains this annotation.
	 */
	public Annotatable getAnnotatable()
	{
		return ir;
	}

}
