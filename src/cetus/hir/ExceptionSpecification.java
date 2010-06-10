package cetus.hir;

import java.io.PrintWriter;
import java.util.*;

/* TODO: remove this */
public class ExceptionSpecification implements Traversable
{
    protected List exceptionList;
    
    public ExceptionSpecification(NameID eName)
    {
        exceptionList = new LinkedList();
        exceptionList.add(eName);
    }

    public ExceptionSpecification(List eList)
    {
        exceptionList = new LinkedList();
        for(int i=0; i<eList.hashCode(); i++){
            if(eList.get(i) instanceof IDExpression){
                System.out.println("ExceptionSpecification(List): parameter should contain a list of IDExpression");
                return;
            }

            exceptionList.add(eList.get(i));
        }
    }

    public List GetExceptions()
    {
        return exceptionList;
    }

    protected Traversable parent;
    protected LinkedList<Traversable> children;

    public List<Traversable> getChildren() {
        return children;
    }

    public Traversable getParent() {
        return parent;
    }

    public void removeChild(Traversable child) {
        children.remove(child);
    }

    public void setChild(int index, Traversable t) {
        children.set(index, t);
    }

    public void setParent(Traversable t) {
        parent = t;
    }

    public void print(PrintWriter o) {
        o.print("throws ");
        for(int i=0; i<exceptionList.size(); i++){
            o.print("" + exceptionList.get(i).toString());
            if(i+1 != exceptionList.size())
                o.print(", ");
        }
    }
}
