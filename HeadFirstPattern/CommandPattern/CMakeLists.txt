cmake_minimum_required(VERSION 3.25)
project(CommandPattern)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
    src/CommandPattern.cpp
    inc/Light.h
    inc/interface.h
    #src/Stereo.cpp
    #src/Light.cpp
    #src/Hottub.cpp
    #src/NoCommand.cpp
    #src/CommandPatternMain.cpp
)

message("Project Source Dir. is: "${PROJECT_SOURCE_DIR})
message("CMake root:" ${CMAKE_ROOT})