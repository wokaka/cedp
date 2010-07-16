package cetus.analysis;

import cetus.hir.*;

import java.util.*;

/**
 * Any class implementing this interface represents a Dependence testing algorithm
 * and provides the common functionality that these tests use to interface with the
 * dependence test wrapper.
 */
public interface DDTest
{
	/**
	 * Runs the dependence test on a direction vector
	 * @param pair Subscript pair for which dependence needs to be tested
	 * @param dv The dependence vector under which test needs to be performed
	 * @return whether dependence exists or not
	 */
	boolean testDependence(DependenceVector dv);
	
	/**
	 * Returns whether the constructor for the dependence test determined
	 * whether it would be eligible to run the test on the pair of
	 * subscripts or not
	 * @return
	 */
	boolean isTestEligible();
	
	/**
	 * Returns a list of loops from outermost to innermost that are common to the
	 * two expressions being tested for dependence, whether they are a pair of subscripts
	 * or a pair of whole array accesses
	 * @return
	 */
	LinkedList<Loop> getCommonEnclosingLoops();
}

