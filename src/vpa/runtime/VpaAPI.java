/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package vpa.runtime;

import cedp.node.PerfJavaNode;
import cedp.util.UtilTable;
import cedp.util.extlib.JcraftWrapper;
import cedp.util.extlib.AStyleWrapper;
import cetus.exec.Driver;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JTable;

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

    public static String GetSelectedProgram()
    {
      JTable table = node.GetBenchmarkTable();

      return (String)table.getModel().getValueAt(table.getSelectedRow(), 0);
    }

    public static String GetSelectedData()
    {
      JTable table = node.GetBenchmarkTable();

      return (String)table.getModel().getValueAt(table.getSelectedRow(), 1);
    }

    public static String GetHomeDir()
    {
      return node.GetCurrentDir();
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

    public static String FileRead(String fileName)
    {
        String str = "";

        try{
            BufferedReader file = new BufferedReader(new FileReader(fileName));
            while(file.ready())
                str += file.readLine() + "\n";
        } catch(Exception e){
            e.printStackTrace();
        }

        return str;
    }

    public static String FileCopy(String src, String dst)
    {
        String str = "";

        try{
            File f = new File(dst);

            if(f.exists())
                f.delete();

            BufferedWriter fout = new BufferedWriter(new FileWriter(dst));
            BufferedReader file = new BufferedReader(new FileReader(src));

            while(file.ready()){
                str = file.readLine();
                fout.write(str + "\n");
            }
            
            fout.close();
        } catch(Exception e){
            e.printStackTrace();
        }

        return str;
    }

    public static String GetCurrentDir()
    {
        return node.GetCurrentDir();
    }

    public static String GetCurrentLocalPath()
    {
      try{
        return new java.io.File(".").getCanonicalPath();
        //currentPath = currentPath.substring(0, currentPath.length()-1) + File.pathSeparator;
      } catch(Exception e){
        e.printStackTrace();
      }

      return null;
    }

    public static void RunCetus(String args[])
    {
      Driver cetusDriver = new Driver();
      cetusDriver.run(args);
    }

    public static void Beautifier(String src, String dst)
    {
      AStyleWrapper.Buautifier(src, dst);
    }

    private static BufferedWriter cmdFile;
    private static int cmdIndex;
    
    public static void SetFaultCommand(String fname, boolean begin)
    {
      if(begin){
        node.GetFITable().removeAll();
        cmdIndex = 0;
        try{
          cmdFile = new BufferedWriter(new FileWriter(fname));
        } catch(IOException e){
          e.printStackTrace();
        }
      }
      else{
        try{
          cmdFile.close();
        } catch(IOException e){
          e.printStackTrace();
        }
      }
    }

    public static void AddFaultCommand(String cmd)
    {
      try{
        cmdFile.write(cmd + "\n");
      } catch(Exception e){
        e.printStackTrace();
      }

      Object obj[] = new Object[3];

      obj[0] = (Object) (String)("" + cmdIndex++);
      obj[1] = (Object) (String)(cmd);
      obj[2] = (Object) (String)("");

      UtilTable.AddToTable(node.GetFITable(), obj, false);
    }

    public static String GetFileSeparator()
    {
      return File.separator;
    }
    
    public static String GetSelectedFile()
    {
        return node.GetSelectedFile();
    }

    public static String InputDialog(String msg)
    {
      InputDialog inputDialog = new InputDialog(msg);

      return inputDialog.GetAnswer();
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
