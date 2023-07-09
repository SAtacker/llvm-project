#include "PRUInstrInfo.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "PRUGenInstrInfo.inc"

using namespace llvm;

void PRUInstrInfo::anchor() {}

PRUInstrInfo::PRUInstrInfo()
    : PRUGenInstrInfo(PRU::ADJCALLSTACKDOWN,
                           PRU::ADJCALLSTACKUP) {}
