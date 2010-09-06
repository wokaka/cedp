/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilThread extends Thread
{
  protected UtilThread callback;
  protected Thread pthread;

  public UtilThread(UtilThread cb)
  {
    if (cb != null) {
      pthread = Thread.currentThread();
      callback = cb;
    }
    setPriority(Thread.currentThread().getPriority() + 1);
    this.start();
  }

  public void run()
  {
    callback.Callback(pthread);
  }

  public void Callback(Thread p)
  {
  }

  public static void Wait(int ms)
  {
    try {
      Thread.sleep(ms);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
