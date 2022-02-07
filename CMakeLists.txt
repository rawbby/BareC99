cmake_minimum_required(VERSION 3.1)

#   ____    ___    _   _   _____   ___    ____
#  / ___|  / _ \  | \ | | |  ___| |_ _|  / ___|
# | |     | | | | |  \| | | |_     | |  | |  _
# | |___  | |_| | | |\  | |  _|    | |  | |_| |
#  \____|  \___/  |_| \_| |_|     |___|  \____|

set(PROJECT_NAME BareC99)

#   ____   _____   _   _   _____   ____    ___    ____
#  / ___| | ____| | \ | | | ____| |  _ \  |_ _|  / ___|
# | |  _  |  _|   |  \| | |  _|   | |_) |  | |  | |
# | |_| | | |___  | |\  | | |___  |  _ <   | |  | |___
#  \____| |_____| |_| \_| |_____| |_| \_\ |___|  \____|

project(${PROJECT_NAME} LANGUAGES C)

# normalise output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# add all core directories
file(GLOB CORE_DIRECTORIES core/*)
foreach (CORE_DIRECTORY ${CORE_DIRECTORIES})
    add_subdirectory(${CORE_DIRECTORY})
endforeach ()

# add all tool directories
file(GLOB TOOL_DIRECTORIES tool/*)
foreach (TOOL_DIRECTORY ${TOOL_DIRECTORIES})
    add_subdirectory(${TOOL_DIRECTORY})
endforeach ()

# add test directory only if enabled
option(BUILD_TESTING "Build Tests" OFF)
if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif ()
