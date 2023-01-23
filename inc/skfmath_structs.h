#pragma once

typedef float  f32;
typedef double f64;

typedef struct skf_vec2
{ f32 v[2]; }  skf_vec2;
typedef struct skf_vec3
{ f32 v[3]; }  skf_vec3;
typedef struct skf_vec4
{ f32 v[4]; }  skf_vec4;

typedef skf_vec4 skf_quat;

typedef struct skf_mat4
{ f32 m[4][4]; } skf_mat4;

// ---- Extras ----
#ifdef SKF_EXTRAS

// Technically not a line,
// but a line segment
typedef struct skf_line
{
   skf_vec2 start;
   skf_vec2 end;
} skf_line;

typedef struct skf_plane
{
   skf_vec3 face;
   f32 d;
} skf_plane;

typedef struct skf_rect
{
   skf_vec2 position;
   skf_vec2 size;
} skf_rect;

typedef struct skf_aabb
{
   skf_vec3 position;
   skf_vec3 size;
} skf_aabb;

typedef struct skf_obb
{
   skf_vec3 position;
   skf_vec3 size;
   skf_quat rotation;
} skf_obb;

#endif
