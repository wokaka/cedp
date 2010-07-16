package cetus.hir;

/**
 * CommentAnnotation is used for an annotation of comment type.
 * It provides two different print method depending on the location of the
 * comments.
 */
public class CommentAnnotation extends Annotation {

    private static final long serialVersionUID = 1; /* avoids gcc 4.3 warning */

    private boolean one_liner; // Is this printed in one line.

    /**
     * Constructs a new comment annotation with the given comment.
     */
    public CommentAnnotation(String comment) {
        super();
        put("comment", comment);
        one_liner = false;
    }

    /**
     * Sets the one_liner field; true for one-liner comments, false for
     * normal multi-line comments.
     */
    public void setOneLiner(boolean one_liner) {
        this.one_liner = one_liner;
    }

    /**
     * Returns the string representation of this comment.
     * @return the string comments.
     */
    public String toString() {
        if(get("comment").toString().contains("[GPUFI]")){
            return "" + get("comment").toString().substring(7);
        }
        else{
            if (skip_print) {
                return "";
            } else if (one_liner) {
                return ("/* " + get("comment") + " */");
            } else {
                return ("/*\n" + get("comment") + "\n*/");
            }
        }
    }
}
