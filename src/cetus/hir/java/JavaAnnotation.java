package cetus.hir.java;

import cetus.hir.Annotation;
import cetus.hir.Expression;
import cetus.hir.IDExpression;
import java.util.*;

/**
 * CommentAnnotation is used for an annotation of comment type.
 * It provides two different print method depending on the location of the
 * comments.
 */
public class JavaAnnotation extends Annotation
{
	private IDExpression id;
        private Expression expr;

	/**
	 * Constructs a new comment annotation with the given comment.
	 */
	public JavaAnnotation(IDExpression i)
	{
            super();
            id = i;
        }

        public JavaAnnotation(IDExpression i, Expression e)
	{
            super();
            id = i;
            expr = e;
	}

        public void SetExpression(Expression e)
        {
            expr = e;
        }

        private boolean parenthesis = false;
        
        public void SetParenthesis()
        {
            parenthesis = true;
        }

        private String type = "";
        
        public void SetType(String t)
        {
            type = t;
        }
        
	/**
	 * Returns the string representation of this comment.
	 * @return the string comments.
	 */
	public String toString()
	{
		if ( skip_print )
			return "";
                else{
                    if(expr == null)
                        return "@" + type + id;
                    else{
                        if(parenthesis)
                            return "@" + type + id + " ( " + expr.toString() + " )";
                        else
                            return "@" + type + id + " " + expr.toString();
                    }
                }
	}
}
