cmake_minimum_required(VERSION 3.25.0)
project(stl VERSION 0.1.0 LANGUAGES C CXX)

add_executable(StrStream src/main.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
