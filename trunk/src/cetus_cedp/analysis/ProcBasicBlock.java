package cetus.analysis;

import java.util.*;

import cetus.hir.*;

public class ProcBasicBlock extends BasicBlock {
  BasicBlock entryBB,exitBB,cloneentryBB,cloneexitBB ;
  public ProcBasicBlock() {
    entryBB = new BasicBlock();
    exitBB = new BasicBlock();
  }

  public void addPredecessor(BasicBlock bb) {
    entryBB.addPredecessor(bb);
  }

  public void addSuccessor(BasicBlock bb) {
    exitBB.addSuccessor(bb);
  }
/*
  JAS: broken
  public ProcBasicBlock clonepbb(){
    ProcBasicBlock newpbb = new ProcBasicBlock();
    cloneentryBB = newpbb.entryBB;
    cloneexitBB = newpbb.exitBB;
    ArrayList<BasicBlock> l_arr = entryBB.preds;
    for(int i=0;i<l_arr.size();i++){
      BasicBlock l_bb = l_arr.get(i);
      BasicBlock l_newbb = depthfirstclone(l_bb);
    }
    return newpbb ;
  }
*/
  public BasicBlock depthfirstclone(BasicBlock p_bb){
    int i;
    BasicBlock newbb = new BasicBlock();
    newbb.statements = new ArrayList<Statement>();
    //Copy over the compoundstatement
    List<Statement> l_li = p_bb.statements;
    for (i=0;i<l_li.size();i++) {
      newbb.statements.set(i,l_li.get(i));
    }
    ArrayList<BasicBlock> l_ar = p_bb.succs ;
    for (i=0;i<l_ar.size();i++){
      BasicBlock l_b = l_ar.get(i);
      if (l_b == exitBB)
        newbb.addSuccessor(cloneexitBB);
      else if (l_b == null)
        newbb.addSuccessor(null);
        else newbb.addSuccessor(depthfirstclone(l_b));
    }

    return newbb ;
  }
}
