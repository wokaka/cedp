/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util.gui;

import javax.swing.tree.DefaultMutableTreeNode;

/**
 *
 * @author yim
 */
public class ToolTipTreeNode extends DefaultMutableTreeNode {
      private String toolTipText;

      public ToolTipTreeNode(String str, String toolTipText) {
        super(str);
        this.toolTipText = toolTipText;
      }

      public String GetToolTipText() {
        return toolTipText;
      }

      public void SetToolTipText(String txt)
      {
          toolTipText = txt;
      }
}
