package cetus.codegen;

import cetus.hir.*;

public abstract class CodeGenPass
{
  protected Program program;

  protected CodeGenPass(Program program)
  {
    this.program = program;
  }

  public abstract String getPassName();

  public static void run(CodeGenPass pass)
  {
    Tools.println(pass.getPassName() + " begin", 0);
    pass.start();
    Tools.println(pass.getPassName() + " end", 0);
  }

  public abstract void start();
}
