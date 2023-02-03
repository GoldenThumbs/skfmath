# --- THIS FILE COMES FROM THE SKFMATH LIBRARY ---
#     MIT License
#     Copyright (c) 2023 Samuel Skiff
# ------------------------------------------------

cmake_minimum_required(VERSION 3.0)
project(skfmath)

add_library(skfmath STATIC "src/skfmath.c" "src/skfmath_int.c" "inc/skfmath_structs.h" "inc/skfmath_helpers.h" "inc/skfmath.h" "inc/skfmath_int.h")
target_include_directories(skfmath PUBLIC "inc")
