#include "matrix3.h"

void	submatrix3(t_m2 *mf, const t_m3 m, const int i, const int j)
{
	int	k;
	int	l;
	int	index;

	index = 0;
	k = 0;
	while (k < 3)
	{
		if (k != i)
		{
			l = 0;
			while (l < 3)
			{
				if (l != j)
				{
					mf->d[index] = m.d[k * 3 + l];
					index++;
				}
				l++;
			}
		}
		k++;
	}
}

double	compute_minor3(const t_m3 m, const int i, const int j)
{
	t_m2	m2;

	submatrix3(&m2, m, i, j);
	return (compute_determinant_matrix2(m2));
}

double	compute_cofactors3(const t_m3 m, const int i, const int j)
{
	double	minor;

	minor = compute_minor3(m, i, j);
	if ((i + j) % 2)
		return (-minor);
	return (minor);
}

double	compute_determinant3(const t_m3 m)
{
	return (m.d[0] * compute_cofactors3(m, 0, 0) + m.d[1] * compute_cofactors3(m, 0, 1) + m.d[2] * compute_cofactors3(m, 0, 2));
}