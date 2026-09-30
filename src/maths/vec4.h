#ifndef VEC4_H
#define VEC4_H

#include <math.h>

typedef struct s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

static  inline __attribute__((__always_inline__)) t_vec4 set_vec4(const float x, const float y, const float z)
{
	return ((t_vec4){x, y, z, 0.0});
}

static inline __attribute__((__always_inline__)) t_vec4	add_vectors(const t_vec4 v1, const t_vec4 v2)
{
	return ((t_vec4){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z,v1.w + v2.w});
}

static inline __attribute__((__always_inline__)) t_vec4	sub_vectors(const t_vec4 v1, const t_vec4 v2)
{
	return ((t_vec4){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w});
}

static inline __attribute__((__always_inline__)) t_vec4	negate_vector(const t_vec4 v)
{
	return ((t_vec4){-v.x, -v.y, -v.z, -v.w});
}

static inline __attribute__((always_inline)) t_vec4	mul_vector(const t_vec4 v, const float s)
{
	return ((t_vec4){v.x * s, v.y * s, v.z * s, v.w * s});
}

static inline __attribute__((always_inline)) float	compute_magnitude(const t_vec4 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}

static inline __attribute__((always_inline)) t_vec4	normalize_vector(const t_vec4 v, const float magnitude)
{
	float	s;

	if (!magnitude || magnitude == 1.0)
		return (v);
	s = 1.0 / magnitude;
	return (mul_vector(v, s));
}

static inline __attribute__((always_inline)) float	compute_dot(const t_vec4 v1, const t_vec4 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

static inline __attribute__((always_inline)) t_vec4	compute_cross(const t_vec4 v1, const t_vec4 v2)
{
	return ((t_vec4){
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x,
		0.0f
		});
}

#endif //VEC4_H
