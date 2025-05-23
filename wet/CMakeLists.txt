cmake_minimum_required(VERSION 3.31)
project(wet)

set(CMAKE_CXX_STANDARD 17)

add_executable(wet main.cpp
        Matrix.cpp
        Matrix.h
        MataMvidia.cpp
        MataMvidia.h)
