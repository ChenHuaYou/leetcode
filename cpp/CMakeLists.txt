cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(leetcode VERSION 1.0)


add_executable(main main.cpp)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE "Debug")
