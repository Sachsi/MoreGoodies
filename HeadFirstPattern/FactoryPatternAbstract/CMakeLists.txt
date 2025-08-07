cmake_minimum_required(VERSION 3.25)
project(FactoryPatternAbstract)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)
file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/inc/*"
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(FactoryPatternAbstract ${SRCS})

include(CTest)
enable_testing()
