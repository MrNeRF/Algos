cmake_minimum_required(VERSION 3.13.0)
project(algos VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall -Wno-write-strings -D_GLIBCXX_DEBUG -g")
message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

file(GLOB SOURCES "src/*.cpp")
include_directories(src)
add_executable(algos ${SOURCES})
