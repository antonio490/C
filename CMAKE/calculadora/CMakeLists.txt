cmake_minimum_required(VERSION 3.0.0)

project(Calculadora VERSION 1.0.0)

add_library(my_math
suma.cpp
division.cpp)

add_library(my_print
resultado.cpp)

add_executable(calculadora
main.cpp)

target_link_libraries(calculadora my_math my_print)
