#ifndef PRUTARGETOBJECTFILE_H_INCLUDED
#define PRUTARGETOBJECTFILE_H_INCLUDED

#include "PRUTargetMachine.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"

namespace llvm {

class PRUTargetMachine;

class PRUTargetObjectFile : public TargetLoweringObjectFileELF {
  PRUTargetMachine const *TM;

public:
  void Initialize(MCContext &Ctx, TargetMachine const &TM) override;
};

} // namespace llvm

#endif