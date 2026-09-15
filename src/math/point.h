#ifndef POINT_H
# define POINT_H

#include "vec4.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_point;

static  __attribute__((__always_inline__)) void set_point(t_point *p, double x, double y, double z)
{
	p->x = x;
	p->y = y;
	p->z = z;
	p->w = 1.0;
}

static __attribute__((always_inline)) void	sub_points(t_vec4 *v, const t_point p1, const t_point p2)
{
	v->x = p1.x - p2.x;
	v->y = p1.y - p2.y;
	v->z = p1.z - p2.z;
	v->w = p1.w - p2.w;
}

static __attribute__((always_inline)) void	sub_vector_from_point(t_vec4 *fv, t_vec4 v,t_point p)
{
	fv->x = p.x - v.x;
	fv->y = p.y - v.y;
	fv->z = p.z - v.z;
	fv->w = p.w - v.w;
}

void	alloc_point(t_point *p);
#endif //POINT_H
