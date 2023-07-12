#if !defined MCTARGETDESC_MCTARGETDESC_H_INCLUDED
#define MCTARGETDESC_MCTARGETDESC_H_INCLUDED

#include "llvm/MC/MCTargetOptions.h"
#include "llvm/Support/DataTypes.h"

#include <memory>

namespace llvm {

class MCCodeEmitter;
class MCInstrInfo;
class MCContext;

MCCodeEmitter *createPRUMCCodeEmitter(const MCInstrInfo &MCII,
                                        MCContext &Ctx);
class Target;

Target &getThePRUTarget();

} // namespace llvm

#define GET_REGINFO_ENUM
#include "PRUGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "PRUGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM


#endif