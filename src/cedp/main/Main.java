/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.main;

import cedp.login.LoginDialog;
import cedp.util.UtilFile;
import cedp.util.extlib.AntlrWrapper;
import cedp.util.extlib.AntlrWrapper;
import cedp.util.extlib.CetusWrapper;

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
        int generate = 3;

        /* LEXER */
        try{
            if(generate == 1){
                new AntlrWrapper().GenerateVpaParser();
                System.exit(0);
            }
            else if(generate == 2){
                if(UtilFile.Read("stat").startsWith("generate")){
                    UtilFile.Write("stat", "run");
                    new AntlrWrapper().GenerateJavaParser();
                    System.exit(0);
                }
                else{
                    UtilFile.Write("stat", "generate");
                    CetusWrapper.Run("AskEnormousTests.java", null, false);
                    return;
                }
            }
            else if(generate == 3){
                    CetusWrapper.Run("bubble.c", null, false);
                    return;
            }
        } catch(Exception e){
            e.printStackTrace();
            return;
        }

        LoginDialog loginDialog = new LoginDialog();
        loginDialog.Show();
    }

}
