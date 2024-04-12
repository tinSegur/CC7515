cmake_minimum_required(VERSION 3.28)
project(Tarea_1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPPLIB_SRC
    "${PROJECT_SOURCE_DIR}/matrix.cpp"
    "${PROJECT_SOURCE_DIR}/matrix.h"
)

add_library(${PROJECT_NAME} INTERFACE ${CPPLIB_SRC})
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})


include(CTest)
add_subdirectory(extern)
add_subdirectory(test)