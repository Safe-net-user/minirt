#include "ray.h"

t_point	position(const t_ray r, const double t)
{
	return (add_vector_to_point(r.origin, mul_vector(r.direction, t)));
}