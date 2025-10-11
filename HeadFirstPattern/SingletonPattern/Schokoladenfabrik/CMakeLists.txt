cmake_minimum_required(VERSION 3.25)
project(Schokoladenfabrik)
set(CMAKE_CXX_STANDARD 17)

set(SCHOKOLADENFABRIK_SRC
    src/main.cpp
)

set(SCHOKOLADENFABRIK_INC
    inc/main.h
)

#set the include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)

#set the global source files
set(GLOB SCHOKOLADENFABRIK_SRC
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/inc/*.h"
)

# add the executable for the Schokoladenfabrik project
add_executable(Schokoladenfabrik ${SCHOKOLADENFABRIK_SRC})

#set the compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
#enable testing
include(CTest)
enable_testing()