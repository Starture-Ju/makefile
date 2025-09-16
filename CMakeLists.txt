cmake_minimum_required(VERSION 3.31)
project(makefile C)

set(CMAKE_C_STANDARD 11)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(makefile main.c
        source/choiceIdentify.c
        source/preProcess.c
        source/basicFunc.c)

