#if !defined MCTARGETDESC_MCTARGETDESC_H_INCLUDED
#define MCTARGETDESC_MCTARGETDESC_H_INCLUDED

#include "llvm/MC/MCTargetOptions.h"
#include "llvm/Support/DataTypes.h"

namespace llvm {

class Target;

Target &getThePRUTarget();

} // namespace llvm

#define GET_REGINFO_ENUM
#include "PRUGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "PRUGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "PRUGenSubtargetInfo.inc"

#endif