/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package vpa.runtime;

import cedp.node.PerfJavaNode;
import cedp.src2src.frontend.java.JavaLexer;
import cedp.src2src.frontend.java.JavaParser;
import cedp.util.extlib.JcraftWrapper;
import cedp.util.UtilFile;
import cedp.util.extlib.CetusWrapper;
import java.util.Vector;
import org.antlr.runtime.ANTLRFileStream;
import org.antlr.runtime.CharStream;
import org.antlr.runtime.CommonTokenStream;

/**
 *
 * @author yim
 */
public class VpaAPI {
    /* Intefaces for Java */
    protected static PerfJavaNode node;

    public static void SetNode(PerfJavaNode n)
    {
        node = n;
    }

    /* Interfaces for Jython */
    public static void ExecCmd(String cmd)
    {
//        System.out.println("** " + cmd);
        JcraftWrapper net = JcraftWrapper.GetLatest();
        net.RunCommandBlocked(cmd);
    }

    public static void RxFile(String src, String dst)
    {
        JcraftWrapper net = JcraftWrapper.GetLatest();
        net.FtpBlocked(src, dst, net.FtpGet);
    }

    public static void TxFile(String src, String dst)
    {
        JcraftWrapper net = JcraftWrapper.GetLatest();
        net.FtpBlocked(src, dst, net.FtpPut);
    }

    public static String GetCurrentDir()
    {
        return node.GetCurrentDir();
    }

    public static String GetSelectedFile()
    {
        return node.GetSelectedFile();
    }

    public static void Src2Src(String fname, String cmd)
    {
        if(cmd.equals("extract-java")){
            Vector opts = new Vector();
            //opts.add("");
            CetusWrapper.Run(fname, opts, false);
            
            /*
            String args[] = null;

            args = new String[2];
            args[0] = "-" + cmd;
            args[1] = fname;

            Driver cetusDriver = new Driver();
            cetusDriver.run(args);
            */
            /* C beautifier for instrumented code */
            //AStyleWrapper.Buautifier(fname, fname + ".beauty");
            //AStyleWrapper.Buautifier("cetus_output" + File.separator + fname, "cetus_output" + File.separator + fname + ".beauty");

            /* direct invokcation */
            /*
            try{
                CharStream input = new ANTLRFileStream(fname);
                JavaLexer lexer = new JavaLexer(input);

                CommonTokenStream tokens = new  CommonTokenStream(lexer);
                JavaParser parser = new JavaParser(tokens);

                String[] tokennames = parser.tokenNames;
//                for(int i=0; i<tokennames.length; i++)
//                    System.out.println(""+tokennames[i]);
                //                JavaParser.document_return root = parser..document();
//                System.out.println("tree="+parser.toString());
                parser.compilationUnit();
            } catch(Exception e){
                e.printStackTrace();
            }
            */
        }
    }

    public static void ViewSource(String fname)
    {
        node.SetSource(UtilFile.Read(fname));
    }
}
