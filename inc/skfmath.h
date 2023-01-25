#pragma once

#include "skfmath_structs.h"

// ---- Float Functions ----

f32 skf_sign(f32 val);
f32 skf_abs(f32 val);
f32 skf_clamp(f32 val, f32 min, f32 max);
f32 skf_lerp(f32 left, f32 right, f32 amount);

// ---- Vector2 Functions ----

f32 skf_vec2_dot(skf_vec2 left, skf_vec2 right);
f32 skf_vec2_len(skf_vec2 vec);
skf_vec2 skf_vec2_normalize(skf_vec2 vec);

// ---- Vector3 Functions ----

static inline skf_vec3 skf_vec3_right()
{
   return (skf_vec3){ 1, 0, 0 };
}
static inline skf_vec3 skf_vec3_up()
{
   return (skf_vec3){ 0, 1, 0 };
}
static inline skf_vec3 skf_vec3_back()
{
   return (skf_vec3){ 0, 0, 1 };
}
static inline skf_vec3 skf_vec3_one()
{
   return (skf_vec3){ 1, 1, 1 };
}
static inline skf_vec3 skf_vec3_zero()
{
   return (skf_vec3){ 0, 0, 0 };
}

f32 skf_vec3_dot(skf_vec3 left, skf_vec3 right);
f32 skf_vec3_len(skf_vec3 vec);
f32 skf_vec3_angle(skf_vec3 left, skf_vec3 right);
skf_vec3 skf_vec3_normalize(skf_vec3 vec);
skf_vec3 skf_vec3_cross(skf_vec3 left, skf_vec3 right);
skf_vec3 skf_vec3_add(skf_vec3 left, skf_vec3 right);
skf_vec3 skf_vec3_sub(skf_vec3 left, skf_vec3 right);
skf_vec3 skf_vec3_neg(skf_vec3 vec);
skf_vec3 skf_vec3_mul(skf_vec3 left, skf_vec3 right);
skf_vec3 skf_vec3_div(skf_vec3 left, skf_vec3 right);
skf_vec3 skf_vec3_rcp(skf_vec3 vec);
skf_vec3 skf_vec3_mul_f32(skf_vec3 vec, f32 scalar);
skf_vec3 skf_vec3_lerp(skf_vec3 left, skf_vec3 right, f32 amount);

// ---- Vector4 Functions ----

f32 skf_vec4_dot(skf_vec4 left, skf_vec4 right);
f32 skf_vec4_len(skf_vec4 vec);
skf_vec4 skf_vec4_normalize(skf_vec4 vec);
skf_vec4 skf_vec4_sub(skf_vec4 left, skf_vec4 right);

// ---- Quaternion Functions ----

static inline skf_quat skf_quat_identity()
{
   return (skf_quat){ 0, 0, 0, 1 };
}

skf_vec3 skf_vec3_quat_rotate(skf_vec3 vec, skf_quat rot);

skf_quat skf_quat_from_axis_angle(skf_vec3 axis, f32 angle);
skf_quat skf_quat_mul(skf_quat left, skf_quat right);

// ---- Matrix4x4 Functions ----

static inline skf_mat4 skf_mat4_identity()
{
   return (skf_mat4) {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1 };
}

skf_vec4 skf_vec4_mat4_transform(skf_vec4 vec, skf_mat4 mat);
skf_vec3 skf_vec3_mat4_transform(skf_vec3 vec, skf_mat4 mat);

skf_mat4 skf_mat4_sub(skf_mat4 left, skf_mat4 right);
skf_mat4 skf_mat4_mul(skf_mat4 left, skf_mat4 right);

skf_mat4 skf_mat4_transpose(skf_mat4 mat);
skf_mat4 skf_mat4_inverse(skf_mat4 mat);

skf_mat4 skf_mat4_translate(skf_vec3 translation);
skf_mat4 skf_mat4_scale(skf_vec3 scale);
skf_mat4 skf_mat4_rotate(skf_quat rotation);
skf_mat4 skf_mat4_rotate_x(f32 angle);
skf_mat4 skf_mat4_rotate_y(f32 angle);
skf_mat4 skf_mat4_rotate_z(f32 angle);

skf_mat4 skf_mat4_view_simple(skf_vec3 position, skf_quat rotation);
skf_mat4 skf_mat4_view_target(skf_vec3 position, skf_vec3 target, skf_vec3 up);

skf_mat4 skf_mat4_orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far);
skf_mat4 skf_mat4_projection(f32 fov, f32 aspect, f32 near, f32 far);
