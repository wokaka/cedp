parser grammar VpaParser;

@header {
package vpa.interpreter;

import vpa.parsetree.ParseTreeNode;
}

document returns [ParseTreeNode node]
  @init {
    node = new ParseTreeNode("root");
    System.out.println("document");
  }
  : element
  ;

element
  @init {
    System.out.println("element");
  }
  : ( startTag
          (element
          | PCDATA
          )*
          endTag
      | emptyElement
      )
  ;

startTag
  @init {
    System.out.println("startTag");
  }
  : TAG_START_OPEN GENERIC_ID attribute* TAG_CLOSE
  ;

attribute
  @init {
    System.out.println("attribute");
  }
  : GENERIC_ID ATTR_EQ ATTR_VALUE
  ;

endTag
  @init {
    System.out.println("endTag");
  }
  : TAG_END_OPEN GENERIC_ID TAG_CLOSE
  ;

emptyElement
  @init {
    System.out.println("emptyElement");
  }
  : TAG_START_OPEN GENERIC_ID attribute* TAG_EMPTY_CLOSE
  ;
