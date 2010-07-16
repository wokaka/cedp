package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Base class for all declarations (special objects that result
 * in new symbol table entries when they are added to an instance
 * of a class that implements SymbolTable).
 */
public abstract class Declaration implements Cloneable, Traversable, Annotatable {

    protected static final Method print_as_statement_method;

    static {
        Class<?>[] params = new Class<?>[2];
        try {
            params[0] = Declaration.class;
            params[1] = OutputStream.class;
            print_as_statement_method =
                    params[0].getMethod("printAsStatement", params);
        } catch (NoSuchMethodException ex) {
            throw new InternalError();
        }
    }
    protected Method object_print_method;
    protected Traversable parent;
    protected LinkedList<Traversable> children;
    protected List<Annotation> annotations;

    /**
     * Base constructor for derived classes.
     */
    protected Declaration() {
        parent = null;
        children = new LinkedList<Traversable>();
        annotations = null;
    }

    /**
     * Base constructor for derived classes; sets an initial size for the
     * list of children of this declaration.
     *
     * @param size The initial size for the child list.
     */
    @SuppressWarnings("unused")
    protected Declaration(int size) {
        parent = null;
        children = new LinkedList<Traversable>();
        annotations = null;
    }

    /**
     * Creates and returns a deep copy of this declaration.
     *
     * @return a deep copy of this declaration.
     */
    public Object clone() {
        Declaration o = null;

        try {
            o = (Declaration) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new InternalError();
        }

        o.object_print_method = object_print_method;
        o.parent = null;

        if (children != null) {
            o.children = new LinkedList<Traversable>();
            /*
            Iterator iter = children.iterator();
            while (iter.hasNext())
            {
            Declarator new_child = (Declarator)((Declarator)iter.next()).clone();
            o.children.add(new_child);
            new_child.setParent(o);
            }
             */
            for (Traversable t : children) {
                Declarator new_child = (Declarator) ((Declarator) t).clone();
                o.children.add(new_child);
                new_child.setParent(o);
            }
        } else {
            o.children = null;
        }

        // Clone annotations after removing shallow copies.
        o.annotations = null;
        List<Annotation> notes = getAnnotations();
        if (notes != null) {
            for (Annotation note : notes) {
                o.annotate((Annotation) note.clone());
            }
        }

        return o;
    }

    /**
     * Detaches this declaration from it's parent, if it has one.
     */
    public void detach() {
        if (parent != null) {
            parent.removeChild(this);
            setParent(null);
        }
    }

    public List<Traversable> getChildren() {
        return children;
    }

    /** Returns a list of IDExpressions that are the symbols
     * introduced by this declaration.
     *
     * @return a list of IDExpressions.  The list will not
     *   be null but may be empty.
     */
    public abstract List<IDExpression> getDeclaredSymbols();

    public Traversable getParent() {
        return parent;
    }

    public void print(OutputStream stream) {
        if (object_print_method == null) {
            return;
        }

        Object[] args = new Object[2];
        args[0] = this;
        args[1] = stream;

        try {
            object_print_method.invoke(null, args);
        } catch (IllegalAccessException e) {
            System.err.println(e);
            e.printStackTrace();
            System.exit(1);
        } catch (InvocationTargetException e) {
            System.err.println(object_print_method.toString());
            System.err.println(e.getCause());
            e.printStackTrace();
            System.exit(1);
        }
    }

    public abstract String toString();

    /*
    public String toString() throws InternalError
    {
    throw new InternalError(
    "[Error] Unknown declaration tried to invoke toString()");
    }
     */
    public void removeChild(Traversable child) {
        throw new UnsupportedOperationException("Declarations do not support removal of arbitrary children.");
    }

    public void setChild(int index, Traversable t) {
        /* t must not be a child of something else */
        if (t.getParent() != null) {
            throw new NotAnOrphanException();
        }

        /* only certain types of objects can be children
        of declarations, so check for them */
        if (t instanceof Declarator
                || t instanceof Declaration
                || t instanceof Statement) {
            /* detach the old child at position index */
            children.get(index).setParent(null);

            /* set the new child */
            children.set(index, t);
            t.setParent(this);
        } else {
            throw new IllegalArgumentException();
        }
    }

    public void setParent(Traversable t) {
        if (t == null) {
            parent = null;
        } else {
            /* parent must already have accepted this object as a child */
            // FIXME - Temporarily disabled until new Declarators are in use
            //    if (Tools.indexByReference(t.getChildren(), this) < 0)
            //      throw new NotAChildException();

            /* only certain types of objects can be the parent of
            a declaration, so check for them */
            if (t instanceof Declaration
                    || t instanceof Declarator // parameter declarations in declarators
                    || t instanceof Statement
                    || t instanceof TemplateID
                    || t instanceof TranslationUnit) {
                parent = t;
            } else {
                throw new IllegalArgumentException();
            }
        }
    }

    /**
     * Overrides the print method for this object only.
     *
     * @param m The new print method.
     */
    public void setPrintMethod(Method m) {
        object_print_method = m;
    }

    /*
    public String toString()
    {
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    print(new PrintStream(baos));
    return baos.toString();
    }
     */
    /**
     * Verifies three properties of this object:
     * (1) All children are not null, (2) the parent object has this
     * object as a child, (3) all children have this object as the parent.
     *
     * @throws IllegalStateException if any of the properties are not true.
     */
    public void verify() throws IllegalStateException {
        if (parent != null && !parent.getChildren().contains(this)) {
            throw new IllegalStateException("parent does not think this is a child");
        }

        if (children != null) {
            if (children.contains(null)) {
                throw new IllegalStateException("a child is null");
            }
            /*
            Iterator<Traversable> iter = children.iterator();
            while (iter.hasNext())
            {
            if (iter.next().getParent() != this)
            throw new IllegalStateException("a child does not think this is the parent");
            }
             */
            for (Traversable t : children) {
                if (t.getParent() != this) {
                    throw new IllegalStateException("a child does not think this is the parent");
                }
            }

        }
    }

    public void annotate(Annotation annotation) {
        annotation.attach(this);
        if (annotations == null) {
            annotations = new LinkedList<Annotation>();
        }
        annotations.add(annotation);
    }

    public void annotateAfter(Annotation annotation) {
        annotation.setPosition(Annotation.AFTER);
        annotate(annotation);
    }

    public void annotateBefore(Annotation annotation) {
        annotation.setPosition(Annotation.BEFORE);
        annotate(annotation);
    }

    public List<Annotation> getAnnotations() {
        return annotations;
    }

    public <T extends Annotation> List<T> getAnnotations(Class<T> type) {
        if (annotations == null) {
            return null;
        }
        List<T> ret = new LinkedList<T>();
        for (Annotation annotation : annotations) {
            if (type.isAssignableFrom(annotation.getClass())) {
                ret.add(type.cast(annotation));
            }
        }
        return ret;
    }

    public boolean containsAnnotation(Class<? extends Annotation> type, String key) {
        return (getAnnotation(type, key) != null);
    }

    public <T extends Annotation> T getAnnotation(Class<T> type, String key) {
        List<T> annotations = getAnnotations(type);
        if (annotations == null) {
            return null;
        }
        for (T annotation : annotations) {
            if (annotation.containsKey(key)) {
                return annotation;
            }
        }
        return null;
    }

    public List<Annotation> getAnnotations(int position) {
        if (annotations == null) {
            return null;
        }
        List<Annotation> ret = new LinkedList<Annotation>();
        for (Annotation annotation : annotations) {
            if (annotation.position == position) {
                ret.add(annotation);
            }
        }
        return ret;
    }

    public void removeAnnotations() {
        annotations = null;
    }

    public void removeAnnotations(Class<?> type) {
        if (annotations == null) {
            return;
        }
        Iterator<Annotation> iter = annotations.iterator();
        while (iter.hasNext()) {
            if (type.isAssignableFrom(iter.next().getClass())) {
                iter.remove();
            }
        }
    }

    public String annotationToString(int position) {
        if (annotations == null) {
            return "";
        }
        List<Annotation> filtered = getAnnotations(position);
        return Tools.collectionToString(filtered, "\n");
    }

    public static void printAsStatement(Declaration decl, OutputStream stream) {
        PrintStream p = new PrintStream(stream);
        p.print(decl.toString());
    }

    public String toAnnotatedString() {
        StringBuilder str = new StringBuilder(80);
        String next = annotationToString(Annotation.BEFORE);
        str.append(next);

        next = this.toString();
        if (str.length() > 0 && next.length() > 0) {
            str.append("\n");
        }
        str.append(next);
        if (object_print_method == print_as_statement_method) {
            str.append(";");
        }

        next = annotationToString(Annotation.WITH);
        if (next.length() > 0) {
            str.append(" " + next);
        }

        next = annotationToString(Annotation.AFTER);
        if (str.length() > 0 && next.length() > 0) {
            str.append("\n");
        }
        str.append(next);

        return str.toString();
    }
}
