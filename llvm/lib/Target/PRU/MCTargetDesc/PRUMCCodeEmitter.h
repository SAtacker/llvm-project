#define PRUCODEEMITTER_H_INCLUDED

#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/Support/DataTypes.h"

namespace llvm {
class MCInstrInfo;
class MCContext;
class MCFixup;
class raw_ostream;

class PRUMCCodeEmitter : public MCCodeEmitter {
  MCInstrInfo const &MCII;
  MCContext &Ctx;
  bool IsLittleEndian;

public:
  PRUMCCodeEmitter(MCInstrInfo const &MCII, MCContext &Ctx, bool IsLittle);

  void encodeInstruction(MCInst const &MI, raw_ostream &OS,
                         SmallVectorImpl<MCFixup> &Fixups,
                         MCSubtargetInfo const &STI) const override;
};

} // namespace llvm
