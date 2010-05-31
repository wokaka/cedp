/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package vpa.parsetree;

import java.util.Vector;

/**
 *
 * @author yim
 */
public class ParseTreeNode {
    public String type;
    public String name;
    public String data;
    public Vector children;
    public ParseTreeNode parent;

    public ParseTreeNode(String t)
    {
        children = new Vector();
        type = t;
    }

    public void SetName(String n)
    {
        if(n.startsWith("'"))
            n = n.substring(1);
        if(n.endsWith("'"))
            n = n.substring(0, n.length()-1);
        
        name = n;
    }

    public void SetData(String d)
    {
        while(d.startsWith("\n"))
            d = d.substring(1);
        while(d.endsWith("'"))
            d = d.substring(0, d.length()-1);

        data = d;
    }

    public void AddChild(ParseTreeNode c)
    {
        children.add(c);
        c.SetParent(this);
    }

    public ParseTreeNode GetChild(int idx)
    {
        return (ParseTreeNode)children.get(idx);
    }

    public void SetParent(ParseTreeNode p)
    {
        parent = p;
    }
}
