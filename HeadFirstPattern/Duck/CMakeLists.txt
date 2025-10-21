cmake_minimum_required(VERSION 3.28.0)
project(Duck VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS 
      "${PROJECT_SOURCE_DIR}/inc/*"
      "${PROJECT_SOURCE_DIR}/src/*.cpp"  
)
add_executable(Duck ${SRCS})

include(CTest)
enable_testing()