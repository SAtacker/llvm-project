#ifndef MCTARGETDESC_PRUMCASMINFO_H_INCLUDED
#define MCTARGETDESC_PRUMCASMINFO_H_INCLUDED


#include "llvm/MC/MCAsmInfo.h"

namespace llvm {

class Triple;

/// Specifies the format of AVR assembly files.
class PRUMCAsmInfo : public MCAsmInfo {

public:
  explicit PRUMCAsmInfo(const Triple &TT, const MCTargetOptions &Options);
};

} // end namespace llvm

#endif 
