package cetus.hir;

import java.util.*;

/**
 * OmpAnnotation is used for internally representing OpenMP pragmas. OpenMP
 * pragmas are raw text right after parsing but converted to an internal
 * annotation of this type.
 */
public class OmpAnnotation extends PragmaAnnotation
{
        private static final long serialVersionUID = 1; /* avoids gcc 4.3 warning */
	// Pragmas used without values
	private static final Set<String> no_values =
		new HashSet<String>(Arrays.asList("sections", "single", "task", "master",
		"barrier", "taskwait", "atomic", "nowait", "ordered"));

	// Pragmas used with collection of values
	private static final Set<String> collection_values =
		new HashSet<String>(Arrays.asList("private", "firstprivate", "lastprivate",
		"shared", "copyprivate", "copyin", "threadprivate", "flush", "schedule"));

	/**
	 * Constructs an empty omp annotation.
	 */
	public OmpAnnotation()
	{
		super();
	}

	/**
	 * Constructs an omp annotation with the given key-value pair.
	 */
	public OmpAnnotation(String key, Object value)
	{
		super();
		put(key, value);
	}

	/**
	 * Returns the string representation of this omp annotation.
	 * @return the string representation.
	 */
	public String toString()
	{
		if ( skip_print )
			return "";

		StringBuilder str = new StringBuilder(80);

		str.append(super.toString()+"omp ");

		// Process "parallel" and "for" before any other keys are processed.
		if ( containsKey("parallel") )
			str.append("parallel ");
		if ( containsKey("for") )
			str.append("for ");

		for ( String key : keySet() )
		{
			if ( key.equals("parallel") || key.equals("for") )
				;
			else if ( no_values.contains(key) )
				str.append(key+" ");
			else if ( collection_values.contains(key) )
			{
				Object value = get(key);
				if ( value instanceof Collection )
					str.append(key+"("+
						Tools.collectionToString((Collection<?>)value, ", ")+") ");
				else // e.g., schedule
					str.append(key+"("+value+") ");
			}
			else if ( key.equals("reduction") )
			{
				Map<String, Set<Expression>> reduction_map = this.get(key);
				for ( String op : reduction_map.keySet() )
				{
					str.append("reduction("+op+": ");
					str.append(Tools.collectionToString(reduction_map.get(op), ", "));
					str.append(") ");
				}
			}
			else
			{
				str.append(key+" ");
				if ( get(key) != null )
					str.append(get(key)+" ");
			}
		}

		return str.toString();
	}
}
