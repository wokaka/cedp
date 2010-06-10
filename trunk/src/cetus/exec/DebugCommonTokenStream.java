/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cetus.exec;

import org.antlr.runtime.CommonTokenStream;
import org.antlr.runtime.Lexer;
import org.antlr.runtime.Token;

/**
 *
 * @author yim
 */
public class DebugCommonTokenStream extends CommonTokenStream {
    public DebugCommonTokenStream()
    {
        super();
    }

    public DebugCommonTokenStream(Lexer lex)
    {
        super(lex);
    }

    static Token lt_token;
    static Token lb_token;
    
    public Token LT(int i)
    {

        Token result = super.LT(i);
        if(result != lt_token)
            System.out.println("LT : " + result.getText());
        lt_token = result;
        return result;
    }

    public Token LB(int i)
    {
        Token result = super.LB(i);
        if(result != lb_token)
            System.out.println("LB : " + result.getText());
        lb_token = result;
        return result;
    }
}
