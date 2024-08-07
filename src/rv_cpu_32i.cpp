#include "rv_cpu_32i.h"
#include "common/log_sys.h"


namespace RVEMU {
    void CCpu32I::Init() {
        LogSys::Log("Initial this RISC-V CPU, ISA type is RV32I");
    }

    void CCpu32I::Run(std::string exeFilename) {
        LogSys::Log("Run this CPU");
    }

    void CCpu32I::Stop() {
        LogSys::Log("Stop this CPU");
    }
}