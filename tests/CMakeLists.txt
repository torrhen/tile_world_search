# find GoogleTest library
find_package(GTest REQUIRED)

add_executable(tileworldsearchtests test_grid.cpp)
target_include_directories(tileworldsearchtests PRIVATE ${CMAKE_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})
target_link_libraries(tileworldsearchtests PRIVATE tile_world_search ${GTEST_LIBRARIES})

gtest_discover_tests(tileworldsearchtests)

# install the executable binary
install(TARGETS tileworldsearchtests DESTINATION ${CMAKE_SOURCE_DIR}/bin)