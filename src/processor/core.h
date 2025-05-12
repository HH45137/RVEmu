#pragma once

#include <array>
#include "cache.h"
#include "instruction.h"

namespace RVEmu::Processor {

constexpr size_t NUM_REGISTERS = 32;

class Core {
public:
    Core(size_t cacheLineSize, size_t cacheSize);

    // Register accessors
    void setRegister(size_t regIndex, Register value);
    Register getRegister(size_t regIndex) const;

    // Program Counter (PC) accessors
    void setPC(Register value);
    Register getPC() const;

    // Interrupt Request (IRQ) accessors
    void setIRQ(Register value);
    Register getIRQ() const;

    // Cache accessors
    void writeToCache(Register address, const std::vector<uint8_t>& data);
    std::vector<uint8_t> readFromCache(Register address) const;

private:
    std::array<Register, NUM_REGISTERS> m_registers;
    Register m_pc;
    Register m_irq;
    Cache m_cache;
};

} // namespace RVEmu::CPU
