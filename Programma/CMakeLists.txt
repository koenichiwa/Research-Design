cmake_minimum_required(VERSION 3.15)
project(Programma)

set(CMAKE_CXX_STANDARD 17)

add_executable(Programma main.cpp)
add_library(Tests CollectionGenerators.cpp MapTests.cpp FoldTests.cpp)

target_link_libraries(Programma Tests)