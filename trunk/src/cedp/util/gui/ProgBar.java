/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * ProgBar.java
 *
 * Created on May 28, 2010, 4:24:10 PM
 */

package cedp.util.gui;

/**
 *
 * @author yim
 */
public class ProgBar extends javax.swing.JPanel implements Runnable
{
    protected final int max = 10;
    
    protected Thread thread;
    protected int cnt;
    protected boolean progress;

    /** Creates new form ProgBar */
    public ProgBar() {
        initComponents();
        cnt = 0;
        progress = false;
        bar.setMinimum(0);
        bar.setMaximum(max);
        thread = new Thread(this);
        thread.start();
    }

    public void Process()
    {
        label.setText("Processing");
        cnt = 1;
        progress = true;
        thread.resume();
    }

    public void Done()
    {
        label.setText("Done");
        progress = false;
    }

    public void run()
    {
        while(true){
            try{
                if(progress){
                    cnt++;
                    if(cnt == 10)
                        cnt = 1;
                    bar.setValue(cnt);
                }
                else{
                    bar.setValue(max);
                    thread.suspend();
                }
                try{
                    Thread.sleep(1000);
                } catch(Exception e){
                    e.printStackTrace();
                }
            } catch(Exception e){
                e.printStackTrace();
            }
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

        label = new javax.swing.JLabel();
        bar = new javax.swing.JProgressBar();

        label.setText("Done");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(label, javax.swing.GroupLayout.PREFERRED_SIZE, 108, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 49, Short.MAX_VALUE)
                .addComponent(bar, javax.swing.GroupLayout.PREFERRED_SIZE, 198, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(label)
            .addComponent(bar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );

        label.getAccessibleContext().setAccessibleName("label");
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JProgressBar bar;
    private javax.swing.JLabel label;
    // End of variables declaration//GEN-END:variables

}