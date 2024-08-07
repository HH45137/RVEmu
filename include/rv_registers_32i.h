#pragma once

#include <iostream>
#include <string>

#include "rv_typedef.h"


namespace RVEMU {
    struct SRegisters32I {
    private:

    public:
        // Zero forever
        Register32 zero{};
        // Pointer
        Register32 ra{};
        Register32 sp{};
        Register32 gp{};
        Register32 tp{};
        // Temporary
        Register32 t0{};
        Register32 t1{};
        Register32 t2{};
        // Frame pointer
        Register32 fp{};
        // Saved
        Register32 s1{};
        // Function argument
        Register32 a0{};
        Register32 a1{};
        Register32 a2{};
        Register32 a3{};
        Register32 a4{};
        Register32 a5{};
        Register32 a6{};
        Register32 a7{};
        // Saved
        Register32 s2{};
        Register32 s3{};
        Register32 s4{};
        Register32 s5{};
        Register32 s6{};
        Register32 s7{};
        Register32 s8{};
        Register32 s9{};
        Register32 s10{};
        Register32 s11{};
        // Temporary
        Register32 t3{};
        Register32 t4{};
        Register32 t5{};
        Register32 t6{};
    };
}
