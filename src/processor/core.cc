#include "core.h"
#include <stdexcept>

namespace RVEmu::Processor {

Core::Core(size_t cacheLineSize, size_t cacheSize)
    : m_pc(0), m_irq(0), m_cache(cacheLineSize, cacheSize) {
    m_registers.fill(0);
}

void Core::setRegister(size_t regIndex, Register value) {
    if (regIndex >= NUM_REGISTERS) {
        throw std::out_of_range("Register index out of range");
    }
    m_registers[regIndex] = value;
}

Register Core::getRegister(size_t regIndex) const {
    if (regIndex >= NUM_REGISTERS) {
        throw std::out_of_range("Register index out of range");
    }
    return m_registers[regIndex];
}

void Core::setPC(Register value) {
    m_pc = value;
}

Register Core::getPC() const {
    return m_pc;
}

void Core::setIRQ(Register value) {
    m_irq = value;
}

Register Core::getIRQ() const {
    return m_irq;
}

void Core::writeToCache(Register address, const std::vector<uint8_t>& data) {
    m_cache.write(address, data);
}

std::vector<uint8_t> Core::readFromCache(Register address) const {
    return m_cache.read(address);
}

} // namespace RVEmu::CPU
