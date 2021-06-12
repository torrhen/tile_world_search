cmake_minimum_required (VERSION 3.10)

project(TileSearch)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_executable(run 
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/grid.cpp
	${PROJECT_SOURCE_DIR}/node.cpp
	${PROJECT_SOURCE_DIR}/search.cpp)