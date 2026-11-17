#include <stddef.h>
#include "core.h"
#include "macros.h"
#include "minirt.h"
#include "mlx.h"
#include "entity/camera.h"
#include "physic/intersection.h"
#include "physic/light.h"
#include "physic/ray.h"

static t_ray intersect_world(t_mrt *mrt, t_ray r)
{
	size_t sp_i;

	sp_i = 0;
	while (sp_i < mrt->sphere.st.x->size)
	{
		intersect(&mrt->sphere, sp_i, &r);
		if (r.intersect.is_hit)
			return (r);
		sp_i++;
	}
	return (r);
}

int is_shadowed(t_mrt *mrt, const t_vec4 normal, const t_point p)
{
	t_vec4	v;
	t_point	origin;
	t_ray	r;
	float	distance;
	t_vec4	direction;

	origin = add_vector_to_point(p, mul_vector(normal, EPSILON));
	v = sub_points(mrt->light.coords, origin);
	distance = compute_magnitude(v);
	direction = normalize_vector(v);
	r = intersect_world(mrt, set_ray(origin, direction));
	if (r.intersect.is_hit && r.intersect.t < distance)
		return (true);
	return (false);
}