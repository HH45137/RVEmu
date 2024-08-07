#include "cache.h"
#include <stdexcept>

namespace RVEmu::Processor {

Cache::Cache(size_t lineSize, size_t cacheSize)
    : m_lineSize(lineSize), m_cacheSize(cacheSize) {}

void Cache::write(Register address, const std::vector<uint8_t>& data) {
    if (data.size() != m_lineSize) {
        throw std::invalid_argument("Data size does not match cache line size");
    }
    m_lines[address] = data;
}

std::vector<uint8_t> Cache::read(Register address) const {
    auto it = m_lines.find(address);
    if (it != m_lines.end()) {
        return it->second;
    } else {
        throw std::out_of_range("Cache miss");
    }
}

} // namespace RVEmu::Processor
