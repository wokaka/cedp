package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a function, subroutine, or method.
 */
public final class Procedure extends Declaration implements SymbolTable, Symbol, Traversable {

    private static Method class_print_method;

    static {
        Class<?>[] params = new Class<?>[2];

        try {
            params[0] = Procedure.class;
            params[1] = OutputStream.class;
            class_print_method = params[0].getMethod("defaultPrint", params);
        } catch (NoSuchMethodException e) {
            throw new InternalError();
        }
    }

    private List<Specifier> leading_specs;
    private Declarator declarator;
    @SuppressWarnings("unused")
    private List<Expression> initializers;
    private Map<IDExpression, Declaration> symbol_table;

    /**
     * Creates a constructor definition (declaration plus body).
     *
     * @param declarator The name and parameter list of the procedure.  Must not be null.
     * @param body The body of the procedure.
     */
    public Procedure(Declarator declarator, CompoundStatement body) {
        object_print_method = class_print_method;

        this.leading_specs = new LinkedList<Specifier>();
        this.declarator = declarator;
        symbol_table = new HashMap<IDExpression, Declaration>();

        if (body.getParent() != null) {
            throw new IllegalArgumentException();
        }

        children.add(body);
        body.setParent(this);

        Iterator<Declaration> i = declarator.getParameters().iterator();
        while (i.hasNext()) {
            VariableDeclaration vdec = (VariableDeclaration) i.next();
            Tools.addSymbols(this, vdec);
        }
    }

    /**
     * Creates a procedure definition (declaration plus body).
     *
     * @param leading_specs A list of specifiers describing the return type of the procedure.  May be null.
     * @param declarator The name and parameter list of the procedure.  Must not be null.
     * @param body The body of the procedure.
     */
    public Procedure(List<Specifier> leading_specs, Declarator declarator, CompoundStatement body) {
        object_print_method = class_print_method;

        this.leading_specs = (new ChainedList<Specifier>()).addAllLinks(leading_specs);
        this.declarator = declarator;
        symbol_table = new HashMap<IDExpression, Declaration>();

        if (body.getParent() != null) {
            throw new IllegalArgumentException();
        }

        children.add(body);
        body.setParent(this);

        if (declarator.getParameters() != null) {
            Iterator<Declaration> i = declarator.getParameters().iterator();
            while (i.hasNext()) {
                VariableDeclaration vdec = (VariableDeclaration) i.next();
                Tools.addSymbols(this, vdec);
            }
        }
    }

    /**
     * Creates a procedure definition (declaration plus body).
     *
     * @param spec A specifier describing the return type of the procedure.
     * @param declarator The name and parameter list of the procedure.  Must not be null.
     * @param body The body of the procedure.
     */
    public Procedure(Specifier spec, Declarator declarator, CompoundStatement body) {
        object_print_method = class_print_method;

        this.leading_specs = (new ChainedList<Specifier>()).addLink(spec);
        this.declarator = declarator;
        symbol_table = new HashMap<IDExpression, Declaration>();

        if (body.getParent() != null) {
            throw new IllegalArgumentException();
        }

        children.add(body);
        body.setParent(this);

        if (declarator.getParameters() != null) {
            Iterator<Declaration> i = declarator.getParameters().iterator();
            while (i.hasNext()) {
                VariableDeclaration vdec = (VariableDeclaration) i.next();
                Tools.addSymbols(this, vdec);
            }
        }
    }

    /**
     * Add parameter declarations to the procedure.
     */
    public void addDeclaration(Declaration decl) {
        declarator.addParameter(decl);
        Tools.addSymbols(this, decl);
    }

    public void addDeclarationBefore(Declaration ref, Declaration decl) {
        declarator.addParameterBefore(ref, decl);
        Tools.addSymbols(this, decl);
    }

    public void addDeclarationAfter(Declaration ref, Declaration decl) {
        declarator.addParameterAfter(ref, decl);
        Tools.addSymbols(this, decl);
    }

    /* **AP**
    Adding method for easy removal of parameters
     */
    public void removeDeclaration(Declaration decl) {
        declarator.removeParameter(decl);
        Tools.removeSymbols((SymbolTable) this, decl);
    }

    /**
     * Prints a procedure to a stream.
     *
     * @param proc The procedure to print.
     * @param stream The stream on which to print the procedure.
     */
    public static void defaultPrint(Procedure proc, OutputStream stream) {
        PrintStream p = new PrintStream(stream);

        Tools.printListWithSeparator(proc.leading_specs, stream, " ");
        p.print(" ");
        proc.declarator.print(stream);
        p.println("");
        proc.getBody().print(stream);
        p.println("");
    }

    /**
     * John A. Stratton
     * Need a blank printing procedure: removal of the procedure
     * seems to have problems
     */
    @SuppressWarnings("unused")
    public static void noPrint(Procedure proc, OutputStream stream) {

        return;
    }

    public String toString() {
        StringBuilder str = new StringBuilder(80);

        str.append(Tools.listToString(leading_specs, " "));
        str.append(" " + declarator.toString());
        str.append("\n" + getBody().toString() + "\n");

        return str.toString();
    }

    public Declaration findSymbol(IDExpression name) {
        return Tools.findSymbol(this, name);
    }

    /**
     * Returns the body of this procedure.
     *
     * @return the body of this procedure.
     */
    public CompoundStatement getBody() {
        return (CompoundStatement) children.get(0);
    }

    public List<IDExpression> getDeclaredSymbols() {
        return (new ChainedList<IDExpression>()).addLink(declarator.getSymbol());
    }

    /**
     * Returns the name of the procedure.
     *
     * @return the name of the procedure.
     */
    public IDExpression getName() {
        return declarator.getSymbol();
    }

    public int getNumParameters() {
        return declarator.getParameters().size();
    }

    public List<Declaration> getParameters() {
        return declarator.getParameters();
    }

    public List<SymbolTable> getParentTables() {
        return Tools.getParentTables(this);
    }

    public List<Specifier> getReturnType() {
        List<Specifier> list = new LinkedList<Specifier>();
        list.addAll(leading_specs);
        list.addAll(declarator.getSpecifiers());
        return list;
    }

    public Map<IDExpression, Declaration> getTable() {
        return symbol_table;
    }

    public void setBody(CompoundStatement body) {
        if (getBody() != null) {
            getBody().setParent(null);
        }

        if (body.getParent() != null) {
            throw new NotAnOrphanException();
        }

        children.set(0, body);
        body.setParent(this);
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

    public void setConstructorInitializers(List<Expression> list) {
        initializers = list;
    }

    public void setName(IDExpression name) {
        declarator.setDirectDeclarator(name);
    }

    // Symbol interface
    public String getSymbolName() {
        return getName().toString();
    }

    public List<Specifier> getTypeSpecifiers() {
        return getReturnType();
    }

    public List<Specifier> getArraySpecifiers() {
        return null;
    }

    /**
     * John A. Stratton: February 2008
     * Functions for viewing and manipulating the specifiers attached
     * to the function.
     */
    public boolean removeProcedureSpec(Specifier spec) {
        return leading_specs.remove(spec);
    }
}
