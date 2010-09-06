/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util.extlib;

import cedp.util.UtilFile;
import org.python.core.PyException;
import org.python.core.PyInteger;
import org.python.core.PyObject;
import org.python.util.PythonInterpreter;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class JythonWrapper
{
  public static String DefaultHeader = "import sys\n" + "from vpa.runtime import VpaAPI\n";

  public static void Exec(String program) throws PyException
  {
    PythonInterpreter interp = new PythonInterpreter();
    interp.exec(DefaultHeader + program);
    /*
    interp.exec("import sys");
    interp.exec("print sys");
    interp.set("a", new PyInteger(42));
    interp.exec("print a");
    interp.exec("x = 2+2");
    PyObject x = interp.get("x");
    System.out.println("x: " + x);
    */
  }

  public static void ExecFile(String fname) throws PyException
  {
    Exec(UtilFile.Read(fname));
  }
}
