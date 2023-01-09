cmake_minimum_required(VERSION 3.20)
project(cpp_exercise)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/utils
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(cpp_exercise ${SOURCES} src/stl/arrayTest.cpp src/utils/timer.cpp src/utils/timer.h)
