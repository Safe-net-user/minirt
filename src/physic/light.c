#include "light.h"
#include "types.h"
#include <math.h>
#include <stdio.h>
#include <stddef.h>

static int mul_colors(const float n, const int c)
{
	return (int)fminf(255, ((c & 0x00FF0000) >> 16) * n) << 16 | (int)fminf(255, ((c & 0x0000FF00) >> 8) * n) << 8 | (int)(fminf(255, (c & 0x000000FF) * n));
}

static int add_colors(const int c1, const int c2)
{
	return (int)fminf(255, ((c1 & 0x00FF0000) >> 16) + ((c2 & 0x00FF0000) >> 16)) << 16 | (int)fminf(255, ((c1 & 0x0000FF00) >> 8) + ((c2 & 0x0000FF00) >> 8)) << 8 | (int)(fminf(255, (c1 & 0x000000FF) + (c2 & 0x000000FF)));
}

int	lighting_sphere(t_sphere *sp, const t_amb_light al, const t_light light, const size_t id, t_point point, t_vec4 v_normal, t_vec4 v_eye)
{
	int		final_color;
	int		material_color;
	t_vec4	v_light;
	float	dot_product;

	(void)v_eye;
	// Extract material's color
	material_color = (int)((uint8_t *)sp->sr.r->buffer)[id] << 16 | (int)((uint8_t *)sp->sr.g->buffer)[id] << 8 | (int)((uint8_t *)sp->sr.b->buffer)[id];

	// Ambient reflection
	final_color = compute_ambient(sp, id, al);

	// Diffuse reflection
	v_light = sub_points(light.coords, point);
	v_light = normalize_vector(v_light, compute_magnitude(v_light));
	dot_product = compute_dot(v_normal, v_light);
	if (dot_product <= 0)
		return (final_color);
	// on utilise directement light.ratio car par defaut, on nous demande de ne pas utiliser la couleur des lumières
	final_color = add_colors(final_color, mul_colors(dot_product, mul_colors(light.ratio, material_color)));
	return (final_color);
}
