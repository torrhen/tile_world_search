cmake_minimum_required (VERSION 3.20)

project(tile_world_search VERSION 1.1 LANGUAGES CXX)

add_subdirectory(src)

enable_testing()

add_subdirectory(tests)