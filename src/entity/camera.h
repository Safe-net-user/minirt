#ifndef MINIRT_CAMERA_H
#define MINIRT_CAMERA_H

#include <stdint.h>
# include <math.h>
# include "physic/ray.h"
#include "maths/point.h"
#include "maths/vec4.h"

# define VIEWPORT_DISTANCE 1

typedef struct s_cam
{
	t_vec4	direction;
	t_vec4	forward;
	t_vec4	right;
	t_vec4	up;
	t_point	coords;
	float	half_width;
	float	half_height;
	float	pixel_size;
	uint8_t	fov;
}	t_cam;

static inline __attribute__((always_inline)) float	compute_half_view(const uint8_t fov)
{
	return (VIEWPORT_DISTANCE * tanf((fov * 0.5f) * (M_PI / 180.0f)));
}

static inline __attribute__((always_inline))float	compute_aspect(const int width, const int height)
{
	return ((float)width / (float)height);
}

static inline __attribute__((always_inline)) t_vec4	compute_forward(const t_cam c)
{
	return (normalize_vector(c.direction));
}

static inline __attribute__((always_inline)) t_vec4
compute_right(const t_vec4 f)
{
	return (normalize_vector(
		compute_cross(
			set_vec4(0, 1, 0),
			f)));
}
static inline __attribute__((always_inline)) t_vec4	compute_up(const t_vec4 f, const t_vec4 r)
{
	return (compute_cross(f, r));
}

t_ray	camera_ray(t_cam c, size_t x, size_t y);
float	compute_pixel_size(t_cam *c, int width, int height, uint8_t fov);

#endif //MINIRT_CAMERA_H
