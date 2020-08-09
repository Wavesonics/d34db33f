cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(d34db33f)

set(CMAKE_CXX_STANDARD 17)

#include_directories(include/)
#link_directories(lib/)

add_executable(d34db33f src/main.cpp)

include(cmake/CPM.cmake)

CPMAddPackage(
        NAME boost-cmake
        GITHUB_REPOSITORY Orphis/boost-cmake
        VERSION 1.67.0
)

CPMAddPackage(
        NAME wren
        GITHUB_REPOSITORY wren-lang/wren
        GIT_TAG cd012469976d1a9da796581cd9a9591842cb0cf8
        VERSION 0.3.0
        DOWNLOAD_ONLY YES
)

if (wren_ADDED)
    FILE(GLOB_RECURSE wren_sources ${wren_SOURCE_DIR}/src/*.c)
    add_library(wren STATIC ${wren_sources})

    target_include_directories(wren
            PUBLIC
            $<BUILD_INTERFACE:${wren_SOURCE_DIR}/src/include>
            )
    target_include_directories(wren
            PRIVATE
            $<BUILD_INTERFACE:${wren_SOURCE_DIR}/src/vm>
            )
    target_include_directories(wren
            PRIVATE
            $<BUILD_INTERFACE:${wren_SOURCE_DIR}/src/optional>
            )
endif()

target_link_libraries(d34db33f LINK_PUBLIC wren)