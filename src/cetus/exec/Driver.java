package cetus.exec;

import java.io.*;
import java.util.*;

import cetus.analysis.*;
import cetus.hir.*;
import cetus.transforms.*;
import cetus.codegen.*;

/**
 * Implements the command line parser and controls pass ordering.
 * Users may extend this class by overriding runPasses
 * (which provides a default sequence of passes).  The derived
 * class should pass an instance of itself to the run method.
 * Derived classes have access to a protected {@link Program Program} object.
 */
public class Driver
{
  /**
   * A mapping from option names to option values.
   */
  protected static CommandLineOptionSet options = new CommandLineOptionSet();

  /**
   * Override runPasses to do something with this object.
   * It will contain a valid program when runPasses is called.
   */
  protected Program program;

  /** The filenames supplied on the command line. */
  protected String[] filenames;

  /**
   * Constructor used by derived classes.
   */
  public Driver()
  {
    options.add(options.ANALYSIS, "callgraph",
                "Print the static call graph to stdout");
    options.add(options.UTILITY, "expand-user-header",
                "Expand user (non-standard) header file #includes into code");
    options.add(options.UTILITY, "expand-all-header",
                "Expand all header file #includes into code");
    options.add(options.UTILITY, "help",
                "Print this message");
    options.add(options.TRANSFORM, "induction",
                "Perform induction variable substitution");
    options.add(options.UTILITY, "outdir", "dirname",
                "Set the output directory name (default is cetus_output)");
    options.add(options.TRANSFORM, "normalize-loops",
                "Normalize for loops so they begin at 0 and have a step of 1");
    options.add(options.UTILITY, "preprocessor", "command",
                "Set the preprocessor command to use");
    options.add(options.ANALYSIS, "privatize",
                "Perform scalar/array privatization analysis");
    options.add(options.ANALYSIS, "reduction", "N",
                "Perform reduction variable analysis\n"
                + "      =1 enable only scalar reduction analysis (default)\n"
                + "      =2 enable array reduction analysis as well");
    options.add(options.UTILITY, "skip-procedures", "proc1,proc2,...",
                "Causes all passes that observe this flag to skip the listed procedures");
    options.add(options.TRANSFORM, "tsingle-call",
                "Transform all statements so they contain at most one function call");
    options.add(options.TRANSFORM, "tinline-expansion",
    			"(Experimental) Perform simple subroutine inline expansion tranformation");
    options.add(options.TRANSFORM, "tsingle-declarator",
                "Transform all variable declarations so they contain at most one declarator");
    options.add(options.TRANSFORM, "tsingle-return",
                "Transform all procedures so they have a single return statement"); 
    options.add(options.UTILITY, "verbosity", "N",
                "Degree of status messages (0-4) that you wish to see (default is 0)");
    options.add(options.UTILITY, "version",
                "Print the version information");

    options.add(options.ANALYSIS, "ddt", "N",
        "Perform Data Dependence Testing\n"
        + "      =1 banerjee-wolfe test (default)\n"
        + "      =2 range test\n"
        + "      =3 not used");

    options.add(options.ANALYSIS, "parallelize-loops",
          "Annotate loops with Parallelization decisions");

    options.add(options.CODEGEN, "ompGen", "N",
        "Generate OpenMP pragma\n"
        + "      =1 keep existing pragmas (default)\n"
        + "      =2 remove existing OpenMP pragma\n"
        + "      =3 remove cetus-internal pragma\n"
        + "      =4 remove both");

/*
    options.add(options.TRANSFORM, "loop-interchange",
                "Interchange loop to improve locality (This flag should be used with -ddt flag)");
*/

    options.add(options.TRANSFORM, "profile-loops", "N",
        "Inserts loop-profiling calls\n"
        + "      =1 every loop          =2 outer-most loop\n"
        + "      =3 auto-parallel loop  =4 outer-most auto-parallel loop\n"
        + "      =5 OpenMP loop         =6 outer-most OpenMP loop");
    
	options.add(options.UTILITY, "macro",
				"Sets macros for the specified names with comma-separated list (no space is allowed). e.g., -macro=ARCH=i686,OS=linux");

	options.add(options.ANALYSIS, "alias", "N",
		"Specify level of alias analysis\n"
		+ "      =0 disable alias analysis\n"
		+ "      =1 advanced interprocedural analysis (default)\n"
		+ "         Uses interprocedural points-to analysis"
		);
/*
    options.add(options.TRANSFORM, "loop-tiling",
                "Loop tiling");
*/
    options.add(options.TRANSFORM, "normalize-return-stmt",
    	"Normalize return statements for all procedures");
    options.add(options.ANALYSIS, "range", "N",
      "Specifies the accuracy of symbolic analysis with value ranges\n"
      + "      =0 disable range computation (minimal symbolic analysis)\n"
      + "      =1 enable local range computation (default)\n"
      + "      =2 enable inter-procedural computation (experimental)");
    options.add(options.UTILITY, "preserve-KR-function",
        "Preserves K&R-style function declaration");

    options.add(options.TRANSFORM, "cuda-inj",
        "Fault Injector Instrumentation for CUDA");
    options.add(options.TRANSFORM, "fault-injector",
        "Fault Injector Instrumentation for CUDA");
    options.add(options.TRANSFORM, "error-detector",
        "Error Detector Instrumentation for CUDA");
    options.add(options.TRANSFORM, "error-detector1pt",
        "Error Detector Instrumentation for CUDA");
    }

  /**
   * Returns the value of the given key or null
   * if the value is not set.  Key values are
   * set on the command line as <b>-option_name=value</b>.
   *
   * @return the value of the given key or null if the
   *   value is not set.
   */
  public static String getOptionValue(String key)
  {
    return options.getValue(key);
  }

  /**
   * Returns the set a procedure names that should be
   * excluded from transformations.  These procedure
   * names are specified with the skip-procedures
   * command line option by providing a comma-separated
   * list of names. */
  public static HashSet getSkipProcedureSet()
  {
    HashSet<String> proc_skip_set = new HashSet<String>();

    String s = getOptionValue("skip-procedures");
    if (s != null)
    {
      String[] proc_names = s.split(",");
      for (String name : proc_names)
        proc_skip_set.add(name);
    }

    return proc_skip_set;
  }

  /**
   * Parses command line options to Cetus.
   *
   * @param args The String array passed to main by the system.
   */
  protected void parseCommandLine(String[] args)
  {
    /* print a useful message if there are no arguments */
    if (args.length == 0)
    {
      printUsage();
      System.exit(1);
    }

    /* set default option values */
    setOptionValue("outdir", "cetus_output");
    setOptionValue("preprocessor", "cpp -C");
    setOptionValue("verbosity", "0");
    setOptionValue("alias", "1");

    int i; /* used after loop; don't put inside for loop */
    for (i = 0; i < args.length; ++i)
    {
      String opt = args[i];

      if (opt.charAt(0) != '-')
        /* not an option -- skip to handling options and filenames */
        break;

      int eq = opt.indexOf('=');

      if (eq == -1)
      {
        /* no value on the command line, so just set it to "1" */
        String option_name = opt.substring(1);

        if (options.contains(option_name))
          setOptionValue(option_name, "1");
        else
          System.err.println("ignoring unrecognized option " + option_name);
      }
      else
      {
        /* use the value from the command line */
        String option_name = opt.substring(1, eq);

        if (options.contains(option_name))
          setOptionValue(option_name, opt.substring(eq + 1));
        else
          System.err.println("ignoring unrecognized option " + option_name);
      }
    }

    if (getOptionValue("help") != null || getOptionValue("usage") != null)
    {
      printUsage();
      System.exit(0);
    }

    if (getOptionValue("version") != null)
    {
      printVersion();
      System.exit(0);
    }

    if (i >= args.length)
    {
      System.err.println("No input files!");
      System.exit(1);
    }

    filenames = new String[args.length - i];
    for (int j = 0; j < filenames.length; ++j)
      filenames[j] = args[i++];
  }

  /**
   * Parses all of the files listed in <var>filenames</var>
   * and creates a {@link Program Program} object.
   */
/*
  protected void parseFiles_old()
  {
    try {
      program = new Program(filenames);
      program.parse();
    } //catch (TreeWalkException e) {
      //System.err.println("failed to build IR from syntax tree");
      //System.err.println(e);
      //System.exit(1);
    //}
    catch (IOException e) {
      System.err.println("I/O error parsing files");
      System.err.println(e);
      System.exit(1);
    } catch (Exception e) {
      System.err.println("Miscellaneous exception while parsing files: " + e);
      e.printStackTrace();
      System.exit(1);
    }
  }
*/

  protected void parseFiles()
	{
	
    try {
      program = new Program();

      Parser parser = new Parser();

      for(String file : filenames){
            program.addTranslationUnit(parser.parse(file));
      }
    } //catch (TreeWalkException e) {
      //System.err.println("failed to build IR from syntax tree");
      //System.err.println(e);
      //System.exit(1);
    //}
    catch (IOException e) {
      System.err.println("I/O error parsing files");
      System.err.println(e);
      System.exit(1);
    } catch (Exception e) {
      System.err.println("Miscellaneous exception while parsing files: " + e);
      e.printStackTrace();
      System.exit(1);
		}
	}
  /**
   * Prints the list of options that Cetus accepts.
   */
  public void printUsage()
  {
    String usage = "\ncetus.exec.Driver [option]... [file]...\n" +
		"------------------------------------------------------\n";
    usage += options.getUsage();
    System.err.println(usage);
  }

  /**
   * Prints the compiler version.
   */
  public void printVersion()
  {
    System.err.println("Cetus 1.2 - A Source-to-Source Compiler for C");
    System.err.println("http://cetus.ecn.purdue.edu");
    System.err.println("Copyright (C) 2002-2010 ParaMount Research Group");
    System.err.println("Purdue University - School of Electrical & Computer Engineering");
  }

  /**
   * Runs this driver with args as the command line.
   *
   * @param args The command line from main.
   */
  public void run(String[] args)
  {
    parseCommandLine(args);

    parseFiles();

    if (getOptionValue("parse-only") != null)
    {
      System.err.println("parsing finished and parse-only option set");
      System.exit(0);
    }

    runPasses();

    PrintTools.printlnStatus("Printing...", 1);

    try {
      program.print();
    } catch (IOException e) {
      System.err.println("could not write output files: " + e);
      System.exit(1);
    }
  }

  /**
   * Runs analysis and optimization passes on the program.
   */
  public void runPasses()
  {
    /* check for option dependences */

    /* in each set of option strings, the first option requires the
       rest of the options to be set for it to run effectively */
    String[][] pass_prerequisites = {
			{ "inline", "tsingle-call", "tsingle-return" },
			{ "parallelize-loops", "alias", "ddt", "privatize", 
				"reduction", "induction", "ompGen" },
/*
			{ "loop-interchange", "ddt" }
*/
			};

    for (int i = 0; i < pass_prerequisites.length; ++i)
    {
      if (getOptionValue(pass_prerequisites[i][0]) != null)
      {
        for (int j = 1; j < pass_prerequisites[i].length; ++j)
        {
          if (getOptionValue(pass_prerequisites[i][j]) == null)
          {
            System.out.println("WARNING: " + pass_prerequisites[i][0] + " flag is set but " + pass_prerequisites[i][j] + " is not set");
            System.out.println("WARNING: turning on " + pass_prerequisites[i][j]);
            setOptionValue(pass_prerequisites[i][j], "1");
          }
        }
      }
    }

    /* Link IDExpression => Symbol object for faster future access. */
    SymbolTools.linkSymbol((Traversable)program);

		/* Convert the IR to a new one with improved annotation support */
		TransformPass.run(new AnnotationParser(program));
    
    if (getOptionValue("callgraph") != null)
    {
      CallGraph cg = new CallGraph(program);
      cg.print(System.out);
    }

    if (getOptionValue("tsingle-declarator") != null)
    {
      SingleDeclarator.run(program);
    }

    if (getOptionValue("tsingle-call") != null)
    {
      TransformPass.run(new SingleCall(program));
    }

    if (getOptionValue("tsingle-return") != null)
    {
      TransformPass.run(new SingleReturn(program));
    }

    if (getOptionValue("tinline-expansion") != null)
    {
      TransformPass.run(new InlineExpansionPass(program));
    }

    if (getOptionValue("normalize-loops") != null)
    {
      TransformPass.run(new LoopNormalization(program));
    }

    if (getOptionValue("normalize-return-stmt") != null)
    {
    	TransformPass.run(new NormalizeReturn(program));
    }
    
    if (getOptionValue("induction") != null)
    {
      TransformPass.run(new IVSubstitution(program));
    }

    if (getOptionValue("privatize") != null)
    {
			AnalysisPass.run(new ArrayPrivatization(program));
    }

    if (getOptionValue("ddt") != null)
    {
      AnalysisPass.run(new DDTDriver(program));
    }

    if (getOptionValue("reduction") != null)
    {
      AnalysisPass.run(new Reduction(program));
    }

		// CHECK
		/*
    if (getOptionValue("openmp") != null)
    {
      AnalysisPass.run(new OmpAnalysis(program));
    }
		*/

    if (getOptionValue("parallelize-loops") != null)
    {
      AnalysisPass.run(new LoopParallelizationPass(program));
    }

    if (getOptionValue("ompGen") != null)
    {
      CodeGenPass.run(new ompGen(program));
    }

/*
    if (getOptionValue("loop-interchange") != null)
    {
      TransformPass.run(new LoopInterchange(program));
    }

    if (getOptionValue("loop-tiling") != null)
    {
      AnalysisPass.run(new LoopTiling(program));
    }
*/

    if (getOptionValue("profile-loops") != null)
    {
    	TransformPass.run(new LoopProfiler(program));
    }

    if (getOptionValue("fault-injector") != null) {
      TransformPass.run(new FaultInjector(program));
    }
    if (getOptionValue("error-detector") != null) {
      TransformPass.run(new ErrorDetector(program));
    }
    if (getOptionValue("error-detector1pt") != null) {
      TransformPass.run(new ErrorDetector1Pt(program));
    }
    if (getOptionValue("cuda-inj") != null) {
      TransformPass.run(new CudaFaultInjection(program));
    }

  }

  /**
   * Sets the value of the option represented by <i>key</i> to
   * <i>value</i>.
   *
   * @param key The option name.
   * @param value The option value.
   */
  protected static void setOptionValue(String key, String value)
  {
    options.setValue(key, value);
  }

  /**
   * Entry point for Cetus; creates a new Driver object,
   * and calls run on it with args.
   *
   * @param args Command line options.
   */
  public static void main(String[] args)
  {
    (new Driver()).run(args);
  }

}

