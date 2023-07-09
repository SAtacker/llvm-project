#include "PRUFrameLowering.h"
#include "PRUInstrInfo.h"
#include "PRUSubtarget.h"

using namespace llvm;

PRUFrameLowering::PRUFrameLowering(PRUSubtarget const &sti)
    : TargetFrameLowering(StackGrowsDown, Align(16), 0), STI(sti) {}

void PRUFrameLowering::emitPrologue(MachineFunction &MF,
                                         MachineBasicBlock &MBB) const {
  // TODO
}

void PRUFrameLowering::emitEpilogue(MachineFunction &MF,
                                         MachineBasicBlock &MBB) const {
  // TODO
}

bool PRUFrameLowering::hasFP(const MachineFunction &MF) const {
  // TODO
  return false;
}

MachineBasicBlock::iterator
PRUFrameLowering::eliminateCallFramePseudoInstr(
    MachineFunction &MF, MachineBasicBlock &MBB,
    MachineBasicBlock::iterator I) const {
  // TODO
  return MBB.erase(I);
}