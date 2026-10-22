#ifndef SPHERES_H
# define SPHERES_H

#include <stdint.h>
#include "vector.h"
#include "macros.h"
#include "maths/vec4.h"
#include "maths/point.h"

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
	return (normalize_vector(sub_points(p, origin)));
}

static inline t_vec4	reflect_at(const t_vec4 in, const t_vec4 normal)
{
	return (sub_vectors(mul_vector(mul_vector(normal, 2), compute_dot(in, normal)), in));
}

_Static_assert(sizeof(t_st) == 32, "maximum st struct size exceeded");
_Static_assert(sizeof(t_sr) == 32, "maximum sr struct size exceeded");

#endif //SPHERES_H
