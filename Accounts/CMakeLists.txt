cmake_minimum_required(VERSION 3.25.0)
project(stl VERSION 0.1.0 LANGUAGES C CXX)

#---learning steps --- 
#add_compile_definitions(STEP_7_)
#add_compile_definitions(STEP_8_)	#Object Slicing
#add_compile_definitions(STEP_9_)	#type info
add_compile_definitions(STEP_10_)	#dynamice cast


include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
)
file(GLOB SRCS
	"${PROJECT_SOURCE_DIR}/include/*"
	"${PROJECT_SOURCE_DIR}/src/*"
)
add_executable(Accounts ${SRCS})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)