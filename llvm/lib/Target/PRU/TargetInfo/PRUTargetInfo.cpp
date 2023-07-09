#include "PRU.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getThePRUTarget() {
  static Target ThePRUTarget;
  return ThePRUTarget;
}
extern "C" void LLVMInitializePRUTargetInfo() {
  RegisterTarget<Triple::PRU, true> X(
      getThePRU32Target(), "PRU", "PRU (32-bit)", "PRU");
