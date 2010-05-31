/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cedp.login;

import java.io.Serializable;
import java.util.Date;

/**
 *
 * @author Keun Soo Yim
 */
public class Session implements Serializable {

    public String       name;
    public int          type;
    public Object       client[][];
    public long         lastUpdate;
    public long         lastUse;
    
    public Session()
    {
        type = 0;

        client = new Object[][]{{"", "22", "", "", "", ""}};
        
        lastUpdate = System.currentTimeMillis();
        lastUse = System.currentTimeMillis();
    }
}
