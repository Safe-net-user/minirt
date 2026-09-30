#include "matrix3.h"

t_m2	submatrix3(const t_m3 m, const int i, const int j)
{
	t_m2	m2;
	int		k;
	int		l;
	int		index;

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
					m2.d[index] = m.d[k * 3 + l];
					index++;
				}
				l++;
			}
		}
		k++;
	}
	return (m2);
}

float	compute_minor3(const t_m3 m, const int i, const int j)
{
	return (compute_determinant_matrix2(submatrix3(m, i, j)));
}

float	compute_cofactors3(const t_m3 m, const int i, const int j)
{
	float	minor;

	minor = compute_minor3(m, i, j);
	if ((i + j) % 2)
		return (-minor);
	return (minor);
}

float	compute_determinant3(const t_m3 m)
{
	return (m.d[0] * compute_cofactors3(m, 0, 0) + m.d[1] * compute_cofactors3(m, 0, 1) + m.d[2] * compute_cofactors3(m, 0, 2));
}