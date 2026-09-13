#ifndef SHAPE_H
#define SHAPE_H

#include "types.h"
#include "macros.h"
#include "vector.h"

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

_Static_assert(sizeof(t_st) == 32);
_Static_assert(sizeof(t_sr) == 32);
_Static_assert(sizeof(t_pt) == 64);
_Static_assert(sizeof(t_pr) == 32);
_Static_assert(sizeof(t_ct) == 64);
_Static_assert(sizeof(t_cr) == 32);

#endif //SHAPE_H
