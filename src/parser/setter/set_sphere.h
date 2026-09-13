#ifndef SET_SPHERE_H
#define SET_SPHERE_H

#include "minirt.h"
#include "vector.h"

static inline void	set_sphere_coords(t_st *st, float x, float y, float z)
{
	push_back_vector(st->x, &x);
	push_back_vector(st->y, &y);
	push_back_vector(st->z, &z);
}

static inline void	set_sphere_radius(t_st *st, float diam)
{
	float	radius;

	radius = diam / 2.0f;
	push_back_vector(st->radius, &radius);
}

static inline void	set_sphere_color(t_sr *sr, unsigned int r, unsigned int g, unsigned int b)
{
	push_back_vector(sr->r, &r);
	push_back_vector(sr->g, &g);
	push_back_vector(sr->b, &b);
}

#endif //MINIRT_SET_SPHERE_H
