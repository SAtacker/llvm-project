#include "PRU.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {
Target &getThePRUTarget() {
  static Target ThePRUTarget;
  return ThePRUTarget;
}
}
extern "C" void LLVMInitializePRUTargetInfo() {
  llvm::RegisterTarget<llvm::Triple::pru> X(
      llvm::getThePRUTarget(), "pru", "PRU (32-bit)", "PRU");
}
