#ifndef SET_PLANE_H
#define SET_PLANE_H

#include "minirt.h"
#include "vector.h"

static inline void	set_plane_coords(t_pt *pt, float x, float y, float z)
{
	push_back_vector(pt->x, &x);
	push_back_vector(pt->y, &y);
	push_back_vector(pt->z, &z);
}

static inline void	set_plane_direction(t_pt *pt, float dx, float dy, float dz)
{
	push_back_vector(pt->dx, &dx);
	push_back_vector(pt->dy, &dy);
	push_back_vector(pt->dz, &dz);
}

static inline void set_plane_color(t_pr *pr, unsigned int r, unsigned int g, unsigned int b)
{
	push_back_vector(pr->r, &r);
	push_back_vector(pr->g, &g);
	push_back_vector(pr->b, &b);
}

#endif //SET_PLANE_H
