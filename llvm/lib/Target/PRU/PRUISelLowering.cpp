#include "PRUISelLowering.h"
#include "PRUTargetMachine.h"

#include "PRUGenCallingConv.inc"

using namespace llvm;

PRUTargetLowering::PRUTargetLowering(PRUTargetMachine const &TM,
                                               PRUSubtarget const &STI)
    : TargetLowering(TM), Subtarget(STI) {
  // TODO
}

SDValue PRUTargetLowering::LowerFormalArguments(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    SmallVectorImpl<ISD::InputArg> const &Ins, SDLoc const &dl,
    SelectionDAG &DAG, SmallVectorImpl<SDValue> &InVals) const {
  // TODO
  return Chain;
}

SDValue
PRUTargetLowering::LowerReturn(SDValue Chain, CallingConv::ID CallConv,
                                    bool IsVarArg,
                                    SmallVectorImpl<ISD::OutputArg> const &Outs,
                                    SmallVectorImpl<SDValue> const &OutVals,
                                    SDLoc const &dl, SelectionDAG &DAG) const {
  // TODO
  return Chain;
}