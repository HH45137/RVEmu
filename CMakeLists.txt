cmake_minimum_required(VERSION 3.28)
project(RVEmu)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include/)

add_executable(RVEmu main.cpp
        include/rv_registers_32i.h
        include/rv_typedef.h
        include/rv_cpu_32i.h
        src/rv_cpu_32i.cpp
        include/common/log_sys.h
        src/common/log_sys.cpp)
