cmake_minimum_required (VERSION 3.10)

project(TileSearch)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable (output src/main.cpp src/Node.cpp src/Grid.cpp src/TreeSearch.cpp)
