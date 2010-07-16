package cetus.hir;

import java.util.*;

/**
 * Peforms a post-order traversal over a Traversable object.
 */
public class PostOrderIterator extends IRIterator
{
  private LinkedList<Traversable> queue;
  private HashSet<Class<? extends Traversable>> prune_set;

  /**
   * Creates a new iterator.
   *
   * @param root The root object for the traversal.
   */
  public PostOrderIterator(Traversable root)
  {
    super(root);
    queue = new LinkedList<Traversable>();
    prune_set = new HashSet<Class<? extends Traversable>>();

    reset();
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
    } catch (EmptyStackException e) {
      throw new NoSuchElementException();
    }

    return t;
  }

  private void populate(Traversable t)
  {
    if (t.getChildren() != null
        && !containsCompatibleClass(prune_set, t.getClass()))
    {
      for (Traversable obj : t.getChildren())
      {
        populate(obj);
      }
    }

    queue.add(t);
  }

  public void pruneOn(Class<? extends Traversable> c)
  {
    prune_set.add(c);
  }

  public void reset()
  {
    queue.clear();
    prune_set.clear();

    populate(root);
  }
}
