/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package vpa.runtime;

import cedp.util.JcraftWrapper;

/**
 *
 * @author yim
 */
public class VpaAPI {

    public static void ExecCmd(String cmd)
    {
//        System.out.println("** " + cmd);
        JcraftWrapper net = JcraftWrapper.GetLatest();
        net.RunCommandBlocked(cmd);
    }
}
