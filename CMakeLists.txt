# cmake_minimum_required(VERSION <specify CMake version here>)
project(projekt C)

set(CMAKE_C_STANDARD 11)

add_executable(projekt main.c board.c board.h user.c user.h card.c card.h functions.c functions.h menu.c menu.h)