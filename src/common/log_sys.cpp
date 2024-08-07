#include "common/log_sys.h"


namespace LogSys {

    void Log(std::string text, LOG_LEVEL_E type) {

        std::string typeStr{};
        switch (type) {
            case NORMAL:
                typeStr = "Normal";
                break;

            case WARING:
                typeStr = "Waring";
                break;

            case ERROR:
                typeStr = "Error";
                break;

            default:
                typeStr = "Unknown";
                break;
        }

        std::cout << typeStr << ": " << text << "\n";
    }
}