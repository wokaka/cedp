/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cetus.transforms;

import cetus.analysis.RangeDomain;
import cetus.hir.AccessExpression;
import cetus.hir.AccessLevel;
import cetus.hir.AlignofExpression;
import cetus.hir.AnnotationDeclaration;
import cetus.hir.AnnotationStatement;
import cetus.hir.ArrayAccess;
import cetus.hir.AssignmentExpression;
import cetus.hir.BinaryExpression;
import cetus.hir.BooleanLiteral;
import cetus.hir.BreakStatement;
import cetus.hir.Case;
import cetus.hir.CharLiteral;
import cetus.hir.ClassDeclaration;
import cetus.hir.CommaExpression;
import cetus.hir.CompoundStatement;
import cetus.hir.ConditionalExpression;
import cetus.hir.ConstructorInitializer;
import cetus.hir.ContinueStatement;
import cetus.hir.CudaAnnotation;
import cetus.hir.Declaration;
import cetus.hir.DeclarationStatement;
import cetus.hir.Declarator;
import cetus.hir.Default;
import cetus.hir.DeleteExpression;
import cetus.hir.DepthFirstIterator;
import cetus.hir.DestructorID;
import cetus.hir.DoLoop;
import cetus.hir.EscapeLiteral;
import cetus.hir.ExceptionHandler;
import cetus.hir.Expression;
import cetus.hir.ExpressionStatement;
import cetus.hir.FloatLiteral;
import cetus.hir.ForLoop;
import cetus.hir.FunctionCall;
import cetus.hir.GotoStatement;
import cetus.hir.IDExpression;
import cetus.hir.Identifier;
import cetus.hir.IfStatement;
import cetus.hir.InfExpression;
import cetus.hir.Initializer;
import cetus.hir.IntegerLiteral;
import cetus.hir.Label;
import cetus.hir.LinkageSpecification;
import cetus.hir.ListInitializer;
import cetus.hir.Literal;
import cetus.hir.MinMaxExpression;
import cetus.hir.Namespace;
import cetus.hir.NamespaceAlias;
import cetus.hir.NestedDeclarator;
import cetus.hir.NewExpression;
import cetus.hir.NullStatement;
import cetus.hir.OffsetofExpression;
import cetus.hir.OperatorID;
import cetus.hir.PreAnnotation;
import cetus.hir.Procedure;
import cetus.hir.ProcedureDeclarator;
import cetus.hir.Program;
import cetus.hir.QualifiedID;
import cetus.hir.RangeExpression;
import cetus.hir.ReturnStatement;
import cetus.hir.SizeofExpression;
import cetus.hir.Specifier;
import cetus.hir.Statement;
import cetus.hir.StatementExpression;
import cetus.hir.StringLiteral;
import cetus.hir.SwitchStatement;
import cetus.hir.SymbolTable;
import cetus.hir.TemplateDeclaration;
import cetus.hir.TemplateID;
import cetus.hir.ThrowExpression;
import cetus.hir.Tools;
import cetus.hir.TranslationUnit;
import cetus.hir.Traversable;
import cetus.hir.Typecast;
import cetus.hir.UnaryExpression;
import cetus.hir.UsingDeclaration;
import cetus.hir.UsingDirective;
import cetus.hir.VaArgExpression;
import cetus.hir.ValueInitializer;
import cetus.hir.VariableDeclaration;
import cetus.hir.VariableDeclarator;
import cetus.hir.WhileLoop;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;

/**
 *
 * @author yim6
 */
public class ErrorDetector1Pt extends TransformPass
{
    private static final String tag = "[ED] ";
    private Map<Statement, RangeDomain> range_map;

    public ErrorDetector1Pt(Program prog)
    {
        super(prog);
        //variable_map = new HashTable();
    }

    @Override
    public String getPassName() {
        return "ErrorDetector1Pt";
    }

    protected String GetType(Traversable e)
    {
        if(e instanceof AccessExpression)
            return "AccessExpression";
        else if(e instanceof AccessLevel)
            return "AccessLevel";
        else if(e instanceof AlignofExpression)
            return "AlignofExpression";
        else if(e instanceof AnnotationDeclaration)
            return "AnnotationDeclaration";
        else if(e instanceof AnnotationStatement)
            return "AnnotationStatement";
        else if(e instanceof ArrayAccess)
            return "ArrayAccess";
        else if(e instanceof AssignmentExpression)
            return "AssignmentExpression";
        else if(e instanceof BinaryExpression)
            return "BinaryExpression";
        else if(e instanceof BooleanLiteral)
            return "BooleanLiteral";
        else if(e instanceof BreakStatement)
            return "BreakStatement";
        else if(e instanceof Case)
            return "Case";
        else if(e instanceof CharLiteral)
            return "CharLiteral";
        else if(e instanceof ClassDeclaration)
            return "ClassDeclaration";
        else if(e instanceof CommaExpression)
            return "CommaExpression";
        else if(e instanceof CompoundStatement)
            return "CompoundStatement";
        else if(e instanceof ConditionalExpression)
            return "ConditionalExpression";
        else if(e instanceof ConstructorInitializer)
            return "ConstructorInitializer";
        else if(e instanceof ContinueStatement)
            return "ContinueStatement";
        else if(e instanceof Declaration)
            return "Declaration";
        else if(e instanceof DeclarationStatement)
            return "DeclarationStatement";
        else if(e instanceof Declarator)
            return "Declarator";
        else if(e instanceof Default)
            return "Default";
        else if(e instanceof DeleteExpression)
            return "DeleteExpression";
        else if(e instanceof DestructorID)
            return "DestructorID";
        else if(e instanceof DoLoop)
            return "DoLoop";
        else if(e instanceof Enumeration)
            return "Enumeration";
        else if(e instanceof EscapeLiteral)
            return "EscapeLiteral";
        else if(e instanceof ExceptionHandler)
            return "ExceptionHandler";
        else if(e instanceof Expression)
            return "Expression";
        else if(e instanceof ExpressionStatement)
            return "ExpressionStatement";
        else if(e instanceof FloatLiteral)
            return "FloatLiteral";
        else if(e instanceof ForLoop)
            return "ForLoop";
        else if(e instanceof FunctionCall)
            return "FunctionCall";
        else if(e instanceof GotoStatement)
            return "GotoStatement";
        else if(e instanceof Identifier)
            return "Identifier";
        else if(e instanceof IDExpression)
            return "IDExpression";
        else if(e instanceof IfStatement)
            return "IfStatement";
        else if(e instanceof InfExpression)
            return "InfExpression";
        else if(e instanceof Initializer)
            return "Initializer";
        else if(e instanceof IntegerLiteral)
            return "IntegerLiteral";
        else if(e instanceof Label)
            return "Label";
        else if(e instanceof LinkageSpecification)
            return "LinkageSpecification";
        else if(e instanceof ListInitializer)
            return "ListInitializer";
        else if(e instanceof Literal)
            return "Literal";
        else if(e instanceof MinMaxExpression)
            return "MinMaxExpression";
        else if(e instanceof Namespace)
            return "Namespace";
        else if(e instanceof NamespaceAlias)
            return "NamespaceAlias";
        else if(e instanceof NestedDeclarator)
            return "NestedDeclarator";
        else if(e instanceof NewExpression)
            return "NewExpression";
        else if(e instanceof NullStatement)
            return "NullStatement";
        else if(e instanceof OffsetofExpression)
            return "OffsetofExpression";
        else if(e instanceof OperatorID)
            return "OperatorID";
        else if(e instanceof PreAnnotation)
            return "PreAnnotation";
        else if(e instanceof Procedure)
            return "Procedure";
        else if(e instanceof ProcedureDeclarator)
            return "ProcedureDeclarator";
        else if(e instanceof Program)
            return "Program";
        else if(e instanceof QualifiedID)
            return "QualifiedID";
        else if(e instanceof RangeExpression)
            return "RangeExpression";
        else if(e instanceof ReturnStatement)
            return "ReturnStatement";
        else if(e instanceof SizeofExpression)
            return "SizeofExpression";
        else if(e instanceof Statement)
            return "Statement";
        else if(e instanceof StatementExpression)
            return "StatementExpression";
        else if(e instanceof StringLiteral)
            return "StringLiteral";
        else if(e instanceof SwitchStatement)
            return "SwitchStatement";
        else if(e instanceof TemplateDeclaration)
            return "TemplateDeclaration";
        else if(e instanceof TemplateID)
            return "TemplateID";
        else if(e instanceof ThrowExpression)
            return "ThrowExpression";
        else if(e instanceof TranslationUnit)
            return "TranslationUnit";
        else if(e instanceof Typecast)
            return "Typecast";
        else if(e instanceof UnaryExpression)
            return "UnaryExpression";
        else if(e instanceof UsingDeclaration)
            return "UsingDeclaration";
        else if(e instanceof UsingDirective)
            return "UsingDirective";
        else if(e instanceof VaArgExpression)
            return "VaArgExpression";
        else if(e instanceof ValueInitializer)
            return "ValueInitializer";
        else if(e instanceof VariableDeclaration)
            return "VariableDeclaration";
        else if(e instanceof VariableDeclarator)
            return "VariableDeclarator";
        else if(e instanceof WhileLoop)
            return "WhileLoop";
        else
            return "Unknown";

    }

    Hashtable variable_map;
    int variable_id = 0;
    
    private int GetNextVariableID() {
        return variable_id++;
    }

    private int GetVariableID(Declaration dclr)
    {
        Object o = variable_map.get(dclr);
        Integer it;
        if (o == null) {
            it = new Integer(GetNextVariableID());
            variable_map.put(dclr, it);
        } else {
            it = (Integer) o;
        }

        return it.intValue();
    }


    TranslationUnit main_tu;
    Procedure main_proc;
    ArrayList<Procedure> proc_list;

    protected ArrayList<Procedure> global_proc;
    protected ArrayList<Procedure> local_proc;

    protected void ScanProcedure()
    {
        DepthFirstIterator iter = new DepthFirstIterator(program);
        proc_list = new ArrayList<Procedure>();
        TranslationUnit tu = null;
        while (iter.hasNext()) {
            Object o = iter.next();
            if (o instanceof TranslationUnit) {
                tu = (TranslationUnit) o;
            } else if (o instanceof Procedure) {
                Procedure proc = (Procedure) o;
                if (proc.getSymbolName().equals("main")) {
                    main_tu = tu;
                    main_proc = proc;
                }

                proc_list.add(proc);
            }
        }
        if (main_tu == null) {
            main_tu = tu;
        }

        // Collecting global procedures
        global_proc = new ArrayList<Procedure>();
        local_proc = new ArrayList<Procedure>();

        for (int i = 0; i < proc_list.size(); i++) {
            Procedure proc = proc_list.get(i);
            List<Specifier> spec_list = proc.getTypeSpecifiers();
            for (int j = 0; j < spec_list.size(); j++) {
                if (spec_list.get(j) == Specifier.GLOBAL) {
                    global_proc.add(proc);
                    local_proc.add(proc);
                    break;
                }
                if(spec_list.get(j) == Specifier.DEVICE) {
                    local_proc.add(proc);
                    break;
                }
            }
        }
    }
    
    @Override
    public void start() {
        ScanProcedure();

        InstrPointers();
    }

    protected void GetAllIDs(Expression e, ArrayList<IDExpression> list)
    {
        int i;
        List<Traversable> child = e.getChildren();
        
        for(i=0; i<child.size(); i++){
            if(child.get(i) instanceof IDExpression){
                System.out.println("Add " + ((IDExpression)child.get(i)).toString());
                list.add((IDExpression)child.get(i));
            }
            else if(child.get(i) instanceof Expression){
                GetAllIDs((Expression)child.get(i), list);
            }
        }
    }

    protected Statement GetStatement(Traversable o)
    {
        Traversable pt = o;

        while(pt != null){
            if(pt instanceof Statement)
                return (Statement)pt;
            pt = pt.getParent();
        };

        return null;
    }

    protected void Check(Statement s, String id)
    {
        s.annotateBefore(new CudaAnnotation("// [ED]\nif(" + id + " != " + id + "_dup)\nGPUFI_EXIT(0);\n"));
        System.out.println("    check: " + id);
    }

    protected boolean Duplicate(VariableDeclaration d, String id)
    {
        String instr = d.toString();
        int i;

        List<Traversable> e = d.getChildren();

        for(i=0; i<e.size(); i++){
            Declarator dd = (Declarator)e.get(i);
            
            String idx = dd.getSymbolName();
            System.out.println("- " + idx + " =? " + id);
            if(idx.equals(id)){
                System.out.println("- instr: " + instr);
                instr = instr.replaceFirst(id, id + "_dup");
                System.out.println("- instr: " + instr);

                    System.out.println("    duplicate: " + id);
                    d.annotateAfter(new CudaAnnotation("// [ED]\n" + instr + ";\n"));
                    return true;
            }
        }
        return false;
    }

    protected void ErrorDetector(Statement s, VariableDeclaration var, String id)
    {
        if(s != null && var != null){
            if(Duplicate(var, id))
                Check(s, id);
        }
    }
    
    protected void InstrPointers()
    {
        int i, j;
        ArrayList<Declaration> d_list, p_list;
        
        /* For each GPU global functions */
        for (i = 0; i < local_proc.size(); i++) {
            Procedure proc = local_proc.get(i);
            
            DepthFirstIterator kern_iter = new DepthFirstIterator(proc.getBody());
            d_list = new ArrayList<Declaration>();
            
            // Collect declaration data structures of variable declaration statements
            while (kern_iter.hasNext()) {
                Object o = kern_iter.next();
                Expression expr;
                expr = null;
                
                if (o instanceof Identifier) {
                    Identifier var = (Identifier)o;
                    
                    if(var instanceof IDExpression){
            
                        Traversable t = (Traversable)var;
                        
                        while (t != null && !(t instanceof SymbolTable))
                            t = t.getParent();

                        if(t!=null){
                            Declaration d = Tools.findSymbol((SymbolTable)t, var);
                            if(d != null){
                                
                                VariableDeclaration vd = (VariableDeclaration) d;
                                if(vd.isPointer()){
                                    System.out.println("var: " + var.toString() + ", " + var.getParent().toString());
                                    System.out.println("    declaration: " + d.toString());
                                    System.out.println("    pointer");
                                    ErrorDetector(GetStatement((Traversable)o), vd, var.toString());
                                }
                            }
                        }
                    }
                }

/*
                if(expr != null){
                    ArrayList<IDExpression> idexpr_list = new ArrayList<IDExpression>();
                    GetAllIDs(expr, idexpr_list);
                    for(j=0; j<idexpr_list.size(); j++){
                        IDExpression id = idexpr_list.get(j);

                        //Traversable t = (Traversable)proc;
                        Traversable t = (Traversable)id;
                        while (t != null && !(t instanceof SymbolTable))
                            t = t.getParent();
                        if(t!=null){
                            //System.out.println("SymbolTable " + t.toString());
                            Declaration d = Tools.findSymbol((SymbolTable)t, id);
                            if(d != null){
                                d_list.add(d);
                                ((Statement)o).annotateBefore(new CudaAnnotation(AnnoCheck(d)));
                            }
                        }
                    }
                }
 */
            }

            /* Annoate the found decarations */
            kern_iter = new DepthFirstIterator(proc.getBody());

            p_list = new ArrayList<Declaration>();
            for(j=0; j<d_list.size(); j++)
                p_list.add(d_list.get(j));
            
            while (kern_iter.hasNext()) {
                Object o = kern_iter.next();
                if(o instanceof DeclarationStatement){
                    DeclarationStatement expr = (DeclarationStatement) o;
                    Declaration e = expr.getDeclaration();
                    for(int k=0; k<d_list.size(); k++){
                        if(e == ((Declaration)d_list.get(k))){ /* Duplicate */
                            p_list.remove(e);
                           // expr.annotateAfter(new CudaAnnotation(AnnoDuplicate(e)));
                        }
                    }
                }
            }

            /* Annotate parameters */
            Statement first_stat = GetFirstStat(proc);
            for(j=0; j<p_list.size(); j++){
                first_stat.annotateBefore(new CudaAnnotation(AnnoDuplicateParam(p_list.get(j))));
            }
        }
    }

    protected Statement GetFirstStat(Procedure p)
    {
        DepthFirstIterator iter = new DepthFirstIterator(p.getBody());

        while (iter.hasNext()) {
            Object o = iter.next();
            if (o == p.getBody() || !(o instanceof Statement)) {
                continue;
            }

            return (Statement) o;
        }

        return null;
    }
    

    protected String AnnoDuplicateParam(Declaration d)
    {
        String instr = d.toString();
        int i;

        List<IDExpression> id = d.getDeclaredSymbols();

        List<Traversable> e = d.getChildren();
        if(e != null && e.get(0) instanceof Declarator){
            Declarator dd = (Declarator) e.get(0);
            System.out.println("SymbolParam: " + dd.getSymbolName());

            instr += "_dup = " + dd.getSymbolName();
        }

        return "// [ED]\n" + instr + ";\n";
    }
}
