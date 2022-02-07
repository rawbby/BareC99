cmake_minimum_required(VERSION 3.1)

#   ____    ___    _   _   _____   ___    ____
#  / ___|  / _ \  | \ | | |  ___| |_ _|  / ___|
# | |     | | | | |  \| | | |_     | |  | |  _
# | |___  | |_| | | |\  | |  _|    | |  | |_| |
#  \____|  \___/  |_| \_| |_|     |___|  \____|

set(TARGET_NAME Common)
set(TARGET_LINK_LIBRARIES)
set(TARGET_DEPENDENCIES)

#   ____   _____   _   _   _____   ____    ___    ____
#  / ___| | ____| | \ | | | ____| |  _ \  |_ _|  / ___|
# | |  _  |  _|   |  \| | |  _|   | |_) |  | |  | |
# | |_| | | |___  | |\  | | |___  |  _ <   | |  | |___
#  \____| |_____| |_| \_| |_____| |_| \_\ |___|  \____|

# collect target source files
file(GLOB_RECURSE TARGET_HEADER *.h)

# add target
add_library(${TARGET_NAME} INTERFACE)
target_sources(${TARGET_NAME} INTERFACE ${TARGET_HEADER})
target_include_directories(${TARGET_NAME} INTERFACE /)
set_target_properties("${TARGET_NAME}" PROPERTIES
        LINKER_LANGUAGE C
        C_STANDARD 99
        C_STANDARD_REQUIRED ON)

# add target dependencies
if (TARGET_LINK_LIBRARIES)
    target_link_libraries("${TARGET_NAME}" INTERFACE ${TARGET_LINK_LIBRARIES})
endif ()
if (TARGET_DEPENDENCIES)
    add_dependencies(${TARGET_NAME} ${TARGET_DEPENDENCIES})
endif ()

# log message for interface library
message("${PROJECT_NAME}: Interface Library '${TARGET_NAME}' added")
