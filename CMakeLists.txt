cmake_minimum_required(VERSION 3.31)
project(makefile C)

set(CMAKE_C_STANDARD 11)

add_executable(makefile main.c
        include/choiceIdentify.h
        source/choiceIdentify.c)
