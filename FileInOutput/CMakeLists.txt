cmake_minimum_required(VERSION 3.5.0)
project(FileInOutput VERSION 0.1.0 LANGUAGES C CXX)

#add_compile_definitions(NoExHand_I_)
#add_compile_definitions(ExHand_II_)
#add_compile_definitions(ExHand_I_)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/include/*"
    "${PROJECT_SOURCE_DIR}/src/*")

add_executable(FileInOutput ${SRCS})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)