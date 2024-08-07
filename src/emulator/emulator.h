#pragma once

#include "../processor/cpu.h"
#include "../logger/logger.h"

namespace RVEmu {

class Emulator {
public:
    Emulator(int numCores, size_t cacheLineSize, size_t cacheSize, size_t sharedMemorySize);

    void initialize();

    void run();

    Processor::CPU& getCPU();

private:
    Processor::CPU m_cpu;
    Logger m_logger;
};

} // namespace RVEmu
