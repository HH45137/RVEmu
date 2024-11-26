set(LOGGER_SRC
        logger.cc
        logger.h
        logger.inl
)

add_library(Logger STATIC ${LOGGER_SRC})
