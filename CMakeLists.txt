cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(d34db33f)

set(CMAKE_CXX_STANDARD 17)

add_executable(d34db33f src/main.cpp src/ChaiProgram.cpp src/ChaiProgram.h)

include(cmake/CPM.cmake)

CPMAddPackage(
        NAME chaiscript
        GIT_REPOSITORY https://github.com/ChaiScript/ChaiScript.git
        VERSION 6.1.0
        DOWNLOAD_ONLY YES
)

if (chaiscript_ADDED)
    add_library(chaiscript INTERFACE)

    target_include_directories(chaiscript
            INTERFACE
            $<BUILD_INTERFACE:${chaiscript_SOURCE_DIR}/include>
            )
endif()

target_link_libraries(d34db33f chaiscript)