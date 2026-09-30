#ifndef SPHERES_H
# define SPHERES_H

#include <stdint.h>
#include "vector.h"
#include "macros.h"

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

_Static_assert(sizeof(t_st) == 32);
_Static_assert(sizeof(t_sr) == 32);

#endif //SPHERES_H
