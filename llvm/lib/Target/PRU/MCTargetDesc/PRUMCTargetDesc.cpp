#include "PRUMCTargetDesc.h"
#include "PRUMCAsmInfo.h"
#include "MCTargetDesc/PRUMCCodeEmitter.h"
#include "MCTargetDesc/PRUInstPrinter.h"
#include "MCTargetDesc/PRUMCAsmInfo.h"
#include "MCTargetDesc/PRUTargetStreamer.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/MachineLocation.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"

#define GET_INSTRINFO_MC_DESC
#include "PRUGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC

#define GET_REGINFO_MC_DESC
#include "PRUGenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createPRUMCInstrInfo() {
  MCInstrInfo *I = new MCInstrInfo();
  // This function is generated in PRUGenInstrInfo.inc
  InitPRUMCInstrInfo(I);
  return I;
}

static MCRegisterInfo *createPRUMCRegisterInfo(Triple const &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  // This function is generated in PRUGenRegisterInfo.inc
  InitPRUMCRegisterInfo(X, 0);
  return X;
}

static MCSubtargetInfo *
createPRUMCSubtargetInfo(Triple const &TT, StringRef CPU, StringRef FS) {
  // This function is generated in PRUGenSubtargetInfo.inc
  return createPRUMCSubtargetInfo(TT, CPU, FS);
}

static MCInstrAnalysis *createPRUMCInstrAnalysis(const MCInstrInfo *Info) {
  return new MCInstrAnalysis(Info);
}

static MCInstPrinter *createPRUMCInstPrinter(Triple const &T,
                                                  unsigned SyntaxVariant,
                                                  MCAsmInfo const &MAI,
                                                  MCInstrInfo const &MII,
                                                  MCRegisterInfo const &MRI) {
  return new PRUInstPrinter(MAI, MII, MRI);
}

static MCTargetStreamer *
createPRUAsmTargetStreamer(MCStreamer &S, formatted_raw_ostream &OS,
                                MCInstPrinter *_InstPrint, bool _isVerboseAsm) {
  return new PRUTargetAsmStreamer(S, OS);
}

static void initializeTarget(Target &T) {
  RegisterMCAsmInfo<PRUMCAsmInfo> X(T);
  TargetRegistry::RegisterMCInstrInfo(T, createPRUMCInstrInfo);
  TargetRegistry::RegisterMCRegInfo(T, createPRUMCRegisterInfo);
  TargetRegistry::RegisterMCSubtargetInfo(T, createPRUMCSubtargetInfo);
  TargetRegistry::RegisterMCInstrAnalysis(T, createPRUMCInstrAnalysis);
  TargetRegistry::RegisterMCInstPrinter(T, createPRUMCInstPrinter);
  TargetRegistry::RegisterAsmTargetStreamer(T, createPRUAsmTargetStreamer);
  // TODO: TargetRegistry::RegisterObjectTargetStreamer
  TargetRegistry::RegisterMCCodeEmitter(T, createPRUMCCodeEmitter);
}

// This function will be called by llc via C preprocessor
extern "C" void LLVMInitializePRUTargetMC() {
  initializeTarget(getThePRUTarget());

}
