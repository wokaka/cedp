/*header
{
package vpa.interpreter;
}

{
import vpa.parsetree.*;
}*/

tree grammar VpaTreeParser ;

options {
    tokenVocab=VpaLexer ;
    ASTLabelType = Tree ;
}

document : element ;

element
    : ^( ELEMENT name=GENERIC_ID
            { VpaParseTree.CreateNode($name.text); System.out.print("<"+$name.text); }
      (^(ATTRIBUTE attrName=GENERIC_ID value=ATTR_VALUE)
            { if($attrName.text.equals("name")) VpaParseTree.SetName(value.getText()); System.out.print(" "+$attrName.text+"="+$value.text); }
      )*
            { System.out.println(">"); }
      (element | text=PCDATA
            { VpaParseTree.SetData($text.text); System.out.print($text.text); }
      )*
            { VpaParseTree.NodeConfigDone(); System.out.println("</"+$name.text+">"); }
      )
      ;