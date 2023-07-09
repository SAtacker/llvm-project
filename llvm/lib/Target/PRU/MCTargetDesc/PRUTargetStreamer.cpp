#include "MCTargetDesc/PRUTargetStreamer.h"

using namespace llvm;

PRUTargetStreamer::PRUTargetStreamer(MCStreamer &S)
    : MCTargetStreamer(S) {}

PRUTargetAsmStreamer::PRUTargetAsmStreamer(MCStreamer &S,
                                                     formatted_raw_ostream &OS)
    : PRUTargetStreamer(S), OS(OS) {}
