//===-- AVRInstPrinter.cpp - Convert AVR MCInst to assembly syntax --------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints an AVR MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#include "PRUInstPrinter.h"

#include "MCTargetDesc/AVRMCTargetDesc.h"

#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrDesc.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/raw_ostream.h"

#include <cstring>

#define DEBUG_TYPE "asm-printer"


// This `using` must be inserted before the following #include because
// PRUGenAsmWriter.inc assumes it
using namespace llvm;

#define PRINT_ALIAS_INSTR
#include "PRUGenAsmWriter.inc"

PRUInstPrinter::PRUInstPrinter(MCAsmInfo const &MAI,
                                         MCInstrInfo const &MII,
                                         MCRegisterInfo const &MRI)
    : MCInstPrinter(MAI, MII, MRI) {}

void PRUInstPrinter::printInst(MCInst const *MI, uint64_t Address,
                                    StringRef Annot, MCSubtargetInfo const &STI,
                                    raw_ostream &O) {
  if (!printAliasInstr(MI, Address, O)) {
    printInstruction(MI, Address, O);
  }
  printAnnotation(O, Annot);
}

void PRUInstPrinter::printRegName(raw_ostream &OS, unsigned RegNo) const {
  OS << StringRef(getRegisterName(RegNo)).lower();
}

void PRUInstPrinter::printOperand(MCInst const *MI, unsigned OpNo,
                                       raw_ostream &OS) {
  MCOperand const &Op = MI->getOperand(OpNo);
  if (Op.isReg()) {
    printRegName(OS, Op.getReg());
    return;
  }

  if (Op.isImm()) {
    OS << Op.getImm();
    return;
  }

  assert(Op.isExpr() && "unknown operand kind in printOperand");
  Op.getExpr()->print(OS, &MAI, true);
}

void PRUInstPrinter::printOperand(MCInst const *MI, uint64_t _Address,
                                       unsigned OpNum, raw_ostream &O) {
  printOperand(MI, OpNum, O);
}