/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.util;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Keun Soo Yim
 */
public class UtilTable {

    public static Object[][] GetTableObject(JTable tbl)
    {
        int     r, c, i, j;
        Object  result[][];

        r = tbl.getModel().getRowCount();
        c = tbl.getModel().getColumnCount() - 1;
        result = new Object[r][c];

        for(i=0; i<r; i++){
            result[i] = new Object[c];

            for(j=0; j<c; j++)
                result[i][j] = tbl.getModel().getValueAt(i, j);
        }

        return result;
    }

    public static void SetTableObject(JTable tbl, Object[][] obj)
    {
        int     r, c, i, j;

        if(obj == null)
            return;

        r = UtilInteger.Min(tbl.getModel().getRowCount(), obj.length);
        if(obj.length == 0)
            return;

        SetTableCount(tbl, obj.length, obj[0]);

        c = UtilInteger.Min(tbl.getModel().getColumnCount(), obj[0].length);

        for(i=0; i<r; i++){
            for(j=0; j<c; j++)
                tbl.getModel().setValueAt(obj[i][j], i, j);
        }
    }

    public static void SetTableCount(JTable tbl, int value, Object []obj)
    {
        int     prev_value;
        int     i;

        prev_value = tbl.getRowCount();
        if(prev_value != value){
            DefaultTableModel tableModel = (DefaultTableModel) tbl.getModel();

            if(prev_value < value){
                for(i=prev_value; i<value; i++)
                    tableModel.insertRow(i, obj);
            }
            else{
                for(i=value; i<prev_value; i++)
                    tableModel.removeRow(value);
            }
        }
    }

    public static void DelFromTable(JTable tbl, int value)
    {
        if(value >= 0 && value < tbl.getRowCount()){
            DefaultTableModel tableModel = (DefaultTableModel) tbl.getModel();
            tableModel.removeRow(value);
        }
    }

    public static void DeleteAll(JTable tbl)
    {
        int i;
        DefaultTableModel tableModel = (DefaultTableModel) tbl.getModel();
        while(tableModel.getRowCount() > 0)
            tableModel.removeRow(0);
    }

    public static void AddToTable(JTable tbl, Object []obj, boolean head)
    {
        int     size = tbl.getRowCount();
        DefaultTableModel tableModel = (DefaultTableModel) tbl.getModel();

        if(head)
            tableModel.insertRow(0, obj);
        else
            tableModel.insertRow(size, obj);
    }
}
