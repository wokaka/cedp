/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package vpa.interpreter;

import cedp.util.AntlrWrapper;
import cedp.util.UtilFile;
import cedp.util.UtilTree;
import cedp.util.gui.ToolTipTreeNode;
import javax.swing.JTree;
import javax.swing.tree.DefaultMutableTreeNode;
import org.antlr.runtime.ANTLRFileStream;
import org.antlr.runtime.CharStream;
import org.antlr.runtime.CommonTokenStream;
import org.antlr.runtime.tree.CommonTreeNodeStream;
import org.antlr.runtime.tree.Tree;
import vpa.parsetree.ParseTreeNode;
import vpa.parsetree.VpaParseTree;

/**
 *
 * @author Keun Soo Yim
 */
public class VpaProgram {

    protected String fname;

    public VpaProgram(String f)
    {
        fname = f;
        ParseUsingAntlr(f);
    }

    public String Tab(int cnt)
    {
        String result = "";
        for(int i=0; i<cnt; i++)
            result += "\t";
        return result;
    }

    public String SaveTreeNode(DefaultMutableTreeNode treeNode, int depth)
    {
        String result;

        
        if(treeNode.toString().equals("Commands"))
            result = Tab(depth) + "<command>\n";
        else
            result = Tab(depth) + "<item name='" + treeNode.toString() + "'>\n";

        if(treeNode instanceof ToolTipTreeNode && !((ToolTipTreeNode)treeNode).GetToolTipText().isEmpty()){
            result += ((ToolTipTreeNode)treeNode).GetToolTipText() + "\n";
        }
        
        for(int i=0; i<treeNode.getChildCount(); i++){
            DefaultMutableTreeNode cnode = (DefaultMutableTreeNode)treeNode.getChildAt(i);
            result += SaveTreeNode(cnode, depth+1);
        }

        if(treeNode.toString().equals("Commands"))
            result += Tab(depth) + "</command>\n";
        else
            result += Tab(depth) + "</item>\n";
        
        return result;
    }

    public void Save(JTree tree, String f)
    {
        if(f == null)
            f = fname;

        ParseTreeNode root = VpaParseTree.GetRoot().GetChild(0);
        DefaultMutableTreeNode treeRoot = (DefaultMutableTreeNode)tree.getModel().getRoot();
        UtilFile.Write(f, SaveTreeNode(treeRoot, 0));
    }

    protected void ParseUsingAntlr(String fname)
    {
        try{
            CharStream input = new ANTLRFileStream(fname);
            VpaLexer lexer = new VpaLexer(input);
            /*
            // This is to print Lexer output
            Token token;
            while((token = lexer.nextToken()) != Token.EOF_TOKEN) {
                System.out.println("Token: " + token.getText());
            }
            */

            /* PARSER */
            CommonTokenStream tokens = new  CommonTokenStream(lexer);
            VpaParser parser = new VpaParser(tokens);
            VpaParser.document_return root = parser.document();
            //System.out.println("tree="+((Tree)root.tree).toStringTree());

            CommonTreeNodeStream nodes = new CommonTreeNodeStream((Tree)root.tree);
            VpaTreeParser walker = new VpaTreeParser(nodes);
            walker.document();
        } catch(Exception e){
            e.printStackTrace();
        }
    }

    public void BuildCommandTreeNode(DefaultMutableTreeNode treeNode, ParseTreeNode node, int depth)
    {
//        System.out.println(" " + depth + " : " + node.type + " : " + node.name);
        for(int i=0; i<node.children.size(); i++){
            DefaultMutableTreeNode cnode = treeNode;
            cnode = (DefaultMutableTreeNode)new ToolTipTreeNode(node.GetChild(i).name, node.GetChild(i).data);
            treeNode.add(cnode);
            BuildCommandTreeNode(cnode, (ParseTreeNode)node.children.get(i), depth+1);
        }
    }

    public void BuildCommandTree(JTree tree)
    {
        UtilTree.RemoveAll(tree);

        ParseTreeNode root = VpaParseTree.GetRoot().GetChild(0);
        DefaultMutableTreeNode treeRoot = (DefaultMutableTreeNode)tree.getModel().getRoot();
        BuildCommandTreeNode(treeRoot, root, 0);

        UtilTree.ExpandAll(tree);
    }
}
