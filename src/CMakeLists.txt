set(MAIN_SRC
        main.cpp
)

add_executable(Main ${MAIN_SRC})

target_include_directories(Main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(emulator)
add_subdirectory(logger)
add_subdirectory(memory)
add_subdirectory(processor)
add_subdirectory(storage)

target_link_libraries(Main PRIVATE
        Emulator
        Logger
#        Memory
        Processor
#        Storage
)