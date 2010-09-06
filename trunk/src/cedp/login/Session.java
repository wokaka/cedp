/**
 * CEDP: Computer Evaluator for Dependability and Performance
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 */

package cedp.login;

import java.io.Serializable;
import java.util.Date;

/**
 * This class maintains data structure for sessions used to connect to an
 * injector node.
 * 
 * @author Keun Soo Yim (yim2012@gmail.com)
 */
public class Session implements Serializable
{
  public String name;
  public int type;
  public Object client[][];
  public long lastUpdate;
  public long lastUse;

  public Session()
  {
    type = 0;
    client = new Object[][]{{"", "22", "", "", "", ""}};
    lastUpdate = System.currentTimeMillis();
    lastUse = System.currentTimeMillis();
  }
}
