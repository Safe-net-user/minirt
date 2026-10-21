#ifndef SPHERES_H
# define SPHERES_H

#include <stdint.h>
#include "vector.h"
#include "macros.h"
#include "../maths/vec4.h"
#include "../maths/point.h"

typedef struct s_ray t_ray;

typedef struct s_sphere_tracer
{
	t_vec	*x;
	t_vec	*y;
	t_vec	*z;
	t_vec	*radius;
}	t_st;

typedef struct s_sphere_render
{
	t_vec	*r;
	t_vec	*g;
	t_vec	*b;
	uint8_t	padding[STRUCT_ALIGNMENT_32 - (sizeof(t_vec *) * 3)];
}	t_sr;

typedef struct s_sphere
{
	t_st	st;
	t_sr	sr;
}	t_sphere;

static inline t_vec4	normal_at(const t_point origin, const t_point p)
{
	t_vec4	v;

	v = sub_points(origin, p);
	return (normalize_vector(v, compute_magnitude(v)));
}

static inline t_vec4	reflect_at(const t_vec4 in, const t_vec4 normal)
{
	return (mul_vector(mul_vector(sub_vectors(in, normal), 2), compute_dot(in, normal)));
}

void	intersect(t_sphere *sp, size_t sp_id, t_ray *r);

_Static_assert(sizeof(t_st) == 32);
_Static_assert(sizeof(t_sr) == 32);

#endif //SPHERES_H
