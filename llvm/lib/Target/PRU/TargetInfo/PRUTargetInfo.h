#ifndefined PRUTARGETINFO_H_INCLUDED
#define PRUTARGETINFO_H_INCLUDED

namespace llvm {

class Target;

Target &getThePRUTarget();

}
#endif