/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */
package cedp.util;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class UtilTable
{
  public static Object[][] GetTableObject(JTable tbl)
  {
    int r = tbl.getModel().getRowCount();
    int c = tbl.getModel().getColumnCount();
    Object[][] result = new Object[r][c];

    for (int i=0; i < r; i++) {
      result[i] = new Object[c];

      for (int j=0; j < c; j++) {
        result[i][j] = tbl.getModel().getValueAt(i, j);
      }
    }

    return result;
  }

  public static void SetTableObject(JTable tbl, Object[][] obj)
  {
    if (obj == null) {
      return;
    }

    int r = UtilInteger.Min(tbl.getModel().getRowCount(), obj.length);
    if (obj.length == 0) {
      return;
    }

    SetTableCount(tbl, obj.length, obj[0]);

    int c = UtilInteger.Min(tbl.getModel().getColumnCount(), obj[0].length);

    for (int i=0; i < r; i++) {
      for (int j=0; j < c; j++) {
        tbl.getModel().setValueAt(obj[i][j], i, j);
      }
    }
  }

  public static void SetTableCount(JTable tbl, int value, Object []obj)
  {
    int     prev_value;
    int     i;

    prev_value = tbl.getRowCount();
    if (prev_value != value) {
      DefaultTableModel tableModel = (DefaultTableModel) tbl.getModel();

      if (prev_value < value) {
        for (i = prev_value; i < value; i++) {
          tableModel.insertRow(i, obj);
        }
      }
      else {
        for(i = value; i < prev_value; i++) {
          tableModel.removeRow(value);
        }
      }
    }
  }

  public static void DelFromTable(JTable tbl, int value)
  {
    if(value >= 0 && value < tbl.getRowCount()) {
      DefaultTableModel tableModel = (DefaultTableModel) tbl.getModel();
      tableModel.removeRow(value);
    }
  }

  public static void DeleteAll(JTable tbl)
  {
    DefaultTableModel tableModel = (DefaultTableModel) tbl.getModel();
    while (tableModel.getRowCount() > 0) {
      tableModel.removeRow(0);
    }
  }

  public static void AddToTable(JTable tbl, Object[] obj, boolean head)
  {
    int size = tbl.getRowCount();
    DefaultTableModel tableModel = (DefaultTableModel) tbl.getModel();

    if (head) {
      tableModel.insertRow(0, obj);
    }
    else {
      tableModel.insertRow(size, obj);
    }
  }
}
