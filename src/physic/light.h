#ifndef LIGHT_H
#define LIGHT_H

#include <stdint.h>
#include <stddef.h>

#include "../maths/vec4.h"
#include "../maths/point.h"
#include "../shape/sphere.h"

typedef struct s_light_data {
	t_point	p;
	t_vec4	c;
	t_vec4	n;
}	t_light_data;

typedef struct s_amb_light {
	float	ratio;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_amb_light;

typedef struct s_light
{
	t_point	coords;
	float	ratio;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	char	padding[4];
}	t_light;

static inline __attribute__((always_inline)) int	compute_ambient(t_sphere *sp, const size_t id, const t_amb_light al)
{
	return ((((int)(((uint8_t *)sp->sr.r->buffer)[id] * (al.r / 255.0f * al.ratio))) << 16) | (((int)(((uint8_t *)sp->sr.g->buffer)[id] * (al.g / 255.0f * al.ratio))) << 8) | (((int)(((uint8_t *)sp->sr.b->buffer)[id] * (al.b / 255.0f * al.ratio)))));
}

int	lighting_sphere(t_sphere *sp, const t_amb_light al, const t_light light, const size_t id, t_point point, t_vec4 v_normal, t_vec4 v_eye);

#endif //LIGHT_H
