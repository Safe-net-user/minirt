#ifndef MATRIX4_H
#define MATRIX4_H

#include "point.h"
#include "matrix3.h"

typedef struct s_matrix4
{
	float	d[16];
}	t_m4;

static inline __attribute__((always_inline)) t_point	mul_matrix4_by_point(const t_point p, const t_m4 m)
{
	return ((t_point){
		m.d[0] * p.x + m.d[1] * p.y + m.d[2] * p.z + m.d[3] * p.w,
		m.d[4] * p.x + m.d[5] * p.y + m.d[6] * p.z + m.d[7] * p.w,
		m.d[8] * p.x + m.d[9] * p.y + m.d[10] * p.z + m.d[11] * p.w,
		1.0f
	});
}

static inline __attribute__((always_inline)) t_vec4	mul_matrix4_by_vector(const t_vec4 v, const t_m4 m)
{
	return ((t_vec4){
		m.d[0] *v.x + m.d[1] * v.y + m.d[2] * v.z + m.d[3] * v.w,
		m.d[4] * v.x + m.d[5] * v.y + m.d[6] * v.z + m.d[7] * v.w,
		m.d[8] * v.x + m.d[9] * v.y + m.d[10] * v.z + m.d[11] * v.w,
		0.0f
		});
}

t_m4	mul_matrices4(t_m4 m1, t_m4 m2);
t_m3	submatrix4(t_m4 m, int i, int j);
t_m4	transpose_matrices4(t_m4 m);
float	compute_minor4(t_m4 m, int i, int j);
float	compute_cofactors4(t_m4 m, int i, int j);
float	compute_determinant4(t_m4 m);
t_m4	invert_matrix4(t_m4 m);

#endif //MATRIX4_H
