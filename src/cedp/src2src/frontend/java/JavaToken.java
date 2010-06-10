/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.src2src.frontend.java;

import antlr.CommonToken;

/**
 *
 * @author yim
 */
public class JavaToken extends antlr.CommonToken
{
  String source = "";
  int tokenNumber;

  public String getSource()
  {
    return source;
  }

  public void setSource(String src)
  {
  	source = src;
  }

  public int getTokenNumber()
  {
    return tokenNumber;
  }

  public void setTokenNumber(int i)
  {
    tokenNumber = i;
  }

    public String toString() {
        return "CToken:" +"(" + hashCode() + ")" + "[" + getType() + "] "+ getText() + " line:" + getLine() + " source:" + source ;
    }
}
