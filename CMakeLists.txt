cmake_minimum_required(VERSION 3.28)
project(Tarea1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPPLIB_SRC
    ${PROJECT_SOURCE_DIR}/include/matrix.hpp
    ${PROJECT_SOURCE_DIR}/include/matrix.cpp
)

add_library(${PROJECT_NAME} STATIC ${CPPLIB_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)


include(CTest)
add_subdirectory(extern)
add_subdirectory(test)