package cetus.transforms;

import java.io.*;
import java.util.*;

import cetus.hir.*;
import cetus.analysis.*;

/**
 * LoopProfile inserts timers around loops following the selection strategy
 * specified by "select" field.
 *
 * Instrument Cuda code to support fault injection.
 * (1) Adding header for main file
 * (2) Adding header for main function
 * (3) Adding GPUFI_END before main's return commands
 * (4) Adding allocating FI memory code before each kernel call
 * (5) Adding deallocating FI memory code after each kernel call
 * (6) Change kernel call parameters
 * 
 *
 * @author cuongpham
 */
public class CudaFaultInjection extends TransformPass {
    /* The total number of loops */

    private int num_loops;

    /* The "main" procedure */
    private Procedure main_proc;

    /* List of all procedures */
    private ArrayList<Procedure> proc_list;

    /* The translation unit containing the "main" procedure */
    private TranslationUnit main_tu;
    private int strategy;

    /* Insertion points of timing routine */
    private static final int ADD = 0;
    private static final int ADD_BEFORE = 1;
    private static final int ADD_AFTER = 2;

    /* Instrumenting strategies */
    private static final int EVERY = 1;
    private static final int OUTER = 2;
    private static final int EVERY_PAR = 3;
    private static final int OUTER_PAR = 4;
    private static final int EVERY_OMP = 5;
    private static final int OUTER_OMP = 6;

    /* global IDs */
    private static int kernel_id = 0;
    private static int variable_id = 1000;

    Hashtable variable_map;
    private int getNextKernelID() {
        return kernel_id++;
    }

    private int getNextVariableID() {
        return variable_id++;
    }

    private int getVariableID(Declaration dclr) {
        Object o = variable_map.get(dclr);
        Integer it;
        if (o == null) {
            it = new Integer(getNextVariableID());
            variable_map.put(dclr, it);
        } else {
            it = (Integer) o;
        }
        
        return it.intValue();
    }
    /**
     * Constructs a new CudaFaultInjection object from the specified program and
     * performs profiling. It collects information such as total number of
     * procedures, maximum number of loops per procedure, main procedure, and
     * main translation unit for code generation.
     */
    public CudaFaultInjection(Program prog) {
        super(prog);
        num_loops = 0;
        main_proc = null;
        main_tu = null;
        strategy = EVERY;
        variable_map = new Hashtable();
    }

    public String getPassName() {
        return "[Cuda fault injection instrumentation]";
    }

    public void start() {
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

        AddGpuFIHeader();

        ModifyMainFunction();

        ModifyKernelLaunch();

        ModifyKernelProcedure();
    }

    private void ModifyKernelProcedure() {
        ArrayList<Procedure> global_proc = new ArrayList<Procedure>();

        // Collecting global procedures
        for (int i = 0; i < proc_list.size(); i++) {
            Procedure proc = proc_list.get(i);
            List<Specifier> spec_list = proc.getTypeSpecifiers();
            for (int j = 0; j < spec_list.size(); j++) {
                if (spec_list.get(j) == Specifier.GLOBAL) {
                    global_proc.add(proc);
                    break;
                }
            }
        }

        for (int i = 0; i < global_proc.size(); i++) {
            Procedure proc = global_proc.get(i);
            InstrumentGlobalProcedure(proc);
        }
    }

    private String GenInstrVariable(VariableDeclaration var) {

        int varId = getVariableID(var);
        
        String var_type = "GPUFI_DATATYPE_UNKNOWN";
        int i;
        
        for(i=0; i<var.getNumDeclarators(); i++){
            System.out.println("Declarator " + i + " : " + var.getDeclarator(i).getSymbolName().toString());
            if(var.getDeclarator(i).getSymbolName().toString().equals("int")){
                var_type = "GPUFI_DATATYPE_INTEGER";
            }
        }
        
        String str = "GPUFI_KERNEL_VARIABLE(gpufi_dev, " +
                    varId +
                    ", \"\", (int*)&" +
                    var.getDeclaredSymbols().get(0).toString() +
                    ", " +
                    var_type +
                    ");\n";

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

    private String generateVariableListInstrumentString(List<?> var_list) {
        String str = "";

        for (int i = 0; i < var_list.size(); i++) {
            if (var_list.get(i) instanceof VariableDeclaration) {
                VariableDeclaration dlc = (VariableDeclaration) var_list.get(i);
                str += generateVariableInstrumentString(dlc);
            }
        }

        return str;
    }

    /**
     *
     */
    private CudaAnnotation generateBeforeLoopAnnotation(
                        List<?> parameter_list,
                        List<?> var_decl_list) {
        String before_loop = "/* Automatically inserted by Cetus_Cuda */\n";

        before_loop += generateVariableListInstrumentString(parameter_list);
        before_loop += generateVariableListInstrumentString(var_decl_list);
        before_loop +=
                "GPUFI_KERNEL_LOOP(gpufi_dev);\n" +
                "/* End of Cetus_Cuda code */";

        return new CudaAnnotation(before_loop);
    }

    private CudaAnnotation generateAfterLoopAnnotation(
                        List<?> parameter_list,
                        List<?> var_decl_list) {
        String before_loop = "/* Automatically inserted by Cetus_Cuda */\n";

        ArrayList<VariableDeclaration> para_list = new ArrayList<VariableDeclaration>();
        for (int i = 0; i < parameter_list.size(); i++) {
            if (parameter_list.get(i) instanceof VariableDeclaration) {
                para_list.add((VariableDeclaration) parameter_list.get(i));
            }

        }

        before_loop += generateVariableListInstrumentString(para_list);
        before_loop += generateVariableListInstrumentString(var_decl_list);
        before_loop += "/* End of Cetus_Cuda code */";

        return new CudaAnnotation(before_loop);
    }

    /**
     * Generate Inside loop Instrument code
     * @param parameter_list
     * @param var_decl_list
     * @return
     */
    private CudaAnnotation generateInsideLoopAnnotation(
                        List<?> parameter_list,
                        List<?> var_decl_list) {
        String before_loop = "/* Automatically inserted by Cetus_Cuda */\n" +
                            "GPUFI_KERNEL_ITERATION(gpufi_dev);\n";

        ArrayList<VariableDeclaration> para_list = new ArrayList<VariableDeclaration>();
        for (int i = 0; i < parameter_list.size(); i++) {
            if (parameter_list.get(i) instanceof VariableDeclaration) {
                para_list.add((VariableDeclaration) parameter_list.get(i));
            }

        }

        before_loop += generateVariableListInstrumentString(para_list);
        before_loop += generateVariableListInstrumentString(var_decl_list);
        before_loop += "/* End of Cetus_Cuda code */";

        return new CudaAnnotation(before_loop);
    }

    /**
     * Instrument Loop
     * @param tr    Target CompoundStatement
     * @param parameter_list    List of parameters in function
     * @param var_list          List of local variables which are defined BEFORE this CompoundStatement
     */
    private void addLoopInstrument(Traversable tr,
                                          List<?> parameter_list,
                                          List<?> var_list) {
        FlatIterator iter = new FlatIterator(tr);
        
        // List contains local variables which is defined within this CompoundStatement
        ArrayList<VariableDeclaration> new_var_list = new ArrayList<VariableDeclaration>();

        // Traverse the statements
        while (iter.hasNext()) {
            Traversable t = iter.next();
            
            if (t instanceof DeclarationStatement) {
                // Store new variables
                DeclarationStatement dclr_stmt = (DeclarationStatement) t;
                new_var_list.add((VariableDeclaration) dclr_stmt.getDeclaration());

            } else if (t instanceof VariableDeclaration) {

                // Store variable and instrument the Declaration
                new_var_list.add((VariableDeclaration) t);
                String anno = generateVariableInstrumentString((VariableDeclaration) t);
                ((Statement)((VariableDeclaration) t).getParent()).annotateAfter(
                         new CudaAnnotation(anno));

            }
            
            if (t == null) {
                // ignore
                continue;

            } else if (t instanceof Procedure) {

                // nested procedure
                addLoopInstrument(t, parameter_list, new ArrayList<VariableDeclaration>());

            } else if (t instanceof ForLoop) {
                // For loop
                ArrayList<VariableDeclaration> list = new ArrayList<VariableDeclaration>();
                list.addAll((List<VariableDeclaration>) var_list);
                list.addAll(new_var_list);

                // Instrument before loop
                ForLoop loop = (ForLoop) t;
                CudaAnnotation before_loop = generateBeforeLoopAnnotation(parameter_list, list);
                loop.annotate(before_loop);

                // Instrument after loop
                CudaAnnotation after_loop = generateAfterLoopAnnotation(parameter_list, list);
                loop.annotateAfter(after_loop);

                // Instrument inside loop
                CudaAnnotation inside_loop = generateInsideLoopAnnotation(parameter_list, list);
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

            } else if (t instanceof WhileLoop) {
                // While loop
                ArrayList<VariableDeclaration> list = new ArrayList<VariableDeclaration>();
                list.addAll((List<VariableDeclaration>) var_list);
                list.addAll(new_var_list);

                // Instrument before loop
                WhileLoop loop = (WhileLoop) t;
                CudaAnnotation before_loop = generateBeforeLoopAnnotation(parameter_list, list);
                loop.annotate(before_loop);

                // Instrument after loop
                CudaAnnotation after_loop = generateAfterLoopAnnotation(parameter_list, list);
                loop.annotateAfter(after_loop);

                // Instrument inside loop
                CudaAnnotation inside_loop = generateInsideLoopAnnotation(parameter_list, list);
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

            } else if (t instanceof DoLoop) {
                // Do ... While loop
                ArrayList<VariableDeclaration> list = new ArrayList<VariableDeclaration>();
                list.addAll((List<VariableDeclaration>) var_list);
                list.addAll(new_var_list);

                // Instrument before loop
                DoLoop loop = (DoLoop) t;
                CudaAnnotation before_loop = generateBeforeLoopAnnotation(parameter_list, list);
                loop.annotate(before_loop);

                // Instrument after loop
                CudaAnnotation after_loop = generateAfterLoopAnnotation(parameter_list, list);
                loop.annotateAfter(after_loop);

                // Instrument inside loop
                CudaAnnotation inside_loop = generateInsideLoopAnnotation(parameter_list, list);
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

            } else if (t.getChildren() != null) {
                ArrayList<VariableDeclaration> list = new ArrayList<VariableDeclaration>();
                list.addAll((List<VariableDeclaration>) var_list);
                list.addAll(new_var_list);
                addLoopInstrument(t, parameter_list, list);
            }
        }
    }

    /**
     * Modify __global__ function
     * @param proc      Function to be modified
     */
    private void InstrumentGlobalProcedure(Procedure proc) {
        // Modify function declaration
        Identifier gpu_para = new Identifier("struct _gpufi_data_ *gpufi_dev");
        
        // Store list of parameter before modifying
        List<Declaration> parameter_list = proc.getParameters();

        proc.addDeclaration(new VariableDeclaration (
                                new VariableDeclarator(gpu_para)));
        
        DepthFirstIterator iter = new DepthFirstIterator(proc.getBody());

        Statement first_stmt = null;

        // Collect variable declaration statements
        while (iter.hasNext()) {
            Object o = iter.next();

            // Collect first statement
            if (first_stmt == null)
                if (o instanceof DeclarationStatement) {
                    first_stmt = (Statement) o;
                    break;
                }
        }

        if (first_stmt == null)
            return;

        // Add head of global function
        String instrument_paramenter = generateVariableListInstrumentString(parameter_list);
        
        String global_head = 
                        "\n/* Automatically inserted by Cetus_Cuda */\n" +
                        "GPUFI_KERNEL_KERNEL(gpufi_dev, " + getNextKernelID() + ");\n" +
                        instrument_paramenter +
                        "/* End of Cetus_Cuda code */";
        first_stmt.annotateBefore(new CudaAnnotation(global_head));

        addLoopInstrument(proc, parameter_list, new ArrayList<VariableDeclaration>());
    }


    /**
     * Modify all kernel launchers
     */
    private void ModifyKernelLaunch() {
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
                            "/* Automatically inserted by Cetus_Cuda */\n" +
                            "cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));\n" +
                            "CUDA_ERRCK\n" +
                            "cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);\n" +
                            "CUDA_ERRCK\n" +
                            "/* End of Cetus_Cuda code */"));

                    prevStmt.annotateAfter(new CudaAnnotation(
                            "/* Automatically inserted by Cetus_Cuda */\n" +
                            "cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);\n" +
                            "CUDA_ERRCK\n" +
                            "cudaFree(gpufi_dev);\n" +
                            "CUDA_ERRCK\n" +
                            "/* End of Cetus_Cuda code */"));

                    launcher.addArgument(gpu_arg);
                }
            }
        }
        
    }

    /**
     * Modify main function:
     *
     */
    private void ModifyMainFunction() {
        if (main_proc == null) {
            System.err.println("[WARNING] main routine not found");
        } else {
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
            Statement mainFIHeaderCode = new ExpressionStatement(
                    new FunctionCall(new Identifier("GPUFI_FETCH_COMMAND")));
            addCudaComment(mainFIHeaderCode);
            main_proc.getBody().addStatementBefore(first_stmt, mainFIHeaderCode);

            /* Inserts tails of main */
            StringLiteral arg = new StringLiteral("fi_profile.txt");
            FunctionCall fiEndFunc = new FunctionCall(new Identifier("GPUFI_END"));
            fiEndFunc.addArgument(arg);

            Statement mainFIReturnCode = new ExpressionStatement(fiEndFunc);
            addCudaComment(mainFIReturnCode);

            if (return_stmts.size() == 0) {
                main_proc.getBody().addStatement((Statement) mainFIReturnCode.clone());
            } else {
                for (Statement stmt : return_stmts) {
                    CompoundStatement parent = (CompoundStatement) stmt.getParent();
                    parent.addStatementBefore(stmt, (Statement) mainFIReturnCode.clone());
                }
            }

        }

    }

    /**
     *  Add comment for each instrumented code
     */
    private void addCudaComment(Statement stmt) {
        CommentAnnotation beginComment = new CommentAnnotation("Automatically inserted by Cetus_Cuda");
        CommentAnnotation endComment = new CommentAnnotation("End of Cetus_Cuda code");
        stmt.annotateBefore(beginComment);
        stmt.annotateAfter(endComment);
    }

    /**
     * Adds GPU FI header file
     */
    private void AddGpuFIHeader() {
        /* Adds GPUFI library. */
        String header =
                "/* Automatically inserted by Cetus_Cuda */\n"
                + "#include \"gpufi.h\"\n"
                + "/* End of Cetus_Cuda code */\n";

        CodeAnnotation header_code = new CodeAnnotation(header);

        /* Puts this code section at the top of the "main_tu" translation unit */
        main_tu.addDeclarationFirst(new AnnotationDeclaration(header_code));
    }
}
