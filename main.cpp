#include <iostream>

#include <rv_cpu_32i.h>


int main() {
    RVEMU::CCpu32I cpu{};

    cpu.Init();
    cpu.Run("");
    cpu.Stop();

    return 0;
}
