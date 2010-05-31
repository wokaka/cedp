// $ANTLR 3.2 Sep 23, 2009 12:02:23 src/vpa/interpreter/VpaLexer.g 2010-05-30 21:53:56
package vpa.interpreter;
import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

public class VpaLexer extends Lexer {
    public static final int PCDATA=10;
    public static final int TAG_EMPTY_CLOSE=7;
    public static final int WS=15;
    public static final int TAG_CLOSE=6;
    public static final int LETTER=11;
    public static final int GENERIC_ID=13;
    public static final int ATTR_EQ=8;
    public static final int ATTR_VALUE=9;
    public static final int TAG_END_OPEN=5;
    public static final int DIGIT=14;
    public static final int EOF=-1;
    public static final int TAG_START_OPEN=4;
    public static final int NAMECHAR=12;

        boolean tagMode = false;


    // delegates
    // delegators

    public VpaLexer() {;} 
    public VpaLexer(CharStream input) {
        this(input, new RecognizerSharedState());
    }
    public VpaLexer(CharStream input, RecognizerSharedState state) {
        super(input,state);

    }
    public String getGrammarFileName() { return "src/vpa/interpreter/VpaLexer.g"; }

    // $ANTLR start "TAG_START_OPEN"
    public final void mTAG_START_OPEN() throws RecognitionException {
        try {
            int _type = TAG_START_OPEN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:15:16: ( '<' )
            // src/vpa/interpreter/VpaLexer.g:15:18: '<'
            {
            match('<'); 
             tagMode = true; 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "TAG_START_OPEN"

    // $ANTLR start "TAG_END_OPEN"
    public final void mTAG_END_OPEN() throws RecognitionException {
        try {
            int _type = TAG_END_OPEN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:16:14: ( '</' )
            // src/vpa/interpreter/VpaLexer.g:16:16: '</'
            {
            match("</"); 

             tagMode = true; 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "TAG_END_OPEN"

    // $ANTLR start "TAG_CLOSE"
    public final void mTAG_CLOSE() throws RecognitionException {
        try {
            int _type = TAG_CLOSE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:17:11: ( '>' )
            // src/vpa/interpreter/VpaLexer.g:17:13: '>'
            {
            match('>'); 
             tagMode = false; 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "TAG_CLOSE"

    // $ANTLR start "TAG_EMPTY_CLOSE"
    public final void mTAG_EMPTY_CLOSE() throws RecognitionException {
        try {
            int _type = TAG_EMPTY_CLOSE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:18:17: ({...}? => '/>' )
            // src/vpa/interpreter/VpaLexer.g:18:19: {...}? => '/>'
            {
            if ( !(( tagMode )) ) {
                throw new FailedPredicateException(input, "TAG_EMPTY_CLOSE", " tagMode ");
            }
            match("/>"); 

             tagMode = false; 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "TAG_EMPTY_CLOSE"

    // $ANTLR start "ATTR_EQ"
    public final void mATTR_EQ() throws RecognitionException {
        try {
            int _type = ATTR_EQ;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:20:9: ({...}? => '=' )
            // src/vpa/interpreter/VpaLexer.g:20:11: {...}? => '='
            {
            if ( !(( tagMode )) ) {
                throw new FailedPredicateException(input, "ATTR_EQ", " tagMode ");
            }
            match('='); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "ATTR_EQ"

    // $ANTLR start "ATTR_VALUE"
    public final void mATTR_VALUE() throws RecognitionException {
        try {
            int _type = ATTR_VALUE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:21:12: ({...}? => ( '\"' (~ '\"' )* '\"' | '\\'' (~ '\\'' )* '\\'' ) )
            // src/vpa/interpreter/VpaLexer.g:21:14: {...}? => ( '\"' (~ '\"' )* '\"' | '\\'' (~ '\\'' )* '\\'' )
            {
            if ( !(( tagMode )) ) {
                throw new FailedPredicateException(input, "ATTR_VALUE", " tagMode ");
            }
            // src/vpa/interpreter/VpaLexer.g:22:9: ( '\"' (~ '\"' )* '\"' | '\\'' (~ '\\'' )* '\\'' )
            int alt3=2;
            int LA3_0 = input.LA(1);

            if ( (LA3_0=='\"') ) {
                alt3=1;
            }
            else if ( (LA3_0=='\'') ) {
                alt3=2;
            }
            else {
                NoViableAltException nvae =
                    new NoViableAltException("", 3, 0, input);

                throw nvae;
            }
            switch (alt3) {
                case 1 :
                    // src/vpa/interpreter/VpaLexer.g:22:11: '\"' (~ '\"' )* '\"'
                    {
                    match('\"'); 
                    // src/vpa/interpreter/VpaLexer.g:22:15: (~ '\"' )*
                    loop1:
                    do {
                        int alt1=2;
                        int LA1_0 = input.LA(1);

                        if ( ((LA1_0>='\u0000' && LA1_0<='!')||(LA1_0>='#' && LA1_0<='\uFFFF')) ) {
                            alt1=1;
                        }


                        switch (alt1) {
                    	case 1 :
                    	    // src/vpa/interpreter/VpaLexer.g:22:16: ~ '\"'
                    	    {
                    	    if ( (input.LA(1)>='\u0000' && input.LA(1)<='!')||(input.LA(1)>='#' && input.LA(1)<='\uFFFF') ) {
                    	        input.consume();

                    	    }
                    	    else {
                    	        MismatchedSetException mse = new MismatchedSetException(null,input);
                    	        recover(mse);
                    	        throw mse;}


                    	    }
                    	    break;

                    	default :
                    	    break loop1;
                        }
                    } while (true);

                    match('\"'); 

                    }
                    break;
                case 2 :
                    // src/vpa/interpreter/VpaLexer.g:23:11: '\\'' (~ '\\'' )* '\\''
                    {
                    match('\''); 
                    // src/vpa/interpreter/VpaLexer.g:23:16: (~ '\\'' )*
                    loop2:
                    do {
                        int alt2=2;
                        int LA2_0 = input.LA(1);

                        if ( ((LA2_0>='\u0000' && LA2_0<='&')||(LA2_0>='(' && LA2_0<='\uFFFF')) ) {
                            alt2=1;
                        }


                        switch (alt2) {
                    	case 1 :
                    	    // src/vpa/interpreter/VpaLexer.g:23:17: ~ '\\''
                    	    {
                    	    if ( (input.LA(1)>='\u0000' && input.LA(1)<='&')||(input.LA(1)>='(' && input.LA(1)<='\uFFFF') ) {
                    	        input.consume();

                    	    }
                    	    else {
                    	        MismatchedSetException mse = new MismatchedSetException(null,input);
                    	        recover(mse);
                    	        throw mse;}


                    	    }
                    	    break;

                    	default :
                    	    break loop2;
                        }
                    } while (true);

                    match('\''); 

                    }
                    break;

            }


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "ATTR_VALUE"

    // $ANTLR start "PCDATA"
    public final void mPCDATA() throws RecognitionException {
        try {
            int _type = PCDATA;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:27:8: ({...}? => (~ '<' )+ )
            // src/vpa/interpreter/VpaLexer.g:27:10: {...}? => (~ '<' )+
            {
            if ( !((!tagMode)) ) {
                throw new FailedPredicateException(input, "PCDATA", "!tagMode");
            }
            // src/vpa/interpreter/VpaLexer.g:27:24: (~ '<' )+
            int cnt4=0;
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( ((LA4_0>='\u0000' && LA4_0<=';')||(LA4_0>='=' && LA4_0<='\uFFFF')) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // src/vpa/interpreter/VpaLexer.g:27:25: ~ '<'
            	    {
            	    if ( (input.LA(1)>='\u0000' && input.LA(1)<=';')||(input.LA(1)>='=' && input.LA(1)<='\uFFFF') ) {
            	        input.consume();

            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;}


            	    }
            	    break;

            	default :
            	    if ( cnt4 >= 1 ) break loop4;
                        EarlyExitException eee =
                            new EarlyExitException(4, input);
                        throw eee;
                }
                cnt4++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "PCDATA"

    // $ANTLR start "GENERIC_ID"
    public final void mGENERIC_ID() throws RecognitionException {
        try {
            int _type = GENERIC_ID;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:29:12: ({...}? => ( LETTER | '_' | ':' ) ( NAMECHAR )* )
            // src/vpa/interpreter/VpaLexer.g:29:14: {...}? => ( LETTER | '_' | ':' ) ( NAMECHAR )*
            {
            if ( !((tagMode)) ) {
                throw new FailedPredicateException(input, "GENERIC_ID", "tagMode");
            }
            if ( input.LA(1)==':'||(input.LA(1)>='A' && input.LA(1)<='Z')||input.LA(1)=='_'||(input.LA(1)>='a' && input.LA(1)<='z') ) {
                input.consume();

            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;}

            // src/vpa/interpreter/VpaLexer.g:29:50: ( NAMECHAR )*
            loop5:
            do {
                int alt5=2;
                int LA5_0 = input.LA(1);

                if ( ((LA5_0>='-' && LA5_0<='.')||(LA5_0>='0' && LA5_0<=':')||(LA5_0>='A' && LA5_0<='Z')||LA5_0=='_'||(LA5_0>='a' && LA5_0<='z')) ) {
                    alt5=1;
                }


                switch (alt5) {
            	case 1 :
            	    // src/vpa/interpreter/VpaLexer.g:29:51: NAMECHAR
            	    {
            	    mNAMECHAR(); 

            	    }
            	    break;

            	default :
            	    break loop5;
                }
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "GENERIC_ID"

    // $ANTLR start "NAMECHAR"
    public final void mNAMECHAR() throws RecognitionException {
        try {
            // src/vpa/interpreter/VpaLexer.g:32:5: ( LETTER | DIGIT | '.' | '-' | '_' | ':' )
            // src/vpa/interpreter/VpaLexer.g:
            {
            if ( (input.LA(1)>='-' && input.LA(1)<='.')||(input.LA(1)>='0' && input.LA(1)<=':')||(input.LA(1)>='A' && input.LA(1)<='Z')||input.LA(1)=='_'||(input.LA(1)>='a' && input.LA(1)<='z') ) {
                input.consume();

            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;}


            }

        }
        finally {
        }
    }
    // $ANTLR end "NAMECHAR"

    // $ANTLR start "DIGIT"
    public final void mDIGIT() throws RecognitionException {
        try {
            // src/vpa/interpreter/VpaLexer.g:36:5: ( '0' .. '9' )
            // src/vpa/interpreter/VpaLexer.g:36:7: '0' .. '9'
            {
            matchRange('0','9'); 

            }

        }
        finally {
        }
    }
    // $ANTLR end "DIGIT"

    // $ANTLR start "LETTER"
    public final void mLETTER() throws RecognitionException {
        try {
            // src/vpa/interpreter/VpaLexer.g:40:5: ( 'a' .. 'z' | 'A' .. 'Z' )
            // src/vpa/interpreter/VpaLexer.g:
            {
            if ( (input.LA(1)>='A' && input.LA(1)<='Z')||(input.LA(1)>='a' && input.LA(1)<='z') ) {
                input.consume();

            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;}


            }

        }
        finally {
        }
    }
    // $ANTLR end "LETTER"

    // $ANTLR start "WS"
    public final void mWS() throws RecognitionException {
        try {
            int _type = WS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/vpa/interpreter/VpaLexer.g:44:5: ({...}? => ( ' ' | '\\r' | '\\t' | '\\u000C' | '\\n' | ) )
            // src/vpa/interpreter/VpaLexer.g:44:7: {...}? => ( ' ' | '\\r' | '\\t' | '\\u000C' | '\\n' | )
            {
            if ( !((tagMode)) ) {
                throw new FailedPredicateException(input, "WS", "tagMode");
            }
            // src/vpa/interpreter/VpaLexer.g:44:20: ( ' ' | '\\r' | '\\t' | '\\u000C' | '\\n' | )
            int alt6=6;
            switch ( input.LA(1) ) {
            case ' ':
                {
                alt6=1;
                }
                break;
            case '\r':
                {
                alt6=2;
                }
                break;
            case '\t':
                {
                alt6=3;
                }
                break;
            case '\f':
                {
                alt6=4;
                }
                break;
            case '\n':
                {
                alt6=5;
                }
                break;
            default:
                alt6=6;}

            switch (alt6) {
                case 1 :
                    // src/vpa/interpreter/VpaLexer.g:44:21: ' '
                    {
                    match(' '); 

                    }
                    break;
                case 2 :
                    // src/vpa/interpreter/VpaLexer.g:44:25: '\\r'
                    {
                    match('\r'); 

                    }
                    break;
                case 3 :
                    // src/vpa/interpreter/VpaLexer.g:44:30: '\\t'
                    {
                    match('\t'); 

                    }
                    break;
                case 4 :
                    // src/vpa/interpreter/VpaLexer.g:44:35: '\\u000C'
                    {
                    match('\f'); 

                    }
                    break;
                case 5 :
                    // src/vpa/interpreter/VpaLexer.g:44:44: '\\n'
                    {
                    match('\n'); 

                    }
                    break;
                case 6 :
                    // src/vpa/interpreter/VpaLexer.g:44:49: 
                    {
                    }
                    break;

            }

            _channel=99;

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "WS"

    public void mTokens() throws RecognitionException {
        // src/vpa/interpreter/VpaLexer.g:1:8: ( TAG_START_OPEN | TAG_END_OPEN | TAG_CLOSE | TAG_EMPTY_CLOSE | ATTR_EQ | ATTR_VALUE | PCDATA | GENERIC_ID | WS )
        int alt7=9;
        alt7 = dfa7.predict(input);
        switch (alt7) {
            case 1 :
                // src/vpa/interpreter/VpaLexer.g:1:10: TAG_START_OPEN
                {
                mTAG_START_OPEN(); 

                }
                break;
            case 2 :
                // src/vpa/interpreter/VpaLexer.g:1:25: TAG_END_OPEN
                {
                mTAG_END_OPEN(); 

                }
                break;
            case 3 :
                // src/vpa/interpreter/VpaLexer.g:1:38: TAG_CLOSE
                {
                mTAG_CLOSE(); 

                }
                break;
            case 4 :
                // src/vpa/interpreter/VpaLexer.g:1:48: TAG_EMPTY_CLOSE
                {
                mTAG_EMPTY_CLOSE(); 

                }
                break;
            case 5 :
                // src/vpa/interpreter/VpaLexer.g:1:64: ATTR_EQ
                {
                mATTR_EQ(); 

                }
                break;
            case 6 :
                // src/vpa/interpreter/VpaLexer.g:1:72: ATTR_VALUE
                {
                mATTR_VALUE(); 

                }
                break;
            case 7 :
                // src/vpa/interpreter/VpaLexer.g:1:83: PCDATA
                {
                mPCDATA(); 

                }
                break;
            case 8 :
                // src/vpa/interpreter/VpaLexer.g:1:90: GENERIC_ID
                {
                mGENERIC_ID(); 

                }
                break;
            case 9 :
                // src/vpa/interpreter/VpaLexer.g:1:101: WS
                {
                mWS(); 

                }
                break;

        }

    }


    protected DFA7 dfa7 = new DFA7(this);
    static final String DFA7_eotS =
        "\1\16\1\20\1\21\1\15\1\23\2\15\1\31\5\33\5\uffff\1\35\1\uffff\1"+
        "\15\1\37\1\uffff\1\15\1\37\1\uffff\1\31\7\uffff";
    static final String DFA7_eofS =
        "\42\uffff";
    static final String DFA7_minS =
        "\1\0\1\57\1\0\1\76\11\0\4\uffff\5\0\1\uffff\5\0\1\uffff\1\0\1\uffff"+
        "\1\0\2\uffff";
    static final String DFA7_maxS =
        "\1\uffff\1\57\1\uffff\1\76\11\uffff\4\uffff\1\0\1\uffff\1\0\2\uffff"+
        "\1\uffff\2\uffff\1\0\1\uffff\1\0\1\uffff\1\0\1\uffff\1\0\2\uffff";
    static final String DFA7_acceptS =
        "\15\uffff\1\7\1\11\1\2\1\1\5\uffff\1\6\5\uffff\1\3\1\uffff\1\5\1"+
        "\uffff\1\10\1\4";
    static final String DFA7_specialS =
        "\1\2\1\uffff\1\21\1\25\1\7\1\10\1\12\1\5\1\15\1\20\1\24\1\27\1\22"+
        "\4\uffff\1\13\1\1\1\16\1\6\1\4\1\uffff\1\0\1\11\1\23\1\3\1\26\1"+
        "\uffff\1\14\1\uffff\1\17\2\uffff}>";
    static final String[] DFA7_transitionS = {
            "\11\15\1\12\1\14\1\15\1\13\1\11\22\15\1\10\1\15\1\5\4\15\1\6"+
            "\7\15\1\3\12\15\1\7\1\15\1\1\1\4\1\2\2\15\32\7\4\15\1\7\1\15"+
            "\32\7\uff85\15",
            "\1\17",
            "\74\15\1\uffff\uffc3\15",
            "\1\22",
            "\74\15\1\uffff\uffc3\15",
            "\42\24\1\25\31\24\1\26\uffc3\24",
            "\47\27\1\30\24\27\1\26\uffc3\27",
            "\55\15\2\32\1\15\13\32\1\15\1\uffff\4\15\32\32\4\15\1\32\1"+
            "\15\32\32\uff85\15",
            "\74\15\1\uffff\uffc3\15",
            "\74\15\1\uffff\uffc3\15",
            "\74\15\1\uffff\uffc3\15",
            "\74\15\1\uffff\uffc3\15",
            "\74\15\1\uffff\uffc3\15",
            "",
            "",
            "",
            "",
            "\1\uffff",
            "\74\15\1\uffff\uffc3\15",
            "\1\uffff",
            "\42\24\1\25\31\24\1\26\uffc3\24",
            "\74\15\1\uffff\uffc3\15",
            "",
            "\47\27\1\30\24\27\1\26\uffc3\27",
            "\74\15\1\uffff\uffc3\15",
            "\1\uffff",
            "\55\15\2\32\1\15\13\32\1\15\1\uffff\4\15\32\32\4\15\1\32\1"+
            "\15\32\32\uff85\15",
            "\1\uffff",
            "",
            "\1\uffff",
            "",
            "\1\uffff",
            "",
            ""
    };

    static final short[] DFA7_eot = DFA.unpackEncodedString(DFA7_eotS);
    static final short[] DFA7_eof = DFA.unpackEncodedString(DFA7_eofS);
    static final char[] DFA7_min = DFA.unpackEncodedStringToUnsignedChars(DFA7_minS);
    static final char[] DFA7_max = DFA.unpackEncodedStringToUnsignedChars(DFA7_maxS);
    static final short[] DFA7_accept = DFA.unpackEncodedString(DFA7_acceptS);
    static final short[] DFA7_special = DFA.unpackEncodedString(DFA7_specialS);
    static final short[][] DFA7_transition;

    static {
        int numStates = DFA7_transitionS.length;
        DFA7_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA7_transition[i] = DFA.unpackEncodedString(DFA7_transitionS[i]);
        }
    }

    class DFA7 extends DFA {

        public DFA7(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 7;
            this.eot = DFA7_eot;
            this.eof = DFA7_eof;
            this.min = DFA7_min;
            this.max = DFA7_max;
            this.accept = DFA7_accept;
            this.special = DFA7_special;
            this.transition = DFA7_transition;
        }
        public String getDescription() {
            return "1:1: Tokens : ( TAG_START_OPEN | TAG_END_OPEN | TAG_CLOSE | TAG_EMPTY_CLOSE | ATTR_EQ | ATTR_VALUE | PCDATA | GENERIC_ID | WS );";
        }
        public int specialStateTransition(int s, IntStream _input) throws NoViableAltException {
            IntStream input = _input;
        	int _s = s;
            switch ( s ) {
                    case 0 : 
                        int LA7_23 = input.LA(1);

                         
                        int index7_23 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (LA7_23=='\'') && (((!tagMode)||( tagMode )))) {s = 24;}

                        else if ( ((LA7_23>='\u0000' && LA7_23<='&')||(LA7_23>='(' && LA7_23<=';')||(LA7_23>='=' && LA7_23<='\uFFFF')) && (((!tagMode)||( tagMode )))) {s = 23;}

                        else if ( (LA7_23=='<') && (( tagMode ))) {s = 22;}

                        else s = 13;

                         
                        input.seek(index7_23);
                        if ( s>=0 ) return s;
                        break;
                    case 1 : 
                        int LA7_18 = input.LA(1);

                         
                        int index7_18 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_18>='\u0000' && LA7_18<=';')||(LA7_18>='=' && LA7_18<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 29;

                         
                        input.seek(index7_18);
                        if ( s>=0 ) return s;
                        break;
                    case 2 : 
                        int LA7_0 = input.LA(1);

                         
                        int index7_0 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (LA7_0=='<') ) {s = 1;}

                        else if ( (LA7_0=='>') ) {s = 2;}

                        else if ( (LA7_0=='/') && (((!tagMode)||( tagMode )))) {s = 3;}

                        else if ( (LA7_0=='=') && (((!tagMode)||( tagMode )))) {s = 4;}

                        else if ( (LA7_0=='\"') && (((!tagMode)||( tagMode )))) {s = 5;}

                        else if ( (LA7_0=='\'') && (((!tagMode)||( tagMode )))) {s = 6;}

                        else if ( (LA7_0==':'||(LA7_0>='A' && LA7_0<='Z')||LA7_0=='_'||(LA7_0>='a' && LA7_0<='z')) && (((!tagMode)||(tagMode)))) {s = 7;}

                        else if ( (LA7_0==' ') && (((!tagMode)||(tagMode)))) {s = 8;}

                        else if ( (LA7_0=='\r') && (((!tagMode)||(tagMode)))) {s = 9;}

                        else if ( (LA7_0=='\t') && (((!tagMode)||(tagMode)))) {s = 10;}

                        else if ( (LA7_0=='\f') && (((!tagMode)||(tagMode)))) {s = 11;}

                        else if ( (LA7_0=='\n') && (((!tagMode)||(tagMode)))) {s = 12;}

                        else if ( ((LA7_0>='\u0000' && LA7_0<='\b')||LA7_0=='\u000B'||(LA7_0>='\u000E' && LA7_0<='\u001F')||LA7_0=='!'||(LA7_0>='#' && LA7_0<='&')||(LA7_0>='(' && LA7_0<='.')||(LA7_0>='0' && LA7_0<='9')||LA7_0==';'||(LA7_0>='?' && LA7_0<='@')||(LA7_0>='[' && LA7_0<='^')||LA7_0=='`'||(LA7_0>='{' && LA7_0<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 14;

                         
                        input.seek(index7_0);
                        if ( s>=0 ) return s;
                        break;
                    case 3 : 
                        int LA7_26 = input.LA(1);

                         
                        int index7_26 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_26>='-' && LA7_26<='.')||(LA7_26>='0' && LA7_26<=':')||(LA7_26>='A' && LA7_26<='Z')||LA7_26=='_'||(LA7_26>='a' && LA7_26<='z')) && (((!tagMode)||(tagMode)))) {s = 26;}

                        else if ( ((LA7_26>='\u0000' && LA7_26<=',')||LA7_26=='/'||LA7_26==';'||(LA7_26>='=' && LA7_26<='@')||(LA7_26>='[' && LA7_26<='^')||LA7_26=='`'||(LA7_26>='{' && LA7_26<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 25;

                         
                        input.seek(index7_26);
                        if ( s>=0 ) return s;
                        break;
                    case 4 : 
                        int LA7_21 = input.LA(1);

                         
                        int index7_21 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_21>='\u0000' && LA7_21<=';')||(LA7_21>='=' && LA7_21<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 31;

                         
                        input.seek(index7_21);
                        if ( s>=0 ) return s;
                        break;
                    case 5 : 
                        int LA7_7 = input.LA(1);

                         
                        int index7_7 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_7>='-' && LA7_7<='.')||(LA7_7>='0' && LA7_7<=':')||(LA7_7>='A' && LA7_7<='Z')||LA7_7=='_'||(LA7_7>='a' && LA7_7<='z')) && (((!tagMode)||(tagMode)))) {s = 26;}

                        else if ( ((LA7_7>='\u0000' && LA7_7<=',')||LA7_7=='/'||LA7_7==';'||(LA7_7>='=' && LA7_7<='@')||(LA7_7>='[' && LA7_7<='^')||LA7_7=='`'||(LA7_7>='{' && LA7_7<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 25;

                         
                        input.seek(index7_7);
                        if ( s>=0 ) return s;
                        break;
                    case 6 : 
                        int LA7_20 = input.LA(1);

                         
                        int index7_20 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (LA7_20=='\"') && (((!tagMode)||( tagMode )))) {s = 21;}

                        else if ( ((LA7_20>='\u0000' && LA7_20<='!')||(LA7_20>='#' && LA7_20<=';')||(LA7_20>='=' && LA7_20<='\uFFFF')) && (((!tagMode)||( tagMode )))) {s = 20;}

                        else if ( (LA7_20=='<') && (( tagMode ))) {s = 22;}

                        else s = 13;

                         
                        input.seek(index7_20);
                        if ( s>=0 ) return s;
                        break;
                    case 7 : 
                        int LA7_4 = input.LA(1);

                         
                        int index7_4 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_4>='\u0000' && LA7_4<=';')||(LA7_4>='=' && LA7_4<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 19;

                         
                        input.seek(index7_4);
                        if ( s>=0 ) return s;
                        break;
                    case 8 : 
                        int LA7_5 = input.LA(1);

                         
                        int index7_5 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_5>='\u0000' && LA7_5<='!')||(LA7_5>='#' && LA7_5<=';')||(LA7_5>='=' && LA7_5<='\uFFFF')) && (((!tagMode)||( tagMode )))) {s = 20;}

                        else if ( (LA7_5=='\"') && (((!tagMode)||( tagMode )))) {s = 21;}

                        else if ( (LA7_5=='<') && (( tagMode ))) {s = 22;}

                        else s = 13;

                         
                        input.seek(index7_5);
                        if ( s>=0 ) return s;
                        break;
                    case 9 : 
                        int LA7_24 = input.LA(1);

                         
                        int index7_24 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_24>='\u0000' && LA7_24<=';')||(LA7_24>='=' && LA7_24<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 31;

                         
                        input.seek(index7_24);
                        if ( s>=0 ) return s;
                        break;
                    case 10 : 
                        int LA7_6 = input.LA(1);

                         
                        int index7_6 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_6>='\u0000' && LA7_6<='&')||(LA7_6>='(' && LA7_6<=';')||(LA7_6>='=' && LA7_6<='\uFFFF')) && (((!tagMode)||( tagMode )))) {s = 23;}

                        else if ( (LA7_6=='\'') && (((!tagMode)||( tagMode )))) {s = 24;}

                        else if ( (LA7_6=='<') && (( tagMode ))) {s = 22;}

                        else s = 13;

                         
                        input.seek(index7_6);
                        if ( s>=0 ) return s;
                        break;
                    case 11 : 
                        int LA7_17 = input.LA(1);

                         
                        int index7_17 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (!(((!tagMode)))) ) {s = 28;}

                        else if ( ((!tagMode)) ) {s = 13;}

                         
                        input.seek(index7_17);
                        if ( s>=0 ) return s;
                        break;
                    case 12 : 
                        int LA7_29 = input.LA(1);

                         
                        int index7_29 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (( tagMode )) ) {s = 33;}

                        else if ( ((!tagMode)) ) {s = 13;}

                         
                        input.seek(index7_29);
                        if ( s>=0 ) return s;
                        break;
                    case 13 : 
                        int LA7_8 = input.LA(1);

                         
                        int index7_8 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_8>='\u0000' && LA7_8<=';')||(LA7_8>='=' && LA7_8<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 27;

                         
                        input.seek(index7_8);
                        if ( s>=0 ) return s;
                        break;
                    case 14 : 
                        int LA7_19 = input.LA(1);

                         
                        int index7_19 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (( tagMode )) ) {s = 30;}

                        else if ( ((!tagMode)) ) {s = 13;}

                         
                        input.seek(index7_19);
                        if ( s>=0 ) return s;
                        break;
                    case 15 : 
                        int LA7_31 = input.LA(1);

                         
                        int index7_31 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (( tagMode )) ) {s = 22;}

                        else if ( ((!tagMode)) ) {s = 13;}

                         
                        input.seek(index7_31);
                        if ( s>=0 ) return s;
                        break;
                    case 16 : 
                        int LA7_9 = input.LA(1);

                         
                        int index7_9 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_9>='\u0000' && LA7_9<=';')||(LA7_9>='=' && LA7_9<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 27;

                         
                        input.seek(index7_9);
                        if ( s>=0 ) return s;
                        break;
                    case 17 : 
                        int LA7_2 = input.LA(1);

                         
                        int index7_2 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_2>='\u0000' && LA7_2<=';')||(LA7_2>='=' && LA7_2<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 17;

                         
                        input.seek(index7_2);
                        if ( s>=0 ) return s;
                        break;
                    case 18 : 
                        int LA7_12 = input.LA(1);

                         
                        int index7_12 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_12>='\u0000' && LA7_12<=';')||(LA7_12>='=' && LA7_12<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 27;

                         
                        input.seek(index7_12);
                        if ( s>=0 ) return s;
                        break;
                    case 19 : 
                        int LA7_25 = input.LA(1);

                         
                        int index7_25 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((!tagMode)) ) {s = 13;}

                        else if ( ((tagMode)) ) {s = 32;}

                         
                        input.seek(index7_25);
                        if ( s>=0 ) return s;
                        break;
                    case 20 : 
                        int LA7_10 = input.LA(1);

                         
                        int index7_10 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_10>='\u0000' && LA7_10<=';')||(LA7_10>='=' && LA7_10<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 27;

                         
                        input.seek(index7_10);
                        if ( s>=0 ) return s;
                        break;
                    case 21 : 
                        int LA7_3 = input.LA(1);

                         
                        int index7_3 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (LA7_3=='>') && (((!tagMode)||( tagMode )))) {s = 18;}

                        else s = 13;

                         
                        input.seek(index7_3);
                        if ( s>=0 ) return s;
                        break;
                    case 22 : 
                        int LA7_27 = input.LA(1);

                         
                        int index7_27 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((!tagMode)) ) {s = 13;}

                        else if ( ((tagMode)) ) {s = 14;}

                         
                        input.seek(index7_27);
                        if ( s>=0 ) return s;
                        break;
                    case 23 : 
                        int LA7_11 = input.LA(1);

                         
                        int index7_11 = input.index();
                        input.rewind();
                        s = -1;
                        if ( ((LA7_11>='\u0000' && LA7_11<=';')||(LA7_11>='=' && LA7_11<='\uFFFF')) && ((!tagMode))) {s = 13;}

                        else s = 27;

                         
                        input.seek(index7_11);
                        if ( s>=0 ) return s;
                        break;
            }
            NoViableAltException nvae =
                new NoViableAltException(getDescription(), 7, _s, input);
            error(nvae);
            throw nvae;
        }
    }
 

}