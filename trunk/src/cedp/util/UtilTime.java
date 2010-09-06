/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

import java.sql.Time;
import java.util.Date;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilTime
{
  public static String GetCurret()
  {
    long t = System.currentTimeMillis();
    Date date = new Date();
    Time time = new Time(t);

    String result = date.getYear() + "yr";
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
    long ms = t % 1000;  t /= 1000;
    long sec = t % 60;   t /= 60;
    long min = t % 60;   t /= 60;
    long hr = t % 24;    t /= 24;
    long day = t;

    String result;
    
    if (day != 0) {
      result = "[" + day + "]";
    }
    else {
      result = "";
    }
    result += "" + hr + ":" + min + ":" + sec + "." + ms;

    return result;
  }
}
