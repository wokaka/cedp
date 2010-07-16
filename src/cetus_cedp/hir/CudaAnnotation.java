package cetus.hir;

/**
 *
 * @author cuongpham
 */
public class CudaAnnotation extends Annotation {

    /**
     * Constructs a new comment annotation with the given comment.
     */
    public CudaAnnotation(String comment) {
        super();
        put("cudastatement", comment);
    }

    /**
     * Returns the string representation of this comment.
     * @return the string comments.
     */
    public String toString() {
            return (get("cudastatement") + "\n");
    }
}
