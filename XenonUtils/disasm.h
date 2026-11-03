#pragma once
#include <cstddef>
#include <cstdint>
#include <ppc_decoder.h>
#include <ppc-inst.h>

namespace ppc
{
    // The PowerPC decoder is the host project's own (ppc_decoder.h); it fills the same ppc_insn as before.
    static int Disassemble(const void* code, size_t size, uint64_t base, ppc_insn& out)
    {
        if (size < 4)
        {
            return 0;
        }

        const uint8_t* bytes = static_cast<const uint8_t*>(code);
        const uint32_t word = uint32_t(bytes[0]) << 24 | uint32_t(bytes[1]) << 16 | uint32_t(bytes[2]) << 8 | bytes[3];
        return DecodeWord(word, base, out);
    }

    static int Disassemble(const void* code, uint64_t base, ppc_insn& out)
    {
        return Disassemble(code, 4, base, out);
    }

    static int Disassemble(const void* code, uint64_t base, ppc_insn* out, size_t nOut);
}
