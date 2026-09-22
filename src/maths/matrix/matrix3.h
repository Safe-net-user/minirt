#ifndef MATRIX3_H
# define MATRIX3_H

#include "matrix2.h"

typedef struct s_matrix3
{
	double	d[9];
}	t_m3;

void	submatrix3(t_m2 *mf, t_m3, int i, int j);
double	compute_minor3(t_m3 m, int i, int j);
double	compute_cofactors3(t_m3 m, int i, int j);
double	compute_minor3(t_m3 m, int i, int j);
double	compute_determinant3(t_m3 m);

#endif
