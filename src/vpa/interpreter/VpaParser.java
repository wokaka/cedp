// $ANTLR 3.2 Sep 23, 2009 12:02:23 src/vpa/interpreter/Vpa.g 2010-07-11 20:54:38

package vpa.interpreter;

import vpa.parsetree.ParseTreeNode;
import java.util.Vector;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

public class VpaParser extends Parser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "PCDATA", "TAG_START_OPEN", "GENERIC_ID", "TAG_CLOSE", "ATTR_EQ", "ATTR_VALUE", "TAG_END_OPEN", "TAG_EMPTY_CLOSE", "LETTER", "NAMECHAR", "DIGIT", "WS"
    };
    public static final int PCDATA=4;
    public static final int TAG_EMPTY_CLOSE=11;
    public static final int WS=15;
    public static final int TAG_CLOSE=7;
    public static final int LETTER=12;
    public static final int GENERIC_ID=6;
    public static final int ATTR_EQ=8;
    public static final int ATTR_VALUE=9;
    public static final int TAG_END_OPEN=10;
    public static final int DIGIT=14;
    public static final int EOF=-1;
    public static final int TAG_START_OPEN=5;
    public static final int NAMECHAR=13;

    // delegates
    // delegators


        public VpaParser(TokenStream input) {
            this(input, new RecognizerSharedState());
        }
        public VpaParser(TokenStream input, RecognizerSharedState state) {
            super(input, state);
             
        }
        

    public String[] getTokenNames() { return VpaParser.tokenNames; }
    public String getGrammarFileName() { return "src/vpa/interpreter/Vpa.g"; }


        boolean debug = false;



    // $ANTLR start "document"
    // src/vpa/interpreter/Vpa.g:22:1: document returns [ParseTreeNode node] : t1= element ;
    public final ParseTreeNode document() throws RecognitionException {
        ParseTreeNode node = null;

        ParseTreeNode t1 = null;



            if(debug) System.out.println("document");
          
        try {
            // src/vpa/interpreter/Vpa.g:26:3: (t1= element )
            // src/vpa/interpreter/Vpa.g:26:5: t1= element
            {
            pushFollow(FOLLOW_element_in_document55);
            t1=element();

            state._fsp--;


                    node = t1;
                  

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return node;
    }
    // $ANTLR end "document"


    // $ANTLR start "element"
    // src/vpa/interpreter/Vpa.g:32:1: element returns [ParseTreeNode node] : (t1= startTag (t2= element | t3= PCDATA )* endTag | t4= emptyElement ) ;
    public final ParseTreeNode element() throws RecognitionException {
        ParseTreeNode node = null;

        Token t3=null;
        ParseTreeNode t1 = null;

        ParseTreeNode t2 = null;

        ParseTreeNode t4 = null;



            if(debug) System.out.println("element");
          
        try {
            // src/vpa/interpreter/Vpa.g:36:3: ( (t1= startTag (t2= element | t3= PCDATA )* endTag | t4= emptyElement ) )
            // src/vpa/interpreter/Vpa.g:36:5: (t1= startTag (t2= element | t3= PCDATA )* endTag | t4= emptyElement )
            {
            // src/vpa/interpreter/Vpa.g:36:5: (t1= startTag (t2= element | t3= PCDATA )* endTag | t4= emptyElement )
            int alt2=2;
            alt2 = dfa2.predict(input);
            switch (alt2) {
                case 1 :
                    // src/vpa/interpreter/Vpa.g:36:7: t1= startTag (t2= element | t3= PCDATA )* endTag
                    {
                    pushFollow(FOLLOW_startTag_in_element91);
                    t1=startTag();

                    state._fsp--;


                              node = t1;
                            
                    // src/vpa/interpreter/Vpa.g:40:7: (t2= element | t3= PCDATA )*
                    loop1:
                    do {
                        int alt1=3;
                        int LA1_0 = input.LA(1);

                        if ( (LA1_0==TAG_START_OPEN) ) {
                            alt1=1;
                        }
                        else if ( (LA1_0==PCDATA) ) {
                            alt1=2;
                        }


                        switch (alt1) {
                    	case 1 :
                    	    // src/vpa/interpreter/Vpa.g:40:8: t2= element
                    	    {
                    	    pushFollow(FOLLOW_element_in_element112);
                    	    t2=element();

                    	    state._fsp--;


                    	              node.AddChild(t2);
                    	            

                    	    }
                    	    break;
                    	case 2 :
                    	    // src/vpa/interpreter/Vpa.g:44:9: t3= PCDATA
                    	    {
                    	    t3=(Token)match(input,PCDATA,FOLLOW_PCDATA_in_element134); 

                    	              node.AddBody((t3!=null?t3.getText():null));
                    	            

                    	    }
                    	    break;

                    	default :
                    	    break loop1;
                        }
                    } while (true);

                    pushFollow(FOLLOW_endTag_in_element161);
                    endTag();

                    state._fsp--;


                    }
                    break;
                case 2 :
                    // src/vpa/interpreter/Vpa.g:50:7: t4= emptyElement
                    {
                    pushFollow(FOLLOW_emptyElement_in_element171);
                    t4=emptyElement();

                    state._fsp--;


                              node = t4;
                            

                    }
                    break;

            }


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return node;
    }
    // $ANTLR end "element"


    // $ANTLR start "startTag"
    // src/vpa/interpreter/Vpa.g:57:1: startTag returns [ParseTreeNode node] : TAG_START_OPEN t1= GENERIC_ID (t2= attribute )* TAG_CLOSE ;
    public final ParseTreeNode startTag() throws RecognitionException {
        ParseTreeNode node = null;

        Token t1=null;
        Vector t2 = null;



            if(debug) System.out.println("startTag");
          
        try {
            // src/vpa/interpreter/Vpa.g:61:3: ( TAG_START_OPEN t1= GENERIC_ID (t2= attribute )* TAG_CLOSE )
            // src/vpa/interpreter/Vpa.g:61:5: TAG_START_OPEN t1= GENERIC_ID (t2= attribute )* TAG_CLOSE
            {
            match(input,TAG_START_OPEN,FOLLOW_TAG_START_OPEN_in_startTag211); 
            t1=(Token)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_startTag215); 

                  node = new ParseTreeNode((t1!=null?t1.getText():null));
                
            // src/vpa/interpreter/Vpa.g:65:5: (t2= attribute )*
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( (LA3_0==GENERIC_ID) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // src/vpa/interpreter/Vpa.g:65:6: t2= attribute
            	    {
            	    pushFollow(FOLLOW_attribute_in_startTag231);
            	    t2=attribute();

            	    state._fsp--;


            	            node.SetParam((String)t2.get(0), (String)t2.get(1));
            	          

            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);

            match(input,TAG_CLOSE,FOLLOW_TAG_CLOSE_in_startTag248); 

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return node;
    }
    // $ANTLR end "startTag"


    // $ANTLR start "attribute"
    // src/vpa/interpreter/Vpa.g:72:1: attribute returns [Vector vec] : t1= GENERIC_ID ATTR_EQ t2= ATTR_VALUE ;
    public final Vector attribute() throws RecognitionException {
        Vector vec = null;

        Token t1=null;
        Token t2=null;


            if(debug) System.out.println("attribute");
          
        try {
            // src/vpa/interpreter/Vpa.g:76:3: (t1= GENERIC_ID ATTR_EQ t2= ATTR_VALUE )
            // src/vpa/interpreter/Vpa.g:76:5: t1= GENERIC_ID ATTR_EQ t2= ATTR_VALUE
            {
            t1=(Token)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_attribute274); 
            match(input,ATTR_EQ,FOLLOW_ATTR_EQ_in_attribute276); 
            t2=(Token)match(input,ATTR_VALUE,FOLLOW_ATTR_VALUE_in_attribute280); 

                    vec = new Vector();
                    vec.add((t1!=null?t1.getText():null));
                    vec.add((t2!=null?t2.getText():null));
                  

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return vec;
    }
    // $ANTLR end "attribute"


    // $ANTLR start "endTag"
    // src/vpa/interpreter/Vpa.g:84:1: endTag : TAG_END_OPEN GENERIC_ID TAG_CLOSE ;
    public final void endTag() throws RecognitionException {

            if(debug) System.out.println("endTag");
          
        try {
            // src/vpa/interpreter/Vpa.g:88:3: ( TAG_END_OPEN GENERIC_ID TAG_CLOSE )
            // src/vpa/interpreter/Vpa.g:88:5: TAG_END_OPEN GENERIC_ID TAG_CLOSE
            {
            match(input,TAG_END_OPEN,FOLLOW_TAG_END_OPEN_in_endTag308); 
            match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_endTag310); 
            match(input,TAG_CLOSE,FOLLOW_TAG_CLOSE_in_endTag312); 

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
    // $ANTLR end "endTag"


    // $ANTLR start "emptyElement"
    // src/vpa/interpreter/Vpa.g:91:1: emptyElement returns [ParseTreeNode node] : TAG_START_OPEN t1= GENERIC_ID (t2= attribute )* TAG_EMPTY_CLOSE ;
    public final ParseTreeNode emptyElement() throws RecognitionException {
        ParseTreeNode node = null;

        Token t1=null;
        Vector t2 = null;



            if(debug) System.out.println("emptyElement");
          
        try {
            // src/vpa/interpreter/Vpa.g:95:3: ( TAG_START_OPEN t1= GENERIC_ID (t2= attribute )* TAG_EMPTY_CLOSE )
            // src/vpa/interpreter/Vpa.g:95:5: TAG_START_OPEN t1= GENERIC_ID (t2= attribute )* TAG_EMPTY_CLOSE
            {
            match(input,TAG_START_OPEN,FOLLOW_TAG_START_OPEN_in_emptyElement336); 
            t1=(Token)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_emptyElement340); 

                    node = new ParseTreeNode((t1!=null?t1.getText():null));
                  
            // src/vpa/interpreter/Vpa.g:99:5: (t2= attribute )*
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( (LA4_0==GENERIC_ID) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // src/vpa/interpreter/Vpa.g:99:6: t2= attribute
            	    {
            	    pushFollow(FOLLOW_attribute_in_emptyElement357);
            	    t2=attribute();

            	    state._fsp--;


            	            node.SetParam((String)t2.get(0), (String)t2.get(1));
            	          

            	    }
            	    break;

            	default :
            	    break loop4;
                }
            } while (true);

            match(input,TAG_EMPTY_CLOSE,FOLLOW_TAG_EMPTY_CLOSE_in_emptyElement374); 

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return node;
    }
    // $ANTLR end "emptyElement"

    // Delegated rules


    protected DFA2 dfa2 = new DFA2(this);
    static final String DFA2_eotS =
        "\10\uffff";
    static final String DFA2_eofS =
        "\10\uffff";
    static final String DFA2_minS =
        "\1\5\2\6\1\10\2\uffff\1\11\1\6";
    static final String DFA2_maxS =
        "\1\5\1\6\1\13\1\10\2\uffff\1\11\1\13";
    static final String DFA2_acceptS =
        "\4\uffff\1\1\1\2\2\uffff";
    static final String DFA2_specialS =
        "\10\uffff}>";
    static final String[] DFA2_transitionS = {
            "\1\1",
            "\1\2",
            "\1\3\1\4\3\uffff\1\5",
            "\1\6",
            "",
            "",
            "\1\7",
            "\1\3\1\4\3\uffff\1\5"
    };

    static final short[] DFA2_eot = DFA.unpackEncodedString(DFA2_eotS);
    static final short[] DFA2_eof = DFA.unpackEncodedString(DFA2_eofS);
    static final char[] DFA2_min = DFA.unpackEncodedStringToUnsignedChars(DFA2_minS);
    static final char[] DFA2_max = DFA.unpackEncodedStringToUnsignedChars(DFA2_maxS);
    static final short[] DFA2_accept = DFA.unpackEncodedString(DFA2_acceptS);
    static final short[] DFA2_special = DFA.unpackEncodedString(DFA2_specialS);
    static final short[][] DFA2_transition;

    static {
        int numStates = DFA2_transitionS.length;
        DFA2_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA2_transition[i] = DFA.unpackEncodedString(DFA2_transitionS[i]);
        }
    }

    class DFA2 extends DFA {

        public DFA2(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 2;
            this.eot = DFA2_eot;
            this.eof = DFA2_eof;
            this.min = DFA2_min;
            this.max = DFA2_max;
            this.accept = DFA2_accept;
            this.special = DFA2_special;
            this.transition = DFA2_transition;
        }
        public String getDescription() {
            return "36:5: (t1= startTag (t2= element | t3= PCDATA )* endTag | t4= emptyElement )";
        }
    }
 

    public static final BitSet FOLLOW_element_in_document55 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_startTag_in_element91 = new BitSet(new long[]{0x0000000000000430L});
    public static final BitSet FOLLOW_element_in_element112 = new BitSet(new long[]{0x0000000000000430L});
    public static final BitSet FOLLOW_PCDATA_in_element134 = new BitSet(new long[]{0x0000000000000430L});
    public static final BitSet FOLLOW_endTag_in_element161 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_emptyElement_in_element171 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_TAG_START_OPEN_in_startTag211 = new BitSet(new long[]{0x0000000000000040L});
    public static final BitSet FOLLOW_GENERIC_ID_in_startTag215 = new BitSet(new long[]{0x00000000000000C0L});
    public static final BitSet FOLLOW_attribute_in_startTag231 = new BitSet(new long[]{0x00000000000000C0L});
    public static final BitSet FOLLOW_TAG_CLOSE_in_startTag248 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_GENERIC_ID_in_attribute274 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ATTR_EQ_in_attribute276 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_ATTR_VALUE_in_attribute280 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_TAG_END_OPEN_in_endTag308 = new BitSet(new long[]{0x0000000000000040L});
    public static final BitSet FOLLOW_GENERIC_ID_in_endTag310 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_TAG_CLOSE_in_endTag312 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_TAG_START_OPEN_in_emptyElement336 = new BitSet(new long[]{0x0000000000000040L});
    public static final BitSet FOLLOW_GENERIC_ID_in_emptyElement340 = new BitSet(new long[]{0x0000000000000840L});
    public static final BitSet FOLLOW_attribute_in_emptyElement357 = new BitSet(new long[]{0x0000000000000840L});
    public static final BitSet FOLLOW_TAG_EMPTY_CLOSE_in_emptyElement374 = new BitSet(new long[]{0x0000000000000002L});

}