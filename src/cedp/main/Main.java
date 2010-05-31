/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.main;

import cedp.login.LoginDialog;

/**
 *
 * @author yim
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        LoginDialog loginDialog = new LoginDialog();
        loginDialog.Show();
    }

}
