cmake_minimum_required(VERSION 3.15)
project(Programma)

include(FetchContent)

FetchContent_Declare(
        jsoncpp
        GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
        GIT_TAG        master
)

FetchContent_GetProperties(jsoncpp)
if (NOT jsoncpp_POPULATED)
    FetchContent_Populate(jsoncpp)
    add_subdirectory(${jsoncpp_SOURCE_DIR} ${jsoncpp_BINARY_DIR})
    message(${jsoncpp_SOURCE_DIR})
    message(${jsoncpp_BINARY_DIR})
endif ()

FetchContent_MakeAvailable(jsoncpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Programma main.cpp)
add_library(Tests TestSubjects.cpp TransformTests.cpp FoldTests.cpp
        TestResults.h SortTests.cpp FindTests.cpp)

target_link_libraries(Programma Tests jsoncpp_lib)