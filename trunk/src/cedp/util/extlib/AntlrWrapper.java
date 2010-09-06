/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util.extlib;

import java.lang.reflect.InvocationTargetException;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class AntlrWrapper
{
  public void GenerateVpaParser() throws ClassNotFoundException, NoSuchMethodException, InstantiationException, IllegalAccessException, InvocationTargetException
  {
    Class class_Tool = getClass().getClassLoader().loadClass("org.antlr.Tool");
    Class[] params = new Class[1];
    params[0] = String[].class;
    Object[][] args = new Object[1][];
    args[0] = new String[1];

    /* Parsers for VPA */
    args[0][0] = "src/vpa/interpreter/Vpa.g";
    org.antlr.Tool antlr = (org.antlr.Tool) class_Tool.getConstructor(params).newInstance(args);
    antlr.process(); /* generates VpaLexer.java */
  }

  public void GenerateVpaParserOld() throws ClassNotFoundException, NoSuchMethodException, InstantiationException, IllegalAccessException, InvocationTargetException
  {
    Class[] params = new Class[1];
    Object[][] args = new Object[1][];
    Class class_Tool = getClass().getClassLoader().loadClass("org.antlr.Tool");
    params[0] = String[].class;
    args[0] = new String[1];

    /* Parsers for VPA */
    args[0][0] = "src/vpa/interpreter/VpaLexer.g";
    org.antlr.Tool antlr = (org.antlr.Tool)class_Tool.getConstructor(params).newInstance(args);
    antlr.process(); /* generates VpaLexer.java */
    /* TODO: now the package of VpaLexer.java shall be manually added after executing this generation step */

    args[0][0] = "src/vpa/interpreter/VpaParser.g";
    antlr = (org.antlr.Tool)class_Tool.getConstructor(params).newInstance(args);
    antlr.process(); /* generates VpaLexer.java */

    args[0][0] = "src/vpa/interpreter/VpaTreeParser.g";
    antlr = (org.antlr.Tool)class_Tool.getConstructor(params).newInstance(args);
    antlr.process(); /* generates VpaLexer.java */
  }

  public void GenerateJavaParser() throws ClassNotFoundException, NoSuchMethodException,
      InstantiationException, IllegalAccessException, InvocationTargetException
  {
    Class[] params = new Class[1];
    Object[][] args = new Object[1][];
    org.antlr.Tool antlr;
    Class class_Tool = getClass().getClassLoader().loadClass("org.antlr.Tool");
    params[0] = String[].class;
    args[0] = new String[1];

    /* Parsers for CETUS Java Front-End */
    args[0][0] = "src/cedp/src2src/frontend/java/Java.g";
    antlr = (org.antlr.Tool)class_Tool.getConstructor(params).newInstance(args);
    antlr.process(); /* generates VpaLexer.java */
  }
}
