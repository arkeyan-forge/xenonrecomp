project("XenonUtils")

add_library(XenonUtils
    "disasm.cpp" 
    "xex.cpp" 
    "image.cpp" 
    "xdbf_wrapper.cpp"
    "xex_patcher.cpp"
    "memory_mapped_file.cpp"
    "${THIRDPARTY_ROOT}/libmspack/libmspack/mspack/lzxd.c"
    "${THIRDPARTY_ROOT}/tiny-AES-c/aes.c"
)

target_compile_definitions(XenonUtils
    PRIVATE
        NOMINMAX
)

target_include_directories(XenonUtils 
    PUBLIC
        .
        "${THIRDPARTY_ROOT}/simde"
    PRIVATE
        "${THIRDPARTY_ROOT}/libmspack/libmspack/mspack"
        "${THIRDPARTY_ROOT}/tiny-AES-c"
        "${THIRDPARTY_ROOT}/TinySHA1"
)

# The PowerPC decoder is the host project's own (ARKEYAN_PPC_DECODER_DIR): binutils' disassembler is not built.
if (NOT ARKEYAN_PPC_DECODER_DIR)
    message(FATAL_ERROR "ARKEYAN_PPC_DECODER_DIR: the directory of ppc_decoder.cpp")
endif()
target_sources(XenonUtils PRIVATE "${ARKEYAN_PPC_DECODER_DIR}/ppc_decoder.cpp")
# ppc-inst.h only: the instruction ids the recompiler switches on.
target_include_directories(XenonUtils PUBLIC "${ARKEYAN_PPC_DECODER_DIR}" "${THIRDPARTY_ROOT}/disasm")
