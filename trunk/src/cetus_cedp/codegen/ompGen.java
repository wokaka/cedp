package cetus.codegen;

import cetus.hir.*;

import java.util.*;

/**
 * This pass looks for Annotations that provide
 * enough information to add OpenMP pragmas and
 * then inserts those pragmas.
 */
public class ompGen extends CodeGenPass
{
  public ompGen(Program program)
  {
    super(program);
  }

  public String getPassName()
  {
    return new String("[ompGen]");
  }

	public void start()
	{
		DepthFirstIterator iter = new DepthFirstIterator(program);
		LinkedList<ForLoop> loops = iter.getList(ForLoop.class);

		for (ForLoop loop : loops)
		{
			genOmpParallelLoops(loop);
		}
	}

	private void genOmpParallelLoops(ForLoop loop)
	{
		// currently, we check only omp parallel for construct
		if ( !loop.containsAnnotation(CetusAnnotation.class, "parallel") )
			return;

		// if the loop already contains an OpenMP parallel construct,
		// return
		if ( loop.containsAnnotation(OmpAnnotation.class, "for") )
			return;

		OmpAnnotation omp_annot = new OmpAnnotation();
		List<CetusAnnotation> cetus_annots =
				loop.getAnnotations(CetusAnnotation.class);

		for ( CetusAnnotation cetus_annot : cetus_annots )
			omp_annot.putAll(cetus_annot);

		omp_annot.put("for", "true");
		loop.annotateBefore(omp_annot);
	}
}
