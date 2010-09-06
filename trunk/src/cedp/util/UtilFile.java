/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilFile
{
  public static String Read(String fileName)
  {
    String str = "";

    try{
      File f = new File(fileName);
      if (!f.exists()) {
        return "";
      }

      BufferedReader file = new BufferedReader(new FileReader(fileName));
      while (file.ready()) {
        str += file.readLine() + "\n";
      }
    } catch(Exception e) {
      e.printStackTrace();
    }

    return str;
  }

  public static void Write(String dst, String msg)
  {
    try{
      File f = new File(dst);

      if (f.exists()) {
        f.delete();
      }

      BufferedWriter fout = new BufferedWriter(new FileWriter(dst));
      fout.write(msg);
      fout.close();
    } catch(Exception e){
      e.printStackTrace();
    }
  }

  public static void Copy(String src, String dst)
  {
    Write(dst, Read(src));
  }
}
