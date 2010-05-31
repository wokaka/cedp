/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util;

import java.io.IOException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;

/**
 *
 * @author Keun Soo Yim
 */
public class UtilNet {


    public static boolean Ping(String a, int port)
    {
        int timeoutMs = 2000;
        long start = -1; //default check value
        long end = -1; //default check value
        boolean result; // default for bad connection

        Socket theSock = new Socket();

        result = true;
        try {
            InetAddress addr = InetAddress.getByName(a);
            SocketAddress sockaddr = new InetSocketAddress(addr, port);

            start = System.currentTimeMillis();
            theSock.connect(sockaddr, timeoutMs);
            end = System.currentTimeMillis();
        } catch (UnknownHostException e) {
            result = false;
        } catch (SocketTimeoutException e) {
            result = false;
        } catch (IOException e) {
            result = false;
        } finally {
            if (theSock != null) {
                try {
                    theSock.close();
                } catch (IOException e) {
                }
            }
        }

        return result; //returns -1 if timeout
    }

    public static boolean Ping(String a)
    {
        /*
        CmdClient     clnt;
        String        temp;

        clnt = Connect();
        if(clnt == null)
            return false;

        temp = clnt.SendCmd("echo hello");
        if(temp.equals("hello\n"))
            return true;

        System.out.println(temp);

        return false;
        */

        System.out.println("Ping " + a);
        
        try {
            InetAddress addr = InetAddress.getByName(a);
            System.out.println(addr.toString());
            if(addr.isReachable(3000))
                return true;
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return false;
    }


}
