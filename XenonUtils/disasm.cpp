#include "disasm.h"

int ppc::Disassemble(const void* code, uint64_t base, ppc_insn* out, size_t nOut)
{
    for (size_t i = 0; i < nOut; i++)
    {
        Disassemble(static_cast<const uint32_t*>(code) + i, base, out[i]);
    }
    return static_cast<int>(nOut) * 4;
}
