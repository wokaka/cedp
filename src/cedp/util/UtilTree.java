/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util;

import javax.swing.JTree;
import javax.swing.tree.DefaultMutableTreeNode;

/**
 *
 * @author Keun Soo Yim
 */
public class UtilTree
{
    public static void ApplyFilter(DefaultMutableTreeNode node, String filter)
    {

        if(node.getChildCount() == 0){
            if(!node.toString().endsWith(filter)){
                node.removeFromParent();
            }
            return;
        }

        for(int i=0; i<node.getChildCount(); i++){
            ApplyFilter((DefaultMutableTreeNode)node.getChildAt(i), filter);
        }
    }

    public static void RemoveChildren(DefaultMutableTreeNode node)
    {
        while(node.getChildCount() > 0){
            RemoveChildren((DefaultMutableTreeNode)node.getFirstChild());
        }
        //System.out.println(""+node);
        node.removeFromParent();
    }
    
    public static void RemoveAll(JTree tree)
    {
        // Tree root won't be removed.
        RemoveChildren((DefaultMutableTreeNode)tree.getModel().getRoot());
        tree.updateUI();
    }

    public static void ExpandAll(JTree tree)
    {
        for(int i=0; i<tree.getRowCount(); i++)
            tree.expandRow(i);
    }

    
}
