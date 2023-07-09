#ifndefined MCTARGETDESC_PRUMCASMINFO_H_INCLUDED
#define MCTARGETDESC_PRUMCASMINFO_H_INCLUDED


#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

/// Specifies the format of AVR assembly files.
class AVRMCAsmInfo : public MCAsmInfo {
  void anchor() override;

public:
  explicit AVRMCAsmInfo(const Triple &TT, const MCTargetOptions &Options);
};

} // end namespace llvm

#endif 
