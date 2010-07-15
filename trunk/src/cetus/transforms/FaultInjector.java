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
import cetus.hir.CodeAnnotation;
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
import cetus.hir.FlatIterator;
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
import cetus.hir.KernelLaunch;
import cetus.hir.Label;
import cetus.hir.LinkageSpecification;
import cetus.hir.ListInitializer;
import cetus.hir.Literal;
import cetus.hir.MacroLiteral;
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
import cetus.hir.TemplateDeclaration;
import cetus.hir.TemplateID;
import cetus.hir.ThrowExpression;
import cetus.hir.Tools;
import cetus.hir.TranslationUnit;
import cetus.hir.Traversable;
import cetus.hir.Typecast;
import cetus.hir.UnaryExpression;
import cetus.hir.UnaryOperator;
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
public class FaultInjector extends TransformPass
{
    private static final String tag = "[ED] ";
    private Map<Statement, RangeDomain> range_map;

    public FaultInjector(Program prog)
    {
        super(prog);
        //variable_map = new HashTable();
    }

    @Override
    public String getPassName() {
        return "Fault Injector";
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
    int kernel_id = 0;

    private int GetNextKernelID() {
        return kernel_id++;
    }
    
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

    /**
     * Adds GPU FI header file
     */
    protected void InstrHeader()
    {
        /* Adds GPUFI library. */
        String header = "/* Instrumented by FaultInjector */\n"
                        + "#include \"gpufi.h\"\n";

        CodeAnnotation header_code = new CodeAnnotation(header);

        /* Puts this code section at the top of the "main_tu" translation unit */
        main_tu.addDeclarationFirst(new AnnotationDeclaration(header_code));
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
            System.out.println(" * " + proc.getSymbolName());
            for (int j = 0; j < spec_list.size(); j++) {
                    System.out.println("" + j + " : " + spec_list.get(j));
                if (spec_list.get(j) == Specifier.GLOBAL) {
                    global_proc.add(proc);
                    local_proc.add(proc);
                    break;
                }
                if (spec_list.get(j) == Specifier.DEVICE) {
                    local_proc.add(proc);
                    //spec_list.get(j).set(40 /* GLOBAL */);
                    break;
                }
            }
        }
    }

    @Override
    public void start()
    {
//        program.createNewDDGraph();
//        DDGraph ddg = program.getDDGraph();
//        System.out.println("DDG: " + ddg.toString());

        ScanProcedure();
        
        InstrHeader();
        InstrKernelCall();
        InstrKernel();
        InstrVirtualVariable(); /* inside kernel */
        InstrMain();
    }

    protected void InstrKernel()
    {
        for (int i = 0; i < global_proc.size(); i++) {
            Procedure proc = global_proc.get(i);
            // Modify function declaration
            Symbol symbol = new Symbol("struct _gpufi_data_ *gpufi_dev");
            Identifier gpu_para = new Identifier(symbol);

            // Store list of parameter before modifying
            List<Declaration> parameter_list = proc.getParameters();

            proc.addDeclaration(new VariableDeclaration (
                                    new VariableDeclarator(gpu_para)));

            DepthFirstIterator iter = new DepthFirstIterator(proc.getBody());

            Statement first_stmt = null;
            List<Statement> return_stmts = new ArrayList<Statement>();
            
            // Collect variable declaration statements
            while (iter.hasNext()) {
                Object o = iter.next();
                if (o == proc.getBody() || !(o instanceof Statement)) {
                    continue;
                }
                
                // collect return statements
                if (o instanceof ReturnStatement) {
                    return_stmts.add((Statement) o);
                }

                // identify the first statement
                if (first_stmt == null /*&& !(o instanceof DeclarationStatement)*/) {
                    first_stmt = (Statement) o;
                }
            }

            /* Instrument Header */
            if (first_stmt == null)
                continue;

            // Add head of global function
            //String instrument_paramenter = generateVariableListInstrumentString(parameter_list);

            int kid = GetNextKernelID();
            FunctionCall headFunc = new FunctionCall(new Identifier("GPUFI_KERNEL"));
            headFunc.addArgument(new MacroLiteral("gpufi_dev"));
            headFunc.addArgument(new MacroLiteral("GPUFI_KERNEL_BEGIN"));
            headFunc.addArgument(new IntegerLiteral(kid));
            headFunc.addArgument(new StringLiteral(proc.getSymbolName()));
            Statement headStat = new ExpressionStatement(headFunc);
            //addCudaComment(mainFIHeaderCode);
            //String headAnno = "GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, " + kid + ");\n";
            //first_stmt.annotateBefore(new CudaAnnotation(headAnno));
            proc.getBody().addStatementBefore(first_stmt, headStat);

            /* Instrument Tail */
            FunctionCall tailFunc = new FunctionCall(new Identifier("GPUFI_KERNEL"));
            tailFunc.addArgument(new MacroLiteral("gpufi_dev"));
            tailFunc.addArgument(new MacroLiteral("GPUFI_KERNEL_END"));
            tailFunc.addArgument(new IntegerLiteral(kid));
            tailFunc.addArgument(new StringLiteral(proc.getSymbolName()));
            Statement tailStat = new ExpressionStatement(tailFunc);

            if (return_stmts.size() == 0) {
                proc.getBody().addStatement((Statement) tailStat.clone());
            }
            else {
                for (Statement stmt : return_stmts) {
                    CompoundStatement parent = (CompoundStatement) stmt.getParent();
                    parent.addStatementBefore(stmt, (Statement) tailStat.clone());
                }
            }

            /* Insturment variables for parameters */
            InstrKernelParameters(proc, parameter_list, headStat);

            /* Instrument Loop Body */
            InstrKernelLoop(proc, parameter_list, new ArrayList<VariableDeclaration>());
        }
    }



    /**
     * Instrument Loop
     * @param tr    Target CompoundStatement
     * @param parameter_list    List of parameters in function
     * @param var_list          List of local variables which are defined BEFORE this CompoundStatement
     */
    private void InstrKernelLoop(Traversable tr, List<?> parameter_list, List<?> var_list)
    {
        FlatIterator iter = new FlatIterator(tr);

        // List contains local variables which is defined within this CompoundStatement
        ArrayList<VariableDeclaration> new_var_list = new ArrayList<VariableDeclaration>();

        // Traverse the statements
        while (iter.hasNext()) {
            Traversable t = iter.next();

            /*
            if (t instanceof DeclarationStatement) {
                // Store new variables
                DeclarationStatement dclr_stmt = (DeclarationStatement) t;
                new_var_list.add((VariableDeclaration) dclr_stmt.getDeclaration());

            }
            else if (t instanceof VariableDeclaration) {

                // Store variable and instrument the Declaration
                new_var_list.add((VariableDeclaration) t);
                String anno = generateVariableInstrumentString((VariableDeclaration) t);
                ((Statement)((VariableDeclaration) t).getParent()).annotateAfter(
                         new CudaAnnotation(anno));
            }
            */

            if (t == null) {
                // ignore
                continue;
            }
            else if (t instanceof Procedure) {
                // nested procedure
                InstrKernelLoop(t, parameter_list, new ArrayList<VariableDeclaration>());
            }
            else if (t instanceof ForLoop) {
                // For loop
                ArrayList<VariableDeclaration> list = new ArrayList<VariableDeclaration>();
                list.addAll((List<VariableDeclaration>) var_list);
                list.addAll(new_var_list);

                // Instrument before loop
                ForLoop loop = (ForLoop) t;
                CudaAnnotation before_loop = InstrKernelLoopBefore(parameter_list, list);
                loop.annotate(before_loop);

                // Instrument after loop
                CudaAnnotation after_loop = InstrKernelLoopAfter(parameter_list, list);
                loop.annotateAfter(after_loop);

                // Instrument inside loop
                CudaAnnotation inside_loop = InstrKernelLoopInside(parameter_list, list);
                Statement first_stmt_in_loop = null;
                List<Traversable> children_list = loop.getBody().getChildren();
                if (children_list != null) {
                    for (int j = 0; j < children_list.size(); j++) {
                        if (children_list.get(j) instanceof Statement) {
                            first_stmt_in_loop = (Statement) children_list.get(j);
                            break;
                        }
                    }

                    if (first_stmt_in_loop != null)
                        first_stmt_in_loop.annotateBefore(inside_loop);
                }

            }
            else if (t instanceof WhileLoop) {
                // While loop
                ArrayList<VariableDeclaration> list = new ArrayList<VariableDeclaration>();
                list.addAll((List<VariableDeclaration>) var_list);
                list.addAll(new_var_list);

                // Instrument before loop
                WhileLoop loop = (WhileLoop) t;
                CudaAnnotation before_loop = InstrKernelLoopBefore(parameter_list, list);
                loop.annotate(before_loop);

                // Instrument after loop
                CudaAnnotation after_loop = InstrKernelLoopAfter(parameter_list, list);
                loop.annotateAfter(after_loop);

                // Instrument inside loop
                CudaAnnotation inside_loop = InstrKernelLoopInside(parameter_list, list);
                Statement first_stmt_in_loop = null;
                List<Traversable> children_list = loop.getBody().getChildren();
                if (children_list != null) {
                    for (int j = 0; j < children_list.size(); j++) {
                        if (children_list.get(j) instanceof Statement) {
                            first_stmt_in_loop = (Statement) children_list.get(j);
                            break;
                        }
                    }

                    if (first_stmt_in_loop != null)
                        first_stmt_in_loop.annotateBefore(inside_loop);
                }

            }
            else if (t instanceof DoLoop) {
                // Do ... While loop
                ArrayList<VariableDeclaration> list = new ArrayList<VariableDeclaration>();
                list.addAll((List<VariableDeclaration>) var_list);
                list.addAll(new_var_list);

                // Instrument before loop
                DoLoop loop = (DoLoop) t;
                CudaAnnotation before_loop = InstrKernelLoopBefore(parameter_list, list);
                loop.annotate(before_loop);

                // Instrument after loop
                CudaAnnotation after_loop = InstrKernelLoopAfter(parameter_list, list);
                loop.annotateAfter(after_loop);

                // Instrument inside loop
                CudaAnnotation inside_loop = InstrKernelLoopInside(parameter_list, list);
                Statement first_stmt_in_loop = null;
                List<Traversable> children_list = loop.getBody().getChildren();
                if (children_list != null) {
                    for (int j = 0; j < children_list.size(); j++) {
                        if (children_list.get(j) instanceof Statement) {
                            first_stmt_in_loop = (Statement) children_list.get(j);
                            break;
                        }
                    }

                    if (first_stmt_in_loop != null)
                        first_stmt_in_loop.annotateBefore(inside_loop);
                }

            }
            else if (t.getChildren() != null) {
                ArrayList<VariableDeclaration> list = new ArrayList<VariableDeclaration>();
                list.addAll((List<VariableDeclaration>) var_list);
                list.addAll(new_var_list);
                InstrKernelLoop(t, parameter_list, list);
            }
        }
    }

    private CudaAnnotation InstrKernelLoopBefore(List<?> parameter_list, List<?> var_decl_list)
    {
        String before_loop = "/* Fault Injector Instrumentation Begin */\n";

        //before_loop += generateVariableListInstrumentString(parameter_list);
        //before_loop += generateVariableListInstrumentString(var_decl_list);
        before_loop +=
                "GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);\n" +
                "/* Fault Injector Instrumentation End */";

        return new CudaAnnotation(before_loop);
    }

    private CudaAnnotation InstrKernelLoopAfter(List<?> parameter_list, List<?> var_decl_list)
    {
        String before_loop = "/* Automatically inserted by Cetus_Cuda */\n";

        /*
        ArrayList<VariableDeclaration> para_list = new ArrayList<VariableDeclaration>();
        for (int i = 0; i < parameter_list.size(); i++) {
            if (parameter_list.get(i) instanceof VariableDeclaration) {
                para_list.add((VariableDeclaration) parameter_list.get(i));
            }
        }

        before_loop += generateVariableListInstrumentString(para_list);
        before_loop += generateVariableListInstrumentString(var_decl_list);
         */
        before_loop +=
                "GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);\n" +
                "/* Fault Injector Instrumentation End */";

        before_loop += "/* End of Cetus_Cuda code */";

        return new CudaAnnotation(before_loop);
    }

    /**
     * Generate Inside loop Instrument code
     * @param parameter_list
     * @param var_decl_list
     * @return
     */
    private CudaAnnotation InstrKernelLoopInside(List<?> parameter_list, List<?> var_decl_list)
    {
        String before_loop = "/* Fault Injector Instrumentation Begin */\n" +
                            "GPUFI_KERNEL_ITERATION(gpufi_dev);\n";
        
        /*
        ArrayList<VariableDeclaration> para_list = new ArrayList<VariableDeclaration>();
        for (int i = 0; i < parameter_list.size(); i++) {
            if (parameter_list.get(i) instanceof VariableDeclaration) {
                para_list.add((VariableDeclaration) parameter_list.get(i));
            }

        }
        before_loop += generateVariableListInstrumentString(para_list);
        before_loop += generateVariableListInstrumentString(var_decl_list);
        */
        
        before_loop += "/* Fault Injector Instrumentation End */";
        
        return new CudaAnnotation(before_loop);
    }

    protected void InstrKernelCall()
    {
        for (int i = 0; i < proc_list.size(); i++) {
            Procedure proc = proc_list.get(i);

            DepthFirstIterator iter = new DepthFirstIterator(proc.getBody());
            Statement prevStmt = null;
            /* Collect the program points to add FI code call before */
            while (iter.hasNext()) {
                Object o = iter.next();
                if (o instanceof Statement) {
                    prevStmt = (Statement) o;
                }

                if (o == proc.getBody() || !(o instanceof FunctionCall)) {
                    continue;
                }

                // collect Kernel Launch
                if (o instanceof KernelLaunch) {
                    KernelLaunch launcher = (KernelLaunch) o;
                    Identifier gpu_arg = new Identifier("gpufi_dev");

                    prevStmt.annotateBefore(new CudaAnnotation(
                            "/* Fault Injection Instrumentation Begin */\n" +
                            "cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));\n" +
                            "CUDA_ERRCK\n" +
                            "cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);\n" +
                            "CUDA_ERRCK\n" +
                            "/* Fault Injection Instrumentation End */"));

                    prevStmt.annotateAfter(new CudaAnnotation(
                            "/* Fault Injection Instrumentation Begin */\n" +
                            "cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);\n" +
                            "CUDA_ERRCK\n" +
                            "cudaFree(gpufi_dev);\n" +
                            "CUDA_ERRCK\n" +
                            "/* Fault Injection Instrumentation End */"));

                    launcher.addArgument(gpu_arg);
                }
            }
        }
    }
    
    /**
     * Modify main function:
     */
    private void InstrMain()
    {
        if (main_proc == null) {
            System.err.println("[WARNING] main routine not found");
        }
        else {
            List<Statement> return_stmts = new ArrayList<Statement>();
            Statement first_stmt = null;
            DepthFirstIterator iter = new DepthFirstIterator(main_proc.getBody());

            /* Collect the program points to add FI code call before */
            while (iter.hasNext()) {
                Object o = iter.next();
                if (o == main_proc.getBody() || !(o instanceof Statement)) {
                    continue;
                }

                // collect return statements
                if (o instanceof ReturnStatement) {
                    return_stmts.add((Statement) o);
                }

                // identify the first statement
                if (first_stmt == null && !(o instanceof DeclarationStatement)) {
                    first_stmt = (Statement) o;
                }
            }

            /* Inserts head of main */
            String mainFIHeaderCode = "GPUFI_INIT(" +
                           kernel_id + ", " +
                           variable_id + ");\n";
            first_stmt.annotateAfter(new CudaAnnotation(mainFIHeaderCode));
            
            /*
            List<Expression> args = ;
            Statement mainFIHeaderCode = new ExpressionStatement(
                    new FunctionCall(new Identifier("GPUFI_FETCH_COMMAND")));
            //addCudaComment(mainFIHeaderCode);
            main_proc.getBody().addStatementBefore(first_stmt, mainFIHeaderCode);
            */
            
            /* Inserts tails of main */
            StringLiteral arg = new StringLiteral("fi_profile.txt");
            FunctionCall fiEndFunc = new FunctionCall(new Identifier("GPUFI_HALT"));
            fiEndFunc.addArgument(arg);
            
            Statement mainFIReturnCode = new ExpressionStatement(fiEndFunc);
            //addCudaComment(mainFIReturnCode);
            
            if (return_stmts.size() == 0) {
                main_proc.getBody().addStatement((Statement) mainFIReturnCode.clone());
            }
            else {
                for (Statement stmt : return_stmts) {
                    CompoundStatement parent = (CompoundStatement) stmt.getParent();
                    parent.addStatementBefore(stmt, (Statement) mainFIReturnCode.clone());
                }
                main_proc.getBody().addStatement((Statement) mainFIReturnCode.clone());
            }
        }
    }

    private String GenInstrVariable(VariableDeclaration var)
    {
        int varId = GetNextVariableID();

        String var_type = "GPUFI_DATATYPE_UNKNOWN";
        int i, j;

        for(i=0; i<var.getNumDeclarators(); i++){
            Declarator d = var.getDeclarator(i);

            List<Specifier> s = d.getSpecifiers();
            for(j=0; j<s.size(); j++){
                Specifier sp = s.get(i);

                System.out.println("* " + sp.toString());
                /*
                System.out.println("Declarator " + i + " : " + var.getDeclarator(i).getSymbolName().toString());
                if(var.getDeclarator(i).getSymbolName().toString().equals("int")){
                    var_type = "GPUFI_DATATYPE_INTEGER";
                }*/
            }
        }

        String str = "GPUFI_KERNEL_VARIABLE(gpufi_dev, " +
                    varId +
                    ", \"" + var.getDeclaredSymbols().get(0).toString() +
                    "\", (int*)&" +
                    var.getDeclaredSymbols().get(0).toString() + ", " +
                    var_type + ");\n";

        if (var.isPointer()) {
            String astr = "GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, " +
                    varId +
                    ", \"\", (int*)" +
                    var.getDeclaredSymbols().get(0).toString() +
                    ", 1 /* Array size */, " +            // size of array
                    "1 /* Number of faults */" +        // number of faults will be injected
                    ");\n";
        }

        return str;
    }

    protected void InstrKernelParameters(Traversable tr, List<Declaration> parameter_list, Statement stat)
    {
        int i;

        for(i=0; i<parameter_list.size(); i++){
            VariableDeclaration var = (VariableDeclaration) parameter_list.get(i);
            stat.annotateAfter(new CudaAnnotation(GetAnnotateVariableString(var, var.getDeclarator(0).getSymbolName())));
        }
    }

    protected String GetAnnotateVariableString(VariableDeclaration var, String id)
    {
        int i, j;
        String var_datatype = "GPUFI_DATATYPE_UNKNOWN";

        /* No fault injection for variables duplicated by error detector */
        if(id.endsWith("_dup"))
            return "";
        
        if(var == null || var.getSpecifiers() == null)
            return "/* CUDAFI ANNOTATION ERROR */";
        
        for(i=0; i<var.getSpecifiers().size(); i++){
            System.out.println("- Spec: " + var.getSpecifiers().get(i));
            if(var.getSpecifiers().get(i).toString().equals("int")){
                var_datatype = "GPUFI_DATATYPE_INTEGER";
            }
            else if(var.getSpecifiers().get(i).toString().equals("float")){
                var_datatype = "GPUFI_DATATYPE_FLOAT";
            }
        }

        if(!id.contains("[") && !id.contains("*") && var.isPointer()){
            var_datatype += "_POINTER";
        }

        /*
        for(i=0; i<var.getNumDeclarators(); i++){
            for(j=0; j<var.getDeclarator(i).getSpecifiers().size(); j++){
                System.out.println("Specifier " + j + " : " + var.getDeclarator(i).getSpecifiers().get(j).toString());
            }
            System.out.println("" + i + " : " + var.getDeclarator(i).toString());
        }
        */


        //Tools.printlnStatus("- " + d.toString() + " : " + d.getSymbolName(), -10);
        return "GPUFI_KERNEL_VARIABLE(gpufi_dev, " +
                       GetNextVariableID() +
                       ", \"" + id + "\", (int*)&" +
                        id + ", " +
                        var_datatype + ");\n";
    }
    
    protected Identifier GetIdentifier(Traversable expr)
    {
        int i;
        List<Traversable> child = expr.getChildren();

        if(expr instanceof Identifier)
            return (Identifier) expr;
        
        for(i=0; i<child.size(); i++){
            if(child.get(i) instanceof Identifier)
                return (Identifier)child.get(i);
            else{
                Identifier t = GetIdentifier(child.get(i));
                if(t != null)
                    return t;
            }
        }

        return null;
    }

    protected void InstrVirtualVariable()
    {
        /* Instrument GPU Kernel Functions */
        for (int i = 0; i < global_proc.size(); i++) {
            Procedure proc = global_proc.get(i);

            //TreeMap<Expression, Expression> defs = DataFlow.defSet(proc);
            //System.out.println("DEFS: " + defs.toString());
            
            /*
            {
                DepthFirstIterator kern_iter = new DepthFirstIterator(proc.getBody());

                // Collect variable declaration statements
                while (kern_iter.hasNext()) {
                    Object o = kern_iter.next();

                    if(o instanceof BasicBlock){
                        BasicBlock bb = (BasicBlock) o;
                        Set<Expression> def = DataFlow.getDefSet(bb);
                        Set<Expression> use = DataFlow.getUseSet(bb);
                        System.out.println("BB : " + bb.toString());
                        for(int j=0; j<def.size(); j++){
                            Expression expr = (Expression) def.toArray()[j];
                            System.out.println("DEF : " + expr.toString());
                        }
                        for(int j=0; j<use.size(); j++){
                            Expression expr = (Expression) use.toArray()[j];
                            System.out.println("USE : " + expr.toString());
                        }
                    }
                }
            }
            */

            Tools.printlnStatus(tag + "Entering procedure \"" + proc.getName() + "\"...", -10);
            {
                DepthFirstIterator kern_iter = new DepthFirstIterator(proc.getBody());

                // Collect variable declaration statements
                while (kern_iter.hasNext()) {
                    Object o = kern_iter.next();

                    if (o instanceof DeclarationStatement) {
                        DeclarationStatement expr = (DeclarationStatement) o;
                        //Tools.printlnStatus(tag + "Dec " + expr.toString(), -10);
                        VariableDeclaration var = (VariableDeclaration) expr.getDeclaration();

                        expr.annotateAfter(new CudaAnnotation(GetAnnotateVariableString(var,var.getDeclarator(0).getSymbolName())));
                    }
                    else if(o instanceof AssignmentExpression){
                        AssignmentExpression expr = (AssignmentExpression) o;

                        /* Find Identifier */
                        Identifier id = GetIdentifier(expr.getLHS());
                        VariableDeclaration var = (VariableDeclaration)id.findDeclaration();

                        expr.getStatement().annotateAfter(new CudaAnnotation(GetAnnotateVariableString(var, expr.getLHS().toString())));
                    }
                    else if(o instanceof UnaryExpression){
                        UnaryExpression expr = (UnaryExpression) o;
                        UnaryOperator op = expr.getOperator();

                        /* there are only a few UnaryOperators that create
                        definitions */
                        if (UnaryOperator.hasSideEffects(op)) {
                            Identifier id = GetIdentifier(expr);
                            VariableDeclaration var = (VariableDeclaration)id.findDeclaration();
                            
                            expr.getStatement().annotateAfter(new CudaAnnotation(GetAnnotateVariableString(var, id.toString())));
                        }
                        /* Common Assignment Statement */
                        /*
                        if(expr.getParent() instanceof ExpressionStatement){
                            ExpressionStatement e = (ExpressionStatement) expr.getParent();
                            String instr = "GPUFI_KERNEL_VARIABLE(gpufi_dev, " +
                                           GetNextVariableID() +
                                           ", \"" + expr.getLHS().toString() + "\", (int*)&" +
                                           expr.getLHS().toString() + ", GPUFI_DATATYPE_UNKNOWN);\n";
                            e.annotateAfter(new CudaAnnotation(instr));
                        }
                        else{
                            // analysis
                            Tools.printlnStatus(tag + "VV-Start " + expr.getLHS().toString(), -10);

                            Traversable e = (Traversable) expr;
                            Tools.printlnStatus("- " + " : " + GetType(e) + " - " + e.toString(), -10);
                            e = e.getParent();
                            while(e != null){
                                Tools.printlnStatus("- " + " : " + GetType(e), -10);
                                if(e instanceof Statement){
                                    Tools.printlnStatus("*", -10);
                                }
                                //e.toString().substring(0, 10) +
                                e = e.getParent();
                            }
                        }
                        */
                    }
                }
            }
        }
    }
}