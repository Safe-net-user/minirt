#ifndef MATRIX2_H
#define MATRIX2_H

#include <immintrin.h>

typedef struct s_matrix2
{
	double	d[4];
}	t_m2;

static inline __attribute__((always_inline)) void	set_matrix2(t_m2 *m, const __m256d d)
{
	_mm256_storeu_pd(m->d, d);
}

static inline __attribute__((always_inline)) double	compute_determinant_matrix2(const t_m2 m)
{
	return (m.d[0] * m.d[3] - m.d[1] * m.d[2]);
}

#endif //MATRIX2_H
