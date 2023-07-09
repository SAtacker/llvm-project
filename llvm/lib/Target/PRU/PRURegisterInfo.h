#if !defined PRUREGISTERINFO_H_INCLUDED
#define PRUREGISTERINFO_H_INCLUDED

#include "PRU.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "PRUGenRegisterInfo.inc"

namespace llvm {

class PRUSubtarget;

struct PRURegisterInfo : public PRUGenRegisterInfo {
  const TOYRISCVSubtarget &Subtarget;
  PRURegisterInfo(PRUSubtarget const &ST)

  MCPhysReg const *getCalleeSavedRegs(MachineFunction const *MF) const override;
  uint32_t const *getCallPreservedMask(MachineFunction const &MF,
                                       CallingConv::ID) const override;
  void eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;
  Register getFrameRegister(MachineFunction const &MF) const override;
};

} // namespace llvm

#endif 
