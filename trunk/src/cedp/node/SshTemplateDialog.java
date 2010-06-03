/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.node;

import cedp.util.JcraftWrapper;
import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelSftp;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.Session;
import com.jcraft.jsch.SftpProgressMonitor;
import java.awt.Dimension;
import java.awt.Toolkit;
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
public class SshTemplateDialog extends JFrame
{
    public SshTemplateDialog()
    {
        super();
    }

}
