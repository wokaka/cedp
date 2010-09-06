/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilString
{
  public static String ParseLine(String s, int no)
  {
    int line = 0;
    int j = 0;
    for (int i=0; i < s.length(); i++) {
      if (s.charAt(i) == '\n') {
        if (line == no) {
          return s.substring(j, i-1);
        }
        j = i + 1;
        line++;
      }
    }

    return null;
  }

  public static int String2Int(String s)
  {
    if (s == null) {
      return 0;
    }

    try {
      return Integer.parseInt(s, 10);
    } catch(Exception e) {
      e.printStackTrace();
    }
    return 0;
  }

  public static double String2Double(String s)
  {
    if (s == null) {
      return 0;
    }

    try {
      return Double.parseDouble(s);
    } catch(Exception e) {
      e.printStackTrace();
    }
    return 0;
  }

  public static long HexStr2Long(String s)
  {
    if (s == null) {
      return 0;
    }

    try {
      return Long.parseLong(s, 16);
    } catch(Exception e){
        e.printStackTrace();
    }
    return 0;
  }

  public static long HexString2Long(String s)
  {
    try {
      return Long.parseLong(s, 16);
    } catch(Exception e) {
      e.printStackTrace();
    }
    return 0;
  }

  public static long String2Long(String s)
  {
    try {
      return Long.parseLong(s, 10);
    } catch(Exception e) {
      e.printStackTrace();
    }
    return 0;
  }

  public static String Long2HexString(long h)
  {
    try {
      return Long.toHexString(h);
    } catch(Exception e) {
      e.printStackTrace();
    }
    return "0";
  }

  public static String Hex2String(int h)
  {
    try {
      return Integer.toHexString(h);
    } catch(Exception e) {
      e.printStackTrace();
    }
    return "0";
  }

  public static boolean IsSameString(String x[], String y[])
  {
    int i;

    if (x == null) {
      if (y == null) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      if (y == null) {
        return false;
      }
      else {
        if (x.length != y.length) {
          return false;
        }

        for (i=0; i < x.length; i++) {
          if (!x[i].equals(y[i])) {
            return false;
          }
        }

        return true;
      }
    }
  }

  public static boolean IsSameInteger(Integer x[], Integer y[])
  {
    if (x == null) {
      if (y == null) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      if (y == null) {
        return false;
      }
      else {
        if (x.length != y.length) {
          return false;
        }

        for (int i=0; i<x.length; i++) {
          if (x[i] != y[i]) {
            return false;
          }
        }

        return true;
      }
    }
  }
}
