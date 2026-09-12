#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef struct t_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct t_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

typedef struct s_cam
{
	t_vec3	direction;
	t_vec3	coords;
	uint8_t	fov;
	char	padding[7];
}	t_cam;

typedef struct s_amb_light {
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	ratio;
}	t_amb_light;

typedef struct s_light
{
	t_vec3	coords;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	ratio;
	char	padding[4];
}	t_light;

#endif //TYPES_H
