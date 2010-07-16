package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import java.lang.Math;

public class KernelLaunch extends FunctionCall {

    private static Method class_print_method;
    private int numLaunchArgs;
    private static final Method print_as_Cuda_method;

    static {
        Class<?>[] params = new Class<?>[2];

        try {
            params[0] = KernelLaunch.class;
            params[1] = OutputStream.class;
            print_as_Cuda_method = params[0].getMethod("CudaPrint", params);
            class_print_method = params[0].getMethod("CPrint", params);
        } catch (NoSuchMethodException e) {
            throw new InternalError();
        }
    }

    public KernelLaunch(Expression function, List<Expression> kernelargs, List<Expression> args) {
        super(function);
        numLaunchArgs = kernelargs.size();
        ChainedList<Expression> allargs = new ChainedList<Expression>();
        super.setArguments(allargs.addAllLinks(kernelargs).addAllLinks(args));
        object_print_method = class_print_method;
    }

    public KernelLaunch(Expression function, List<Expression> kernelargs) {
        super(function, kernelargs);
        numLaunchArgs = kernelargs.size();
        object_print_method = class_print_method;
    }

    public void addLaunchArgument(Expression arg) {
        children.add(numLaunchArgs, arg);
        numLaunchArgs++;
    }

    public void addLaunchArgument(int n, Expression arg) {
        if (n > numLaunchArgs + 1) {
            throw new IllegalArgumentException();
        }
        numLaunchArgs++;
        children.add(n + 1, arg);
    }

    public Expression getArgument(int n) {
        return (Expression) children.get(n + numLaunchArgs + 1);
    }

    public List<Expression> getArguments() {
        LinkedList<Expression> list = new LinkedList<Expression>();
        for (int i = (1 + numLaunchArgs); i < children.size(); i++) {
            if (children.get(i) instanceof Expression) {
                list.add((Expression) children.get(i));
            }
        }
        return list;
    }

    public List<Expression> getLaunchArguments() {
        LinkedList<Expression> list = new LinkedList<Expression>();
        for (int i = 1; i <= numLaunchArgs; i++) {
            if (children.get(i) instanceof Expression) {
                list.add((Expression) children.get(i));
            }
        }
        return list;
    }

    public int getNumArguments() {
        return children.size() - (1 + numLaunchArgs);
    }

    public int getNumLaunchArguments() {
        return numLaunchArgs;
    }

    public List<Specifier> getReturnType() {
        return (new ChainedList<Specifier>()).addLink(Specifier.VOID);
    }

    public void setLaunchArgument(int n, Expression arg) {
        children.set(n + 1, arg);
    }

    public void setArgument(int n, Expression expr) {
        children.set(n + numLaunchArgs + 1, expr);
    }

    public void setArguments(List<Expression> args) {
        List<Traversable> save = new LinkedList<Traversable>();
        int i = 0;
        for (Traversable t : children) {
            save.add(t);
            i++;
            if (i >= numLaunchArgs) {
                break;
            }
        }
        children.clear();
        children.addAll(save);
        for (Expression e : args) {
            children.add(e);
            e.setParent(this);
        }
    }

    public void setLaunchArguments(List<Expression> largs) {
        for (int i = 0; i < numLaunchArgs; i++) {
            children.remove(1);
        }
        numLaunchArgs = 0;
        for (Expression e : largs) {
            children.add(++numLaunchArgs, e);
            e.setParent(this);
        }
    }

    //Truncate the launch argument list to n items
    public void clipLaunchArguments(int n) {
        for (int i = n; i < numLaunchArgs; i++) {
            children.remove(n + 1);
        }
        numLaunchArgs = Math.max(n, numLaunchArgs);
    }

    public void setKernel(Expression expr) {
        setFunction(expr);
    }

    public static void CudaPrint(KernelLaunch call, OutputStream stream) {
        PrintStream p = new PrintStream(stream);

        if (call.needs_parens) {
            p.print("(");
        }

        call.getName().print(stream);
        p.print("<<<");
        Tools.printListWithCommas(call.getLaunchArguments(), stream);
        p.print(">>>");

        p.print("(");
        Tools.printListWithCommas(call.getArguments(), stream);
        p.print(")");

        if (call.needs_parens) {
            p.print(")");
        }
    }

    public static void CPrint(KernelLaunch call, OutputStream stream) {
        PrintStream p = new PrintStream(stream);

        if (call.needs_parens) {
            p.print("(");
        }

        call.getName().print(stream);
        p.print("(");
        ChainedList<Expression> tmp = new ChainedList<Expression>();
        tmp.addAllLinks(call.getArguments()).addAllLinks(call.getLaunchArguments());
        Tools.printListWithCommas(tmp, stream);
        p.print(")");

        if (call.needs_parens) {
            p.print(")");
        }
    }

    public String toCString() {
        StringBuilder str = new StringBuilder(80);

        if (needs_parens) {
            str.append("(");
        }

        str.append(getName());
        str.append("(");
        str.append(Tools.listToString(getArguments(), ", "));
        if (numLaunchArgs != 0) {
            str.append(", ");
            str.append(Tools.listToString(getLaunchArguments(), ", "));
        }
        str.append(")");

        if (needs_parens) {
            str.append(")");
        }

        return str.toString();
    }

    public String toCudaString() {
        StringBuilder str = new StringBuilder(80);

        if (needs_parens) {
            str.append("(");
        }

        str.append(getName());
        str.append("<<<");
        str.append(Tools.listToString(getLaunchArguments(), ", "));
        str.append(">>> (");
        str.append(Tools.listToString(getArguments(), ", "));
        str.append(")");

        if (needs_parens) {
            str.append(")");
        }

        return str.toString();
    }

    public String toString() {
        /*if(object_print_method == print_as_Cuda_method)
        return toCudaString();
        else
        return toCString();
         *
         */

        return toCudaString();
    }
}
