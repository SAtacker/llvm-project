#ifndefined PRUINSTRINFO_H_INCLUDED
#define PRUINSTRINFO_H_INCLUDED

#include "PRU.h"
#include "PRURegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "PRUGenInstrInfo.inc"

namespace llvm {

class PRUInstrInfo : public PRUGenInstrInfo {
  virtual void anchor();

public:
  PRUInstrInfo();

  // TODO
};

} // namespace llvm

#endif