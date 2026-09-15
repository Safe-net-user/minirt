#ifndef VEC4_H
#define VEC4_H

#include <math.h>

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

static  __attribute__((__always_inline__)) void set_vec4(t_vec4 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = 0.0;
}

static __attribute__((__always_inline__)) void	sub_vectors(t_vec4 *fv, t_vec4 v1, t_vec4 v2)
{
	fv->x = v1.x - v2.x;
	fv->y = v1.y - v2.y;
	fv->z = v1.z - v2.z;
	fv->w = v1.w - v2.w;
}

static __attribute__((__always_inline__)) void	negate_vector(t_vec4 *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
	v->w = -v->w;
}

static __attribute__((always_inline)) void	mul_vector(t_vec4 *v, double s)
{
	v->x *= s;
	v->y *= s;
	v->z *= s;
	v->w *= s;
}

static __attribute__((always_inline)) double	compute_magnitude(t_vec4 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}

static __attribute__((always_inline)) void	normalize_vector(t_vec4 *v, double magnitude)
{
	double	s;

	if (!magnitude || magnitude == 1.0)
		return ;
	s = 1.0 / magnitude;
	mul_vector(v, s);
}

static __attribute__((always_inline)) double	compute_dot(t_vec4 v1, t_vec4 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

static __attribute__((always_inline)) t_vec4	*compute_cross(t_vec4 *vf, t_vec4 v1, t_vec4 v2)
{
	set_vec4(
		vf,
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
		);
	return (vf);
}

#endif //VEC4_H
