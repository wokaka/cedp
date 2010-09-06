/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util.extlib;

import astyle.ASFormatter;
import astyle.ASResource;
import astyle.ASStreamIterator;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Vector;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class AStyleWrapper
{
  public static boolean Buautifier(String src, String dst)
  {
    ASFormatter formatter = new ASFormatter();
    Vector fileNameVector = new Vector();
    Vector optionsVector = new Vector();
    boolean ok;

    // manage flags
    formatter.setBracketIndent(false);
    formatter.setSpaceIndentation(4);
    formatter.setBracketFormatMode(ASResource.BREAK_MODE);
    formatter.setClassIndent(false);
    formatter.setSwitchIndent(false);
    formatter.setNamespaceIndent(false);

    File srcFile = new File(src);
    File dstFile = new File(dst);

    if (dstFile.exists() && !dstFile.delete()) {
      System.err.println("Could not delete file " + dstFile.toString());
      return false;
    }

    BufferedReader in = null;
    try {
      in = new BufferedReader(new FileReader(srcFile));
    } catch (FileNotFoundException fnfex) {
      System.err.println("Could not open input file " + srcFile.toString());
      return false;
    }

    BufferedWriter out = null;
    try {
      out = new BufferedWriter(new FileWriter(dstFile));
    } catch (IOException ioex) {
      System.err.println("Could not open output file " + dstFile.toString());
      return false;
    }

    // Unless a specific language mode has been, set the language
    // mode according to the file's suffix.
    /*
    if (!_modeManuallySet) {
        if (origFileName.endsWith(".java")) {
            formatter.setCStyle(false);
        } else {
            formatter.setCStyle(true);
        }
    }
    */

    formatter.init(new ASStreamIterator(in));
    try {
      while (formatter.hasMoreLines()) {
        String line = formatter.nextLine();
        out.write(line, 0, line.length());
        if (formatter.hasMoreLines()) {
          out.newLine();
        }
      }
      out.flush();
    } catch(IOException ioex) {
      System.err.println("Could not write to output file " + dstFile.toString());
      return false;
    }

    try {
      out.close();
    } catch (IOException ioex) {
      ioex.printStackTrace();
    }
    
    try {
      in.close();
    } catch (IOException ioex) {
      ioex.printStackTrace();
    }

    return true;
  }
}
