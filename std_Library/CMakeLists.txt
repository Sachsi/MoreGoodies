cmake_minimum_required(VERSION 3.25.0)
project(std_Library VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

#add_compile_definitions(FUNCTIONPOINTER)
#add_compile_definitions(FUNCTIONOBJECT)
#add_compile_definitions(LAMBDA)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/inc/*"
    #"${PROJECT_SOURCE_DIR}/src/array_vector.cpp"
    #"${PROJECT_SOURCE_DIR}/src/deque.cpp"
    #"${PROJECT_SOURCE_DIR}/src/list_multiList.cpp"
    #"${PROJECT_SOURCE_DIR}/src/bind.cpp"
    #"${PROJECT_SOURCE_DIR}/src/function.cpp"
    #"${PROJECT_SOURCE_DIR}/src/set_multiset.cpp"
    #"${PROJECT_SOURCE_DIR}/src/map_Multimap.cpp"
    #"${PROJECT_SOURCE_DIR}/src/unordert_set.cpp"
    #"${PROJECT_SOURCE_DIR}/src/unordert_map.cpp"
    #"${PROJECT_SOURCE_DIR}/src/hash.cpp"
    "${PROJECT_SOURCE_DIR}/src/optional.cpp"
    #"${PROJECT_SOURCE_DIR}/src/*"
)

add_executable(std_Library ${SRCS})

include(CTest)
enable_testing()