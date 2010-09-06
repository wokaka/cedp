/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilLog
{
  public static void Info(String message)
  {
    System.out.println(message);
  }

  public static void Warning(String message)
  {
    System.err.println(message);
  }

  public static void Error(String message)
  {
    System.err.println(message);
  }
}
