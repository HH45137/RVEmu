#include "emulator.h"

namespace RVEmu {

Emulator::Emulator(int numCores, size_t cacheLineSize, size_t cacheSize, size_t sharedMemorySize)
    : m_cpu(numCores, cacheLineSize, cacheSize, sharedMemorySize), m_logger("Emulator") {}

void Emulator::initialize() {
    m_logger.info("Initializing Emulator");
}

void Emulator::run() {
    m_logger.info("Running Emulator");
}

Processor::CPU& Emulator::getCPU() {
    return m_cpu;
}

} // namespace RVEmu
