#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H

#include "point.h"
#include "matrix4.h"

typedef struct s_scaling
{
	float	x;
	float	y;
	float	z;
}	t_scaling;

struct s_data
{
	float	x;
	float	y;
	float	z;
};

struct s_data_shearing
{
	float	xy;
	float	xz;
	float	yx;
	float	yz;
	float	zx;
	float	zy;
};

static inline __attribute__((always_inline)) t_m4	translation_matrix4(const struct s_data xyz)
{
	return ((t_m4){
			{
				1.0,
				0.0,
				0.0,
				xyz.x,
				0.0,
				1.0,
				0.0,
				xyz.y,
				0.0,
				0.0,
				1.0,
				xyz.z,
				0.0,
				0.0,
				0.0,
				1.0
			}});
}

static inline __attribute__((always_inline)) t_point	mul_translation_matrix(const t_point p, const struct s_data xyz)
{
	t_m4 translation;

	translation = translation_matrix4(xyz);
	return (mul_matrix4_by_point(p, translation));
}

static inline __attribute__((always_inline)) t_m4	scaling_matrix4(const struct s_data xyz)
{
	return ((t_m4) {
		{
			xyz.x,
			0.0,
			0.0,
			0.0,
			0.0,
			xyz.y,
			0.0,
			0.0,
			0.0,
			0.0,
			xyz.z,
			0.0,
			0.0,
			0.0,
			0.0,
			1.0
		}});
}

static inline __attribute__((always_inline)) t_point	mul_scaling_matrix_to_point(const t_point p, const struct s_data xyz)
{
	t_m4	scaling;

	scaling = scaling_matrix4(xyz);
	return (mul_matrix4_by_point(p, scaling));
}

static inline __attribute__((always_inline)) t_vec4	mul_scaling_matrix_to_vector(const t_vec4 v, const struct s_data xyz)
{
	t_m4	scaling;

	scaling = scaling_matrix4(xyz);
	return (mul_matrix4_by_vector(v, scaling));
}

static inline __attribute__((always_inline)) t_m4	shearing_matrix4(const struct s_data_shearing d)
{
	return ((t_m4){
		{
			1.0,
			d.xy,
			d.xz,
			0.0,
			d.yx,
			1.0,
			d.yz,
			0.0,
			d.zx,
			d.zy,
			1.0,
			0.0,
			0.0,
			0.0,
			0.0,
			1.0
		}});
}

t_point	mul_inv_translation_matrix(t_point p, struct s_data xyz);
t_vec4	mul_inv_scaling_matrix(t_vec4 v, struct s_data xyz);
t_m4	rotation_x(float r);
t_m4	rotation_y(float r);
t_m4	rotation_z(float r);

#endif //TRANSFORMATIONS_H
