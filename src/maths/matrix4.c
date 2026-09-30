#include "matrix4.h"
#include "matrix3.h"

t_m3	submatrix4(const t_m4 m, const int i, const int j)
{
	t_m3	m3;
	int	k;
	int	l;
	int	index;

	k = 0;
	index = 0;
	while (k < 4)
	{
		if (k != i)
		{
			l = 0;
			while (l < 4)
			{
				if (l != j)
				{
					m3.d[index] = m.d[k * 4 + l];
					index++;
				}
				l++;
			}
		}
		k++;
	}
	return (m3);
}

float	compute_minor4(const t_m4 m, const int i, const int j)
{
	t_m3	m3;

	m3 = submatrix4(m, i, j);
	return (compute_determinant3(m3));
}

float	compute_cofactors4(const t_m4 m, const int i, const int j)
{
	float	minor;

	minor = compute_minor4(m, i, j);
	if ((i + j) % 2)
		return (-minor);
	return (minor);
}

float	compute_determinant4(const t_m4 m)
{
	return (m.d[0] * compute_cofactors4(m, 0, 0) + m.d[1] * compute_cofactors4(m, 0, 1) + m.d[2] * compute_cofactors4(m, 0, 2) + m.d[3] * compute_cofactors4(m, 0, 3));
}

t_m4	transpose_matrices4(const t_m4 m)
{
	return ((t_m4){
		{
			m.d[0],
			m.d[4],
			m.d[8],
			m.d[12],
			m.d[1],
			m.d[5],
			m.d[9],
			m.d[13],
			m.d[2],
			m.d[6],
			m.d[10],
			m.d[14],
			m.d[3],
			m.d[7],
			m.d[11],
			m.d[15]
		}});
}

t_m4	mul_matrices4(const t_m4 m1, const t_m4 m2)
{
	return ((t_m4)
		{{
	m1.d[0] * m2.d[0] + m1.d[1] * m2.d[4] + m1.d[2] * m2.d[8] + m1.d[3] * m2.d[12],
	m1.d[0] * m2.d[1] + m1.d[1] * m2.d[5] + m1.d[2] * m2.d[9] + m1.d[3] * m2.d[13],
	m1.d[0] * m2.d[2] + m1.d[1] * m2.d[6] + m1.d[2] * m2.d[10] + m1.d[3] * m2.d[14],
	m1.d[0] * m2.d[3] + m1.d[1] * m2.d[7] + m1.d[2] * m2.d[11] + m1.d[3] * m2.d[15],
	m1.d[4] * m2.d[0] + m1.d[5] * m2.d[4] + m1.d[6] * m2.d[8] + m1.d[7] * m2.d[12],
	m1.d[4] * m2.d[1] + m1.d[5] * m2.d[5] + m1.d[6] * m2.d[9] + m1.d[7] * m2.d[13],
	m1.d[4] * m2.d[2] + m1.d[5] * m2.d[6] + m1.d[6] * m2.d[10] + m1.d[7] * m2.d[14],
	m1.d[4] * m2.d[3] + m1.d[5] * m2.d[7] + m1.d[6] * m2.d[11] + m1.d[7] * m2.d[15],
	m1.d[8] * m2.d[0] + m1.d[9] * m2.d[4] + m1.d[10] * m2.d[8] + m1.d[11] * m2.d[12],
	m1.d[8] * m2.d[1] + m1.d[9] * m2.d[5] + m1.d[10] * m2.d[9] + m1.d[11] * m2.d[13],
			m1.d[8] * m2.d[2] + m1.d[9] * m2.d[6] + m1.d[10] * m2.d[10] + m1.d[11] * m2.d[14],
	m1.d[8] * m2.d[3] + m1.d[9] * m2.d[7] + m1.d[10] * m2.d[11] + m1.d[11] * m2.d[15],
	m1.d[12] * m2.d[0] + m1.d[13] * m2.d[4] + m1.d[14] * m2.d[8] + m1.d[15] * m2.d[12],
	m1.d[12] * m2.d[1] + m1.d[13] * m2.d[5] + m1.d[14] * m2.d[9] + m1.d[15] * m2.d[13],
	m1.d[12] * m2.d[2] + m1.d[13] * m2.d[6] + m1.d[14] * m2.d[10] + m1.d[15] * m2.d[14],
			m1.d[12] * m2.d[3] + m1.d[13] * m2.d[7] + m1.d[14] * m2.d[11] + m1.d[15] * m2.d[15]
}});
}

t_m4	invert_matrix4(const t_m4 m)
{
	float	det;
	t_m4	m4;
	int		row;
	int		col;

	if (!compute_determinant4(m))
		return (m);
	det = compute_determinant4(m);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			m4.d[col * 4 + row] = compute_cofactors4(m, row, col) / det;
			col++;
		}
		row++;
	}
	return (m4);
}