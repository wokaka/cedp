/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilInteger
{
  public static int Int(byte b0, byte b1)
  {
    int i0 = b0;
    i0 &= 0xFF;

    int i1 = b1;
    i1 <<= 8;
    i1 &= 0x0000FF00;

    return ((i0 | i1) & 0xFFFF);
  }

  public static int Int(byte b0, byte b1, byte b2, byte b3)
  {
    int i0 = b0;
    i0 &= 0xFF;

    int i1 = b1;
    i1 <<= 8;
    i1 &= 0x0000FF00;

    int i2 = b2;
    i2 <<= 16;
    i2 &= 0x00FF0000;

    int i3 = b3;
    i3 <<= 24;
    i3 &= 0xFF000000;

    return (i0 | i1 | i2 | i3);
  }

  public static int Integer2Int(Integer i)
  {
    try{
      return i.intValue();
    } catch(Exception e){
      e.printStackTrace();
    }
    return 0;
  }

  public static int Min(int x, int y)
  {
    if (x<y) {
      return x;
    }
    return y;
  }
}
