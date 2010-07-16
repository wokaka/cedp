package cetus.hir;

import java.util.*;

/**
 * Iterates over Traversable objects in depth-first order.
 */
public class DepthFirstIterator extends IRIterator
{
  private Vector<Traversable> stack;
  private HashSet<Class<? extends Traversable>> prune_set;

  /**
   * Creates a new iterator.
   *
   * @param init The first object to visit.
   */
  public DepthFirstIterator(Traversable init)
  {
    super(init);
    stack = new Vector<Traversable>();
    stack.add(init);
    prune_set = new HashSet<Class<? extends Traversable>>();
  }

  public boolean hasNext()
  {
    return !stack.isEmpty();
  }

  public Traversable next()
  {
    Traversable t = null;

    try {
      t = stack.remove(0);
    } catch (EmptyStackException e) {
      throw new NoSuchElementException();
    }

/*
    if (t.getChildren() != null
        && !containsCompatibleClass(prune_set, t.getClass()))
*/
		if ( !containsCompatibleClass(prune_set, t.getClass()) &&
			t.getChildren() != null )
    {
      int i = 0;
			/*
      Iterator iter = t.getChildren().iterator();
      while (iter.hasNext())
      {
        Object o = iter.next();
        if (o != null)
          stack.add(i++, o);
      }
			*/
      for(Traversable o : t.getChildren())
        if (o != null)
          stack.add(i++, o);
				
    }

    return t;
  }

  public <T extends Traversable> void pruneOn(Class<T> c)
  {
    prune_set.add(c);
  }


	/**
		* Returns a linked list of objects of Class c in the IR
		*/
	public <T extends Traversable> LinkedList<T> getList(Class<T> c)
	{
		LinkedList<T> list = new LinkedList<T>();

		while (hasNext())
		{
			try{
				list.add(next(c));
			} catch (NoSuchElementException e) {
				break;
			}
		}
		return list;
	}

	/**
		* Returns a set of objects of Class c in the IR
		*/
	public <T extends Traversable> Set<T> getSet(Class<T> c)
	{
		HashSet<T> set = new HashSet<T>();

		while (hasNext())
		{
			Traversable obj = next();

      		if (c.isInstance(obj))
			{
				set.add(c.cast(obj));
			}
		}
		return set;
	}
 
  public void reset()
  {
    stack.clear();
    stack.add(root);
  }
}
