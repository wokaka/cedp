/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */

package cedp.util.gui;

import javax.swing.tree.DefaultMutableTreeNode;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class ToolTipTreeNode extends DefaultMutableTreeNode
{
  private String toolTipText;

  public ToolTipTreeNode(String str, String toolTipText)
  {
    super(str);
    this.toolTipText = toolTipText;
  }

  public String GetToolTipText()
  {
    return toolTipText;
  }

  public void SetToolTipText(String text)
  {
    toolTipText = text;
  }
}
