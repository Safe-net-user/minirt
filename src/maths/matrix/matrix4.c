#include "matrix4.h"
#include "matrix3.h"

void	submatrix4(t_m3 *mf, const t_m4 m, const int i, const int j)
{
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
					mf->d[index] = m.d[k * 4 + l];
					index++;
				}
				l++;
			}
		}
		k++;
	}
}

double	compute_minor4(const t_m4 m, const int i, const int j)
{
	t_m3	m3;

	submatrix4(&m3, m, i, j);
	return (compute_determinant3(m3));
}

double	compute_cofactors4(const t_m4 m, const int i, const int j)
{
	double	minor;

	minor = compute_minor4(m, i, j);
	if ((i + j) % 2)
		return (-minor);
	return (minor);
}

double	compute_determinant4(const t_m4 m)
{
	return (m.d[0] * compute_cofactors4(m, 0, 0) + m.d[1] * compute_cofactors4(m, 0, 1) + m.d[2] * compute_cofactors4(m, 0, 2) + m.d[3] * compute_cofactors4(m, 0, 3));
}

void	transpose_matrices4(t_m4 *fm, const t_m4 m)
{
	fm->d[0] = m.d[0];
	fm->d[1] = m.d[4];
	fm->d[2] = m.d[8];
	fm->d[3] = m.d[12];
	fm->d[4] = m.d[1];
	fm->d[5] = m.d[5];
	fm->d[6] = m.d[9];
	fm->d[7] = m.d[13];
	fm->d[8] = m.d[2];
	fm->d[9] = m.d[6];
	fm->d[10] = m.d[10];
	fm->d[11] = m.d[14];
	fm->d[12] = m.d[3];
	fm->d[13] = m.d[7];
	fm->d[14] = m.d[11];
	fm->d[15] = m.d[15];
}

void	mul_matrices4(t_m4 *fm, const t_m4 m1, const t_m4 m2)
{
	fm->d[0] = m1.d[0] * m2.d[0] + m1.d[1] * m2.d[4] + m1.d[2] * m2.d[8] + m1.d[3] * m2.d[12];
	fm->d[1] = m1.d[0] * m2.d[1] + m1.d[1] * m2.d[5] + m1.d[2] * m2.d[9] + m1.d[3] * m2.d[13];
	fm->d[2] = m1.d[0] * m2.d[2] + m1.d[1] * m2.d[6] + m1.d[2] * m2.d[10] + m1.d[3] * m2.d[14];
	fm->d[3] = m1.d[0] * m2.d[3] + m1.d[1] * m2.d[7] + m1.d[2] * m2.d[11] + m1.d[3] * m2.d[15];
	fm->d[4] = m1.d[4] * m2.d[0] + m1.d[5] * m2.d[4] + m1.d[6] * m2.d[8] + m1.d[7] * m2.d[12];
	fm->d[5] = m1.d[4] * m2.d[1] + m1.d[5] * m2.d[5] + m1.d[6] * m2.d[9] + m1.d[7] * m2.d[13];
	fm->d[6] = m1.d[4] * m2.d[2] + m1.d[5] * m2.d[6] + m1.d[6] * m2.d[10] + m1.d[7] * m2.d[14];
	fm->d[7] = m1.d[4] * m2.d[3] + m1.d[5] * m2.d[7] + m1.d[6] * m2.d[11] + m1.d[7] * m2.d[15];
	fm->d[8] = m1.d[8] * m2.d[0] + m1.d[9] * m2.d[4] + m1.d[10] * m2.d[8] + m1.d[11] * m2.d[12];
	fm->d[9] = m1.d[8] * m2.d[1] + m1.d[9] * m2.d[5] + m1.d[10] * m2.d[9] + m1.d[11] * m2.d[13];
	fm->d[10] = m1.d[8] * m2.d[2] + m1.d[9] * m2.d[6] + m1.d[10] * m2.d[10] + m1.d[11] * m2.d[14];
	fm->d[11] = m1.d[8] * m2.d[3] + m1.d[9] * m2.d[7] + m1.d[10] * m2.d[11] + m1.d[11] * m2.d[15];
	fm->d[12] = m1.d[12] * m2.d[0] + m1.d[13] * m2.d[4] + m1.d[14] * m2.d[8] + m1.d[15] * m2.d[12];
	fm->d[13] = m1.d[12] * m2.d[1] + m1.d[13] * m2.d[5] + m1.d[14] * m2.d[9] + m1.d[15] * m2.d[13];
	fm->d[14] = m1.d[12] * m2.d[2] + m1.d[13] * m2.d[6] + m1.d[14] * m2.d[10] + m1.d[15] * m2.d[14];
	fm->d[15] = m1.d[12] * m2.d[3] + m1.d[13] * m2.d[7] + m1.d[14] * m2.d[11] + m1.d[15] * m2.d[15];
}

void	invert_matrix4(t_m4 *fm, const t_m4 m)
{
	double	det;
	int		i;
	int		j;

	if (!compute_determinant4(m))
	{
		fm = NULL;
		return ;
	}
	det = compute_determinant4(m);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			fm->d[i + j] = compute_cofactors4(m, j, i) / det;
			j++;
		}
		i++;
	}
}