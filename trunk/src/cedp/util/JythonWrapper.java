/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util;

import org.python.core.PyException;
import org.python.core.PyInteger;
import org.python.core.PyObject;
import org.python.util.PythonInterpreter;

/**
 *
 * @author yim
 */
public class JythonWrapper {

    public static void Exec(String program) throws PyException
    {
        PythonInterpreter interp = new PythonInterpreter();
        interp.exec(program);
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
