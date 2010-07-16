package cetus.transforms;

import java.util.*;

import cetus.exec.*;
import cetus.hir.*;

public abstract class ProcedureTransformPass extends TransformPass
{
  protected ProcedureTransformPass(Program program)
  {
    super(program);
  }

  public abstract void transformProcedure(Procedure proc);

  public void start()
  {
    HashSet<String> skip_set = Driver.getSkipProcedureSet();

    DepthFirstIterator iter = new DepthFirstIterator(program);
    iter.pruneOn(Procedure.class);

    for (;;)
    {
      Procedure proc = null;

      try {
        proc = iter.next(Procedure.class);
      } catch (NoSuchElementException e) {
        break;
      }

      if (!skip_set.contains(proc.getName().toString()))
      {
        Tools.printlnStatus(getPassName() + " examining procedure " + proc.getName(), 2);

        transformProcedure(proc);
      }
      else
      {
        Tools.printlnStatus(getPassName() + " skipping procedure " + proc.getName(), 2);
      }
    }
  }
}
