package cetus.hir;

import java.io.*;
import java.util.*;

import cetus.exec.*;
import cetus.analysis.*;

/**
 * A collection of useful static methods that operate on the IR.
 * In general, code goes here if it is used by multiple classes
 * that have no common ancestor.  Java does not have multiple
 * inheritence, and it seems better to put the code here instead
 * of introducing extra classes to solve the problem.  Note that
 * interfaces cannot solve the problem because you cannot provide
 * an implementation of a method within an interface. 
 */
public abstract class Tools {

    static final int verbosity = Integer.valueOf(Driver.getOptionValue("verbosity")).intValue();
    static final Set<String> unary_def;

    static {
        // Add increment/decrement operator in search list.
        unary_def = new HashSet<String>();
        unary_def.add("--");
        unary_def.add("++");
    }

    /**
     * Java doesn't allow a class to be both abstract and final,
     * so this private constructor prevents any derivations.
     */
    private Tools() {
    }

    /**
     * Adds symbols to a symbol table and checks for duplicates.
     *
     * @param table The symbol table to add the symbols to.
     * @param decl The declaration of the symbols.
     * @throws DuplicateSymbolException if there are conflicts with
     *   any existing symbols in the table.
     */
    public static void addSymbols(SymbolTable table, Declaration decl) {
        List<IDExpression> names = decl.getDeclaredSymbols();
        Iterator<IDExpression> iter = names.iterator();

        Map<IDExpression, Declaration> symbol_table = table.getTable();

        while (iter.hasNext()) {
            IDExpression expr = iter.next();

            if (!(decl instanceof Procedure) && symbol_table.containsKey(expr)) {
                //throw new DuplicateSymbolException(expr.toString() + " is already in this table");
                //System.err.println("[WARNING] " + expr.toString() + " is already in this table");
            } else {
                symbol_table.put(expr, decl);
                // Link ID => Symbol
                DepthFirstIterator sym_iter = new DepthFirstIterator(decl);
                while (sym_iter.hasNext()) {
                    Object o = sym_iter.next();
                    if ((o instanceof Symbol)
                            && ((Symbol) o).getSymbolName().equals(expr.toString())) {
                        expr.setSymbol((Symbol) o);
                    }
                }
            }
        }
    }

    /**
     * Searches the IR tree beginning at t for the Expression e.
     *
     * @return true if t contains e and false otherwise
     */
    public static boolean containsExpression(Traversable t, Expression e) {
        return (t.toString().indexOf(e.toString()) != -1);
    }

    /**
     * Counts the number of times that the Expression e appears in
     * the IR tree t.
     *
     * @return the number of times e appears in t
     */
    public static int countExpressions(Traversable t, Expression e) {
        String t_string = t.toString();
        String e_string = e.toString();
        int e_string_length = e_string.length();

        int i, n = 0;

        while ((i = t_string.indexOf(e_string)) != -1) {
            ++n;

            t_string = t_string.substring(i + e_string_length);
        }

        return n;
    }

    /**
     * Finds the first instance of the Expression e in the IR tree t.
     *
     * @return an expression from t that matches e
     */
    public static Expression findExpression(Traversable t, Expression e) {
        DepthFirstIterator iter = new DepthFirstIterator(t);
        String e_string = e.toString();

        for (;;) {
            Expression t_e;

            try {
                t_e = iter.next(Expression.class);
            } catch (NoSuchElementException nse) {
                break;
            }

            if (t_e.toString().compareTo(e_string) == 0) {
                return t_e;
            }
        }

        return null;
    }

    /**
     * Finds the list of instance of the Expression e in the IR tree t.
     *
     * @return an expression from t that matches e
     */
    public static List<Integer> findUniqueExpressionList(Traversable t, Expression e) {
        DepthFirstIterator iter = new DepthFirstIterator(t);
        String e_string = e.toString();
        LinkedList<Integer> list = new LinkedList<Integer>();

        for (;;) {
            Expression t_e;

            try {
                t_e = iter.next(Expression.class);
            } catch (NoSuchElementException nse) {
                break;
            }

            if (t_e.toString().compareTo(e_string) == 0) {
                list.add(new Integer(System.identityHashCode(t_e)));
            }
        }

        return list;
    }

    /**
     * Searches for a symbol by name in the table.  If the symbol is
     * not in the table, then parent tables will be searched breadth-first.
     *
     * @param table The initial table to search.
     * @param name The name of the symbol to locate.
     *
     * @return a Declaration if the symbol is found, or null if it is not found.
     *    The Declaration may contain multiple declarators, of which name will
     *    be one, unless the SingleDeclarator pass has been run on the program.
     */
    public static Declaration findSymbol(SymbolTable table, IDExpression name) {
        LinkedList<SymbolTable> tables_to_search = new LinkedList<SymbolTable>();
        tables_to_search.add(table);

        /* Treat tables_to_search as a queue of tables, adding parent
        tables to the end of the list if name isn't in the current table. */
        while (!tables_to_search.isEmpty()) {
            SymbolTable st = tables_to_search.removeFirst();

            Declaration decl = st.getTable().get(name);

            if (decl != null) {
                return decl;
            }

            tables_to_search.addAll(st.getParentTables());
        }

        return null;
    }

    /**
     * Searches for a symbol by String sname in the table. If the symbol is
     * not in the table, then parent tables will be searched breadth-first.
     * If multiple symbols have the same String name, the first one found
     * during the search will be returned.
     *
     * @param table The initial table to search.
     * @param sname The String name of the symbol (Symbol.getSymbolName()) to locate.
     *
     * @return a Declaration if the symbol is found, or null if it is not found.
     *    The Declaration may contain multiple declarators, of which sname will
     *    be one, unless the SingleDeclarator pass has been run on the program.
     */
    public static Declaration findSymbol(SymbolTable table, String sname) {
        LinkedList<SymbolTable> tables_to_search = new LinkedList<SymbolTable>();
        tables_to_search.add(table);

        /* Treat tables_to_search as a queue of tables, adding parent
        tables to the end of the list if name isn't in the current table. */
        while (!tables_to_search.isEmpty()) {
            SymbolTable st = tables_to_search.removeFirst();
            Set<Symbol> symbolset = getSymbols(st);
            for (Symbol sym : symbolset) {
                if (sym.getSymbolName().compareTo(sname) == 0) {
                    Declaration decl = (Declaration) ((Declarator) sym).getParent();
                    if (decl != null) {
                        return decl;
                    }
                }
            }
            tables_to_search.addAll(st.getParentTables());
        }

        return null;
    }

    public static List<SymbolTable> getParentTables(Traversable obj) {
        LinkedList<SymbolTable> list = new LinkedList<SymbolTable>();

        Traversable p = obj.getParent();
        while (p != null) {
            try {
                SymbolTable st = (SymbolTable) p;
                list.add(st);
                break;
            } catch (ClassCastException e) {
                p = p.getParent();
            }
        }

        return list;
    }

    /**
     * Returns a randomly-generated name that is not found in the table.
     *
     * @param table The table to search.
     *
     * @return a unique name.
     */
    public static Identifier getUnusedSymbol(SymbolTable table) {
        String name = null;
        Identifier ident = null;
        Random rand = new Random();

        do {
            name = "";
            name += (char) ('a' + (rand.nextInt(25))); //% 26));  //*AP*
            name += (char) ('a' + (rand.nextInt(25))); //% 26));  //*AP*
            name += (char) ('a' + (rand.nextInt(25))); //% 26));  //*AP*
            name += (char) ('a' + (rand.nextInt(25))); //% 26));  //*AP*
            name += (char) ('a' + (rand.nextInt(25))); //% 26));  //*AP*
            name += (char) ('a' + (rand.nextInt(25))); //% 26));  //*AP*
            name += (char) ('a' + (rand.nextInt(25))); //% 26));  //*AP*
            name += (char) ('a' + (rand.nextInt(25))); //% 26));  //*AP*

            ident = new Identifier(name);
            /**
             * John A. Stratton
             * Bug fix: leave when we -don't- get an existing symbol
             */
        } while (findSymbol(table, ident) != null);

        return ident;
    }

    /**
     * The standard indexOf methods on lists use the equals method
     * when searching for an object; sometimes we want to use ==
     * and this method provides that service.
     *
     * @param list The list to search.
     * @param obj The object sought.
     *
     * @return the index of the object or -1 if it cannot be found.
     */
    public static int indexByReference(List<?> list, Object obj) {
        int index = 0;

        Iterator<?> iter = list.iterator();
        while (iter.hasNext()) {
            if (iter.next() == obj) {
                return index;
            } else {
                index++;
            }
        }

        return -1;
    }

    /**
     * Calls print on every element of the list; does not put any
     * spaces or other text between the elements.
     *
     * @param list The list to print, which must contain only Printable objects.
     * @param stream The stream on which to print.
     */
    public static void printList(List<? extends Printable> list, OutputStream stream) {
        if (list != null) {
            Iterator<? extends Printable> iter = list.iterator();
            while (iter.hasNext()) {
                iter.next().print(stream);
            }
        }
    }

    /**
     * Calls print on every element of the list and prints a newline
     * after each element.
     *
     * @param list The list to print, which must contain only Printable objects.
     * @param stream The stream on which to print.
     */
    public static void printlnList(List<? extends Printable> list, OutputStream stream) {
        if (list == null || list.size() == 0) {
            return;
        }

        PrintStream p = new PrintStream(stream);

        Iterator<? extends Printable> iter = list.iterator();
        while (iter.hasNext()) {
            iter.next().print(stream);
            p.println("");
        }
    }

    /**
     * Prints a Printable object to System.err if the
     * verbosity level is greater than min_verbosity.
     *
     * @param p A Printable object.
     * @param min_verbosity An integer to compare with the value
     *   set by the -verbosity command-line flag.
     */
    public static void printlnStatus(Printable p, int min_verbosity) {
        if (verbosity >= min_verbosity) {
            p.print(System.err);
            System.err.println("");
        }
    }

    /**
     * Prints a string to System.err if the
     * verbosity level is greater than min_verbosity.
     *
     * @param message The message to print.
     * @param min_verbosity An integer to compare with the value
     *   set by the -verbosity command-line flag.
     */
    public static void printlnStatus(String message, int min_verbosity) {
        if (verbosity >= min_verbosity) {
            System.err.println(message);
        }
    }

    public static void print(String message, int min_verbosity) {
        if (verbosity >= min_verbosity) {
            System.out.print(message);
        }
    }

    public static void println(String message, int min_verbosity) {
        if (verbosity >= min_verbosity) {
            System.out.println(message);
        }
    }

    /**
     * Prints a Printable object to System.err if the
     * verbosity level is greater than min_verbosity.
     *
     * @param p A Printable object.
     * @param min_verbosity An integer to compare with the value
     *   set by the -verbosity command-line flag.
     */
    public static void printStatus(Printable p, int min_verbosity) {
        if (verbosity >= min_verbosity) {
            p.print(System.err);
        }
    }

    /**
     * Prints a string to System.err if the
     * verbosity level is greater than min_verbosity.
     *
     * @param message The message to print.
     * @param min_verbosity An integer to compare with the value
     *   set by the -verbosity command-line flag.
     */
    public static void printStatus(String message, int min_verbosity) {
        if (verbosity >= min_verbosity) {
            System.err.print(message);
        }
    }

    /**
     * Calls print on every element of the list and prints a comma
     * and a space between elements.
     *
     * @param list The list to print, which must contain only Printable objects.
     * @param stream The stream on which to print.
     */
    public static void printListWithCommas(List<? extends Printable> list, OutputStream stream) {
        printListWithSeparator(list, stream, ", ");
    }

    /**
     * Calls print on every element of the list and prints a string between them.
     * If the list has a single element, no separator is printed.
     *
     * @param list The list to print, which must contain only Printable objects.
     * @param stream The stream on which to print.
     * @param separator A string to print between the objects.
     */
    public static void printListWithSeparator(List<? extends Printable> list,
            OutputStream stream, String separator) {
        if (list == null || list.size() == 0) {
            return;
        }

        PrintStream p = new PrintStream(stream);

        Iterator<? extends Printable> iter = list.iterator();
        if (iter.hasNext()) {
            iter.next().print(stream);
            while (iter.hasNext()) {
                p.print(separator);
                iter.next().print(stream);
            }
        }
    }

    /**
     * Checks if the IR tree is consistent; it traverses the tree and checks if
     * every item can reach the root node.
     *
     * @param t the root IR object.
     * @return true if it is consistent, false otherwise.
     */
    public static boolean checkConsistency(Traversable t) {
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Traversable tr = iter.next();
            while (tr != null && tr != t) {
                tr = tr.getParent();
            }
            if (tr == null) {
                return false;
            }
        }
        return true;
    }

    public static int getVerbosity() {
        return verbosity;
    }

    /**
     * Converts a collection of objects to a string with the given separator.
     * By default, the element of the collections are sorted alphabetically.
     *
     * @param coll the collection to be converted.
     * @param separator the separating string.
     * @return the converted string.
     */
    public static String collectionToString(Collection<?> coll, String separator) {
        if (coll == null || coll.size() == 0) {
            return "";
        }

        // Sort the collection first.
        TreeSet<String> sorted = new TreeSet<String>();
        for (Object o : coll) {
            if (o instanceof Symbol) {
                sorted.add(((Symbol) o).getSymbolName());
            } else {
                sorted.add(o.toString());
            }
        }

        StringBuilder str = new StringBuilder(80);

        Iterator<String> iter = sorted.iterator();
        if (iter.hasNext()) {
            str.append(iter.next());
            while (iter.hasNext()) {
                str.append(separator);
                str.append(iter.next());
            }
        }

        return str.toString();
    }

    /**
     * Converts a list of objects to a string with the given separator.
     *
     * @param list the list to be converted.
     * @param separator the separating string.
     * @return the converted string.
     */
    public static String listToString(List<?> list, String separator) {
        if (list == null || list.size() == 0) {
            return "";
        }

        StringBuilder str = new StringBuilder(80);

        Iterator<?> iter = list.iterator();
        if (iter.hasNext()) {
            str.append(iter.next().toString());
            while (iter.hasNext()) {
                str.append(separator + iter.next().toString());
            }
        }

        return str.toString();
    }

    public static String mapToString(Map<?, ?> map, String separator) {
        if (map == null || map.size() == 0) {
            return "";
        }

        StringBuilder str = new StringBuilder(80);

        Iterator<?> iter = map.keySet().iterator();
        if (iter.hasNext()) {
            Object key = iter.next();
            str.append(key.toString() + ":" + map.get(key).toString());
            while (iter.hasNext()) {
                key = iter.next();
                str.append(separator + key.toString() + ":" + map.get(key).toString());
            }
        }
        return str.toString();
    }

    /**
     * Replaces all instances of expression <var>x</var> on the IR tree
     * beneath <var>t</var> by <i>clones of</i> expression <var>y</var>.
     * Skips the immediate right hand side of member access expressions.
     *
     * @param t The location at which to start the search.
     * @param x The expression to be replaced.
     * @param y The expression to substitute.
     */
    public static void replaceAll(Traversable t, Expression x, Expression y) {
        BreadthFirstIterator iter = new BreadthFirstIterator(t);

        for (;;) {
            Expression o = null;

            try {
                o = iter.next(x.getClass());
            } catch (NoSuchElementException e) {
                break;
            }

            if (o.equals(x)) {
                if (o.getParent() instanceof AccessExpression
                        && ((AccessExpression) o.getParent()).getRHS() == o) {
                    /* don't replace these */
                } else {
                    if (o.getParent() == null) {
                        System.err.println("[ERROR] this " + o.toString() + " should be on the tree");
                    }

                    Expression copy = (Expression) y.clone();
                    o.swapWith(copy);

                    if (copy.getParent() == null) {
                        System.err.println("[ERROR] " + y.toString() + " didn't get put on tree properly");
                    }
                }
            }
        }
    }

    /**
     * Removes the symbols declared by the declaration from the symbol
     * table.
     *
     * @param table The table from which to remove the symbols.
     * @param decl The declaration of the symbols.
     */
    public static void removeSymbols(SymbolTable table, Declaration decl) {
        List<IDExpression> names = decl.getDeclaredSymbols();
        Iterator<IDExpression> iter = names.iterator();

        Map<IDExpression, Declaration> symbol_table = table.getTable();

        while (iter.hasNext()) {
            IDExpression symbol = iter.next();

            if (symbol_table.remove(symbol) == null) {
                System.err.println("Tools.removeSymbols could not remove entry for " + symbol.toString());
                System.err.println("table contains only " + symbol_table.toString());
            }
        }
    }

    /**
     * Verifies that every element of the list is of the same type.
     *
     * @param list The list to verify.
     * @param type The desired type for all elements.
     * @return true if all elements pass isInstance checks, false otherwise
     */
    public static <T> boolean verifyHomogeneousList(List<?> list, Class<T> type) {
        Iterator<?> iter = list.iterator();

        while (iter.hasNext()) {
            if (!type.isInstance(iter.next())) {
                return false;
            }
        }

        return true;
    }

    /**
     * Returns a new identifier derived from the given identifier.
     *
     * @param id the identifier from which type and scope are derived.
     * @return the new identifier.
     */
    public static Identifier getTemp(Identifier id) {
        return getTemp(id, id.getName());
    }

    /**
     * Returns a new identifier derived from the given IR object and identifier.
     *
     * @param where the IR object from which scope is derived.
     * @param id the identifier from which type is derived.
     * @return the new identifier.
     */
    public static Identifier getTemp(Traversable where, Identifier id) {
        return getTemp(where, id.getSymbol().getTypeSpecifiers(), id.getName());
    }

    /**
     * Returns a new identifier derived from the given identifier and name.
     *
     * @param id the identifier from which scope is derived.
     * @param name the string from which name is derived.
     * @return the new identifier.
     */
    public static Identifier getTemp(Identifier id, String name) {
        return getTemp(id, id.getSymbol().getTypeSpecifiers(), name);
    }

    /**
     * Returns a new identifier derived from the given IR object, type, and name.
     *
     * @param where the IR object from which scope is derived.
     * @param spec the type specifier.
     * @param name the string from which name is derived.
     * @return the new identifier.
     */
    public static Identifier getTemp(Traversable where, Specifier spec, String name) {
        List<Specifier> specs = new LinkedList<Specifier>();
        specs.add(spec);
        return getTemp(where, specs, name);
    }

    /**
     * Returns a new identifier derived from the given IR object, type list, and
     * name.
     *
     * @param where the IR object from which scope is derived.
     * @param specs the type specifiers.
     * @param name the string from which name is derived.
     * @return the new identifier.
     */
    public static Identifier getTemp(Traversable where, List<Specifier> specs, String name) {
        return getArrayTemp(where, specs, (List<Specifier>) null, name);
    }

    /**
     * Returns a new identifier derived from the given IR object, type list,
     * array specifier and name.
     *
     * @param where the IR object from which scope is derived.
     * @param specs the type specifiers.
     * @param aspec the array specifier.
     * @param name the string from which name is derived.
     * @return the new identifier.
     */
    public static Identifier getArrayTemp(Traversable where, List<Specifier> specs, Specifier aspec, String name) {
        List<Specifier> aspecs = new LinkedList<Specifier>();
        aspecs.add(aspec);
        return getArrayTemp(where, specs, aspecs, name);
    }

    /**
     * Returns a new identifier derived from the given IR object, type list,
     * array specifiers and name.
     *
     * @param where the IR object from which scope is derived.
     * @param specs the type specifiers.
     * @param aspecs the array specifier.
     * @param name the string from which name is derived.
     * @return the new identifier.
     */
    public static Identifier getArrayTemp(Traversable where, List<Specifier> specs, List<Specifier> aspecs, String name) {
        Traversable t = where;
        while (!(t instanceof SymbolTable)) {
            t = t.getParent();
        }
        // Traverse to the parent of a loop statement
        if (t instanceof ForLoop || t instanceof DoLoop || t instanceof WhileLoop) {
            t = t.getParent();
            while (!(t instanceof SymbolTable)) {
                t = t.getParent();
            }
        }
        SymbolTable st = (SymbolTable) t;

        String header = (name == null) ? "_temp_" : name + "_";
        Identifier ret = null;
        for (int trailer = 0; ret == null; ++trailer) {
            Identifier newid = new Identifier(header + trailer);
            if (findSymbol(st, newid) == null) {
                ret = newid;
            }
        }

        Declarator decl = null;
        if (aspecs == null) {
            decl = new VariableDeclarator(ret);
        } else {
            decl = new VariableDeclarator(ret, aspecs);
        }
        Declaration decls = new VariableDeclaration(specs, decl);
        st.addDeclaration(decls);
        ret.setSymbol(decl);

        return ret;
    }

    /**
     * Returns a new, pointer-type identifier derived from the given IR object.
     *
     * @param where the IR object from which scope is derived.
     * @param refID the identifier from which type and name are derived.
     * @return the new pointer-type identifier.
     */
    public static Identifier getPointerTemp(Traversable where, Identifier refID) {
        List<Specifier> pspecs = new LinkedList<Specifier>();
        pspecs.add(PointerSpecifier.UNQUALIFIED);
        return getPointerTemp(where, refID.getSymbol().getTypeSpecifiers(),
                pspecs, refID.getName());
    }

    /**
     * Returns a new, pointer-type identifier derived from the given IR object.
     *
     * @param where the IR object from which scope is derived.
     * @param specs the type specifiers.
     * @param name the string from which name is derived.
     * @return the new pointer-type identifier.
     */
    public static Identifier getPointerTemp(Traversable where, List<Specifier> specs, String name) {
        List<Specifier> pspecs = new LinkedList<Specifier>();
        pspecs.add(PointerSpecifier.UNQUALIFIED);
        return getPointerTemp(where, specs, pspecs, name);
    }

    /**
     * Returns a new, pointer-type identifier derived from the given IR object.
     *
     * @param where the IR object from which scope is derived.
     * @param specs the type specifiers.
     * @param pspecs the pointer-type specifiers.
     * @param name the string from which name is derived.
     * @return the new pointer-type identifier.
     */
    public static Identifier getPointerTemp(Traversable where, List<Specifier> specs, List<Specifier> pspecs, String name) {
        Traversable t = where;
        while (!(t instanceof SymbolTable)) {
            t = t.getParent();
        }
        // Traverse to the parent of a loop statement
        if (t instanceof ForLoop || t instanceof DoLoop || t instanceof WhileLoop) {
            t = t.getParent();
            while (!(t instanceof SymbolTable)) {
                t = t.getParent();
            }
        }
        SymbolTable st = (SymbolTable) t;

        String header = (name == null) ? "_temp_" : name + "_";
        Identifier ret = null;
        for (int trailer = 0; ret == null; ++trailer) {
            Identifier newid = new Identifier(header + trailer);
            if (findSymbol(st, newid) == null) {
                ret = newid;
            }
        }

        Declarator decl = new VariableDeclarator(pspecs, ret);
        Declaration decls = new VariableDeclaration(specs, decl);
        st.addDeclaration(decls);
        ret.setSymbol(decl);

        return ret;
    }

    /**
     * Returns the set of Symbol objects contained in the given SymbolTable
     * object.
     *
     * @param st the symbol table being searched.
     * @return the set of symbols.
     */
    public static Set<Symbol> getSymbols(SymbolTable st) {
        Set<Symbol> ret = new HashSet<Symbol>();
        if (st == null) {
            return ret;
        }
        for (Object key : st.getTable().keySet()) {
            Symbol symbol = ((IDExpression) key).getSymbol();
            if (symbol != null) {
                ret.add(symbol);
            }
        }
        return ret;
    }

    /**
     * Returns the set of Symbol objects contained in the given SymbolTable
     * object excluding Procedures.
     *
     * @param st the symbol table being searched.
     * @return the set of symbols.
     */
    public static Set<Symbol> getVariableSymbols(SymbolTable st) {
        Set<Symbol> ret = new HashSet<Symbol>();
        if (st == null) {
            return ret;
        }
        for (Object key : st.getTable().keySet()) {
            Symbol symbol = ((IDExpression) key).getSymbol();
            if (!(symbol == null
                    || symbol instanceof Procedure
                    || symbol instanceof ProcedureDeclarator)) {
                ret.add(symbol);
            }
        }
        return ret;
    }

    /**
     * Returns the set of Symbol objects that are global variables
     * of the File scope
     */
    public static Set<Symbol> getGlobalSymbols(Traversable t) {
        while (true) {
            if (t instanceof TranslationUnit) {
                break;
            }
            t = t.getParent();
        }
        TranslationUnit t_unit = (TranslationUnit) t;
        return Tools.getVariableSymbols(t_unit);
    }

    /**
     * Returns the Procedure to which the input traversable
     * object belongs
     */
    public static Procedure getParentProcedure(Traversable t) {
        while (true) {
            if (t instanceof Procedure) {
                break;
            }
            t = t.getParent();
        }
        return (Procedure) t;
    }

    /**
     * Returns the TranslationUnit to which the input traversable
     * object belongs
     */
    public static TranslationUnit getParentTranslationUnit(Traversable t) {
        while (true) {
            if (t instanceof TranslationUnit) {
                break;
            }
            t = t.getParent();
        }
        return (TranslationUnit) t;
    }

    /**
     * Returns the last declaration of the given traverable object
     */
    public static Declaration getLastDeclaration(Traversable t) {
        DeclarationStatement decl_stmt = getLastDeclarationStatement(t);
        if (decl_stmt == null) {
            return null;
        } else {
            return decl_stmt.getDeclaration();
        }
    }

    /**
     * Returns the last declaration statement of the given traverable object
     */
    public static DeclarationStatement getLastDeclarationStatement(Traversable t) {
        DeclarationStatement decl_stmt = null;
        for (Traversable child : t.getChildren()) {
            if (child.getClass() != DeclarationStatement.class) {
                break;
            }
            decl_stmt = (DeclarationStatement) child;
        }
        return decl_stmt;
    }

    /**
     * Returns the first non-DeclarationStatement of the given traverable object
     */
    public static Statement getFirstNonDeclarationStatement(Traversable t) {
        Statement non_decl_stmt = null;
        for (Traversable child : t.getChildren()) {
            if (child.getClass() != DeclarationStatement.class) {
                non_decl_stmt = (Statement) child;
                break;
            }
        }
        return non_decl_stmt;
    }

    /**
     * Returns the set of Symbol objects that are formal parameters of
     * the given Procedure
     */
    public static Set<Symbol> getParameterSymbols(Procedure proc) {
        HashSet<Symbol> parameters = new HashSet<Symbol>();
        for (Object o : proc.getParameters()) {
            VariableDeclaration var_decl = (VariableDeclaration) o;
            List<IDExpression> id_expr_list = var_decl.getDeclaredSymbols();

            for (IDExpression id_expr : id_expr_list) {
                if (id_expr.getSymbol() != null) {
                    parameters.add(id_expr.getSymbol());
                }
            }
        }

        return parameters;
    }

    public static Set<Symbol> getSideEffectSymbols(FunctionCall fc) {
        Set<Symbol> side_effect_set = new HashSet<Symbol>();

        // set of GlobalVariable Symbols that are accessed within a Procedure
        Procedure proc = fc.getProcedure();

        // we assume that there is no global variable access within a procedure
        // if a procedure body is not available for a compiler
        // example: system calls
        if (proc != null) {
            Set<Symbol> global_variables = new HashSet<Symbol>();
            Set<Symbol> accessed_symbols = getAccessedSymbols(proc.getBody());
            for (Symbol var : accessed_symbols) {
                if (isGlobal(var, proc)) {
                    global_variables.add(var);
                }
            }

            if (!global_variables.isEmpty()) {
                side_effect_set.addAll(global_variables);
            }
        }

        // find the set of actual parameter Symbols of each function call
        List<Expression> arguments = fc.getArguments();
        HashSet<Symbol> parameters = new HashSet<Symbol>();
        for (Expression e : arguments) {
            parameters.addAll(getAccessedSymbols(e));
        }

        if (!parameters.isEmpty()) {
            side_effect_set.addAll(parameters);
        }

        return side_effect_set;
    }

    /**
     * Returns the set of symbols accessed in the traversable object.
     *
     * @param t the traversable object.
     * @return the set of symbols.
     */
    public static Set<Symbol> getAccessedSymbols(Traversable t) {
        Set<Symbol> ret = new HashSet<Symbol>();

        if (t == null) {
            return ret;
        }

        DepthFirstIterator iter = new DepthFirstIterator(t);

        while (iter.hasNext()) {
            Object o = iter.next();
            if (!(o instanceof Identifier)) {
                continue;
            }
            Symbol symbol = ((Identifier) o).getSymbol();
            if (symbol != null) {
                ret.add(symbol);
            }
        }

        return ret;
    }

    /**
     * Returns the symbol object having the specified string name.
     * @param name the name to be searched for.
     * @param tr the IR location where searching starts.
     * @return the symbol object.
     */
    public static Symbol getSymbolOfName(String name, Traversable tr) {
        Symbol ret = null;
        Traversable t = tr;

        while (ret == null && t != null) {
            if (t instanceof SymbolTable) {
                Set<Symbol> symbols = getSymbols((SymbolTable) t);
                for (Symbol symbol : symbols) {
                    if (name.equals(symbol.getSymbolName())) {
                        ret = symbol;
                        break;
                    }
                }
            }
            t = t.getParent();
        }

        return ret;
    }

    /**
     * Returns a set of used expressions in the traversable object.
     *
     * @param t the traversable object.
     * @return the set of used expressions.
     */
    public static Set<Expression> getUseSet(Traversable t) {
        TreeSet<Expression> ret = new TreeSet<Expression>();

        DepthFirstIterator iter = new DepthFirstIterator(t);

        // Handle these expressions specially.
        iter.pruneOn(AccessExpression.class);
        iter.pruneOn(ArrayAccess.class);
        iter.pruneOn(AssignmentExpression.class);

        while (iter.hasNext()) {
            Object o = iter.next();

            if (o instanceof AccessExpression) {
                AccessExpression ae = (AccessExpression) o;
                DepthFirstIterator ae_iter = new DepthFirstIterator(ae);
                iter.pruneOn(ArrayAccess.class);

                // Catches array subscripts in the access expression.
                while (ae_iter.hasNext()) {
                    Object oo = ae_iter.next();
                    if (oo instanceof ArrayAccess) {
                        ArrayAccess aa = (ArrayAccess) oo;
                        Set<Expression> aa_use = getUseSet(aa);
                        aa_use.remove(aa);
                        ret.addAll(aa_use);
                    }
                }

                ret.add(ae);
            } else if (o instanceof ArrayAccess) {
                ArrayAccess aa = (ArrayAccess) o;

                for (int i = 0; i < aa.getNumIndices(); ++i) {
                    ret.addAll(getUseSet(aa.getIndex(i)));
                }

                ret.add(aa);
            } else if (o instanceof AssignmentExpression) {
                AssignmentExpression ae = (AssignmentExpression) o;
                ret.addAll(getUseSet(ae.getRHS()));
                Set<Expression> lhs_use = getUseSet(ae.getLHS());

                // Other cases should include the lhs in the used set. (+=,...)
                if (ae.getOperator() == AssignmentOperator.NORMAL) {
                    lhs_use.remove(ae.getLHS());
                }

                ret.addAll(lhs_use);
            } else if (o instanceof Identifier) {
                Identifier id = (Identifier) o;

                if (id.getSymbol() instanceof Procedure
                        || id.getSymbol() instanceof ProcedureDeclarator); else {
                    ret.add(id);
                }
            }
        }

        return ret;
    }

    private static void add2Map(Map<Expression, Set<Integer>> map, Expression expr) {
        if (map.containsKey(expr)) {
            Set<Integer> set = map.get(expr);
            set.add(new Integer(System.identityHashCode(expr)));
        } else {
            Set<Integer> set = new HashSet<Integer>();
            set.add(new Integer(System.identityHashCode(expr)));
            map.put(expr, set);
        }
    }

    /**
     * add contents of new_map to orig_map
     */
    public static void mergeSymbolMaps(Map<Symbol, Set<Integer>> orig_map, Map<Symbol, Set<Integer>> new_map) {
        for (Symbol new_sym : new_map.keySet()) {
            if (orig_map.containsKey(new_sym)) {
                Set<Integer> set = orig_map.get(new_sym);
                set.addAll(new_map.get(new_sym));
            } else {
                Set<Integer> set = new HashSet<Integer>();
                set.addAll(new_map.get(new_sym));
                orig_map.put(new_sym, set);
            }
        }
    }

    /**
     * add contents of new_map to orig_map
     */
    public static void mergeMaps(Map<Expression, Set<Integer>> orig_map, Map<Expression, Set<Integer>> new_map) {
        for (Expression new_expr : new_map.keySet()) {
            if (orig_map.containsKey(new_expr)) {
                Set<Integer> set = orig_map.get(new_expr);
                set.addAll(new_map.get(new_expr));
            } else {
                Set<Integer> set = new HashSet<Integer>();
                set.addAll(new_map.get(new_expr));
                orig_map.put(new_expr, set);
            }
        }
    }

    public static Map<Symbol, Set<Integer>> convertExprMap2SymbolMap(Map<Expression, Set<Integer>> imap) {
        Map<Symbol, Set<Integer>> omap = new HashMap<Symbol, Set<Integer>>();
        for (Expression expr : imap.keySet()) {
            Set<Integer> iset = imap.get(expr);
            Symbol sym = Tools.getSymbolOf(expr);
            if (omap.containsKey(sym)) {
                Set<Integer> orig_set = omap.get(sym);
                orig_set.addAll(iset);
            } else {
                Set<Integer> oset = new HashSet<Integer>();
                oset.addAll(iset);
                omap.put(Tools.getSymbolOf(expr), oset);
            }
        }
        return omap;
    }

    public static Map<Symbol, Set<Integer>> getUseSymbolMap(Traversable t) {
        return convertExprMap2SymbolMap(getUseMap(t));
    }

    public static Map<Symbol, Set<Integer>> getDefSymbolMap(Traversable t) {
        return convertExprMap2SymbolMap(getDefMap(t));
    }

    /**
     * Returns a map from a variable to its section
     */
    public static Section.MAP getUseSectionMap(Expression e, RangeDomain rd, Set<Symbol> def_vars) {
        Section.MAP ret = new Section.MAP();

        Expression expr = rd.substituteForward(e);

        if (expr instanceof ArrayAccess) {
            ArrayAccess aa = (ArrayAccess) expr;

            //Symbol var = Tools.getSymbolOf(aa.getArrayName());

            Section new_section = new Section(aa);
            new_section.expandMay(rd, def_vars);
            ret.put(Tools.getSymbolOf(aa.getArrayName()), new_section);
        } else if (expr instanceof AccessExpression) {
            Set<Expression> use_set = Tools.getUseSet(expr);
            if (use_set.size() == 1) {
                AccessSymbol var = (AccessSymbol) Tools.getSymbolOf(expr);
                ret.put(var.get(0), new Section(-1));
            }
        } else {
            Symbol var = Tools.getSymbolOf(expr);
            // var == null means it is not variable type
            // e.g.) *a = 0;
            if (var != null) {
                ret.put(var, new Section(-1));
            } else {
                /////////////////////////////////////////////////////////
                // [Added by Seyong Lee]                               //
                // If forward-substituted expression, expr, is  not a  //
                // variable type, use original expression, e, instead. //
                /////////////////////////////////////////////////////////
                if (e instanceof ArrayAccess) {
                    ArrayAccess aa = (ArrayAccess) e;

                    //Symbol var2 = Tools.getSymbolOf(aa.getArrayName());

                    Section new_section = new Section(aa);
                    new_section.expandMay(rd, def_vars);
                    ret.put(Tools.getSymbolOf(aa.getArrayName()), new_section);
                } else if (e instanceof AccessExpression) {
                    Set<Expression> use_set = Tools.getUseSet(e);
                    if (use_set.size() == 1) {
                        AccessSymbol var2 = (AccessSymbol) Tools.getSymbolOf(e);
                        ret.put(var2.get(0), new Section(-1));
                    }
                } else {
                    Symbol var2 = Tools.getSymbolOf(e);
                    // var2 == null means it is not variable type
                    // e.g.) *a = 0;
                    if (var2 != null) {
                        ret.put(var2, new Section(-1));
                    }
                }

            }
        }

        ret.clean();	// cleans up empty Sections

        return ret;
    }

    /**
     * Returns a map from a variable to its section
     */
    public static Section.MAP getDefSectionMap(Expression e, RangeDomain rd, Set<Symbol> def_vars) {
        Section.MAP ret = new Section.MAP();

        Expression expr = rd.substituteForward(e);

        if (expr instanceof ArrayAccess) {
            ArrayAccess aa = (ArrayAccess) expr;

            //Symbol var = Tools.getSymbolOf(aa.getArrayName());

            Section new_section = new Section(aa);
            new_section.expandMay(rd, def_vars);
            ret.put(Tools.getSymbolOf(aa.getArrayName()), new_section);
        } else {
            Symbol var = Tools.getSymbolOf(expr);
            // var == null means it is not variable type
            // e.g.) *a = 0;
            if (var != null) {
                ret.put(var, new Section(-1));
            } else {
                /////////////////////////////////////////////////////////
                // [Added by Seyong Lee]                               //
                // If forward-substituted expression, expr, is  not a  //
                // variable type, use original expression, e, instead. //
                /////////////////////////////////////////////////////////
                if (e instanceof ArrayAccess) {
                    ArrayAccess aa = (ArrayAccess) e;

                    //Symbol var2 = Tools.getSymbolOf(aa.getArrayName());

                    Section new_section = new Section(aa);
                    new_section.expandMay(rd, def_vars);
                    ret.put(Tools.getSymbolOf(aa.getArrayName()), new_section);
                } else {
                    Symbol var2 = Tools.getSymbolOf(e);
                    // var2 == null means it is not variable type
                    // e.g.) *a = 0;
                    if (var2 != null) {
                        ret.put(var2, new Section(-1));
                    }
                }

            }
        }

        ret.clean();	// cleans up empty Sections

        return ret;
    }

    /**
     * Returns a set of used expressions with their unique hashcodes in the
     * traversable object.
     *
     * @param t the traversable object.
     * @return the set of used expressions.
     */
    public static Map<Expression, Set<Integer>> getUseMap(Traversable t) {
        Map<Expression, Set<Integer>> ret = new TreeMap<Expression, Set<Integer>>();

        DepthFirstIterator iter = new DepthFirstIterator(t);

        // Handle these expressions specially.
        iter.pruneOn(AccessExpression.class);
        iter.pruneOn(ArrayAccess.class);
        iter.pruneOn(AssignmentExpression.class);

        while (iter.hasNext()) {
            Object o = iter.next();

            if (o instanceof AccessExpression) {
                AccessExpression ae = (AccessExpression) o;
                DepthFirstIterator ae_iter = new DepthFirstIterator(ae);
                iter.pruneOn(ArrayAccess.class);

                // Catches array subscripts in the access expression.
                while (ae_iter.hasNext()) {
                    Object oo = ae_iter.next();
                    if (oo instanceof ArrayAccess) {
                        ArrayAccess aa = (ArrayAccess) oo;
                        Map<Expression, Set<Integer>> aa_use = getUseMap(aa);
                        aa_use.remove(aa);

                        mergeMaps(ret, aa_use);
                    }
                }
                add2Map(ret, ae);
            } else if (o instanceof ArrayAccess) {
                ArrayAccess aa = (ArrayAccess) o;

                for (int i = 0; i < aa.getNumIndices(); ++i) {
                    mergeMaps(ret, getUseMap(aa.getIndex(i)));
                }

                add2Map(ret, aa);
            } else if (o instanceof AssignmentExpression) {
                AssignmentExpression ae = (AssignmentExpression) o;

                mergeMaps(ret, getUseMap(ae.getRHS()));

                // lhs_use is {A[i], i} for both {A[i]=...;} and {A[i]+=...} cases
                Map<Expression, Set<Integer>> lhs_use = getUseMap(ae.getLHS());

                // Other cases should include the lhs in the used set. (+=,...)
                // now, lhs_use is {i} for both {A[i]=...;} and {A[i]+=...} cases
                if (ae.getOperator() == AssignmentOperator.NORMAL) {
                    lhs_use.remove(ae.getLHS());
                }

                mergeMaps(ret, lhs_use);
            } else if (o instanceof Identifier) {
                Identifier id = (Identifier) o;

                if (id.getSymbol() instanceof Procedure
                        || id.getSymbol() instanceof ProcedureDeclarator); else {
                    add2Map(ret, id);
                }
            }
        }

        return ret;
    }

    public static void displayMap(Map<Expression, Set<Integer>> imap, String name) {
        int key_cnt = 0;
        for (Expression expr : imap.keySet()) {
            System.out.print(name + ++key_cnt + " : " + expr.toString() + " = {");
            int val_cnt = 0;
            for (Integer hashcode : imap.get(expr)) {
                if (val_cnt++ == 0) {
                    System.out.print(hashcode.toString());
                } else {
                    System.out.print(", " + hashcode.toString());
                }
            }
            System.out.println("}");
        }
    }

    /**
     * Returns a set of used expressions in the traversable object.
     *
     * @param t the traversable object.
     * @return the set of used expressions.
     */
    public static Set<Expression> getFlatUseSet(Traversable t) {
        TreeSet<Expression> ret = new TreeSet<Expression>();

        FlatIterator iter = new FlatIterator(t);

        // Handle these expressions specially.
/*
        iter.pruneOn(AccessExpression.class);
        iter.pruneOn(ArrayAccess.class);
        iter.pruneOn(AssignmentExpression.class);
         */

        while (iter.hasNext()) {
            Object o = iter.next();

            if (o instanceof AccessExpression) {
                AccessExpression ae = (AccessExpression) o;
                DepthFirstIterator ae_iter = new DepthFirstIterator(ae);
                /*
                iter.pruneOn(ArrayAccess.class);
                 */

                // Catches array subscripts in the access expression.
                while (ae_iter.hasNext()) {
                    Object oo = ae_iter.next();
                    if (oo instanceof ArrayAccess) {
                        ArrayAccess aa = (ArrayAccess) oo;
                        Set<Expression> aa_use = getUseSet(aa);
                        aa_use.remove(aa);
                        ret.addAll(aa_use);
                    }
                }

                ret.add(ae);
            } else if (o instanceof ArrayAccess) {
                ArrayAccess aa = (ArrayAccess) o;

                for (int i = 0; i < aa.getNumIndices(); ++i) {
                    ret.addAll(getUseSet(aa.getIndex(i)));
                }

                ret.add(aa);
            } else if (o instanceof AssignmentExpression) {
                AssignmentExpression ae = (AssignmentExpression) o;
                ret.addAll(getUseSet(ae.getRHS()));
                Set<Expression> lhs_use = getUseSet(ae.getLHS());

                // Other cases should include the lhs in the used set. (+=,...)
                if (ae.getOperator() == AssignmentOperator.NORMAL) {
                    lhs_use.remove(ae.getLHS());
                }

                ret.addAll(lhs_use);
            } else if (o instanceof Identifier) {
                Identifier id = (Identifier) o;

                if (id.getSymbol() instanceof Procedure
                        || id.getSymbol() instanceof ProcedureDeclarator); else {
                    ret.add(id);
                }
            }
        }

        return ret;
    }

    /**
     * Returns a set of defined expressions in the traversable object.
     *
     * @param t the traversable object.
     * @return the set of defined expressions.
     */
    public static Set<Expression> getDefSet(Traversable t) {
        Set<Expression> ret = new TreeSet<Expression>();

        if (t == null) {
            return ret;
        }


        DepthFirstIterator iter = new DepthFirstIterator(t);

        while (iter.hasNext()) {
            Object o = iter.next();

            // Expression being modified
            if (o instanceof AssignmentExpression) {
                ret.add(((AssignmentExpression) o).getLHS());
            } else if (o instanceof UnaryExpression) {
                UnaryExpression ue = (UnaryExpression) o;
                if (unary_def.contains(ue.getOperator().toString())) {
                    ret.add(ue.getExpression());
                }
            }
        }

        return ret;
    }

    /**
     * Returns a set of defined expressions in the traversable object.
     *
     * @param t the traversable object.
     * @return the set of defined expressions.
     */
    public static Map<Expression, Set<Integer>> getDefMap(Traversable t) {
        TreeMap<Expression, Set<Integer>> ret = new TreeMap<Expression, Set<Integer>>();

        if (t == null) {
            return ret;
        }

        DepthFirstIterator iter = new DepthFirstIterator(t);

        while (iter.hasNext()) {
            Object o = iter.next();

            // Expression being modified
            if (o instanceof AssignmentExpression) {
                Expression expr = ((AssignmentExpression) o).getLHS();
                add2Map(ret, expr);
            } else if (o instanceof UnaryExpression) {
                UnaryExpression ue = (UnaryExpression) o;
                if (unary_def.contains(ue.getOperator().toString())) {
                    Expression expr = ue.getExpression();
                    add2Map(ret, expr);
                }
            }
        }

        return ret;
    }

    /**
     * Returns a set of defined Section expressions in the traversable object.
     *
     * @param t the traversable object.
     * @param range_map the range map of the procedure that contains t
     * @return the set of defined expressions.
     */
    public static Section.MAP getDefSectionMap(Traversable t, Map<Statement, RangeDomain> range_map, RangeDomain unioned_rd, Set<Symbol> def_vars) {
        Section.MAP map = new Section.MAP();


        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            Expression def_expr = null;
            if (o instanceof AssignmentExpression) {
                def_expr = ((AssignmentExpression) o).getLHS();
            } else if (o instanceof UnaryExpression) {
                UnaryExpression ue = (UnaryExpression) o;
                if (unary_def.contains(ue.getOperator().toString())) {
                    def_expr = ue.getExpression();
                }
            }

            if (def_expr != null) {
                if (def_expr instanceof ArrayAccess) // A[i][j], p->q[k], etc...
                {
                    ArrayAccess aa_expr = (ArrayAccess) def_expr;
                    Symbol aa_symbol = Tools.getSymbolOf(aa_expr);
                    Section new_section = new Section(aa_expr);
                    Statement stmt = aa_expr.getStatement();
                    RangeDomain rd = range_map.get(stmt);
                    // expand symbolic varaibles in subscript expression specified in def_vars
                    new_section.expandMay(rd, def_vars);

                    // if section_map already contains a (aa_symbol, Section) pair
                    if (map.keySet().contains(aa_symbol)) {
                        Section old_section = map.get(aa_symbol);
                        if (old_section.getDimension() != aa_expr.getNumIndices()) {
                            Tools.exit("ERROR: array re-shaping is not supported:" + aa_expr.toString());
                        } else {
                            Tools.println("old_section before merge: " + old_section.toString(), 4);
                            Tools.println("new_section before merge: " + new_section.toString(), 4);
                            // merge two Sections, the previous and the current, to find out
                            // the maximum range of access ranges for a given ArrayAccess
                            new_section = new_section.unionWith(old_section, unioned_rd);
                            Tools.println("old_section after merge: " + old_section.toString(), 4);
                            Tools.println("new_section after merge: " + new_section.toString(), 4);
                            map.remove(aa_symbol);							// remove old_section
                            map.put(aa_symbol, new_section);		// insert new_section
                        }
                    } else {
                        map.put(aa_symbol, new_section);		// insert new_section
                        Tools.println("Section inserted: " + new_section.toString(), 3);
                    }
                } else {
                    Symbol scalar_symbol = Tools.getSymbolOf(def_expr);
                    map.put(scalar_symbol, new Section(-1));
                }
            }
        }

        return map;
    }

    /**
     * Returns a set of defined expressions in the traversable object.
     *
     * @param t the traversable object.
     * @return the set of defined expressions.
     */
    public static Set<Expression> getFlatDefSet(Traversable t) {
        Set<Expression> ret = new TreeSet<Expression>();

        if (t == null) {
            return ret;
        }

        FlatIterator iter = new FlatIterator(t);

        while (iter.hasNext()) {
            Object o = iter.next();

            // Expression being modified
            if (o instanceof AssignmentExpression) {
                ret.add(((AssignmentExpression) o).getLHS());
            } else if (o instanceof UnaryExpression) {
                UnaryExpression ue = (UnaryExpression) o;
                if (unary_def.contains(ue.getOperator().toString())) {
                    ret.add(ue.getExpression());
                }
            }
        }

        return ret;
    }

    /**
     * Returns a list of specifiers of the expression.
     */
    public static LinkedList<Specifier> getVariableType(Expression e) {
        LinkedList<Specifier> ret = new LinkedList<Specifier>();
        if (e instanceof Identifier) {
            Symbol var = ((Identifier) e).getSymbol();
            if (var != null) {
                ret.addAll(var.getTypeSpecifiers());
            }
        } else if (e instanceof ArrayAccess) {
            ArrayAccess aa = (ArrayAccess) e;
            ret = getVariableType(aa.getArrayName());
            for (int i = 0; i < aa.getNumIndices(); ++i) {
                if (ret.getLast() instanceof PointerSpecifier) {
                    ret.removeLast();
                }
            }
        } else if (e instanceof AccessExpression) {
            Symbol var = ((AccessExpression) e).getSymbol();
            if (var != null) {
                ret.addAll(var.getTypeSpecifiers());
            }
        } else if (e instanceof UnaryExpression) {
            UnaryExpression ue = (UnaryExpression) e;
            if (ue.getOperator() == UnaryOperator.DEREFERENCE) {
                ret = getVariableType(ue.getExpression());
                if (ret.getLast() instanceof PointerSpecifier) {
                    ret.removeLast();
                } else {
                    ret.clear();
                }
            }
        }
        return ret;
    }

    /**
     * Returns a list of specifiers of the given expression.
     *
     * @param e the given expression.
     * @return the list of specifiers.
     */
    public static List<Specifier> getExpressionType(Expression e) {
        if (e instanceof Identifier) {
            Symbol var = ((Identifier) e).getSymbol();
            if (var != null) {
                return var.getTypeSpecifiers();
            }
        } else if (e instanceof ArrayAccess) {
            ArrayAccess aa = (ArrayAccess) e;
            List<Specifier> ret = getExpressionType(aa.getArrayName());
            if (ret != null) {
                LinkedList<Specifier> ret0 = new LinkedList<Specifier>(ret);
                for (int i = 0; i < aa.getNumIndices(); ++i) {
                    if (ret0.getLast() instanceof PointerSpecifier) {
                        ret0.removeLast();
                    }
                }
                return ret0;
            }
            return ret;
        } else if (e instanceof AccessExpression) {
            Symbol var = ((AccessExpression) e).getSymbol();
            if (var != null) {
                return var.getTypeSpecifiers();
            }
        } else if (e instanceof AssignmentExpression) {
            return getExpressionType(((AssignmentExpression) e).getLHS());
        } else if (e instanceof CommaExpression) {
            List<Traversable> children = e.getChildren();
            return getExpressionType((Expression) children.get(children.size() - 1));
        } else if (e instanceof ConditionalExpression) {
            return getExpressionType(((ConditionalExpression) e).getTrueExpression());
        } else if (e instanceof FunctionCall) {
            Expression fc_name = ((FunctionCall) e).getName();
            if (fc_name instanceof Identifier) {
                Symbol fc_var = ((Identifier) fc_name).getSymbol();
                if (fc_var != null) {
                    return fc_var.getTypeSpecifiers();
                }
            }
        } else if (e instanceof IntegerLiteral) {
            return new LinkedList<Specifier>(Arrays.asList(Specifier.LONG));
        } else if (e instanceof BooleanLiteral) {
            return new LinkedList<Specifier>(Arrays.asList(Specifier.BOOL));
        } else if (e instanceof CharLiteral) {
            return new LinkedList<Specifier>(Arrays.asList(Specifier.CHAR));
        } else if (e instanceof StringLiteral) {
            return new LinkedList<Specifier>(Arrays.asList(
                    Specifier.CHAR,
                    PointerSpecifier.UNQUALIFIED));
        } else if (e instanceof FloatLiteral) {
            return new LinkedList<Specifier>(Arrays.asList(Specifier.DOUBLE));
        } else if (e instanceof Typecast) {
            return ((Typecast) e).getSpecifiers();
        } else if (e instanceof UnaryExpression) {
            UnaryExpression ue = (UnaryExpression) e;
            UnaryOperator op = ue.getOperator();
            List<Specifier> ret = getExpressionType(ue.getExpression());
            if (ret != null) {
                LinkedList<Specifier> ret0 = new LinkedList<Specifier>(ret);
                if (op == UnaryOperator.ADDRESS_OF) {
                    ret0.addLast(PointerSpecifier.UNQUALIFIED);
                } else if (op == UnaryOperator.DEREFERENCE) {
                    ret0.removeLast();
                }
                return ret0;
            }
            return ret;
        } else if (e instanceof BinaryExpression) {
            Set<String> logical_op =
                    new HashSet<String>(Arrays.asList("==", ">=", ">", "<=", "<", "!=", "&&", "||"));
            BinaryExpression be = (BinaryExpression) e;
            BinaryOperator op = be.getOperator();
            if (logical_op.contains(op.toString())) {
                return new LinkedList<Specifier>(Arrays.asList(Specifier.LONG));
            } else {
                return getExpressionType(be.getLHS());
            }
        } else if (e instanceof VaArgExpression) {
            return ((VaArgExpression) e).getSpecifiers();
        }
        printlnStatus("[WARNING] Unknown expression type: " + e, 0);
        return null;
    }

    /**
     * Returns the symbol of the expression if it represents an lvalue.
     *
     * @param e the input expression.
     * @return the corresponding symbol object.
     */
    /*
     * The following symbol is returned for each expression types.
     * Identifier         : its symbol.
     * ArrayAccess        : base name's symbol.
     * AccessExpression   : access symbol (list of symbols).
     * Pointer Dereference: the first symbol found in the expression tree.
     */
    public static Symbol getSymbolOf(Expression e) {
        if (e instanceof Identifier) {
            return ((Identifier) e).getSymbol();
        } else if (e instanceof ArrayAccess) {
            return getSymbolOf(((ArrayAccess) e).getArrayName());
        } else if (e instanceof AccessExpression) {
            return ((AccessExpression) e).getSymbol();
        } else if (e instanceof UnaryExpression) {
            UnaryExpression ue = (UnaryExpression) e;
            if (ue.getOperator() == UnaryOperator.DEREFERENCE) {
                DepthFirstIterator iter = new DepthFirstIterator(ue.getExpression());
                while (iter.hasNext()) {
                    Object o = iter.next();
                    if (o instanceof Identifier) {
                        return ((Identifier) o).getSymbol();
                    }
                }
            }
        }
        return null;
    }

    /**
     * Returns a set of defined symbols from the traversable object.
     *
     * @param t the traversable object.
     * @return the set of defined symbols.
     */
    public static Set<Symbol> getDefSymbol(Traversable t) {
        Set<Symbol> ret = new HashSet<Symbol>();

        for (Expression e : getDefSet(t)) {
            Symbol symbol = getSymbolOf(e);
            if (symbol != null) {
                ret.add(symbol);
            }
        }

        return ret;
    }

    /**
     * Returns a set of defined symbols from the traversable object.
     *
     * @param t the traversable object.
     * @return the set of defined symbols.
     */
    public static Set<Symbol> getFlatDefSymbol(Traversable t) {
        Set<Symbol> ret = new HashSet<Symbol>();

        for (Expression e : getFlatDefSet(t)) {
            Symbol symbol = getSymbolOf(e);
            if (symbol != null) {
                ret.add(symbol);
            }
        }

        return ret;
    }

    /**
     * Returns a set of used symbols from the traversable object.
     *
     * @param t the traversable object.
     * @return the set of used symbols.
     */
    public static Set<Symbol> getUseSymbol(Traversable t) {
        Set<Symbol> ret = new HashSet<Symbol>();

        for (Expression e : getUseSet(t)) {
            Symbol symbol = getSymbolOf(e);
            if (symbol != null) {
                ret.add(symbol);
            }
        }

        return ret;
    }

    /**
     * Returns a set of used symbols from the traversable object.
     *
     * @param t the traversable object.
     * @return the set of used symbols.
     */
    public static Set<Symbol> getFlatUseSymbol(Traversable t) {
        Set<Symbol> ret = new HashSet<Symbol>();

        for (Expression e : getFlatUseSet(t)) {
            Symbol symbol = getSymbolOf(e);
            if (symbol != null) {
                ret.add(symbol);
            }
        }

        return ret;
    }

    /**
     * Replaces all occurrences of the specified variable with the given
     * expression expr in the input expression e. If the traversable object is the
     * specified variable it returns a copy of the expression.
     * @param e the given expression.
     * @param var the variable to be replaced.
     * @param expr the expression to be substituted.
     * @return the modified expression clone.
     */
    public static Expression replaceSymbol(Expression e, Symbol var, Expression expr) {
        if (var.getSymbolName().equals(e.toString())) {
            return (Expression) expr.clone();
        }

        Expression ret = (Expression) e.clone();

        DepthFirstIterator iter = new DepthFirstIterator(ret);
        while (iter.hasNext()) {
            Object o = iter.next();
            if ((o instanceof Identifier) && ((Identifier) o).getSymbol() == var) {
                ((Expression) o).swapWith((Expression) expr.clone());
            }
        }
        return ret;
    }

    /**
     * Replaces all occurrences of the specified variable with the given
     * expression in the traversable object in place.
     * @param t the traversable object to be modified.
     * @param var the variable to be replaced.
     * @param e the expression to be substituted.
     */
    public static void replaceSymbolIn(Traversable t, Symbol var, Expression e) {
        if (t.getChildren() == null) {
            Tools.printlnStatus(
                    "[WARNING] no in-place replacement allowed in leaf nodes.", 0);
            return;
        }
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if ((o instanceof Identifier) && ((Identifier) o).getSymbol() == var) {
                ((Expression) o).swapWith((Expression) e.clone());
            }
        }
    }

    /**
     * Returns true if the traversable contains the specified symbol.
     * More accurate but slower than containsExpression.
     *
     * @param t    the traversable object being searched.
     * @param e    the expression object being searched for.
     */
    public static boolean containsExpr(Traversable t, Expression e) {
        if (t == null) {
            return false;
        }
        String e_str = e.toString();
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            if (iter.next().toString().equals(e_str)) {
                return true;
            }
        }
        return false;
    }

    public static boolean containsExprs(Traversable t, Collection<? extends Expression> es) {
        for (Expression e : es) {
            if (containsExpr(t, e)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Returns true if the traversable contains the specified symbol
     * @param t			traversable object being searched
     * @param var		symbol being searched for
     */
    public static boolean containsSymbol(Traversable t, Symbol var) {
        if (t == null) {
            return false;
        }

        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof Identifier && ((Identifier) o).getSymbol() == var) {
                return true;
            }
        }

        return false;
    }

    /**
     * Returns true if the traversable contains one of the symbols in the set.
     * @param t			traversable object being searched
     * @param vars	set of symbols being searched for
     */
    public static boolean containsSymbols(Traversable t, Set<Symbol> vars) {
        if (t == null) {
            return false;
        }
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof Identifier
                    && vars.contains(((Identifier) o).getSymbol())) {
                return true;
            }
        }
        return false;
    }

    public static boolean containsSymbols(Set<Symbol> vars, Set<Symbol> symbols) {
        for (Symbol symbol : symbols) {
            if (vars.contains(symbol)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Returns true if the traversable contains the specified type of object
     * @param t			the traversable object being searched
     * @param type 	the class being searched for
     */
    public static boolean containsClass(Traversable t, Class<?> type) {
        if (t == null) {
            return false;
        }
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            if (iter.next().getClass() == type) {
                return true;
            }
        }
        return false;
    }

    public static boolean containsClasses(Traversable t, Set<Class<?>> types) {
        if (t == null) {
            return false;
        }
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            if (types.contains(iter.next().getClass())) {
                return true;
            }
        }
        return false;
    }

    /**
     * Checks if the collection contains the specified type of object.
     *
     * @param c the collection being searched.
     * @param type the class being searched for.
     */
    public static boolean containsClass(Collection<?> c, Class<?> type) {
        if (c == null) {
            return false;
        }
        for (Object o : c) {
            if (o.getClass() == type) {
                return true;
            }
        }
        return false;
    }

    /**
     * Checks if the traversable object contains the specified type of binary
     * operations.
     *
     * @param t The traversable object being searched
     * @param op The binary operator being searched for
     * @return True if there is such an operation, False otherwise
     */
    public static boolean containsBinary(Traversable t, BinaryOperator op) {
        if (t == null) {
            return false;
        }
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof BinaryExpression
                    && ((BinaryExpression) o).getOperator() == op) {
                return true;
            }
        }
        return false;
    }

    /**
     * Checks if the traversable object contains the specified type of unary
     * operations.
     *
     * @param t The traversable object being searched
     * @param op The unary operator being searched for
     * @return True if there is such an operation, False otherwise
     */
    public static boolean containsUnary(Traversable t, UnaryOperator op) {
        if (t == null) {
            return false;
        }
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof UnaryExpression
                    && ((UnaryExpression) o).getOperator() == op) {
                return true;
            }
        }
        return false;
    }

    /**
     * Checks if the traversable object contains any IO-related function calls
     * declared in the stdio.h.
     */
    public static boolean containsIO(Traversable t) {
        if (t == null) {
            return false;
        }

        List<FunctionCall> fc_list = getFunctionCalls(t);
        Set<String> io = new HashSet<String>(Arrays.asList(
                "fopen", "freopen", "fflush", "fclose", "remove", "rename", "tmpfile", "tmpnam",
                "setvbuf", "setbuf", "fprintf", "printf", "sprintf", "vfprintf", "vprintf",
                "vsprintf", "fscanf", "scanf", "sscanf", "fgetc", "fgets", "fputc", "fputs",
                "getc", "getchar", "gets", "putc", "putchar", "puts", "unget", "fread", "fseek",
                "ftell", "rewind", "fgetpos", "fsetpos", "clearerr", "feof", "ferror", "perror",
                "fwrite"));

        for (FunctionCall fc : fc_list) {
            if (io.contains((fc.getName()).toString())) {
                return true;
            }
        }
        return false;
    }

    /**
     * Checks if the traversable object contains any function call declared
     * in the C standard library header stdlib.h
     */
    public static boolean isStdLibCall(FunctionCall fc) {
        Set<String> stdlib = new HashSet<String>(Arrays.asList(
                "atof", "atoi", "atol", "strtod", "strtol", "strtoul", "rand", "srand", "calloc",
                "malloc", "realloc", "free", "abort", "exit", "atexit", "system", "getenv",
                "bsearch", "qsort", "abs", "labs", "div", "ldiv", "abort", "mblen", "mbstowcs",
                "mbtowc", "wcstombs", "wctomb"));

        if (stdlib.contains((fc.getName()).toString())) {
            return true;
        }
        return false;
    }

    /**
     * Returns a list of unary expressions with the given unary operator.
     *
     * @param t the traversable object being searched.
     * @param op the unary operator being searched for.
     * @return the list of unary expressions.
     */
    public static List<UnaryExpression> getUnaryExpression(Traversable t, UnaryOperator op) {
        List<UnaryExpression> ret = new LinkedList<UnaryExpression>();
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof UnaryExpression
                    && ((UnaryExpression) o).getOperator() == op) {
                ret.add((UnaryExpression) o);
            }
        }
        return ret;
    }

    /**
     * Returns true if the traversable contains any side effects that change the
     * program state.
     *
     * @param t  The traversable object being searched
     * @return true if there is such a case, false otherwise.
     */
    public static boolean containsSideEffect(Traversable t) {
        if (t == null) {
            return false;
        }

        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof AssignmentExpression
                    || o instanceof FunctionCall
                    || o instanceof VaArgExpression
                    || o instanceof UnaryExpression
                    && unary_def.contains(((UnaryExpression) o).getOperator().toString())) {
                return true;
            }
        }
        return false;
    }

    /**
     * Returns the nearest ancestor object of the given traversable object
     * that has the specified type.
     * @param t the traversable object.
     * @param type the IR type being searched for.
     */
    public static Traversable getAncestorOfType(Traversable t, Class<?> type) {
        Traversable ret = t;
        while (ret != null && !type.isAssignableFrom(ret.getClass())) {
            ret = ret.getParent();
        }
        return ret;
    }

    /**
     * Returns a list of descendents with the specified type.
     * @param t the traversable object.
     * @param type the IR type to be searched for.
     */
    public static List<Traversable> getDescendentsOfType(Traversable t, Class<?> type) {
        List<Traversable> ret = new LinkedList<Traversable>();
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (type.isAssignableFrom(o.getClass())) {
                ret.add((Traversable) o);
            }
        }
        return ret;
    }

    /**
     * Checks if the specified traversable object "anc" is an ancestor of the
     * other traversable object "des" in the IR tree.
     */
    public static boolean isAncestorOf(Traversable anc, Traversable des) {
        return isDescendantOf(des, anc);
    }

    /**
     * Checks if the specified traversable object "des" is a descendant of the
     * other traversable object "des" in the IR tree.
     */
    public static boolean isDescendantOf(Traversable des, Traversable anc) {
        Traversable t = des;
        while (t != null && t != anc) {
            t = t.getParent();
        }
        return (des != anc && t == anc);
    }

    /**
     * Returns true if there is a FunctionCall within the traversable
     * @param t  traversable object being searched
     */
    public static boolean containsFunctionCall(Traversable t) {
        if (t == null) {
            return false;
        }

        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof FunctionCall) {
                return true;
            }
        }
        return false;
    }

    /**
     * Returns a set of FunctionCall statement within the traversable
     * @param t  traversable object being searched
     */
    public static List<FunctionCall> getFunctionCalls(Traversable t) {
        List<FunctionCall> fc_list = new LinkedList<FunctionCall>();

        if (t == null) {
            return null;
        }

        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof FunctionCall) {
                fc_list.add((FunctionCall) o);
            }
        }
        return fc_list;
    }

    /**
     * Checks if the symbol is a global variable to the procedure containing the
     * given traversable object.
     *
     * @param symbol The symbol object
     * @param t The traversable object
     * @return true if it is global, false otherwise
     */
    public static boolean isGlobal(Symbol symbol, Traversable t) {
        while (t != null && !(t instanceof Procedure)) {
            t = t.getParent();
        }

        if (t == null) {
            return true; // conservative decision if a bad thing happens.
        }
        List<SymbolTable> parent_symtabs = getParentTables(t);

        for (Object symtab : parent_symtabs) {
            Set<Symbol> symbols = getSymbols((SymbolTable) symtab);
            if (symbols.contains(symbol)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Checks if the symbol is a scalar variable.
     *
     * @param symbol The symbol
     * @return true if it is a scalar variable, false otherwise
     */
    public static boolean isScalar(Symbol symbol) {
        if (symbol == null) {
            return false;
        }

        List<Specifier> specs = symbol.getArraySpecifiers();

        return (specs == null || specs.isEmpty());
    }

    /**
     * Checks if the symbol is an array variable.
     *
     * @param symbol The symbol
     * @return true if it is an array variable, false otherwise
     */
    public static boolean isArray(Symbol symbol) {
        if (symbol == null) {
            return false;
        }

        List<Specifier> specs = symbol.getArraySpecifiers();

        return (specs != null && !specs.isEmpty());
    }

    /**
     * Checks if the symbol is a pointer type variable.
     *
     * @param symbol The symbol
     * @return true if it is a pointer type variable, false otherwise
     */
    public static boolean isPointer(Symbol symbol) {
        if (symbol == null) {
            return false;
        }

        List<Specifier> specs = symbol.getTypeSpecifiers();

        if (specs == null) {
            return false;
        }

        for (Object o : specs) {
            if (o instanceof PointerSpecifier) {
                return true;
            }
        }

        return false;
    }

    /**
     * Checks if the symbol is a pointer type variable. The input expression
     * should represent a variable. Otherwise it will return true.
     *
     * @param e the expression to be tested.
     */
    public static boolean isPointer(Expression e) {
        List<Specifier> spec = getExpressionType(e);
        if (spec == null || spec.isEmpty()
                || spec.get(spec.size() - 1) instanceof PointerSpecifier) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Checks if the symbol is an interger type variable.
     *
     * @param symbol the symbol.
     * @return true if it is an integer type variable, false otherwise.
     */
    public static boolean isInteger(Symbol symbol) {
        if (symbol == null) {
            return false;
        }

        Set<Specifier> include = new HashSet<Specifier>(Arrays.asList(
                Specifier.INT,
                Specifier.LONG,
                Specifier.SIGNED,
                Specifier.UNSIGNED));
        Set<Specifier> exclude = new HashSet<Specifier>(Arrays.asList(
                Specifier.CHAR,
                PointerSpecifier.UNQUALIFIED,
                PointerSpecifier.CONST,
                PointerSpecifier.VOLATILE,
                PointerSpecifier.CONST_VOLATILE));

        List<Specifier> specs = symbol.getTypeSpecifiers();

        if (specs == null) {
            return false;
        }

        boolean ret = false;
        for (Object o : specs) {
            if (exclude.contains(o)) {
                return false;
            }
            ret |= include.contains(o);
        }
        return ret;
    }

    /**
     * Returns a current system time in seconds since a system-wise reference
     * time.
     *
     * @return the time in seconds.
     */
    public static double getTime() {
        return (System.currentTimeMillis() / 1000.0);
    }

    /**
     * Returns the elapsed time in seconds since the given reference time.
     *
     * @param since the reference time
     * @return the elapsed time in seconds
     */
    public static double getTime(double since) {
        return (System.currentTimeMillis() / 1000.0 - since);
    }

    public static <T extends PragmaAnnotation> List<T> collectPragmas(Traversable t, Class<T> pragma_cls, String key) {
        List<T> ret = new LinkedList<T>();

        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof Annotatable) {
                Annotatable at = (Annotatable) o;
                List<T> pragmas = at.getAnnotations(pragma_cls);
                for (T pragma : pragmas) {
                    if (pragma.containsKey(key)) {
                        ret.add(pragma);
                    }
                }
            }
        }
        return ret;
    }

    /**
     * returns a list of the last Statements of the Procedure
     */
    public static List<Statement> getLastStatements(Procedure proc) {
        List<Statement> last_stmt_list = new LinkedList<Statement>();
        BreadthFirstIterator iter = new BreadthFirstIterator(proc);

        // Case I: find all ReturnStatements
        for (;;) {
            ReturnStatement stmt = null;
            try {
                stmt = iter.next(ReturnStatement.class);
                last_stmt_list.add(stmt);
            } catch (NoSuchElementException e) {
                break;
            }
        }

        // Case II: if no ReturnStatement is found, find the last Statement of the Procedure
        List<Traversable> children = proc.getBody().getChildren();

        if (children.size() == 0) {
            Tools.exit("ERROR: function [" + proc.getName() + "] is empty (needs at least one Statement)");
        }

        Statement last_stmt = (Statement) children.get(children.size() - 1);
        if (!last_stmt_list.contains(last_stmt)) {
            last_stmt_list.add(last_stmt);
        }

        return last_stmt_list;
    }

    /**
     * return a list of Procedures in a program
     */
    public static List<Procedure> getProcedureList(Program program) {
        DepthFirstIterator iter = new DepthFirstIterator(program);
        iter.pruneOn(Procedure.class);
        iter.pruneOn(Statement.class);
        iter.pruneOn(Declaration.class);

        LinkedList<Procedure> proc_list = new LinkedList<Procedure>();
        while (iter.hasNext()) {
            Object obj = iter.next();
            if (obj instanceof Procedure) {
                proc_list.add((Procedure) obj);
            }
        }
        return proc_list;
    }

    public static void exit(String str) {
        System.out.println(str);
        System.exit(0);
    }

    public static void removeAnnotations(Traversable t, Class<? extends Annotation> type) {
        DepthFirstIterator iter = new DepthFirstIterator(t);
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof Annotatable) {
                ((Annotatable) o).removeAnnotations(type);
            }
        }
    }

    /*
     * Get the block depth of the traversable object t in terms of
     * a provided class type
     */
    public static int getBlockLevel(Traversable t, Class c) {
        int level = 0;

        while (true) {
            if (t.getClass().equals(c)) {
                break;
            }
            t = t.getParent();
            if (t instanceof CompoundStatement) {
                level++;
            }
        }
        return level;
    }
}


