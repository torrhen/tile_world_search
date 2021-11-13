cmake_minimum_required (VERSION 3.15)

project(tile_world_search VERSION 1.0.0 LANGUAGES CXX)

add_executable(run src/main.cpp src/grid.cpp src/node.cpp src/search.cpp)

target_compile_features(run PUBLIC cxx_std_17)
target_compile_options(run INTERFACE -Wall -Wextra -pedantic -Werror)