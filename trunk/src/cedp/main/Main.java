/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.main;

import cedp.login.LoginDialog;
import cedp.util.UtilFile;
import cedp.util.extlib.AntlrWrapper;
import cedp.util.extlib.CetusWrapper;
import java.applet.Applet;

/**
 *
 * @author yim
 */
public class Main extends Applet {

    @Override
    public void init()
    {
        LoginDialog loginDialog = new LoginDialog();
        loginDialog.Show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int generate = 4;

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
//                    CetusWrapper.Run("7.java", null, false);
                    CetusWrapper.Run("ad.java", null, true);
                    return;
                }
            }
            else if(generate == 3){
                    CetusWrapper.Run("bubble.c", null, true);
                    return;
            }
            else if(generate == 4){
              CetusWrapper.Run("ad.java", null, true);
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
