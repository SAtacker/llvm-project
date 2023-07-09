#include "PRUISelDagToDag.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

PRUDAGToDAGISel::PRUDAGToDAGISel(PRUTargetMachine &TM,
                                           CodeGenOpt::Level OL)
    : SelectionDAGISel(TM, OL), Subtarget(nullptr) {}

StringRef PRUDAGToDAGISel::getPassName() const {
  return "PRU DAG->DAG Pattern Instruction Selection";
}

void PRUDAGToDAGISel::Select(SDNode *N) {
  if (N->isMachineOpcode()) {
    N->setNodeId(-1);
    return;
  }

  SelectCode(N);
}