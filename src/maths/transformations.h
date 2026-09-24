#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H

#include "point.h"
#include "matrix/matrix4.h"

typedef struct s_scaling
{
	double	x;
	double	y;
	double	z;
}	t_scaling;

struct s_data
{
	double	x;
	double	y;
	double	z;
};

struct s_data_shearing
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
};

static inline __attribute__((always_inline)) void	translation_matrix4(t_m4 *m, const struct s_data xyz)
{
	m->d[0] = 1.0;
	m->d[1] = 0.0;
	m->d[2] = 0.0;
	m->d[3] = xyz.x;
	m->d[4] = 0.0;
	m->d[5] = 1.0;
	m->d[6] = 0.0;
	m->d[7] = xyz.y;
	m->d[8] = 0.0;
	m->d[9] = 0.0;
	m->d[10] = 1.0;
	m->d[11] = xyz.z;
	m->d[12] = 0.0;
	m->d[13] = 0.0;
	m->d[14] = 0.0;
	m->d[15] = 1.0;
}

static inline __attribute__((always_inline)) void	mul_translation_matrix(t_point *fp, const t_point p, const struct s_data xyz)
{
	t_m4 translation;

	translation_matrix4(&translation, xyz);
	mul_matrix4_by_point(fp, p, translation);
}

static inline __attribute__((always_inline)) void	scaling_matrix4(t_m4 *m, const struct s_data xyz)
{
	m->d[0] = xyz.x;
	m->d[1] = 0.0;
	m->d[2] = 0.0;
	m->d[3] = 0.0;
	m->d[4] = 0.0;
	m->d[5] = xyz.y;
	m->d[6] = 0.0;
	m->d[7] = 0.0;
	m->d[8] = 0.0;
	m->d[9] = 0.0;
	m->d[10] = xyz.z;
	m->d[11] = 0.0;
	m->d[12] = 0.0;
	m->d[13] = 0.0;
	m->d[14] = 0.0;
	m->d[15] = 1.0;
}

static inline __attribute__((always_inline)) void	mul_scaling_matrix_to_point(t_point *fp, const t_point p, const struct s_data xyz)
{
	t_m4	scaling;

	scaling_matrix4(&scaling, xyz);
	mul_matrix4_by_point(fp, p, scaling);
}

static inline __attribute__((always_inline)) void	mul_scaling_matrix_to_vector(t_vec4 *fv, const t_vec4 v, const struct s_data xyz)
{
	t_m4	scaling;

	scaling_matrix4(&scaling, xyz);
	mul_matrix4_by_vector(fv, v, scaling);
}

static inline __attribute__((always_inline)) void	shearing_matrix4(t_m4 *m, const struct s_data_shearing d)
{
	m->d[0] = 1.0;
	m->d[1] = d.xy;
	m->d[2] = d.xz;
	m->d[3] = 0.0;
	m->d[4] = d.yx;
	m->d[5] = 1.0;
	m->d[6] = d.yz;
	m->d[7] = 0.0;
	m->d[8] = d.zx;
	m->d[9] = d.zy;
	m->d[10] = 1.0;
	m->d[11] = 0.0;
	m->d[12] = 0.0;
	m->d[13] = 0.0;
	m->d[14] = 0.0;
	m->d[15] = 1.0;
}

#endif //TRANSFORMATIONS_H
