add_library(tile_world_search STATIC grid.cpp node.cpp search.cpp)

add_executable(tileworldsearch main.cpp)
target_link_libraries(tileworldsearch PRIVATE tile_world_search)
# set compiler to use c++17
target_compile_features(tileworldsearch PRIVATE cxx_std_17)
# raise all possible warnings as errors
target_compile_options(tileworldsearch PRIVATE -Wall -Wextra -pedantic -Werror)

# install the executable binary
install(TARGETS tileworldsearch DESTINATION ${CMAKE_SOURCE_DIR}/bin)