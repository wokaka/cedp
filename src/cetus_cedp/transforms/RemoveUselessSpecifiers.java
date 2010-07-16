package cetus.transforms;

import java.util.*;

import cetus.hir.*;

public class RemoveUselessSpecifiers 
{
  private static String pass_name = "[RemoveUselessSpecifiers]";

  private Program program;

  private RemoveUselessSpecifiers(Program program)
  {
    this.program = program;
  }

  public static void run(Program program)
  {
    Tools.printlnStatus(pass_name + " begin", 1);

    RemoveUselessSpecifiers pass = new RemoveUselessSpecifiers(program);
    pass.start();

    Tools.printlnStatus(pass_name + " end", 1);
  }

  private void start()
  {
    DepthFirstIterator i = new DepthFirstIterator(program);
    i.pruneOn(VariableDeclaration.class);

    Set<Class<? extends Traversable>> set = new HashSet<Class<? extends Traversable>>();
    set.add(Procedure.class);
    set.add(VariableDeclaration.class);

    for (;;)
    {
      Procedure proc = null;
      VariableDeclaration decl = null;

      try {
        Object o = i.next(set);
        if (o instanceof Procedure)
          proc = (Procedure)o;
        else
          decl = (VariableDeclaration)o;
      } catch (NoSuchElementException e) {
        break;
      }

      if (proc != null)
      {
        Tools.printlnStatus(pass_name + " examining procedure " + proc.getName(), 2);
      }
      else  
      {
        while (decl.getSpecifiers().remove(Specifier.AUTO));
        while (decl.getSpecifiers().remove(Specifier.REGISTER));
      }
    }
  }
}
