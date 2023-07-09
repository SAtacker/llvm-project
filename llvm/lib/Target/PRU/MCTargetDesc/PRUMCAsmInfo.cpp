#include "llvm/ADT/Triple.h"
#include "PRUMCAsmInfo.h"

using namespace llvm;

void PRUMCAsmInfo::anchor() {}

PRUMCAsmInfo::PRUMCAsmInfo(Triple const &T) {
  AlignmentIsInBytes = true;
  Data16bitsDirective = "\t.word\t";
  PrivateGlobalPrefix = "$";
  PrivateLabelPrefix = "$";
  CommentString = "#";
  SupportsDebugInformation = true;
  DwarfRegNumForCFI = true;
} // end of namespace llvm
