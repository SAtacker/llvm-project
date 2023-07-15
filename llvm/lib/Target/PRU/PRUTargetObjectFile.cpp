#include "PRUTargetObjectFile.h"
#include "llvm/BinaryFormat/Dwarf.h"
#include "llvm/CodeGen/MachineModuleInfoImpls.h"
#include "llvm/CodeGen/TargetLowering.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

void PRUTargetObjectFile::Initialize(MCContext &Ctx,
                                          TargetMachine const &TM) {
  TargetLoweringObjectFileELF::Initialize(Ctx, TM);
}