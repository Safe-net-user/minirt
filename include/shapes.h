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
	t_vec	*diam;
}	__attribute__((__aligned__(STRUCT_ALIGNMENT_32))) t_st;

typedef struct s_sphere_render
{
	uint8_t *r;
	uint8_t	*g;
	uint8_t	*b;
	uint8_t	padding[STRUCT_ALIGNMENT_32 - (sizeof(t_vec *) * 3)];
}	__attribute__((__aligned__(STRUCT_ALIGNMENT_32))) t_sr;

typedef struct s_sphere
{
	t_st	*st;
	t_sr	*sr;
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
}	__attribute__((__aligned__(STRUCT_ALIGNMENT_64))) t_pt;

typedef struct s_plane_render
{
	uint8_t	*r;
	uint8_t	*g;
	uint8_t	*b;
	uint8_t	padding[STRUCT_ALIGNMENT_32 - (sizeof(t_vec *) * 3)];
}	__attribute__((__aligned__(STRUCT_ALIGNMENT_32))) t_pr;

typedef struct s_plane
{
	t_pt	*pt;
	t_pr	*pr;
}	t_plane;

typedef struct s_cylinder_tracer
{
	t_vec	*x;
	t_vec	*y;
	t_vec	*z;
	t_vec	*dx;
	t_vec	*dy;
	t_vec	*dz;
	t_vec	*diam;
	t_vec	*height;
}	__attribute__((__aligned__(STRUCT_ALIGNMENT_64))) t_ct;

typedef struct s_cylinder_render
{
	uint8_t	*r;
	uint8_t	*g;
	uint8_t	*b;
	uint8_t	padding[STRUCT_ALIGNMENT_32 - (sizeof(t_vec *) * 3)];
}	__attribute__((__aligned__(STRUCT_ALIGNMENT_32))) t_cr;

typedef struct s_cylinder
{
	t_ct	*ct;
	t_cr	*cr;
}	t_cylinder;
#endif //SHAPE_H
