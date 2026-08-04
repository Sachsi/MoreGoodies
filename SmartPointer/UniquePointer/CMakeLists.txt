cmake_minimum_required(VERSION 3.20)
project(UniquePointer)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
# Require the C++ standard to be set
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(UniquePointer main.cpp dog.cpp)
# Build the executable
