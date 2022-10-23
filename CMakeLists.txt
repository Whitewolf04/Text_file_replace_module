cmake_minimum_required(VERSION 3.20)
project(C_learning C)

set(CMAKE_C_STANDARD 99)

add_executable(C_learning
        A1.c
        text.c
        text.h
        )

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test/test.txt
        ${CMAKE_CURRENT_BINARY_DIR})
