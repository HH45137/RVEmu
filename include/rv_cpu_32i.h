#pragma once

#include <iostream>
#include <string>

#include "rv_registers_32i.h"


namespace RVEMU {
    class CCpu32I {
    private:
        SRegisters32I registers{};

    public:
        void Init();

        void Run(std::string exeFilename);

        void Stop();

    };
}
