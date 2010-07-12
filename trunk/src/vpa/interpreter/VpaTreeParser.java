// $ANTLR 3.2 Sep 23, 2009 12:02:23 src/vpa/interpreter/VpaTreeParser.g 2010-07-11 18:41:03

import org.antlr.runtime.*;
import org.antlr.runtime.tree.*;import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

public class VpaTreeParser extends TreeParser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "TAG_START_OPEN", "TAG_END_OPEN", "TAG_CLOSE", "TAG_EMPTY_CLOSE", "ATTR_EQ", "ATTR_VALUE", "PCDATA", "LETTER", "NAMECHAR", "GENERIC_ID", "DIGIT", "WS", "ELEMENT", "ATTRIBUTE"
    };
    public static final int PCDATA=10;
    public static final int TAG_EMPTY_CLOSE=7;
    public static final int WS=15;
    public static final int TAG_CLOSE=6;
    public static final int LETTER=11;
    public static final int GENERIC_ID=13;
    public static final int ATTRIBUTE=17;
    public static final int ELEMENT=16;
    public static final int ATTR_EQ=8;
    public static final int ATTR_VALUE=9;
    public static final int TAG_END_OPEN=5;
    public static final int DIGIT=14;
    public static final int EOF=-1;
    public static final int TAG_START_OPEN=4;
    public static final int NAMECHAR=12;

    // delegates
    // delegators


        public VpaTreeParser(TreeNodeStream input) {
            this(input, new RecognizerSharedState());
        }
        public VpaTreeParser(TreeNodeStream input, RecognizerSharedState state) {
            super(input, state);
             
        }
        

    public String[] getTokenNames() { return VpaTreeParser.tokenNames; }
    public String getGrammarFileName() { return "src/vpa/interpreter/VpaTreeParser.g"; }



    // $ANTLR start "document"
    // src/vpa/interpreter/VpaTreeParser.g:17:1: document : element ;
    public final void document() throws RecognitionException {
        try {
            // src/vpa/interpreter/VpaTreeParser.g:17:10: ( element )
            // src/vpa/interpreter/VpaTreeParser.g:17:12: element
            {
            pushFollow(FOLLOW_element_in_document43);
            element();

            state._fsp--;


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return ;
    }
    // $ANTLR end "document"


    // $ANTLR start "element"
    // src/vpa/interpreter/VpaTreeParser.g:19:1: element : ^( ELEMENT name= GENERIC_ID ( ^( ATTRIBUTE attrName= GENERIC_ID value= ATTR_VALUE ) )* ( element | text= PCDATA )* ) ;
    public final void element() throws RecognitionException {
        Tree name=null;
        Tree attrName=null;
        Tree value=null;
        Tree text=null;

        try {
            // src/vpa/interpreter/VpaTreeParser.g:20:5: ( ^( ELEMENT name= GENERIC_ID ( ^( ATTRIBUTE attrName= GENERIC_ID value= ATTR_VALUE ) )* ( element | text= PCDATA )* ) )
            // src/vpa/interpreter/VpaTreeParser.g:20:7: ^( ELEMENT name= GENERIC_ID ( ^( ATTRIBUTE attrName= GENERIC_ID value= ATTR_VALUE ) )* ( element | text= PCDATA )* )
            {
            match(input,ELEMENT,FOLLOW_ELEMENT_in_element58); 

            match(input, Token.DOWN, null); 
            name=(Tree)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_element62); 
             VpaParseTree.CreateNode((name!=null?name.getText():null)); System.out.print("<"+(name!=null?name.getText():null)); 
            // src/vpa/interpreter/VpaTreeParser.g:22:7: ( ^( ATTRIBUTE attrName= GENERIC_ID value= ATTR_VALUE ) )*
            loop1:
            do {
                int alt1=2;
                int LA1_0 = input.LA(1);

                if ( (LA1_0==ATTRIBUTE) ) {
                    alt1=1;
                }


                switch (alt1) {
            	case 1 :
            	    // src/vpa/interpreter/VpaTreeParser.g:22:8: ^( ATTRIBUTE attrName= GENERIC_ID value= ATTR_VALUE )
            	    {
            	    match(input,ATTRIBUTE,FOLLOW_ATTRIBUTE_in_element86); 

            	    match(input, Token.DOWN, null); 
            	    attrName=(Tree)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_element90); 
            	    value=(Tree)match(input,ATTR_VALUE,FOLLOW_ATTR_VALUE_in_element94); 

            	    match(input, Token.UP, null); 
            	     if((attrName!=null?attrName.getText():null).equals("name")) VpaParseTree.SetName(value.getText()); System.out.print(" "+(attrName!=null?attrName.getText():null)+"="+(value!=null?value.getText():null)); 

            	    }
            	    break;

            	default :
            	    break loop1;
                }
            } while (true);

             System.out.println(">"); 
            // src/vpa/interpreter/VpaTreeParser.g:26:7: ( element | text= PCDATA )*
            loop2:
            do {
                int alt2=3;
                int LA2_0 = input.LA(1);

                if ( (LA2_0==ELEMENT) ) {
                    alt2=1;
                }
                else if ( (LA2_0==PCDATA) ) {
                    alt2=2;
                }


                switch (alt2) {
            	case 1 :
            	    // src/vpa/interpreter/VpaTreeParser.g:26:8: element
            	    {
            	    pushFollow(FOLLOW_element_in_element141);
            	    element();

            	    state._fsp--;


            	    }
            	    break;
            	case 2 :
            	    // src/vpa/interpreter/VpaTreeParser.g:26:18: text= PCDATA
            	    {
            	    text=(Tree)match(input,PCDATA,FOLLOW_PCDATA_in_element147); 
            	     VpaParseTree.SetData((text!=null?text.getText():null)); System.out.print((text!=null?text.getText():null)); 

            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);

             VpaParseTree.NodeConfigDone(); System.out.println("</"+(name!=null?name.getText():null)+">"); 

            match(input, Token.UP, null); 

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return ;
    }
    // $ANTLR end "element"

    // Delegated rules


 

    public static final BitSet FOLLOW_element_in_document43 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ELEMENT_in_element58 = new BitSet(new long[]{0x0000000000000004L});
    public static final BitSet FOLLOW_GENERIC_ID_in_element62 = new BitSet(new long[]{0x0000000000030408L});
    public static final BitSet FOLLOW_ATTRIBUTE_in_element86 = new BitSet(new long[]{0x0000000000000004L});
    public static final BitSet FOLLOW_GENERIC_ID_in_element90 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_ATTR_VALUE_in_element94 = new BitSet(new long[]{0x0000000000000008L});
    public static final BitSet FOLLOW_element_in_element141 = new BitSet(new long[]{0x0000000000010408L});
    public static final BitSet FOLLOW_PCDATA_in_element147 = new BitSet(new long[]{0x0000000000010408L});

}