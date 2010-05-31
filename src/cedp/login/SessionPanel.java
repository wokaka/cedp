/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * SessionPanel.java
 *
 * Created on Jul 27, 2009, 11:42:06 PM
 */

package cedp.login;

import cedp.node.PerfJavaNode;
import cedp.util.UtilRandom;
import cedp.util.UtilString;
import cedp.util.UtilTable;
import java.awt.Frame;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import javax.swing.JTable;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.TableCellRenderer;
import vpa.interpreter.VpaProgram;

/**
 *
 * @author Keun Soo Yim
 */
public class SessionPanel extends javax.swing.JPanel
{
    protected final int maxInjector = 1;
    
    /** Creates new form SessionPanel */
    protected final String  configFileName = "session-";
    protected Frame parent;

    public SessionPanel()
    {
        initComponents();
    }

    public SessionPanel(Frame p)
    {
        parent = p;
        initComponents();
        InitCampaign();
    }

    protected void InitCampaign()
    {
        String      campList[];
        Session     camp;
        int         i;

        System.out.println("InitCampaign");
        campList = Init();
        if(campList != null){
            for(i=0; i<campList.length; i++)
                idCombo.addItem(campList[i]);

            if(idCombo.getItemCount() == 1){
                idCombo.setSelectedIndex(0);
            }
            else{
                idCombo.setSelectedIndex(1);
            }
            idComboActionPerformed(null);
        }
    }

    protected String[] Init()
    {
        String      result[] = new String[0];
        String      files[];
        int         i, cnt;

        File dir = new File("./");

        files = dir.list();
        if (files != null) {
            for (i=0, cnt=0; i<files.length; i++) {
                if(files[i].startsWith("session-") && files[i].endsWith(".cfg"))
                    cnt++;
            }

            if(cnt>0){
                result = new String[cnt];
                for (i=0, cnt=0; i<files.length; i++) {
                    if(files[i].startsWith("session-") && files[i].endsWith(".cfg")){
                        result[cnt] = files[i].substring(8, files[i].length() - 4);
                        cnt++;
                    }
                }
            }
        }

        return result;
    }

    public boolean Store(String name, Session camp)
    {
        ObjectOutputStream out;

        Delete(name);

        try {
            out = new ObjectOutputStream(new FileOutputStream("session-" + name + ".cfg"));

            out.writeObject(camp);

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

        return true;
    }

    public Session Load(String name)
    {
        ObjectInputStream in;
        Object obj;
        Session camp;
        File file;

        try{
            // Check if file exists or not
            file = new File("session-" + name + ".cfg");
            if(!file.exists())
                return null;

            // Read data form a file
            in = new ObjectInputStream(new FileInputStream("session-" + name + ".cfg"));

            obj = in.readObject();
            if(!(obj instanceof Session)){
                System.out.println("Config file does follow the format.");
                return null;
            }
            camp = (Session) obj;

            in.close();

            return camp;
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }

    public void Delete(String name)
    {
        File    file;

        try{
            file = new File("session-" + name + ".cfg");
            if(file.exists())
                file.delete();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void SaveSession()
    {
        if(CheckSession()){
            Store(nameField.getText(), GetSession());
            if(idCombo.getSelectedIndex() == 0 ||
               !nameField.getText().equals(idCombo.getSelectedItem())){
                idCombo.addItem(nameField.getText());
                idCombo.setSelectedIndex(idCombo.getItemCount()-1);
            }
        }
        else
            System.out.println("error: check the session name (it could be either empty or duplicated)");
    }

    public void DeleteSession()
    {
        // TODO add your handling code here:
        if(idCombo.getSelectedIndex() != 0){
            Delete(nameField.getText());
            idCombo.removeItemAt(idCombo.getSelectedIndex());
        }
        else{
            Session camp;
            camp = GetDefaultSession();
            SetSession(camp);
        }
    }

    protected boolean CheckSession()
    {
        String  temp;
        String  list[];
        int     i;

        // Check whether it's an empty string
        temp = nameField.getText();
        if(temp.length() < 1)
            return false;

        // Check whether the session name is same as one preexist
        if(idCombo.getSelectedIndex() == 0){
            list = Init();
            for(i=0; i<list.length; i++)
                if(list[i].equals(temp))
                    return false;
        }

        return true;
    }

    private void SetSession(Session camp) {
        // TODO add your handling code here:
        nameField.setText(camp.name);
        typeCombo.setSelectedIndex(camp.type);
//        serverPortField.setText(camp.serverPort);

        UtilTable.SetTableObject(clientTable, camp.client);

//        appField.setText(camp.application);
//        kernCheck.setSelected(camp.kernel);
//        appField.setEditable(!kernelCheck.isSelected());

//        resetServerField.setText(camp.resetIp);
//        resetPortField.setText(camp.resetPort);
    }

    private Session GetSession() {
        Session camp = new Session();

        camp.name = nameField.getText();

        camp.type = typeCombo.getSelectedIndex();
//        camp.serverPort = serverPortField.getText();

        camp.client = UtilTable.GetTableObject(clientTable);

//        camp.application = appField.getText();
//        camp.kernel = kernCheck.isSelected();

//        camp.resetIp = resetServerField.getText();
//        camp.resetPort = resetPortField.getText();

        return camp;
    }

    private Session GetDefaultSession() {
        Session camp = new Session();

        return camp;
    }

    public void Propagate()
    {
    }

    public JTable GetNodeTable()
    {
        return null;
    }

    static class PasswordRenderer extends DefaultTableCellRenderer
    {
        protected void setValue(Object value)
        {
            setText("*");
        }
    }


    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        kernelCheck = new javax.swing.JCheckBox();
        jPanel4 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        idCombo = new javax.swing.JComboBox();
        jLabel3 = new javax.swing.JLabel();
        nameField = new javax.swing.JTextField();
        saveButton = new javax.swing.JButton();
        deleteButton = new javax.swing.JButton();
        jPanel5 = new javax.swing.JPanel();
        jLabel7 = new javax.swing.JLabel();
        typeCombo = new javax.swing.JComboBox();
        jScrollPane1 = new javax.swing.JScrollPane();
        clientTable = new javax.swing.JTable(){
            public TableCellRenderer getCellRenderer(int row, int col){
                if (col == 3)
                return (TableCellRenderer)new PasswordRenderer();
                else
                return super.getCellRenderer(row, col);
            }
        };
        ;
        plusButton = new javax.swing.JButton();
        minusButton = new javax.swing.JButton();
        launchButton = new javax.swing.JButton();

        kernelCheck.setText("Kernel");

        jPanel4.setBorder(javax.swing.BorderFactory.createTitledBorder("Session"));

        jLabel2.setText("ID:");

        idCombo.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "<New Session>" }));
        idCombo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                idComboActionPerformed(evt);
            }
        });

        jLabel3.setText("Name:");

        saveButton.setText("Save");
        saveButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveButtonActionPerformed(evt);
            }
        });

        deleteButton.setText("Delete");
        deleteButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                deleteButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel3)
                    .addComponent(jLabel2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(nameField, javax.swing.GroupLayout.DEFAULT_SIZE, 280, Short.MAX_VALUE)
                    .addComponent(idCombo, 0, 280, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(saveButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(deleteButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(idCombo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(saveButton))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(nameField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(deleteButton)))
        );

        jPanel5.setBorder(javax.swing.BorderFactory.createTitledBorder("Target Node(s)"));

        jLabel7.setText("Type:");

        typeCombo.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Perf - Java", "Perf - OS Memory (Linux)", "-----", "Fault(HW) - OS(SUSE) - Monitor", "Fault(HW) - OS(SUSE) - Injector", "Fault(HW) - VMM", "Fault(HW) - Data Analyzer", "Fault(SW) - GPU(Cuda/Linux)", "-----", "Rigel" }));
        typeCombo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                typeComboActionPerformed(evt);
            }
        });

        clientTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, "22", null, null, "", ""}
            },
            new String [] {
                "DNS", "Port", "ID", "PW", "VPA", "Config"
            }
        ));
        jScrollPane1.setViewportView(clientTable);

        plusButton.setText("+");
        plusButton.setMargin(new java.awt.Insets(2, 5, 2, 5));
        plusButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                plusButtonActionPerformed(evt);
            }
        });

        minusButton.setText("-");
        minusButton.setMargin(new java.awt.Insets(2, 5, 2, 5));
        minusButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                minusButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel5Layout = new javax.swing.GroupLayout(jPanel5);
        jPanel5.setLayout(jPanel5Layout);
        jPanel5Layout.setHorizontalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel5Layout.createSequentialGroup()
                .addComponent(jLabel7)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(typeCombo, 0, 262, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(plusButton)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(minusButton, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 407, Short.MAX_VALUE)
        );
        jPanel5Layout.setVerticalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(typeCombo, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(minusButton, javax.swing.GroupLayout.PREFERRED_SIZE, 22, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(plusButton, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 64, Short.MAX_VALUE))
        );

        launchButton.setText("Connect");
        launchButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                launchButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(launchButton, javax.swing.GroupLayout.DEFAULT_SIZE, 419, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(launchButton)
                .addContainerGap())
        );
    }// </editor-fold>//GEN-END:initComponents

    private void saveButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveButtonActionPerformed
        // TODO add your handling code here:
        SaveSession();
    }//GEN-LAST:event_saveButtonActionPerformed

    private void deleteButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_deleteButtonActionPerformed
        // TODO add your handling code here:
        DeleteSession();
    }//GEN-LAST:event_deleteButtonActionPerformed

    private void idComboActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_idComboActionPerformed
        // TODO add your handling code here:
        Session camp;

        // TODO add your handling code here:
        if(idCombo.getSelectedIndex() == 0){
            camp = GetDefaultSession();
            SetSession(camp);
        }
        else{
            camp = Load(idCombo.getSelectedItem().toString());
            if(camp != null){
                SetSession(camp);
            }
            else{
                camp = GetDefaultSession();
                SetSession(camp);
            }
        }
    }//GEN-LAST:event_idComboActionPerformed

    private void typeComboActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_typeComboActionPerformed
        // TODO add your handling code here:

    }//GEN-LAST:event_typeComboActionPerformed

    private void launchButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_launchButtonActionPerformed
        // TODO add your handling code here:
        int     i;
        String  addr;
        int  port;
        String id, pwd;
        String vpa, cfg;
        
        launchButton.disable();

        parent.hide();
        if(typeCombo.getSelectedIndex() == 0){ // Performance - Java
            for(i=0; i<clientTable.getModel().getRowCount(); i++){
                addr = (String)clientTable.getModel().getValueAt(i, 0);
                port = Integer.parseInt((String)clientTable.getModel().getValueAt(i, 1), 10);
                id = (String)clientTable.getModel().getValueAt(i, 2);
                pwd = (String)clientTable.getModel().getValueAt(i, 3);
                vpa = (String)clientTable.getModel().getValueAt(i, 4);
                cfg = (String)clientTable.getModel().getValueAt(i, 5);

                PerfJavaNode perfJava = new PerfJavaNode(addr+":"+port, new VpaProgram(vpa), cfg);
                perfJava.Launch(addr, port, id, pwd);
            }
        }

        /*
        if(typeCombo.getSelectedIndex() == 0){ // OS Injector Master
            for(i=0; i<clientTable.getModel().getRowCount(); i++){
                addr = (String)clientTable.getModel().getValueAt(i, 0);
                port = Integer.parseInt((String)clientTable.getModel().getValueAt(i, 1), 10);

                mainFrame.CreateMasterInjector(i, addr+":"+port);
//                mainFrame.GetInjector(i).SetInjector(addr, port, Integer.parseInt(serverPortField.getText(), 10), typeCombo.getSelectedIndex());
//                mainFrame.GetInjector(i).GetResetClientPanel().SetReset(resetServerField.getText(), Integer.parseInt(resetPortField.getText()), (String)clientTable.getModel().getValueAt(i, 2));
                if(!mainFrame.GetInjector(i).Launch()){
                    mainFrame.RemoveInjector(i);
                }
            }
        }
        else if(typeCombo.getSelectedIndex() == 1){ // OS Injector Slave
            for(i=0; i<clientTable.getModel().getRowCount(); i++){
                addr = (String)clientTable.getModel().getValueAt(i, 0);
                port = Integer.parseInt((String)clientTable.getModel().getValueAt(i, 1), 10);

                mainFrame.CreateSlaveInjector(i, addr+":"+port);
//                mainFrame.GetInjector(i).SetInjector(addr, port, Integer.parseInt(serverPortField.getText(), 10), typeCombo.getSelectedIndex());
//                mainFrame.GetInjector(i).GetResetClientPanel().SetReset(resetServerField.getText(), Integer.parseInt(resetPortField.getText()), (String)clientTable.getModel().getValueAt(i, 2));
                if(!mainFrame.GetInjector(i).Launch()){
                    mainFrame.RemoveInjector(i);
                }
            }
        }
        else if(typeCombo.getSelectedIndex() == 2){ // Memory Profiler
            mainFrame.CreateProfiler();
            mainFrame.GetProfiler().Launch();
        }
        else if(typeCombo.getSelectedIndex() == 3){ // VMM
            addr = (String)clientTable.getModel().getValueAt(0, 0);
            port = Integer.parseInt((String)clientTable.getModel().getValueAt(0, 1), 10);
            id = (String)clientTable.getModel().getValueAt(0, 2);
            pwd = (String)clientTable.getModel().getValueAt(0, 3);

            mainFrame.CreateQemuManager(addr+":"+port);
            mainFrame.GetQemuManager().Launch(addr, port, id, pwd);
            mainFrame.Hide();
        }
        else if(typeCombo.getSelectedIndex() == 4){
            mainFrame.CreateAnalyzer();
            mainFrame.GetAnalyzer().Launch();
        }
        else if(typeCombo.getSelectedIndex() == 5){
            addr = (String)clientTable.getModel().getValueAt(0, 0);
            port = Integer.parseInt((String)clientTable.getModel().getValueAt(0, 1), 10);
            id = (String)clientTable.getModel().getValueAt(0, 2);
            pwd = (String)clientTable.getModel().getValueAt(0, 3);

            mainFrame.CreateSWFaultManager(addr+":"+port);
            mainFrame.GetSWFaultManager().Launch(addr, port, id, pwd);
            mainFrame.Hide();
        }
        else if(typeCombo.getSelectedIndex() == 6){
            addr = (String)clientTable.getModel().getValueAt(0, 0);
            port = Integer.parseInt((String)clientTable.getModel().getValueAt(0, 1), 10);
            id = (String)clientTable.getModel().getValueAt(0, 2);
            pwd = (String)clientTable.getModel().getValueAt(0, 3);

            mainFrame.CreateRigelManager(addr+":"+port);
            mainFrame.GetRigelManager().Launch(addr, port, id, pwd);
            mainFrame.Hide();
        }
        //mainFrame.FocusLogPanel();
         */
    }//GEN-LAST:event_launchButtonActionPerformed
    
    private void plusButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_plusButtonActionPerformed
        // TODO add your handling code here:
        int     cnt;
        
        cnt = clientTable.getRowCount() + 1;
        if(cnt >=1  && cnt <= maxInjector)
            UtilTable.SetTableCount(clientTable, cnt, new Object[]{"", "22", "", "", "NA"});
    }//GEN-LAST:event_plusButtonActionPerformed

    private void minusButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_minusButtonActionPerformed
        // TODO add your handling code here:
        int     cnt;

        cnt = clientTable.getRowCount() - 1;
        if(cnt >=1  && cnt <= maxInjector)
            UtilTable.SetTableCount(clientTable, cnt, new Object[]{"", "22", "", "", "NA"});
    }//GEN-LAST:event_minusButtonActionPerformed


    protected String GetMask(int length)
    {
        String  result;
        int     i, j, k;
        int     mask = 0;

        result = null;
        j = 1;
        for(i=0; i<j; i++){
            do{
                k = UtilRandom.Random(0, length*8-1);
                k = 1 << k;
            } while((k & mask) != 0);
            mask |= k;
        }
        result = "0x" + (UtilString.Hex2String(mask));

        return result;
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTable clientTable;
    private javax.swing.JButton deleteButton;
    private javax.swing.JComboBox idCombo;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JCheckBox kernelCheck;
    private javax.swing.JButton launchButton;
    private javax.swing.JButton minusButton;
    private javax.swing.JTextField nameField;
    private javax.swing.JButton plusButton;
    private javax.swing.JButton saveButton;
    private javax.swing.JComboBox typeCombo;
    // End of variables declaration//GEN-END:variables
}
