#ifndef RAY_H
# define RAY_H

#include "../maths/vec4.h"
#include "../maths/point.h"
#include "intersection.h"

typedef struct s_ray
{
	t_point		origin;
	t_vec4		direction;
	t_intersect	intersect;
}	t_ray;

static inline __attribute__((always_inline)) t_ray	set_ray(const t_point p, const t_vec4 v)
{
	return ((t_ray){p, v});
}

t_point	position(t_ray r, double t);

#endif //RAY_H
