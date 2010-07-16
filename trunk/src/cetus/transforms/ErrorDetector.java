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
import cetus.hir.Loop;
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
public class ErrorDetector extends TransformPass
{
    private static final String tag = "[ED] ";
    private Map<Statement, RangeDomain> range_map;

    public ErrorDetector(Program prog)
    {
        super(prog);
        //variable_map = new HashTable();
    }

    @Override
    public String getPassName() {
        return "ErrorDetector";
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

        InstrCtrlFlow();
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

    protected void InstrCtrlFlow()
    {
        int i, j;
        ArrayList<Declaration> d_list, p_list;
                
        /* For each GPU global functions */
        for (i = 0; i < global_proc.size(); i++) {
            Procedure proc = global_proc.get(i);

            DepthFirstIterator kern_iter = new DepthFirstIterator(proc.getBody());
            d_list = new ArrayList<Declaration>();
            
            // Collect declaration data structures of variable declaration statements
            while (kern_iter.hasNext()) {
                Object o = kern_iter.next();
                Expression expr;
                expr = null;
                
                if (o instanceof IfStatement) {
                    IfStatement stat = (IfStatement) o;
                    System.out.println("[If]");
                    expr = stat.getControlExpression();
                }
                else if (o instanceof Case) {
                    Case stat = (Case) o;
                    System.out.println("[Case]");
                    expr = stat.getExpression();
                }
                else if (o instanceof Loop) {
                    Loop stat = (Loop) o;
                    System.out.println("[Loop]");
                    expr = stat.getCondition();
                }

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
//                                System.out.println("Annotated " + "/* [ED] " + d.toString() + "; */");
                                ((Statement)o).annotateBefore(new CudaAnnotation(AnnoCheck(d)));
                            }
                        }
                    }
                }
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
                            expr.annotateAfter(new CudaAnnotation(AnnoDuplicate(e)));
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
    
    protected String AnnoCheck(Declaration d)
    {
        String instr = null;

        List<IDExpression> id = d.getDeclaredSymbols();

        List<Traversable> e = d.getChildren();
        if(e != null && e.get(0) instanceof Declarator){
            Declarator dd = (Declarator) e.get(0);
//            System.out.println("Symbol: " + dd.getSymbolName());
            instr = dd.getSymbolName();
        }

        if(instr == null)
            return "// [ED] Error";
        
        return "// [ED]\nif(" + instr + " != " + instr + "_dup)\nGPUFI_EXIT(0);\n";
    }

    protected String AnnoDuplicate(Declaration d)
    {
        String instr = d.toString();
        int i;
        
        List<IDExpression> id = d.getDeclaredSymbols();

        List<Traversable> e = d.getChildren();
        if(e != null && e.get(0) instanceof Declarator){
            Declarator dd = (Declarator) e.get(0);
            System.out.println("Symbol: " + dd.getSymbolName());

            instr = instr.replaceFirst(dd.getSymbolName(), dd.getSymbolName() + "_dup");
        }

        return "// [ED]\n" + instr + ";\n";
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
