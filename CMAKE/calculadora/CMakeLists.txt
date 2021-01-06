cmake_minimum_required(VERSION 3.0.0)

project(Calculadora VERSION 1.0.0)

add_subdirectory(my_math_dir)
add_subdirectory(my_print_dir)

add_executable(calculadora
main.cpp)

target_link_libraries(calculadora my_math my_print)
