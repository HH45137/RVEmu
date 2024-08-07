#pragma once

#include <unordered_map>
#include <vector>
#include <cstdint>
#include <cstddef>

namespace RVEmu::Processor {

using Register = uint32_t;

class Cache {
public:
    Cache(size_t lineSize, size_t cacheSize);

    void write(Register address, const std::vector<uint8_t>& data);
    std::vector<uint8_t> read(Register address) const;

private:
    size_t m_lineSize;
    size_t m_cacheSize;
    std::unordered_map<Register, std::vector<uint8_t>> m_lines;
};

} // namespace RVEmu::CPU
