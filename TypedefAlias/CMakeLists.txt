cmake_minimum_required(VERSION 3.25.0)
project(TypedefAlias VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/include/*"
    "${PROJECT_SOURCE_DIR}/src/*"
)

add_executable(TypedefAlias ${SRCS})


#... (vorherige Inhalte)

# Anweisung, um den Test zu erstellen
add_executable(MeinTest Test/test_main.cpp)

# Anweisung, um den Test zu registrieren
include(CTest)
enable_testing()
add_test(NAME MeinEinfacherTest
         COMMAND MeinTest
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})