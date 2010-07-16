package cetus.hir;

import java.io.*;
//import java.lang.reflect.*;
//import java.util.*;

/**
 * AnnotationStatement is used for stand-alone annotations in executable
 * code section, e.g., under CompoundStatement.
 */
public class AnnotationStatement extends Statement {
    /*
    private static Method class_print_method;

    static
    {
    Class<?>[] params = new Class<?>[2];
    try {
    params[0] = AnnotationStatement.class;
    params[1] = OutputStream.class;
    class_print_method = params[0].getMethod("defaultPrint", params);
    } catch ( NoSuchMethodException ex ) {
    throw new InternalError();
    }
    }
     */

    /**
     * Constructs an empty annotation statement.
     */
    public AnnotationStatement() {
        super();
    }

    /**
     * Constructs a new annotation statement with the specified annotation.
     */
    public AnnotationStatement(Annotation annotation) {
        super();
        annotate(annotation);
    }

    /**
     * Prints this annotation statement.
     */
    public static void defaultPrint(AnnotationStatement astmt, OutputStream stream) {
        PrintStream p = new PrintStream(stream);
        p.print(astmt.toString());
    }

    /**
     * Sets the class print method with the given method.
     */
    /*
    public static void setClassPrintMethod(Method m)
    {
    class_print_method = m;
    }
     */
    /**
     * Returns the string representation of this annotation statement.
     */
    public String toString() {
        return ""; // no stmt representation - annotations are handled separately
    }
}
