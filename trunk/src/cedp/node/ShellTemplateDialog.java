/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.node;

package

import java.io.InputStreamReader;
import java.io.PrintStream;
import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelSftp;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.Session;
import com.jcraft.jsch.SftpProgressMonitor;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Vector;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.ProgressMonitor;
import javax.swing.SwingUtilities;

/**
 *
 * @author Keun Soo Yim
 */
public class ShellTemplateDialog extends JFrame implements Runnable
{
    protected String nodeName;

    public ShellTemplateDialog()
    {
        super();
    }

    public ShellTemplateDialog(String name)
    {
        super();
        nodeName = name;
    }

    protected Thread    thread;
    protected String    address;
    protected int       port;
    protected String    id;
    protected String    pwd;
    protected Channel channel;
    protected ChannelSftp channelFtp;

    protected JTextArea consoleArea;


    public void Launch(String pAddr, int pPort, String pId, String pPwd)
    {
        address = pAddr;
        port = pPort;
        id = pId;
        pwd = pPwd;

        Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension window = getSize();

        setLocation(screen.width/2 - window.width/2, screen.height/2 - window.height/2);

        thread = new Thread(this);
        thread.start();
    }

    private class PipeThread implements Runnable
    {
        private BufferedReader source;
        protected Thread thread;

        PipeThread(BufferedReader s)
        {
            source = s;
            thread = new Thread(this);
            thread.start();
        }

        public void run()
        {
            char buf[] = new char[1];
            
            try {
                System.out.print("Enter");
                while(source.read(buf, 0, 1) == 1){
                    consoleArea.append(""+buf[0]);
                    System.out.print("O " + buf[0]);
                }
                System.out.print("Exit");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    PrintStream parser_stdin;
  
    public void run()
    {
        /* 1: create ssh session */
        try {
            Process p = Runtime.getRuntime().exec("ssh -l " + id + " " + address + " -p " + port);

            /* read the parser's output stream */
            /* Note: Yes, this is reading the output stream even though it says getInputStream.
             Sun's naming conventions are weird like that. */
            BufferedReader parser_stdout = new BufferedReader(new InputStreamReader(p.getInputStream()));

            /* read the parser's error stream */
            BufferedReader parser_stderr = new BufferedReader(new InputStreamReader(p.getErrorStream()));

//            parser_stdin = new PrintStream(p.getOutputStream());

            /* Redirect all output from the parser to the JVM's output and error streams. */
            PipeThread out_pipe = new PipeThread(parser_stdout);
            PipeThread err_pipe = new PipeThread(parser_stderr);


            /* Wait on the parser to finish. */
/*            if (p.waitFor() != 0)
            {
                System.err.println("cetus: parser terminated with exit code " + p.exitValue());
                System.exit(1);
            }*/

            //out_pipe.join();
            //err_pipe.join();
        } catch (Exception e) {
            System.err.println("cetus: interrupted waiting for parser to finish");
        }

        /* 2: redirect console to a JTextArea */
        //System.setOut(new PrintStream(new CmdOutputStream(cmdConsoleArea), true));
        //System.setErr(new PrintStream(new CmdOutputStream(cmdConsoleArea), true));

        show();
    }

    protected void Wait(int ms)
    {
        try{
            Thread.sleep(ms);
        } catch(Exception e){
            e.printStackTrace();
        }
    }
}
