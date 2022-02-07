cmake_minimum_required(VERSION 3.1)

#   ____    ___    _   _   _____   ___    ____
#  / ___|  / _ \  | \ | | |  ___| |_ _|  / ___|
# | |     | | | | |  \| | | |_     | |  | |  _
# | |___  | |_| | | |\  | |  _|    | |  | |_| |
#  \____|  \___/  |_| \_| |_|     |___|  \____|

set(TARGET_NAME Application)
set(TARGET_LINK_LIBRARIES Common Allocator)
set(TARGET_DEPENDENCIES Assets)

#   ____   _____   _   _   _____   ____    ___    ____
#  / ___| | ____| | \ | | | ____| |  _ \  |_ _|  / ___|
# | |  _  |  _|   |  \| | |  _|   | |_) |  | |  | |
# | |_| | | |___  | |\  | | |___  |  _ <   | |  | |___
#  \____| |_____| |_| \_| |_____| |_| \_\ |___|  \____|

file(GLOB_RECURSE TARGET_HEADER *.h)
file(GLOB_RECURSE TARGET_SOURCE *.c)

add_executable(${TARGET_NAME})
target_sources(${TARGET_NAME} PRIVATE ${TARGET_HEADER} ${TARGET_SOURCE})

target_link_libraries(${TARGET_NAME} ${TARGET_LINK_LIBRARIES})
add_dependencies(${TARGET_NAME} ${TARGET_DEPENDENCIES})

set_target_properties(${TARGET_NAME} PROPERTIES
        LINKER_LANGUAGE C
        C_STANDARD 99
        C_STANDARD_REQUIRED ON)

message("${PROJECT_NAME}: Executable '${TARGET_NAME}' added")
