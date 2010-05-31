/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util;

import java.sql.Time;
import java.util.Date;

/**
 *
 * @author Keun Soo Yim
 */
public class UtilTime {

    public static String GetCurret()
    {
        long    t = System.currentTimeMillis();
        Date    date = new Date();
        Time    time = new Time(t);
        String  result;
        
        result = date.getYear() + "yr";
        result += "-" + date.getMonth() + "mon";
        result += "-" + date.getDay() + "day";
        result += "-" + time.getHours() + "hr";
        result += "-" + time.getMinutes() + "min";
        result += "-" + time.getSeconds() + "s";
        result += "-" + t % 1000 + "ms";

        return result;
    }
    
    public static String CurrentDateString()
    {
        return (new Date()).toString();
    }

    public static String CurrentTimeString()
    {
        long    t = System.currentTimeMillis();

        return (new Time(t)).toString() + "." + t % 1000;
    }

    public static String TimeString(long t)
    {
        String  result;
        long     day;
        long     hr;
        long     min;
        long     sec;
        long     ms;

        ms = t % 1000;  t /= 1000;
        sec = t % 60;   t /= 60;
        min = t % 60;   t /= 60;
        hr = t % 24;    t /= 24;
        day = t;

        if(day != 0)
            result = "[" + day + "]";
        else
            result = "";

        result += "" + hr + ":" + min + ":" + sec + "." + ms;

        return result;
    }
}
