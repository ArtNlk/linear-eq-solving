cmake_minimum_required(VERSION 3.16)
project(CPP1_task)

set(CMAKE_CXX_STANDARD 20)

include_directories(linsolvers)
link_directories(linsolvers)

add_subdirectory(linsolvers)
add_subdirectory(main)