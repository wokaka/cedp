/*
Copyright (c) 1998-2000, Non, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

	Redistributions of source code must retain the above copyright
	notice, this list of conditions, and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions, and the following disclaimer in
	the documentation and/or other materials provided with the
	distribution.

	All advertising materials mentioning features or use of this
	software must display the following acknowledgement:

		This product includes software developed by Non, Inc. and
		its contributors.

	Neither name of the company nor the names of its contributors
	may be used to endorse or promote products derived from this
	software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COMPANY OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        Copyright (c) Non, Inc. 1997 -- All Rights Reserved

PROJECT:        C Compiler
MODULE:         Parser
FILE:           stdc.g

AUTHOR:         John D. Mitchell (john@non.net), Jul 12, 1997

REVISION HISTORY:

        Name    Date            Description
        ----    ----            -----------
        JDM     97.07.12        Initial version.
        JTC     97.11.18        Declaration vs declarator & misc. hacking.
        JDM     97.11.20        Fixed:  declaration vs funcDef,
                                        parenthesized expressions,
                                        declarator iteration,
                                        varargs recognition,
                                        empty source file recognition,
                                        and some typos.


DESCRIPTION:

        This grammar supports the Standard C language.

        Note clearly that this grammar does *NOT* deal with
        preprocessor functionality (including things like trigraphs)
        Nor does this grammar deal with multi-byte characters nor strings
        containing multi-byte characters [these constructs are "exercises
        for the reader" as it were :-)].

        Please refer to the ISO/ANSI C Language Standard if you believe
        this grammar to be in error.  Please cite chapter and verse in any
        correspondence to the author to back up your claim.

TODO:

        - typedefName is commented out, needs a symbol table to resolve
        ambiguity.

        - trees

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
header {
package cetus.base.grammars;
}

{
//import java.io.*;

//import antlr.CommonAST;
//import antlr.DumpASTVisitor;
import java.util.*;
import cetus.hir.*;
//John A. Stratton: September 2008
// Sometimes need to access the parameters to slightly change parser behavior.
import cetus.exec.*;
}


class NewCParser extends Parser;

options
        {
        k = 2;
        exportVocab = NEWC;
        //buildAST = true;
        //ASTLabelType = "TNode";

        // Copied following options from java grammar.
        codeGenMakeSwitchThreshold = 2;
        codeGenBitsetTestThreshold = 3;
        }


{


		Expression baseEnum = null,curEnum = null;
		NewCLexer curLexer=null;
		boolean isFuncDef = false;
		boolean isExtern = false;
	   	PreprocessorInfoChannel preprocessorInfoChannel = null;
        SymbolTable symtab = null;
        CompoundStatement curr_cstmt = null;
        boolean hastypedef = false;
        HashMap<String,String> typetable = null;
        LinkedList<Declaration> currproc = new LinkedList<Declaration>();
        Declaration prev_decl = null;
        boolean old_style_func = false;
        HashMap<String,Declaration> func_decl_list = new HashMap<String,Declaration>();
        public void getPreprocessorInfoChannel(PreprocessorInfoChannel preprocChannel )
		{
        	preprocessorInfoChannel = preprocChannel;

		}
		public void setLexer(NewCLexer lexer){
			curLexer=lexer;
			curLexer.setParser(this);
		}
		public NewCLexer getLexer(){
			return curLexer;
		}
		public LinkedList<Pragma> getPragma(int a){
		 	return preprocessorInfoChannel.extractLinesPrecedingTokenNumber
								(new Integer(a));
		}
        public void putPragma(Token sline,SymbolTable sym){
                	LinkedList<Pragma> v  = null;
                	v = getPragma(((CToken)sline).getTokenNumber());
        			Iterator<Pragma> iter = v.iterator();
        			Pragma p = null;
        				PreAnnotation anote = null;
        			while(iter.hasNext()){
        				p = iter.next();
        			 	anote = new PreAnnotation(p.str);
        				if(p.type ==Pragma.pragma)
        					anote.setPrintMethod(PreAnnotation.print_raw_method);
        				else if(p.type ==Pragma.comment)
        					anote.setPrintMethod(PreAnnotation.print_raw_method);
        				//sym.addStatement(new DeclarationStatement(anote));
        				if(sym instanceof CompoundStatement)
        					((CompoundStatement)sym).addStatement(new DeclarationStatement(anote));
        				else
        					sym.addDeclaration(anote);
        			}
        }

    // Suppport C++-style single-line comments?
    public static boolean CPPComments = true;
	public Stack<SymbolTable> symtabstack = new Stack<SymbolTable>();
	public Stack<HashMap<String,String>> typestack = new Stack<HashMap<String,String>>();
	public void enterSymtab(SymbolTable curr_symtab){
		symtabstack.push(symtab);
		typetable = new HashMap<String,String>();
		typestack.push(typetable);
		symtab = curr_symtab;
	}
	public void exitSymtab(){
		SymbolTable o = symtabstack.pop();
		if(o != null){
			typestack.pop();
			typetable = (typestack.peek());
			symtab = o;
		}
	}
    public boolean isTypedefName(String name) {
		/*
		boolean returnValue = false;
		Object o = typetable.get(name);
		if(o == null){
			returnValue = false;
		}
		else{
			returnValue = true;
		}

      if(name.equals("__builtin_va_list"))
      	returnValue = true;


      return returnValue;
      */

      //System.err.println("Typename "+name);
      int n = typestack.size()-1;
      Object d = null;
      while(n>=0){
          	d = typestack.get(n).get(name);

      		if(d != null )
      			return true;


			n--;
      }
      if(name.equals("__builtin_va_list"))
      	return true;

      //System.err.println("Typename "+name+" not found");

      return false;

      /*
      System.err.println("Checking for typedef name: "+name);
      boolean returnValue = false;
      Declaration d = Tools.findSymbol(symtab,new Identifier(name));
      if(d != null && d instanceof VariableDeclaration){
      	VariableDeclaration v = (VariableDeclaration)d;
      	List l = v.getSpecifiers();
      	Iterator i = l.iterator();
      	Object o = null;
      	while(i.hasNext()){
      		o = i.next();
      		if(o == Specifier.TYPEDEF)
      			return true;
      	}

      }
      if(name.equals("__builtin_va_list"))
      	returnValue = true;

      if(returnValue ==false){

      	System.err.println(name+" is not a typedef name");
      	System.err.println(symtab.getClass());
      }
      return returnValue;
      */
    }





        int traceDepth = 0;
        public void reportError(RecognitionException ex){
          try {
            //System.err.println("ANTLR Parsing Error: "+ex + " token name:" + tokenNames[LA(1)]);
            //System.err.println("Before: ");
	    //((Printable)symtab).print(System.err);
	    //System.err.println();
	    System.err.println("ANTLR Parsing Error: "+"Exception Type: "+ex.getClass().getName());
            System.err.println("Source: "+getLexer().lineObject.getSource()+" Line:"+ex.getLine()+" Column: "+ex.getColumn() +" token name:" + tokenNames[LA(1)]);
            ex.printStackTrace(System.err);
            System.exit(1);
          }
	  catch (TokenStreamException e) {
            System.err.println("ANTLR Parsing Error: "+ex);
            ex.printStackTrace(System.err);
	    System.exit(1);
          }
        }
        public void reportError(String s) {
            System.err.println("ANTLR Parsing Error from String: " + s);
        }
        public void reportWarning(String s) {
            System.err.println("ANTLR Parsing Warning from String: " + s);
        }
        public void match(int t) throws MismatchedTokenException {
          boolean debugging = false;

          if ( debugging ) {
           for (int x=0; x<traceDepth; x++) System.out.print(" ");
           try {
            System.out.println("Match("+tokenNames[t]+") with LA(1)="+
                tokenNames[LA(1)] + ((inputState.guessing>0)?" [inputState.guessing "+ inputState.guessing + "]":""));
           }
           catch (TokenStreamException e) {
            System.out.println("Match("+tokenNames[t]+") " + ((inputState.guessing>0)?" [inputState.guessing "+ inputState.guessing + "]":""));

           }

          }
          try {
            if ( LA(1)!=t ) {
                if ( debugging ){
                    for (int x=0; x<traceDepth; x++) System.out.print(" ");
                    System.out.println("token mismatch: "+tokenNames[LA(1)]
                                + "!="+tokenNames[t]);
                }
	        throw new MismatchedTokenException(tokenNames, LT(1), t, false, getFilename());

            } else {
                // mark token as consumed -- fetch next token deferred until LA/LT
                consume();
            }
          }
          catch (TokenStreamException e) {
          }

        }
        public void traceIn(String rname) {
          traceDepth += 1;
          for (int x=0; x<traceDepth; x++) System.out.print(" ");
          try {
            System.out.println("> "+rname+"; LA(1)==("+ tokenNames[LT(1).getType()]
                + ") " + LT(1).getText() + " [inputState.guessing "+ inputState.guessing + "]");
          }
          catch (TokenStreamException e) {
          }
        }
        public void traceOut(String rname) {
          for (int x=0; x<traceDepth; x++) System.out.print(" ");
          try {
            System.out.println("< "+rname+"; LA(1)==("+ tokenNames[LT(1).getType()]
                + ") "+LT(1).getText() + " [inputState.guessing "+ inputState.guessing + "]");
          }
          catch (TokenStreamException e) {
          }
          traceDepth -= 1;
        }

}

/*
 *	TranslationUnit
 */

translationUnit [TranslationUnit init_tunit] returns [TranslationUnit tunit]
		{
			/* build a new Translation Unit */
			if(init_tunit == null)
				tunit = new TranslationUnit(getLexer().originalSource);
			else
				tunit = init_tunit;
			enterSymtab(tunit);
			/*
			symtab = tunit;
			typetable = new HashMap();
			*/

		}
        :       ( externalList[tunit]

        		)?       /* Empty source files are allowed.  */

			{//System.err.println(typetable);
				exitSymtab();
			}
        ;

externalList [TranslationUnit tunit]
			{ /*boolean flag = true;*/	}
        :       (
        			pre_dir:PREPROC_DIRECTIVE
					{
						//String value = (pre_dir.getText()).substring(7).trim();
						putPragma(pre_dir,symtab);
						/*
						if(value.startsWith("endinclude")){

								flag = true;
						}
						else if(value.startsWith("startinclude")){

								flag = false;
						}
						*/
						PreAnnotation anote = new PreAnnotation(pre_dir.getText());
						tunit.addDeclaration(anote);
						anote.setPrintMethod(PreAnnotation.print_raw_method);



						//elist.add(pre_dir.getText());
					}
					|
        			externalDef[tunit]
					/*
					{
						if(flag){
							//elist.add(edef);
						}
					}
					*/
        		)+
        ;
/*
 *	Declaration
 */

externalDef [TranslationUnit tunit]
        {
			Declaration decl = null;
		}
        :
               ( "typedef" | declaration )=>
        		decl=declaration
        		{
        			if(decl != null){
        				/*System.err.println("Adding Declaration");
        				decl.print(System.err);
        				System.err.println("");*/
        				//Tools.printStatus("Adding Declaration: ",3);
        				//Tools.printlnStatus(decl,3);
        				tunit.addDeclaration(decl);
        			}

        		}
        |   ( functionPrefix )=>
        		decl=functionDef
        		{
        			/*System.err.println("Adding Declaration");
        				decl.print(System.err);
        				System.err.println("");*/
        			//Tools.printStatus("Adding Declaration: ",3);
        			//	Tools.printlnStatus(decl,3);
        			tunit.addDeclaration(decl);}
        |   decl=typelessDeclaration
        		{/*System.err.println("Adding Declaration");
        				decl.print(System.err);
        				System.err.println("");*/
        			//	Tools.printStatus("Adding Declaration: ",3);
        			//	Tools.printlnStatus(decl,3);
        			tunit.addDeclaration(decl);}
        |   asm_expr // not going to handle this now
        |   SEMI	// empty declaration - ignore it
        ;

/* these two are here because GCC allows "cat = 13;" as a valid program! */
//Need to check side effect
functionPrefix
                {/*Declarator decl = null;*/}
        :       ( (functionDeclSpecifiers)=>
        					functionDeclSpecifiers
                |  //epsilon
                )
                // Passing "null" could cause a problem
                /*decl = */declarator
                ( declaration )* (VARARGS)? ( SEMI )*
                LCURLY
        ;

/*
 *	Declaration
 */

// Type Declaration
typelessDeclaration returns [Declaration decl]
                {decl=null;
				List<Declarator> idlist=null;}
        :
        		idlist=initDeclList SEMI
        		/*
        		 * Proper constructor missing
        		 */
        		{decl = new VariableDeclaration(new LinkedList<Specifier>(),idlist); }
        ;

// going to ignore this
asm_expr { /*Expression expr1 = null;*/}
        :       "asm"^
                ("volatile")? LCURLY expr RCURLY ( SEMI )+
        ;

/*
 *	Declaration
 */
declaration returns [Declaration bdecl]
				{bdecl=null;
				List<Specifier> dspec=null;
				List<Declarator> idlist=null;
				}
        :       dspec=declSpecifiers
                (
					// Pass specifier to add to Symtab
                    idlist=initDeclList
                )?
                {	if(idlist != null){


                		if(old_style_func){

                			Iterator<Declarator> iter = idlist.iterator();
                			Declarator d  = null;
                			Declaration newdecl = null;
                			while(iter.hasNext()){
                				d = (iter.next());
                				newdecl = new VariableDeclaration(dspec,d);
                				func_decl_list.put(d.getSymbol().toString(),newdecl);

                			}
                			bdecl = null;
						/*
							Iterator iter = idlist.iterator();
                			Declarator d  = null;
                			Declaration newdecl = null;
                			while(iter.hasNext()){
                				d = (Declarator)(iter.next());
                				newdecl = new VariableDeclaration(dspec,d);
                				symtab.addDeclaration(newdecl);

                			}
                			bdecl = null;
                		*/
						}
                		else
                			bdecl = new VariableDeclaration(dspec,idlist);
                		prev_decl = null;
                	}
                	else{
                		/*
                		 * Looks like a forward declaration
                		 */

                		if(prev_decl != null){

                			bdecl = prev_decl;
                			prev_decl = null;
                		}
                	}

                	hastypedef = false;
                }
                ( dsemi:SEMI )+ {

                	/*int sline;
                	sline = dsemi.getLine();*/

        			putPragma(dsemi,symtab);
        			hastypedef = false;

                }
        ;

/*
 *	Specifier List
 */
// The main type information
declSpecifiers returns [List<Specifier> decls]
                { decls = new LinkedList<Specifier>();
                	Specifier spec = null;
                	Specifier temp=null;}
        :       (               options { // this loop properly aborts when
                                          //  it finds a non-typedefName ID MBZ
                                          warnWhenFollowAmbig = false;
                                        } :
                  /* Modifier */
                  spec = storageClassSpecifier {decls.add(spec);}
                | /* Modifier */
                  spec = typeQualifier {decls.add(spec);}

                | /* SubType */
                  ( "struct" | "union" | "enum" | typeSpecifier )=>
                        temp = typeSpecifier
                        {
                        	decls.add(temp) ;
                        }
                 // MinGW specific
                 | attributeDecl
                )+

        ;
/*********************************
 * Specifier                      *
 **********************************/


storageClassSpecifier returns [Specifier cspec]
				{cspec= null;}
        :       "auto"
        		{cspec = Specifier.AUTO;}
        |       "register"
        		{cspec = Specifier.REGISTER;}
        |       "typedef"
        		{
        			cspec = Specifier.TYPEDEF;
        			hastypedef = true;
        		}
        |       cspec = functionStorageClassSpecifier

        ;

functionStorageClassSpecifier  returns [Specifier type] {type= null;}
        :       ( "extern" {type= Specifier.EXTERN; }
        |       "static" {type= Specifier.STATIC;}
        |       "inline"  {type= Specifier.INLINE;}
	|	"__global__" {type= Specifier.GLOBAL;}
	|	"__device__" {type= Specifier.DEVICE;}
	|	"__host__" {type= Specifier.HOST;}
	)
	//JAS added to handle gcc stuff, even if it's not passed through correctly 
	(attributeDecl)* 
        ;

typeQualifier returns [Specifier tqual] {tqual=null;}
        :       "const"
        		{tqual = Specifier.CONST;}
        |       "volatile"
        		{tqual = Specifier.VOLATILE;}
	|	"__shared__"
			{tqual = Specifier.SHARED;}
	|	"__constant__"
			{tqual = Specifier.CONSTANT;}
        ;
//	|	"__device__"
//			{tqual = Specifier.DEVICE;}


// A Type Specifier (basic type and user type)
/***************************************************
 * Should a basic type be an int value or a class ? *
 ****************************************************/
typeSpecifier returns [Specifier types]
        { types = null;
				//String tname = null;
				//Expression expr1 = null;
				//List tyname = null;
				boolean typedefold = false;
		}
        :       {typedefold = hastypedef;
        		hastypedef = false;
        }
        ( 		"void" {types = Specifier.VOID;}
        |       "char" {types = Specifier.CHAR;}
        |       "short" {types = Specifier.SHORT;}
        |       "int" {types = Specifier.INT;}
        |       "long" {types = Specifier.LONG;}
        |       "float" {types = Specifier.FLOAT;}
        |       "double" {types = Specifier.DOUBLE;}
        |       "signed" {types = Specifier.SIGNED;}
        |       "unsigned" {types = Specifier.UNSIGNED;}
		/* C99 built-in type support */
	|	"_Bool" {types = Specifier.CBOOL;}
	|	"_Complex" {types = Specifier.CCOMPLEX;}
	|	"_Imaginary" {types = Specifier.CIMAGINARY;}
		/* John A. Stratton: February 2008
		 * added support for widely used boolean type */
	|	i:"bool" {types = new UserSpecifier(new Identifier(i.getText()));}

        |       types = structOrUnionSpecifier
        		( options{warnWhenFollowAmbig=false;}: attributeDecl )*
        |       types = enumSpecifier
        |       types = typedefName
        |
        		/*
        		 * Maybe unused
        		 */
        		"typeof"^ LPAREN
                ( ( typeName )=> /*tyname=*/ typeName
                | /*expr1=*/ expr
                )
                RPAREN
        |       "__complex" {types = Specifier.DOUBLE;}
        )
        {
        	hastypedef = typedefold;
        }
        ;

typedefName returns[Specifier name] {name = null;}
        :       { isTypedefName ( LT(1).getText() ) }?
                i:ID
                //{ ## = #(#[NTypedefName], #i); }
                {name = new UserSpecifier(new Identifier(i.getText()));}
        ;


structOrUnion returns [int type] { type=0 ;}
        :       "struct"	{type = 1;}
        |       "union"		{type = 2;}
        ;
// A User Type
structOrUnionSpecifier returns [Specifier spec]
				{
					ClassDeclaration decls = null;
					String name=null;
					int type=0;
					spec = null;
					//int linenum = 0;
				}
        :       type=structOrUnion!
                (
                	//Named stucture with body
                	( ID LCURLY )=> i:ID LCURLY
                		{name = i.getText();
				//linenum = i.getLine(); 
				putPragma(i,symtab);}
                        {
                        	//String sname = null;
							if(type == 1){
									decls = new ClassDeclaration(ClassDeclaration.STRUCT,new Identifier(name));
									spec = new UserSpecifier(new Identifier("struct "+name));
							}
							else{
									decls = new ClassDeclaration(ClassDeclaration.UNION,new Identifier(name));
									spec = new UserSpecifier(new Identifier("union "+name));
							}

						}
                        ( structDeclarationList[decls] )?
                       {
                       		if(symtab instanceof ClassDeclaration){
                       			int si = symtabstack.size()-1;
                       			for(;si>=0;si--){
                       				if(!(symtabstack.get(si) instanceof ClassDeclaration)){

                       						(symtabstack.get(si)).addDeclaration(decls);
                       					break;
                       				}
                       			}
                       		}
                       		else
                       			symtab.addDeclaration(decls);
                       }
                     RCURLY
                |
                	// unnamed structure with body
                  	// This is for one time use
										// Added "named_" to prevent illegal identifiers.
                	l1:LCURLY
                	{
                		name = "named_"+getLexer().originalSource +"_"+ ((CToken)l1).getTokenNumber();
                		name =name.replaceAll("[.]","_");
                		name =name.replaceAll("-","_");
                		//linenum = l1.getLine(); 
				putPragma(l1,symtab);
                		if(type == 1){
							decls = new ClassDeclaration(ClassDeclaration.STRUCT,new Identifier(name));
							spec = new UserSpecifier(new Identifier("struct "+name));
						}
						else{
							decls = new ClassDeclaration(ClassDeclaration.UNION,new Identifier(name));
							spec = new UserSpecifier(new Identifier("union "+name));
						}

					}
                    ( structDeclarationList[decls] )?
                    {
                    	if(symtab instanceof ClassDeclaration){
                       			int si = symtabstack.size()-1;
                       			for(;si>=0;si--){
                       				if(!(symtabstack.get(si) instanceof ClassDeclaration)){

                       					(symtabstack.get(si)).addDeclaration(decls);
                       					break;
                       				}
                       			}
                       		}
                       		else
                       			symtab.addDeclaration(decls);
                    }
                    RCURLY
                | // named structure without body
                	sou3:ID
                	{name = sou3.getText();
			//linenum = sou3.getLine(); 
			putPragma(sou3,symtab);}
					{
						if(type == 1){
							spec = new UserSpecifier(new Identifier("struct "+name));
							decls = new ClassDeclaration(ClassDeclaration.STRUCT,new Identifier(name),true);
						}
						else{
							spec = new UserSpecifier(new Identifier("union "+name));
							decls = new ClassDeclaration(ClassDeclaration.UNION,new Identifier(name),true);
						}
						prev_decl = decls;
					}

                )
        ;

/*
 * Declarations are added to ClassDeclaration
 */

structDeclarationList [ClassDeclaration cdecl] {Declaration sdecl= null;/*SymbolTable prev_symtab = symtab;*/}
        :
        	{
        		enterSymtab(cdecl);
        	}
        	( sdecl=structDeclaration  {if(sdecl != null )cdecl.addDeclaration(sdecl);} )+
        	{
        		exitSymtab();
        		/*symtab = prev_symtab;*/
        	}
        ;


/*
 * A declaration
 */
structDeclaration returns [Declaration sdecl]
			{
				List<Specifier> bsqlist=null;
	        	List<Declarator> bsdlist=null;
				sdecl=null;
			}
        :
        		bsqlist = specifierQualifierList

        		// passes specifier to put in symtab
				bsdlist = structDeclaratorList
        		 ( COMMA! )? ( SEMI! )+
        		{sdecl = new VariableDeclaration(bsqlist,bsdlist);
        		hastypedef = false;
        		}
        ;

/*
 * List of Specifiers
 */
specifierQualifierList returns [List<Specifier> sqlist]
               //{ int specCount = 0; }
               {
               		sqlist=new LinkedList<Specifier>();
					Specifier tspec=null;
					Specifier tqual=null;
				}
        :       (               options {   // this loop properly aborts when
                                            // it finds a non-typedefName ID MBZ
                                            warnWhenFollowAmbig = false;
                                        } :
                /* A type : BaseType */
                ( "struct" | "union" | "enum" | typeSpecifier )=>
                  tspec = typeSpecifier {sqlist.add(tspec);}
                |
                /* A Modifier : int value */
                tqual=typeQualifier {sqlist.add(tqual);}
                )+
        ;

/*
 * List of Declarators
 */
structDeclaratorList returns [List<Declarator> sdlist]
				{
					sdlist = new LinkedList<Declarator>();
         			Declarator sdecl=null;
         		}
        :       sdecl = structDeclarator
        		{
        			/*
        			 * why am I getting a null value here ?
        			 */
        			if(sdecl != null)
        			sdlist.add(sdecl);
        		}
        		( options{warnWhenFollowAmbig=false;}:
        		COMMA! sdecl=structDeclarator
        		{
        			sdlist.add(sdecl);
        		}
        		)*
        ;

/*
 *	Declarator
 */
structDeclarator returns [Declarator sdecl]
		{
			sdecl=null;
			Expression expr1=null;
		}
        :       ( sdecl = declarator )?
                //( COLON expr1=constExpr )?
								/*
								 * bit-field recognition
                 */
								( COLON expr1=expr )?
								{
									if ( sdecl != null && expr1 != null ) {
										expr1 = cetus.analysis.NormalExpression.simplify(expr1);
										if ( expr1 instanceof IntegerLiteral )
											sdecl.addTrailingSpecifier(new BitfieldSpecifier(expr1));
										else
											; // need to throw parse error
									}
								}
                /*
                 * This needs to be fixed
                 */
                //{sdecl.addExpr(expr1);}
            	// Ignore this GCC dialect
            	/*
            	{if(sdecl == null && expr1 == null){
            	System.err.println("Errorororororo");
            	}
            	}*/
                ( attributeDecl )*
        ;

/*
 * UserSpecifier (Enumuration)
 */
enumSpecifier returns[Specifier spec]
		 {
		 	cetus.hir.Enumeration espec = null;
		 	String enumN = null;
		 	List<Declarator> elist=null;
		 	spec = null;
		 }
        :       "enum"^
                ( ( ID LCURLY )=> i:ID
                LCURLY elist=enumList RCURLY
                 {enumN =i.getText();}
                | el1:LCURLY elist=enumList RCURLY
                	//{enumN = "anonymous";}
                	//{enumN = "";}
                	{

                	enumN = getLexer().originalSource +"_"+ ((CToken)el1).getTokenNumber();
                		enumN =enumN.replaceAll("[.]","_");
                		enumN =enumN.replaceAll("-","_");
                	}
                | espec2:ID {enumN =espec2.getText();}
                )
				// has name and list of members
                {
                	if(elist != null){

                		espec = new cetus.hir.Enumeration(new Identifier(enumN),elist);
                		{
                				if(symtab instanceof ClassDeclaration){
                       			int si = symtabstack.size()-1;
                       			for(;si>=0;si--){
                       				if(!(symtabstack.get(si) instanceof ClassDeclaration)){

                       					(symtabstack.get(si)).addDeclaration(espec);
                       					break;
                       				}
                       			}
                       		}
                       		else
                       			symtab.addDeclaration(espec);

                    	}
                	}


                	spec = new UserSpecifier(new Identifier("enum "+enumN));
                }
        ;
/*
 * List of Declarator
 */

enumList returns [List<Declarator> elist]
         {
         	Declarator enum1=null;
         	elist = new LinkedList<Declarator>();
         }
        :       enum1=enumerator {elist.add(enum1);}
        		( options{warnWhenFollowAmbig=false;}:
        		COMMA! enum1=enumerator {elist.add(enum1);}
        		)*
        		( COMMA! )?
        ;

/*
 *	Declarator
 */
// Complicated due to setting values for each enum value
enumerator  returns[Declarator decl]
        {
        	decl=null;Expression expr2=null;

        	String val = null;
        }
        :       /*
        		 * Declarator
        		 */
        		i:ID {
        			val = i.getText();
        			decl = new VariableDeclarator(new Identifier(val));
        		}
        		/*
        		 * Initializer
        		 */
                (ASSIGN expr2=constExpr
                 {
        			decl.setInitializer(new Initializer(expr2));
        		}

                )?

        ;

// Not handling this as of now (sort of GCC stuff)
attributeDecl
//JAS: edited to at least not fail when recognized, even if it's not input correctly
        :       LITERAL___attribute^ 
		LPAREN LPAREN attributeList RPAREN RPAREN
		(attributeDecl)*
        |	"__asm"^
		LPAREN stringConst RPAREN
        ;

attributeList
        :       attribute
		( options{warnWhenFollowAmbig=false;}:
		
		COMMA attribute
		)*
	//	( COMMA )?
        ;

attribute
        :       (
		// Word
		(
		ID
		//| declSpecifiers
		| storageClassSpecifier
		| typeQualifier
		)
		(
		LPAREN 
			(
			ID
			//|
			//assignExpr
			| //epsilon
			)
		
			(
			//(COMMA assignExpr)*
			expr
			|
			) //epsilon
		RPAREN
		)?
		//~(LPAREN | RPAREN | COMMA)
                //|  LPAREN attributeList RPAREN
                )?
        ;

/*
 *	List of Declarator
 */
initDeclList returns [List<Declarator> dlist]
        		{
	        		Declarator decl=null;
					dlist = new LinkedList<Declarator>();
        		}
        :       decl = initDecl
        		{
	        		dlist.add(decl);
	    		}
                ( options{warnWhenFollowAmbig=false;}:
                COMMA!
                decl = initDecl
                {
	        		dlist.add(decl);
	    		}
                )*
                ( COMMA! )?
        ;
/*
 *	Declarator
 */
initDecl returns [Declarator decl]
                {
					decl = null;
					//Initializer binit=null;
					Object binit = null;
					//Expression expr1=null;
				}
        :
        		// casting could cause a problem
        		decl = declarator
                ( attributeDecl )* // Not Handled
                ( ASSIGN binit=initializer
                | COLON /*expr1=*/ expr // What is this guy ?
                )?
                {
                	if(binit instanceof Expression)
                		binit = new Initializer((Expression)binit);
                	if(binit != null){
                	decl.setInitializer((Initializer)binit);
                	/*
                	System.out.println("Initializer " + decl.getClass());
                	decl.print(System.out);
                	System.out.print(" ");
                	((Initializer)binit).print(System.out);
                	System.out.println("");
                	*/
                	}

                }
        ;


// add a pointer to the type list
pointerGroup returns [List<Specifier> bp]
         {
         	bp = new LinkedList<Specifier>();
         	Specifier temp = null;
         	boolean b_const = false;
         	boolean b_volatile = false;
         }

        :       (
        			STAR
        			 // add the modifer
        			(
        				temp = typeQualifier
        				{
        					if(temp == Specifier.CONST)
        						b_const = true;

        					else if(temp == Specifier.VOLATILE)
        						b_volatile = true;
        				}
        			)*
        			{
        				if(b_const && b_volatile)
        					bp.add(PointerSpecifier.CONST_VOLATILE);
        				else if(b_const)
        					bp.add(PointerSpecifier.CONST);
        				else if(b_volatile)
        					bp.add(PointerSpecifier.VOLATILE);
        				else
        					bp.add(PointerSpecifier.UNQUALIFIED);
        			b_const = false;
        			b_volatile = false;
        			}
        		)+

        ;

// need to decide what to add
idList returns [List<Declaration> ilist]
         {
         	//int i = 1;
         	String name;
		//Specifier temp = null;
         	ilist = new LinkedList<Declaration>();
         }
        :       idl1:ID
        		{
        			name = idl1.getText();
        			ilist.add(new VariableDeclaration(new VariableDeclarator(new Identifier(name))));

        		}
        		( options{warnWhenFollowAmbig=false;}: COMMA
        		idl2:ID
        		{
        				name = idl2.getText();
        				ilist.add(new VariableDeclaration(new VariableDeclarator(new Identifier(name))));
        		}
        		)*

        ;

//initializer returns [Initializer binit]
initializer returns [Traversable binit]
		{binit = null; Expression expr1 = null;
           	List<Traversable> ilist = null;}
        : (
        	(
        		( (initializerElementLabel)=> initializerElementLabel )?
                (
                	expr1=assignExpr
                	{
                		//binit = new Initializer(expr1);
                		binit = expr1;
                	}
                	| ilist=lcurlyInitializer
                	{binit = new Initializer(ilist);}
                )
           )
              | ilist=lcurlyInitializer
              	{binit = new Initializer(ilist);}
         )
        ;

// GCC allows more specific initializers
initializerElementLabel {/*Expression expr1 = null,expr2=null;*/}
        :   (   ( LBRACKET
        		((/*expr1=*/constExpr VARARGS)=>
        			/*expr1=*/rangeExpr
        		| /*expr2=*/constExpr) RBRACKET (ASSIGN)? )
                | ID COLON
                | DOT ID ASSIGN
            )
        ;

// GCC allows empty initializer lists
lcurlyInitializer returns [List<Traversable> ilist] {ilist = new LinkedList<Traversable>();}
        :
                LCURLY^
                (ilist=initializerList ( COMMA! )? )?
                RCURLY
        ;

initializerList returns [List<Traversable> ilist]
		{Traversable init = null; ilist = new LinkedList<Traversable>();}
        :
        		(
        			init = initializer {ilist.add(init);}
        		)
        		(
        				 options{warnWhenFollowAmbig=false;}:COMMA! init = initializer
        				 {ilist.add(init);}
        		)*
        ;

/*
 *	Declarator
 */
declarator returns [Declarator decl]
			{
				Expression expr1=null;
				String declName = null;
				decl = null;
				Declarator tdecl = null;
				IDExpression idex = null;
				List<Declaration> plist = null;
				List<Specifier> bp = null;
				Specifier aspec = null;
				boolean isArraySpec = false;
				//boolean isNested = false;
				List<Expression> llist = new LinkedList<Expression>();
				List<Specifier> tlist = null;
			}
        :


        		// Pass "Type" to add pointer Type
                ( bp=pointerGroup )?
                {/*
                	if(bp == null)
                		bp = new LinkedList();
                */
                }
				(attributeDecl)? // For cygwin support
                (
                	id:ID
                	// Add the name of the Var
                	{
                		declName = id.getText();
                		idex = new Identifier(declName);
						if(hastypedef){
							typetable.put(declName,"typedef");
						}
                	}
                |
                	/*
                	 *	Nested Declarator
                	 */
                	LPAREN
                	tdecl = declarator
                	RPAREN
                	{
	               	}
                )
			// Attribute Specifier List Possible
			(attributeDecl)?
				/*
				 *	I give up this part !!!
				 */
                (
                	/*
                	 *	Parameter List
                	 */
                	plist = declaratorParamaterList
                	{
                		//decl = new Declarator(bp,idex,plist,null,null);
                	}
                |
                	/*
                	 *	ArraySpecifier
                	 */
                	LBRACKET ( expr1=expr )? RBRACKET
                	{
                		isArraySpec = true;

                			llist.add(expr1);

                	}
                )*
                {
					/*
					 * Possible combinations
					 * []+ ,  ()
					 */
					 if(plist != null){

                		/*
                		if(isArraySpec){

                			aspec = new ArraySpecifier(llist);
                		//aspec = new ArraySpecifier();
                		tlist = new LinkedList();
                		tlist.add(aspec);
                		}
                		*/
                		/*
                		 * ()
                		 */

					}
					else{
						/*
						 * []+
						 */


						if(isArraySpec){
							/*
							 * []+
							 */
							aspec = new ArraySpecifier(llist);
							//aspec = new ArraySpecifier();
							tlist = new LinkedList<Specifier>();
							tlist.add(aspec);
						}

					}
					/*
				if(idex != null){
					decl = new Declarator(bp, idex, plist, tlist,null) ;
				}
				else{
					// this is wrong
					decl = new Declarator(bp, tdecl, plist) ;
				}
					*/
					if(bp == null)
            				bp = new LinkedList<Specifier>();
					if(tdecl != null) // assume tlist == null
					{
						//assert tlist == null : "Assertion (tlist == null) failed 2";
						if(tlist == null)
            					tlist = new LinkedList<Specifier>();
						//if(plist != null){
							decl = new NestedDeclarator(bp,tdecl,plist,tlist);
						//}
						//else
						//	decl = new NestedDeclarator(bp,tdecl,new LinkedList(),tlist);
					}
					else{
						if(plist != null) // assume tlist == null
            					decl = new ProcedureDeclarator(bp,idex,plist);
            			else{
            				if(tlist != null)
            					decl = new VariableDeclarator(bp,idex,tlist);
            				else
            					decl = new VariableDeclarator(bp,idex);
            			}
					}
					//decl = new Declarator(bp, idex,tdecl,plist, tlist);
					//hastypedef = false;

                }
        ;
/*
 *	List
 */
declaratorParamaterList returns [List<Declaration> plist]

        {
        	plist = new LinkedList<Declaration>();
        }
        :
                LPAREN^
                (
                        (declSpecifiers)=>
                        plist=parameterTypeList

                        | (plist=idList)?
                )

                ( COMMA! )?
                RPAREN
        ;
/*
 *	List of (?)
 */
parameterTypeList returns [List<Declaration> ptlist]
        {
        	ptlist = new LinkedList<Declaration>();
        	Declaration pdecl = null;
	    }
        :       pdecl=parameterDeclaration
        		{ptlist.add(pdecl);}
                (   options {
                            warnWhenFollowAmbig = false;
                        } :
                  ( COMMA | SEMI )
                  pdecl = parameterDeclaration
                   {ptlist.add(pdecl);}
                )*
                /*
                 *	What about "..." ?
                 */
                ( ( COMMA | SEMI )
                  VARARGS {ptlist.add(new VariableDeclaration(new VariableDeclarator(new Identifier("..."))));}
                )?
        ;

/*
 *	Declaration (?)
 */
parameterDeclaration returns [Declaration pdecl]
			{
				pdecl =null;
				List<Specifier> dspec = null;
				Declarator decl = null;
				boolean prevhastypedef = hastypedef;
				hastypedef = false;
			}
        :       dspec=declSpecifiers
                (
                	( declarator )=> decl = declarator
                |
                	decl = nonemptyAbstractDeclarator
                )?
                {
                	if(decl != null){

                		pdecl = new VariableDeclaration(dspec,decl);
                		if(isFuncDef){
                			currproc.add(pdecl);
                		}
                	}
                	else
                		pdecl = new VariableDeclaration(dspec,new VariableDeclarator(new Identifier("")));
									hastypedef = prevhastypedef;
                }
        ;

/* JTC:
 * This handles both new and old style functions.
 * see declarator rule to see differences in parameters
 * and here (declaration SEMI)* is the param type decls for the
 * old style.  may want to do some checking to check for illegal
 * combinations (but I assume all parsed code will be legal?)
 */

functionDef returns [Procedure curFunc]
			{
				CompoundStatement stmt=null;
				Declarator bdecl=null;
				List<Specifier> dspec=null;
				curFunc = null;
				int dcount = 0;
				//SymbolTable prev_symtab =null;
				SymbolTable temp_symtab = new CompoundStatement();
			}

        :       (
        		{ isFuncDef = true;}
        		(functionDeclSpecifiers)=>
        		dspec=functionDeclSpecifiers
                |  //epsilon
                )
                {
                	if(dspec == null)
                		dspec = new LinkedList<Specifier>();
                }
                bdecl = declarator
                /*
                 *	This type of declaration is a problem
                 */
                 {
                 	/*
                 		prev_symtab = symtab;
                 		symtab = temp_symtab;
                 	*/
                 	enterSymtab(temp_symtab);
                 		old_style_func = true;
                 		func_decl_list.clear();
                 }
                ( declaration {dcount++;})* (VARARGS)? ( SEMI! )*
                {
                	old_style_func = false;
                	/*
                	symtab = prev_symtab;
                	*/
                	exitSymtab();
                }
                {

                	isFuncDef = false;

                	if(dcount > 0){
                		//HashMap hm = null;
                		Identifier name = null;
					    Declaration tdecl = null;

                		/**
                		 *  This implementation is not so good since it relies on
                		 * the fact that function parameter starts from the second
                		 *  children and getChildren returns a reference to the
                		 * actual internal list
                		 */
                		ListIterator<Traversable> i = ((bdecl.getChildren())).listIterator();
					    i.next();
					    while (i.hasNext())
					    {
					      VariableDeclaration vdec = (VariableDeclaration)i.next();

					      Iterator<IDExpression> j = vdec.getDeclaredSymbols().iterator();
					      while (j.hasNext())
					      {
					      	// declarator name
					        name = (Identifier)(j.next());
					       /*
					        // find matching Declaration

					        hm = temp_symtab.getTable();

					        tdecl = (Declaration)(hm.get(name));
					        if(tdecl == null){
					        	//ByteArrayOutputStream bs = new ByteArrayOutputStream();
					        	//name.print(bs);
					        	System.err.println("cannot find symbol "+name+"------------"+hm);
					        }

					        // replace declaration
					        else
					        i.set(tdecl);
					        */

					        // find matching Declaration

					        tdecl = (func_decl_list.get(name.toString()));
					        if(tdecl == null){
					        	//ByteArrayOutputStream bs = new ByteArrayOutputStream();
					        	//name.print(bs);
					        	Tools.printlnStatus("cannot find symbol "+name+ "in old style function declaration, now assuming an int",1);
					        	tdecl = new VariableDeclaration(Specifier.INT,new VariableDeclarator((Identifier)name.clone())) ;
					        	i.set(tdecl);
					        }
					        // replace declaration
					        else
					        i.set(tdecl);

					      }
					    }

                		Iterator<Map.Entry<IDExpression,Declaration>> diter = temp_symtab.getTable().entrySet().iterator();
	                	Declaration tobject = null;
	                	while(diter.hasNext()){
	                		tobject = diter.next().getValue();
	                		if(tobject instanceof PreAnnotation)
	                			symtab.addDeclaration(tobject);
	                	}
	                }


				}
				/*
				{
				curFunc = new Procedure(dspec,bdecl, stmt);

				enterSymtab(curFunc);
				}
				stmt=compoundStatement
				{
				exitSymtab();
				curFunc.setBody(stmt);
				currproc.clear();
				}
				*/

                stmt=compoundStatement
                {
					if(stmt != null){
						curFunc = new Procedure(dspec,bdecl, stmt);
					}
					// function delaration
					else{
						curFunc = new Procedure(dspec,bdecl, stmt);
					}
					Tools.printStatus("Creating Procedure: ",1);
					Tools.printlnStatus(bdecl,1);
					// already handled in constructor

					//Iterator iter = currproc.iterator();
					//while(iter.hasNext()){
					//	curFunc.addDeclaration((Declaration)(iter.next()));
					//}

					//System.err.println(currproc);
					currproc.clear();
				}

        ;

functionDeclSpecifiers returns [List<Specifier> dspec]
         {
         	dspec = new LinkedList<Specifier>();
         	Specifier type=null;
         	Specifier tqual=null;
         	Specifier tspec=null;
         }
        :       ( options {   // this loop properly aborts when
                   // it finds a non-typedefName ID MBZ
                  warnWhenFollowAmbig = false;
                  } :
                  type=functionStorageClassSpecifier {dspec.add(type);}
                | tqual=typeQualifier {dspec.add(tqual);}
                | ( "struct" | "union" | "enum" | tspec=typeSpecifier)=>
                        tspec=typeSpecifier {dspec.add(tspec);}
                )+
        ;

declarationList
			{Declaration decl=null;/*LinkedList tlist = new LinkedList();*/}
         :       (               options {   // this loop properly aborts when
                                            // it finds a non-typedefName ID MBZ
                                            warnWhenFollowAmbig = false;
                                        } :

                localLabelDeclaration
                |  ( declarationPredictor )=>
                	decl=declaration //{ if(decl != null ) tlist.add(0,decl);}
                	{ if(decl != null ) curr_cstmt.addDeclaration(decl);}
                )+
                /*
                {
                	int i = 0;
                	for(i = 0; i < tlist.size();i++){
                		cstmt.addDeclaration((Declaration)tlist.get(i));
                	}
                }*/
        ;

declarationPredictor  {/*Declaration decl=null;*/}
        :       (options {      //only want to look at declaration if I don't see typedef
                    warnWhenFollowAmbig = false;
                }:
                "typedef"
                | /*decl=*/declaration
                )
        ;

localLabelDeclaration
        :       ( //GNU note:  any __label__ declarations must come before regular declarations.
                "__label__"^ ID (options{warnWhenFollowAmbig=false;}: COMMA! ID)* ( COMMA! )? ( SEMI! )+
                )
        ;

compoundStatement returns [CompoundStatement stmt]{
				stmt = null;
				int linenum = 0;
				SymbolTable prev_symtab = null;
				CompoundStatement prev_cstmt = null;
				// JAS
				Statement statb = null;
				}
        :       lcur:LCURLY^ {linenum = lcur.getLine();}
                 {

                 	 prev_symtab = symtab;


				 prev_cstmt = curr_cstmt;
                    	stmt = new CompoundStatement();
						/*
						if(symtab instanceof CompoundStatement){

						}
						else if(symtab instanceof Procedure){

						}
						*/
                    	enterSymtab(stmt);
                    	stmt.setLineNumber(linenum);
                    	putPragma(lcur,prev_symtab);
                    	curr_cstmt = stmt;
                    	/*symtab = stmt;*/
                    }
                (       //this ambiguity is ok, declarationList and nestedFunctionDef end properly
                        options {
                            warnWhenFollowAmbig = false;
                        } :

                    ( "typedef" | "__label__" | declaration )=>
                    declarationList
                    | (nestedFunctionDef)=>
                    nestedFunctionDef // not going to handle this
		    | ( statb = statement {curr_cstmt.addStatement(statb);})
                )*
                ( statementList )?

                rcur:RCURLY
                {
                	linenum = rcur.getLine();
                   	putPragma(rcur,symtab);

                    curr_cstmt = prev_cstmt;
                    /*
                    symtab = prev_symtab;
                    */
                    exitSymtab();
                }
        ;

//Not handled now
nestedFunctionDef
                            {/* Declarator decl=null; */}
        :       ( "auto" )? //only for nested functions
                ( (functionDeclSpecifiers)=> functionDeclSpecifiers
                )?
                // "null" could cause a problem
                /*decl = */declarator
                ( declaration )*
                compoundStatement
        ;


statementList {
				Statement statb = null;
				}
        :        ( statb = statement {curr_cstmt.addStatement(statb);})+
        ;

statement	 returns [Statement statb]
		{ Expression stmtb_expr;
			statb = null;
			Expression expr1=null, expr2=null, expr3=null;
	         Statement stmt1=null,stmt2=null;
	         //int a=0;
	         int sline = 0;


		}
        :
        		/*
        		 *	NullStatement
        		 */
        		tsemi:SEMI                    // Empty statements
        		{
        			sline = tsemi.getLine();
        			statb = new NullStatement();
        			putPragma(tsemi,symtab);

        		}
        |
        		/*
        		 * CompoundStatement
        		 */
        		statb=compoundStatement      // Group of statements

        |
        		/*
        		 * ExpressionStatement
        		 */
        		stmtb_expr=expr exprsemi:SEMI!
        		{
        			sline = exprsemi.getLine();
        			putPragma(exprsemi,symtab);
        			/*
        			 *	I really shouldn't do this test
        			 */

        			statb = new ExpressionStatement(stmtb_expr);


        		}
// Iteration statements:
        |
        		/*
        		 * WhileLoop
        		 */
        	    twhile:"while"^ LPAREN!
        		{
        			sline = twhile.getLine();
        			putPragma(twhile,symtab);
        		}
        		expr1=expr RPAREN! stmt1=statement
        		{
					statb = new WhileLoop(expr1, stmt1);
					statb.setLineNumber(sline);



				}
        |
        		/*
        		 * DoLoop
        		 */
        		tdo:"do"^
        		{
        			sline = tdo.getLine();
        			putPragma(tdo,symtab);
        		}
        		stmt1=statement "while"! LPAREN!
        		expr1=expr RPAREN! SEMI!
        		{
        			statb = new DoLoop(stmt1, expr1);
					statb.setLineNumber(sline);


        		}
        |		/*
        		 * ForLoop
        		 */

        	!      tfor:"for"
        		{
        			sline = tfor.getLine();
        			putPragma(tfor,symtab);

        		}
                LPAREN ( expr1=expr )? //{if (expr1 == null) expr1 = new Expression();}
                SEMI ( expr2=expr )? //{if (expr2 == null) expr2 = new Expression();}
                SEMI ( expr3=expr )? //{if (expr3 == null) expr3 = new Expression();}
                RPAREN
                stmt1=statement
				{  	if(expr1 != null)
					statb = new ForLoop(new ExpressionStatement(expr1),expr2,expr3,stmt1);
                	else
                	statb = new ForLoop(new NullStatement(),expr2,expr3,stmt1);
                	statb.setLineNumber(sline);


        		}
// Jump statements:
        |
        		/*
        		 * GotoStatement
        		 */
        		tgoto:"goto"^
        		{
        			sline = tgoto.getLine();
        			putPragma(tgoto,symtab);
        		}
        		//expr1=expr SEMI!
        		gotoTarget:ID SEMI!
        		{
        			/*
        			BaseDeclaration target = null;
        			Object o = null;
        			o =functionSymtab.get(gotoTarget.getText());
        			if(o == null){
        				target = new BaseDeclaration(new BaseSpecifier(),null);
        				functionSymtab.put(gotoTarget.getText(),target);
        			}
        			else
        				target = (Declaration)o;

        			statb = new GotoStmt(target);
        			*/
        			statb = new GotoStatement(new Identifier(gotoTarget.getText()));

        			statb.setLineNumber(sline);


        		}

        |
        		/*
        		 * ContinueStatement
        		 */
        		tcontinue:"continue" SEMI!
        		{
        			sline = tcontinue.getLine();

        			statb = new ContinueStatement();
        			statb.setLineNumber(sline);
        			putPragma(tcontinue,symtab);

        		}

        |
        		/*
        		 *	BreakStatement
        		 */
        		tbreak:"break" SEMI!
        		{
        			sline = tbreak.getLine();

        			statb = new BreakStatement();
        			statb.setLineNumber(sline);
        			putPragma(tbreak,symtab);

        		}

        |
        		/*
        		 *	ReturnStatement
        		 */
        		treturn:"return"^
        		{
        			sline = treturn.getLine();

        		}
        		( expr1=expr )? SEMI!
        		{
        			if(expr1 != null)
        				statb=new ReturnStatement(expr1);
        			else
        				statb=new ReturnStatement();
        			statb.setLineNumber(sline);
        			putPragma(treturn,symtab);

        		}
        |
        		/*
        		 * Label
        		 */
        		lid:ID COLON!
        		{
        			sline = lid.getLine();

        		}
        		{
        			/*
				Object o = null;
        			Declaration target = null;
				*/

        			//statb = new Label(new Identifier(lid.getText()));
					statb = new Label(new Identifier(lid.getText()));
					/*
					o = functionSymtab.get(lid.getText());
					// place holder is there
					if(o != null){
						target = (Declaration)o;
						target.getSpecifier().add(statb);
					}
					else{
						Specifier spec = new Specifier();
						spec.add(statb);
						target = new Declaration(spec,null);
						functionSymtab.put(lid.getText(),target);
					}
					*/
					statb.setLineNumber(sline);
					putPragma(lid,symtab);

        		}
			// Attribute Specifier List Possible
			(attributeDecl)?
        		(options {warnWhenFollowAmbig=false;}: stmt1=statement
        		{
        			CompoundStatement cstmt = new CompoundStatement();
        			cstmt.addStatement(statb);
        			statb = cstmt;
        			cstmt.addStatement(stmt1);
        		}
        		)?

// GNU allows range expressions in case statements
        |
        		/*
        		 *	Case
        		 */
        		tcase:"case"^
        		{
        			sline = tcase.getLine();

        		}
        		((constExpr VARARGS)=>
        			expr1=rangeExpr
        			| expr1=constExpr)

        		{
        			statb = new Case(expr1);
					statb.setLineNumber(sline);
					putPragma(tcase,symtab);

        		}
        		COLON! ( options{warnWhenFollowAmbig=false;}:
        		stmt1=statement {
        			CompoundStatement cstmt = new CompoundStatement();
        			cstmt.addStatement(statb);
        			statb = cstmt;
        			cstmt.addStatement(stmt1);
        		})?

        |
        		/*
        		 * Default
        		 */
        		tdefault:"default"^
        		{
        			sline = tdefault.getLine();
        		}

        		{
        			statb = new Default();
					statb.setLineNumber(sline);
					putPragma(tdefault,symtab);

        		}
        		COLON! ( options{warnWhenFollowAmbig=false;}:
        		stmt1=statement {
        			CompoundStatement cstmt = new CompoundStatement();
        			cstmt.addStatement(statb);
        			statb = cstmt;
        			cstmt.addStatement(stmt1);
        		})?

// Selection statements:

        |       /*
         		 * IfStatement;
         		 */
        		tif:"if"^
        		{
        			sline = tif.getLine();
        			putPragma(tif,symtab);
        		}
                 LPAREN! expr1=expr RPAREN! stmt1=statement
                ( //standard if-else ambiguity
                        options {
                            warnWhenFollowAmbig = false;
                        } :
                "else" stmt2=statement )?
                 {
		 			if(stmt2 != null)
			 			statb = new IfStatement(expr1,stmt1,stmt2);
			 		else
			 			statb = new IfStatement(expr1,stmt1);
			 		statb.setLineNumber(sline);


		 		}
        |
        		/*
        		 *	SwitchStatement
        		 */
        		tswitch:"switch"^ LPAREN!
        		{
        			sline = tswitch.getLine();
        		 }
        		expr1=expr RPAREN!
        		{
        			statb = new SwitchStatement(expr1);
					statb.setLineNumber(sline);
				putPragma(tswitch,symtab);

        		}
        		stmt1=statement{
        			((SwitchStatement)statb).setBody((CompoundStatement)stmt1);
        		}
        ;






expr	returns [Expression ret_expr]
{ret_expr = null; Expression expr1=null; List<Expression> elist = new LinkedList<Expression>();
	}
        :       ret_expr=assignExpr
        		{
                           	elist.add(ret_expr);
                }
        		(options {
                                /* MBZ:
                                    COMMA is ambiguous between comma expressions and
                                    argument lists.  argExprList should get priority,
                                    and it does by being deeper in the expr rule tree
                                    and using (COMMA assignExpr)*
                                */
                                warnWhenFollowAmbig = false;
                            } :
                            /*
                             * CommaExpression is not handled now
                             */

                            COMMA^

                            expr1=assignExpr
                            {elist.add(expr1);
                            }
                            )*
                            {

                            	if(elist.size() > 1){
                            		//System.err.println("CommaExpr");
                            		ret_expr = new CommaExpression(elist);
                            	}
                            }
        ;


assignExpr returns [Expression ret_expr]
			{ ret_expr = null; Expression expr1=null;AssignmentOperator code=null;}
        :       ret_expr=conditionalExpr
        		( code = assignOperator!

        		expr1=assignExpr
        		{ret_expr = new AssignmentExpression(ret_expr,code,expr1); }
        		)?
        ;

assignOperator returns [AssignmentOperator code] {code = null;}
        :       ASSIGN 				{code = AssignmentOperator.NORMAL;}
        |       DIV_ASSIGN          {code = AssignmentOperator.DIVIDE;}
        |       PLUS_ASSIGN         {code = AssignmentOperator.ADD;}
        |       MINUS_ASSIGN        {code = AssignmentOperator.SUBTRACT;}
        |       STAR_ASSIGN         {code = AssignmentOperator.MULTIPLY;}
        |       MOD_ASSIGN          {code = AssignmentOperator.MODULUS;}
        |       RSHIFT_ASSIGN       {code = AssignmentOperator.SHIFT_RIGHT;}
        |       LSHIFT_ASSIGN       {code = AssignmentOperator.SHIFT_LEFT;}
        |       BAND_ASSIGN         {code = AssignmentOperator.BITWISE_AND;}
        |       BOR_ASSIGN          {code = AssignmentOperator.BITWISE_INCLUSIVE_OR;}
        |       BXOR_ASSIGN         {code = AssignmentOperator.BITWISE_EXCLUSIVE_OR;}
        ;

constExpr returns [Expression ret_expr] {ret_expr = null;}
        :       ret_expr=conditionalExpr
        ;

logicalOrExpr	 returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				//BinaryOperator code = null;
			}
        :       ret_expr=logicalAndExpr
        		( LOR^ expr1=logicalAndExpr
        		{ret_expr = new BinaryExpression(ret_expr,BinaryOperator.LOGICAL_OR,expr1);}
        		)*
        ;


logicalAndExpr	 returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				//BinaryOperator code = null;
			}
        :       ret_expr=inclusiveOrExpr
        		( LAND^ expr1=inclusiveOrExpr
        		{ret_expr = new BinaryExpression(ret_expr,BinaryOperator.LOGICAL_AND,expr1);}
        		)*
        ;

inclusiveOrExpr	 returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				//BinaryOperator code = null;
			}
        :       ret_expr=exclusiveOrExpr
        		( BOR^  expr1=exclusiveOrExpr
        		{ret_expr = new BinaryExpression(ret_expr,BinaryOperator.BITWISE_INCLUSIVE_OR,expr1);}
        		)*
        ;


exclusiveOrExpr	 returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				//BinaryOperator code = null;
			}
        :       ret_expr=bitAndExpr
        		( BXOR^  expr1=bitAndExpr
        		{ret_expr = new BinaryExpression(ret_expr,BinaryOperator.BITWISE_EXCLUSIVE_OR,expr1);}
        		)*
        ;


bitAndExpr	 returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				//BinaryOperator code = null;
			}
        :       ret_expr=equalityExpr
        		( BAND^
        		expr1=equalityExpr
        		{ret_expr = new BinaryExpression(ret_expr,BinaryOperator.BITWISE_AND,expr1);}
        		)*
        ;



equalityExpr	 returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				BinaryOperator code = null;
			}
        :       ret_expr=relationalExpr
                ( ( EQUAL^ {code = BinaryOperator.COMPARE_EQ;}
                | NOT_EQUAL^ {code = BinaryOperator.COMPARE_NE;})

                expr1=relationalExpr
                {ret_expr = new BinaryExpression(ret_expr,code,expr1);}
                )*
        ;


relationalExpr	 returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				BinaryOperator code = null;
			}
        :       ret_expr=shiftExpr
                ( ( LT^ {code = BinaryOperator.COMPARE_LT;}
                | LTE^ {code = BinaryOperator.COMPARE_LE;}
                | GT^ {code = BinaryOperator.COMPARE_GT;}
                | GTE^ {code = BinaryOperator.COMPARE_GE;})

                expr1=shiftExpr
                {ret_expr = new BinaryExpression(ret_expr,code,expr1);}
                )*
        ;



shiftExpr returns  [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				BinaryOperator code = null;
			}
        :       ret_expr=additiveExpr
                ( ( LSHIFT^ {code = BinaryOperator.SHIFT_LEFT;}
                | RSHIFT^ {code = BinaryOperator.SHIFT_RIGHT;})

                expr1=additiveExpr
                {ret_expr = new BinaryExpression(ret_expr,code,expr1);}
                )*
        ;


additiveExpr returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				BinaryOperator code = null;
			}
        :       ret_expr=multExpr
                ( ( PLUS^ {code = BinaryOperator.ADD;}
                | MINUS^ {code=BinaryOperator.SUBTRACT;})

                expr1=multExpr
                {ret_expr = new BinaryExpression(ret_expr,code,expr1);}
                )*
        ;


multExpr	returns [Expression ret_expr]{
				Expression expr1; ret_expr=null;
				BinaryOperator code = null;
			}
        :       ret_expr=castExpr
                ( ( STAR^ {code = BinaryOperator.MULTIPLY;}
                | DIV^ {code=BinaryOperator.DIVIDE;}
                | MOD^ {code=BinaryOperator.MODULUS;})

                expr1=castExpr
                 {ret_expr = new BinaryExpression(ret_expr,code,expr1);}
                )*
        ;




typeName	returns [List tname]
		{
			tname = null;
			//Declarator decl= new Declarator();
			Declarator decl = null;
		}
        :       tname = specifierQualifierList
        		/*
        		 *	Need to add this part
        		 */
        		(decl = nonemptyAbstractDeclarator {tname.add(decl);})?
        ;


postfixExpr  returns [Expression ret_expr]
				{
					ret_expr=null;
					Expression expr1=null;
				}
        :       expr1=primaryExpr
        		{ret_expr = expr1;}
                (
                ret_expr=postfixSuffix[expr1]
                )?
        ;
postfixSuffix [Expression expr1] returns [Expression ret_expr]
        		{
        			Expression expr2=null;
        			//boolean builtin=false;
        			//SymbolTable saveSymtab = null;
        			//String s;
					ret_expr = expr1;
					List<Expression> args = null;
					List<Expression> kernelargs = null;
				}
        :
                (
                /*
                 * POINTER_ACCESS
                 *
                 */
                PTR ptr_id:ID
                {
                	/*
                	ret_expr =
                	new BinaryExpression(ret_expr,BinaryOperator.POINTER_ACCESS,new Identifier(ptr_id.getText()));
                	*/
                	ret_expr = new AccessExpression(ret_expr,AccessOperator.POINTER_ACCESS,new Identifier(ptr_id.getText()));
                }
                |
                /*
                 * MEMBER_ACCESS
                 *
                 */
                DOT dot_id:ID
                {
                	/*
                	ret_expr =
                	new BinaryExpression(ret_expr,BinaryOperator.MEMBER_ACCESS,new Identifier(dot_id.getText()));
                	*/
                	ret_expr =
                	new AccessExpression(ret_expr,AccessOperator.MEMBER_ACCESS,new Identifier(dot_id.getText()));
                }
                /*
                 *	FunctionCall
                 */
                | (kernelargs=kernelCall)? args=functionCall
                {
                	if(args == null) {
				if(kernelargs == null) ret_expr = new FunctionCall(ret_expr);
				else ret_expr = new KernelLaunch(ret_expr,kernelargs);
                	} else {
                		if(kernelargs == null) ret_expr = new FunctionCall(ret_expr,args);
				else ret_expr = new KernelLaunch(ret_expr,kernelargs,args);
			}
                }
                /*
                 * ArrayAcess
                 * Need a fix for multi-dimension access
                 */
                | LBRACKET expr2=expr RBRACKET
                {
                	if(ret_expr instanceof ArrayAccess){
                		ArrayAccess aacc = (ArrayAccess)ret_expr;
                		int dim = aacc.getNumIndices();
                		int n = 0;
                		LinkedList<Expression> alist = new LinkedList<Expression>();
                		for(n = 0;n < dim; n++){

                			alist.add(aacc.getIndex(n));
						}
						alist.add(expr2);
                		aacc.setIndices(alist);

                	}
                	else
						ret_expr = new ArrayAccess(ret_expr,expr2);
				}
                | INC {ret_expr = new UnaryExpression(UnaryOperator.POST_INCREMENT,ret_expr);}
                | DEC {ret_expr = new UnaryExpression(UnaryOperator.POST_DECREMENT,ret_expr);}
                 /*
                 |
                LPAREN^ expr2=assignExpr COMMA parameterDeclaration[null] RPAREN
                {
                	ExprList eList=new ExprList();
               	eList.add(expr2);
                	ret_expr = new FuncExpr(ret_expr,eList);
                	ret_expr.print();
                	}*/
                )+
        ;

/**
 * John A. Stratton: October 2009
 * Adding parsing support for CUDA kernel launches.
 */
kernelCall returns [List<Expression> kargs] 
	{
		kargs = null;
	}
	:
		LKERNEL_LAUNCH^ (kargs=argExprList)? RKERNEL_LAUNCH
	;

functionCall	returns [List<Expression> args] {
					args=null;
				}
        :
                LPAREN^  (args=argExprList)? RPAREN
        ;


conditionalExpr returns [Expression ret_expr]
				{ ret_expr=null;
				Expression expr1=null,expr2=null,expr3=null;}
        :       expr1=logicalOrExpr {ret_expr = expr1;}
                ( QUESTION^ (expr2=expr)? COLON expr3=conditionalExpr
				{	//if(expr2 == null) expr2 = new Expression();
					ret_expr = new ConditionalExpression(expr1,expr2,expr3);}
				)?
        ;

rangeExpr  returns [Expression ret_expr] //used in initializers only
			{ret_expr = null;}
        :  constExpr VARARGS constExpr
        ;

castExpr	returns [Expression ret_expr]
				{
					ret_expr = null;
					Expression expr1=null;
					List<Specifier> tname=null;
				}
        :       ( LPAREN typeName RPAREN )=>
                LPAREN^ tname=typeName RPAREN
                ( expr1=castExpr
                	{
                		//System.err.println("Typecast");
                		ret_expr = new Typecast(tname,expr1);
                	}
                | lcurlyInitializer // What is this ?
                )
        |       ret_expr=unaryExpr
        ;

/*
 *	This causing problems with type casting
 */
nonemptyAbstractDeclarator returns [Declarator adecl]
		{
			Expression expr1=null;
			List<Declaration> plist=null;
			List<Specifier> bp = null;

			Declarator tdecl = null;


				Specifier aspec = null;
				boolean isArraySpec = false;
				//boolean isNested = false;
				List<Expression> llist = new LinkedList<Expression>();
				List<Specifier> tlist = null;
				boolean empty = true;
			adecl = null;
		}
        :   (

                bp = pointerGroup
                (
                	(LPAREN
                    (

                    	(
                    	// ( )
                    	(
                    	tdecl = nonemptyAbstractDeclarator
                        )
                        |
                        // function proto
                        plist=parameterTypeList
                       ) {empty = false;}

                    )?

                    ( COMMA! )?
                    RPAREN)
                    {

                     if(empty)
                    	plist = new LinkedList<Declaration>();
                    empty = true;
                    }
                | (LBRACKET (expr1=expr)? RBRACKET)
                	{
                		isArraySpec = true;

                			llist.add(expr1);

                	}
                )*
            |   (   (LPAREN
             	    (
                    (
                    	// ( )
                    	(
                    	tdecl = nonemptyAbstractDeclarator
                    	)
                        |
                        // function proto
                        plist=parameterTypeList

                    ) {empty = false;}
                    )?
                    ( COMMA! )?
                    RPAREN)
                     {

                     if(empty)
                    	plist = new LinkedList<Declaration>();
                    empty = true;
                    }
                | (LBRACKET (expr1=expr)? RBRACKET)
                {
                		isArraySpec = true;

                			llist.add(expr1);

                	}
                )+
            )
            {
            	// this is wrong
            	/*
            	if(tdecl == null){
					adecl = new Declarator(bp, new Identifier(""), plist, tlist,null) ;
				}
            	else
            		adecl = new Declarator(bp, tdecl, plist) ;

            		*/
            		if(isArraySpec){
							/*
							 * []+
							 */
							aspec = new ArraySpecifier(llist);
							//aspec = new ArraySpecifier();
							tlist = new LinkedList<Specifier>();
							tlist.add(aspec);
					}
            		{ Identifier idex = null;

            			// nested declarator (tlist == null ?)

            			if(bp == null)
            				bp = new LinkedList<Specifier>();
						if(tdecl != null) // assume tlist == null
						{
							//assert tlist == null : "Assertion (tlist == null) failed 2";
							if(tlist == null)
            						tlist = new LinkedList<Specifier>();
							//if(plist != null){
								adecl = new NestedDeclarator(bp,tdecl,plist,tlist);
							//}
							//else
							//	decl = new NestedDeclarator(bp,tdecl,new LinkedList(),tlist);
						}
						else{
							idex = new Identifier("");
							if(plist != null) // assume tlist == null
            						adecl = new ProcedureDeclarator(bp,idex,plist);
            				else{
            					if(tlist != null)
            						adecl = new VariableDeclarator(bp,idex,tlist);
            					else
            						adecl = new VariableDeclarator(bp,idex);
            				}
						}
            		}

            }
        ;

unaryExpr returns [Expression ret_expr]
				{
					Expression expr1=null;
					UnaryOperator code;
					ret_expr = null;
					List<Specifier> tname = null;
				}
        :       ret_expr=postfixExpr
        |       INC^ expr1=castExpr
        		{ret_expr = new UnaryExpression(UnaryOperator.PRE_INCREMENT, expr1);}
        |       DEC^ expr1=castExpr
        		{ret_expr = new UnaryExpression(UnaryOperator.PRE_DECREMENT, expr1);}
        |       code=unaryOperator expr1=castExpr
				{
					ret_expr = new UnaryExpression(code, expr1);
				}
       	/*
       	 *	sizeof is not handled
       	 */
        |       "sizeof"^
                ( ( LPAREN typeName )=>
                LPAREN tname=typeName RPAREN
                 {ret_expr = new SizeofExpression(tname);}
                | expr1=unaryExpr
                {ret_expr = new SizeofExpression(expr1);}
                )
                /*
                {
                	ByteArrayOutputStream bs = new ByteArrayOutputStream();
                	if(tname != null){

                	Tools.printList(tname,bs);
                	ret_expr = new Identifier("sizeof("+bs.toString() +")");
                	}
                	else {
                		expr1.print(bs);
                		ret_expr = new Identifier("sizeof "+bs.toString());
                	}

                }
                */
        |        // Handles __alignof__ operator
        		"__alignof__"^
                ( ( LPAREN typeName )=>
                	LPAREN tname=typeName RPAREN
                 	{ret_expr = new AlignofExpression(tname); }
                | expr1=unaryExpr
                	{ret_expr = new AlignofExpression(expr1); }
                )
	|	// Handles the builtin GCC function __builtin_va_arg
		// as an intrinsic function (operator)
		"__builtin_va_arg"
		( ( LPAREN
		  ( expr1 = unaryExpr )
		    COMMA
		  ( tname = typeName )
		    RPAREN )
		  	{ret_expr = new VaArgExpression(expr1, tname);}
		)
	|	// Handles the builtin GCC function __builtin_offsetof
		// as an intrinsic function (operator)
		"__builtin_offsetof"
		(
		( LPAREN
		( tname = typeName )
		  COMMA
		( expr1 = unaryExpr )
		  RPAREN )
			{ret_expr = new OffsetofExpression(tname, expr1);}
		)
        |       gnuAsmExpr {ret_expr = new Identifier("asm");}

        ;

unaryOperator returns [UnaryOperator code] {code = null;}
        :       BAND {code = UnaryOperator.ADDRESS_OF;}
        |       STAR {code = UnaryOperator.DEREFERENCE;}
        |       PLUS	{code = UnaryOperator.PLUS;}
        |       MINUS	{code = UnaryOperator.MINUS;}
        |       BNOT	{code = UnaryOperator.BITWISE_COMPLEMENT;}
        |       LNOT	{code = UnaryOperator.LOGICAL_NEGATION;}
//      |       LAND	{code = LAND;}
        |       "__real"	{code = null;}
        |       "__imag"	{code = null;}
        ;

gnuAsmExpr
        :       "__asm"^ ("volatile")?
                LPAREN stringConst
                ( options { warnWhenFollowAmbig = false; }:
                  COLON (strOptExprPair ( COMMA strOptExprPair)* )?
                  ( options { warnWhenFollowAmbig = false; }:
                    COLON (strOptExprPair ( COMMA strOptExprPair)* )?
                  )?
                )?
                ( COLON stringConst ( COMMA stringConst)* )?
                RPAREN
                               // { ##.setType(NGnuAsmExpr); }
        ;

//GCC requires the PARENs
strOptExprPair
        :  stringConst ( LPAREN expr RPAREN )?
        ;


primaryExpr returns [Expression p] {
		Expression expr1=null;
		CompoundStatement cstmt = null;
		p=null;
		String name = null;
		//TNode temp;
		}
        :
        		/*
        		 *	Identifier
        		 */
        		 prim_id:ID
        		{
        			name = prim_id.getText();
					//Declaration d = Tools.findSymbol(curr_cstmt,new Identifier(name));
 	       			/*
 	       			if(d == null)
						System.err.println("Warning unregistered symbol: "+name);
					*/
					p=new Identifier(name);
        		}
        |       /*
        		 * Need to handle these correctly
        		 */
        		prim_num:Number {
        		 	name = prim_num.getText();
        		 	boolean handled = false;
        		 	//int i = 0;
        		 	//int radix = 10;
        		 	double d = 0;
        		 	//Integer i2 = null;
        		 	//Long in = null;
				
				//JAS: July 2008
				//Having issues with preserving the signed/unsigned 
				// properties of immediates.  Current IR printing 
				// assumes all numbers are signed, and we need input from 
				// the parser to correct that at all.  
				// While we're at it, we may as well preserve the 
				// input format for easier correlation.
				
        		 	name = name.toUpperCase();
        		 		name = name.replaceAll("L","");
        		 		name = name.replaceAll("U","");
        		 	 	//name= name.replaceAll("I"," ");
        		 	if(name.startsWith("0X") == false){
        		 		name.replaceAll("F","");

        		 	}
        		  	try{

        		 		/*i2 = */Integer.decode(name);
					//JAS, need to use the actual string here
        		 		p=new IntegerLiteral(name);
        		 		// p=new IntegerLiteral(i2.intValue());
        		 		handled = true;
        		 	}catch(NumberFormatException e){
        		 		;
        		 	}
        		 	if(handled == false)
        		 	try{


        		 		Long.decode(name);
        		 		//p=new IntegerLiteral(in.intValue());
					//JAS, again, want the output format to match
        		 		p=new IntegerLiteral(name);
        		 		// p=new IntegerLiteral(in.longValue());
        		 		handled = true;
        		 	}
        		 	catch(NumberFormatException e){
        		 		;

        		 	}
        		 	if(handled == false)
        		 	try{d = Double.parseDouble(name);
					// JAS
        		 		// p=new FloatLiteral(d);
				  if(name.lastIndexOf("F") != -1) {
				    p = new FloatLiteral(d, true);
				  } else {
				    p = new FloatLiteral(d, false);
        		          }
        		 		handled = true;
        		 	}catch(NumberFormatException e){

        		 		p=new Identifier(name);

        		 		Tools.printlnStatus("Strange number "+name,0);
        		 		//System.exit(1);
        		 	}

        		}
        |       name=charConst {
        			//Scanner scan = new Scanner(name);
        			//Tools.printlnStatus("CharLiteral "+name.charAt(1)+" "+name.length(),0);
        			if(name.length()==3)
        				p = new CharLiteral(name.charAt(1));
        			// escape sequence is not handled at this point
        			else{
/*
        				char c = name.charAt(2);
        				switch(c){
        					case 'a':
        					p =new CharLiteral('\7');
        					break;
        					case 'b':
        					p =new CharLiteral('\b');
        					break;
        					case 'f':
        					p =new CharLiteral('\f');
        					break;
        					case 'n':
        					p =new CharLiteral('\n');
        					break;
        					case 'r':
        					p =new CharLiteral('\r');
        					break;
        					case 't':
        					p =new CharLiteral('\t');
        					break;
        					case 'v':
        					p =new CharLiteral('\14');
        					break;
        					case '\\':
        					p =new CharLiteral('\\');
        					break;
        					case '?':
        					p =new CharLiteral('\77');
        					break;
        					case '\'':
        					p =new CharLiteral('\'');
        					break;
        					case '\"':
        					p =new CharLiteral('\"');
        					break;
        					case 'x':
        						c = (char)Integer.parseInt(name.substring(3,name.length()-1),16);
        						p = new CharLiteral(c);
        					break;
        					default:
        						if(c <= '7' && c >= '0'){
        							c = (char)Integer.parseInt(name.substring(2,name.length()-1),8);
        					 		p = new CharLiteral(c);

        						}
        						else{

        							Tools.printlnStatus("Unrecognized Escape Sequence "+name,0);
        							p = new Identifier(name);
        						}
        					break;
        				}
*/        				p = new EscapeLiteral(name);
        			}


        		}
        |       /*
        		 * StringLiteral
        		 */
        		name=stringConst {
        			//name = name.replaceAll("\"","");
        			p=new StringLiteral(name);
        			((StringLiteral)p).stripQuotes();
        		}
// JTC:
// ID should catch the enumerator
// leaving it in gives ambiguous err
//      | enumerator
        |       /*
        		 *	Compound statement Expression
        		 */
        		(LPAREN LCURLY) =>
        		LPAREN^
        		cstmt = compoundStatement
        		RPAREN
        		//{ p = new CompoundExpr(cstmt); }
        		//{p = new StringLiteral("CompoundStatement Expression");}
			{
				Tools.printlnStatus("[DEBUG] Warning: CompoundStatement Expression !",0);
				/*
				ByteArrayOutputStream bs = new ByteArrayOutputStream();
				cstmt.print(bs);
				p = new StringLiteral(bs.toString());
				*/
				p = new StatementExpression(cstmt);
			}
        |       /*
        		 *	Paren
        		 */
        		LPAREN^ expr1=expr RPAREN
        		{
					p=expr1;
				}
        ;
/*
 * Type of list is unclear
 */
argExprList  returns [List eList]
			{
				Expression expr1 = null;
				eList=new LinkedList();
				Declaration pdecl = null;
			}
        :       expr1=assignExpr {eList.add(expr1);}
        		( COMMA!
        		(
        		 expr1=assignExpr {eList.add(expr1);}
        		 |
        		 pdecl=parameterDeclaration
        		 {

        		 	eList.add(/*new StringLiteral(pdecl.toString())*/pdecl);
        		 }
        		)
        		)*
        ;

protected
charConst	returns [String name] { name = null;}
        :       cl:CharLiteral	{name=cl.getText();}
        ;


protected
stringConst	returns [String name] { name = "";}
        :       (sl:StringLiteral	{name += sl.getText();})+                //{ ## = #(#[NStringSeq], ##); }
        ;


protected
intConst
        :       IntOctalConst
        |       LongOctalConst
        |       UnsignedOctalConst
        |       IntIntConst
        |       LongIntConst
        |       UnsignedIntConst
        |       IntHexConst
        |       LongHexConst
        |       UnsignedHexConst
        ;


protected
floatConst
        :       FloatDoubleConst
        |       DoubleDoubleConst
        |       LongDoubleConst
        ;

dummy
        :       NTypedefName
        |       NInitDecl
        |       NDeclarator
        |       NStructDeclarator
        |       NDeclaration
        |       NCast
        |       NPointerGroup
        |       NExpressionGroup
        |       NFunctionCallArgs
        |       NNonemptyAbstractDeclarator
        |       NInitializer
        |       NStatementExpr
        |       NEmptyExpression
        |       NParameterTypeList
        |       NFunctionDef
        |       NCompoundStatement
        |       NParameterDeclaration
        |       NCommaExpr
        |       NUnaryExpr
        |       NLabel
        |       NPostfixExpr
        |       NRangeExpr
        |       NStringSeq
        |       NInitializerElementLabel
        |       NLcurlyInitializer
        |       NAsmAttribute
        |       NGnuAsmExpr
        |       NTypeMissing
        ;





{
        import java.io.*;
        import antlr.*;
}

class NewCLexer extends Lexer;

options
        {
        k = 3;
        exportVocab = NEWC;
        testLiterals = false;
        }
tokens {
        LITERAL___extension__ = "__extension__";
}

{
	public void initialize(String src)
  {
    setOriginalSource(src);
    initialize();
  }

  public void initialize()
  {
    literals.put(new ANTLRHashString("__alignof__", this), new Integer(LITERAL___alignof__));
    literals.put(new ANTLRHashString("__ALIGNOF__", this), new Integer(LITERAL___alignof__));
    literals.put(new ANTLRHashString("__asm", this), new Integer(LITERAL___asm));
    literals.put(new ANTLRHashString("__asm__", this), new Integer(LITERAL___asm));
    literals.put(new ANTLRHashString("__attribute__", this), new Integer(LITERAL___attribute));
    // JAS added line to handle gcc-specific stuff
    literals.put(new ANTLRHashString("__attribute", this), new Integer(LITERAL___attribute));

    literals.put(new ANTLRHashString("__complex__", this), new Integer(LITERAL___complex));
    literals.put(new ANTLRHashString("__const", this), new Integer(LITERAL_const));
    literals.put(new ANTLRHashString("__const__", this), new Integer(LITERAL_const));
    literals.put(new ANTLRHashString("__imag__", this), new Integer(LITERAL___imag));
    literals.put(new ANTLRHashString("__inline", this), new Integer(LITERAL_inline));
    literals.put(new ANTLRHashString("__inline__", this), new Integer(LITERAL_inline));
    literals.put(new ANTLRHashString("__real__", this), new Integer(LITERAL___real));
    literals.put(new ANTLRHashString("__restrict", this), new Integer(LITERAL___extension__));
 	literals.put(new ANTLRHashString("__signed", this), new Integer(LITERAL_signed));
    literals.put(new ANTLRHashString("__signed__", this), new Integer(LITERAL_signed));
    literals.put(new ANTLRHashString("__typeof", this), new Integer(LITERAL_typeof));
    literals.put(new ANTLRHashString("__typeof__", this), new Integer(LITERAL_typeof));
    literals.put(new ANTLRHashString("__volatile", this), new Integer(LITERAL_volatile));
    literals.put(new ANTLRHashString("__volatile__", this), new Integer(LITERAL_volatile));
    // GCC Builtin function
    literals.put(new ANTLRHashString("__builtin_va_arg", this), new Integer(LITERAL___builtin_va_arg));
    literals.put(new ANTLRHashString("__builtin_offsetof", this), new Integer(LITERAL___builtin_offsetof));
	// MinGW specific
	literals.put(new ANTLRHashString("__MINGW_IMPORT", this), new Integer(LITERAL___extension__));
	literals.put(new ANTLRHashString("_CRTIMP", this), new Integer(LITERAL___extension__));
	// Microsoft specific
	literals.put(new ANTLRHashString("__cdecl", this), new Integer(LITERAL___extension__));
	literals.put(new ANTLRHashString("__w64", this), new Integer(LITERAL___extension__));
	literals.put(new ANTLRHashString("__int64", this), new Integer(LITERAL_int));
	literals.put(new ANTLRHashString("__int32", this), new Integer(LITERAL_int));
	literals.put(new ANTLRHashString("__int16", this), new Integer(LITERAL_int));
	literals.put(new ANTLRHashString("__int8", this), new Integer(LITERAL_int));
  }
  LineObject lineObject = new LineObject();
  String originalSource = "";
  PreprocessorInfoChannel preprocessorInfoChannel = new PreprocessorInfoChannel();
  int tokenNumber = 0;
  boolean countingTokens = true;
  int deferredLineCount = 0;
  int extraLineCount = 1;
  NewCParser parser = null;
  public void setCountingTokens(boolean ct)
  {
    countingTokens = ct;
    if ( countingTokens ) {
      tokenNumber = 0;
    }
    else {
      tokenNumber = 1;
    }
  }

	public void setParser(NewCParser p){
		parser = p;
	}
 /*
  public void startHeader(String s){
  	//System.out.println(s);
  	parser.startHeader(s);
  }
  public void endHeader(){
  	parser.endHeader();
  }*/
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
  /*
  	// handle special pragma cases
  	if(pre.startsWith("#pragma startinclude")){

  		System.out.println("Found "+pre);

  	}
  	else if(pre.startsWith("#pragma endinclude")){
  		System.out.println("Found "+pre);
    }
    else{
    */
    	//System.out.println("Found "+pre);
    	//preprocessorInfoChannel.addLineForTokenNumber( new Pragma(pre,t), new Integer(lineObject.line) );
    	preprocessorInfoChannel.addLineForTokenNumber( new Pragma(pre,t), new Integer(tokenNumber) );
    /*}*/
  }

  protected Token makeToken(int t)
  {
    if ( t != Token.SKIP && countingTokens) {
        tokenNumber++;
    }
    CToken tok = (CToken) super.makeToken(t);
    tok.setLine(lineObject.line);
    tok.setSource(lineObject.source);
    tok.setTokenNumber(tokenNumber);

    lineObject.line += deferredLineCount;
    deferredLineCount = 0;
    return tok;
  }

    public void deferredNewline() {
        deferredLineCount++;
    }

    public void newline() {
        lineObject.newline();
        setColumn(1);
    }





}

protected
Vocabulary
        :       '\3'..'\377'
        ;

/* Operators: */

ASSIGN          : '=' ;
COLON           : ':' ;
COMMA           : ',' ;
QUESTION        : '?' ;
SEMI            : ';' ;
PTR             : "->" ;


// DOT & VARARGS are commented out since they are generated as part of
// the Number rule below due to some bizarre lexical ambiguity shme.

// DOT  :       '.' ;
protected
DOT:;

// VARARGS      : "..." ;
protected
VARARGS:;


LPAREN          : '(' ;
RPAREN          : ')' ;
LBRACKET        : '[' ;
RBRACKET        : ']' ;
LCURLY          : '{' ;
RCURLY          : '}' ;

EQUAL           : "==" ;
NOT_EQUAL       : "!=" ;
LTE             : "<=" ;
LT              : "<" ;
GTE             : ">=" ;
GT              : ">" ;

DIV             : '/' ;
DIV_ASSIGN      : "/=" ;
PLUS            : '+' ;
PLUS_ASSIGN     : "+=" ;
INC             : "++" ;
MINUS           : '-' ;
MINUS_ASSIGN    : "-=" ;
DEC             : "--" ;
STAR            : '*' ;
STAR_ASSIGN     : "*=" ;
MOD             : '%' ;
MOD_ASSIGN      : "%=" ;
RSHIFT          : ">>" ;
RSHIFT_ASSIGN   : ">>=" ;
LSHIFT          : "<<" ;
LSHIFT_ASSIGN   : "<<=" ;

/**
 * John A. Stratton: February 2008
 * Added support for CUDA kernel invocation semantics
 */
LKERNEL_LAUNCH  : "<<<" ;
RKERNEL_LAUNCH  : ">>>" ;


LAND            : "&&" ;
LNOT            : '!' ;
LOR             : "||" ;

BAND            : '&' ;
BAND_ASSIGN     : "&=" ;
BNOT            : '~' ;
BOR             : '|' ;
BOR_ASSIGN      : "|=" ;
BXOR            : '^' ;
BXOR_ASSIGN     : "^=" ;


Whitespace
        :       ( ( ' ' | '\t' | '\014')
                | "\r\n"                { newline(); }
                | ( '\n' | '\r' )       { newline();    }
                )                       { _ttype = Token.SKIP;  }
        ;


Comment
        :       ("/*"
                ( { LA(2) != '/' }? '*'
                | "\r\n"                { deferredNewline(); }
                | ( '\r' | '\n' )       { deferredNewline();    }
                | ~( '*'| '\r' | '\n' )
                )*
                "*/"
                {setPreprocessingDirective(getText(),Pragma.comment);}
                )                    {

	                						 _ttype = Token.SKIP;
                                        }
        ;


CPPComment
        :
                ("//" ( ~('\n') )* {setPreprocessingDirective(getText(),Pragma.comment);})
                        {

                        _ttype = Token.SKIP;
                        }
        ;

PREPROC_DIRECTIVE
options {
  paraphrase = "a line directive";
}

        :
        '#'
        (
        	( "line" || ((Space)+ Digit)) => LineDirective {_ttype = Token.SKIP; }
			|
			( "pragma"
				(
					( ~('\n'))* { setPreprocessingDirective(getText(),Pragma.pragma);_ttype = Token.SKIP; }
					| (Space)+ "startinclude" ( ~('\n'))*
					// {startHeader(getText());}
					| (Space)+ "endinclude" ( ~('\n'))* {extraLineCount +=2; lineObject.setLine(lineObject.getLine() - 2);}
					// {endHeader();}
				)
			)
			| ( ~('\n'))* {_ttype = Token.SKIP; }
		)
		/*

                {
                    _ttype = Token.SKIP;
                }
        */
        ;

protected  Space:
        ( ' ' | '\t' | '\014')
        ;

protected LineDirective
{
        boolean oldCountingTokens = countingTokens;
        countingTokens = false;
}
:
                {
                        lineObject = new LineObject();
                        deferredLineCount = 0;
                }
        ("line")?  //this would be for if the directive started "#line", but not there for GNU directives
        (Space)+
        n:Number { lineObject.setLine(Integer.parseInt(n.getText()) - extraLineCount); }
        (
        (Space)+
        (       fn:StringLiteral {  try {
                                          lineObject.setSource(fn.getText().substring(1,fn.getText().length()-1));
                                    }
                                    catch (StringIndexOutOfBoundsException e) { /*not possible*/ }
                                 }
                | fi:ID { lineObject.setSource(fi.getText()); }
        )?
        (Space)*
        ("1"            { lineObject.setEnteringFile(true); } )?
        (Space)*
        ("2"            { lineObject.setReturningToFile(true); } )?
        (Space)*
        ("3"            { lineObject.setSystemHeader(true); } )?
        (Space)*
        ("4"            { lineObject.setTreatAsC(true); } )?
        (~('\r' | '\n'))*
        //("\r\n" | "\r" | "\n")
        )?
                {
                        //preprocessorInfoChannel.addLineForTokenNumber(new LineObject(lineObject), new Integer(tokenNumber));
                        countingTokens = oldCountingTokens;
                }
        ;



/* Literals: */

/*
 * Note that we do NOT handle tri-graphs nor multi-byte sequences.
 */


/*
 * Note that we can't have empty character constants (even though we
 * can have empty strings :-).
 */
CharLiteral
        :       '\'' ( Escape | ~( '\'' ) ) '\''
        ;


protected BadStringLiteral
        :       // Imaginary token.
        ;


protected
Escape
        :       '\\'
                ( options{warnWhenFollowAmbig=false;}:
                  ~('0'..'7' | 'x')
                | ('0'..'3') ( options{warnWhenFollowAmbig=false;}: Digit )*
                | ('4'..'7') ( options{warnWhenFollowAmbig=false;}: Digit )*
                | 'x' ( options{warnWhenFollowAmbig=false;}: Digit | 'a'..'f' | 'A'..'F' )+
                )
        ;


/* Numeric Constants: */
protected IntSuffix
        :   'L'
            | 'l'
            | 'U'
            | 'u'
            | 'I'
            | 'i'
            | 'J'
            | 'j'
        ;
protected NumberSuffix
        :
            IntSuffix
            | 'F'
            | 'f'
        ;
protected
Digit
        :       '0'..'9'


        ;

protected
Exponent
        :       ( 'e' | 'E' ) ( '+' | '-' )? ( Digit )+
        ;


Number
        :       ( ( Digit )+ ( '.' | 'e' | 'E' ) )=> ( Digit )+
                ( '.' ( Digit )* ( Exponent )?
                | Exponent
                )
                ( NumberSuffix
                )*

        |       ( "..." )=> "..."       { _ttype = VARARGS;     }

        |       '.'                     { _ttype = DOT; }
                ( ( Digit )+ ( Exponent )?
                                        { _ttype = Number;   }
                    ( NumberSuffix
                    )*
                )?

        |       '0' ( '0'..'7' )*
                ( NumberSuffix
                )*

        |       '1'..'9' ( Digit )*
                ( NumberSuffix
                )*

        |       '0' ( 'x' | 'X' ) ( 'a'..'f' | 'A'..'F' | Digit )+
                ( IntSuffix
                )*
        ;

IDMEAT
        :
                i:ID                {

                                        if ( i.getType() == LITERAL___extension__ ) {
                                                $setType(Token.SKIP);
                                        }
                                        else {
                                                $setType(i.getType());
                                        }

                                    }
        ;

protected ID
        options
                {
                testLiterals = true;
                }
        :       ( 'a'..'z' | 'A'..'Z' | '_' | '$')
                ( 'a'..'z' | 'A'..'Z' | '_' | '$' | '0'..'9' )*
        ;

        WideCharLiteral
        :
                'L' CharLiteral
                                { $setType(CharLiteral); }
        ;



WideStringLiteral
        :
                'L' StringLiteral
                                { $setType(StringLiteral); }
        ;

StringLiteral
        :
                '"'
                ( ('\\' ~('\n'))=> Escape
                | ( '\r'        { newline(); }
                  | '\n'        {
                                newline();
                                }
                  | '\\' '\n'   {
                                newline();
                                }
                  )
                | ~( '"' | '\r' | '\n' | '\\' )
                )*
                '"'
        ;

