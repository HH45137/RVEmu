#pragma once

#include <vector>
#include <mutex>
#include <array>
#include "core.h"
#include "../logger/logger.h"

namespace RVEmu::Processor {

constexpr size_t NUM_SHARED_REGISTERS = 8;

class CPU {
public:
    CPU(int numCores, size_t cacheLineSize, size_t cacheSize, size_t sharedMemorySize);

    // Core accessors
    Core& getCore(int coreIndex);
    const Core& getCore(int coreIndex) const;

    // Shared Register accessors
    void setSharedRegister(size_t regIndex, Register value);
    Register getSharedRegister(size_t regIndex) const;

    // Shared Memory accessors
    void writeToSharedMemory(Register address, uint8_t value);
    uint8_t readFromSharedMemory(Register address) const;

private:
    std::vector<Core> m_cores;
    std::array<Register, NUM_SHARED_REGISTERS> m_sharedRegisters;
    std::vector<uint8_t> m_sharedMemory;
    mutable std::mutex m_sharedMemoryMutex;
    mutable std::mutex m_sharedRegisterMutex;
    Logger m_logger;
};

} // namespace RVEmu::CPU
