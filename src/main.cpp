#include "emulator/emulator.h"
#include <iostream>

int main() {
    RVEmu::Logger::addConsoleOutput();
    
    try {
        // Initialize the emulator with 4 cores, cache line size of 64 bytes, cache size of 1024 bytes, and shared memory size of 4096 bytes
        RVEmu::Emulator emulator(4, 64, 1024, 4096);
        emulator.initialize();

        auto& cpu = emulator.getCPU();

        // Set and get register values for core 0
        cpu.getCore(0).setRegister(1, 42);
        std::cout << "Core 0, Register 1: " << cpu.getCore(0).getRegister(1) << std::endl;

        // Set shared register 0 to value 100
        cpu.setSharedRegister(0, 100);
        std::cout << "Shared Register 0: " << cpu.getSharedRegister(0) << std::endl;

        // Write value to shared memory at address 0x10
        cpu.writeToSharedMemory(0x10, 0xFF);
        std::cout << "Shared Memory at 0x10: " << static_cast<int>(cpu.readFromSharedMemory(0x10)) << std::endl;

        // Run the emulator
        emulator.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
