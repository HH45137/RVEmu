set(PROCESSOR_SRC
        cache.cc
        cache.h
        core.cc
        core.h
        cpu.cc
        cpu.h
        instruction.cc
        instruction.h
)

add_library(Processor STATIC ${PROCESSOR_SRC})
