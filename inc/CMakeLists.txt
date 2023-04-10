# --- THIS FILE COMES FROM THE SKFMATH LIBRARY ---
#     MIT License
#     Copyright (c) 2023 Samuel Skiff
# ------------------------------------------------

set(files_include
"skfmath_helpers.h" 
"skfmath_structs.h" 
"skfmath.h" 
"skfmath_int.h")

foreach(file_inc IN ITEMS ${files_include})

   set(tmp_inc "${CMAKE_CURRENT_SOURCE_DIR}/${file_inc}")
   set(skfmath_inc "${skfmath_inc}${tmp_inc}" PARENT_SCOPE)

endforeach()
