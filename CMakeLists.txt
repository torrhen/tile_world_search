cmake_minimum_required (VERSION 3.20)

project(tile_world_search VERSION 1.1 LANGUAGES CXX)

# find GoogleTest library
find_package(GTest REQUIRED)

add_executable(tile_world_search src/main.cpp src/grid.cpp src/node.cpp src/search.cpp)
# include GoogleTest public headers inside application
target_include_directories(tile_world_search PRIVATE ${GTEST_INCLUDE_DIRS})
# link the GoogleTest library
target_link_libraries(tile_world_search PRIVATE ${GTEST_LIBRARIES})

# set to c++17, c++11 at least required for GoogleTest
target_compile_features(tile_world_search PRIVATE cxx_std_17)
# raise all possible warnings as errors
target_compile_options(tile_world_search PRIVATE -Wall -Wextra -pedantic -Werror)