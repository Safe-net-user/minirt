#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include "maths.h"

typedef struct s_cam
{
	t_point	direction;
	t_point	coords;
	uint8_t	fov;
	char	padding[7];
}	t_cam;

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

#endif //TYPES_H
