# --- THIS FILE COMES FROM THE SKFMATH LIBRARY ---
#     MIT License
#     Copyright (c) 2023 Samuel Skiff
# ------------------------------------------------

set(files_include
"skfmath_helpers.h" 
"skfmath_structs.h" 
"skfmath.h" 
"skfmath_int.h")

set(full_inc)

foreach(file_inc IN ITEMS ${files_include})

   set(tmp_inc "${CMAKE_CURRENT_SOURCE_DIR}/${file_inc};")
   set(full_inc "${full_inc}${tmp_inc}")

endforeach()

set(skfmath_inc ${full_inc} PARENT_SCOPE)
