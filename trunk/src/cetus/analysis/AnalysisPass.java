package cetus.analysis;

import cetus.hir.*;

public abstract class AnalysisPass
{
  protected Program program;

  protected AnalysisPass(Program program)
  {
    this.program = program;
  }

  public abstract String getPassName();

  public static void run(AnalysisPass pass)
  {
		double timer = Tools.getTime();
    Tools.println(pass.getPassName() + " begin", 0);
    pass.startAndCheck();
    Tools.println(pass.getPassName() + " end in " +
			String.format("%.2f seconds", Tools.getTime(timer)), 0);
  }

  public abstract void start();

	public void startAndCheck()
	{
		start();
		// IR consistency checking - useful for debugging.
		if ( Tools.getVerbosity() > 0 && !Tools.checkConsistency(program) )
			Tools.printlnStatus("[WARNING] Inconsistent IR after "+getPassName(), 0);
	}
}
