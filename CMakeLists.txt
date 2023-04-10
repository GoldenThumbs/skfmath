# --- THIS FILE COMES FROM THE SKFMATH LIBRARY ---
#     MIT License
#     Copyright (c) 2023 Samuel Skiff
# ------------------------------------------------

cmake_minimum_required(VERSION 3.0)
project(skfmath)

set(skfmath_inc)
set(skfmath_src)

add_subdirectory("inc")
add_subdirectory("src")

add_library(skfmath STATIC ${skfmath_inc} ${skfmath_src})
target_include_directories(skfmath PUBLIC "inc")
