cmake_minimum_required(VERSION 3.0)
project(skfmath C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(skfmath STATIC "src/skfmath.c")
target_include_directories(skfmath PUBLIC "inc")
