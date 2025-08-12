cmake_minimum_required(VERSION 3.25)
project(SingletonPattern)
set(CMAKE_CXX_STANDARD 20)

# Add the source files for the SingletonPattern project
set(SINGLETON_PATTERN_SRC
    src/main.cpp
)
# Add the header files for the SingletonPattern project
set(SINGLETON_PATTERN_INC
    inc/main.h
)

# Set the include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)

# Glob the source files
file(GLOB SINGLETON_PATTERN_SRC
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/inc/*.h"
)

# Create the executable for the SingletonPattern project
add_executable(SingletonPattern ${SINGLETON_PATTERN_SRC})

# Set the compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
# Enable testing
include(CTest)
enable_testing()