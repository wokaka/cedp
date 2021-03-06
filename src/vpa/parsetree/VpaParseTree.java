/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package vpa.parsetree;

/**
 *
 * @author yim
 */
public final class VpaParseTree {

    protected static ParseTreeNode root;
    protected static ParseTreeNode curr;

    public static void CreateNode(String t)
    {
        if(root == null){
            root = new ParseTreeNode("root");
            curr = root;
        }
        
        ParseTreeNode n = new ParseTreeNode(t);
        curr.AddChild(n);
        curr = n;
    }

    public static ParseTreeNode GetRoot()
    {
        return root;
    }
    
    public static void SetParam(String id, String n)
    {
      curr.SetParam(id, n);
    }

    public static void SetData(String d)
    {
        curr.AddBody(d);
    }

    public static void NodeConfigDone()
    {
        curr = curr.parent;
    }
}
