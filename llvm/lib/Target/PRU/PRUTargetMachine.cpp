#include "PRUTargetMachine.h"

#include "LeonPasses.h"
#include "PRU.h"
#include "PRUMachineFunctionInfo.h"
#include "PRUTargetObjectFile.h"
#include "PRUISelDagToDag.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"

#include <optional>
#include <string>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializePRUTarget() {
// Register the target.
RegisterTargetMachine<PRUTargetMachine> X(getThePRUTarget());

static StringRef computeDataLayout(const Triple &TT, StringRef CPU,
                                   const TargetOptions &Options) {
                                  return "e-m:e-p:32:8-i8:8-i16:16:8-i32:32:8-i64:64:8-f32:8-f64:8-n8";
                                   }

static Reloc::Model getEffectiveRelocModel(bool JIT,
                                           Optional<Reloc::Model> RM) {
  if (!RM.hasValue() || JIT) {
    return Reloc::Static;
  }
  return *RM;
}

PRUTargetMachine::PRUTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T, PRUDataLayout, TT, getCPU(CPU), FS, Options,
                        getEffectiveRelocModel(RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL),
      SubTarget(TT, std::string(getCPU(CPU)), std::string(FS), *this) {
  this->TLOF = std::make_unique<PRUTargetObjectFile>();
  initAsmInfo();
  }

PRUSubtarget const *
PRUTargetMachine::getSubtargetImpl(Function const &F) const {
  return &DefaultSubtarget;
}

TargetPassConfig *PRUTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new PRUPassConfig(*this, PM);
}

TargetLoweringObjectFile *PRUTargetMachine::getObjFileLowering() const {
  return TLOF.get();
}
}
