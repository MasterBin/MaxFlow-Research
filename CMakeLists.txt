cmake_minimum_required(VERSION 3.13)
project(kdz_prj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)
add_executable(kdz_prj ${SOURCE_FILES})

add_subdirectory(tests)