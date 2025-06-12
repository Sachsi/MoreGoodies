cmake_minimum_required(VERSION 3.25)
project(Observer)
set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/inc/*"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)
add_executable(Observer ${SRCS})

include(CTest)
enable_testing()