cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(LEETCODE VERSION 1.0)

add_library(leetcode leetcode.c)
add_executable(main main.c)

target_link_libraries(main PUBLIC leetcode)
target_link_libraries(main PUBLIC m)
#target_link_libraries(main PRIVATE -fsanitize=address)



set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_FLAGS "-fsanitize=undefined,address,leak -fno-omit-frame-pointer -gdwarf-2 -g3")
set(CMAKE_Ｌ_FLAGS "-fsanitize=undefined,address,leak -fno-omit-frame-pointer")
