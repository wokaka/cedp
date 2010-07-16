package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a function or method call.
 */
public class FunctionCall extends Expression {

    private static Method class_print_method;

    static {
        Class<?>[] params = new Class<?>[2];

        try {
            params[0] = FunctionCall.class;
            params[1] = OutputStream.class;
            class_print_method = params[0].getMethod("defaultPrint", params);
        } catch (NoSuchMethodException e) {
            throw new InternalError();
        }
    }

    /**
     * Creates a function call.
     *
     * @param function An expression that evaluates to a function.
     */
    public FunctionCall(Expression function) {
        object_print_method = class_print_method;
        needs_parens = false;

        setFunction(function);
    }

    /**
     * Creates a function call.
     *
     * @param function An expression that evaluates to a function.
     * @param args A list of arguments to the function.
     */
    public FunctionCall(Expression function, List<Expression> args) {
        object_print_method = class_print_method;
        needs_parens = false;

        setFunction(function);
        setArguments(args);
    }

    public void addArgument(Expression expr) {
        if (expr.getParent() != null) {
            throw new NotAnOrphanException();
        }

        children.add(expr);
        expr.setParent(this);
    }

    /**
     * Prints a function call to a stream.
     *
     * @param call The call to print.
     * @param stream The stream on which to print the call.
     */
    public static void defaultPrint(FunctionCall call, OutputStream stream) {
        PrintStream p = new PrintStream(stream);

        if (call.needs_parens) {
            p.print("(");
        }

        call.getName().print(stream);
        p.print("(");
        List<Traversable> tmp = (new ChainedList<Traversable>()).addAllLinks(call.children);
        tmp.remove(0);
        Tools.printListWithCommas(tmp, stream);
        p.print(")");

        if (call.needs_parens) {
            p.print(")");
        }
    }

    public String toString() {
        StringBuilder str = new StringBuilder(80);

        if (needs_parens) {
            str.append("(");
        }

        str.append(getName());
        str.append("(");
        List<Traversable> tmp = (new ChainedList<Traversable>()).addAllLinks(children);
        tmp.remove(0);
        str.append(Tools.listToString(tmp, ", "));
        str.append(")");

        if (needs_parens) {
            str.append(")");
        }

        return str.toString();
    }

    public Expression getArgument(int n) {
        return (Expression) children.get(n + 1);
    }

    public List<Expression> getArguments() {
        LinkedList<Expression> list = new LinkedList<Expression>();
        for (int i = 1; i < children.size(); i++) {
            if (children.get(i) instanceof Expression) {
                list.add((Expression) children.get(i));
            }
        }
        //list.remove(0);
        return list;
    }

    public Expression getName() {
        return (Expression) children.get(0);
    }

    /**
     * Returns the number of arguments being passed to this function call.
     *
     * @return the number of arguments being passed to this function call.
     */
    public int getNumArguments() {
        return children.size() - 1;
    }

    /**
     * Returns the Procedure object for the function that is being called.
     *
     * @return the Procedure object for the function that is being called.
     */
    public Procedure getProcedure() {
        Traversable t = this;

        do {
            if (t == null) {
                return null;
            }
            t = t.getParent();
        } while (!(t instanceof SymbolTable));

        SymbolTable table = (SymbolTable) t;

        Declaration decl = null;
        try {
            decl = table.findSymbol((IDExpression) getName());
        } catch (ClassCastException e) {
            return null;
        }

        if (decl instanceof Procedure) {
            return (Procedure) decl;
        } else if (decl instanceof VariableDeclaration) {
            t = this;
            while (t.getParent() != null) {
                t = t.getParent();
            }

            Program prog = (Program) t;

            FlatIterator iter = new FlatIterator(prog);
            while (iter.hasNext()) {
                TranslationUnit tu = (TranslationUnit) iter.next();
                Object o = tu.findSymbol((IDExpression) getName());
                if (o != null && o instanceof Procedure) {
                    return (Procedure) o;
                }
            }

            return null;
        } else {
            return null;
        }
    }

    public List<Specifier> getReturnType() {
        Traversable t = this;

        do {
            t = t.getParent();
        } while (!(t instanceof SymbolTable));

        SymbolTable table = (SymbolTable) t;

        Declaration decl = null;
        try {
            decl = table.findSymbol((IDExpression) getName());
        } catch (ClassCastException e) {
            System.err.println("Cast Exception in FunctionCall.getReturnType: " + getName().toString());
        }

        if (decl == null) {
            return new LinkedList<Specifier>();
        } else if (decl instanceof VariableDeclaration) {
            List<Specifier> list = new LinkedList<Specifier>();
            list.addAll(((VariableDeclaration) decl).getSpecifiers());

            /* must also get specifiers from the declarator */
            Declarator d = ((VariableDeclaration) decl).getDeclarator(0);
            list.addAll(d.getSpecifiers());

            return list;
        } else if (decl instanceof Procedure) {
            return ((Procedure) decl).getReturnType();
        } else {
            return new LinkedList<Specifier>();
        }
    }

    public void setArgument(int n, Expression expr) {
        children.set(n + 1, expr);
    }

    public void setArguments(List<Expression> args) {
        Traversable save = children.get(0);
        children.clear();
        children.add(save);
        /*
        Iterator iter = args.iterator();
        while (iter.hasNext())
        {
        Expression expr = null;
        try {
        expr = (Expression)iter.next();
        } catch (ClassCastException e) {
        throw new IllegalArgumentException();
        }

        children.add(expr);
        expr.setParent(this);
        }
         */
        for (Object o : args) {
            Expression expr = null;
            try {
                expr = (Expression) o;
            } catch (ClassCastException e) {
                throw new IllegalArgumentException();
            }

            children.add(expr);
            expr.setParent(this);
        }
    }

    /**
     * Overrides the class print method, so that all subsequently
     * created objects will use the supplied method.
     *
     * @param m The new print method.
     */
    static public void setClassPrintMethod(Method m) {
        class_print_method = m;
    }

    public void setFunction(Expression expr) {
        if (expr.getParent() != null) {
            throw new NotAnOrphanException();
        }

        if (children.size() == 0) {
            children.add(expr);
        } else {
            children.set(0, expr);
        }

        expr.setParent(this);
    }
}
