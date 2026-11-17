#include "light.h"
#include "maths/vec4.h"
#include "shape/color.h"
#include "core.h"
#include <stdbool.h>
#include <stddef.h>

#include "ray.h"

int	lighting_sphere(t_sphere *sp, const t_amb_light al, const t_light light, const size_t id, t_point point, t_vec4 v_normal, t_vec4 v_eye, const int is_shadowed)
{
	t_rgba		final_color;
	t_rgba		object_color;
	t_vec4	v_light;
	float	dot_product;

	(void)is_shadowed;
	(void)v_eye;
	// Extract material's color
	object_color = set_rgba(((uint8_t *)sp->sr.r->buffer)[id], ((uint8_t *)sp->sr.g->buffer)[id], ((uint8_t *)sp->sr.b->buffer)[id], 0.0f);

	// Ambient reflection
	final_color = compute_ambient(object_color, al);
	if (is_shadowed)
		return (rgba_to_int(final_color));
	// Diffuse reflection
	v_light = sub_points(light.coords, point);
	v_light = normalize_vector(v_light);
	dot_product = compute_dot(v_normal, v_light);
	if (dot_product <= 0)
		return (rgba_to_int(final_color));
	// on utilise directement light.ratio car par defaut, on nous demande de ne pas utiliser la couleur des lumières
	final_color = add_rgba(final_color, mul_rgba(mul_rgba(object_color, light.ratio), dot_product));
	return (rgba_to_int(final_color));
}
