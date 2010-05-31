/*header
{
package vpa.interpreter;
}

{
}*/

lexer grammar VpaLexer;

@members {
    boolean tagMode = false;
}

TAG_START_OPEN : '<' { tagMode = true; };
TAG_END_OPEN : '</' { tagMode = true; } ;
TAG_CLOSE : '>' { tagMode = false; };
TAG_EMPTY_CLOSE : { tagMode }?=> '/>' { tagMode = false; } ;

ATTR_EQ : { tagMode }?=> '=' ;
ATTR_VALUE : { tagMode }?=>
        ( '"' (~'"')* '"'
        | '\'' (~'\'')* '\''
        )
    ;

PCDATA : {!tagMode}?=> (~'<')+;

GENERIC_ID : {tagMode}?=> ( LETTER | '_' | ':' ) (NAMECHAR)*;

fragment NAMECHAR
    : LETTER | DIGIT | '.' | '-' | '_' | ':'
    ;

fragment DIGIT
    : '0'..'9'
    ;

fragment LETTER
    : 'a'..'z'
    | 'A'..'Z'
    ;

WS  : {tagMode}?=> (' '|'\r'|'\t'|'\u000C'|'\n'|) {_channel=99;};


