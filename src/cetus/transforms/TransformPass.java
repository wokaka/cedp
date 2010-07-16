package cetus.transforms;

import cetus.hir.*;

public abstract class TransformPass
{
  protected Program program;

  protected TransformPass(Program program)
  {
    this.program = program;
  }

  public abstract String getPassName();

  public static void run(TransformPass pass)
  {
		double timer = Tools.getTime();
    Tools.println(pass.getPassName() + " begin", 0);
    pass.startAndCheck();
    Tools.println(pass.getPassName() + " end in " +
			Double.toString(timer) + " seconds", 0);
//			String.format("%.2f seconds", Tools.getTime(timer)), 0);
  }

  public abstract void start();

	public void startAndCheck()
	{
		start();
		// IR consistency checking - useful for debugging.
		if ( Tools.getVerbosity() > 0 && !Tools.checkConsistency(program) )
			Tools.printlnStatus("[WARNING] Inconsistent IR after "+getPassName(), 0);
		SymbolTools.linkSymbol(program);
	}
}
