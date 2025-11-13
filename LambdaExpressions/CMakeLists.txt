cmake_minimum_required(VERSION 3.25.0)
project(LambdaExpressions VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

#add_compile_definitions(FUNCTIONPOINTER)
#add_compile_definitions(FUNCTIONOBJECT)
#add_compile_definitions(LAMBDA)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/include/*"
    #"${PROJECT_SOURCE_DIR}/src/lambda.cpp"
    #"${PROJECT_SOURCE_DIR}/src/lambdaPart_2.cpp"
    #"${PROJECT_SOURCE_DIR}/src/lambdaPart_3.cpp"
    "${PROJECT_SOURCE_DIR}/src/GeneralizedLambda.cpp"
    #"${PROJECT_SOURCE_DIR}/src/*"
)

add_executable(LambdaExpressions ${SRCS})

include(CTest)
enable_testing()