cmake_minimum_required(VERSION 3.25.0)
project(TestFile VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/include/*"
    "${PROJECT_SOURCE_DIR}/src/*")

add_executable(TestFile ${SRCS})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)