#ifndef MATRIX4_H
#define MATRIX4_H

#include "../point.h"
#include "matrix3.h"
#include <immintrin.h>

typedef struct s_matrix4
{
	double	d[16];
}	t_m4;

static inline __attribute__((always_inline)) void	set_matrix4(t_m4 *m, const __m512d a, const __m512d b)
{
	_mm512_storeu_pd(m->d, a);
	_mm512_storeu_pd(&m->d[8], b);
}

static inline __attribute__((always_inline)) void	mul_matrix4_by_point(t_point *fp, const t_point p, const t_m4 m)
{
	set_point(
		fp,
		m.d[0] * p.x + m.d[1] * p.y + m.d[2] * p.z + m.d[3] * p.w,
		m.d[4] * p.x + m.d[5] * p.y + m.d[6] * p.z + m.d[7] * p.w,
		m.d[8] * p.x + m.d[9] * p.y + m.d[10] * p.z + m.d[11] * p.w
		);
}

static inline __attribute__((always_inline)) void	mul_matrix4_by_vector(t_vec4 *fv, const t_vec4 v, const t_m4 m)
{
	set_vec4(
		fv,
		m.d[0] *v.x + m.d[1] * v.y + m.d[2] * v.z + m.d[3] * v.w,
		m.d[4] * v.x + m.d[5] * v.y + m.d[6] * v.z + m.d[7] * v.w,
		m.d[8] * v.x + m.d[9] * v.y + m.d[10] * v.z + m.d[11] * v.w
		);
}

void	mul_matrices4(t_m4 *fm, const t_m4 m1, const t_m4 m2);
void	submatrix4(t_m3 *mf, t_m4 m, int i, int j);
void	transpose_matrices4(t_m4 *fm, t_m4 m);
double	compute_minor4(t_m4 m, int i, int j);
double	compute_cofactors4(t_m4 m, int i, int j);
double	compute_determinant4(t_m4 m);
void	invert_matrix4(t_m4 *fm, const t_m4 m);

#endif //MATRIX4_H
