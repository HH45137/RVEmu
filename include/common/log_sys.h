#pragma once

#include <iostream>
#include <string>


namespace LogSys {

    enum LOG_LEVEL_E {
        NORMAL = 0,
        WARING,
        ERROR
    };

    void Log(std::string text, LOG_LEVEL_E type = NORMAL);

}
