// $ANTLR 3.2 Sep 23, 2009 12:02:23 src/vpa/interpreter/VpaParser.g 2010-05-30 21:53:57
package vpa.interpreter;
import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;


import org.antlr.runtime.tree.*;

public class VpaParser extends Parser {
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


        public VpaParser(TokenStream input) {
            this(input, new RecognizerSharedState());
        }
        public VpaParser(TokenStream input, RecognizerSharedState state) {
            super(input, state);
             
        }
        
    protected TreeAdaptor adaptor = new CommonTreeAdaptor();

    public void setTreeAdaptor(TreeAdaptor adaptor) {
        this.adaptor = adaptor;
    }
    public TreeAdaptor getTreeAdaptor() {
        return adaptor;
    }

    public String[] getTokenNames() { return VpaParser.tokenNames; }
    public String getGrammarFileName() { return "src/vpa/interpreter/VpaParser.g"; }


    public static class document_return extends ParserRuleReturnScope {
        Object tree;
        public Object getTree() { return tree; }
    };

    // $ANTLR start "document"
    // src/vpa/interpreter/VpaParser.g:20:1: document : element ;
    public final VpaParser.document_return document() throws RecognitionException {
        VpaParser.document_return retval = new VpaParser.document_return();
        retval.start = input.LT(1);

        Object root_0 = null;

        VpaParser.element_return element1 = null;



        try {
            // src/vpa/interpreter/VpaParser.g:20:10: ( element )
            // src/vpa/interpreter/VpaParser.g:20:12: element
            {
            root_0 = (Object)adaptor.nil();

            pushFollow(FOLLOW_element_in_document56);
            element1=element();

            state._fsp--;

            adaptor.addChild(root_0, element1.getTree());

            }

            retval.stop = input.LT(-1);

            retval.tree = (Object)adaptor.rulePostProcessing(root_0);
            adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
    	retval.tree = (Object)adaptor.errorNode(input, retval.start, input.LT(-1), re);

        }
        finally {
        }
        return retval;
    }
    // $ANTLR end "document"

    public static class element_return extends ParserRuleReturnScope {
        Object tree;
        public Object getTree() { return tree; }
    };

    // $ANTLR start "element"
    // src/vpa/interpreter/VpaParser.g:22:1: element : ( startTag ( element | PCDATA )* endTag | emptyElement ) ;
    public final VpaParser.element_return element() throws RecognitionException {
        VpaParser.element_return retval = new VpaParser.element_return();
        retval.start = input.LT(1);

        Object root_0 = null;

        Token PCDATA4=null;
        VpaParser.startTag_return startTag2 = null;

        VpaParser.element_return element3 = null;

        VpaParser.endTag_return endTag5 = null;

        VpaParser.emptyElement_return emptyElement6 = null;


        Object PCDATA4_tree=null;

        try {
            // src/vpa/interpreter/VpaParser.g:23:5: ( ( startTag ( element | PCDATA )* endTag | emptyElement ) )
            // src/vpa/interpreter/VpaParser.g:23:7: ( startTag ( element | PCDATA )* endTag | emptyElement )
            {
            root_0 = (Object)adaptor.nil();

            // src/vpa/interpreter/VpaParser.g:23:7: ( startTag ( element | PCDATA )* endTag | emptyElement )
            int alt2=2;
            alt2 = dfa2.predict(input);
            switch (alt2) {
                case 1 :
                    // src/vpa/interpreter/VpaParser.g:23:9: startTag ( element | PCDATA )* endTag
                    {
                    pushFollow(FOLLOW_startTag_in_element71);
                    startTag2=startTag();

                    state._fsp--;

                    root_0 = (Object)adaptor.becomeRoot(startTag2.getTree(), root_0);
                    // src/vpa/interpreter/VpaParser.g:24:13: ( element | PCDATA )*
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
                    	    // src/vpa/interpreter/VpaParser.g:24:14: element
                    	    {
                    	    pushFollow(FOLLOW_element_in_element87);
                    	    element3=element();

                    	    state._fsp--;

                    	    adaptor.addChild(root_0, element3.getTree());

                    	    }
                    	    break;
                    	case 2 :
                    	    // src/vpa/interpreter/VpaParser.g:25:15: PCDATA
                    	    {
                    	    PCDATA4=(Token)match(input,PCDATA,FOLLOW_PCDATA_in_element103); 
                    	    PCDATA4_tree = (Object)adaptor.create(PCDATA4);
                    	    adaptor.addChild(root_0, PCDATA4_tree);


                    	    }
                    	    break;

                    	default :
                    	    break loop1;
                        }
                    } while (true);

                    pushFollow(FOLLOW_endTag_in_element132);
                    endTag5=endTag();

                    state._fsp--;


                    }
                    break;
                case 2 :
                    // src/vpa/interpreter/VpaParser.g:28:11: emptyElement
                    {
                    pushFollow(FOLLOW_emptyElement_in_element145);
                    emptyElement6=emptyElement();

                    state._fsp--;

                    adaptor.addChild(root_0, emptyElement6.getTree());

                    }
                    break;

            }


            }

            retval.stop = input.LT(-1);

            retval.tree = (Object)adaptor.rulePostProcessing(root_0);
            adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
    	retval.tree = (Object)adaptor.errorNode(input, retval.start, input.LT(-1), re);

        }
        finally {
        }
        return retval;
    }
    // $ANTLR end "element"

    public static class startTag_return extends ParserRuleReturnScope {
        Object tree;
        public Object getTree() { return tree; }
    };

    // $ANTLR start "startTag"
    // src/vpa/interpreter/VpaParser.g:32:1: startTag : TAG_START_OPEN GENERIC_ID ( attribute )* TAG_CLOSE -> ^( ELEMENT GENERIC_ID ( attribute )* ) ;
    public final VpaParser.startTag_return startTag() throws RecognitionException {
        VpaParser.startTag_return retval = new VpaParser.startTag_return();
        retval.start = input.LT(1);

        Object root_0 = null;

        Token TAG_START_OPEN7=null;
        Token GENERIC_ID8=null;
        Token TAG_CLOSE10=null;
        VpaParser.attribute_return attribute9 = null;


        Object TAG_START_OPEN7_tree=null;
        Object GENERIC_ID8_tree=null;
        Object TAG_CLOSE10_tree=null;
        RewriteRuleTokenStream stream_TAG_CLOSE=new RewriteRuleTokenStream(adaptor,"token TAG_CLOSE");
        RewriteRuleTokenStream stream_TAG_START_OPEN=new RewriteRuleTokenStream(adaptor,"token TAG_START_OPEN");
        RewriteRuleTokenStream stream_GENERIC_ID=new RewriteRuleTokenStream(adaptor,"token GENERIC_ID");
        RewriteRuleSubtreeStream stream_attribute=new RewriteRuleSubtreeStream(adaptor,"rule attribute");
        try {
            // src/vpa/interpreter/VpaParser.g:32:10: ( TAG_START_OPEN GENERIC_ID ( attribute )* TAG_CLOSE -> ^( ELEMENT GENERIC_ID ( attribute )* ) )
            // src/vpa/interpreter/VpaParser.g:32:12: TAG_START_OPEN GENERIC_ID ( attribute )* TAG_CLOSE
            {
            TAG_START_OPEN7=(Token)match(input,TAG_START_OPEN,FOLLOW_TAG_START_OPEN_in_startTag168);  
            stream_TAG_START_OPEN.add(TAG_START_OPEN7);

            GENERIC_ID8=(Token)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_startTag170);  
            stream_GENERIC_ID.add(GENERIC_ID8);

            // src/vpa/interpreter/VpaParser.g:32:38: ( attribute )*
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( (LA3_0==GENERIC_ID) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // src/vpa/interpreter/VpaParser.g:32:38: attribute
            	    {
            	    pushFollow(FOLLOW_attribute_in_startTag172);
            	    attribute9=attribute();

            	    state._fsp--;

            	    stream_attribute.add(attribute9.getTree());

            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);

            TAG_CLOSE10=(Token)match(input,TAG_CLOSE,FOLLOW_TAG_CLOSE_in_startTag175);  
            stream_TAG_CLOSE.add(TAG_CLOSE10);



            // AST REWRITE
            // elements: GENERIC_ID, attribute
            // token labels: 
            // rule labels: retval
            // token list labels: 
            // rule list labels: 
            // wildcard labels: 
            retval.tree = root_0;
            RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.tree:null);

            root_0 = (Object)adaptor.nil();
            // 33:9: -> ^( ELEMENT GENERIC_ID ( attribute )* )
            {
                // src/vpa/interpreter/VpaParser.g:33:12: ^( ELEMENT GENERIC_ID ( attribute )* )
                {
                Object root_1 = (Object)adaptor.nil();
                root_1 = (Object)adaptor.becomeRoot((Object)adaptor.create(ELEMENT, "ELEMENT"), root_1);

                adaptor.addChild(root_1, stream_GENERIC_ID.nextNode());
                // src/vpa/interpreter/VpaParser.g:33:33: ( attribute )*
                while ( stream_attribute.hasNext() ) {
                    adaptor.addChild(root_1, stream_attribute.nextTree());

                }
                stream_attribute.reset();

                adaptor.addChild(root_0, root_1);
                }

            }

            retval.tree = root_0;
            }

            retval.stop = input.LT(-1);

            retval.tree = (Object)adaptor.rulePostProcessing(root_0);
            adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
    	retval.tree = (Object)adaptor.errorNode(input, retval.start, input.LT(-1), re);

        }
        finally {
        }
        return retval;
    }
    // $ANTLR end "startTag"

    public static class attribute_return extends ParserRuleReturnScope {
        Object tree;
        public Object getTree() { return tree; }
    };

    // $ANTLR start "attribute"
    // src/vpa/interpreter/VpaParser.g:36:1: attribute : GENERIC_ID ATTR_EQ ATTR_VALUE -> ^( ATTRIBUTE GENERIC_ID ATTR_VALUE ) ;
    public final VpaParser.attribute_return attribute() throws RecognitionException {
        VpaParser.attribute_return retval = new VpaParser.attribute_return();
        retval.start = input.LT(1);

        Object root_0 = null;

        Token GENERIC_ID11=null;
        Token ATTR_EQ12=null;
        Token ATTR_VALUE13=null;

        Object GENERIC_ID11_tree=null;
        Object ATTR_EQ12_tree=null;
        Object ATTR_VALUE13_tree=null;
        RewriteRuleTokenStream stream_ATTR_EQ=new RewriteRuleTokenStream(adaptor,"token ATTR_EQ");
        RewriteRuleTokenStream stream_ATTR_VALUE=new RewriteRuleTokenStream(adaptor,"token ATTR_VALUE");
        RewriteRuleTokenStream stream_GENERIC_ID=new RewriteRuleTokenStream(adaptor,"token GENERIC_ID");

        try {
            // src/vpa/interpreter/VpaParser.g:36:11: ( GENERIC_ID ATTR_EQ ATTR_VALUE -> ^( ATTRIBUTE GENERIC_ID ATTR_VALUE ) )
            // src/vpa/interpreter/VpaParser.g:36:13: GENERIC_ID ATTR_EQ ATTR_VALUE
            {
            GENERIC_ID11=(Token)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_attribute207);  
            stream_GENERIC_ID.add(GENERIC_ID11);

            ATTR_EQ12=(Token)match(input,ATTR_EQ,FOLLOW_ATTR_EQ_in_attribute209);  
            stream_ATTR_EQ.add(ATTR_EQ12);

            ATTR_VALUE13=(Token)match(input,ATTR_VALUE,FOLLOW_ATTR_VALUE_in_attribute211);  
            stream_ATTR_VALUE.add(ATTR_VALUE13);



            // AST REWRITE
            // elements: ATTR_VALUE, GENERIC_ID
            // token labels: 
            // rule labels: retval
            // token list labels: 
            // rule list labels: 
            // wildcard labels: 
            retval.tree = root_0;
            RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.tree:null);

            root_0 = (Object)adaptor.nil();
            // 36:43: -> ^( ATTRIBUTE GENERIC_ID ATTR_VALUE )
            {
                // src/vpa/interpreter/VpaParser.g:36:46: ^( ATTRIBUTE GENERIC_ID ATTR_VALUE )
                {
                Object root_1 = (Object)adaptor.nil();
                root_1 = (Object)adaptor.becomeRoot((Object)adaptor.create(ATTRIBUTE, "ATTRIBUTE"), root_1);

                adaptor.addChild(root_1, stream_GENERIC_ID.nextNode());
                adaptor.addChild(root_1, stream_ATTR_VALUE.nextNode());

                adaptor.addChild(root_0, root_1);
                }

            }

            retval.tree = root_0;
            }

            retval.stop = input.LT(-1);

            retval.tree = (Object)adaptor.rulePostProcessing(root_0);
            adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
    	retval.tree = (Object)adaptor.errorNode(input, retval.start, input.LT(-1), re);

        }
        finally {
        }
        return retval;
    }
    // $ANTLR end "attribute"

    public static class endTag_return extends ParserRuleReturnScope {
        Object tree;
        public Object getTree() { return tree; }
    };

    // $ANTLR start "endTag"
    // src/vpa/interpreter/VpaParser.g:38:1: endTag : TAG_END_OPEN GENERIC_ID TAG_CLOSE ;
    public final VpaParser.endTag_return endTag() throws RecognitionException {
        VpaParser.endTag_return retval = new VpaParser.endTag_return();
        retval.start = input.LT(1);

        Object root_0 = null;

        Token TAG_END_OPEN14=null;
        Token GENERIC_ID15=null;
        Token TAG_CLOSE16=null;

        Object TAG_END_OPEN14_tree=null;
        Object GENERIC_ID15_tree=null;
        Object TAG_CLOSE16_tree=null;

        try {
            // src/vpa/interpreter/VpaParser.g:38:9: ( TAG_END_OPEN GENERIC_ID TAG_CLOSE )
            // src/vpa/interpreter/VpaParser.g:38:11: TAG_END_OPEN GENERIC_ID TAG_CLOSE
            {
            root_0 = (Object)adaptor.nil();

            TAG_END_OPEN14=(Token)match(input,TAG_END_OPEN,FOLLOW_TAG_END_OPEN_in_endTag231); 
            TAG_END_OPEN14_tree = (Object)adaptor.create(TAG_END_OPEN14);
            adaptor.addChild(root_0, TAG_END_OPEN14_tree);

            GENERIC_ID15=(Token)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_endTag233); 
            GENERIC_ID15_tree = (Object)adaptor.create(GENERIC_ID15);
            adaptor.addChild(root_0, GENERIC_ID15_tree);

            TAG_CLOSE16=(Token)match(input,TAG_CLOSE,FOLLOW_TAG_CLOSE_in_endTag235); 
            TAG_CLOSE16_tree = (Object)adaptor.create(TAG_CLOSE16);
            adaptor.addChild(root_0, TAG_CLOSE16_tree);


            }

            retval.stop = input.LT(-1);

            retval.tree = (Object)adaptor.rulePostProcessing(root_0);
            adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
    	retval.tree = (Object)adaptor.errorNode(input, retval.start, input.LT(-1), re);

        }
        finally {
        }
        return retval;
    }
    // $ANTLR end "endTag"

    public static class emptyElement_return extends ParserRuleReturnScope {
        Object tree;
        public Object getTree() { return tree; }
    };

    // $ANTLR start "emptyElement"
    // src/vpa/interpreter/VpaParser.g:40:1: emptyElement : TAG_START_OPEN GENERIC_ID ( attribute )* TAG_EMPTY_CLOSE -> ^( ELEMENT GENERIC_ID ( attribute )* ) ;
    public final VpaParser.emptyElement_return emptyElement() throws RecognitionException {
        VpaParser.emptyElement_return retval = new VpaParser.emptyElement_return();
        retval.start = input.LT(1);

        Object root_0 = null;

        Token TAG_START_OPEN17=null;
        Token GENERIC_ID18=null;
        Token TAG_EMPTY_CLOSE20=null;
        VpaParser.attribute_return attribute19 = null;


        Object TAG_START_OPEN17_tree=null;
        Object GENERIC_ID18_tree=null;
        Object TAG_EMPTY_CLOSE20_tree=null;
        RewriteRuleTokenStream stream_TAG_EMPTY_CLOSE=new RewriteRuleTokenStream(adaptor,"token TAG_EMPTY_CLOSE");
        RewriteRuleTokenStream stream_TAG_START_OPEN=new RewriteRuleTokenStream(adaptor,"token TAG_START_OPEN");
        RewriteRuleTokenStream stream_GENERIC_ID=new RewriteRuleTokenStream(adaptor,"token GENERIC_ID");
        RewriteRuleSubtreeStream stream_attribute=new RewriteRuleSubtreeStream(adaptor,"rule attribute");
        try {
            // src/vpa/interpreter/VpaParser.g:40:14: ( TAG_START_OPEN GENERIC_ID ( attribute )* TAG_EMPTY_CLOSE -> ^( ELEMENT GENERIC_ID ( attribute )* ) )
            // src/vpa/interpreter/VpaParser.g:40:16: TAG_START_OPEN GENERIC_ID ( attribute )* TAG_EMPTY_CLOSE
            {
            TAG_START_OPEN17=(Token)match(input,TAG_START_OPEN,FOLLOW_TAG_START_OPEN_in_emptyElement243);  
            stream_TAG_START_OPEN.add(TAG_START_OPEN17);

            GENERIC_ID18=(Token)match(input,GENERIC_ID,FOLLOW_GENERIC_ID_in_emptyElement245);  
            stream_GENERIC_ID.add(GENERIC_ID18);

            // src/vpa/interpreter/VpaParser.g:40:42: ( attribute )*
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( (LA4_0==GENERIC_ID) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // src/vpa/interpreter/VpaParser.g:40:42: attribute
            	    {
            	    pushFollow(FOLLOW_attribute_in_emptyElement247);
            	    attribute19=attribute();

            	    state._fsp--;

            	    stream_attribute.add(attribute19.getTree());

            	    }
            	    break;

            	default :
            	    break loop4;
                }
            } while (true);

            TAG_EMPTY_CLOSE20=(Token)match(input,TAG_EMPTY_CLOSE,FOLLOW_TAG_EMPTY_CLOSE_in_emptyElement250);  
            stream_TAG_EMPTY_CLOSE.add(TAG_EMPTY_CLOSE20);



            // AST REWRITE
            // elements: attribute, GENERIC_ID
            // token labels: 
            // rule labels: retval
            // token list labels: 
            // rule list labels: 
            // wildcard labels: 
            retval.tree = root_0;
            RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.tree:null);

            root_0 = (Object)adaptor.nil();
            // 41:9: -> ^( ELEMENT GENERIC_ID ( attribute )* )
            {
                // src/vpa/interpreter/VpaParser.g:41:12: ^( ELEMENT GENERIC_ID ( attribute )* )
                {
                Object root_1 = (Object)adaptor.nil();
                root_1 = (Object)adaptor.becomeRoot((Object)adaptor.create(ELEMENT, "ELEMENT"), root_1);

                adaptor.addChild(root_1, stream_GENERIC_ID.nextNode());
                // src/vpa/interpreter/VpaParser.g:41:33: ( attribute )*
                while ( stream_attribute.hasNext() ) {
                    adaptor.addChild(root_1, stream_attribute.nextTree());

                }
                stream_attribute.reset();

                adaptor.addChild(root_0, root_1);
                }

            }

            retval.tree = root_0;
            }

            retval.stop = input.LT(-1);

            retval.tree = (Object)adaptor.rulePostProcessing(root_0);
            adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
    	retval.tree = (Object)adaptor.errorNode(input, retval.start, input.LT(-1), re);

        }
        finally {
        }
        return retval;
    }
    // $ANTLR end "emptyElement"

    // Delegated rules


    protected DFA2 dfa2 = new DFA2(this);
    static final String DFA2_eotS =
        "\10\uffff";
    static final String DFA2_eofS =
        "\10\uffff";
    static final String DFA2_minS =
        "\1\4\1\15\1\6\1\10\2\uffff\1\11\1\6";
    static final String DFA2_maxS =
        "\1\4\2\15\1\10\2\uffff\1\11\1\15";
    static final String DFA2_acceptS =
        "\4\uffff\1\2\1\1\2\uffff";
    static final String DFA2_specialS =
        "\10\uffff}>";
    static final String[] DFA2_transitionS = {
            "\1\1",
            "\1\2",
            "\1\5\1\4\5\uffff\1\3",
            "\1\6",
            "",
            "",
            "\1\7",
            "\1\5\1\4\5\uffff\1\3"
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
            return "23:7: ( startTag ( element | PCDATA )* endTag | emptyElement )";
        }
    }
 

    public static final BitSet FOLLOW_element_in_document56 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_startTag_in_element71 = new BitSet(new long[]{0x0000000000000430L});
    public static final BitSet FOLLOW_element_in_element87 = new BitSet(new long[]{0x0000000000000430L});
    public static final BitSet FOLLOW_PCDATA_in_element103 = new BitSet(new long[]{0x0000000000000430L});
    public static final BitSet FOLLOW_endTag_in_element132 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_emptyElement_in_element145 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_TAG_START_OPEN_in_startTag168 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_GENERIC_ID_in_startTag170 = new BitSet(new long[]{0x0000000000002040L});
    public static final BitSet FOLLOW_attribute_in_startTag172 = new BitSet(new long[]{0x0000000000002040L});
    public static final BitSet FOLLOW_TAG_CLOSE_in_startTag175 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_GENERIC_ID_in_attribute207 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ATTR_EQ_in_attribute209 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_ATTR_VALUE_in_attribute211 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_TAG_END_OPEN_in_endTag231 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_GENERIC_ID_in_endTag233 = new BitSet(new long[]{0x0000000000000040L});
    public static final BitSet FOLLOW_TAG_CLOSE_in_endTag235 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_TAG_START_OPEN_in_emptyElement243 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_GENERIC_ID_in_emptyElement245 = new BitSet(new long[]{0x0000000000002080L});
    public static final BitSet FOLLOW_attribute_in_emptyElement247 = new BitSet(new long[]{0x0000000000002080L});
    public static final BitSet FOLLOW_TAG_EMPTY_CLOSE_in_emptyElement250 = new BitSet(new long[]{0x0000000000000002L});

}