cmake_minimum_required (VERSION 3.10)

project(TileSearch)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

add_executable(output 
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/Grid.cpp
	${PROJECT_SOURCE_DIR}/Node.cpp
	${PROJECT_SOURCE_DIR}/Search.cpp)

target_include_directories(output PUBLIC ${PROJECT_INCLUDE_DIR})
