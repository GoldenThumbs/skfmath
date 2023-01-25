#include "skfmath.h"

#include <math.h>

// ---- Float Functions ----

f32 skf_sign(f32 val)
{
   return (f32)((val > 0.0f) - (val < 0.0f));
}
f32 skf_abs(f32 val)
{
   // This function is probably useless, seeing as fabsf exists.
   // redid it to use fabsf itself anyway...
   return fabsf(val);
}
f32 skf_clamp(f32 val, f32 min, f32 max)
{
   return (val < min) ? min : ((val > max) ? max : val);
}
f32 skf_lerp(f32 left, f32 right, f32 amount)
{
   return left + amount * (right - left);
}

// ---- Vector2 Functions ----

f32 skf_vec2_dot(skf_vec2 left, skf_vec2 right)
{
   return left.v[0]*right.v[0] + left.v[1]*right.v[1];
}
f32 skf_vec2_len(skf_vec2 vec)
{
   return sqrtf(skf_vec2_dot(vec, vec));
}
skf_vec2 skf_vec2_normalize(skf_vec2 vec)
{
   f32 rcp = 1.0f / skf_vec2_len(vec);
   return (skf_vec2){ vec.v[0]*rcp, vec.v[1]*rcp };
}

// ---- Vector3 Functions ----

f32 skf_vec3_dot(skf_vec3 left, skf_vec3 right)
{
   return left.v[0]*right.v[0] + left.v[1]*right.v[1] + left.v[2]*right.v[2];
}
f32 skf_vec3_len(skf_vec3 vec)
{
   return sqrtf(skf_vec3_dot(vec, vec));
}
f32 skf_vec3_angle(skf_vec3 left, skf_vec3 right)
{
   f32 a = 1.0f / (skf_vec3_len(left) * skf_vec3_len(right)) * skf_vec3_dot(left, right);
   return acosf(a);
}
skf_vec3 skf_vec3_normalize(skf_vec3 vec)
{
   f32 rcp = 1.0f / skf_vec3_len(vec);
   return (skf_vec3){ vec.v[0]*rcp, vec.v[1]*rcp, vec.v[2]*rcp };
}
skf_vec3 skf_vec3_cross(skf_vec3 left, skf_vec3 right)
{
   f32 lx = left.v[0]; f32 ly = left.v[1]; f32 lz = left.v[2];
   f32 rx = right.v[0]; f32 ry = right.v[1]; f32 rz = right.v[2];

   return (skf_vec3){ ly*rz - ry*lz, lz*rx - rz*lx, lx*ry - rx*ly };
}
skf_vec3 skf_vec3_add(skf_vec3 left, skf_vec3 right)
{
   return (skf_vec3){
      left.v[0] + right.v[0],
      left.v[1] + right.v[1],
      left.v[2] + right.v[2] };
}
skf_vec3 skf_vec3_sub(skf_vec3 left, skf_vec3 right)
{
   return (skf_vec3){
      left.v[0] - right.v[0],
      left.v[1] - right.v[1],
      left.v[2] - right.v[2] };
}
skf_vec3 skf_vec3_neg(skf_vec3 vec)
{
   return (skf_vec3){
      -vec.v[0],
      -vec.v[1],
      -vec.v[2] };
}
skf_vec3 skf_vec3_mul(skf_vec3 left, skf_vec3 right)
{
   return (skf_vec3){
      left.v[0] * right.v[0],
      left.v[1] * right.v[1],
      left.v[2] * right.v[2] };
}
skf_vec3 skf_vec3_div(skf_vec3 left, skf_vec3 right)
{
   return (skf_vec3){
      left.v[0] * (1.0f / right.v[0]),
      left.v[1] * (1.0f / right.v[1]),
      left.v[2] * (1.0f / right.v[2]) };
}
skf_vec3 skf_vec3_rcp(skf_vec3 vec)
{
   return (skf_vec3){
      1.0f / vec.v[0],
      1.0f / vec.v[1],
      1.0f / vec.v[2] };
}
skf_vec3 skf_vec3_mul_f32(skf_vec3 vec, f32 scalar)
{
   return (skf_vec3){
      vec.v[0] * scalar,
      vec.v[1] * scalar,
      vec.v[2] * scalar };
}
skf_vec3 skf_vec3_lerp(skf_vec3 left, skf_vec3 right, f32 amount)
{
   return (skf_vec3){
      skf_lerp(left.v[0], right.v[0], amount),
      skf_lerp(left.v[1], right.v[1], amount),
      skf_lerp(left.v[2], right.v[2], amount) };
}

// ---- Vector4 Functions ----

f32 skf_vec4_dot(skf_vec4 left, skf_vec4 right)
{
   return left.v[0]*right.v[0] + left.v[1]*right.v[1] + left.v[2]*right.v[2] + left.v[3]*right.v[3];
}
f32 skf_vec4_len(skf_vec4 vec)
{
   return sqrtf(skf_vec4_dot(vec, vec));
}
skf_vec4 skf_vec4_normalize(skf_vec4 vec)
{
   f32 rcp = 1.0f / skf_vec4_len(vec);
   return (skf_vec4){ vec.v[0]*rcp, vec.v[1]*rcp, vec.v[2]*rcp, vec.v[3]*rcp };
}
skf_vec4 skf_vec4_sub(skf_vec4 left, skf_vec4 right)
{
   return (skf_vec4){
      left.v[0]-right.v[0],
      left.v[1]-right.v[1],
      left.v[2]-right.v[2],
      left.v[3]-right.v[3] };
}

// ---- Quaternion Functions ----

skf_vec3 skf_vec3_quat_rotate(skf_vec3 vec, skf_quat rot)
{
   skf_vec3 u = (skf_vec3){ rot.v[0], rot.v[1], rot.v[2] };
   f32 s = rot.v[3];

   skf_vec3 uv = skf_vec3_cross(vec, u);
   skf_vec3 uuv = skf_vec3_cross(uv, u);

   return skf_vec3_add(vec, skf_vec3_mul_f32(skf_vec3_add(skf_vec3_mul_f32(uv, s), uuv), 2));
}

skf_quat skf_quat_from_axis_angle(skf_vec3 axis, f32 angle)
{
   f32 half_a = angle*0.5f;
   f32 a = sinf(half_a);
   return (skf_quat){
      a * axis.v[0],
      a * axis.v[1],
      a * axis.v[2],
      cosf(half_a) };
}
skf_quat skf_quat_mul(skf_quat left, skf_quat right)
{
   return (skf_quat){
      left.v[3]*right.v[0] + left.v[0]*right.v[3] + left.v[1]*right.v[2] - left.v[2]*right.v[1],
      left.v[3]*right.v[1] - left.v[0]*right.v[2] + left.v[1]*right.v[3] + left.v[2]*right.v[0],
      left.v[3]*right.v[2] + left.v[0]*right.v[1] - left.v[1]*right.v[0] + left.v[2]*right.v[3],
      left.v[3]*right.v[3] - left.v[0]*right.v[0] - left.v[1]*right.v[1] - left.v[2]*right.v[2]
   };
}

// ---- Matrix4x4 Functions ----

skf_vec4 skf_vec4_mat4_transform(skf_vec4 vec, skf_mat4 mat)
{
   skf_vec4 res = (skf_vec4){ 0 };
   for (int i=0; i<4; i++)
   {
      for (int j=0; j<4; j++)
      {
         res.v[i] += mat.m[j][i] * vec.v[j];
      }
   }
   return res;
}
skf_vec3 skf_vec3_mat4_transform(skf_vec3 vec, skf_mat4 mat)
{
   skf_vec3 res = (skf_vec3){ 0 };
   for (int i=0; i<3; i++)
   {
      for (int j=0; j<3; j++)
      {
         res.v[i] += mat.m[j][i] * vec.v[j];
      }
   }
   return res;
}

skf_mat4 skf_mat4_sub(skf_mat4 left, skf_mat4 right)
{
   skf_mat4 res = left;
   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
   {
      res.m[i][j] -= right.m[i][j];
   }

   return res;
}
skf_mat4 skf_mat4_mul(skf_mat4 left, skf_mat4 right)
{
   skf_mat4 res = (skf_mat4){ 0 };
   for (int i=0; i<4; i++)
   {
      for (int j=0; j<4; j++)
      {
         f32 sum = 0.0f;

         for (int k=0; k<4; k++)
         {
            sum += left.m[k][j] * right.m[i][k];
         }

         res.m[i][j] = sum;
      }
   }
   return res;
}

skf_mat4 skf_mat4_transpose(skf_mat4 mat)
{
   skf_mat4 res = (skf_mat4){ 0 };
   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
   {
      res.m[i][j] = mat.m[j][i];
   }
   return res;
}
skf_mat4 skf_mat4_inverse(skf_mat4 mat)
{
   skf_mat4 alt = mat;
   skf_mat4 res = (skf_mat4){
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
   };

   for (int i=0; i<4; i++)
   {
      f32 val = alt.m[i][i];
      if (val == 0.0f)
      {
         res = mat;
         break;
      }

      for (int j=0; j<4; j++)
      {
         f32 rcp = 1.0f / val;
         alt.m[i][j] *= rcp;
         res.m[i][j] *= rcp;
      }

      for (int j=0; j<4; j++)
      {
         f32 tmp = alt.m[j][i];
         for (int k=0; k<4; k++)
         {
            if (j == i)
               break;
            alt.m[j][k] -= alt.m[i][k] * tmp;
            res.m[j][k] -= res.m[i][k] * tmp;
         }
      }
   }

   return res;
}

skf_mat4 skf_mat4_translate(skf_vec3 translation)
{
   return (skf_mat4){
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      translation.v[0], translation.v[1], translation.v[2], 1
   };
}
skf_mat4 skf_mat4_scale(skf_vec3 scale)
{
   return (skf_mat4){
      scale.v[0], 0, 0, 0,
      0, scale.v[1], 0, 0,
      0, 0, scale.v[2], 0,
      0, 0, 0, 1
   };
}
skf_mat4 skf_mat4_rotate(skf_quat rotation)
{
   f32 v0 = rotation.v[0]; // X
   f32 v1 = rotation.v[1]; // Y
   f32 v2 = rotation.v[2]; // Z
   f32 v3 = rotation.v[3]; // W
   return (skf_mat4){
      2*(v3*v3 + v0*v0)-1, 2*(v0*v1 - v3*v2)  , 2*(v0*v2 + v3*v1)  , 0,
      2*(v0*v1 + v3*v2)  , 2*(v3*v3 + v1*v1)-1, 2*(v1*v2 - v3*v0)  , 0,
      2*(v0*v2 - v3*v1)  , 2*(v1*v2 + v3*v0)  , 2*(v3*v3 + v2*v2)-1, 0,
      0, 0, 0, 1
   };
}
skf_mat4 skf_mat4_rotate_x(f32 angle)
{
   f32 c = cosf(angle);
   f32 s = sinf(angle);
   return (skf_mat4){
      1, 0, 0, 0,
      0, c, s, 0,
      0,-s, c, 0,
      0, 0, 0, 1
   };
}
skf_mat4 skf_mat4_rotate_y(f32 angle)
{
   f32 c = cosf(angle);
   f32 s = sinf(angle);
   return (skf_mat4){
      c, 0,-s, 0,
      0, 1, 0, 0,
      s, 0, c, 0,
      0, 0, 0, 1
   };
}
skf_mat4 skf_mat4_rotate_z(f32 angle)
{
   f32 c = cosf(angle);
   f32 s = sinf(angle);
   return (skf_mat4){
       c, s, 0, 0,
      -s, c, 0, 0,
       0, 0, 1, 0,
       0, 0, 0, 1
   };
}

skf_mat4 skf_mat4_view_simple(skf_vec3 position, skf_quat rotation)
{
   f32 r0 = rotation.v[0]; // X
   f32 r1 = rotation.v[1]; // Y
   f32 r2 = rotation.v[2]; // Z
   f32 r3 = rotation.v[3]; // W

   skf_mat4 res = (skf_mat4){
      2*(r3*r3 + r0*r0)-1, 2*(r0*r1 + r3*r2)  , 2*(r0*r2 - r3*r1)  , 0,
      2*(r0*r1 - r3*r2)  , 2*(r3*r3 + r1*r1)-1, 2*(r1*r2 + r3*r0)  , 0,
      2*(r0*r2 + r3*r1)  , 2*(r1*r2 - r3*r0)  , 2*(r3*r3 + r2*r2)-1, 0,
      0, 0, 0, 1
   };

   for (int i=0; i<3; i++)
   {
      for (int j=0; j<3; j++)
      {
         res.m[3][i] -= res.m[j][i] * position.v[j];
      }
   }

   return res;
}
skf_mat4 skf_mat4_view_target(skf_vec3 position, skf_vec3 target, skf_vec3 up)
{
   skf_vec3 axis_z = skf_vec3_normalize(skf_vec3_sub(target, position));
   skf_vec3 axis_x = skf_vec3_normalize(skf_vec3_cross(up, axis_z));
   skf_vec3 axis_y = skf_vec3_cross(axis_z, axis_x);

   skf_vec3 eye = skf_vec3_neg(position);

   return (skf_mat4){
      axis_x.v[0], axis_y.v[0], axis_z.v[0], 0,
      axis_x.v[1], axis_y.v[1], axis_z.v[1], 0,
      axis_x.v[2], axis_y.v[2], axis_z.v[2], 0,
      skf_vec3_dot(axis_x, eye), skf_vec3_dot(axis_x, eye), skf_vec3_dot(axis_x, eye), 1 };
}

// Projection functions!!!
// ... Might need some rethinking but currently appear to give correct results...

skf_mat4 skf_mat4_orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far)
{
   skf_mat4 res = (skf_mat4){ 0 };

   res.m[0][0] = 2.0f / (right - left);
   res.m[1][1] = 2.0f / (top - bottom);
   res.m[2][2] =-(2.0f / (far - near));
   res.m[3][3] = 1.0f;

   res.m[3][0] = (right + left) * -(1.0f / (right - left));
   res.m[3][1] = (top + bottom) * -(1.0f / (top - bottom));
   res.m[3][2] = (far + near) * -(1.0f / (far - near));

   return res;
}
skf_mat4 skf_mat4_projection(f32 fov, f32 aspect, f32 near, f32 far)
{
   skf_mat4 res = (skf_mat4){ 0 };

   f32 tan_half_fov = tanf(fov * 0.5f);

   f32 range = 1.0f / (near - far);

   res.m[0][0] = 1.0f / (tan_half_fov * aspect);
   res.m[1][1] = 1.0f / tan_half_fov;
   res.m[2][2] = (near + far) * range;
   res.m[2][3] =-1;
   res.m[3][2] = near * 2.0f * far * range;

   return res;
}
