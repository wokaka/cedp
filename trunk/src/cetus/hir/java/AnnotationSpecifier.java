/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cetus.hir.java;

import cetus.hir.Specifier;

/**
 *
 * @author yim
 */
public class AnnotationSpecifier extends Specifier {

    protected String name;

    public AnnotationSpecifier()
    {
        super(41);
    }
    
    public AnnotationSpecifier(String n)
    {
        super(41);
        name = n;
    }

    public void SetName(String n)
    {
        name = n;
    }
}
