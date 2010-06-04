/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.main;

import cedp.login.LoginDialog;
import cedp.util.extlib.AntlrWrapper;

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
        int generate = 2;

        /* LEXER */
        try{
            if(generate == 1){
                new AntlrWrapper().GenerateVpaParser();
                System.exit(0);
            }
            else if(generate == 2){
                new AntlrWrapper().GenerateJavaParser();
                System.exit(0);
            }
        } catch(Exception e){
            e.printStackTrace();
            return;
        }

        LoginDialog loginDialog = new LoginDialog();
        loginDialog.Show();
    }

}
