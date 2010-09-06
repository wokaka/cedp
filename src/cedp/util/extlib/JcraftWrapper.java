/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util.extlib;

import cedp.util.UtilLog;
import cedp.util.UtilThread;
import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelSftp;
import com.jcraft.jsch.ChannelShell;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.Session;
import com.jcraft.jsch.SftpProgressMonitor;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Vector;
import javax.swing.JTextArea;
import javax.swing.ProgressMonitor;
import javax.swing.SwingUtilities;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class JcraftWrapper
{
  protected JcraftInputStream is;
  protected JcraftOutputStream os;
  protected Channel channelSh;
  protected ChannelSftp channelFtp;
  protected static JcraftWrapper latest;

  public JcraftWrapper(final String address, final int port, final String id, final String pwd,
      JTextArea area)
  {
    is = new JcraftInputStream();
    os = new JcraftOutputStream(area);

    new UtilThread(null) {
      public void run() {
        Connect(address, port, id, pwd);
      }
    };

    latest = this;
  }

  public static JcraftWrapper GetLatest()
  {
    return latest;
  }

  public void Connect(String address, int port, String id, String pwd)
  {
    /* create ssh/sftp sessions */
    try{
      JSch jsch=new JSch();
      //java.util.Properties config = new java.util.Properties();

      System.out.println("Connect to " + id + "@" + address + ":" + port + " via SSH");
      //jsch.setKnownHosts("/home/foo/.ssh/known_hosts");
      Session session=jsch.getSession(id, address, port);
//    session.setConfig(config);
      session.setPassword(pwd);

      //UserInfo ui=new MyUserInfo();
      //session.setUserInfo(ui);
      session.setConfig("StrictHostKeyChecking", "no");

      session.connect(30000);   // making a connection with timeout.

      channelSh = session.openChannel("shell");
      channelFtp = (ChannelSftp) session.openChannel("sftp");

      // Enable agent-forwarding.
      //((ChannelShell)channel).setAgentForwarding(true);

      //  channel.setInputStream(System.in);
      channelSh.setInputStream(is);
      channelSh.setOutputStream(os);

      /*
      // a hack for MS-DOS prompt on Windows.
      channel.setInputStream(new FilterInputStream(System.in){
          public int read(byte[] b, int off, int len)throws IOException{
            return in.read(b, off, (len>1024?1024:len));
          }
      });
      */

      // Choose the pty-type "vt102".
      ((ChannelShell)channelSh).setPtySize(8000, 30, 8000*10, 30*20);

      /*
      // Set environment variable "LANG" as "ja_JP.eucJP".
      ((ChannelShell)channel).setEnv("LANG", "ja_JP.eucJP");
      */

      //channel.connect();
      channelSh.connect(3*1000);
      channelFtp.connect(3*1000);
    } catch(Exception e){
      System.out.println(e);
    }
  }

  public void RunCommandCallback(String cmd)
  {
  }

  public void RunCommandBlocked(final String cmd)
  {
    System.out.println("Start " + cmd);
    is.AddCommand(cmd + "\n");
    os.WaitCommand(cmd + "\n");
    Thread.currentThread().suspend();
  }

  public final int FtpGet = 1;
  public final int FtpPut = 2;

  public void FtpBlocked(String src, String dst, int rw)
  {
    //System.out.println("File " + ((rw==FtpGet)?"Get":"Put"));
    //System.out.println("    From: " + src);
    //System.out.println("    To  : " + dst);
    CustomProgressMonitor monitor;

    try{
      monitor = new CustomProgressMonitor(Thread.currentThread());
      if (rw == FtpGet) {
        /* File f = new File(dst);
        if(f.exists())
            f.delete(); */
        int mode = ChannelSftp.OVERWRITE;
        /*
        if(cmd.equals("get-resume")){
            mode=ChannelSftp.RESUME;
        }
        else if(cmd.equals("get-append")){
            mode=ChannelSftp.APPEND;
        }
        */
        channelFtp.get(src, dst, monitor, mode);
      }
      else {
        int mode = ChannelSftp.OVERWRITE;
      //if(cmd.equals("put-resume")){ mode=ChannelSftp.RESUME; }
      //else if(cmd.equals("put-append")){ mode=ChannelSftp.APPEND; }
        channelFtp.put(src, dst, monitor, mode);
      }

      UtilLog.Info("FTP Start");
      if(monitor.GetThread() != null) {
        Thread.currentThread().suspend();
      }
    } catch(Exception e){
      UtilLog.Info(e.toString());
    }
  }

  public static class CustomProgressMonitor implements SftpProgressMonitor
  {
    ProgressMonitor monitor;
    long count = 0;
    long max = 0;
    Thread pthread;

    public CustomProgressMonitor(Thread t)
    {
      pthread = t;
    }

    public Thread GetThread()
    {
      return pthread;
    }

    public void init(int op, String src, String dest, long max) {
      this.max = max;
      monitor = new ProgressMonitor(null, ((op == SftpProgressMonitor.PUT)? "put" : "get") +
          ": " + src, "", 0, (int) max);
      count = 0;
      percent = -1;
      monitor.setProgress((int) this.count);
      monitor.setMillisToDecideToPopup(1000);
    }
    
    private long percent = -1;

    public boolean count(long count)
    {
        this.count += count;

        if (percent >= this.count * 100 / max)
        {
            return true;
        }
        percent = this.count * 100 / max;

        monitor.setNote("Completed " + this.count + "(" + percent + "%) out of " + max + ".");
        monitor.setProgress((int) this.count);

        return !(monitor.isCanceled());
    }

    public void end()
    {
      monitor.close();
      if (pthread != null) {
        pthread.resume();
        pthread = null;
        UtilLog.Info("FTP End");
      }
    }
  }

  public class JcraftInputStream extends InputStream
  {
    Vector vec;
    int pos;
    int count;

    public JcraftInputStream()
    {
      vec = new Vector();
      pos = 0;
      count = 0;
    }

    public void AddCommand(String cmd)
    {
      vec.addElement(cmd);
      count += cmd.length();
    }

    public int available() throws IOException
    {
      return count;
    }

    public int read() throws IOException
    {
      int result = -1;

      if (vec == null) {
        return -1;
      }

      while (true) {
        if (vec.isEmpty()) {
          return -1;
        }

        String cmd = (String)vec.elementAt(0);
        if (pos >= cmd.length()) {
          vec.removeElementAt(0);
          pos = 0;
          continue;
        }
        result = cmd.charAt(pos);
        pos++;
        count--;
        break;
      }

      return result;
    }

    /* an over rided function which does not return -1. */
    public int read(byte b[], int off, int len) throws IOException
    {
      if (b == null) {
        throw new NullPointerException();
      }
      else if (off < 0 || len < 0 || len > b.length - off) {
        throw new IndexOutOfBoundsException();
      }
      else if (len == 0) {
        return 0;
      }

      int c = read();
      if (c == -1) {
        return 0;
      }
      b[off] = (byte)c;

      int i = 1;
      try {
        for (; i < len ; i++) {
          c = read();
          if (c == -1) {
            break;
          }
          b[off + i] = (byte) c;
        }
      } catch (IOException ee) {
        UtilLog.Info(ee.getMessage());
      }
      return i;
    }
  }

  public class JcraftOutputStream extends OutputStream
  {
    JTextArea   textArea;
    int pos;
    char cmd[];
    Thread thread;
    int cmdsent = 0;

    public JcraftOutputStream(JTextArea t)
    {
      textArea = t;
      pos = -1;
    }

    public synchronized void WaitCommand(String c)
    {
      if (pos != -1) {
        UtilLog.Info("Jcraft: retry after when the previous thread completes");
        return;
      }

      pos = 0;
      cmd = new char[c.length()];
      c.getChars(0, c.length(), cmd, 0);
      thread = Thread.currentThread();
      cmdsent = 0;
    }

    public void write(int b) //minimum implementation of an OutputStream
    {
      byte[] bs = new byte[1];
      bs[0] = (byte) b;

      String bstr = new String(bs);
      if (bstr.isEmpty()) {
        return;
      }

      textArea.append(bstr);
      textArea.setCaretPosition(textArea.getText().length()-1);
      //AsyncUpdate(bstr);
      if(pos != -1){
//    System.out.println("" + pos + " - " + bstr + " - " + b + " maxpos " + cmd.length);
        if(cmdsent != 0){
          cmdsent++;
          if(cmdsent > 3){
            // command sent and we have another output meaning that the command is executed because we forward the output of command to a file
            System.out.println("End ");
            thread.resume();
            pos = -1;
          }
        }
        else{
          if(b == cmd[pos]){
            pos++;
            if(pos == cmd.length-1){
              cmdsent = 1;
            }
          }
          else{
            pos = 0;
          }
        }
      }
    }

    private void AsyncUpdate(final String text)
    {
      SwingUtilities.invokeLater(new Runnable() {
        public void run() {
          textArea.append(text);
          textArea.setCaretPosition(textArea.getText().length()-1);
        }
      });
    }
  }

  /*
  public static InputStream GetInputStream(final String cmd)
  {
    return new InputStream(){
      String s = cmd;
      int inPtr=0;
      public int read()  //minimum implementation of an InputStream
      {
        if( inPtr >= s.length() ) {
          return -1;
        }
        else {
          inPtr++;
          return s.charAt(inPtr-1);
        }
      }  //read
    };  //InputStream
  }
  */
}
