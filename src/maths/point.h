#ifndef POINT_H
# define POINT_H

#include "vec4.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_point;

static  inline __attribute__((always_inline)) t_point	set_point(const float x, const float y, const float z)
{
	return ((t_point){x, y, z, 1.0});
}

static inline __attribute__((always_inline)) t_point	add_vector_to_point(const t_point p, const t_vec4 v)
{
	return ((t_point){p.x + v.x,p.y + v.y,p.z + v.z,p.w + v.w});
}

static inline __attribute__((always_inline)) t_vec4	sub_points(const t_point p1, const t_point p2)
{
	return ((t_vec4){p1.x - p2.x, p1.y - p2.y,p1.z - p2.z, p1.w - p2.w});
}

static inline __attribute__((always_inline)) t_point	sub_vector_from_point(const t_vec4 v, const t_point p)
{
	return ((t_point){p.x - v.x, p.y - v.y, p.z - v.z, p.w - v.w});
}

#endif //POINT_H
