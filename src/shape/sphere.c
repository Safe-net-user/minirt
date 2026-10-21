#include <stddef.h>
#include "../physic/ray.h"
#include "sphere.h"
#include "minirt.h"
#include "maths.h"
#include <stdio.h>

void	intersect(t_sphere *sp, size_t sp_id, t_ray *r)
{
	t_vec4		sphere;
	t_point		sp_coords;
	float		radius;
	float		a;
	float		b;
	float		c;
	float		discriminant;
	float		sqrt_d;

	sp_coords = set_point(
		((float *)sp->st.x->buffer)[sp_id],
		((float *)sp->st.y->buffer)[sp_id],
		((float *)sp->st.z->buffer)[sp_id]
	);
	sphere = sub_points(r->origin, sp_coords);
	radius = ((float *)sp->st.radius->buffer)[sp_id];
	a = compute_dot(r->direction, r->direction);
	b = 2.0f * compute_dot(r->direction, sphere);
	c = compute_dot(sphere, sphere) - radius * radius;
	discriminant = b * b - 4.0f * a * c;
	if (discriminant < 0.0f)
	{
		r->intersect.is_hit = 0;
		return ;
	}
	sqrt_d = fsqrt(discriminant);
	r->intersect.id = sp_id;
	r->intersect.object.sp = sp;
	r->intersect.t[0] = (-b - sqrt_d) / (2.0f * a);
	r->intersect.t[1] = (-b + sqrt_d) / (2.0f * a);
	if (r->intersect.t[0] >= 0 && r->intersect.t[1] >= 0)
		r->intersect.is_hit = 1;
	else
		r->intersect.is_hit = 0;
}