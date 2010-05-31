/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util;

/**
 *
 * @author Keun Soo Yim
 */
public class UtilThread extends Thread {

    protected UtilThread callback;
    protected Thread pthread;
    
    public UtilThread(UtilThread cb)
    {
        if(cb != null){
            pthread = Thread.currentThread();
            callback = cb;
        }
        setPriority(Thread.currentThread().getPriority()+1);
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
        try{
            Thread.sleep(ms);
        } catch(Exception e){
            e.printStackTrace();
        }
    }
}
