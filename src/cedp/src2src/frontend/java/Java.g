/*
 [The "BSD licence"]
 Copyright (c) 2007-2008 Terence Parr
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
 3. The name of the author may not be used to endorse or promote products
    derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/** A Java 1.5 grammar for ANTLR v3 derived from the spec
 *
 *  This is a very close representation of the spec; the changes
 *  are comestic (remove left recursion) and also fixes (the spec
 *  isn't exactly perfect).  I have run this on the 1.4.2 source
 *  and some nasty looking enums from 1.5, but have not really
 *  tested for 1.5 compatibility.
 *
 *  I built this with: java -Xmx100M org.antlr.Tool java.g
 *  and got two errors that are ok (for now):
 *  java.g:691:9: Decision can match input such as
 *    "'0'..'9'{'E', 'e'}{'+', '-'}'0'..'9'{'D', 'F', 'd', 'f'}"
 *    using multiple alternatives: 3, 4
 *  As a result, alternative(s) 4 were disabled for that input
 *  java.g:734:35: Decision can match input such as "{'$', 'A'..'Z',
 *    '_', 'a'..'z', '\u00C0'..'\u00D6', '\u00D8'..'\u00F6',
 *    '\u00F8'..'\u1FFF', '\u3040'..'\u318F', '\u3300'..'\u337F',
 *    '\u3400'..'\u3D2D', '\u4E00'..'\u9FFF', '\uF900'..'\uFAFF'}"
 *    using multiple alternatives: 1, 2
 *  As a result, alternative(s) 2 were disabled for that input
 *
 *  You can turn enum on/off as a keyword :)
 *
 *  Version 1.0 -- initial release July 5, 2006 (requires 3.0b2 or higher)
 *
 *  Primary author: Terence Parr, July 2006
 *
 *  Version 1.0.1 -- corrections by Koen Vanderkimpen & Marko van Dooren,
 *      October 25, 2006;
 *      fixed normalInterfaceDeclaration: now uses typeParameters instead
 *          of typeParameter (according to JLS, 3rd edition)
 *      fixed castExpression: no longer allows expression next to type
 *          (according to semantics in JLS, in contrast with syntax in JLS)
 *
 *  Version 1.0.2 -- Terence Parr, Nov 27, 2006
 *      java spec I built this from had some bizarre for-loop control.
 *          Looked weird and so I looked elsewhere...Yep, it's messed up.
 *          simplified.
 *
 *  Version 1.0.3 -- Chris Hogue, Feb 26, 2007
 *      Factored out an annotationName rule and used it in the annotation rule.
 *          Not sure why, but typeName wasn't recognizing references to inner
 *          annotations (e.g. @InterfaceName.InnerAnnotation())
 *      Factored out the elementValue section of an annotation reference.  Created
 *          elementValuePair and elementValuePairs rules, then used them in the
 *          annotation rule.  Allows it to recognize annotation references with
 *          multiple, comma separated attributes.
 *      Updated elementValueArrayInitializer so that it allows multiple elements.
 *          (It was only allowing 0 or 1 element).
 *      Updated localVariableDeclaration to allow annotations.  Interestingly the JLS
 *          doesn't appear to indicate this is legal, but it does work as of at least
 *          JDK 1.5.0_06.
 *      Moved the Identifier portion of annotationTypeElementRest to annotationMethodRest.
 *          Because annotationConstantRest already references variableDeclarator which
 *          has the Identifier portion in it, the parser would fail on constants in
 *          annotation definitions because it expected two identifiers.
 *      Added optional trailing ';' to the alternatives in annotationTypeElementRest.
 *          Wouldn't handle an inner interface that has a trailing ';'.
 *      Swapped the expression and type rule reference order in castExpression to
 *          make it check for genericized casts first.  It was failing to recognize a
 *          statement like  "Class<Byte> TYPE = (Class<Byte>)...;" because it was seeing
 *          'Class<Byte' in the cast expression as a less than expression, then failing
 *          on the '>'.
 *      Changed createdName to use typeArguments instead of nonWildcardTypeArguments.
 *          Again, JLS doesn't seem to allow this, but java.lang.Class has an example of
 *          of this construct.
 *      Changed the 'this' alternative in primary to allow 'identifierSuffix' rather than
 *          just 'arguments'.  The case it couldn't handle was a call to an explicit
 *          generic method invocation (e.g. this.<E>doSomething()).  Using identifierSuffix
 *          may be overly aggressive--perhaps should create a more constrained thisSuffix rule?
 *
 *  Version 1.0.4 -- Hiroaki Nakamura, May 3, 2007
 *
 *  Fixed formalParameterDecls, localVariableDeclaration, forInit,
 *  and forVarControl to use variableModifier* not 'final'? (annotation)?
 *
 *  Version 1.0.5 -- Terence, June 21, 2007
 *  --a[i].foo didn't work. Fixed unaryExpression
 *
 *  Version 1.0.6 -- John Ridgway, March 17, 2008
 *      Made "assert" a switchable keyword like "enum".
 *      Fixed compilationUnit to disallow "annotation importDeclaration ...".
 *      Changed "Identifier ('.' Identifier)*" to "qualifiedName" in more
 *          places.
 *      Changed modifier* and/or variableModifier* to classOrInterfaceModifiers,
 *          modifiers or variableModifiers, as appropriate.
 *      Renamed "bound" to "typeBound" to better match language in the JLS.
 *      Added "memberDeclaration" which rewrites to methodDeclaration or
 *      fieldDeclaration and pulled type into memberDeclaration.  So we parse
 *          type and then move on to decide whether we're dealing with a field
 *          or a method.
 *      Modified "constructorDeclaration" to use "constructorBody" instead of
 *          "methodBody".  constructorBody starts with explicitConstructorInvocation,
 *          then goes on to blockStatement*.  Pulling explicitConstructorInvocation
 *          out of expressions allowed me to simplify "primary".
 *      Changed variableDeclarator to simplify it.
 *      Changed type to use classOrInterfaceType, thus simplifying it; of course
 *          I then had to add classOrInterfaceType, but it is used in several
 *          places.
 *      Fixed annotations, old version allowed "@X(y,z)", which is illegal.
 *      Added optional comma to end of "elementValueArrayInitializer"; as per JLS.
 *      Changed annotationTypeElementRest to use normalClassDeclaration and
 *          normalInterfaceDeclaration rather than classDeclaration and
 *          interfaceDeclaration, thus getting rid of a couple of grammar ambiguities.
 *      Split localVariableDeclaration into localVariableDeclarationStatement
 *          (includes the terminating semi-colon) and localVariableDeclaration.
 *          This allowed me to use localVariableDeclaration in "forInit" clauses,
 *           simplifying them.
 *      Changed switchBlockStatementGroup to use multiple labels.  This adds an
 *          ambiguity, but if one uses appropriately greedy parsing it yields the
 *           parse that is closest to the meaning of the switch statement.
 *      Renamed "forVarControl" to "enhancedForControl" -- JLS language.
 *      Added semantic predicates to test for shift operations rather than other
 *          things.  Thus, for instance, the string "< <" will never be treated
 *          as a left-shift operator.
 *      In "creator" we rule out "nonWildcardTypeArguments" on arrayCreation,
 *          which are illegal.
 *      Moved "nonWildcardTypeArguments into innerCreator.
 *      Removed 'super' superSuffix from explicitGenericInvocation, since that
 *          is only used in explicitConstructorInvocation at the beginning of a
 *           constructorBody.  (This is part of the simplification of expressions
 *           mentioned earlier.)
 *      Simplified primary (got rid of those things that are only used in
 *          explicitConstructorInvocation).
 *      Lexer -- removed "Exponent?" from FloatingPointLiteral choice 4, since it
 *          led to an ambiguity.
 *
 *      This grammar successfully parses every .java file in the JDK 1.5 source
 *          tree (excluding those whose file names include '-', which are not
 *          valid Java compilation units).
 *
 *  Known remaining problems:
 *      "Letter" and "JavaIDDigit" are wrong.  The actual specification of
 *      "Letter" should be "a character for which the method
 *      Character.isJavaIdentifierStart(int) returns true."  A "Java
 *      letter-or-digit is a character for which the method
 *      Character.isJavaIdentifierPart(int) returns true."
 */
grammar Java;

options {
backtrack=true;
memoize=true;

k = 2;
//exportVocab = NEWC;
}

/*========================================================================*/
/* HEADERS */

@lexer::header{
package cedp.src2src.frontend.java;

import java.io.*;
import antlr.CommonAST;
import antlr.DumpASTVisitor;
import java.util.*;
import cetus.hir.*;
import cetus.hir.java.*;
import org.antlr.runtime.BitSet;
import cetus.base.grammars.PreprocessorInfoChannel;
import cetus.base.grammars.LineObject;
}

@header {
package cedp.src2src.frontend.java;

import java.io.*;
import antlr.CommonAST;
import antlr.DumpASTVisitor;
import java.util.*;
import cetus.hir.*;
import cetus.hir.java.*;
import org.antlr.runtime.BitSet;
import cetus.base.grammars.PreprocessorInfoChannel;
}


/*========================================================================*/
/* METHODS */

@lexer::members{
protected boolean enumIsKeyword = true;
protected boolean assertIsKeyword = true;

public void initialize(String src)
{
  setOriginalSource(src);
  initialize();
}

public void initialize()
{
//  literals.put(new ANTLRHashString("__alignof__", this), new Integer(LITERAL___alignof__));
}

LineObject lineObject = new LineObject();
String originalSource = "";
PreprocessorInfoChannel preprocessorInfoChannel = new PreprocessorInfoChannel();
int tokenNumber = 0;
boolean countingTokens = true;
int deferredLineCount = 0;
int extraLineCount = 1;
JavaParser parser = null;

public void setCountingTokens(boolean ct)
{
  countingTokens = ct;
  if ( countingTokens ) {
    tokenNumber = 0;
  } else {
    tokenNumber = 1;
  }
}

public void setParser(JavaParser p)
{
  parser = p;
}

public void setOriginalSource(String src)
{
  originalSource = src;
  lineObject.setSource(src);
}

public void setSource(String src)
{
  lineObject.setSource(src);
}

public PreprocessorInfoChannel getPreprocessorInfoChannel()
{
  return preprocessorInfoChannel;
}

public void setPreprocessingDirective(String pre,int t)
{
  preprocessorInfoChannel.addLineForTokenNumber(
      new Pragma(pre,t), new Integer(tokenNumber));
}

protected Token makeToken(int t)
{
  if ( t != Token.SKIP && countingTokens) {
    tokenNumber++;
  }
  JavaToken tok = (JavaToken) super.makeToken(t);
  tok.setLine(lineObject.line);
  tok.setSource(lineObject.source);
  tok.setTokenNumber(tokenNumber);

  lineObject.line += deferredLineCount;
  deferredLineCount = 0;
  return tok;
}

public void deferredNewline()
{
  deferredLineCount++;
}

public void newline()
{
  lineObject.newline();
  setColumn(1);
}

}

@members{
// Copied following options from java grammar.
int codeGenMakeSwitchThreshold = 2;
int codeGenBitsetTestThreshold = 3;

Expression baseEnum = null,curEnum = null;
JavaLexer curLexer=null;
boolean isFuncDef = false;
boolean isExtern = false;
PreprocessorInfoChannel preprocessorInfoChannel = null;
SymbolTable symtab = null;
CompoundStatement curr_cstmt = null;
boolean hastypedef = false;
HashMap typetable = null;
LinkedList currproc = new LinkedList();
Declaration prev_decl = null;
boolean old_style_func = false;
HashMap func_decl_list = new HashMap();

public List MergeList(List a, List b)
{
    List ret = new LinkedList();

    for(int i=0; i<a.size(); i++)
        ret.add(a.get(i));

    for(int i=0; i<b.size(); i++)
        ret.add(b.get(i));

    return ret;
}

public void getPreprocessorInfoChannel(PreprocessorInfoChannel preprocChannel)
{
  preprocessorInfoChannel = preprocChannel;
}

public void setLexer(JavaLexer lexer)
{
  curLexer=lexer;
  curLexer.setParser(this);
}

public JavaLexer getLexer()
{
  return curLexer;
}

public LinkedList getPragma(int a)
{
  return
      preprocessorInfoChannel.extractLinesPrecedingTokenNumber(new Integer(a));
}

public void putPragma(Token sline, SymbolTable sym)
{
  LinkedList v  = null;
  v = getPragma(((JavaToken)sline).getTokenNumber());
  Iterator iter = v.iterator();
  Pragma p = null;
  PreAnnotation anote = null;
  while(iter.hasNext()) {
    p = (Pragma)iter.next();
    anote = new PreAnnotation(p.str);
    if (p.type ==Pragma.pragma)
      anote.setPrintMethod(PreAnnotation.print_raw_method);
    else if(p.type ==Pragma.comment)
      anote.setPrintMethod(PreAnnotation.print_raw_method);
    //sym.addStatement(new DeclarationStatement(anote));
    if (sym instanceof CompoundStatement)
      ((CompoundStatement)sym).addStatement(new DeclarationStatement(anote));
    else
      sym.addDeclaration(anote);
  }
}

// Suppport C++-style single-line comments?
public static boolean CPPComments = true;
public Stack symtabstack = new Stack();
public Stack typestack = new Stack();

public void enterSymtab(SymbolTable curr_symtab)
{
  symtabstack.push(symtab);
  typetable = new HashMap();
  typestack.push(typetable);
  symtab = curr_symtab;
}

public void exitSymtab()
{
  Object o = symtabstack.pop();
  if (o != null) {
    typestack.pop();
    typetable = (HashMap)(typestack.peek());
    symtab = (SymbolTable)o;
  }
}

public boolean isTypedefName(String name)
{
  //System.err.println("Typename "+name);
  int n = typestack.size()-1;
  Object d = null;
  while(n>=0) {
    d = ((HashMap)(typestack.get(n))).get(name);
    if (d != null )
      return true;
    n--;
  }
  if (name.equals("__builtin_va_list"))
    return true;

  //System.err.println("Typename "+name+" not found");
  return false;
}

int traceDepth = 0;

public void reportError(RecognitionException ex)
{
  try {
    System.err.println("ANTLR Parsing Error: " + "Exception Type: "
        + ex.getClass().getName());
    System.err.println("Source: " + getLexer().lineObject.getSource()
        + " Line:" + ex.getLine() + " Column: " + ex.getColumn()
        + " token name:" + tokenNames[LA(1)]);
    ex.printStackTrace(System.err);
    System.exit(1);
  } catch (TokenStreamException e) {
    System.err.println("ANTLR Parsing Error: "+ex);
    ex.printStackTrace(System.err);
    System.exit(1);
  }
}

public void reportError(String s)
{
  System.err.println("ANTLR Parsing Error from String: " + s);
}

public void reportWarning(String s)
{
  System.err.println("ANTLR Parsing Warning from String: " + s);
}

public void match(int t) throws MismatchedTokenException
{
  boolean debugging = false;
  if ( debugging ) {
    for (int x=0; x<traceDepth; x++)
      System.out.print(" ");
    try {
      System.out.println("Match(" + tokenNames[t] + ") with LA(1)="
          + tokenNames[LA(1)] + ((inputState.guessing>0)?
          " [inputState.guessing " + inputState.guessing + "]":""));
    } catch (TokenStreamException e) {
      System.out.println("Match("+tokenNames[t]+") "
          + ((inputState.guessing>0)?
          " [inputState.guessing "+ inputState.guessing + "]":""));
    }
  }
  try {
    if ( LA(1)!=t ) {
      if ( debugging ) {
        for (int x=0; x<traceDepth; x++)
          System.out.print(" ");
        System.out.println("token mismatch: "+tokenNames[LA(1)]
            + "!=" + tokenNames[t]);
      }
      throw new MismatchedTokenException
          (tokenNames, LT(1), t, false, getFilename());
    } else {
      // mark token as consumed -- fetch next token deferred until LA/LT
      consume();
    }
  } catch (TokenStreamException e) {
  }
}

public void traceIn(String rname)
{
  traceDepth += 1;
  for (int x=0; x<traceDepth; x++)
    System.out.print(" ");
  try {
    System.out.println("> "+rname+"; LA(1)==("+ tokenNames[LT(1).getType()]
        + ") " + LT(1).getText() + " [inputState.guessing "
        + inputState.guessing + "]");
  } catch (TokenStreamException e) {
  }
}

public void traceOut(String rname)
{
  for (int x=0; x<traceDepth; x++)
    System.out.print(" ");
  try {
    System.out.println("< "+rname+"; LA(1)==("+ tokenNames[LT(1).getType()]
        + ") " + LT(1).getText() + " [inputState.guessing "
        + inputState.guessing + "]");
  } catch (TokenStreamException e) {
  }
  traceDepth -= 1;
}

boolean dFlag = true;
Expression prev_expr;
}

/*========================================================================*/
/* BUILDING PARSE TREE */
/* SYNTAX */

// starting point for parsing a java file
/* The annotations are separated out to make parsing faster, but must be associated with
   a packageDeclaration or a typeDeclaration (and not an empty one). */
/* OK */
translationUnit [TranslationUnit init_tunit] returns [TranslationUnit tunit]
    @init {
        if(dFlag) System.out.println("translationUnit");
        /* build a new Translation Unit */
        if (init_tunit == null)
          tunit = new TranslationUnit(getLexer().originalSource);
        else
          tunit = init_tunit;
        enterSymtab(tunit);
    }
    @after{
        exitSymtab();
    }
    :   t1=annotations
                {
                    tunit.addDeclaration(t1);
                }
        (   t2=packageDeclaration
                {
                    tunit.addDeclaration(t2);
                }
            (t3=importDeclaration
                {
                    tunit.addDeclaration(t3);
                }
            )*
            (t4=typeDeclaration
                {
                    tunit.addDeclaration(t4);
                }
            )*
        |   t5=classOrInterfaceDeclaration
                {
                    tunit.addDeclaration(t5);
                }
            (t6=typeDeclaration
                {
                        tunit.addDeclaration(t6);
                }
            )*
        )
    |   (t7=packageDeclaration
                {
                    tunit.addDeclaration(t7);
                }
        )?
        (t8=importDeclaration
                {
                    tunit.addDeclaration(t8);
                }
        )*
        (t9=typeDeclaration
                {
                    tunit.addDeclaration(t9);
                }
        )*
    ;

/* OK */
packageDeclaration returns [Declaration ret_decl]
    @init { if(dFlag) System.out.println("packageDeclaration"); LinkedList list = new LinkedList(); }
    :   'package' qualifiedName ';'
            {
                list.add(new StringDeclaration("package"));
                list.add(new StringDeclaration($qualifiedName.text));
                list.add(new StringDeclaration(";"));
                ret_decl = new StringDeclaration(list);

                //CodeAnnotation anno = new CodeAnnotation("package " + $qualifiedName.text);
                //ret_decl = new AnnotationDeclaration(anno);
            }
    ;

/* OK */
importDeclaration returns [Declaration ret_decl]
    @init { if(dFlag) System.out.println("importDeclaration"); LinkedList list = new LinkedList();
            // int check1=0, check2=0;
          }
    :   'import'
            {
                list.add(new StringDeclaration("import"));
            }
        ('static'
            {
                //check1 = 1;
                list.add(new StringDeclaration("static"));
            }
        )?
        t1=qualifiedName
            {
                list.add(new StringDeclaration($t1.text));
            }
        ('.' '*'
            {
                //check2 = 1;
                list.add(new StringDeclaration(".*"));
            }
        )? ';'
            {
                list.add(new StringDeclaration(";"));
                ret_decl = new StringDeclaration(list);

                //CodeAnnotation anno = new CodeAnnotation("import " + ((check1==1)?"static ":"") + $t1.text + ((check2==1)?".*":"") + ";");
                //ret_decl = new AnnotationDeclaration(anno);
            }
    ;

/* OK */
typeDeclaration returns [Declaration ret_decl]
    @init { if(dFlag) System.out.println("typeDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=classOrInterfaceDeclaration
            {
                ret_decl = t1;
            }
    |   ';'
            {
                //ret_decl = null;
                ret_decl = new StringDeclaration(";");
            }
    ;

/* OK */
classOrInterfaceDeclaration returns [Declaration ret_decl]
    @init { if(dFlag) System.out.println("classOrInterfaceDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=classOrInterfaceModifiers
        (t2=classDeclaration
            {
                list.add(t1);
                list.add(t2);
                ret_decl = new StringDeclaration(list);
//                t2.SetClassSpec(t1);
//                ret_decl = (Declaration) t2;
            }
        | t3=interfaceDeclaration
            {
                list.add(t1);
                list.add(t3);
                ret_decl = new StringDeclaration(list);
//                t3.SetClassSpec(t1);
//                ret_decl = (Declaration) t3;
            }
        )
    ;

/* OK */
classOrInterfaceModifiers returns [Declaration ret_decl] // [LinkedList list]
    @init { if(dFlag) System.out.println("classOrInterfaceModifiers");  LinkedList list = new LinkedList(); }
    :   (t1=classOrInterfaceModifier
            {
                list.add(t1); // original
            }
        )*
            {
                ret_decl = new StringDeclaration(list);
            }
    ;

/* OK */
classOrInterfaceModifier returns [Declaration ret_decl] //[Specifier type]
    @init { if(dFlag) System.out.println("classOrInterfaceModifier"); LinkedList list = new LinkedList(); }
    :   t1=annotation   // class or interface
            {
            //    type = t1;
                ret_decl = 51;
            }
    |   'public'     // class or interface
            {
                //type = Specifier.PUBLIC;
                ret_decl = new StringDeclaration("public");
            }
    |   'protected'  // class or interface
            {
                //type = Specifier.PROTECTED;
                ret_decl = new StringDeclaration("protected");
            }
    |   'private'    // class or interface
            {
                //type = Specifier.PRIVATE;
                ret_decl = new StringDeclaration("private");
            }
    |   'abstract'   // class or interface
            {
                //type = Specifier.ABSTRACT;
                ret_decl = new StringDeclaration("abstract");
            }
    |   'static'     // class or interface
            {
                //type = Specifier.STATIC;
                ret_decl = new StringDeclaration("static");
            }
    |   'final'      // class only -- does not apply to interfaces
            {
                //type = Specifier.FINAL;
                ret_decl = new StringDeclaration("final");
            }
    |   'strictfp'   // class or interface
            {
                //type = Specifier.STRICTFP;
                ret_decl = new StringDeclaration("strictfp");
            }
    ;

/* OK */
modifiers returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("modifiers"); LinkedList list = new LinkedList(); }
    :   (t1=modifier
            {
                //list.add(t1);
                ret_decl = t1;
            }
        )*
    ;

/* OK */
classDeclaration returns [Declaration ret_decl] //[ClassDeclaration decl]
    @init { if(dFlag) System.out.println("classDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=normalClassDeclaration
            {
                ret_decl = t1;
            }
    |   t2=enumDeclaration
            {
                ret_decl = t2;
            }
    ;

/* OK */
normalClassDeclaration returns [Declaration ret_decl] //[ClassDeclaration ret_decl]
    @init { if(dFlag) System.out.println("normalClassDeclaration"); int check1 = 0; LinkedList list = new LinkedList(); }
    :   'class' Identifier
            {
                list.add(new StringDeclaration("class"));
                list.add(new StringDeclaration($Identifier.text));
            }
        (t1=typeParameters
            {
                list.add(t1);
            }
        )?
        ('extends' t2=type
            {
                //check1 = 1;
                list.add(new StringDeclaration("extends"));
                list.add(t2);
            }
        )?
        ('implements' t3=typeList
            {
                //check1 = 1;
                list.add(new StringDeclaration("implements"));
                list.add(t3);
            }
        )?
        t4=classBody
            {
                list.add(t4);
                ret_decl = new StringDeclaration(list);
                //ret_decl = new ClassDeclaration(ClassDeclaration.CLASS, new NameID($Identifier.text));
                //ret_decl.SetBodyStatement(t1);
                /* TODO extends and implments supports */
                //if(check1 == 1)
                //    ret_decl.addBaseInterface(t2); // t2 is List of Specifier
            }
    ;

typeParameters returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("typeParameters"); LinkedList list = new LinkedList(); }
    :   '<' t1=typeParameter
            {
                list.add(new StringDeclaration("<"));
                list.add(t1);
            }
        (',' t2=typeParameter
            {
                list.add(new StringDeclaration(","));
                list.add(t2);
            }
        )* '>'
            {
                list.add(new StringDeclaration(">"));
                ret_decl = new StringDeclaration(list);
            }
    ;

typeParameter returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("typeParameter"); LinkedList list = new LinkedList(); }
    :   Identifier
            {
                ret_decl = new StringDeclaration($Identifier.text);
                list.add(ret_decl);
            }
        ('extends' t1=typeBound
            {
                list.add(new StringDeclaration("extends"));
                list.add(t1);
                ret_decl = new StringDeclaration(list);
            }
        )?
    ;

typeBound returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("typeBound"); LinkedList list = new LinkedList(); }
    :   t1=type
            {
                ret_decl = t1;
                list.add(t1);
            }
        ('&' t2=type
            {
                list.add(new StringDeclaration("&"));
                list.add(t2);
                ret_decl = new StringDeclaration(list);
            }
        )*
    ;

enumDeclaration returns [Declaration ret_decl] //[ClassDeclaration ret_decl]
    @init { if(dFlag) System.out.println("enumDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=ENUM Identifier
            {
                list.add(t1);
                list.add(new StringDeclaration($Identifier.text));
            }
        ('implements' t2=typeList
            {
                list.add(new StringDeclaration("implements"));
                list.add(t2);
            }
        )? t3=enumBody
            {
                list.add(t3);
                ret_decl = new StringDeclaration(list);
                //ret_decl = new ClassDeclaration(Specifier.ENUM, new NameID($Identifier.text));
                //for(int i=0; i<t1.size(); i++)
                //    ret_decl.addDeclaration(t1.get(i));
                /* TODO implements support */
            }
    ;

enumBody returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("enumBody"); LinkedList list = new LinkedList(); }
    :   '{'
            {
                list.add(new StringDeclaration("{"));
            }
        (t1=enumConstants
            {
                list.add(t1);
                //for(int i=0; i<t1.size(); i++)
                //    list.add(t1.get(i));
            }
        )?
        (','
            {
                list.add(new StringDeclaration(","));
            }
        )?
        (t2=enumBodyDeclarations
            {
                list.add(t2);
                /* TODO */
                //list = new LinkedList();
            }
        )?
        '}'
            {
                list.add(new StringDeclaration("}"));
                ret_decl = new StringDeclaration(list);
            }
    ;

enumConstants returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("enumConstants"); LinkedList list = new LinkedList(); }
    :   t1=enumConstant
            {
                list.add(t1);
                ret_decl = t1;
            }
        (',' t2=enumConstant
            {
                list.add(new StringDeclaration(","));
                list.add(t2);
                ret_decl = new StringDeclaration(list);
            }
        )*
    ;

enumConstant returns [Declaration ret_decl] //[VariableDeclarator ret_decl]
    @init { if(dFlag) System.out.println("enumConstant"); LinkedList list = new LinkedList(); }
    :   (t1=annotations
            {
                list.add(t1);
            }
        )? Identifier t2=arguments? t3=classBody?
            {
                list.add(new StringDeclaration($Identifier.text));
                if(t2 != null)
                    list.add(t2);
                if(t3 != null)
                    list.add(t3);
                ret_decl = new StringDeclaration(list);
                //ret_decl = new VariableDeclarator($Identifier.text);
                /* TODO */
            }
    ;

enumBodyDeclarations returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("enumBodyDeclarations"); LinkedList list = new LinkedList(); }
    :   ';'
            {
                ret_decl = new StringDeclaration(";");
                list.add(ret_decl);
            }
        (t1=classBodyDeclaration
            {
                list.add(t1);
                ret_decl = new StringDeclaration(list);
            }
        )*
    ;

interfaceDeclaration returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("interfaceDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=normalInterfaceDeclaration
            {
                ret_decl = t1;
            }
    |   t2=annotationTypeDeclaration
            {
                ret_decl = t2;
            }
    ;

normalInterfaceDeclaration returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("normalInterfaceDeclaration"); LinkedList list = new LinkedList(); }
    :   'interface' Identifier t1=typeParameters? ('extends' t2=typeList)? t3=interfaceBody
            {
                list.add(new StringDeclaration("interface"));
                list.add(new StringDeclaration($Identifier.text));
                if(t1 != null)
                    list.add(t1);
                if(t2 != null){
                    list.add(new StringDeclaration("extends"));
                    list.add(t2);
                }
                list.add(t3);
                ret_decl = new StringDeclaration(list);
            }
    ;

typeList returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("typeList"); LinkedList list = new LinkedList(); }
    :   t1=type
            {
                ret_decl = t1;
                list.add(t1);
                //list = t1;
            }
        (',' t2=type
            {
                list.add(new StringDeclaration(","));
                list.add(t2);
                ret_decl = new StringDeclaration(list);
                //for(int i=0; i<t2.size(); i++)
                //    list.add(t2.get(i));
            }
        )*
    ;

classBody returns [Declaration ret] //[CompoundStatement ret_stat]
    @init { if(dFlag) System.out.println("classBody"); LinkedList list = new LinkedList(); }
    :   '{' ( t1=classBodyDeclaration
                {
                    list.add(t1);
                    //if(t1 != null)
                    //    ret_stat.addDeclaration((Declaration)t1);
                }
         )* '}'
                {
                    list.addFirst(new StringDeclaration("{"));
                    list.addLast(new StringDeclaration("}"));
                    ret = new StringDeclaration(list);
                }
    ;

interfaceBody returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("interfaceBody"); LinkedList list = new LinkedList(); }
    :   '{' (t1=interfaceBodyDeclaration
                {
                    list.add(t1);
                }
        )* '}'
                {
                    list.addFirst(new StringDeclaration("{"));
                    list.addLast(new StringDeclaration("}"));
                    ret_decl = new StringDeclaration(list);
                }
    ;

classBodyDeclaration returns [Declaration ret_decl] //[Declaration ret_decl]
    @init { if(dFlag) System.out.println("classBodyDeclaration"); int check; LinkedList list = new LinkedList(); }
    :   ';'
            {
                ret_decl = new StringDeclaration(";");
                //ret_decl = null;
                //ret_decl = new NullStatement();
            }
    |   {check=0;} ('static' {check=1;})? t1=block
            {
                if(check == 1){
                    list.add(new StringDeclaration("static"));
                    list.add(t1);
                    ret_decl = new StringDeclaration(list);
                    //ret_decl = t1;  /* Need to handle 'static' */
                }
                else
                    ret_decl = t1;
                    //ret_decl = t2;
            }
    |   t3=modifiers t4=memberDecl
            {
                list.add(t3);
                list.add(t4);
                ret_decl = new StringDeclaration(list);
                //ret_decl = t4;
                /* TODO t3? */
            }
    ;

memberDecl returns [Declaration ret_decl] //[Declaration ret_decl]
    @init { if(dFlag) System.out.println("memberDecl"); LinkedList list = new LinkedList(); }
    :   t1=genericMethodOrConstructorDecl
            {
                ret_decl = t1;
            }
    |   t2=memberDeclaration
            {
                ret_decl = t2;
            }
    |   'void' Identifier t3=voidMethodDeclaratorRest
            {
                list.add(new StringDeclaration("void"));
                list.add(new StringDeclaration($Identifier.text));
                list.add(t3);
                ret_decl = new StringDeclaration(list);

                //List l1 = new LinkedList();
                //li.add(Specifier.VOID);
                //ProcedureDeclarator pdecl = new ProcedureDeclarator(l1, new NameID($Identifier.text), (List)t3.get(0));
                //ret_decl = new Procedure(Specifier.VOID, pdecl, (t3.size()>1)?t3.get(1):null);
            }
    |   Identifier t4=constructorDeclaratorRest
            {
                list.add(new StringDeclaration($Identifier.text));
                list.add(t4);
                ret_decl = new StringDeclaration(list);
               // ProcedureDeclarator pdecl = new ProcedureDeclarator(new NameID($Identifier.text), (List)t4.get("param"));
               // ret_decl = new Procedure(pdecl, (CompoundStatement)t4.get("body"));
            }
    |   t5=interfaceDeclaration
            {
                ret_decl = t5;
            }
    |   t6=classDeclaration
            {
                ret_decl = t6;
            }
    ;

memberDeclaration returns [Declaration ret_decl] //[Declaration ret_decl]
    @init { if(dFlag) System.out.println("memberDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=type (t2=methodDeclaration | t3=fieldDeclaration )
                {
                    list.add(t1);
                    if(t2 != null)
                        list.add(t2);
                    if(t3 != null)
                        list.add(t3);
                    ret_decl = new StringDeclaration(list);

                    //if(t2.containsKey("body")){
                    //    ProcedureDeclarator pdec = new ProcedureDeclarator((IDExpression)t2.get("id"), (List)t2.get("param"));
                    //    ret_decl = new Procedure(t1, pdec, (CompoundStatement)t2.get("body"));
                    //}
                    //else{
                    //    VariableDeclarator vdec = new VariableDeclarator((IDExpression)t2.get("id"));
                    //    ret_decl = new VariableDeclaration(t1, vdec);
                    //}
                    //if(t3.getNumDeclarators() > 0){
                    //    VariableDeclaration temp = new VariableDeclaration(t1, (Declarator)t3.getDeclarator(0));
                    //    for(int i=1; i<t3.getNumDeclarators(); i++)
                    //        temp.addDeclarator((Declarator)t3.getDeclarator(i));
                    //   ret_decl = temp;
                    //}
                    //else
                    //    ret_decl = t3;
                }
    ;

genericMethodOrConstructorDecl returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("genericMethodOrConstructorDecl"); LinkedList list = new LinkedList(); }
    :   t1=typeParameters t2=genericMethodOrConstructorRest
            {
                list.add(t1);
                list.add(t2);
                ret_decl = new StringDeclaration(list);
            }
    ;

genericMethodOrConstructorRest returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("genericMethodOrConstructorRest"); LinkedList list = new LinkedList(); }
    :   (t1=type | 'void') t2=Identifier t3=methodDeclaratorRest
            {
                if(t1 != null)
                    list.add(t1);
                else
                    list.add(new StringDeclaration("void"));
                list.add(new StringDeclaration($t2.text));
                list.add(t3);
                ret_decl = new StringDeclaration(list);
            }
    |   t4=Identifier t5=constructorDeclaratorRest
            {
                list.add(new StringDeclaration($t4.text));
                list.add(t5);
                ret_decl = new StringDeclaration(list);
            }
    ;

methodDeclaration returns [Declaration ret_decl] //[Hashtable hash]
    @init { if(dFlag) System.out.println("methodDeclaration"); LinkedList list = new LinkedList(); }
    :   Identifier t1=methodDeclaratorRest
            {
                //hash = t1;
                //hash.put("id", new NameID($Identifier.text));
                list.add(new StringDeclaration($Identifier.text));
                list.add(t1);
                ret_decl = new StringDeclaration(list);
            }
    ;

fieldDeclaration returns [Declaration ret_decl] //[VariableDeclaration ret_decl]
    @init { if(dFlag) System.out.println("fieldDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=variableDeclarators ';'
            {
                //ret_decl = new VariableDeclaration((Declarator)t1.get(0));
                //for(int i=1; i<t1.size(); i++)
                //    ret_decl.addDeclarator((Declarator)t1.get(i));
                list.add(t1);
                list.add(new StringDeclaration(";"));
                ret_decl = new StringDeclaration(list);
            }
    ;

interfaceBodyDeclaration returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("interfaceBodyDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=modifiers t2=interfaceMemberDecl
            {
                list.add(t1);
                list.add(t2);
                ret_decl = new StringDeclaration(list);
            }
    |   ';'
            {
                ret_decl = new StringDeclaration(";");
            }
    ;

interfaceMemberDecl returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("interfaceMemberDecl"); LinkedList list = new LinkedList(); }
    :   t1=interfaceMethodOrFieldDecl
            {
                ret_decl = t1;
            }
    |   t2=interfaceGenericMethodDecl
            {
                ret_decl = t2;
            }
    |   'void' Identifier t3=voidInterfaceMethodDeclaratorRest
            {
                list.add(new StringDeclaration("void"));
                list.add(new StringDeclaration($Identifier.text));
                list.add(t3);
                ret_decl = new StringDeclaration(list);
            }
    |   t4=interfaceDeclaration
            {
                ret_decl = t4;
            }
    |   t5=classDeclaration
            {
                ret_decl = t5;
            }
    ;

interfaceMethodOrFieldDecl returns [Declaration ret_decl] //[Declarator ret_decl]
    @init { if(dFlag) System.out.println("interfaceMethodOrFieldDecl"); LinkedList list = new LinkedList(); }
    :   t1=type Identifier t2=interfaceMethodOrFieldRest
            {
                list.add(t1);
                list.add(new StringDeclaration($Identifier.text));
                list.add(t3);
                ret_decl = new StringDeclaration(list);
                //new Declarator()
            }
    ;

interfaceMethodOrFieldRest returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("interfaceMethodOrFieldRest"); LinkedList list = new LinkedList(); }
    :   t1=constantDeclaratorsRest ';'
            {
                list.add(t1);
                list.add(new StringDeclaration(";"));
                ret_decl = new StringDeclaration(list);
            }
    |   t2=interfaceMethodDeclaratorRest
            {
                ret_decl = t2;
            }
    ;

methodDeclaratorRest returns [Declaration ret_decl] //[Hashtable hash]
    @init { if(dFlag) System.out.println("methodDeclaratorRest"); LinkedList list = new LinkedList(); }
    :   t1=formalParameters
            {
                list.add(t1);
            }
        ('[' ']'
            {
                list.add(new StringDeclaration("[]"));
            }
        )*
        ('throws' t2=qualifiedNameList
            {
                list.add(new StringDeclaration("throws"));
                list.add(t2);
//                hash.put("throw", ExceptionSpecifier = new ExceptionSpecification(t2));
            }
        )?
        (   t3=methodBody
            {
                list.add(t3);
//                hash.put("body", t3);
                ret_decl = new StringDeclaration(list);
            }
        |   ';'
            {
                list.add(new StringDeclaration(";"));
                ret_decl = new StringDeclaration(list);
            }
        )
    ;

voidMethodDeclaratorRest returns [Declaration ret_decl] //[Hashtable hash]
    @init { if(dFlag) System.out.println("voidMethodDeclaratorRest"); LinkedList list = new LinkedList(); }
    :   t1=formalParameters
            {
                list.add(t1);
//                hash.put("param", t1);
            }
        ('throws' t2=qualifiedNameList
            {
                list.add(new StringDeclaration("throws"));
                list.add(t2);
                //hash.put("throw", ExceptionSpecifier = new ExceptionSpecification(t2));
            }
        )?
        (   t3=methodBody
            {
                list.add(t3);
                ret_decl = new StringDeclaration(list);
//                hash.put("body", t3);
            }
        |   ';'
        )
    ;

interfaceMethodDeclaratorRest returns [Declaration ret_decl] //[Hashtable hash]
    @init { if(dFlag) System.out.println("interfaceMethodDeclaratorRest"); LinkedList list = new LinkedList(); }
    :   t1=formalParameters
            {
                list.add(t1);
                //hash.put("param", t1);
            }
        ('[' ']'
            {
                list.add(new StringDeclaration("[]"));
            }
        )*
        ('throws' t2=qualifiedNameList
            {
                list.add(new StringDeclaration("throws"));
                list.add(t2);
                //hash.put("throw", ExceptionSpecifier = new ExceptionSpecification(t2));
            }
        )? ';'
            {
                list.add(new StringDeclaration(";"));
                ret_decl = new StringDeclaration(list);
            }
    ;


interfaceGenericMethodDecl returns [Declaration ret_decl] //
    @init { if(dFlag) System.out.println("interfaceGenericMethodDecl"); LinkedList list = new LinkedList(); }
    :   t1=typeParameters (t2=type | 'void') Identifier t3=interfaceMethodDeclaratorRest
            {
                list.add(t1);
                if(t2 != null)
                    list.add(t2);
                else
                    list.add(new StringDeclaration("void"));
                list.add(new StringDeclaration($Identifier.text));
                list.add(t3);
                ret_decl = new StringDeclaration(list);
            }
    ;

voidInterfaceMethodDeclaratorRest returns [Declaration ret_decl] //[Hashtable hash]
    @init { if(dFlag) System.out.println("voidInterfaceMethodDeclaratorRest"); LinkedList list = new LinkedList(); }
    :   t1=formalParameters ('throws' t2=qualifiedNameList)? ';'
            {
                list.add(t1);
                if(t2 != null)
                    list.add(t2);
                else
                    list.add(new StringDeclaration("throws"));
                list.add(new StringDeclaration(";"));
                ret_decl = new StringDeclaration(list);
                //hash.put("param", t1);
                //hash.put("throw", ExceptionSpecifier = new ExceptionSpecification(t2));
            }
    ;

constructorDeclaratorRest returns [Declaration ret_decl] //[Hashtable hash]
    @init { if(dFlag) System.out.println("constructorDeclaratorRest"); LinkedList list = new LinkedList(); }
    :   t1=formalParameters ('throws' t2=qualifiedNameList)? t3=constructorBody
            {
                list.add(t1);
                if(t2 != null)
                    list.add(t2);
                else
                    list.add(new StringDeclaration("throws"));
                list.add(new StringDeclaration(";"));
                ret_decl = new StringDeclaration(list);

                //hash.put("param", t1);
                //hash.put("throw", t2);
                //if(t3 != null)
                //    hash.put("body", t3);
            }
    ;

constantDeclarator returns [Declaration ret_decl] //[VariableDeclarator ret_decl]
    @init { if(dFlag) System.out.println("constantDeclarator"); LinkedList list = new LinkedList(); }
    :   Identifier t1=constantDeclaratorRest
            {
                list.add(new StringDeclaration($Identifier.text));
                list.add(t1);
                ret_decl = new StringDeclaration(list);
                //ret_decl = new VariableDeclarator(new NameID($Identifier.text));
                //ret_decl.setInitializer(t1);
            }
    ;

variableDeclarators returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("variableDeclarators"); LinkedList list = new LinkedList(); }
    :   t1=variableDeclarator
        (',' t2=variableDeclarator
            {
                list.add(t2);
            }
        )*
            {
                list.addFirst(t1);
                ret_decl = new StringDeclaration(list);
            }
    ;

/* OK */
variableDeclarator returns [Declaration ret] //[VariableDeclarator ret_decl]
    @init { if(dFlag) System.out.println("variableDeclarator"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=variableDeclaratorId
            {
                list.add(t1);
            }
        ('=' t2=variableInitializer
            {
                list.add(new StringDeclaration("="));
                list.add(t2);
                //ret_decl = new VariableDeclarator(t1);
                //if(t2 != null) ret_decl.setInitializer(t2);
            }
        )?
    ;

/* OK */
constantDeclaratorsRest returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("constantDeclaratorsRest"); LinkedList list = new LinkedList(); }
    :   t1=constantDeclaratorRest (',' t2=constantDeclarator
            {
                list.add(new StringDeclaration(","));
                list.add(t2);
            }
        )*
            {
                list.addFirst(t1);
                ret_decl = new StringDeclaration(list);
                //list.add(new Initializer(t1));
            }
    ;

/* OK */
constantDeclaratorRest returns [Declaration ret_decl] //[Initializer ret_init]
    @init { if(dFlag) System.out.println("constantDeclaratorRest"); LinkedList list = new LinkedList(); }
    :   ('[' ']'
            {
                list.add(new StringDeclaration("[]"));
            }
        )* '=' t1=variableInitializer
            {
                list.add(new StringDeclaration("="));
                list.add(t1);
                ret_decl = new StringDeclaration(list);
                //ret_init = new Initializer(t1);
            }
    ;

/* OK */
variableDeclaratorId returns [Declaration ret_decl] //[IDExpression ret_id]
    @init { if(dFlag) System.out.println("variableDeclaratorId"); LinkedList list = new LinkedList(); }
    :   Identifier
        ('[' ']'
            {
                list.add(new StringDeclaration("[]"));
                //ret_id = ret_id;
                /* TODO */
            }
        )*
            {
                list.addFirst(new StringDeclaration($Identifier.text));
                ret_decl = new StringDeclaration(list);
                //ret_id = new NameID($Identifier.text);
            }
    ;

/* OK */
variableInitializer returns [Declaration ret_decl] //[Initializer init]
    @init { if(dFlag) System.out.println("variableInitializer"); LinkedList list = new LinkedList(); }
    :   t1=arrayInitializer
            {
                ret_decl = t1;
                //init = t1;
            }
    |   t2=expression
            {
                ret_decl = t2;
                //if(t2 != null) init = new Initializer(t2);
            }
    ;

/* OK */
arrayInitializer returns [Declaration ret_decl] //[Initializer init]
    @init { if(dFlag) System.out.println("arrayInitializer"); LinkedList list = new LinkedList(); }
    :   '{' (t1=variableInitializer
         (',' t2=variableInitializer
                {
                    list.add(new StringDeclaration(","));
                    list.add(t2);
                    //List tlist = variableInitializer.getChildren();
                    //for(int i=0; i<tlist.size(); i++)
                    //list.add(tlist.get(i));
                }
        )* (','
                {
                    list.add(new StringDeclaration(","));
                }
        )? )? '}'
                {
                    if(t1 != null)
                        list.addFirst(t1);
                    list.addFirst(new StringDeclaration("{"));
                    list.addLast(new StringDeclaration("}"));
                    ret_decl = new StringDeclaration(list);

                    //List tlist = variableInitializer.getChildren();
                    //for(int i=0; i<tlist.size(); i++)
                    //    list.add(tlist.get(i));
                    //init = new Initializer(list);
                }
    ;

modifier returns [Declaration ret_decl] //[Specifier type]
    @init { if(dFlag) System.out.println("modifier"); LinkedList list = new LinkedList(); }
    :   t1=annotation
            {
                ret_decl = t1;
                //type = t1;
            }
    |   'public'
            {
                ret_decl = new StringDeclaration("public");
                //type = Specifier.PUBLIC;
            }
    |   'protected'
            {
                ret_decl = new StringDeclaration("protected");
                //type = Specifier.PROTECTED;
            }
    |   'private'
            {
                ret_decl = new StringDeclaration("private");
                //type = Specifier.PRIVATE;
            }
    |   'static'
            {
                ret_decl = new StringDeclaration("static");
                //type = Specifier.STATIC;
            }
    |   'abstract'
            {
                ret_decl = new StringDeclaration("abstract");
                //type = Specifier.ABSTRACT;
            }
    |   'final'
            {
                ret_decl = new StringDeclaration("final");
                //type = Specifier.FINAL;
            }
    |   'native'
            {
                ret_decl = new StringDeclaration("native");
                //type = Specifier.NATIVE;
            }
    |   'synchronized'
            {
                ret_decl = new StringDeclaration("synchronized");
                //type = Specifier.SYNCHRONIZED;
            }
    |   'transient'
            {
                ret_decl = new StringDeclaration("transient");
                //type = Specifier.TRANSIENT;
            }
    |   'volatile'
            {
                ret_decl = new StringDeclaration("volatile");
                //type = Specifier.VOLATILE;
            }
    |   'strictfp'
            {
                ret_decl = new StringDeclaration("strictfp");
                //type = Specifier.STRICTFP;
            }
    ;

packageOrTypeName /* Intended */
    @init { if(dFlag) System.out.println("packageOrTypeName"); }
    :   t1=qualifiedName
    ;


/* OK */
enumConstantName returns [Declaration ret_decl] //[Identifier id]
    @init { if(dFlag) System.out.println("enumConstantName"); Identifier id_temp = null; LinkedList list = new LinkedList(); }
    :   t1=Identifier
            {
                ret_decl = new StringDeclaration($t1.text);
                //id = new Identifier(id_temp);
            }
    ;

typeName /* Intended */
    @init { if(dFlag) System.out.println("typeName"); }
    :   qualifiedName
    ;

type returns [Declaration ret] //[List types]
    @init { if(dFlag) System.out.println("type"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    : t1=classOrInterfaceType
        {
            list.add(t1);
            //if(t1 != null)
            //    types.add(t1);
        }
      ('[' ']'
            {
                list.add(new StringDeclaration("[]"));
                //types.add(new ArraySpecifier());
            }
      )*
    | t2=primitiveType
            {
                list.add(t2);
                //types.add(t2); /* TODO ('[' ']')* */
            }
       ('[' ']'
            {
                list.add(new StringDeclaration("[]"));
//                types.add(new ArraySpecifier());
            }
       )*
    ;

classOrInterfaceType returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("classOrInterfaceType"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    : t1=Identifier (t2=typeArguments)?
        {
            list.add(new StringDeclaration($t1.text));
            if(t2 != null)
                list.add(t2);
        }
      ('.' t3=Identifier t4=typeArguments?
        {
            list.add(new StringDeclaration("."));
            list.add(new StringDeclaration($t3.text));
            if(t4 != null)
                list.add(t4);
            //ret_expr = new AccessExpression(ret_expr, AccessOperator.MEMBER_ACCESS, new NameID($t3.text));
        }
      )*
    ;
/*
            if(t2 != null && t2.containsKey("argument")){
                if(!t2.containsKey("body")){
                    Expression arg = t2.get("argument");
                    if(arg instanceof OperatorID)
                        ret_expr = new FunctionCall(new NameID($t1.text));
                    else
                        ret_expr = new FunctionCall(new NameID($t1.text), arg);
                }
                else{
                    // TODO
                }
            }
            else{
                */

/* OK */
primitiveType returns [Declaration ret_decl] //[Specifier type]
    @init { if(dFlag) System.out.println("primitiveType"); LinkedList list = new LinkedList(); }
    :   'boolean'
            {
                ret_decl = new StringDeclaration("boolean");
                //type = Specifier.BOOLEAN;
            }
    |   'char'
            {
                ret_decl = new StringDeclaration("char");
                //type = Specifier.CHAR;
            }
    |   'byte'
            {
                ret_decl = new StringDeclaration("byte");
                //type = Specifier.BYTE;
            }
    |   'short'
            {
                ret_decl = new StringDeclaration("short");
                //type = Specifier.SHORT;
            }
    |   'int'
            {
                ret_decl = new StringDeclaration("int");
                //type = Specifier.INT;
            }
    |   'long'
            {
                ret_decl = new StringDeclaration("long");
                //type = Specifier.LONG;
            }
    |   'float'
            {
                ret_decl = new StringDeclaration("float");
                //type = Specifier.FLOAT;
            }
    |   'double'
            {
                ret_decl = new StringDeclaration("double");
                //type = Specifier.DOUBLE;
            }
    ;

variableModifier returns [Declaration ret] //[Specifier anno]
    @init { if(dFlag) System.out.println("variableModifier"); }
    :   'final'
            {
                ret = new StringDeclaration("final");
                //anno = Specifier.final;
            }
    |   t1=annotation
            {
                ret = t1;
                //anno = t1;
            }
    ;

typeArguments returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("typeArguments"); LinkedList list = new LinkedList(); }
    :   '<' t1=typeArgument
        (',' t2=typeArgument
            {
                list.add(new StringDeclaration(","));
                list.add(t2);
                //list.add(t2);
                //ret_expr = new TypeParamExpression(list);
            }
        )* '>'
            {
                list.addFirst(t1);
                list.addFirst(new StringDeclaration("<"));
                list.addLast(new StringDeclaration(">"));
                ret = new StringDeclaration(list);
                //list.add(t1);
                //ret_expr = new TypeParamExpression(list);
            }
    ;

/* OK */
typeArgument returns [Declaration ret_decl] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("typeArgument"); LinkedList list = new LinkedList(); }
    @after { ret_decl = new StringDeclaration(list); }
    :   t1=type
            {
                list.add(t1);
                //LinkedList list = new LinkedList();
                //for(int i=0; i<t1.size(); i++)
                //    list.add(new StringExpression(t1.get(i).toString()));
                //ret_expr = new StringExpression(list);
            }
    |   '?'
                {
                    list.add(new StringDeclaration("?"));
                }
        (('extends'
                {
                    list.add(new StringDeclaration("extends"));
                    //ret_expr.addExpression(new StringDeclaration("?"));
                    //ret_expr.addExpression(new StringDeclaration("extends"));
                }
            | 'super'
                {
                    list.add(new StringDeclaration("super"));
                    //ret_expr.addExpression(new StringDeclaration("?"));
                    //ret_expr.addExpression(new StringDeclaration("super"));
                }
            ) t2=type
                {
                    list.add(t2);
                    //LinkedList list = new LinkedList();
                    //for(int i=0; i<t2.size(); i++)
                    //    ret_expr.addExpression(new StringDeclaration(t2.get(i).toString()));
                }
        )?
    ;

qualifiedNameList returns [Declaration ret] //[List list]
    @init { if(dFlag) System.out.println("qualifiedNameList"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=qualifiedName
            {
                list.add(new StringDeclaration($t1.text));
            }
        (',' t2=qualifiedName
            {
                list.add(new StringDeclaration(","));
                list.add(new StringDeclaration($t2.text));
            }
        )*
    ;

formalParameters returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("formalParameters"); LinkedList list = new LinkedList(); }
    @after { ret_decl = new StringDeclaration(list); }
    :   '(' (t1=formalParameterDecls
                {
                    list.add(t1);
                    //list = t1;
                }
            )?
        ')'
            {
                list.addFirst(new StringDeclaration("("));
                list.addLast(new StringDeclaration(")"));
            }
    ;

formalParameterDecls returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("formalParameterDecls"); LinkedList list = new LinkedList(); }
    @after { ret_decl = new StringDeclaration(list); }
    :   t1=variableModifiers t2=type t3=formalParameterDeclsRest
            {
                list.add(t1);
                list.add(t2);
                list.add(t3);
                //List tlist = new LinkedList();
                //VariableDeclarator var_decl = new VariableDeclarator((IDExpression)t3.get(0));
                //VariableDeclaration vdec = new VariableDeclaration(MergeList(t1, t2), var_decl);
                //tlist.add(vdec);
                //t3.remove(0);
                //list = MergeList(tlist, t3);
            }
    ;

formalParameterDeclsRest returns [Declaration ret_decl] //[List list]
    @init { if(dFlag) System.out.println("formalParameterDeclsRest"); LinkedList list = new LinkedList(); }
    @after { ret_decl = new StringDeclaration(list); }
    :   t1=variableDeclaratorId
            {
                list.add(t1);
            }
        (',' t2=formalParameterDecls
            {
                list.add(new StringDeclaration(","));
                list.add(t2);
                //for(int i=0; i<t2.size(); i++)
                //    list.add(t2.get(i));
            }
        )?
    |   '...' t3=variableDeclaratorId
            {
                list.add(new StringDeclaration("..."));
                list.add(t3);
                //System.err.println("Supported ... argument\n");
                //System.exit(-1);
                /* TODO SUPPORT! */
            }
    ;

methodBody returns [Declaration ret_decl] //[Statement stat]
    @init { if(dFlag) System.out.println("methodBody"); LinkedList list = new LinkedList(); }
    :   t1=block
            {
                ret_decl = t1;
                //stat = t1;
            }
    ;

constructorBody returns [Declaration ret] //[CompoundStatement ret_stat]
    @init { if(dFlag) System.out.println("constructorBody"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '{' (t1=explicitConstructorInvocation)?
        (t2=blockStatement
            {
                list.add(t2);
               //ret_stat.addStatement(t2);
            }
        )* '}'
            {
                if(t1 != null)
                    list.addFirst(t1);
                list.addFirst(new StringDeclaration("{"));
                list.addLast(new StringDeclaration("}"));
            }
    ;

explicitConstructorInvocation returns [Declaration ret] //[List list]
    @init { if(dFlag) System.out.println("explicitConstructorInvocation"); LinkedList list = new LinkedList(); int c1, c2; }
    @after{ ret = new StringDeclaration(list); }
    :   (t1=nonWildcardTypeArguments)? ('this' {c1=1;} | 'super' {c1=2;}) t2=arguments ';'
            {
                list.add(t1);
                if(c1==1)
                    list.add(new StringDeclaration("this"));
                if(c1==2)
                    list.add(new StringDeclaration("super"));
                list.add(t2);
                list.add(new StringDeclaration(";"));

                /*
                if(c1==1)
                    list.add(new OperatorID("this"));
                if(c1==2)
                    list.add(new OperatorID("super"));
                for(int i=0; i<t2.size(); i++)
                    list.add(t2.get(i));
                */
            }
    |   t3=primary '.' (t4=nonWildcardTypeArguments)? 'super' t5=arguments ';'
            {
                list.add(t3);
                list.add(new StringDeclaration("."));
                if(t4 != null)
                    list.add(t4);
                list.add(new StringDeclaration("super"));
                list.add(t5);
                list.add(new StringDeclaration(";"));
                //list.add(t3);
                //list.add(new OperatorID("super"));
                //for(int i=0; i<t5.size(); i++)
                //    list.add(t5.get(i));
            }
    ;

qualifiedName /* Explicitly returns string that is intended */
    @init { if(dFlag) System.out.println("qualifiedName"); }
    :   Identifier ('.' Identifier)*
    ;

literal returns [Declaration ret] //[Literal ret]
    @init { if(dFlag) System.out.println("literal"); LinkedList list = new LinkedList(); }
    :   t1=integerLiteral
            {
                retval.ret = t1;
            }
    |   t2=FloatingPointLiteral
            {
                retval.ret = new StringDeclaration($t2.text);
            }
    |   t3=CharacterLiteral
            {
                retval.ret = new StringDeclaration($t3.text);
            }
    |   t4=StringLiteral
            {
                retval.ret = new StringDeclaration($t4.text);
            }
    |   t5=booleanLiteral
            {
                retval.ret = t5;
            }
    |   'null'
            {
                retval.ret = new StringDeclaration("null");
            }
    ;

integerLiteral returns [Declaration ret] //[IntegerLiteral ret_lit]
    @init { if(dFlag) System.out.println("integerLiteral"); LinkedList list = new LinkedList(); }
    :  t1=HexLiteral
            {
                //System.out.println("Hex " + $HexLiteral.text);
                //ret_lit = new IntegerLiteral($HexLiteral.text);
                ret = new StringDeclaration($t1.text);
            }
    |   t2=OctalLiteral
            {
                //System.out.println("Oct " + $OctalLiteral.text);
                //ret_lit = new IntegerLiteral($OctalLiteral.text);
                ret = new StringDeclaration($t2.text);
            }
    |   t3=DecimalLiteral
            {
                //System.out.println("Deci " + $DecimalLiteral.text);
                //ret_lit = new IntegerLiteral($DecimalLiteral.text);
                //if(ret_lit == null) System.out.println("*");
                ret = new StringDeclaration($t3.text);
            }
    ;

booleanLiteral returns [Declaration ret] //[BooleanLiteral ret_lit]
    @init { if(dFlag) System.out.println("booleanLiteral"); LinkedList list = new LinkedList(); }
    :   'true'
            {
                ret = new StringDeclaration("true");
                //ret_lit = new BooleanLiteral(true);
            }
    |   'false'
            {
                ret = new StringDeclaration("false");
                //ret_lit = new BooleanLiteral(false);
            }
    ;

// ANNOTATIONS

annotations returns [Declaration ret] //[Declaration ret_decl]
    @init { if(dFlag) System.out.println("annotations"); list = new LinkedList(); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   (t1=annotation
            {
                list.add(t1);
                //ret_decl.annotate(t1);
            }
        )+
    ;

/* OK */
annotation returns [Declaration ret] //[Annotation ret_anno]
    @init { if(dFlag) System.out.println("annotation"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '@' t1=annotationName
            {
                list.add(new StringDeclaration("@"));
                list.add(new StringDeclaration($t1.text));
                //ret_anno = new JavaAnnotation(new NameID($annotationName.text));
            }
        ( '('
                 {
                    list.add(new StringDeclaration("("));
                 }
           ( t2=elementValuePairs
                    {
                        list.add(t2);
                        //ret.anno.SetParenthesis();
                        //ret_anno.SetExpression(t2);
                    }
           | t3=elementValue
                    {
                        list.add(t3);
                        //ret.anno.SetParenthesis();
                        //ret_anno.SetExpression(t3);
                    }
           )? ')'
                {
                    list.add(new StringDeclaration(")"));
                }
        )?
    ;

/* OK */
annotationName
    @init { if(dFlag) System.out.println("annotationName"); }
    : Identifier ('.' Identifier)*
    ;

/* OK */
elementValuePairs returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("elementValuePairs"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=elementValuePair
            {
                list.add(t1);
                //ret_expr = t1;
                //list.add(t1);
            }
        (',' t2=elementValuePair
            {
                list.add(new StringDeclaration(","));
                list.add(t2);
                //list.add(t2);
                //ret_expr = new CommaExpression(list);
            }
        )*
    ;

/* OK */
elementValuePair returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("elementValuePair"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=Identifier '=' t2=elementValue
            {
                list.add($t1.text);
                list.add(new StringDeclaration("="));
                list.add(t2);
                ret = new StringDeclaration(list);
                //ret_expr = new AssignmentExpression(new NameID($Identifier.text), AssignmentOperator.NORMAL, t1);
            }
    ;

/* OK */
elementValue returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("elementValue"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=conditionalExpression
            {
                ret = t1;
            }
    |   t2=annotation
            {
                ret = t2;
            }
    |   t3=elementValueArrayInitializer
            {
                ret = t2;
            }
    ;

/* OK */
elementValueArrayInitializer returns [Declaration ret_decl] //[Initializer ret_expr]
    @init { if(dFlag) System.out.println("elementValueArrayInitializer"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '{' (t1=elementValue
            {
                list.add(new StringDeclaration("{"));
                list.add(t1);
                //ret_expr = new Initializer(list);
            }
        (',' t2=elementValue
            {
                list.add(new StringDeclaration(","));
                list.add(t2);
                //ret_expr = new Initializer(list);
            }
        )*)? (','
            {
                list.add(new StringDeclaration(","));
                //ret_expr.SetLastComma();
            }
        )? '}'
            {
                list.add(new StringDeclaration("}"));
            }
    ;

annotationTypeDeclaration returns [Declaration ret]
    @init { if(dFlag) System.out.println("annotationTypeDeclaration"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '@' 'interface' t1=Identifier t2=annotationTypeBody
            {
                list.add(new StringDeclaration("@"));
                list.add(new StringDeclaration("interface"));
                list.add($t1.text);
                list.add(t2);
                //JavaAnnotation anno = new JavaAnnotation(new NameID($Identifier.text), t1);
                //anno.SetType("Interface");
                //ret_decl.annotate(anno);
            }
    ;

annotationTypeBody returns [Declaration ret_decl] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("annotationTypeBody"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '{'
            {
                list.add(new StringDeclaration("{"));
            }
        (t1=annotationTypeElementDeclaration
            {
                list.add(t1);
            }
        )* '}'
            {
                list.add(new StringDeclaration("}"));
            }
    ;

annotationTypeElementDeclaration returns [Declaration ret]
    @init { if(dFlag) System.out.println("annotationTypeElementDeclaration"); LinkedList list = new LinkedList(); }
    :   t1=modifiers t2=annotationTypeElementRest
            {
                list.add(t1);
                list.add(t2);
                ret = new StringDeclaration(list);
                //ret_decl = new VariableDeclaration(t1, t2);
            }
    ;

annotationTypeElementRest returns [Declarator ret]
    @init { if(dFlag) System.out.println("annotationTypeElementRest"); LinkedList list = new LinkedList(); }
    :   t1=type t2=annotationMethodOrConstantRest ';'
            {
                list.add(t1);
                list.add(t2);
                list.add(new StringDeclaration(";"));
                ret = new StringDeclaration(list);
                //ret_decl = new VariableDeclarator(t1, t2);
            }
    |   t3=normalClassDeclaration ';'?
            {
                list.add(t3);
                list.add(new StringDeclaration(";"));
                ret = new StringDeclaration(list);
                //ret_decl = t3;
            }
    |   t4=normalInterfaceDeclaration ';'?
            {
                list.add(t4);
                list.add(new StringDeclaration(";"));
                ret = new StringDeclaration(list);
                //ret_decl = t4;
            }
    |   t5=enumDeclaration ';'?
            {
                list.add(t5);
                list.add(new StringDeclaration(";"));
                ret = new StringDeclaration(list);
                //ret_decl = t5;
            }
    |   t6=annotationTypeDeclaration ';'?
            {
                list.add(t6);
                list.add(new StringDeclaration(";"));
                ret = new StringDeclaration(list);
                //ret_decl = t6;
            }
    ;

annotationMethodOrConstantRest returns [Declaration ret] //
    @init { if(dFlag) System.out.println("annotationMethodOrConstantRest"); LinkedList list = new LinkedList(); }
    :   t1=annotationMethodRest
            {
                ret = t1;
            }
    |   t2=annotationConstantRest
            {
                ret = t2;
            }
    ;

annotationMethodRest returns [Declaration ret] //
    @init { if(dFlag) System.out.println("annotationMethodRest"); LinkedList list = new LinkedList(); }
    :   t1=Identifier '(' ')' t2=defaultValue?
            {
                list.add(new StringDeclaration($t1.text));
                list.add(new StringDeclaration("()"));
                if(t2 != null)
                    list.add(t2);
                ret = new StringDeclaration(list);
            }
    ;

annotationConstantRest returns [Declaration ret] //[List list]
    @init { if(dFlag) System.out.println("annotationConstantRest"); LinkedList list = new LinkedList();  }
    :   t1=variableDeclarators
            {
                ret = t1;
                //list = t1;
            }
    ;

defaultValue returns [Declaration ret] //
    @init { if(dFlag) System.out.println("defaultValue"); LinkedList list = new LinkedList(); }
    :   'default' t1=elementValue
            {
                list.add(new StringDeclaration("default"));
                list.add(t1);
                ret = new StringDeclaration(list);
            }
    ;

// STATEMENTS / BLOCKS

block returns [Declaration ret] //[CompoundStatement cstat]
    @init { if(dFlag) System.out.println("block"); LinkedList list = new LinkedList(); }
    @after {
        list.addFirst(new StringDeclaration("{"));
        list.addLast(new StringDeclaration("}"));
        ret = new StringDeclaration(list);
    }
    :   '{' (t1=blockStatement
            {
                list.add(t1);
                //cstat.addStatement(t1);
            }
        )* '}'
    ;

blockStatement returns [Declaration ret] //[Statement ret]
    @init { if(dFlag) System.out.println("blockStatement"); LinkedList list = new LinkedList(); }
    :   t1=localVariableDeclarationStatement
            {
                ret = t1;
            }
    |   t2=classOrInterfaceDeclaration
            {
                ret = t2;
            }
    |   t3=statement
            {
                ret = t3;
            }
    ;

localVariableDeclarationStatement returns [Declaration ret] //[DeclarationStatement stat]
    @init { if(dFlag) System.out.println("localVariableDeclarationStatement"); LinkedList list = new LinkedList();  }
    @after { ret = new StringDeclaration(list); }
    :    t1=localVariableDeclaration ';'
            {
                list.add(t1);
                list.add(new StringDeclaration(";"));
                //stat = new DeclarationStatement(t1);
            }
    ;

/* OK */
localVariableDeclaration returns [Declaration ret] //[VariableDeclaration ret_vardecl]
    @init { if(dFlag) System.out.println("localVariableDeclaration"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=variableModifiers t2=type t3=variableDeclarators
            {
                if(t1 != null)
                    list.add(t1);
                if(t2 != null)
                    list.add(t2);
                if(t3 != null)
                    list.add(t3);
                //ret_vardecl = new VariableDeclaration(MergeList(t1, t2), t3.get(0));
                //for(int i=1; i<t3.size(); i++)
                //    ret_vardecl.addDeclarator(t3.get(i));
            }
    ;

variableModifiers returns [Declaration ret] //[List list]
    @init { if(dFlag) System.out.println("variableModifiers"); LinkedList list = new LinkedList(); }
    @after { if(list.size() > 1) ret = new StringDeclaration(list); }
    :   (t1=variableModifier
            {
                list.add(t1);
                ret = t1;
            }
        )*
    ;

statement returns [Declaration ret] //[Statement ret_stat]
    @init { if(dFlag) System.out.println("statement"); int check1 = 0; LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    : t1=block
            {
                list.add(t1);
                //ret_stat = (Statement) t1;
            }
    |   t2=ASSERT t3=expression (':' t4=expression)? ';'
            {
                list.add(t2);
                list.add(t3);
                if(t4 != null){
                    list.add(new StringDeclaration(":"));
                    list.add(t4);
                }
                list.add(new StringDeclaration(";"));
            }
    |   'if' t5=parExpression t6=statement
            {
                list.add(new StringDeclaration("if"));
                list.add(t5.ret);
                list.add(t6);
                //ret_stat = (Statement) new IfStatement(tok2, stat1);
            }
        (options {k=1;}:'else' t8=statement
            {
                list.add(t8);
                //ret_stat = (Statement) new IfStatement(tok2, stat1, stat2);
            }
        )?
    |   'for' '(' t9=forControl ')' t10=statement
            {
                list.add(new StringDeclaration("for"));
                if(t9 != null){
                    list.add(new StringDeclaration("{"));
                    list.add(t9);
                    list.add(new StringDeclaration("}"));
                }
                list.add(t10);
                //forControl.setBody(stat2);
                //ret_stat = (Statement)tok3;
            }
    |   'while' t11=parExpression t12=statement
            {
                list.add(new StringDeclaration("while"));
                list.add(t11.ret);
                list.add(t12);
                //ret_stat = (Statement) new WhileLoop(tok4, stat3);
            }
    |   'do' t13=statement 'while' t14=parExpression ';'
            {
                list.add(new StringDeclaration("do"));
                list.add(t13);
                list.add(new StringDeclaration("while"));
                list.add(t14.ret);
                //ret_stat = (Statement) new DoLoop(stat4, tok5);
            }
    |   'try' t15=block
            {
                list.add(new StringDeclaration("try"));
                list.add(t15);
            }
        ( t16=catches 'finally' t17=block
            {
                list.add(t16);
                list.add(t17);
            }
        | t18=catches
            {
                list.add(t18);
            }
        | 'finally' t19 = block
            {
                list.add(new StringDeclaration("finally"));
                list.add(t19);
                //CompoundStatement cstat = new CompoundStatement();
                //cstat.addStatement(t1);
                //ret_stat = cstat;
                /* TODO  t2, t3, catches */
            }
        )
    |   'switch' t20=parExpression '{' t21=switchBlockStatementGroups '}'
            {
                list.add(new StringDeclaration("switch"));
                list.add(t20.ret);
                list.add(new StringDeclaration("{"));
                list.add(t21);
                list.add(new StringDeclaration("}"));
                //ret_stat = (Statement) new SwitchStatement(tok6, tok7);
            }
    |   'synchronized' t22=parExpression t22_1=block
            {
                list.add(new StringDeclaration("synchronized"));
                list.add(t22.ret);
                list.add(t22_1);
            }
    |   { check1 = 0; }'return' (t23=expression { check1 = 1; })? ';'
            {
                list.add(new StringDeclaration("return"));
                list.add(t23);
                list.add(new StringDeclaration(";"));
                //if(check1 == 0 || tok8 == null)
                //    ret_stat = (Statement) new ReturnStatement();
                //else
                //    ret_stat = (Statement) new ReturnStatement(tok8);
            }
    |   'throw' t24=expression ';'
            {
                list.add(new StringDeclaration("throw"));
                list.add(t24);
                list.add(new StringDeclaration(";"));
                //ret_stat = (Statement) new Statement();
                //ret_stat.addChild(0, new ThrowExpression(tok9));
            }
    |   'break' t25=Identifier? ';'
            {
                list.add(new StringDeclaration("break"));
                if(t25 != null)
                    list.add($t25.text);
                list.add(new StringDeclaration(";"));
                //ret_stat = (Statement) new BreakStatement(); /* TODO Identifier support */
            }
    |   'continue' t26=Identifier? ';'
            {
                list.add(new StringDeclaration("continue"));
                if(t26 != null)
                    list.add($t26.text);
                list.add(new StringDeclaration(";"));
                //ret_stat = (Statement) new ContinueStatement(); /* TODO Identifier support */
            }
    |   ';'
            {
                list.add(new StringDeclaration(";"));
                //ret_stat = new NullStatement();
            }
    |   t28=statementExpression ';'
            {
                list.add(t28);
                list.add(new StringDeclaration(";"));
                //ret_stat = (Statement) new Statement();
                //ret_stat.addChild(0, tok10);
            }
    |   t29=Identifier ':' t30=statement
            {
                list.add(t29);
                list.add(new StringDeclaration(":"));
                list.add(t30);
                //Label label = new Label(new NameID($t11.text));
                //ret_stat = label;
                //ret_stat.addChild(0, t12);
            }
    ;

catches returns [Declaration ret] //
    @init { if(dFlag) System.out.println("catches"); LinkedList list = new LinkedList();  }
    @after { ret = new StringDeclaration(list); }
    :   t1=catchClause
            {
                list.add(t1);
            }
        (t2=catchClause
            {
                list.add(t2);
            }
        )*
    ;

catchClause returns [Declaration ret] //
    @init { if(dFlag) System.out.println("catchClause"); LinkedList list = new LinkedList();  }
    @after { ret = new StringDeclaration(list); }
    :   'catch' '(' t1=formalParameter ')' t2=block
            {
                list.add(new StringDeclaration("catch"));
                list.add(new StringDeclaration("("));
                list.add(t1);
                list.add(new StringDeclaration(")"));
                list.add(t2);
            }
    ;

formalParameter returns [Declaration ret] //[Declarator ret_decl]
    @init { if(dFlag) System.out.println("formalParameter"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=variableModifiers t2=type t3=variableDeclaratorId
            {
                list.add(t1);
                list.add(t2);
                list.add(t3);
                //ret_decl = new VariableDeclarator(MergeList(t1,t2), t3);
            }
    ;

/* OK */
switchBlockStatementGroups returns [Declaration ret] //[CompoundStatement cstat]
    @init { if(dFlag) System.out.println("switchBlockStatementGroups"); cstat = new CompoundStatement(); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   (t1=switchBlockStatementGroup
            {
                list.add(t1);
                //cstat.addStatement(t1);
            }
        )*
    ;

/* The change here (switchLabel -> switchLabel+) technically makes this grammar
   ambiguous; but with appropriately greedy parsing it yields the most
   appropriate AST, one in which each group, except possibly the last one, has
   labels and statements. */
switchBlockStatementGroup returns [Declaration ret]
    @init { if(dFlag) System.out.println("switchBlockStatementGroup"); }
    @after { ret = new StringDeclaration(list); }
    :   (t1=switchLabel
            {
                list.add(t1);
            }
        )+
        (t2=blockStatement
            {
                list.add(t2);
            }
        )*
    ;

/* OK */
switchLabel returns [Declaration ret] //[Statement ret_case]
    @init { if(dFlag) System.out.println("switchLabel"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   'case' t1=constantExpression ':'
            {
                list.add(new StringDeclaration("case"));
                list.add(t1);
                list.add(new StringDeclaration(":"));
                //ret_case = new Case(constantExpression);
            }
    |   'case' t2=enumConstantName ':'
            {
                list.add(new StringDeclaration("case"));
                list.add(t2);
                list.add(new StringDeclaration(":"));
                //ret_case = new Case(constantExpression);
            }
    |   'default' ':'
            {
                list.add(new StringDeclaration("default"));
                list.add(new StringDeclaration(":"));
                //ret_case = new Default();
            }
    ;

/* OK */
forControl returns [Declaration ret] //[ForLoop forloop]
    options {k=3;} // be efficient for common case: for (ID ID : ID) ...
    @init { if(dFlag) System.out.println("forControl"); Statement stat=null; Expression expr1=null, expr2=null; LinkedList list = new LinkedList(); }
    :   t1=enhancedForControl
            {
                ret = t1;
                //forloop = enhancedForControl;
            }
    |   t2=forInit? ';' t3=expression? ';' t4=forUpdate?
            {
                if(t2 != null)
                    list.add(t2);
                list.add(new StringDeclaration(";"));
                if(t3 != null)
                    list.add(t3);
                list.add(new StringDeclaration(";"));
                if(t4 != null)
                    list.add(t4);
                ret = new StringDeclaration(list);
                //forloop = new ForLoop(stat, expr1, expr2, null);
            }
    ;

forInit returns [Declaration ret] //[Statement stat]
    @init { if(dFlag) System.out.println("forInit"); LinkedList list = new LinkedList(); }
    :   t1=localVariableDeclaration
            {
                ret = t1;
                //stat = TODO;
            }
    |   t2=expressionList
            {
                ret = t2;
                //stat = TODO;
            }
    ;

/* OK - TODO */
enhancedForControl returns [Declaration ret] //[ForLoop forloop]
    @init { if(dFlag) System.out.println("enhancedForControl"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=variableModifiers t2=type t3=Identifier ':' t4=expression
            {
                list.add(t1);
                list.add(t2);
                list.add(new StringDeclaration($t3.text));
                list.add(new StringDeclaration(":"));
                list.add(t4);
                //System.out.println("Unsupported for-loop style\n"); System.exit(-1);
            }
    ;

/* OK */
forUpdate returns [Declaration ret] //[Expression expr]
    @init { if(dFlag) System.out.println("forUpdate"); LinkedList list = new LinkedList(); }
    :   t1=expressionList
            {
                ret = t1;
                //expr = expressionList;
            }
    ;

// EXPRESSIONS
/* OK */
parExpression returns [Declaration ret] //[Expression ret]
    @init { if(dFlag) System.out.println("parExpression"); LinkedList list = new LinkedList(); }
    @after { retval.ret = new StringDeclaration(list); }
    :   '(' t1=expression
            {
                list.add(new StringDeclaration("("));
                list.add(t1);
                list.add(new StringDeclaration(")"));
                //expr = t1;
            }
        ')'
    ;

/* OK */
expressionList returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("expressionList"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=expression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        (',' t2=expression
            {
                list.add(t2);
                //ret_expr = new CommaExpression(list);
            }
        )*
    ;

/* OK */
statementExpression returns [Declaration ret] //[Expression expr]
    @init { if(dFlag) System.out.println("statementExpression"); LinkedList list = new LinkedList(); }
    :   t1=expression
            {
                ret = t1;
                //expr = expression;
            }
    ;

/* OK */
constantExpression returns [Declaration ret] //[Expression expr]
    @init { if(dFlag) System.out.println("constantExpression"); LinkedList list = new LinkedList(); }
    :   t1=expression
            {
                ret = t1;
                //expr = expression;
            }
    ;

/* OK */
expression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("expression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=conditionalExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        (t2=assignmentOperator t3=expression
            {
                list.add(t2);
                list.add(t3);
                //ret_expr = new BinaryExpression(expr1, t1, expr2);
            }
        )?
    ;

/* OK */
assignmentOperator returns [Declaration ret] //[AssignmentOperator op]
    @init { if(dFlag) System.out.println("assignmentOperator"); AssignmentOperator op=null; LinkedList list = new LinkedList(); }
    :   '='
            {
                ret = new StringDeclaration("=");
                //op = AssignmentOperator.NORMAL;
            }
    |   '+='
            {
                ret = new StringDeclaration("+=");
                //op = AssignmentOperator.ADD;
            }
    |   '-='
            {
                ret = new StringDeclaration("-=");
                //op = AssignmentOperator.SUBTRACT;
            }
    |   '*='
            {
                ret = new StringDeclaration("*=");
                //op = AssignmentOperator.MULTIPLY;
            }
    |   '/='
            {
                ret = new StringDeclaration("/=");
                //op = AssignmentOperator.DIVIDE;
            }
    |   '&='
            {
                ret = new StringDeclaration("&=");
                //op = AssignmentOperator.BITWISE_AND;
            }
    |   '|='
            {
                ret = new StringDeclaration("|=");
                //op = AssignmentOperator.BITWISE_INCLUSIVE_OR;
            }
    |   '^='
            {
                ret = new StringDeclaration("^=");
                //op = AssignmentOperator.BITWISE_EXCLUSIVE_OR;
            }
    |   '%='
            {
                ret = new StringDeclaration("?=");
                //op = AssignmentOperator.MODULUS;
            }
    |   ('<' '<' '=')=> t1='<' t2='<' t3='='
         { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() &&
          $t2.getLine() == $t3.getLine() &&
          $t2.getCharPositionInLine() + 1 == $t3.getCharPositionInLine() }?
            {
                ret = new StringDeclaration("<<");
                //op = AssignmentOperator.SHIFT_LEFT;
            }
/*    |   ('>' '>' '>' '=')=> t1='>' t2='>' t3='>' t4='='   [Original Code*/
    |   ('<' '<' '<' '=')=> t1='>' t2='>' t3='>' t4='='
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() &&
          $t2.getLine() == $t3.getLine() &&
          $t2.getCharPositionInLine() + 1 == $t3.getCharPositionInLine() &&
          $t3.getLine() == $t4.getLine() &&
          $t3.getCharPositionInLine() + 1 == $t4.getCharPositionInLine() }?
            {
                ret = new StringDeclaration("<<<");
                //op = AssignmentOperator.SHIFT_LEFT_TRIPLE;
            }
    |   ('>' '>' '=')=> t1='>' t2='>' t3='='
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() &&
          $t2.getLine() == $t3.getLine() &&
          $t2.getCharPositionInLine() + 1 == $t3.getCharPositionInLine() }?
            {
                ret = new StringDeclaration(">>");
                //op = AssignmentOperator.SHIFT_RIGHT;
            }
    ;

/* OK */
conditionalExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("conditionalExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=conditionalOrExpression
            {
                list.add(t1);
                //ret = t1;
            }
        ( '?' t2=expression ':' t33=expression
            {
                list.add(new StringDeclaration("?"));
                list.add(t2);
                list.add(new StringDeclaration(":"));
                list.add(t3);
                //ret_expr = new ConditionalExpression(t1, t2, t3);
            }
        )?
    ;

/* OK */
conditionalOrExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("conditionalOrExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1 = conditionalAndExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( '||' t2=conditionalAndExpression
            {
                list.add(new StringDeclaration("||"));
                list.add(t2);
                //ret_expr = new BinaryExpression(expr1, BinaryOperator.LOGICAL_OR, expr2);
            }
        )*
    ;

/* OK */
conditionalAndExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("conditionalAndExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1 = inclusiveOrExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( '&&' t2=inclusiveOrExpression
            {
                list.add(new StringDeclaration("&&"));
                list.add(t2);
                //ret_expr = new BinaryExpression(expr1, BinaryOperator.LOGICAL_AND, expr2);
            }
        )*
    ;

/* OK */
inclusiveOrExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("inclusiveOrExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1 = exclusiveOrExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( '|' t2 = exclusiveOrExpression
            {
                list.add(new StringDeclaration("|"));
                list.add(t2);
                //ret_expr = new BinaryExpression(expr1, BinaryOperator.BITWISE_INCLUSIVE_OR, expr2);
            }
        )*
    ;

/* OK */
exclusiveOrExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("exclusiveOrExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1 = andExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( '^' t2 = andExpression
            {
                list.add(new StringDeclaration("^"));
                list.add(t2);
                //ret_expr = new BinaryExpression(expr1, BinaryOperator.BITWISE_EXCLUSIVE_OR, expr2);
            }
        )*
    ;

/* OK */
andExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("andExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1 = equalityExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( '&' t2=equalityExpression
            {
                list.add(new StringDeclaration("&"));
                list.add(t2);
                //ret_expr = new BinaryExpression(expr1, BinaryOperator.BITWISE_AND, expr2);
            }
        )*
    ;

/* OK */
equalityExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("equalityExpression"); BinaryOperator op=null; LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=instanceOfExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( ('==' { op=BinaryOperator.COMPARE_EQ; }| '!=' { op = BinaryOperator.COMPARE_NE; } ) t2=instanceOfExpression
            {
                if(op == BinaryOperator.COMPARE_EQ)
                    list.add(new StringDeclaration("=="));
                else
                    list.add(new StringDeclaration("!="));
                list.add(t2);
                //ret_expr = new BinaryExpression(expr1, op, expr2);
            }
        )*
    ;

/* OK */
instanceOfExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("instanceOfExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=relationalExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ('instanceof' t2=type
            {
                list.add(new StringDeclaration("instanceof"));
                list.add(t2);
                //ret_expr = new BinaryExpresion(expr1, BinaryOperator.INSTANCEOF, expr2);
            }
        )?
    ;

/* OK */
relationalExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("relationalExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=shiftExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( t2=relationalOp t3=shiftExpression
            {
                list.add(t2);
                list.add(t3);
                //ret_expr = new BinaryExpression(expr1, relationalOp, expr2);
            }
        )*
    ;

/* OK = TODO - need to understand the meaning of => operator in this language syntax */
relationalOp returns [Declaration ret] //[BinaryOperator op]
    @init { if(dFlag) System.out.println("relationalOp"); BinaryOperator op=null; LinkedList list = new LinkedList(); }
    :   ('<' '=')=> t1='<' t2='='
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() }?
            {
                ret = new StringDeclaration("<=");
                //op = BinaryOperator.LE;
            }
    |   ('>' '=')=> t1='>' t2='='
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() }?
            {
                ret = new StringDeclaration(">=");
                //op = BinaryOperator.GE;
            }
    |   '<'
            {
                ret = new StringDeclaration("<");
                //op = BinaryOperator.LT;
            }
    |   '>'
            {
                ret = new StringDeclaration(">");
                //op = BinaryOperator.GT;
            }
    ;

/* OK */
shiftExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("shiftExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=additiveExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( t2=shiftOp t3=additiveExpression
            {
                list.add(t2);
                list.add(t3);
                //ret_expr = new BinaryExpression(expr1, shiftOp, expr2);
            }
        )*
    ;

/* OK */
shiftOp returns [Declaration ret] //[BinaryOperator op]
    @init { if(dFlag) System.out.println("shiftOp"); BinaryOperator op=null; LinkedList list = new LinkedList(); }
    :   ('<' '<')=> t1='<' t2='<'
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() }?
            {
                ret = new StringDeclaration("<<");
                //op = BinaryOperator.SHIFT_LEFT;
            }
    |   ('>' '>' '>')=> t1='>' t2='>' t3='>'
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() &&
          $t2.getLine() == $t3.getLine() &&
          $t2.getCharPositionInLine() + 1 == $t3.getCharPositionInLine() }?
            {
                ret = new StringDeclaration("<<<");
                //op = BinaryOperator.SHIFT_LEFT_TRIPLE;
            }
    |   ('>' '>')=> t1='>' t2='>'
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() }?
            {
                ret = new StringDeclaration(">>");
                //op = BinaryOperator.SHIFT_RIGHT;
            }
    ;

/* OK */
additiveExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("additiveExpression"); BinaryOperator op=null; LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=multiplicativeExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( ('+' { op = BinaryOperator.ADD; }| '-' { op = BinaryOperator.SUBTRACT; }) t2=multiplicativeExpression
            {
                if(op == BinaryOperator.ADD)
                    list.add(new StringDeclaration("+"));
                else
                    list.add(new StringDeclaration("-"));
                list.add(t2);
                //ret_expr = new BinaryExpression(expr1, op, expr2);
            }
        )*
    ;

/* OK */
multiplicativeExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("multiplicativeExpression"); BinaryOperator op=null; LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=unaryExpression
            {
                list.add(t1);
                //ret_expr = expr1;
            }
        ( ( '*' { op = BinaryOperator.MULTIPLY; } | '/' { op = BinaryOperator.DIVIDE; } | '%' { op = BinaryOperator.MODULUS; } ) t2=unaryExpression
            {
                list.add(op);
                list.add(t2);
                //ret_expr = new BinaryExpression(expr1, op, expr2);
            }
        )*
    ;

/* OK */
unaryExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("unaryExpression"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '+' t1=unaryExpression
            {
                list.add(new StringDeclaration("+"));
                list.add(t1);
                //ret_expr = new UnaryExpression(UnaryOperator.PLUS, tok1);
            }
    |   '-' t2=unaryExpression
            {
                list.add(new StringDeclaration("-"));
                list.add(t2);
                //ret_expr = new UnaryExpression(UnaryOperator.MINUS, tok2);
            }
    |   '++' t3=unaryExpression
            {
                list.add(new StringDeclaration("++"));
                list.add(t3);
                //ret_expr = new UnaryExpression(UnaryOperator.PRE_INCREMENT, tok3);
            }
    |   '--' t4=unaryExpression
            {
                list.add(new StringDeclaration("--"));
                list.add(t4);
                //ret_expr = new UnaryExpression(UnaryOperator.PRE_DECREMENT, tok4);
            }
    |   t5=unaryExpressionNotPlusMinus
            {
                list.add(t5);
                //ret_expr = t5;
            }
    ;

unaryExpressionNotPlusMinus returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("unaryExpressionNotPlusMinus"); int c1, c2; LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '~' t1=unaryExpression
            {
                list.add(new StringDeclaration("~"));
                list.add(t1);
                //ret_expr = new UnaryExpression(UnaryOperator.BITWISE_COMPLEMENT, t1);
            }
    |   '!' t2=unaryExpression
            {
                list.add(new StringDeclaration("!"));
                list.add(t2);
                //ret_expr = new UnaryExpression(UnaryOperator.LOGICAL_NEGATION, t2);
            }
    |   t3=castExpression
            {
                list.add(t3);
                //ret_expr = t3;
            }
    |   {c1=0; c2=0;} t4=primary
            {
                list.add(t4);
                //ret_expr = t4;
                //prev_expr = t4;
                /* TODO */
            }
        (t5=selector
            {
                list.add(t5);
            }
        )* ('++' {
            c1=1;
            list.add(new StringDeclaration("++"));
        } |'--'{
            c2=1;
            list.add(new StringDeclaration("--"));
        })?
    ;

castExpression returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("castExpression"); int check1, check2; LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :  '(' t1=primitiveType ')' t2=unaryExpression
            {
                LinkedList list = new LinkedList();
                list.add(t1);
                ret_expr = new NewExpression(list, t2);
            }
        |  {check1=0; check2=0;} '(' (t3=type {check1=1;}| t4=expression {check2=1;}) ')' t5=unaryExpressionNotPlusMinus
            {
                if(check1 == 1){
                    LinkedList list = new LinkedList();
                    list.add(t3);
                    ret_expr = new NewExpression(list, t5);
                }
                else if (check2 == 1){
                    ret_expr = new RangeExpression(t4, t5); /* TODO Make sure it is the right class */
                }
            }
    ;

primary returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("primary"); String str=""; LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=parExpression
            {
                list.add(t1.ret);
                //ret_expr = t1;
            }
    |   'this'
            {
                list.add(new StringDeclaration("this"));
                //prev_expr = new OperatorID("this");
            }
        ('.' t2=Identifier
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration($t2.text));
                //prev_expr = new AccessExpression(prev_expr, AccessOperator.MEMBER_ACCESS , new NameID($t2.text));
            }
        )*
        (t3=identifierSuffix
            {
                list.add(t3);
                //prev_expr = t3;
            }
        )?
                //ret_expr = prev_expr;
    |   'super' t4=superSuffix
            {
                list.add(new StringDeclaration("super"));
                list.add(t4);
            }
    |   t5=literal
            {
                list.add(t5.ret);
                //ret_expr = t4;
            }
    |   'new' t6=creator
            {
                list.add(new StringDeclaration("new"));
                list.add(t6.ret);
                //ret_expr = new UnaryExpression(UnaryOperator.NEW, t11);
            }
    |   t7=Identifier
            {
                list.add(new StringDeclaration($t7.text));
                //prev_expr = new NameID($t5.text);
            }
        ('.' t8=Identifier
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration($t8.text));
                //prev_expr = new AccessExpression(prev_expr, AccessOperator.MEMBER_ACCESS , new NameID($t6.text));
            }
        )*
        (t9=identifierSuffix
            {
                list.add(t9);
                //prev_expr = t3;
            }
        )?
                //ret_expr = prev_expr;
    |   t10=primitiveType
            {
                list.add(t10);
            }
        ('[' ']'
            {
                list.add(new StringDeclaration("[]"));
            }
        )* '.' 'class'
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration("class"));
            }
    |   'void' '.' 'class'
            {
                list.add(new StringDeclaration("void"));
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration("class"));
                //ret_expr = new AccessExpression(new OperatorID("void"), AccessOperator.MEMBER_ACCESS , new OperatorID("class"));
            }
    ;

identifierSuffix returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("identifierSuffix"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   ('[' ']'
            {
                list.add(new StringDeclaration("[]"));
                //list.add(new ArraySpecifier());
            }
        )+ '.' 'class'
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration("class"));
                //ArrayAccess lhs = new ArrayAccess(prev_expr), list);
                //ret_expr = new AccessExpression(lhs, AccessOperator.MEMBER_ACCESS, new OperatorID("class"));
            }
    |   ('['
            {
                list.add(new StringDeclaration("["));
            }
        t1=expression
            {
                list.add(t1);
            }
        ']')+ // can also be matched by selector, but do here
            {
                list.add(new StringDeclaration("]"));
                //ret_expr = new ArrayAccess(prev_expr, t1);
            }
    |   t2=arguments
            {
                list.add(t2);
                //ret_expr = t2;
            }
    |   '.' 'class'
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration("class"));
                //ret_expr = new AccessExpression(prev_expr, AccessOperator.MEMBER_ACCESS, new OperatorID("class"));
            }
    |   '.' t3=explicitGenericInvocation
            {
                list.add(new StringDeclaration("."));
                list.add(t3);
                //ret_expr = new AccessExpression(prev_expr, AccessOperator.MEMBER_ACCESS, t1);
            }
    |   '.' 'this'
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration("this"));
                //ret_expr = new AccessExpression(prev_expr, AccessOperator.MEMBER_ACCESS, new OperatorID("this"));
            }
    |   '.' 'super' t4=arguments
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration("super"));
                list.add(t4);
                //ret_expr = new AccessExpression(prev_expr, AccessOperator.MEMBER_ACCESS, new OperatorID("super") /* TODO */);
            }
    |   '.' 'new' t5=innerCreator
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration("new"));
                list.add(t5);
                //Expression expr = new BinaryExpression(UnaryOperator.NEW, t20);
                //ret_expr = new AccessExpression(prev_expr, AccessOperator.MEMBER_ACCESS, expr));
            }
    ;

creator returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("creator"); LinkedList list = new LinkedList(); }
    @after { retval.ret = new StringDeclaration(list); }
    :   t1=nonWildcardTypeArguments t2=createdName t3=classCreatorRest
            {
                list.add(t1);
                list.add(t2);
                list.add(t3);
                /*
                if(t2.containsKey("argument")){
                    if(!t2.containsKey("body")){
                        Expression arg = (Expression) t2.get("argument");
                        if(arg instanceof OperatorID)
                            ret_expr = new FunctionCall(t1);
                        else
                            ret_expr = new FunctionCall(t1, arg);
                    }
                    else{
                        // TODO
                    }
                }
                else{
                    ret_expr = t1;
                }
                */
            }
    |   t3=createdName (t4=arrayCreatorRest
            {
                list.add(t3);
                list.add(t4);
                /* TODO */
                //ret_expr = t3;
            }
        | t5=classCreatorRest
            {
                list.add(t3);
                list.add(t5);
                /*
                if(t5.containsKey("argument")){
                    if(!t5.containsKey("body")){
                        Expression arg = (Expression) t5.get("argument");
                        if(arg instanceof OperatorID)
                            ret_expr = new FunctionCall(t3);
                        else
                            ret_expr = new FunctionCall(t3, arg);
                    }
                    else{
                        // TODO
                    }
                }
                else{
                    ret_expr = t3;
                }*/
            }
        )
    ;

createdName returns [Declaration ret] //[Expression expr]
    @init { if(dFlag) System.out.println("createdName"); LinkedList list = new LinkedList(); }
    :   t1=classOrInterfaceType
            {
                ret = t1;
                //expr = t1;
            }
    |   t2=primitiveType
            {
                ret = t2;
            }
    ;

innerCreator returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("innerCreator"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=nonWildcardTypeArguments? t2=Identifier t3=classCreatorRest
            {
                if(t1 != null)
                    list.add(t1);
                list.add(new StringDeclaration($t2.text));
                list.add(t3);
                //ret_expr = new NameID($t1.text);
            }
    ;

arrayCreatorRest returns [Declaration ret] //
    @init { if(dFlag) System.out.println("arrayCreatorRest"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '['
                {
                    list.add(new StringDeclaration("["));
                }
        (   ']'
                {
                    list.add(new StringDeclaration("]"));
                }
            ('[' ']'
                {
                    list.add(new StringDeclaration("[]"));
                }
            )* t1=arrayInitializer
                {
                    list.add(t1);
                }
        |   t2=expression ']'
                {
                    list.add(t2);
                    list.add(new StringDeclaration("]"));
                    //list.add(new StringDeclaration("["));
                }
            ('[' t3=expression ']'
                {
                    list.add(new StringDeclaration("["));
                    list.add(t3);
                    list.add(new StringDeclaration("]"));
                }
            )* ('[' ']'
                {
                    list.add(new StringDeclaration("[]"));
                }
            )*
        )
    ;

classCreatorRest returns [Declaration ret] //[Hashtable hash]
    @init { if(dFlag) System.out.println("classCreatorRest"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=arguments
            {
                list.add(t1);
                /*if(t1 != null){
                    System.out.println("PUSH ");
                    hash.put("argument", t1);
                }*/
            }
        (t2=classBody
            {
                list.add(t2);
                //if(t2 != null)
                //    hash.put("body", t2);
            }
        )?
    ;

explicitGenericInvocation returns [Declaration ret] //
    @init { if(dFlag) System.out.println("explicitGenericInvocation"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=nonWildcardTypeArguments t2=Identifier t3=arguments
            {
                list.add(t1);
                list.add(new stringDeclaration($t2.text));
                list.add(t3);
            }
    ;

nonWildcardTypeArguments returns [Declaration ret] //[List list]
    @init { if(dFlag) System.out.println("nonWildcardTypeArguments"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '<' t1=typeList '>'
        {
            list.add(new StringDeclaration("<"));
            list.add(t1);
            list.add(new stringDeclaration(">"));
            //list = t1;
        }
    ;

selector returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("selector"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '.' t1=Identifier
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration($t1.text));
                //if(prev_expr == null)
                //    ret_expr = new AccessExpression(new NameID("??"), AccessOperator.MEMBER_ACCESS, new NameID($t1.text));
                //else
                //    ret_expr = new AccessExpression(prev_expr, AccessOperator.MEMBER_ACCESS, new NameID($t1.text));
            }
        (t2=arguments
            {
                list.add(t2);
                //if(t2 == null)
                //    ret_expr = new NameID($Identifier.text);
                //else if(t2 instanceof OperatorID)
                //    ret_expr = new FunctionCall(new NameID($Identifier.text));
                //else{
                //    LinkedList list = new LinkedList();
                //    list.add(t2);
                //    ret_expr = new FunctionCall(new NameID($Identifier.text), list);
                //}
            }
        )?
    |   '.' 'this'
        {
            list.add(new StringDeclaration("."));
            list.add(new StringDeclaration("this"));
        }
    |   '.' 'super' t3=superSuffix
        {
            list.add(new StringDeclaration("."));
            list.add(new StringDeclaration("super"));
            list.add(t3);
        }
    |   '.' 'new' t4=innerCreator
        {
            list.add(new StringDeclaration("."));
            list.add(new StringDeclaration("new"));
            list.add(t4);
        }
    |   '[' t5=expression ']'
        {
            list.add(new StringDeclaration("["));
            list.add(t5);
            list.add(new StringDeclaration("]"));
        }
    ;

superSuffix returns [Declaration ret] //
    @init { if(dFlag) System.out.println("superSuffix"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   t1=arguments
            {
                list.add(t1);
            }
    |   '.' t2=Identifier t3=arguments?
            {
                list.add(new StringDeclaration("."));
                list.add(new StringDeclaration($t2.text));
                if(t3 != null)
                    list.add(t3);
            }
    ;

/* OK */
arguments returns [Declaration ret] //[Expression ret_expr]
    @init { if(dFlag) System.out.println("arguments"); LinkedList list = new LinkedList(); }
    @after { ret = new StringDeclaration(list); }
    :   '('
                {
                    list.add(new StringDeclaration("("));
                    //ret_expr = new OperatorID("()");
                }
        (t1=expressionList
                {
                    list.add(t1);
                    //ret_expr = t1;
                }
        )? ')'
                {
                    list.add(new StringDeclaration(")"));
                }
    ;

/*========================================================================*/
/* LEXER */

HexLiteral : '0' ('x'|'X') HexDigit+ IntegerTypeSuffix? ;

DecimalLiteral : ('0' | '1'..'9' '0'..'9'*) IntegerTypeSuffix? ;

OctalLiteral : '0' ('0'..'7')+ IntegerTypeSuffix? ;

fragment
HexDigit : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
IntegerTypeSuffix : ('l'|'L') ;

FloatingPointLiteral
    :   ('0'..'9')+ '.' ('0'..'9')* Exponent? FloatTypeSuffix?
    |   '.' ('0'..'9')+ Exponent? FloatTypeSuffix?
    |   ('0'..'9')+ Exponent FloatTypeSuffix?
    |   ('0'..'9')+ FloatTypeSuffix
    ;

fragment
Exponent : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

fragment
FloatTypeSuffix : ('f'|'F'|'d'|'D') ;

CharacterLiteral
    :   '\'' ( EscapeSequence | ~('\''|'\\') ) '\''
    ;

StringLiteral
    :  '"' ( EscapeSequence | ~('\\'|'"') )* '"'
    ;

fragment
EscapeSequence
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    |   UnicodeEscape
    |   OctalEscape
    ;

fragment
OctalEscape
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UnicodeEscape
    :   '\\' 'u' HexDigit HexDigit HexDigit HexDigit
    ;

ENUM:   'enum' {if (!enumIsKeyword) $type=Identifier;}
    ;

ASSERT
    :   'assert' {if (!assertIsKeyword) $type=Identifier;}
    ;

Identifier returns [String str]
    :   Letter (Letter |JavaIDDigit)*
            { str = $text; }
    ;

/**I found this char range in JavaCC's grammar, but Letter and Digit overlap.
   Still works, but...
 */
fragment
Letter
    :  '\u0024' |
       '\u0041'..'\u005a' |
       '\u005f' |
       '\u0061'..'\u007a' |
       '\u00c0'..'\u00d6' |
       '\u00d8'..'\u00f6' |
       '\u00f8'..'\u00ff' |
       '\u0100'..'\u1fff' |
       '\u3040'..'\u318f' |
       '\u3300'..'\u337f' |
       '\u3400'..'\u3d2d' |
       '\u4e00'..'\u9fff' |
       '\uf900'..'\ufaff'
    ;

fragment
JavaIDDigit
    :  '\u0030'..'\u0039' |
       '\u0660'..'\u0669' |
       '\u06f0'..'\u06f9' |
       '\u0966'..'\u096f' |
       '\u09e6'..'\u09ef' |
       '\u0a66'..'\u0a6f' |
       '\u0ae6'..'\u0aef' |
       '\u0b66'..'\u0b6f' |
       '\u0be7'..'\u0bef' |
       '\u0c66'..'\u0c6f' |
       '\u0ce6'..'\u0cef' |
       '\u0d66'..'\u0d6f' |
       '\u0e50'..'\u0e59' |
       '\u0ed0'..'\u0ed9' |
       '\u1040'..'\u1049'
   ;

WS  :  (' '|'\r'|'\t'|'\u000C'|'\n') {$channel=HIDDEN;}
    ;

COMMENT
    :   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

LINE_COMMENT
    : '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    ;