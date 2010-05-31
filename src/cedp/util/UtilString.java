/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util;

import java.io.IOException;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.sql.Time;
import java.util.Random;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Keun Soo Yim
 */
public class UtilString {

    public static String ParseLine(String s, int no)
    {
        int line = 0;
        int i, j;

        j = 0;
        for(i=0; i<s.length(); i++){
            if(s.charAt(i) == '\n'){
                if(line == no){
                    return s.substring(j, i-1);
                }
                j = i+1;
                line++;
            }
        }

        return null;
    }
    
    public static int String2Int(String s)
    {
        if(s == null)
            return 0;
        
        try{
            return Integer.parseInt(s, 10);
        } catch(Exception e){
            e.printStackTrace();
        }
        return 0;
    }

    public static double String2Double(String s)
    {
        if(s == null)
            return 0;

        try{
            return Double.parseDouble(s);
        } catch(Exception e){
            e.printStackTrace();
        }
        
        return 0;
    }
    
    public static long HexStr2Long(String s)
    {
        if(s == null)
            return 0;

        try{
            return Long.parseLong(s, 16);
        } catch(Exception e){
            e.printStackTrace();
        }
        return 0;
    }

    public static long HexString2Long(String s)
    {
        try{
            return Long.parseLong(s, 16);
        } catch(Exception e){
            e.printStackTrace();
        }
        return 0;
    }


    public static long String2Long(String s)
    {
        try{
            return Long.parseLong(s, 10);
        } catch(Exception e){
            e.printStackTrace();
        }
        return 0;
    }

    public static String Long2HexString(long h)
    {
        try{
            return Long.toHexString(h);
        } catch(Exception e){
            e.printStackTrace();
        }
        return "0";
    }

    public static String Hex2String(int h)
    {
        try{
            return Integer.toHexString(h);
        } catch(Exception e){
            e.printStackTrace();
        }
        return "0";
    }

    public static boolean IsSameString(String x[], String y[])
    {
        int i;
        
        if(x == null){
            if(y == null)
                return true;
            else
                return false;
        }
        else{
            if(y == null)
                return false;
            else{
                if(x.length != y.length)
                    return false;

                for(i=0; i<x.length; i++)
                    if(!x[i].equals(y[i]))
                        return false;

                return true;
            }
        }
    }

    public static boolean IsSameInteger(Integer x[], Integer y[])
    {
        int i;

        if(x == null){
            if(y == null)
                return true;
            else
                return false;
        }
        else{
            if(y == null)
                return false;
            else{
                if(x.length != y.length)
                    return false;

                for(i=0; i<x.length; i++)
                    if(x[i] != y[i])
                        return false;

                return true;
            }
        }
    }


}

