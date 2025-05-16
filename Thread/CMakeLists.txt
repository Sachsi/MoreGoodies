cmake_minimum_required(VERSION 3.25.0)
project(thread VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/inc/*"
    #"${PROJECT_SOURCE_DIR}/src/concurrency.cpp"
    #"${PROJECT_SOURCE_DIR}/src/ThreadCreate.cpp"
    #"${PROJECT_SOURCE_DIR}/src/ArgToThreads.cpp"
    #"${PROJECT_SOURCE_DIR}/src/ReturnValueThread.cpp"
    "${PROJECT_SOURCE_DIR}/src/ThreadSynchronMutex.cpp"
)


add_executable(thread ${SRCS})

include(CTest)
enable_testing()

