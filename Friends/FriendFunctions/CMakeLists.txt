cmake_minimum_required(VERSION 3.20)
PROJECT(FriendFunctions)

# set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
# additional flags for C++20 can be set here if needed
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(FriendFunctions main.cpp)

# for multi-file projects with headers and separate .cpp files, you can add them like this:
# add_executable(FriendFunctions main.cpp friend.cpp friend.h)