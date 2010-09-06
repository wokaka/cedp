/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.ClipboardOwner;
import java.awt.datatransfer.Transferable;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.awt.Toolkit;
import java.io.*;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public final class UtilClipboard implements ClipboardOwner {
  /**
   * Empty implementation of the ClipboardOwner interface.
   */
  public void lostOwnership(Clipboard aClipboard, Transferable aContents) {
    // do nothing
  }

  /**
   * Place a String on the clipboard, and make this class the
   * owner of the Clipboard's contents.
   */
  public static void Set(String aString) {
    StringSelection stringSelection = new StringSelection(aString);
    Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
    clipboard.setContents(stringSelection, new UtilClipboard());
  }

  /**
   * Gets the String residing on the clipboard.
   *
   * @return any text found on the Clipboard; if none found, return an
   * empty String.
   */
  public static String Get() {
    String result = "";
    Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
    
    //odd: the Object param of getContents is not currently used
    Transferable contents = clipboard.getContents(null);
    
    boolean hasTransferableText = (contents != null) &&
        contents.isDataFlavorSupported(DataFlavor.stringFlavor);
    
    if (hasTransferableText) {
      try {
        result = (String) contents.getTransferData(DataFlavor.stringFlavor);
      } catch (UnsupportedFlavorException ex) {
        //highly unlikely since we are using a standard DataFlavor
        ex.printStackTrace();
      } catch (IOException ex) {
        ex.printStackTrace();
      }
    }
    
    return result;
  }
}