/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package vpa.interpreter;

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
    protected String script;

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

        
        if(treeNode.toString().equals("vpa"))
            result = Tab(depth) + "<vpa>\n";
        else if(treeNode.toString().equals("command"))
            result = Tab(depth) + "<command>\n";
        else if(treeNode.toString().equals("script"))
            result = Tab(depth) + "<script>\n";
        else
            result = Tab(depth) + "<item name='" + treeNode.toString() + "'>\n";

        if(treeNode instanceof ToolTipTreeNode && !((ToolTipTreeNode)treeNode).GetToolTipText().isEmpty()){
            result += ((ToolTipTreeNode)treeNode).GetToolTipText() + "\n";
        }
        
        for(int i=0; i<treeNode.getChildCount(); i++){
            DefaultMutableTreeNode cnode = (DefaultMutableTreeNode)treeNode.getChildAt(i);
            result += SaveTreeNode(cnode, depth+1);
        }

        if(treeNode.toString().equals("vpa"))
            result += Tab(depth) + "</vpa>\n";
        else if(treeNode.toString().equals("command"))
            result += Tab(depth) + "</command>\n";
        else if(treeNode.toString().equals("script"))
            result += Tab(depth) + "</script>\n";
        else
            result += Tab(depth) + "</item>\n";
        
        return result;
    }

    public void Save(JTree tree, String f)
    {
        if(f == null)
            f = fname;

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

    public ParseTreeNode GetParseTreeNode(ParseTreeNode root, String name)
    {
        for(int i=0; i<root.children.size(); i++){
            ParseTreeNode child = (ParseTreeNode) root.children.get(i);
            if(child.type.equals(name))
                return child;
            else if(GetParseTreeNode(child, name) != null){
                return GetParseTreeNode(child, name);
            }
        }

        return null;
    }

    public void BuildCommandTree(JTree tree)
    {
        UtilTree.RemoveAll(tree);

        DefaultMutableTreeNode treeRoot = (DefaultMutableTreeNode)tree.getModel().getRoot();

        /* Script Section */
        ParseTreeNode root = GetParseTreeNode(VpaParseTree.GetRoot(), "script");
        if(root != null){
            DefaultMutableTreeNode cnode = (DefaultMutableTreeNode)new ToolTipTreeNode("script", root.data);
            script = root.data;
            treeRoot.add(cnode);
        }
        
        /* Command Section */
        root = GetParseTreeNode(VpaParseTree.GetRoot(), "command");
        if(root != null){
            DefaultMutableTreeNode cnode = (DefaultMutableTreeNode)new ToolTipTreeNode("command", "");
            treeRoot.add(cnode);
            BuildCommandTreeNode(cnode, root, 0);
        }
        
        UtilTree.ExpandAll(tree);
    }

    public String GetScript()
    {
        return script;
    }
}
