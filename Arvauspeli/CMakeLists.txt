cmake_minimum_required(VERSION 3.16)

project(Arvauspeli)

set(CMAKE_CXX_STANDARD 17)

# All source files
set(SOURCES
    src/main.cpp
)

add_executable(Arvauspeli ${SOURCES})