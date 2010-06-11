/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util.extlib;

import cedp.util.UtilTree;
import cedp.util.gui.ToolTipTreeNode;
import cetus.exec.Driver;
import cetus.hir.*;
import cetus.hir.java.PackageOrImportDeclaration;
import cetus.hir.java.StringDeclaration;
import java.io.File;
import java.lang.annotation.Annotation;
import java.util.Enumeration;
import java.util.List;
import java.util.Vector;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.tree.DefaultMutableTreeNode;

/**
 *
 * @author yim
 */
public class CetusWrapper {

    public static void Run(String fileName, Vector opts, boolean beautifier)
    {
        String args[];

        if(opts == null || opts.size() == 0){
            args = new String[1];
            args[0] = fileName;
        }
        else{
            args = new String[1 + opts.size()];
            for(int i=0; i<opts.size(); i++)
                args[i] = (String)opts.get(i);

            args[opts.size()] = fileName;
        }
        //args[0] = "-fault-injector";
        //args[1] = "-error-detector";
        //args[1] = "-expand-all-header";
        //args[4] = "-verbosity";
        //args[2] = "-outdir";

        Driver cetusDriver = new Driver();
        cetusDriver.run(args);

        /* C beautifier for instrumented code */
        if(beautifier){
            AStyleWrapper.Buautifier(fileName, fileName + ".beauty");
            AStyleWrapper.Buautifier("cetus_output" + File.separator + fileName, "cetus_output" + File.separator + fileName + ".beauty");
        }
    }

    protected static String GetParseNodeType(Traversable ct)
    {
        if(ct instanceof AccessExpression) return "AccessExpression";
        if(ct instanceof AccessLevel) return "AccessLevel";
        if(ct instanceof AccessOperator) return "AccessOperator";
        if(ct instanceof AccessSymbol) return "AccessSymbol";
        if(ct instanceof AlignofExpression) return "AlignofExpression";
        if(ct instanceof Annotation) return "Annotation";
        if(ct instanceof AnnotationDeclaration) return "AnnotationDeclaration";
        if(ct instanceof AnnotationStatement) return "AnnotationStatement";
        if(ct instanceof ArrayAccess) return "ArrayAccess";
        if(ct instanceof ArraySpecifier) return "ArraySpecifier";
        if(ct instanceof AssignmentExpression) return "AssignmentExpression";
        if(ct instanceof AssignmentOperator) return "AssignmentOperator";
        if(ct instanceof BinaryExpression) return "BinaryExpression";
        if(ct instanceof BinaryOperator) return "BinaryOperator";
        if(ct instanceof BitfieldSpecifier) return "BitfieldSpecifier";
        if(ct instanceof BooleanLiteral) return "BooleanLiteral";
        if(ct instanceof BreadthFirstIterator) return "BreadthFirstIterator";
        if(ct instanceof BreakStatement) return "BreakStatement";
        if(ct instanceof Case) return "Case";
        if(ct instanceof CetusAnnotation) return "CetusAnnotation";
        if(ct instanceof ChainedList) return "ChainedList";
        if(ct instanceof CharLiteral) return "CharLiteral";
        if(ct instanceof ClassDeclaration) return "ClassDeclaration";
        if(ct instanceof ClassDeclaration.Key) return "ClassDeclaration.Key";
        if(ct instanceof CodeAnnotation) return "CodeAnnotation";
        if(ct instanceof CommaExpression) return "CommaExpression";
        if(ct instanceof CommentAnnotation) return "CommentAnnotation";
        if(ct instanceof CompoundStatement) return "CompoundStatement";
        if(ct instanceof ConditionalExpression) return "ConditionalExpression";
        if(ct instanceof ConstructorInitializer) return "ConstructorInitializer";
        if(ct instanceof ContinueStatement) return "ContinueStatement";
        //if(ct instanceof DataFlowTools) return "";
//abstract        if(ct instanceof Declaration) return "Declaration";
        if(ct instanceof DeclarationStatement) return "DeclarationStatement";
//abstract        if(ct instanceof Declarator) return "Declarator";
        if(ct instanceof Default) return "Default";
        if(ct instanceof DeleteExpression) return "DeleteExpression";
        if(ct instanceof DepthFirstIterator) return "DepthFirstIterator";
        if(ct instanceof DerefSymbol) return "DerefSymbol";
        if(ct instanceof DestructorID) return "DestructorID";
        if(ct instanceof DoLoop) return "DoLoop";
        if(ct instanceof Enumeration) return "Enumeration";
        if(ct instanceof EscapeLiteral) return "EscapeLiteral";
        if(ct instanceof ExceptionHandler) return "ExceptionHandler";
        if(ct instanceof ExceptionSpecification) return "ExceptionSpecification";
//abstract        if(ct instanceof Expression) return "Expression";
        if(ct instanceof ExpressionStatement) return "ExpressionStatement";
        if(ct instanceof FlatIterator) return "FlatIterator";
        if(ct instanceof FloatLiteral) return "FloatLiteral";
        if(ct instanceof ForLoop) return "ForLoop";
        if(ct instanceof FunctionCall) return "FunctionCall";
        if(ct instanceof GotoStatement) return "GotoStatement";
        if(ct instanceof Identifier) return "Identifier";
//abstract        if(ct instanceof IDExpression) return "IDExpression";
        if(ct instanceof IfStatement) return "IfStatement";
        if(ct instanceof InfExpression) return "InfExpression";
        if(ct instanceof Initializer) return "Initializer";
        if(ct instanceof IntegerLiteral) return "IntegerLiteral";
        if(ct instanceof IRIterator) return "IRIterator";
//        if(ct instanceof IRTools) return "";
        if(ct instanceof Label) return "Label";
        if(ct instanceof LinkageSpecification) return "LinkageSpecification";
        if(ct instanceof ListInitializer) return "ListInitializer";
        if(ct instanceof Literal) return "Literal";
        if(ct instanceof MinMaxExpression) return "MinMaxExpression";
        if(ct instanceof NameID) return "NameID";
        if(ct instanceof Namespace) return "Namespace";
        if(ct instanceof NamespaceAlias) return "NamespaceAlias";
        if(ct instanceof NestedDeclarator) return "NestedDeclarator";
        if(ct instanceof NewExpression) return "NewExpression";
        if(ct instanceof NullStatement) return "NullStatement";
        if(ct instanceof OffsetofExpression) return "OffsetofExpression";
        if(ct instanceof OmpAnnotation) return "OmpAnnotation";
        if(ct instanceof OperatorID) return "OperatorID";
        if(ct instanceof PointerSpecifier) return "PointerSpecifier";
        if(ct instanceof PostOrderIterator) return "PostOrderIterator";
        if(ct instanceof PragmaAnnotation) return "PragmaAnnotation";
        if(ct instanceof PreAnnotation) return "PreAnnotation";
//        if(ct instanceof PrintTools) return "";
        if(ct instanceof Procedure) return "Procedure";
        if(ct instanceof ProcedureDeclarator) return "ProcedureDeclarator";
        if(ct instanceof Program) return "Program";
        if(ct instanceof PseudoSymbol) return "PseudoSymbol";
        if(ct instanceof QualifiedID) return "QualifiedID";
        if(ct instanceof RangeExpression) return "RangeExpression";
        if(ct instanceof ReturnStatement) return "ReturnStatement";
        if(ct instanceof SimpleExpression) return "SimpleExpression";
        if(ct instanceof SizeofExpression) return "SizeofExpression";
        if(ct instanceof SomeExpression) return "SomeExpression";
        if(ct instanceof Specifier) return "Specifier";
        if(ct instanceof StandardLibrary) return "StandardLibrary";
        if(ct instanceof Statement) return "Statement";
        if(ct instanceof StatementExpression) return "StatementExpression";
        if(ct instanceof StringLiteral) return "StringLiteral";
        if(ct instanceof SwitchStatement) return "SwitchStatement";
        if(ct instanceof Symbolic) return "Symbolic";
//        if(ct instanceof SymbolTools) return "";
        if(ct instanceof TemplateDeclaration) return "TemplateDeclaration";
        if(ct instanceof TemplateID) return "TemplateID";
        if(ct instanceof ThrowExpression) return "ThrowExpression";
//        if(ct instanceof Tools) return "";
        if(ct instanceof TranslationUnit) return "TranslationUnit";
        if(ct instanceof Typecast) return "Typecast";
        if(ct instanceof Typecast.Cast) return "Typecast.Cast";
        if(ct instanceof TypeofSpecifier) return "TypeofSpecifier";
        if(ct instanceof UnaryExpression) return "UnaryExpression";
        if(ct instanceof UnaryOperator) return "UnaryOperator";
        if(ct instanceof UserSpecifier) return "UserSpecifier";
        if(ct instanceof UsingDeclaration) return "UsingDeclaration";
        if(ct instanceof UsingDirective) return "UsingDirective";
        if(ct instanceof VaArgExpression) return "VaArgExpression";
        if(ct instanceof ValueInitializer) return "ValueInitializer";
        if(ct instanceof VariableDeclaration) return "VariableDeclaration";
        if(ct instanceof VariableDeclarator) return "VariableDeclarator";
        if(ct instanceof WhileLoop) return "WhileLoop";
//        if(ct instanceof Exceptions) return "";
        if(ct instanceof DuplicateSymbolException) return "DuplicateSymbolException";
        if(ct instanceof NotAChildException) return "NotAChildException";
        if(ct instanceof NotAnOrphanException) return "NotAnOrphanException";
        if(ct instanceof StringDeclaration) return "StringDeclaration";
        if(ct instanceof PackageOrImportDeclaration) return "PackageOrImportDeclaration";

        return "";
    }
    
    public static String PlotNode(DefaultMutableTreeNode tnode, Traversable t)
    {
        List child = t.getChildren();

        if(child == null)
            return t.toString();

        String content = t.toString();
        for(int i=0; i<child.size(); i++){
            Traversable ct = (Traversable)child.get(i);
            
            ToolTipTreeNode cnode = new ToolTipTreeNode(GetParseNodeType(ct), "");
            tnode.add(cnode);
            String temp = PlotNode(cnode, ct);
//            content.replace(temp, "");
        }
        
        if(tnode instanceof ToolTipTreeNode){
            tnode.setUserObject((String)tnode.getUserObject() + " - " + content);
            //((ToolTipTreeNode)tnode).SetToolTipText();
        }

        return t.toString();
    }

    public static void Plot(TranslationUnit tu)
    {
        JFrame jframe = new JFrame();
        JScrollPane spanel = new JScrollPane();
        JTree jtree = new JTree();
        spanel.setViewportView(jtree);
        jtree.setScrollsOnExpand(true);
        jframe.add(spanel);
//        spanel.add(jtree);
        jframe.setSize(1000, 1000);
        jframe.show();

        UtilTree.RemoveAll(jtree);
        PlotNode((DefaultMutableTreeNode)jtree.getModel().getRoot(), tu);
        UtilTree.ExpandAll(jtree);
    }
}
