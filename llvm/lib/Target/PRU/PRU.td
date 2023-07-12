include "llvm/Target/Target.td"

include "PRURegisterInfo.td"
include "PRUInstrInfo.td"
include "PRUCallingConv.td"
include "PRUSchedule.td"

def PRUInstrInfo : InstrInfo;

def PRU : Target {
  let InstructionSet = PRUInstrInfo;
}
