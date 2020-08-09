cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(d34db33f)

set(CMAKE_CXX_STANDARD 14)

#link_directories(lib/)
include_directories(include/)

add_executable(d34db33f src/main.cpp)

include(cmake/CPM.cmake)
