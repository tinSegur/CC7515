cmake_minimum_required(VERSION 3.28)
project(Tarea_1)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

add_executable(Tarea_1
        matrix.cpp
        matrix.h)

add_subdirectory(extern)