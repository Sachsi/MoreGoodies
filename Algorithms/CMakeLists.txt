cmake_minimum_required(VERSION 3.25.0)
project(Algorithms VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS 
      "${PROJECT_SOURCE_DIR}/inc/*"
      "${PROJECT_SOURCE_DIR}/src/Algorith_Part1.cpp"  
      #"${PROJECT_SOURCE_DIR}/src/Algorith_Part2.cpp"  
)

add_executable(Algorithms ${SRCS})

include(CTest)
enable_testing()