// --- THIS FILE COMES FROM THE SKFMATH LIBRARY ---
//     MIT License
//     Copyright (c) 2023 Samuel Skiff
// ------------------------------------------------

#include "skfmath_int.h"

// ---- Int Functions ----

int skf_wrap(int x, int min, int max)
{
   int range = max - min + 1;

   if (x < min)
      x += range * ((min - x) / range + 1);
   
   return min + (x - min) % range;
}
