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
    :   annotations
        (   decl1=packageDeclaration
                {
                    tunit.addDeclaration(decl1);
                }
            (decl2=importDeclaration
                {
                    tunit.addDeclaration(decl2);
                }
            )*
            (decl3=typeDeclaration
                {
                    if(decl3 != null)
                        tunit.addDeclaration(decl3);
                }
            )*
        |   decl4=classOrInterfaceDeclaration
                {
                    tunit.addDeclaration(decl4);
                }
            (decl5=typeDeclaration
                {
                    if(decl5 != null)
                        tunit.addDeclaration(decl5);
                }
            )*
        )
    |   (decl6=packageDeclaration
                {
                    tunit.addDeclaration(decl6);
                }
        )?
        ( decl7=importDeclaration
                {
                    tunit.addDeclaration(decl7);
                }
        )*
        ( decl8=typeDeclaration
                {
                    if(decl8 != null)
                        tunit.addDeclaration(decl8);
                }
        )*
    ;

/* OK */
packageDeclaration returns [Declaration ret_decl]
    :   'package' qualifiedName ';'
            {
                CodeAnnotation anno = new CodeAnnotation("package " + $qualifiedName.text);
                ret_decl = new AnnotationDeclaration(anno);
            }
    ;

/* OK */
importDeclaration returns [Declaration ret_decl]
    @init {int check1=0, check2=0; }
    :   'import' ('static'{check1 = 1;})? qualifiedName ('.' '*' {check2 = 1;})? ';'
            {
                CodeAnnotation anno = new CodeAnnotation("import " + ((check1==1)?"static ":"") + ((check2==1)?".*":"") + ";");
                ret_decl = new AnnotationDeclaration(anno);
/*
                ret_decl = new AnnotationDeclaration(2 + check1 + check2);
                int i = 0;
                ret_decl.setChild(i++, new NameID("import"));
                if(check1)
                    ret_decl.setChild(i++, new NameID("static"));
                ret_decl.setChild(i++, qualifiedName);
                if(check2)
                    ret_decl.setChild(i++, new NameID(".*"));*/
            }
    ;

/* OK */
typeDeclaration returns [Declaration ret_decl]
    :   classOrInterfaceDeclaration
            {
                ret_decl = classOrInterfaceDeclaration;
            }
    |   ';'
            {
                ret_decl = null;
            }
    ;

/* OK */
classOrInterfaceDeclaration returns [Declaration ret_decl]
    :   tok1=classOrInterfaceModifiers
        (tok2=classDeclaration
            {
                classDeclaration.SetClassSpec(tok1);
                ret_decl = (Declaration) tok2;
            }
        | tok3=interfaceDeclaration
            {
                interfaceDeclaration.SetClassSpec(tok1);
                ret_decl = (Declaration) tok3;
            }
        )
    ;

/* OK */
classOrInterfaceModifiers returns [LinkedList list]
    @init { list = new LinkedList(); }
    :   (tok1=classOrInterfaceModifier
            {
              list.add(tok1);
            }
        )*
    ;

/* OK */
classOrInterfaceModifier returns [Specifier type]
    :   annotation   // class or interface
            { type = Specifier.ANNOTATION; }
    |   'public'     // class or interface
            { type = Specifier.PUBLIC; }
    |   'protected'  // class or interface
            { type = Specifier.PROTECTED; }
    |   'private'    // class or interface
            { type = Specifier.PRIVATE; }
    |   'abstract'   // class or interface
            { type = Specifier.ABSTRACT; }
    |   'static'     // class or interface
            { type = Specifier.STATIC; }
    |   'final'      // class only -- does not apply to interfaces
            { type = Specifier.FINAL; }
    |   'strictfp'   // class or interface
            { type = Specifier.STRICTFP; }
    ;

modifiers
    :   modifier*
    ;

classDeclaration returns [ClassDeclaration decl]
    :   normalClassDeclaration
        { decl = normalClassDeclaration; }
    |   enumDeclaration
        { decl = enumDeclaration; }
    ;

normalClassDeclaration returns [ClassDeclaration ret_decl]
    :   'class' Identifier typeParameters?
        ('extends' type)?
        ('implements' typeList)?
        classBody
            {
                ret_decl = new ClassDeclaration(ClassDeclaration.CLASS, new NameID($Identifier.text));
                /* TODO */
            }
    ;

typeParameters returns [List class_specs]
    :   '<' typeParameter (',' typeParameter)* '>'
    {
    }
    ;

typeParameter
    :   Identifier ('extends' typeBound)?
    ;

typeBound
    :   type ('&' type)*
    ;

enumDeclaration returns [ClassDeclaration decl]
    :   ENUM Identifier ('implements' typeList)? enumBody
            {
                decl = new ClassDeclaration(Specifier.ENUM, new NameID($Identifier.text));
                /* TODO */
            }
    ;

enumBody
    :   '{' enumConstants? ','? enumBodyDeclarations? '}'
    ;

enumConstants
    :   enumConstant (',' enumConstant)*
    ;

enumConstant
    :   annotations? Identifier arguments? classBody?
    ;

enumBodyDeclarations
    :   ';' (classBodyDeclaration)*
    ;

interfaceDeclaration
    :   normalInterfaceDeclaration
    |   annotationTypeDeclaration
    ;

normalInterfaceDeclaration
    :   'interface' Identifier typeParameters? ('extends' typeList)? interfaceBody
    ;

typeList
    :   type (',' type)*
    ;

classBody returns [CompoundStatement ret_stat]
    @init { ret_stat = new CompoundStatement(); }
    :   '{' ( t1=classBodyDeclaration
                {
                    ret_stat.addStatement(t1);
                }
            )*
        '}'
    ;

interfaceBody
    :   '{' interfaceBodyDeclaration* '}'
    ;

classBodyDeclaration returns [Statement ret_decl]
    @init { int check = 0; }
    :   ';'
            {
                ret_decl = new NullStatement();
            }
    |   ('static' { check = 1; })? t2=block
            {
                if(check == 1)
                    ret_decl = t2;  /* Need to handle 'static'
                else
                    ret_decl = t2;
            }
    |   modifiers memberDecl
            {
                
            }
    ;

memberDecl
    :   genericMethodOrConstructorDecl
    |   memberDeclaration
    |   'void' Identifier voidMethodDeclaratorRest
            {
                System.out.println("memnerDecl - void - " + $Identifier.text);
            }
    |   Identifier constructorDeclaratorRest
    |   interfaceDeclaration
    |   classDeclaration
    ;

memberDeclaration returns [Declaration ret_decl]
    :   t1=type (t2=methodDeclaration
                {
                    ProcedureDeclarator decl = new ProcedureDeclarator(t1, t2.get(0), t2.get(1));
                    ret_decl = null;//new Procedure(, decl, );
                }
        | t3=fieldDeclaration
                {
                    ret_decl = t3;
                }
        )
    ;

genericMethodOrConstructorDecl
    :   typeParameters genericMethodOrConstructorRest
    ;

genericMethodOrConstructorRest
    :   (type | 'void') Identifier methodDeclaratorRest
    |   Identifier constructorDeclaratorRest
    ;

methodDeclaration returns [List list]
    @init { list = new LinkedList(); }
    :   Identifier t1=methodDeclaratorRest
            {
                list.add(new NameID($Identifier.text));
                list.add(t1.get(0));
                list.add(t1.get(1));
            }
    ;

fieldDeclaration returns [Declaration ret_decl]
    :   t1=variableDeclarators ';'
            {
                new VariableDeclaration
            }
    ;

interfaceBodyDeclaration
    :   modifiers interfaceMemberDecl
    |   ';'
    ;

interfaceMemberDecl
    :   interfaceMethodOrFieldDecl
    |   interfaceGenericMethodDecl
    |   'void' Identifier voidInterfaceMethodDeclaratorRest
    |   interfaceDeclaration
    |   classDeclaration
    ;

interfaceMethodOrFieldDecl returns [Declarator ret_decl]
    :   type Identifier interfaceMethodOrFieldRest
            {
                //new Declarator()
            }
    ;

interfaceMethodOrFieldRest
    :   constantDeclaratorsRest ';'
    |   interfaceMethodDeclaratorRest
    ;

methodDeclaratorRest returns [List list]
    @init { list = new LinkedList(); }
    :   t1=formalParameters ('[' ']')*
            {
                list.add(t1.get(0));
                list.add(t1.get(1));
            }
        ('throws' qualifiedNameList)?
        (   methodBody
        |   ';'
        )
    ;

voidMethodDeclaratorRest
    :   formalParameters ('throws' qualifiedNameList)?
        (   methodBody
        |   ';'
        )
    ;

interfaceMethodDeclaratorRest
    :   formalParameters ('[' ']')* ('throws' qualifiedNameList)? ';'
    ;

interfaceGenericMethodDecl
    :   typeParameters (type | 'void') Identifier
        interfaceMethodDeclaratorRest
    ;

voidInterfaceMethodDeclaratorRest
    :   formalParameters ('throws' qualifiedNameList)? ';'
    ;

constructorDeclaratorRest returns [Procedure ret_proc]
    :   formalParameters ('throws' qualifiedNameList)? constructorBody
    ;

constantDeclarator returns [VariableDeclarator ret_decl]
    :   Identifier t1=constantDeclaratorRest
            {
                ret_decl = new VariableDeclarator(new NameID($Identifier.text);
                ret_decl.setInitializer(t1);
            }
    ;

variableDeclarators [List list]
    @init { list = new LinkedList(); }
    :   t1=variableDeclarator
            {
                list.add(t1); 
            }
        (',' t2=variableDeclarator
            {
                list.add(t2);
            }
        )*
    ;

/* OK */
variableDeclarator returns [VariableDeclarator ret_decl]
    :   t1=variableDeclaratorId
            { ret_decl = new VariableDeclarator(t1); }
        ('=' t2=variableInitializer
            { ret_decl.setInitializer(t2); }
        )?
    ;

/* OK */
constantDeclaratorsRest returns [List list]
    @init { list = new LinkedList(); }
    :   t1=constantDeclaratorRest
            {
                list.add(new Initializer(t1));
            }
        (',' t2=constantDeclarator
            {
                list.add(t2);
            }
        )*
    ;

/* OK */
constantDeclaratorRest returns [Initializer ret_init]
    :   ('[' ']')* '=' t1=variableInitializer
            {
                ret_init = new Initializer(t1);
            }
    ;

/* OK */
variableDeclaratorId returns [IDExpression ret_id]
    :   Identifier
            {
                ret_decl = new NameID($Identifier.text);
            }
        ('[' ']' { /* TODO */ } )*
    ;

/* OK */
variableInitializer returns [Initializer init]
    :   t1=arrayInitializer
            { init = t1; }
    |   t2=expression
            { init = new Initializer(t2); }
    ;

/* OK */
arrayInitializer returns [Initializer init]
    @init { List list = new LinkedList(); }
    :   '{' (variableInitializer
                { List tlist = variableInitializer.getChildren();
                  for(int i=0; i<tlist.size(); i++)
                    list.add(tlist.get(i));
                }
         (',' variableInitializer
                { List tlist = variableInitializer.getChildren();
                  for(int i=0; i<tlist.size(); i++)
                    list.add(tlist.get(i));
                }
        )* (',')? )? '}'
                {
                    init = new Initializer(list);
                }
    ;

modifier returns [Specifier type]
    :   annotation
            { type = Specifier.ANNOTATION; }
    |   'public'
            {type = Specifier.PUBLIC;}
    |   'protected'
            {type = Specifier.PROTECTED;}
    |   'private'
            {type = Specifier.PRIVATE;}
    |   'static'
            {type = Specifier.STATIC;}
    |   'abstract'
            {type = Specifier.ABSTRACT;}
    |   'final'
            {type = Specifier.FINAL;}
    |   'native'
            {type = Specifier.NATIVE;}
    |   'synchronized'
            {type = Specifier.SYNCHRONIZED;}
    |   'transient'
            {type = Specifier.TRANSIENT;}
    |   'volatile'
            {type = Specifier.VOLATILE;}
    |   'strictfp'
            {type = Specifier.STRICTFP;}
    ;

packageOrTypeName
    :   qualifiedName
    ;


/* OK */
enumConstantName returns [Identifier id]
    @init { Identifier id_temp = null; }
    :   id_temp=Identifier
            { id = new Identifier(id_temp); }
    ;

typeName
    :   qualifiedName
    ;

type returns [List types]
    @init {
        types = new LinkedList();
    }
    : t1=classOrInterfaceType ('[' ']')*
        {
            types.addAll(t1); /* TODO ('[' ']')* */
        }
    | t2=primitiveType ('[' ']')*
        {
            types.add(t2); /* TODO ('[' ']')* */
        }
    ;

classOrInterfaceType returns [List types]
    @init {
        types = new LinkedList();
    }
    : Identifier typeArguments? ('.' Identifier typeArguments? )*
    {
        /* TODO */
    }
    ;

/* OK */
primitiveType returns [Specifier type]
    :   'boolean'
            { type = Specifier.BOOLEAN; }
    |   'char'
            { type = Specifier.CHAR; }
    |   'byte'
            { type = Specifier.BYTE; }
    |   'short'
            { type = Specifier.SHORT; }
    |   'int'
            { type = Specifier.INT; }
    |   'long'
            { type = Specifier.LONG; }
    |   'float'
            { type = Specifier.FLOAT; }
    |   'double'
            { type = Specifier.DOUBLE; }
    ;

variableModifier returns [Specifier anno]
    :   'final'
            { anno = Specifier.final; }
    |   t1=annotation
            { anno = t1; }
    ;

typeArguments
    :   '<' typeArgument (',' typeArgument)* '>'
    ;

typeArgument
    :   type
    |   '?' (('extends' | 'super') type)?
    ;

qualifiedNameList
    :   qualifiedName (',' qualifiedName)*
    ;

formalParameters returns [List list]
    @init { list = new LinkedList(); }
    :   '(' (t1=formalParameterDecls
                {
                    list = t1;
                }
            )?
        ')'
    ;

formalParameterDecls returns [List list]
    :   t1=variableModifiers t2=type t3=formalParameterDeclsRest
            {
                List tlist = new LinkedList();
                VariableDeclarator var_decl = new VariableDeclarator(MergeList(t1, t2), t3.get(0));
                tlist.add(var_decl);
                t3.remove(0);
                list = MergeList(tlist, t3);
            }
    ;

formalParameterDeclsRest returns [List list]
    @init { list = new LinkedList(); }
    :   t1=variableDeclaratorId
            {
                list.add(t1);
                
            }
        (',' t2=formalParameterDecls
            {
                for(int i=0; i<t2.size(); i++)
                    list.add(t2.get(i));
            }
        )?
    |   '...' variableDeclaratorId
            {
                System.err.println("Supported ... argument\n");
                System.exit(-1);
                /* TODO SUPPORT! */
            }
    ;

methodBody returns [Statement stat]
    :   t1=block
            {
                stat = t1;
            }
    ;

constructorBody
    :   '{' explicitConstructorInvocation? blockStatement* '}'
    ;

explicitConstructorInvocation
    :   nonWildcardTypeArguments? ('this' | 'super') arguments ';'
    |   primary '.' nonWildcardTypeArguments? 'super' arguments ';'
    ;


qualifiedName returns [NameID ret_id]
    @init { String str = "";}
    @after{
        retval.ret_id = new NameID(str);
    }
    :   id1=Identifier
            {
                str += "" + id1;
            }
        ('.' id2=Identifier
            {
                str += "." + id2;
            }
        )*
    ;

literal
    :   integerLiteral
    |   FloatingPointLiteral
    |   CharacterLiteral
    |   StringLiteral
    |   booleanLiteral
    |   'null'
    ;

integerLiteral
    :   HexLiteral
    |   OctalLiteral
    |   DecimalLiteral
    ;

booleanLiteral
    :   'true'
    |   'false'
    ;

// ANNOTATIONS

annotations returns [List list]
    @init { list = new LinkedList(); }
    :   (t1=annotation
            {
                list.add(t1);
            }
        )+
    ;

/* OK */
annotation returns [Specifier type]
    :   '@' annotationName 
            { type = new AnnotationSpecifier($annotationName.text); }
        ( '(' ( elementValuePairs | elementValue )? ')' )?
            { type = new AnnotationSpecifier("--");                 } /* TODO : Need to define a class for Java Annotation */
    ;

annotationName
    : Identifier ('.' Identifier)*
    ;

elementValuePairs
    :   elementValuePair (',' elementValuePair)*
    ;

elementValuePair
    :   Identifier '=' elementValue
    ;

elementValue
    :   conditionalExpression
    |   annotation
    |   elementValueArrayInitializer
    ;

elementValueArrayInitializer
    :   '{' (elementValue (',' elementValue)*)? (',')? '}'
    ;

annotationTypeDeclaration
    :   '@' 'interface' Identifier annotationTypeBody
    ;

annotationTypeBody
    :   '{' (annotationTypeElementDeclaration)* '}'
    ;

annotationTypeElementDeclaration
    :   modifiers annotationTypeElementRest
    ;

annotationTypeElementRest
    :   type annotationMethodOrConstantRest ';'
    |   normalClassDeclaration ';'?
    |   normalInterfaceDeclaration ';'?
    |   enumDeclaration ';'?
    |   annotationTypeDeclaration ';'?
    ;

annotationMethodOrConstantRest
    :   annotationMethodRest
    |   annotationConstantRest
    ;

annotationMethodRest
    :   Identifier '(' ')' defaultValue?
    ;

annotationConstantRest
    :   variableDeclarators
    ;

defaultValue
    :   'default' elementValue
    ;

// STATEMENTS / BLOCKS

block returns [CompoundStatement cstat]
    @init{
        cstat = new CompoundStatement();
    }
    :   '{' t1=blockStatement* '}'
    {
        cstat.addStatement(t1);
    }
    ;

blockStatement returns [Statement stat]
    :   t1=localVariableDeclarationStatement
            {   stat = t1;    }
    |   t2=classOrInterfaceDeclaration
            {   stat = t2;    }
    |   t3=statement
            {   stat = t3;    }
    ;

localVariableDeclarationStatement returns [DeclarationStatement stat]
    :    t1=localVariableDeclaration ';'
            { stat = new DeclarationStatement(t1); }
    ;

/* OK */
localVariableDeclaration returns [VariableDeclaration ret_vardecl]
    :   t1=variableModifiers t2=type t3=variableDeclarators
            {
                ret_vardecl = new VariableDeclaration(MergeList(t1, t2), t3);
            }
    ;

variableModifiers returns [List list]
    @init { list = new LinkedList(); }
    :   (t1=variableModifier
            {
                list.add(t1);
            }
        )*
    ;

statement returns [Statement ret_stat]
    @init {int check1 = 0;}
    : t1=block
            { stat = (Statement) t1; }
    |   ASSERT expression (':' expression)? ';'
            {  /* TODO */ }
    |   'if' tok2=parExpression stat1=statement
            {
                ret_stat = (Statement) new IfStatement(tok2, stat1);
            }
        (options {k=1;}:'else' stat2=statement
            {
                ret_stat = (Statement) new IfStatement(tok2, stat1, stat2);
            }
        )?
    |   'for' '(' tok3=forControl ')' stat2=statement
            {
                forControl.setBody(stat2);
                ret_stat = (Statement)tok3;
            }
    |   'while' tok4=parExpression stat3=statement
            {
                ret_stat = (Statement) new WhileLoop(tok4, stat3);
            }
    |   'do' stat4=statement 'while' tok5=parExpression ';'
            {
                ret_stat = (Statement) new DoLoop(stat4, tok5);
            }
    |   'try' t1=block
        ( catches 'finally' t2=block
        | catches
        | 'finally' t3 = block
        )
            {
                CompoundStatement cstat = new CompoundStatement();
                cstat.addStatement(t1);
                ret_stat = cstat;
                /* TODO  t2, t3, catches */
            }
    |   'switch' tok6=parExpression '{' tok7=switchBlockStatementGroups '}'
            {   ret_stat = (Statement) new SwitchStatement(tok6, tok7); }
    |   'synchronized' parExpression block
            {  /* TODO */ }
    |   { check1 = 0; }'return' (tok8=expression { check1 = 1; })? ';'
            {
                if(check1 == 0 || tok8 == null)
                    ret_stat = (Statement) new ReturnStatement();
                else
                    ret_stat = (Statement) new ReturnStatement(tok8);
            }
    |   'throw' tok9=expression ';'
            {   ret_stat = (Statement) new Statement();
                ret_stat.addChild(0, new ThrowExpression(tok9)); }
    |   'break' Identifier? ';'
            {   ret_stat = (Statement) new BreakStatement(); /* TODO Identifier support */ }
    |   'continue' Identifier? ';'
            {   ret_stat = (Statement) new ContinueStatement(); /* TODO Identifier support */ }
    |   ';'
            {   ret_stat = new NullStatement(); }
    |   tok10=statementExpression ';'
            {   ret_stat = (Statement) new Statement();
                ret_stat.addChild(0, tok10); }
    |   Identifier ':' statement
            {  /* TODO */ }
    ;

catches
    :   catchClause (catchClause)*
    ;

catchClause
    :   'catch' '(' formalParameter ')' block
    ;

formalParameter returns [Declarator ret_decl]
    :   t1=variableModifiers t2=type t3=variableDeclaratorId
            {
                ret_decl = new VariableDeclarator(MergeList(t1,t2), t3);
            }
    ;

/* OK */
switchBlockStatementGroups returns [CompoundStatement cstat]
    @init { cstat = new CompoundStatement(); }
    :   (t1=switchBlockStatementGroup
            { cstat.addStatement(t1); }
        )*
    ;

/* The change here (switchLabel -> switchLabel+) technically makes this grammar
   ambiguous; but with appropriately greedy parsing it yields the most
   appropriate AST, one in which each group, except possibly the last one, has
   labels and statements. */
switchBlockStatementGroup returns [Statement stat]
    :   switchLabel+ blockStatement*
    ;

/* OK */
switchLabel returns [Statement ret_case]
    :   'case' constantExpression ':'
            { ret_case = new Case(constantExpression); }
    |   'case' enumConstantName ':'
            { ret_case = new Case(constantExpression); }
    |   'default' ':'
            { ret_case = new Default();  }
    ;

/* OK */
forControl returns [ForLoop forloop]
    options {k=3;} // be efficient for common case: for (ID ID : ID) ...
    @init { Statement stat=null; Expression expr1=null, expr2=null; }
    :   enhancedForControl
            { forloop = enhancedForControl; }
    |   stat=forInit? ';' expr1=expression? ';' expr2=forUpdate?
            { forloop = new ForLoop(stat, expr1, expr2, null);  }
    ;

forInit returns [Statement stat]
    :   localVariableDeclaration
            { stat = TODO; }
    |   expressionList
            { stat = TODO; }
    ;

/* OK - TODO */
enhancedForControl returns [ForLoop forloop]
    :   variableModifiers type Identifier ':' expression
            { System.out.println("Unsupported for-loop style\n"); System.exit(-1); }
    ;

/* OK */
forUpdate returns [Expression expr]
    :   expressionList
        {expr = expressionList; }
    ;

// EXPRESSIONS
/* OK */
parExpression returns [Expression expr]
    :   '(' expression 
            { expr = expression; }
        ')'
    ;

/* OK */
expressionList returns [Expression ret_expr]
    @init { List list;}
    :   expr1=expression
            { ret_expr = expr1; }
        (',' expr2=expression
            { list = new LinkedList();
              list.add(expr1);
              list.add(expr2);
              ret_expr = new CommaExpression(list);
            }
        )*
    ;

/* OK */
statementExpression returns [Expression expr]
    :   expression
            { expr = expression; }
    ;

/* OK */
constantExpression returns [Expression expr]
    :   expression
            { expr = expression; }
    ;

/* OK */
expression returns [Expression ret_expr]
    :   expr1=conditionalExpression
            {   ret_expr = expr1;    }
        (t1=assignmentOperator expr2=expression
            {   ret_expr = new BinaryExpression(expr1, t1, expr2); }
        )?
    ;

/* OK */
assignmentOperator returns [AssignmentOperator op]
    :   '='
            { op = AssignmentOperator.NORMAL; }
    |   '+='
            { op = AssignmentOperator.ADD; }
    |   '-='
            { op = AssignmentOperator.SUBTRACT; }
    |   '*='
            { op = AssignmentOperator.MULTIPLY; }
    |   '/='
            { op = AssignmentOperator.DIVIDE; }
    |   '&='
            { op = AssignmentOperator.BITWISE_AND; }
    |   '|='
            { op = AssignmentOperator.BITWISE_INCLUSIVE_OR; }
    |   '^='
            { op = AssignmentOperator.BITWISE_EXCLUSIVE_OR; }
    |   '%='
            { op = AssignmentOperator.MODULUS; }
    |   ('<' '<' '=')=> t1='<' t2='<' t3='='
         { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() &&
          $t2.getLine() == $t3.getLine() &&
          $t2.getCharPositionInLine() + 1 == $t3.getCharPositionInLine() }?
            { op = AssignmentOperator.SHIFT_LEFT; }
/*    |   ('>' '>' '>' '=')=> t1='>' t2='>' t3='>' t4='='   [Original Code*/
    |   ('<' '<' '<' '=')=> t1='>' t2='>' t3='>' t4='='
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() &&
          $t2.getLine() == $t3.getLine() &&
          $t2.getCharPositionInLine() + 1 == $t3.getCharPositionInLine() &&
          $t3.getLine() == $t4.getLine() &&
          $t3.getCharPositionInLine() + 1 == $t4.getCharPositionInLine() }?
            { op = AssignmentOperator.SHIFT_LEFT_TRIPLE; }
    |   ('>' '>' '=')=> t1='>' t2='>' t3='='
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() &&
          $t2.getLine() == $t3.getLine() &&
          $t2.getCharPositionInLine() + 1 == $t3.getCharPositionInLine() }?
            { op = AssignmentOperator.SHIFT_RIGHT; }
    ;

/* OK */
conditionalExpression returns [Expression ret_expr]
    :   expr1 = conditionalOrExpression
            { ret_expr = expr1; }
        ( '?' expr2=expression ':' expr3=expression
            { ret_expr = new ConditionalExpression(expr1, expr2, expr3); }
        )?
    ;

/* OK */
conditionalOrExpression returns [Expression ret_expr]
    :   expr1 = conditionalAndExpression
            { ret_expr = expr1; }
        ( '||' expr2=conditionalAndExpression
            { ret_expr = new BinaryExpression(expr1, BinaryOperator.LOGICAL_OR, expr2); }
        )*
    ;

/* OK */
conditionalAndExpression returns [Expression ret_expr]
    :   expr1 = inclusiveOrExpression
            { ret_expr = expr1; }
        ( '&&' inclusiveOrExpression 
            { ret_expr = new BinaryExpression(expr1, BinaryOperator.LOGICAL_AND, expr2); }
        )*
    ;

/* OK */
inclusiveOrExpression returns [Expression ret_expr]
    :   expr1 = exclusiveOrExpression
            { ret_expr = expr1; }
        ( '|' expr2 = exclusiveOrExpression
            { ret_expr = new BinaryExpression(expr1, BinaryOperator.BITWISE_INCLUSIVE_OR, expr2); }
        )*
    ;

/* OK */
exclusiveOrExpression returns [Expression ret_expr]
    :   expr1 = andExpression 
            { ret_expr = expr1; }
        ( '^' expr2 = andExpression
            { ret_expr = new BinaryExpression(expr1, BinaryOperator.BITWISE_EXCLUSIVE_OR, expr2); }
        )*
    ;

/* OK */
andExpression returns [Expression ret_expr]
    :   expr1 = equalityExpression 
            { ret_expr = expr1; }
        ( '&' equalityExpression 
            { ret_expr = new BinaryExpression(expr1, BinaryOperator.BITWISE_AND, expr2); }
        )*
    ;

/* OK */
equalityExpression returns [Expression ret_expr]
    :   expr1=instanceOfExpression 
            { ret_expr = expr1; }
        ( ('==' { op = BinaryOperator.COMPARE_EQ; }| '!=' { op = BinaryOperator.COMPARE_NE; } ) expr2 = instanceOfExpression
            { ret_expr = new BinaryExpression(expr1, op, expr2); }
        )*
    ;

/* OK */
instanceOfExpression returns [Expression ret_expr]
    :   expr1=relationalExpression
            { ret_expr = expr1; }
        ('instanceof' expr2=type
            { ret_expr = new BinaryExpresion(expr1, BinaryOperator.INSTANCEOF, expr2); }
        )?
    ;

/* OK */
relationalExpression returns [Expression ret_expr]
    :   expr1=shiftExpression
            { ret_expr = expr1; }
        ( relationalOp expr2=shiftExpression
            { ret_expr = new BinaryExpression(expr1, relationalOp, expr2); }
        )*
    ;

/* OK = TODO - need to understand the meaning of => operator in this language syntax */
relationalOp returns [BinaryOperator op]
    :   ('<' '=')=> t1='<' t2='='
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() }?
            { op = BinaryOperator.LE; }
    |   ('>' '=')=> t1='>' t2='='
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() }?
            { op = BinaryOperator.GE; }
    |   '<'
            { op = BinaryOperator.LT; }
    |   '>'
            { op = BinaryOperator.GT; }
    ;

/* OK */
shiftExpression returns [Expression ret_expr]
    :   expr1=additiveExpression
            { ret_expr = expr1; }
        ( shiftOp expr2=additiveExpression
            { ret_expr = new BinaryExpression(expr1, shiftOp, expr2); }
        )*
    ;

/* OK */
shiftOp returns [BinaryOperator op]
    :   ('<' '<')=> t1='<' t2='<'
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() }?
            { op = BinaryOperator.SHIFT_LEFT; }
    |   ('>' '>' '>')=> t1='>' t2='>' t3='>'
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() &&
          $t2.getLine() == $t3.getLine() &&
          $t2.getCharPositionInLine() + 1 == $t3.getCharPositionInLine() }?
            { op = BinaryOperator.SHIFT_LEFT_TRIPLE; }
    |   ('>' '>')=> t1='>' t2='>'
        { $t1.getLine() == $t2.getLine() &&
          $t1.getCharPositionInLine() + 1 == $t2.getCharPositionInLine() }?
            { op = BinaryOperator.SHIFT_RIGHT; }
    ;

/* OK */
additiveExpression returns [Expression ret_expr]
    :   expr1=multiplicativeExpression 
            { ret_expr = expr1; }
        ( ('+' { op = BinaryOperator.ADD; }| '-' { op = BinaryOperator.SUBTRACT; }) expr2=multiplicativeExpression
            { ret_expr = new BinaryExpression(expr1, op, expr2); }
        )*
    ;

/* OK */
multiplicativeExpression returns [Expression ret_expr]
    :   expr1=unaryExpression
            { ret_expr = expr1; }
        ( ( '*' { op = BinaryOperator.MULTIPLY; } | '/' { op = BinaryOperator.DIVIDE; } | '%' { op = BinaryOperator.MODULUS; } ) expr2=unaryExpression
            { ret_expr = new BinaryExpression(expr1, op, expr2); }
        )*
    ;

/* OK */
unaryExpression returns [Expression ret_expr]
    :   '+' tok1=unaryExpression
            { ret_expr = new UnaryExpression(UnaryOperator.PLUS, tok1); }
    |   '-' tok2=unaryExpression
            { ret_expr = new UnaryExpression(UnaryOperator.MINUS, tok2); }
    |   '++' tok3=unaryExpression
            { ret_expr = new UnaryExpression(UnaryOperator.PRE_INCREMENT, tok3); }
    |   '--' tok4=unaryExpression
            { ret_expr = new UnaryExpression(UnaryOperator.PRE_DECREMENT, tok4); }
    |   tok5=unaryExpressionNotPlusMinus
            { ret_expr = tok5; }
    ;

unaryExpressionNotPlusMinus returns [Expression ret_expr]
    :   '~' t1=unaryExpression
            { ret_expr = new UnaryExpression(UnaryOperator.BITWISE_COMPLEMENT, t1); }
    |   '!' t2=unaryExpression
            { ret_expr = new UnaryExpression(UnaryOperator.LOGICAL_NEGATION, t2); }
    |   t3=castExpression
            { ret_expr = t3; }
    |   t4=primary t5=selector* ('++'|'--')?
            { /* TODO */ }
    ;

castExpression
    :  '(' primitiveType ')' unaryExpression
    |  '(' (type | expression) ')' unaryExpressionNotPlusMinus
    ;

primary
    :   parExpression
    |   'this' ('.' Identifier)* identifierSuffix?
    |   'super' superSuffix
    |   literal
    |   'new' creator
    |   Identifier ('.' Identifier)* identifierSuffix?
    |   primitiveType ('[' ']')* '.' 'class'
    |   'void' '.' 'class'
    ;

identifierSuffix
    :   ('[' ']')+ '.' 'class'
    |   ('[' expression ']')+ // can also be matched by selector, but do here
    |   arguments
    |   '.' 'class'
    |   '.' explicitGenericInvocation
    |   '.' 'this'
    |   '.' 'super' arguments
    |   '.' 'new' innerCreator
    ;

creator
    :   nonWildcardTypeArguments createdName classCreatorRest
    |   createdName (arrayCreatorRest | classCreatorRest)
    ;

createdName
    :   classOrInterfaceType
    |   primitiveType
    ;

innerCreator
    :   nonWildcardTypeArguments? Identifier classCreatorRest
    ;

arrayCreatorRest
    :   '['
        (   ']' ('[' ']')* arrayInitializer
        |   expression ']' ('[' expression ']')* ('[' ']')*
        )
    ;

classCreatorRest
    :   arguments classBody?
    ;

explicitGenericInvocation
    :   nonWildcardTypeArguments Identifier arguments
    ;

nonWildcardTypeArguments
    :   '<' typeList '>'
    ;

selector
    :   '.' Identifier arguments?
    |   '.' 'this'
    |   '.' 'super' superSuffix
    |   '.' 'new' innerCreator
    |   '[' expression ']'
    ;

superSuffix
    :   arguments
    |   '.' Identifier arguments?
    ;

/* OK */
arguments returns [List param_list]
    @init { param_list = new LinkedList(); }
    :   '(' (t1=expressionList { param_list.add(t1); })? ')'
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