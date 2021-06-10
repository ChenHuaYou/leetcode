cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(LEETCODE VERSION 1.0)

add_library(leetcode leetcode.cpp)
add_executable(main main.cpp)

target_link_libraries(main PUBLIC leetcode)



set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE "Debug")
