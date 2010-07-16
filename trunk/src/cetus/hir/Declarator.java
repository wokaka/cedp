package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents the part of a declaration that is the name
 * of the symbol, some type information, and initial values.
 * This class actually is more similar to what the C++ grammar
 * calls an init-declarator.  Many different constructors are
 * provided because Java does not have default arguments.
 */
public abstract class Declarator implements Cloneable, Traversable, Symbol {

    private static Method class_print_method;
    protected Method object_print_method;

    static {
        Class<?>[] params = new Class<?>[2];

        try {
            params[0] = Declarator.class;
            params[1] = OutputStream.class;
            class_print_method = params[0].getMethod("defaultPrint", params);
        } catch (NoSuchMethodException e) {
            throw new InternalError();
        }
    }
    protected Traversable parent;
    protected LinkedList<Traversable> children;
    protected List<Specifier> leading_specs;
    protected List<Specifier> trailing_specs;
    private IDExpression direct_decl;
    private Declarator nested_decl;
    private List<Declaration> parameters;
    private ExceptionSpecification espec;

    protected Declarator() {
        object_print_method = class_print_method;

        parent = null;
        children = new LinkedList<Traversable>();

        leading_specs = new LinkedList<Specifier>();
    }

    @SuppressWarnings("unused")
    protected Declarator(int size) {
        object_print_method = class_print_method;

        parent = null;
        children = new LinkedList<Traversable>();

        leading_specs = new LinkedList<Specifier>();
    }

    public void addParameter(Declaration decl) {
        if (decl.getParent() != null) {
            throw new NotAnOrphanException();
        }

        parameters.add(decl);
        decl.setParent(this);
    }

    public void addParameterBefore(Declaration ref, Declaration decl) {
        int index = Tools.indexByReference(parameters, ref);

        if (index == -1) {
            throw new IllegalArgumentException();
        }

        if (decl.getParent() != null) {
            throw new NotAnOrphanException();
        }

        parameters.add(index, decl);
        decl.setParent(this);
    }

    public void addParameterAfter(Declaration ref, Declaration decl) {
        int index = Tools.indexByReference(parameters, ref);

        if (index == -1) {
            throw new IllegalArgumentException();
        }

        if (decl.getParent() != null) {
            throw new NotAnOrphanException();
        }

        parameters.add(index + 1, decl);
        decl.setParent(this);
    }

    /* **AP**
    Adding method for removing parameters from declarator list
     */
    public void removeParameter(Declaration decl) {
        int index = Tools.indexByReference(parameters, decl);

        if (index == -1) {
            throw new IllegalArgumentException();
        }

        decl.setParent(null);
        parameters.remove(decl);
    }

    // This method is called only by the parser when accepting bit-field.
    public void addTrailingSpecifier(Specifier spec) {
        if (trailing_specs == null) {
            trailing_specs = new ChainedList<Specifier>();
        }
        trailing_specs.add(spec);
    }

    public Object clone() {
        Declarator d = null;

        try {
            d = (Declarator) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new InternalError();
        }

        d.parent = null;
        d.children = new LinkedList<Traversable>();

        if (leading_specs != null) {
            d.leading_specs = (new ChainedList<Specifier>()).addAllLinks(leading_specs);
        } else {
            d.leading_specs = null;
        }

        if (direct_decl != null) {
            d.direct_decl = (IDExpression) direct_decl.clone();
        } else {
            d.direct_decl = null;
        }

        if (nested_decl != null) {
            d.nested_decl = (Declarator) nested_decl.clone();
        } else {
            d.nested_decl = null;
        }

        if (parameters != null) {
            //d.parameters = Tools.cloneList(parameters);
        } else {
            d.parameters = null;
        }

        if (trailing_specs != null) {
            d.trailing_specs = (new ChainedList<Specifier>()).addAllLinks(trailing_specs);
        } else {
            d.trailing_specs = null;
        }
        d.espec = espec;
        /*
        if (espec != null)
        d.espec = (ExceptionSpecification)espec.clone();
        else
        d.espec = null;
         */
        if (children.size() > 0) {
            if (children.get(0) instanceof Initializer) {

                Initializer init = (Initializer) getInitializer().clone();
                d.setInitializer(init);
            }

        }

        return d;
    }

    /**
     * Prints a declarator to a stream.
     *
     * @param decl The declarator to print.
     * @param stream The stream on which to print the declarator.
     */
    public static void defaultPrint(Declarator decl, OutputStream stream) {
        PrintStream p = new PrintStream(stream);

        Tools.printList(decl.leading_specs, stream);

        if (decl.direct_decl != null) {
            decl.direct_decl.print(stream);
        } else if (decl.nested_decl != null) {
            p.print("(");
            decl.nested_decl.print(stream);
            p.print(")");
        }

        if (decl.parameters != null) {
            p.print("(");
            Tools.printListWithCommas(decl.parameters, stream);
            p.print(")");
        }

        Tools.printList(decl.trailing_specs, stream);

        if (decl.getInitializer() != null) {
            decl.getInitializer().print(stream);
        }
    }

    public String toString() {
        StringBuilder str = new StringBuilder(80);

        str.append(Tools.listToString(leading_specs, ""));

        if (direct_decl != null) {
            str.append(direct_decl.toString());
        } else if (nested_decl != null) {
            str.append("(" + nested_decl.toString() + ")");
        }

        if (parameters != null) {
            str.append("(" + Tools.listToString(parameters, ", ") + ")");
        }

        str.append(Tools.listToString(trailing_specs, ""));

        if (getInitializer() != null) {
            str.append(getInitializer().toString());
        }

        return str.toString();
    }

    public List<Traversable> getChildren() {
        return children;
    }

    public Initializer getInitializer() {
        if (children.size() > 0) {
            return (Initializer) children.get(0);
        } else {
            return null;
        }
    }

    /**
     * Returns a List of Function Parameter
     *
     * @return List null is returned when there is no Function Parameter in the Declarator
     */
    public List<Declaration> getParameters() {
        return parameters;
    }

    public Traversable getParent() {
        return parent;
    }

    /**
     * Returns a List of ArraySpecifier
     *
     * @return An empty list if there is no ArraySpecifier for this Declarator.
     */
    public List<Specifier> getArraySpecifiers() {
        return trailing_specs;
    }

    public List<Specifier> getSpecifiers() {
        return leading_specs;
    }

    /**
     * Returns the symbol declared by this declarator.
     */
    public IDExpression getSymbol() {
        if (direct_decl != null) {
            return direct_decl;
        } else if (nested_decl != null) {
            return nested_decl.getSymbol();
        } else {
            return null;
        }
    }

    public void print(OutputStream stream) {
        Object[] args = new Object[2];
        args[0] = this;
        args[1] = stream;

        if (object_print_method == null) {
            throw new NullPointerException();
        }

        try {
            object_print_method.invoke(null, args);
        } catch (IllegalAccessException e) {
            System.err.println(e);
            e.printStackTrace();
            System.exit(1);
        } catch (InvocationTargetException e) {
            System.err.println(e.getCause());
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void removeChild(Traversable child) {
        throw new UnsupportedOperationException();
    }

    public void setChild(int index, Traversable t) {
        throw new UnsupportedOperationException();
    }

    IDExpression getDirectDeclarator() {
        return direct_decl;
    }

    void setDirectDeclarator(IDExpression direct_decl) {
        this.direct_decl = direct_decl;
        nested_decl = null;
    }

    /**
     * Sets the initial value of the variable.  The initial
     * value cannot be set in the constructor, for the purpose
     * of limiting the number of constructors.
     *
     * @param init An initial value for the variable.
     */
    public void setInitializer(Initializer init) {
        if (getInitializer() != null) {
            getInitializer().setParent(null);

            if (init != null) {
                children.set(0, init);
                init.setParent(this);
            } else {
                children.clear();
            }
        } else {
            if (init != null) {
                children.add(init);
                init.setParent(this);
            } else {
                children.clear();
            }
        }
    }

    public void setParent(Traversable t) {
        parent = t;
    }
}
