cmake_minimum_required(VERSION 3.0.0)
project(hw1 VERSION 0.1.0)

set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)
add_library(hw1 SHARED ErrorCode.c Matrix.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})