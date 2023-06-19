cmake_minimum_required(VERSION 3.14)
project(tui LANGUAGES CXX)

# If standalone project define standars
if(CMAKE_SOURCE_DIR STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)
file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# If standalone project build main
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(tui src/main.cpp ${all_SRCS})
else()
    add_library(tui ${all_SRCS})
endif()
set_target_properties(tui PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
add_subdirectory(test)
