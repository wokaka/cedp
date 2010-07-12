/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package vpa.parsetree;

import java.util.HashMap;
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
    public HashMap param;

    public ParseTreeNode(String t)
    {
        children = new Vector();
        param = new HashMap();
        type = t;
        data = "";
    }

    public void SetParam(String id, String n)
    {
      if(n.startsWith("'") || n.startsWith("\""))
          n = n.substring(1);
      if(n.endsWith("'") || n.endsWith("\""))
          n = n.substring(0, n.length()-1);

      if(id.equals("name")){
        name = n;
      }
      else{
        param.put(id, n);
      }
    }

    public String GetParam(String id)
    {
      if(id.equals("name"))
        return name;
      
      return (String)param.get(id);
    }

    public void AddBody(String d)
    {
        while(d.startsWith("\n"))
            d = d.substring(1);
        while(d.endsWith("\n") || d.endsWith("\t"))
            d = d.substring(0, d.length()-1);

        data += d;
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
