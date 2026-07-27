cmake_minimum_required(VERSION 3.20)

#Project name
project(ConstructorList)

#Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)