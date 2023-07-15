#ifndef PRUISELLOWERING_H_INCLUDED
#define PRUISELLOWERING_H_INCLUDED

#include "PRU.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class PRUSubtarget;
class PRUTargetMachine;

class PRUTargetLowering : public TargetLowering {

public:
  PRUTargetLowering(const PRUTargetMachine &TM,
                         const PRUSubtarget &STI);
  SDValue LowerFormalArguments(SDValue Chain, CallingConv::ID CallConv,
                               bool IsVarArg,
                               SmallVectorImpl<ISD::InputArg> const &Ins,
                               SDLoc const &dl, SelectionDAG &DAG,
                               SmallVectorImpl<SDValue> &InVals) const override;

  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
                      SmallVectorImpl<ISD::OutputArg> const &Outs,
                      SmallVectorImpl<SDValue> const &OutVals, SDLoc const &dl,
                      SelectionDAG &DAG) const override;


  protected:
  const PRUSubtarget &Subtarget;
};

} // namespace llvm

#endif