#include "camera.h"
#include "physic/ray.h"

float	compute_pixel_size(t_cam *c, const int width, const int height, const uint8_t fov)
{
	float	half_view;
	float	aspect;

	half_view = compute_half_view(fov);
	aspect = compute_aspect(width, height);
	if (aspect >= 1.0f)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
		return ((c->half_width * 2.0f) / width);
	}
	c->half_width = half_view * aspect;
	c->half_height = half_view;
	return (c->half_height * 2.0f / height);
}

t_ray	camera_ray(const t_cam c, const size_t x, const size_t y)
{
	float	x_offset;
	float	y_offset;
	t_point	p;
	t_vec4	d;

	x_offset = (x + 0.5) * c.pixel_size - c.half_width;
	y_offset = c.half_height - (y + 0.5f) * c.pixel_size;
	p = add_vector_to_point(
		c.coords,
		add_vectors(
			mul_vector(c.forward, VIEWPORT_DISTANCE),
			add_vectors(
				mul_vector(
					c.right,
					x_offset),
				mul_vector(
					c.up,
					y_offset)))
	);
	d = normalize_vector(sub_points(p, c.coords));
	return (set_ray(c.coords, d));
	
}