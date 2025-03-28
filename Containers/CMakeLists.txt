cmake_minimum_required(VERSION 3.25.0)
project(Containers VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(CHANGE_TWO)
#add_compile_definitions(CHANGE_ONE)


include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS 
      "${PROJECT_SOURCE_DIR}/inc/*"
      "${PROJECT_SOURCE_DIR}/src/change_two.cpp"  
      "${PROJECT_SOURCE_DIR}/src/*"  
)

add_executable(Containers ${SRCS})

include(CTest)
enable_testing()