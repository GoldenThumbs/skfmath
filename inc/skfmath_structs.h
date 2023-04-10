// --- THIS FILE COMES FROM THE SKFMATH LIBRARY ---
//     MIT License
//     Copyright (c) 2023 Samuel Skiff
// ------------------------------------------------

#pragma once

#ifdef __cplusplus
   #define CREATE_C_TYPE(t)  t
#else
   #define CREATE_C_TYPE(t) (t)
#endif

typedef float  f32;
typedef double f64;

typedef struct skf_vec2
{
   f32 v[2];
}  skf_vec2;
typedef struct skf_vec3
{
   f32 v[3];
}  skf_vec3;
typedef struct skf_vec4
{
   f32 v[4];
}  skf_vec4;

typedef skf_vec4 skf_quat;

typedef struct skf_mat4
{
   f32 m[4][4];
} skf_mat4;
