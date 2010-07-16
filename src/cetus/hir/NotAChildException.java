package cetus.hir;


/**
 * Thrown when an action is performed on an IR object and
 * that action requires the object to be the child of
 * another object, but that is not the case.
 */
public class NotAChildException extends RuntimeException
{
  private static final long serialVersionUID = 1; /* avoids gcc 4.3 warning */
  public NotAChildException()
  {
    super();
  }

  public NotAChildException(String message)
  {
    super(message);
  }
}
