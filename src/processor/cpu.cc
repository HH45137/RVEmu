#include "cpu.h"
#include <stdexcept>

namespace RVEmu::Processor {

CPU::CPU(int numCores, size_t cacheLineSize, size_t cacheSize, size_t sharedMemorySize)
    : m_sharedMemory(sharedMemorySize, 0), m_logger("CPU"), m_instr() {
    if (numCores <= 0) {
        throw std::invalid_argument("Number of cores must be positive");
    }

    for (int i = 0; i < numCores; ++i) {
        m_cores.emplace_back(cacheLineSize, cacheSize);
    }

    m_sharedRegisters.fill(0);
    m_logger.info("CPU initialized with %d cores", numCores);
}

Core& CPU::getCore(int coreIndex) {
    if (coreIndex < 0 || static_cast<size_t>(coreIndex) >= m_cores.size()) {
        throw std::out_of_range("Core index out of range");
    }
    return m_cores[coreIndex];
}

const Core& CPU::getCore(int coreIndex) const {
    if (coreIndex < 0 || static_cast<size_t>(coreIndex) >= m_cores.size()) {
        throw std::out_of_range("Core index out of range");
    }
    return m_cores[coreIndex];
}

void CPU::setSharedRegister(size_t regIndex, Register value) {
    std::lock_guard<std::mutex> lock(m_sharedRegisterMutex);
    if (regIndex >= NUM_SHARED_REGISTERS) {
        throw std::out_of_range("Shared register index out of range");
    }
    m_sharedRegisters[regIndex] = value;
}

Register CPU::getSharedRegister(size_t regIndex) const {
    std::lock_guard<std::mutex> lock(m_sharedRegisterMutex);
    if (regIndex >= NUM_SHARED_REGISTERS) {
        throw std::out_of_range("Shared register index out of range");
    }
    return m_sharedRegisters[regIndex];
}

void CPU::writeToSharedMemory(Register address, uint8_t value) {
    std::lock_guard<std::mutex> lock(m_sharedMemoryMutex);
    if (address >= m_sharedMemory.size()) {
        throw std::out_of_range("Shared memory address out of range");
    }
    m_sharedMemory[address] = value;
}

uint8_t CPU::readFromSharedMemory(Register address) const {
    std::lock_guard<std::mutex> lock(m_sharedMemoryMutex);
    if (address >= m_sharedMemory.size()) {
        throw std::out_of_range("Shared memory address out of range");
    }
    return m_sharedMemory[address];
}

void CPU::run()
{
    const auto *instr_addi = new instr_i_s{0x01F00093}; // ADDI x1, x0, 31
    m_instr.executeInstruction(instr_addi);

    const auto *instr_andi = new instr_i_s{0x01437293}; // andi x5, x6, 20
    m_instr.executeInstruction(instr_andi);

    const auto *instr_sub = new instr_r_s{0x407302B3}; // sub x5, x6, x7
    m_instr.executeInstruction(instr_sub);
}
} // namespace RVEmu::CPU
