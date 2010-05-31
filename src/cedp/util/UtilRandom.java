/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util;

import java.util.Random;

/**
 *
 * @author Keun Soo Yim
 */
public class UtilRandom {

    protected static Random   random;

    public static long Random(long s, long e)
    {
        long     result;

        if(random == null)
            random = new Random();

        result = random.nextLong();

        if(result < 0)
            result *= -1;

        result %= (e - s + 1);
        result += s;

        return result;
    }


    public static int Random(int s, int e)
    {
        int     result;

        if(random == null)
            random = new Random();

        result = random.nextInt();

        if(result < 0)
            result *= -1;

        result %= (e - s + 1);
        result += s;

        return result;
    }
}
