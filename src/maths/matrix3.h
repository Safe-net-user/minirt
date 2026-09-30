#ifndef MATRIX3_H
# define MATRIX3_H

#include "matrix2.h"

typedef struct s_matrix3
{
	float	d[9];
}	t_m3;

t_m2	submatrix3(t_m3 m, int i, int j);
float	compute_minor3(t_m3 m, int i, int j);
float	compute_cofactors3(t_m3 m, int i, int j);
float	compute_determinant3(t_m3 m);

#endif
