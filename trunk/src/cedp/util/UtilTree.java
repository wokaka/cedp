/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

import javax.swing.JTree;
import javax.swing.tree.DefaultMutableTreeNode;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilTree
{
  public static void ApplyFilter(DefaultMutableTreeNode node, String filter)
  {
    if(node.getChildCount() == 0){
      if(!node.toString().endsWith(filter)) {
        node.removeFromParent();
      }
      return;
    }

    for (int i = 0; i < node.getChildCount(); i++) {
      ApplyFilter((DefaultMutableTreeNode)node.getChildAt(i), filter);
    }
  }

  public static void RemoveChildren(DefaultMutableTreeNode node)
  {
    while (node.getChildCount() > 0) {
      RemoveChildren((DefaultMutableTreeNode)node.getFirstChild());
    }
    //System.out.println("" + node);
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
    for(int i = 0; i < tree.getRowCount(); i++) {
      tree.expandRow(i);
    }
  }
}
