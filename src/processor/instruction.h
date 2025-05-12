#pragma once
#include <bitset>

#include "../logger/logger.h"

namespace RVEmu::Processor
{
    enum instr_name_e
    {
        add,
        sub,
        addi
    };

    enum instr_type_e
    {
        R,
        I,
        S,
        B,
        U,
        J
    };

    struct instr_base_s
    {
        instr_type_e type{};
        uint8_t opcode{}; // 7 bits (0x7F)
    };

    struct instr_r_s : instr_base_s
    {
        uint8_t rd{}; // 5 bits (0x1F)
        uint8_t funct3{}; // 3 bits (0x07)
        uint8_t rs1{}; // 5 bits (0x1F)
        uint8_t rs2{}; // 5 bits (0x1F)
        uint8_t funct7{}; // 7 bits (0x7F)

        void init(const uint32_t instr)
        {
            type = instr_type_e::R;
            opcode = instr & 0x7F;

            rd = (instr >> 7) & 0x1F;
            funct3 = (instr >> 12) & 0x07;
            rs1 = (instr >> 15) & 0x1F;
            rs2 = (instr >> 20) & 0x1F;
            funct7 = (instr >> 25) & 0x7F;
            return;
        }

        instr_r_s(const uint32_t instr)
        {
            init(instr);
        }
    };

    struct instr_i_s : instr_base_s
    {
        uint8_t rd{}; // 5 bits (0x1F)
        uint8_t funct3{}; // 3 bits (0x07)
        uint8_t rs1{}; // 5 bits (0x1F)
        int16_t imm{}; // 12 bits (expand to 16 bits)

        void init(const uint32_t instr)
        {
            type = instr_type_e::I;
            opcode = instr & 0x7F;

            rd = (instr >> 7) & 0x1F;
            funct3 = (instr >> 12) & 0x07;
            rs1 = (instr >> 15) & 0x1F;
            imm = (instr >> 20) & 0xFFF;
            imm = (imm << 4) >> 4;
            return;
        }

        instr_i_s(const uint32_t instr)
        {
            init(instr);
        }
    };

    class instruction
    {
    public:
        instruction() = default;

        bool executeInstruction(const instr_base_s* instr);

    private:
        void executeInstruction_R(instr_r_s* instr);

        void executeInstruction_I(instr_i_s* instr);
    };
}
