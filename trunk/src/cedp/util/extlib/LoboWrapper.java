/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util.extlib;

import java.awt.Component;
import java.awt.event.WindowEvent;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.border.EtchedBorder;
import org.lobobrowser.gui.BrowserPanel;
import org.lobobrowser.gui.FramePanel;
import org.lobobrowser.gui.NavigationAdapter;
import org.lobobrowser.main.PlatformInit;
import org.lobobrowser.ua.NavigationEvent;
import org.lobobrowser.ua.NavigationVetoException;
import org.w3c.dom.html.HTMLElement;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class LoboWrapper extends JFrame
{
  public void Launch() throws Exception {
    // This optional step initializes logging so only warnings
    // are printed out.
    PlatformInit.getInstance().initLogging(false);

    // This step is necessary for extensions to work:
    PlatformInit.getInstance().init(false, false);

    // Create frame with a specific size.
    JFrame frame = new LoboTestFrame();
    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    frame.setSize(600, 400);
    frame.setVisible(true);
  }

  public void Launch2() throws Exception {
    // Initialize logging.
    PlatformInit.getInstance().initLogging(false);

    // This step is necessary for extensions to work:
    PlatformInit.getInstance().init(false, false);

    // Create frame with a specific size.
    JFrame frame = new BrowserPanelTest();
    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    frame.setSize(600, 400);
    frame.setVisible(true);
  }

  public static void main(String args[]) throws Exception {
    // Initialize logging.
    PlatformInit.getInstance().initLogging(false);

    // This step is necessary for extensions to work:
    PlatformInit.getInstance().init(false, false);

    // Create frame with a specific size.
    JFrame frame = new LoboWrapper();
    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    frame.setSize(600, 400);
    frame.setVisible(true);
  }

  public LoboWrapper() throws Exception {
    this.setTitle("Lobo Demo");
    final BrowserPanel bp = new BrowserPanel();
    bp.setBorder(BorderFactory.createTitledBorder(new EtchedBorder(EtchedBorder.RAISED), "Embedded browser"));
    bp.navigate("http://googole.com");
    this.getContentPane().add(bp);

    this.addWindowListener(new java.awt.event.WindowAdapter() {

      public void windowClosing(WindowEvent e) {
        // This needs to be called in order
        // to inform extensions about the
        // window closing.
        bp.windowClosing();
      }
    });
  }

  public class LoboTestFrame extends JFrame {

    public LoboTestFrame() throws Exception {
      FramePanel framePanel = new FramePanel();
      this.getContentPane().add(framePanel);
      framePanel.navigate("http://lobobrowser.org/browser/home.jsp");
    }
  }

  public class BrowserPanelTest extends JFrame {

    public BrowserPanelTest() throws Exception {
      this.setTitle("Lobo Demo");
      final BrowserPanel bp = new BrowserPanel();
      bp.setBorder(BorderFactory.createTitledBorder(new EtchedBorder(EtchedBorder.RAISED), "Embedded browser"));
      bp.navigate("http://google.com");
      this.getContentPane().add(bp);

      this.addWindowListener(new java.awt.event.WindowAdapter() {

        public void windowClosing(WindowEvent e) {
          // This needs to be called in order
          // to inform extensions about the
          // window closing.
          bp.windowClosing();
        }
      });
    }
  }

  public void Launch3() throws Exception {
    // We'll disable all logging but WARNING.
    Logger.getLogger("org.lobobrowser").setLevel(Level.WARNING);

    // This step is necessary for extensions (including HTML) to work:
    PlatformInit.getInstance().init(false, false);

    // Create window with a specific size.
    JFrame frame = new VetoableNavigationDemo();
    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    frame.setSize(600, 400);
    frame.setVisible(true);
  }

  public class VetoableNavigationDemo extends JFrame {

    private final BrowserPanel browserPanel;

    public VetoableNavigationDemo() throws Exception {
      this.setTitle("Lobo Vetoable Navigation Demo");

      // Create a BrowserPanel and set a default home page.
      final BrowserPanel bp = new BrowserPanel();
      this.browserPanel = bp;
      bp.navigate("http://google.com");

      // Add a navigation listener.
      bp.addNavigationListener(new LocalNavigationListener());
      bp.setSize(500, 500);
      // Add top-level components to window.
      this.setLayout(null);
      ///this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

      this.add(bp);

      this.addWindowListener(new java.awt.event.WindowAdapter() {

        public void windowClosing(WindowEvent e) {
          // This needs to be called in order
          // to inform extensions about the
          // window closing.
          bp.windowClosing();
        }
      });
    }

    private class LocalNavigationListener extends NavigationAdapter {

      @Override
      public void beforeLocalNavigate(NavigationEvent event) throws NavigationVetoException {
        Object linkObject = event.getLinkObject();
        if (linkObject instanceof HTMLElement) {
          HTMLElement linkElement = (HTMLElement) linkObject;
          String rel = linkElement.getAttribute("rel");
          if ("nofollow".equalsIgnoreCase(rel)) {
            Component dialogParent = event.getOriginatingFrame().getComponent();
            int response = JOptionPane.showConfirmDialog(dialogParent, "This is a rel='nofollow' link. Are you sure you want to continue?", "Please Confirm", JOptionPane.YES_NO_OPTION);
            if (response != JOptionPane.YES_OPTION) {
              throw new NavigationVetoException();
            }
          }
        }
      }
    }
  }
}
