package cetus.exec;

import java.io.*;

import cetus.base.grammars.*;
import cetus.hir.TranslationUnit;
import java.lang.reflect.Array;

public class Parser {

    /** This nested class continuously reads from the output
     * or error stream of an external parser and reproduces
     * the data on the JVM's output or error stream.
     */
    private class PipeThread extends Thread {

        private BufferedReader source;
        private PrintStream dest;

        PipeThread(BufferedReader source, PrintStream dest) {
            this.source = source;
            this.dest = dest;
        }

        public void run() {
            String s = null;
            try {
                while ((s = source.readLine()) != null) {
                    dest.println(s);
                }
            } catch (IOException e) {
                dest.println("cetus: I/O error on redirection, " + e);
            }
        }
    }

    /**
     * Parse this translation unit.
     *
     * @throws IOException if there is a problem accessing any file.
     */
    @SuppressWarnings("all")
    public TranslationUnit parse(String input_filename) throws IOException {
        return parseAntlr(input_filename);
        /**
         * If you want to add another parser other than antlr, then you need to modify
         * parseExternal routine below for your purpose and update the cetus manual
         *
        if (Driver.getOptionValue("antlr") != null)
        parseAntlr();
        else
        parseExternal();
         */
    }

    /**
     * Parse the associated input file using the Antlr
     * parser and create IR for this translation unit.
     *
     * @throws IOException if there is any problem accessing the file.
     */
    protected TranslationUnit parseAntlr(String input_filename) {
        String currfile = input_filename;
        TranslationUnit tu = new TranslationUnit(input_filename);
        String filename = null;
        @SuppressWarnings("unused")
        File f = null, myf = null;
        byte[] barray = null;
        //InputStream source = null;
        // pre step to handle header files
        // Insert markers for start and end of a header file
        String prename = null;

        /* Create the Antlr-derived lexer and parser through the ClassLoader
        so antlr.jar will be required only if the Antlr parser is used. */

        Class<?>[] params = new Class<?>[1];
        Object[] args = new Object[1];

        try {
            Class<?> class_PreCLexer = getClass().getClassLoader().loadClass("cetus.base.grammars.PreCLexer");
            params[0] = InputStream.class;
            String userDir = System.getProperty("user.dir");
            String currentPath = new java.io.File(".").getCanonicalPath();
            args[0] = new DataInputStream(new FileInputStream(currfile));
            PreCLexer lexer = (PreCLexer) class_PreCLexer.getConstructor(params).newInstance(args);

            Class<?> class_PreCParser = getClass().getClassLoader().loadClass("cetus.base.grammars.PreCParser");
            params[0] = getClass().getClassLoader().loadClass("antlr.TokenStream");
            args[0] = lexer;
            PreCParser parser = (PreCParser) class_PreCParser.getConstructor(params).newInstance(args);

            File dir = new File(".");
            String currdir = dir.getCanonicalPath();

            File ff = new File(currfile);
            filename = ff.getName();
            prename = "cppinput_" + filename;
            myf = new File(currdir, prename);
//            myf.deleteOnExit();
            FileOutputStream fo = new FileOutputStream(myf);
            parser.programUnit(new PrintStream(fo));
            fo.close();
        } catch (ClassNotFoundException e) {
            System.err.println("cetus: could not load class " + e);
            System.exit(1);
        } catch (NoSuchMethodException e) {
            System.err.println("cetus: could not find constructor " + e);
            System.exit(1);
        } catch (IllegalAccessException e) {
            System.err.println("cetus: could not access constructor " + e);
            System.exit(1);
        } catch (InstantiationException e) {
            System.err.println("cetus: constructor failed " + e);
            System.exit(1);
        } catch (FileNotFoundException e) {
            System.err.println("cetus: could not read input file " + e);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("cetus: could not create intermdiate output file " + e);
            System.exit(1);
        } catch (Exception e) {
            System.err.println("cetus: exception: " + e);
            e.printStackTrace();
            System.exit(1);
        }

        // Run cpp on the input file and output to a temporary file.
        try {
            ByteArrayOutputStream bo = new ByteArrayOutputStream(50000);
            PrintStream outStream = new PrintStream(bo);

            //String cmd = Driver.getOptionValue("preprocessor") + " " + prename;
            String cmd = Driver.getOptionValue("preprocessor");
            cmd += getMacros() + " " + prename;
            //Process p = Runtime.getRuntime().exec(cmd);
            System.out.println("Preprocessor command : " + cmd);
            Process p = Runtime.getRuntime().exec(cmd, null, new File(System.getProperty("user.dir")));

            BufferedReader inReader = new BufferedReader(new InputStreamReader(p.getInputStream()));
            BufferedReader errReader = new BufferedReader(new InputStreamReader(p.getErrorStream()));

            PipeThread out_pipe = new PipeThread(inReader, outStream);
            PipeThread err_pipe = new PipeThread(errReader, System.err);

            out_pipe.start();
            err_pipe.start();

            if (p.waitFor() != 0) {
                System.err.println("cetus: preprocessor terminated with exit code " + p.exitValue());
                System.exit(1);
            }

            out_pipe.join();
            err_pipe.join();

            barray = bo.toByteArray();
            //----------------
            System.out.println("================================");
            System.out.println("Preproc ");
            System.out.println("================================");
            System.out.write(barray, 0, Array.getLength(barray));
            System.out.println("================================");
            System.out.println("Preproc ");
            System.out.println("================================");
        } catch (java.io.IOException e) {
            System.err.println("Fatal error creating temporary file: " + e);
            System.exit(1);
        } catch (java.lang.InterruptedException e) {
            System.err.println("Fatal error starting preprocessor: " + e);
            System.exit(1);
        }

        // Actual antlr parser is called
        try {
            Class<?> class_NewCLexer = getClass().getClassLoader().loadClass("cetus.base.grammars.NewCLexer");
            params[0] = InputStream.class;
            args[0] = new DataInputStream(new ByteArrayInputStream(barray));
            NewCLexer lexer = (NewCLexer) class_NewCLexer.getConstructor(params).newInstance(args);

            lexer.setOriginalSource(filename);
            lexer.setTokenObjectClass("cetus.base.grammars.CToken");
            lexer.initialize();

            Class<?> class_NewCParser = getClass().getClassLoader().loadClass("cetus.base.grammars.NewCParser");
            params[0] = getClass().getClassLoader().loadClass("antlr.TokenStream");
            args[0] = lexer;
            NewCParser parser = (NewCParser) class_NewCParser.getConstructor(params).newInstance(args);

            parser.getPreprocessorInfoChannel(lexer.getPreprocessorInfoChannel());
            parser.setLexer(lexer);
            parser.translationUnit(tu);
        } catch (Exception e) {
            System.err.println("Antlr Parse error: " + e);
            System.exit(1);
        }

        try {
            Class<?>[] pparams = new Class<?>[2];
            pparams[0] = TranslationUnit.class;
            pparams[1] = OutputStream.class;
            tu.setPrintMethod(pparams[0].getMethod("defaultPrint2", pparams));
        } catch (NoSuchMethodException e) {
            throw new InternalError();
        }
        return tu;
    }

    // Reads option value from -macro and returns a converted string to be added
    // in the preprocessor cmd line.
    protected static String getMacros() {
        String ret = " ";
        String macro = Driver.getOptionValue("macro");
        if (macro == null) {
            return ret;
        }

        String[] macro_list = macro.split(",");
        for (int i = 0; i < macro_list.length; i++) {
            ret += (" -D" + macro_list[i]);
        }

        return ret;
    }
}
