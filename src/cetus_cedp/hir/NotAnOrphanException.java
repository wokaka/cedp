package cetus.hir;


/**
 * Thrown when an action is performed on an IR object
 * and that object is required to have no parent object,
 * but that is not the case.
 */
public class NotAnOrphanException extends RuntimeException
{
  private static final long serialVersionUID = 1; /* avoids gcc 4.3 warning */
  public NotAnOrphanException()
  {
    super();
  }

  public NotAnOrphanException(String message)
  {
    super(message);
  }
}
