add_llvm_component_group(PRU)
set(LLVM_TARGET_DEFINITIONS PRU.td)

tablegen(LLVM PRUGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM PRUGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM PRUGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM PRUGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM PRUGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM PRUGenCallingConv.inc -gen-callingconv)
tablegen(LLVM PRUGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(PRUCommonTableGen)

add_llvm_target(PRUCodeGen
    PRUTargetMachine.cpp
    PRUFrameLowering.cpp
    PRUISelLowering.cpp
    PRURegisterInfo.cpp
    PRUSubtarget.cpp
    PRUInstrInfo.cpp
    PRUTargetObjectFile.cpp
    PRUAsmPrinter.cpp
    PRUISelDagToDag.cpp
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)



