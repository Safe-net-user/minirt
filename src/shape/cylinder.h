#ifndef CYLINDER_H
#define CYLINDER_H

#include <stdint.h>
#include "vector.h"
#include "macros.h"

typedef struct s_cylinder_tracer
{
	t_vec	*x;
	t_vec	*y;
	t_vec	*z;
	t_vec	*dx;
	t_vec	*dy;
	t_vec	*dz;
	t_vec	*radius;
	t_vec	*height;
}	t_ct;

typedef struct s_cylinder_render
{
	t_vec	*r;
	t_vec	*g;
	t_vec	*b;
	uint8_t	padding[STRUCT_ALIGNMENT_32 - (sizeof(t_vec *) * 3)];
}	t_cr;

typedef struct s_cylinder
{
	t_ct	ct;
	t_cr	cr;
}	t_cylinder;

_Static_assert(sizeof(t_ct) == 64);
_Static_assert(sizeof(t_cr) == 32);
#endif //CYLINDER_H
