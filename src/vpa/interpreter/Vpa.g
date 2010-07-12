grammar Vpa;

@lexer::header {
package vpa.interpreter;
}

@header {
package vpa.interpreter;

import vpa.parsetree.ParseTreeNode;
import java.util.Vector;
}

@lexer::members {
    boolean tagMode = false;
}

@members {
    boolean debug = false;
}

document returns [ParseTreeNode node]
  @init {
    if(debug) System.out.println("document");
  }
  : t1=element
      {
        node = t1;
      }
  ;

element returns [ParseTreeNode node]
  @init {
    if(debug) System.out.println("element");
  }
  : ( t1=startTag
        {
          node = t1;
        }
      (t2=element
        {
          node.AddChild(t2);
        }
      | t3=PCDATA
        {
          node.AddBody($t3.text);
        }
      )*
      endTag
    | t4=emptyElement
        {
          node = t4;
        }
    )
  ;

startTag returns [ParseTreeNode node]
  @init {
    if(debug) System.out.println("startTag");
  }
  : TAG_START_OPEN t1=GENERIC_ID 
    {
      node = new ParseTreeNode($t1.text);
    }
    (t2=attribute
      {
        node.SetParam((String)t2.get(0), (String)t2.get(1));
      }
    )* TAG_CLOSE
  ;

attribute returns [Vector vec]
  @init {
    if(debug) System.out.println("attribute");
  }
  : t1=GENERIC_ID ATTR_EQ t2=ATTR_VALUE
      {
        vec = new Vector();
        vec.add($t1.text);
        vec.add($t2.text);
      }
  ;

endTag
  @init {
    if(debug) System.out.println("endTag");
  }
  : TAG_END_OPEN GENERIC_ID TAG_CLOSE
  ;

emptyElement returns [ParseTreeNode node]
  @init {
    if(debug) System.out.println("emptyElement");
  }
  : TAG_START_OPEN t1=GENERIC_ID
      {
        node = new ParseTreeNode($t1.text);
      }
    (t2=attribute
      {
        node.SetParam((String)t2.get(0), (String)t2.get(1));
      }
    )* TAG_EMPTY_CLOSE
  ;

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
