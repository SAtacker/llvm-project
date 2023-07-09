#ifndefined PRUFRAMELOWERING_H_INCLUDED
#define PRUFRAMELOWERING_H_INCLUDED

#include "PRU.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {

class PRUSubtarget;

class PRUFrameLowering : public TargetFrameLowering {
protected:
  const PRUSubtarget &STI;

public:
  explicit PRUFrameLowering(const PRUSubtarget &sti);

  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  bool hasFP(const MachineFunction &MF) const override;
  MachineBasicBlock::iterator
  eliminateCallFramePseudoInstr(MachineFunction &MF, MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator I) const override;
};

} // namespace llvm

#endif