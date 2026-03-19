cmake_minimum_required(VERSION 3.20)

# Project name
project(TryOutFunctions)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(TryOutFunctions main.cpp)

# For multi-file projects with headers and separate .cpp files
# add_executable(TryOutFunctions main.cpp dog.cpp dog.h cat.cpp cat.h)
