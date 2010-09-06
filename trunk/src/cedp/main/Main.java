/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */

package cedp.main;

import cedp.login.LoginDialog;
import cedp.util.UtilFile;
import cedp.util.extlib.AntlrWrapper;
import cedp.util.extlib.CetusWrapper;
import java.applet.Applet;

/**
 * The main class for when used as an OS application or a JavaApplet.
 *
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class Main extends Applet {
  @Override
  public void init()
  {
    (new LoginDialog()).show();
  }

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    int generate = 0;

    // TODO(yim): Commmand line arguments parsing (e.g., for logging level).
    
    // LEXER
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
//            CetusWrapper.Run("7.java", null, false);
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

    (new LoginDialog()).show();
  }
}
