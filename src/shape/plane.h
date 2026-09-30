#ifndef PLANE_H
#define PLANE_H

#include <stdint.h>
#include "vector.h"
#include "macros.h"

typedef struct s_plane_tracer
{
	t_vec	*x;
	t_vec	*y;
	t_vec	*z;
	t_vec	*dx;
	t_vec	*dy;
	t_vec	*dz;
	uint8_t	padding[STRUCT_ALIGNMENT_64 - (sizeof(t_vec *) * 6)];
}	t_pt;

typedef struct s_plane_render
{
	t_vec	*r;
	t_vec	*g;
	t_vec	*b;
	uint8_t	padding[STRUCT_ALIGNMENT_32 - (sizeof(t_vec *) * 3)];
}	t_pr;

typedef struct s_plane
{
	t_pt	pt;
	t_pr	pr;
}	t_plane;

_Static_assert(sizeof(t_pt) == 64);
_Static_assert(sizeof(t_pr) == 32);

#endif //PLANE_H
