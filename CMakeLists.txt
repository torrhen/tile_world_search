# project specific logic here.#

cmake_minimum_required (VERSION 3.8)

project(TileSearch)


set(CMAKE_CXX_STANDARD 17)


# Add source to this project's executable.
add_executable (output "src/main.cpp" "src/Node.cpp" "src/Grid.cpp")
