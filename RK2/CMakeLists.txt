cmake_minimum_required(VERSION 3.31)

project(lab08)

file(GLOB_RECURSE SRC "*.cpp")
add_executable(lab08 ${SRC})
target_link_libraries(lab08)