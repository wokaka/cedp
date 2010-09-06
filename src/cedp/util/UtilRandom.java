/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

import java.util.Random;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilRandom
{
  protected static Random random;

  public static long Random(long s, long e)
  {
    if (random == null) {
      random = new Random();
    }

    long result = random.nextLong();

    if (result < 0) {
        result *= -1;
    }

    result %= (e - s + 1);
    result += s;

    return result;
  }

  public static int Random(int start, int end)
  {
    if (random == null) {
      random = new Random();
    }

    int result = random.nextInt();

    if (result < 0) {
      result *= -1;
    }

    result %= end - start + 1;
    result += start;

    return result;
  }
}
