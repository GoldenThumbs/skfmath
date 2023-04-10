# --- THIS FILE COMES FROM THE SKFMATH LIBRARY ---
#     MIT License
#     Copyright (c) 2023 Samuel Skiff
# ------------------------------------------------

set(files_source
"skfmath.c" 
"skfmath_int.c")

set(full_src)

foreach(file_src IN ITEMS ${files_source})

   set(tmp_src "${CMAKE_CURRENT_SOURCE_DIR}/${file_src};")
   set(full_src "${full_src}${tmp_src}")

endforeach()

set(skfmath_src ${full_src} PARENT_SCOPE)
