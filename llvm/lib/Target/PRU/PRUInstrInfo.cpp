#include "PRUInstrInfo.h"
#include "PRU.h"
#include "PRURegisterInfo.h"
#include "PRUTargetMachine.h"
#include "MCTargetDesc/PRUMCTargetDesc.h"

#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "PRUGenInstrInfo.inc"

using namespace llvm;

PRUInstrInfo::PRUInstrInfo()
    : PRUGenInstrInfo(PRU::ADJCALLSTACKDOWN,
                           PRU::ADJCALLSTACKUP), RI() {}
