package cetus.base.grammars;

import java.util.*;

public class PreprocessorInfoChannel
{
    HashMap<Integer, LinkedList<Pragma>> lineLists = new HashMap<Integer, LinkedList<Pragma>>(); // indexed by Token number
    int firstValidTokenNumber = 0;
    int maxTokenNumber = 0;

    public void addLineForTokenNumber( Pragma line, Integer toknum )
    {
        if ( lineLists.containsKey( toknum ) ) {
            LinkedList<Pragma> lines = lineLists.get( toknum );
            lines.add(line);
        }
        else {
            LinkedList<Pragma> lines = new LinkedList<Pragma>();
            lines.add(line);
            lineLists.put(toknum, lines);
            if ( maxTokenNumber < toknum.intValue() ) {
                maxTokenNumber = toknum.intValue();
            }
        }
    }

    public int getMaxTokenNumber()
    {
        return maxTokenNumber;
    }
        
    public LinkedList<Pragma> extractLinesPrecedingTokenNumber( Integer toknum )
    {
        LinkedList<Pragma> lines = new LinkedList<Pragma>();
        if (toknum == null) return lines;       
        for (int i = firstValidTokenNumber; i < toknum.intValue(); i++){
            Integer inti = new Integer(i);
            if ( lineLists.containsKey( inti ) ) {
                LinkedList<Pragma> tokenLineVector = lineLists.get( inti );
                if ( tokenLineVector != null) {
                    //Enumeration tokenLines = tokenLineVector.elements();
                    //while ( tokenLines.hasMoreElements() ) {
                    //    lines.add( tokenLines.nextElement() );
                    //}
										for(Pragma o : tokenLineVector)
												lines.add(o);
                    lineLists.remove(inti);
                }
            }
        }
        firstValidTokenNumber = toknum.intValue();
        return lines;
    }

    public String toString()
    {
        StringBuffer sb = new StringBuffer("PreprocessorInfoChannel:\n");
        for (int i = 0; i <= maxTokenNumber + 1; i++){
            Integer inti = new Integer(i);
            if ( lineLists.containsKey( inti ) ) {
                LinkedList<Pragma> tokenLineVector = lineLists.get( inti );
                if ( tokenLineVector != null) {
                    //Enumeration tokenLines = tokenLineVector.elements();
                    //while ( tokenLines.hasMoreElements() ) {
                    //    sb.append(inti + ":" + tokenLines.nextElement() + '\n');
                    //}
										for(Pragma o : tokenLineVector)
											sb.append(inti + ":" + o + '\n');
                }
            }
        }
        return sb.toString();
    }
}



