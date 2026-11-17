#include "ray.h"

#include "../../include/macros.h"

t_point	position(const t_ray r, const float t)
{
	return (add_vector_to_point(r.origin, mul_vector(r.direction, t)));
}

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
	float		t[2];

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
		return ;
	sqrt_d = fsqrt(discriminant);
	t[0] = (-b - sqrt_d) / (2.0f * a);
	t[1] = (-b + sqrt_d) / (2.0f * a);
	if (t[0] >= 0 && t[1] >= EPSILON && r->intersect.t >= t[0])
	{
		r->intersect.object.sp = sp;
		r->intersect.t = t[0];
		r->intersect.id = sp_id;
		r->intersect.is_hit = 1;
	}
	else if (t[0] < 0 && t[1] >= EPSILON && r->intersect.t >= t[1])
	{
		r->intersect.object.sp = sp;
		r->intersect.t = t[1];
		r->intersect.id = sp_id;
		r->intersect.is_hit = 1;
	}
}