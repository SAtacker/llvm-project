#include "PRUTargetMachine.h"
#include "PRU.h"
#include "PRUTargetMachine.h"
#include "PRUSubtarget.h"
#include "MCTargetDesc/PRUMCTargetDesc.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define PASS_NAME "PRU DAG->DAG Instruction Selection"

namespace {
class PRUDAGToDAGISel : public SelectionDAGISel {
public:
  static char ID;

 PRUDAGToDAGISel() = delete;
 explicit PRUDAGToDAGISel(PRUTargetMachine &tm) : SelectionDAGISel(ID, tm), Subtarget(nullptr) {}

 #include "PRUGenDAGISel.inc"

 void Select(SDNode *N) override;

 const PRUSubtarget *Subtarget;

  };
}

void PRUDAGToDAGISel::Select(SDNode *N) {
  SelectCode(N);
}