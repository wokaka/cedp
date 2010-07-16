package cetus.hir;

import java.util.*;

/**
 * Iterates over Traversable objects in breadth-first order.
 */
public class BreadthFirstIterator extends IRIterator
{
  private Vector<Traversable> queue;
  private HashSet<Class<? extends Traversable>> prune_set;

  /**
   * Creates a new iterator.
   *
   * @param init The first object to visit.
   */
  public BreadthFirstIterator(Traversable init)
  {
    super(init);
    queue = new Vector<Traversable>();
    queue.add(init);
    prune_set = new HashSet<Class<? extends Traversable>>();
  }

  public boolean hasNext()
  {
    return !queue.isEmpty();
  }

  public Traversable next()
  {
    Traversable t = null;

    try {
      t = queue.remove(0);
    } catch (ArrayIndexOutOfBoundsException e) {
      throw new NoSuchElementException();
    }

    if (t.getChildren() != null
        && !containsCompatibleClass(prune_set, t.getClass()))
    {
		/*
      Iterator iter = t.getChildren().iterator();
      while (iter.hasNext())
      {
        Object o = iter.next();
        if (o != null)
          queue.add(o);
      }
		*/
			for(Traversable o : t.getChildren())
				if(o != null)
					queue.add(o);
    }

    return t;
  }

  public <T extends Traversable> void pruneOn(Class<T> c)
  {
    prune_set.add(c);
  }


  // **AP**
  // Add a function to remove classes from prune_set
  public <T extends Traversable> void pruneOff(Class<T> c)
  {
    prune_set.remove(c);
  }


  /**
    * Returns a linked list of objects of Class c in the IR
    */
  public <T extends Traversable> LinkedList<T> getList(Class<T> c)
  {
    LinkedList<T> list = new LinkedList<T>();

    while (hasNext())
    {
      Traversable obj = next();
      if (c.isInstance(obj))
      {
        list.add(c.cast(obj));
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

    //System.out.println("getSet strt");
    while (hasNext())
    {
      Traversable obj = next();

      //System.out.println(obj.getClass().toString() + ": " + obj.toString());

      if (c.isInstance(obj))
      {
        set.add(c.cast(obj));
      }
    }
    return set;
  }      

  public void reset()
  {
    queue.clear();
    queue.add(root);
  }
}
