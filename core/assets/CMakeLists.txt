cmake_minimum_required(VERSION 3.1)

#   ____    ___    _   _   _____   ___    ____
#  / ___|  / _ \  | \ | | |  ___| |_ _|  / ___|
# | |     | | | | |  \| | | |_     | |  | |  _
# | |___  | |_| | | |\  | |  _|    | |  | |_| |
#  \____|  \___/  |_| \_| |_|     |___|  \____|

set(RESOURCE_FOLDER assets)

#  _   _   _____   ___   _
# | | | | |_   _| |_ _| | |
# | | | |   | |    | |  | |
# | |_| |   | |    | |  | |___
#  \___/    |_|   |___| |_____|

macro(capitalise OUTPUT_VARIABLE INPUT)
    set(${OUTPUT_VARIABLE} ${INPUT})
    foreach (LOWER_LETTER a b c d e f g h i j k l m n o p q r s t u v w x y z)
        string(TOUPPER ${LOWER_LETTER} UPPER_LETTER)
        string(REGEX REPLACE "^${LOWER_LETTER}" "${UPPER_LETTER}" ${OUTPUT_VARIABLE} ${${OUTPUT_VARIABLE}})
    endforeach ()
endmacro()

#   ____   _____   _   _   _____   ____    ___    ____
#  / ___| | ____| | \ | | | ____| |  _ \  |_ _|  / ___|
# | |  _  |  _|   |  \| | |  _|   | |_) |  | |  | |
# | |_| | | |___  | |\  | | |___  |  _ <   | |  | |___
#  \____| |_____| |_| \_| |_____| |_| \_\ |___|  \____|

# capitalise the folder name and use it as target name
capitalise(RESOURCE_NAME ${RESOURCE_FOLDER})

set(RESOURCE_FOLDER_SRC "${CMAKE_CURRENT_LIST_DIR}/${RESOURCE_FOLDER}/")
set(RESOURCE_FOLDER_DST "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${RESOURCE_FOLDER}/")

add_custom_target(${RESOURCE_NAME}
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${RESOURCE_FOLDER_SRC}" "${RESOURCE_FOLDER_DST}")

# log message for resource folder
message("${PROJECT_NAME}: Resource '${RESOURCE_NAME}' added")
