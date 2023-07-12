#ifndef PRUINSTRINFO_H_INCLUDED
#define PRUINSTRINFO_H_INCLUDED

#include "PRURegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "PRUGenInstrInfo.inc"

namespace llvm {

class PRUInstrInfo : public PRUGenInstrInfo {
const PRURegisterInfo RI;
public:
  explicit PRUInstrInfo();

   const PRURegisterInfo &getRegisterInfo() const { return RI; }
  // TODO
  
 
};

} // namespace llvm

#endif