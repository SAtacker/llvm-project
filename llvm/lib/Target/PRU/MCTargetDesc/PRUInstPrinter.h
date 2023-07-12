#ifndef MCTARGETDESC_PRUINSTPRINTER_H_INCLUDED
#define MCTARGETDESC_PRUINSTPRINTER_H_INCLUDED

#include "llvm/MC/MCInstPrinter.h"

namespace llvm {

class TargetMachine;

class PRUInstPrinter : public MCInstPrinter {
public:
  PRUInstPrinter(MCAsmInfo const &MAI, MCInstrInfo const &MII,
                      MCRegisterInfo const &MRI);

  void printInst(MCInst const *MI, uint64_t Address, StringRef Annot,
                 MCSubtargetInfo const &STI, raw_ostream &O) override;
  void printRegName(raw_ostream &OS, MCRegister Reg) const;
  void printOperand(MCInst const *MI, unsigned OpNo, raw_ostream &O);
  void printOperand(MCInst const *MI, uint64_t _Address, unsigned OpNum,
                    raw_ostream &O);

  // These member functions are generated in PRUGenAsmWriter.inc
  std::pair<char const *, uint64_t> getMnemonic(MCInst const *MI) override;
  void printInstruction(MCInst const *MI, uint64_t Address, raw_ostream &OS);
  static char const *getRegisterName(MCRegister Reg);
  bool printAliasInstr(MCInst const *MI, uint64_t Address, raw_ostream &OS);
};

} // namespace llvm

#endif 