#include "sphere.h"
#include <math.h>
#include <stddef.h>
#include "minirt.h"
#include "maths.h"
#include "shapes.h"

void	intersect(t_mrt *mrt, t_sphere *sp, size_t sp_id, t_ray r)
{
	t_point		center_sp;
	t_vec4		sphere_to_ray;
	float		discriminant;
	float		a;
	float		b;
	float		c;

	mrt.intersect->count->buffer[sp_id] = 0;
	set_point(&center_sp, mrt->sphere.st.x->buffer[sp_id], mrt->sphere.st.y->buffer[sp_id], mrt->sphere.st.z->buffer[sp_id]);
	sub_points(&sphere_to_ray, r.origin, center_sp);
	a = compute_dot(r.direction, r.direction);
	b = 2 * compute_dot(r.direction, sphere_to_ray);
	c = compute_dot(sphere_to_ray, sphere_to_ray);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (intersect);
	intersect.inter[0] = (-b - sqrt(discriminant)) / (2 * a);
	intersect.inter[1] = (-b + sqrt(discriminant)) / (2 * a);
	if (intersect.inter[0] == intersect.inter[1])
		intersect->count->buffer[sp_id] = 1;
	else
		intersect->count->buffer[sp_id] = 2;
	return (intersect);



}
