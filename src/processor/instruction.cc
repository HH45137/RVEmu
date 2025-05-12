#include "instruction.h"

namespace RVEmu::Processor
{
    bool instruction::executeInstruction(const instr_base_s* instr)
    {
        switch (instr->type)
        {
        case R:
            {
                auto* temp_instr = (instr_r_s*)instr;
                executeInstruction_R(temp_instr);
                break;
            }
        case I:
            {
                auto* temp_instr = (instr_i_s*)instr;
                executeInstruction_I(temp_instr);
                break;
            }
        default:
            return false;
        }

        return true;
    }

    void instruction::executeInstruction_R(instr_r_s* instr)
    {
        std::cout
            << instr->type
            << instr->opcode
            << instr->rd
            << instr->rs1
            << std::endl;
    }

    void instruction::executeInstruction_I(instr_i_s* instr)
    {
        std::cout << "type:    " << instr->type << "\n"
            << "opcode:  " << std::dec << static_cast<int>(instr->opcode)
            << " (0b" << std::bitset<7>(instr->opcode)
            << ", 0x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(instr->opcode) << ")\n"
            << "rd:      " << std::dec << static_cast<int>(instr->rd)
            << " (0b" << std::bitset<5>(instr->rd)
            << ", 0x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(instr->rd) << ")\n"
            << "rs1:     " << std::dec << static_cast<int>(instr->rs1)
            << " (0b" << std::bitset<5>(instr->rs1)
            << ", 0x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(instr->rs1) << ")\n"
            << "imm:     " << std::dec << static_cast<int>(instr->imm)
            << " (0b" << std::bitset<12>(instr->imm)
            << ", 0x" << std::setw(3) << std::setfill('0') << std::hex << static_cast<int>(instr->imm) << ")\n"
            << std::endl;
    }
}
