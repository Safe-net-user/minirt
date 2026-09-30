#include <stdio.h>
#include <math.h>
#include "maths.h"
#include "../../../src/maths/transformations.h"

#define EPSILON 1e-6

static int	test_float(const char *name, float got, float expected)
{
	if (fabs(got - expected) > EPSILON)
	{
		printf("  [FAIL] %s: got %.12f, expected %.12f\n",
			name, got, expected);
		return (1);
	}
	printf("  [ OK ] %s\n", name);
	return (0);
}

static int	test_matrix(const char *name, const float *got,
	const float *expected, int n)
{
	int	i;
	int	failed;

	i = 0;
	failed = 0;
	while (i < n)
	{
		if (fabs(got[i] - expected[i]) > EPSILON)
		{
			printf("  [FAIL] %s[%d]: got %.12f, expected %.12f\n",
				name, i, got[i], expected[i]);
			failed = 1;
		}
		i++;
	}
	if (!failed)
		printf("  [ OK ] %s\n", name);
	return (failed);
}

/*
** ============================================================
** 2x2
** ============================================================
*/

static int	test_matrix2_determinants(void)
{
	t_m2	m;
	int		failed;

	printf("\n  -- 2x2 determinants --\n");
	failed = 0;

	/* det = 1*4 - 2*3 = -2 */
	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 4;
	failed += test_float("2x2 negative", 
		compute_determinant_matrix2(m), -2.0);

	/* det = 4*3 - (-2)*5 = 22 */
	m.d[0] = 4;
	m.d[1] = -2;
	m.d[2] = 5;
	m.d[3] = 3;
	failed += test_float("2x2 positive",
		compute_determinant_matrix2(m), 22.0);

	/* det = 1*4 - 2*2 = 0 */
	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 2;
	m.d[3] = 4;
	failed += test_float("2x2 zero",
		compute_determinant_matrix2(m), 0.0);

	/* det = 0*5 - 7*(-3) = 21 */
	m.d[0] = 0;
	m.d[1] = 7;
	m.d[2] = -3;
	m.d[3] = 5;
	failed += test_float("2x2 zero pivot",
		compute_determinant_matrix2(m), 21.0);

	return (failed);
}

/*
** ============================================================
** 3x3 SUBMATRICES
** ============================================================
*/

static int	test_submatrix3(void)
{
	t_m3	m;
	t_m2	got;
	int		failed;

	printf("\n  -- 3x3 submatrices --\n");
	failed = 0;

	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 5;
	m.d[5] = 6;
	m.d[6] = 7;
	m.d[7] = 8;
	m.d[8] = 9;

	/*
	** Remove (0,0):
	**
	** 1 2 3
	** 4 5 6
	** 7 8 9
	**
	** -> 5 6
	**    8 9
	*/
	got = submatrix3(m, 0, 0);
	{
		float expected[] = {5, 6, 8, 9};
		failed += test_matrix("submatrix3 (0,0)",
			got.d, expected, 4);
	}

	/*
	** Remove (0,1):
	**
	** -> 4 6
	**    7 9
	*/
	got = submatrix3(m, 0, 1);
	{
		float expected[] = {4, 6, 7, 9};
		failed += test_matrix("submatrix3 (0,1)",
			got.d, expected, 4);
	}

	/*
	** Remove (0,2):
	**
	** -> 4 5
	**    7 8
	*/
	got = submatrix3(m, 0, 2);
	{
		float expected[] = {4, 5, 7, 8};
		failed += test_matrix("submatrix3 (0,2)",
			got.d, expected, 4);
	}

	/*
	** Remove (1, 0):
	**
	** -> 2 3
	** -> 8 9
	**
	*/
	got = submatrix3(m, 1, 0);
	{
		float expected[] = {2, 3, 8, 9};
		failed += test_matrix("submatrix3 (1,0)",
			got.d, expected, 4);
	}
	/*
	** Remove (1,1):
	**
	** -> 1 3
	**    7 9
	*/
	got = submatrix3(m, 1, 1);
	{
		float expected[] = {1, 3, 7, 9};
		failed += test_matrix("submatrix3 (1,1)",
			got.d, expected, 4);
	}

	/*
	** Remove (2,0):
	**
	** -> 2 3
	**    5 6
	*/
	got = submatrix3(m, 2, 0);
	{
		float expected[] = {2, 3, 5, 6};
		failed += test_matrix("submatrix3 (2,0)",
			got.d, expected, 4);
	}

	return (failed);
}

/*
** ============================================================
** 3x3 MINORS
**
** Matrix:
**
**  1   2   3
**  0   1   4
**  5   6   0
**
** Every minor is tested.
** ============================================================
*/

static int	test_matrix3_minors(void)
{
	t_m3	m;
	int		failed;

	printf("\n  -- 3x3 minors --\n");
	failed = 0;

	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 0;
	m.d[4] = 1;
	m.d[5] = 4;
	m.d[6] = 5;
	m.d[7] = 6;
	m.d[8] = 0;

	failed += test_float("M00", compute_minor3(m, 0, 0), -24);
	failed += test_float("M01", compute_minor3(m, 0, 1), -20);
	failed += test_float("M02", compute_minor3(m, 0, 2), -5);

	failed += test_float("M10", compute_minor3(m, 1, 0), -18);
	failed += test_float("M11", compute_minor3(m, 1, 1), -15);
	failed += test_float("M12", compute_minor3(m, 1, 2), -4);

	failed += test_float("M20", compute_minor3(m, 2, 0), 5);
	failed += test_float("M21", compute_minor3(m, 2, 1), 4);
	failed += test_float("M22", compute_minor3(m, 2, 2), 1);

	return (failed);
}

/*
** Cofactors:
**
** + - +
** - + -
** + - +
*/

static int	test_matrix3_cofactors(void)
{
	t_m3	m;
	int		failed;

	printf("\n  -- 3x3 cofactors --\n");
	failed = 0;

	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 0;
	m.d[4] = 1;
	m.d[5] = 4;
	m.d[6] = 5;
	m.d[7] = 6;
	m.d[8] = 0;

	failed += test_float("C00", compute_cofactors3(m, 0, 0), -24);
	failed += test_float("C01", compute_cofactors3(m, 0, 1), 20);
	failed += test_float("C02", compute_cofactors3(m, 0, 2), -5);

	failed += test_float("C10", compute_cofactors3(m, 1, 0), 18);
	failed += test_float("C11", compute_cofactors3(m, 1, 1), -15);
	failed += test_float("C12", compute_cofactors3(m, 1, 2), 4);

	failed += test_float("C20", compute_cofactors3(m, 2, 0), 5);
	failed += test_float("C21", compute_cofactors3(m, 2, 1), -4);
	failed += test_float("C22", compute_cofactors3(m, 2, 2), 1);

	return (failed);
}

static int	test_matrix3_determinants(void)
{
	t_m3	m;
	int		failed;

	printf("\n  -- 3x3 determinants --\n");
	failed = 0;

	/* determinant = 1 */
	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 0;
	m.d[4] = 1;
	m.d[5] = 4;
	m.d[6] = 5;
	m.d[7] = 6;
	m.d[8] = 0;
	failed += test_float("3x3 = 1",
		compute_determinant3(m), 1.0);

	/* determinant = -9 */
	m.d[0] = 2;
	m.d[1] = -1;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 0;
	m.d[5] = 5;
	m.d[6] = 1;
	m.d[7] = 2;
	m.d[8] = -2;
	failed += test_float("3x3 = -9",
		compute_determinant3(m), -9.0);

	/* determinant = 0 */
	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 2;
	m.d[4] = 4;
	m.d[5] = 6;
	m.d[6] = 3;
	m.d[7] = 6;
	m.d[8] = 9;
	failed += test_float("3x3 = 0",
		compute_determinant3(m), 0.0);

	/* determinant = -75 */
	m.d[0] = 3;
	m.d[1] = 5;
	m.d[2] = -2;
	m.d[3] = 1;
	m.d[4] = -4;
	m.d[5] = 6;
	m.d[6] = 2;
	m.d[7] = 0;
	m.d[8] = 7;
	failed += test_float("3x3 = -75",
		compute_determinant3(m), -75.0);

	return (failed);
}

/*
** ============================================================
** 4x4 SUBMATRICES
**
** Matrix:
**
**  1   2   3   4
**  5   6   7   8
**  9  10  11  12
** 13  14  15  16
**
** ============================================================
*/

static int	test_submatrix4(void)
{
	t_m4	m;
	t_m3	got;
	int		failed;

	printf("\n  -- 4x4 submatrices --\n");
	failed = 0;

	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 5;
	m.d[5] = 6;
	m.d[6] = 7;
	m.d[7] = 8;
	m.d[8] = 9;
	m.d[9] = 10;
	m.d[10] = 11;
	m.d[11] = 12;
	m.d[12] = 13;
	m.d[13] = 14;
	m.d[14] = 15;
	m.d[15] = 16;

	got = submatrix4(m, 0, 0);
	{
		float expected[] = {
			6, 7, 8,
			10, 11, 12,
			14, 15, 16
		};
		failed += test_matrix("submatrix4 (0,0)",
			got.d, expected, 9);
	}

	got = submatrix4(m, 0, 3);
	{
		float expected[] = {
			5, 6, 7,
			9, 10, 11,
			13, 14, 15
		};
		failed += test_matrix("submatrix4 (0,3)",
			got.d, expected, 9);
	}

	got = submatrix4(m, 1, 1);
	{
		float expected[] = {
			1, 3, 4,
			9, 11, 12,
			13, 15, 16
		};
		failed += test_matrix("submatrix4 (1,1)",
			got.d, expected, 9);
	}
	got = submatrix4(m, 2, 2);
	{
		float expected[] = {
			1, 2, 4,
			5, 6, 8,
			13, 14, 16
		};
		failed += test_matrix("submatrix4 (2,2)",
			got.d, expected, 9);
	}
	got = submatrix4(m, 3, 0);
	{
		float expected[] = {
			2, 3, 4,
			6, 7, 8,
			10, 11, 12
		};
		failed += test_matrix("submatrix4 (3,0)",
			got.d, expected, 9);
	}
	return (failed);
}

/*
** ============================================================
** 4x4 MINORS
**
** Matrix:
**
**  1   2   3   4
**  5   6   7   8
**  2   6   4   8
**  3   1   1   2
**
** Every single minor is tested.
** ============================================================
*/

static int	test_matrix4_minors(void)
{
	t_m4	m;
	int		failed;

	printf("\n  -- 4x4 minors --\n");
	failed = 0;

	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 5;
	m.d[5] = 6;
	m.d[6] = 7;
	m.d[7] = 8;
	m.d[8] = 2;
	m.d[9] = 6;
	m.d[10] = 4;
	m.d[11] = 8;
	m.d[12] = 3;
	m.d[13] = 1;
	m.d[14] = 1;
	m.d[15] = 2;

	failed += test_float("M00", compute_minor4(m, 0, 0), -12);
	failed += test_float("M01", compute_minor4(m, 0, 1), 60);
	failed += test_float("M02", compute_minor4(m, 0, 2), 12);
	failed += test_float("M03", compute_minor4(m, 0, 3), -42);

	failed += test_float("M10", compute_minor4(m, 1, 0), -4);
	failed += test_float("M11", compute_minor4(m, 1, 1), 20);
	failed += test_float("M12", compute_minor4(m, 1, 2), -20);
	failed += test_float("M13", compute_minor4(m, 1, 3), -26);

	failed += test_float("M20", compute_minor4(m, 2, 0), -4);
	failed += test_float("M21", compute_minor4(m, 2, 1), -16);
	failed += test_float("M22", compute_minor4(m, 2, 2), -20);
	failed += test_float("M23", compute_minor4(m, 2, 3), -8);

	failed += test_float("M30", compute_minor4(m, 3, 0), -24);
	failed += test_float("M31", compute_minor4(m, 3, 1), -24);
	failed += test_float("M32", compute_minor4(m, 3, 2), 24);
	failed += test_float("M33", compute_minor4(m, 3, 3), 24);

	return (failed);
}

static int	test_matrix4_cofactors(void)
{
	t_m4	m;
	int		failed;

	printf("\n  -- 4x4 cofactors --\n");
	failed = 0;

	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 5;
	m.d[5] = 6;
	m.d[6] = 7;
	m.d[7] = 8;
	m.d[8] = 2;
	m.d[9] = 6;
	m.d[10] = 4;
	m.d[11] = 8;
	m.d[12] = 3;
	m.d[13] = 1;
	m.d[14] = 1;
	m.d[15] = 2;

	failed += test_float("C00", compute_cofactors4(m, 0, 0), -12);
	failed += test_float("C01", compute_cofactors4(m, 0, 1), -60);
	failed += test_float("C02", compute_cofactors4(m, 0, 2), 12);
	failed += test_float("C03", compute_cofactors4(m, 0, 3), 42);

	failed += test_float("C10", compute_cofactors4(m, 1, 0), 4);
	failed += test_float("C11", compute_cofactors4(m, 1, 1), 20);
	failed += test_float("C12", compute_cofactors4(m, 1, 2), 20);
	failed += test_float("C13", compute_cofactors4(m, 1, 3), -26);

	failed += test_float("C20", compute_cofactors4(m, 2, 0), -4);
	failed += test_float("C21", compute_cofactors4(m, 2, 1), 16);
	failed += test_float("C22", compute_cofactors4(m, 2, 2), -20);
	failed += test_float("C23", compute_cofactors4(m, 2, 3), 8);

	failed += test_float("C30", compute_cofactors4(m, 3, 0), 24);
	failed += test_float("C31", compute_cofactors4(m, 3, 1), -24);
	failed += test_float("C32", compute_cofactors4(m, 3, 2), -24);
	failed += test_float("C33", compute_cofactors4(m, 3, 3), 24);

	return (failed);
}

static int	test_matrix4_determinants(void)
{
	t_m4	m;
	int		failed;

	printf("\n  -- 4x4 determinants --\n");
	failed = 0;

	/* determinant = 72 */
	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 5;
	m.d[5] = 6;
	m.d[6] = 7;
	m.d[7] = 8;
	m.d[8] = 2;
	m.d[9] = 6;
	m.d[10] = 4;
	m.d[11] = 8;
	m.d[12] = 3;
	m.d[13] = 1;
	m.d[14] = 1;
	m.d[15] = 2;

	failed += test_float("4x4 = 72",
		compute_determinant4(m), 72.0);

	/* determinant = -63 */
	m.d[0] = 2;
	m.d[1] = -1;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 0;
	m.d[5] = 5;
	m.d[6] = 2;
	m.d[7] = -2;
	m.d[8] = 1;
	m.d[9] = 0;
	m.d[10] = 4;
	m.d[11] = 3;
	m.d[12] = 6;
	m.d[13] = 2;
	m.d[14] = -1;
	m.d[15] = 1;

	failed += test_float("4x4 = -63",
		compute_determinant4(m), -63.0);

	/* determinant = -105 */
	m.d[0] = 1;
	m.d[1] = 0;
	m.d[2] = 2;
	m.d[3] = -1;
	m.d[4] = 3;
	m.d[5] = 4;
	m.d[6] = 0;
	m.d[7] = 2;
	m.d[8] = 2;
	m.d[9] = -2;
	m.d[10] = 1;
	m.d[11] = 5;
	m.d[12] = 1;
	m.d[13] = 3;
	m.d[14] = 2;
	m.d[15] = 0;

	failed += test_float("4x4 = -105",
		compute_determinant4(m), -105.0);

	/* determinant = 0 */
	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 2;
	m.d[5] = 4;
	m.d[6] = 6;
	m.d[7] = 8;
	m.d[8] = 5;
	m.d[9] = 1;
	m.d[10] = 0;
	m.d[11] = 3;
	m.d[12] = 7;
	m.d[13] = 2;
	m.d[14] = 1;
	m.d[15] = 9;

	failed += test_float("4x4 = 0",
		compute_determinant4(m), 0.0);

	return (failed);
}

/*
** ============================================================
** INVERSE
** ============================================================
*/

static int	test_inverse4()
{
	t_m4	m;
	t_m4	got;
	int		failed;

	failed = 0;
	printf("\n  -- 4x4 inverse --\n");
	m.d[0] = -5.0;
	m.d[1] = 2.0;
	m.d[2] = 6.0;
	m.d[3] = -8.0;
	m.d[4] = 1.0;
	m.d[5] = -5.0;
	m.d[6] = 1.0;
	m.d[7] = 8.0;
	m.d[8] = 7.0;
	m.d[9] = 7.0;
	m.d[10] = -6.0;
	m.d[11] = -7.0;
	m.d[12] = 1.0;
	m.d[13] = -3.0;
	m.d[14] = 7.0;
	m.d[15] = 4.0;

	got = invert_matrix4(m);
	float expected[] = {
		0.218045112782, 0.451127819549, 0.240601503759, -0.045112781955,
		-0.808270676692, -1.456766917293, -0.443609022556, 0.520676691729,
		-0.078947368421, -0.223684210526, -0.052631578947, 0.197368421053,
		-0.522556390977, -0.813909774436, -0.300751879699, 0.306390977444,
	};
	failed += test_matrix("invert matrix 4x4", got.d, expected, 16);
	return (failed);
}

/*
** ============================================================
** TRANSPOSE
** ============================================================
*/

static int	test_transpose4(void)
{
	t_m4	m;
	t_m4	got;
	int		failed;

	printf("\n  -- 4x4 transpose --\n");
	failed = 0;

	m.d[0] = 1;
	m.d[1] = 2;
	m.d[2] = 3;
	m.d[3] = 4;
	m.d[4] = 5;
	m.d[5] = 6;
	m.d[6] = 7;
	m.d[7] = 8;
	m.d[8] = 9;
	m.d[9] = 10;
	m.d[10] = 11;
	m.d[11] = 12;
	m.d[12] = 13;
	m.d[13] = 14;
	m.d[14] = 15;
	m.d[15] = 16;

	got = transpose_matrices4(m);
		float expected[] = {
			1, 5, 9, 13,
			2, 6, 10, 14,
			3, 7, 11, 15,
			4, 8, 12, 16
		};

		failed += test_matrix("transpose4",
			got.d, expected, 16);

	return (failed);
}

/*
** ============================================================
** MATRIX MULTIPLICATION
** ============================================================
*/

static int	test_matrix4_multiplication(void)
{
	t_m4	a;
	t_m4	b;
	t_m4	got;
	int		failed;

	printf("\n  -- 4x4 multiplication --\n");
	failed = 0;

	a.d[0] = 1;
	a.d[1] = 2;
	a.d[2] = 3;
	a.d[3] = 4;
	a.d[4] = 5;
	a.d[5] = 6;
	a.d[6] = 7;
	a.d[7] = 8;
	a.d[8] = 9;
	a.d[9] = 10;
	a.d[10] = 11;
	a.d[11] = 12;
	a.d[12] = 13;
	a.d[13] = 14;
	a.d[14] = 15;
	a.d[15] = 16;

	b.d[0] = 16;
	b.d[1] = 15;
	b.d[2] = 14;
	b.d[3] = 13;
	b.d[4] = 12;
	b.d[5] = 11;
	b.d[6] = 10;
	b.d[7] = 9;
	b.d[8] = 8;
	b.d[9] = 7;
	b.d[10] = 6;
	b.d[11] = 5;
	b.d[12] = 4;
	b.d[13] = 3;
	b.d[14] = 2;
	b.d[15] = 1;

	got = mul_matrices4(a, b);

	{
		float expected[] = {
			80, 70, 60, 50,
			240, 214, 188, 162,
			400, 358, 316, 274,
			560, 502, 444, 386
		};

		failed += test_matrix("4x4 multiplication",
			got.d, expected, 16);
	}

	return (failed);
}

/*
** ============================================================
** IDENTITY MULTIPLICATION
** ============================================================
*/

static int	test_identity_multiplication(void)
{
	t_m4	m;
	t_m4	id;
	t_m4	got;
	int		failed;

	printf("\n  -- identity multiplication --\n");
	failed = 0;

	m.d[0] = 2;
	m.d[1] = -3;
	m.d[2] = 5;
	m.d[3] = 7;
	m.d[4] = 11;
	m.d[5] = 13;
	m.d[6] = -17;
	m.d[7] = 19;
	m.d[8] = 23;
	m.d[9] = -29;
	m.d[10] = 31;
	m.d[11] = 37;
	m.d[12] = 41;
	m.d[13] = 43;
	m.d[14] = -47;
	m.d[15] = 53;

	id.d[0] = 1;
	id.d[1] = 0;
	id.d[2] = 0;
	id.d[3] = 0;
	id.d[4] = 0;
	id.d[5] = 1;
	id.d[6] = 0;
	id.d[7] = 0;
	id.d[8] = 0;
	id.d[9] = 0;
	id.d[10] = 1;
	id.d[11] = 0;
	id.d[12] = 0;
	id.d[13] = 0;
	id.d[14] = 0;
	id.d[15] = 1;

	got = mul_matrices4(m, id);

	failed += test_matrix("M * I", got.d, m.d, 16);

	got = mul_matrices4(id, m);

	failed += test_matrix("I * M", got.d, m.d, 16);

	return (failed);
}

/*
** ============================================================
** RUN ALL MATRIX TESTS
** ============================================================
*/

int	run_matrix_tests(void)
{
	int	failed;

	failed = 0;

	printf("[MATRIX TESTS]\n");

	failed += test_matrix2_determinants();

	failed += test_submatrix3();
	failed += test_matrix3_minors();
	failed += test_matrix3_cofactors();
	failed += test_matrix3_determinants();

	failed += test_submatrix4();
	failed += test_matrix4_minors();
	failed += test_matrix4_cofactors();
	failed += test_matrix4_determinants();

	failed += test_transpose4();
	failed += test_inverse4();
	failed += test_matrix4_multiplication();
	failed += test_identity_multiplication();

	if (failed == 0)
		printf("\n  >>> ALL MATRIX TESTS PASSED <<<\n");
	else
		printf("\n  >>> %d MATRIX TEST(S) FAILED <<<\n", failed);

	return (failed);
}

int	test_vector_addition(void)
{
	t_vec4	v1;
	t_vec4	v2;
	t_vec4	got;
	int		failed;

	failed = 0;
	printf("\n  -- vector addition --\n");

	v1 = set_vec4(1.0, 2.0, 3.0);
	v2 = set_vec4(4.0, 5.0, 6.0);
	got = add_vectors(v1, v2);

	failed += test_float("x", got.x, 5.0);
	failed += test_float("y", got.y, 7.0);
	failed += test_float("z", got.z, 9.0);
	failed += test_float("w", got.w, 0.0);

	return (failed);
}

int	test_vector_substraction(void)
{
	t_vec4	v1;
	t_vec4	v2;
	t_vec4	got;
	int		failed;

	failed = 0;
	printf("\n  -- vector subtraction --\n");

	v1 = set_vec4(5.0, 7.0, 9.0);
	v2 = set_vec4(1.0, 2.0, 3.0);
	got = sub_vectors(v1, v2);

	failed += test_float("x", got.x, 4.0);
	failed += test_float("y", got.y, 5.0);
	failed += test_float("z", got.z, 6.0);
	failed += test_float("w", got.w, 0.0);

	return (failed);
}

int	test_vector_negation(void)
{
	t_vec4	v;
	int		failed;

	failed = 0;
	printf("\n  -- vector negation --\n");

	v = set_vec4(1.0, -2.0, 3.0);
	v = negate_vector(v);

	failed += test_float("x", v.x, -1.0);
	failed += test_float("y", v.y, 2.0);
	failed += test_float("z", v.z, -3.0);
	failed += test_float("w", v.w, 0.0);

	return (failed);
}

int	test_vector_multiplication(void)
{
	t_vec4	v;
	int		failed;

	failed = 0;
	printf("\n  -- vector multiplication --\n");

	v = set_vec4(1.0, -2.0, 3.0);
	v = mul_vector(v, 2.5);

	failed += test_float("x", v.x, 2.5);
	failed += test_float("y", v.y, -5.0);
	failed += test_float("z", v.z, 7.5);
	failed += test_float("w", v.w, 0.0);

	return (failed);
}

int	test_vector_division(void)
{
	t_vec4	v;
	int		failed;

	failed = 0;
	printf("\n  -- vector division --\n");

	v = set_vec4(2.0, -4.0, 8.0);
	v = mul_vector(v, 0.5);

	failed += test_float("x", v.x, 1.0);
	failed += test_float("y", v.y, -2.0);
	failed += test_float("z", v.z, 4.0);
	failed += test_float("w", v.w, 0.0);

	return (failed);
}

int	test_vector_magnitude(void)
{
	t_vec4	v;
	float	magnitude;
	int		failed;

	failed = 0;
	printf("\n  -- vector magnitude --\n");

	v = set_vec4(3.0, 4.0, 0.0);
	magnitude = compute_magnitude(v);

	failed += test_float("magnitude", magnitude, 5.0);

	return (failed);
}

int	test_vector_normalization(void)
{
	t_vec4	v;
	int		failed;

	failed = 0;
	printf("\n  -- vector normalization --\n");

	v = set_vec4(3.0, 4.0, 0.0);
	v = normalize_vector(v, compute_magnitude(v));

	failed += test_float("x", v.x, 0.6);
	failed += test_float("y", v.y, 0.8);
	failed += test_float("z", v.z, 0.0);
	failed += test_float("magnitude", compute_magnitude(v), 1.0);

	return (failed);
}

int	test_vector_cross_product(void)
{
	t_vec4	v1;
	t_vec4	v2;
	t_vec4	got;
	int		failed;

	failed = 0;
	printf("\n  -- vector cross product --\n");

	v1 = set_vec4(1.0, 2.0, 3.0);
	v2 = set_vec4(2.0, 3.0, 4.0);

	got = compute_cross(v1, v2);

	failed += test_float("x", got.x, -1.0);
	failed += test_float("y", got.y, 2.0);
	failed += test_float("z", got.z, -1.0);
	failed += test_float("w", got.w, 0.0);

	return (failed);
}

int	test_vector_dot_product(void)
{
	t_vec4	v1;
	t_vec4	v2;
	float	got;
	int		failed;

	failed = 0;
	printf("\n  -- vector dot product --\n");

	v1 = set_vec4(1.0, 2.0, 3.0);
	v2 = set_vec4(2.0, 3.0, 4.0);

	got = compute_dot(v1, v2);

	failed += test_float("dot", got, 20.0);

	return (failed);
}

int	run_vector_tests(void)
{
	int failed;

	failed = 0;
	printf("[VECTOR TESTS]\n");

	failed += test_vector_addition();
	failed += test_vector_substraction();
	failed += test_vector_negation();
	failed += test_vector_multiplication();
	failed += test_vector_division();
	failed += test_vector_magnitude();
	failed += test_vector_normalization();
	failed += test_vector_dot_product();
	failed += test_vector_cross_product();

	if (failed == 0)
		printf("\n  >>> ALL VECTOR TESTS PASSED <<<\n");
	else
		printf("\n  >>> %d VECTOR TEST(S) FAILED <<<\n", failed);

	return (failed);
}

int	test_point_substraction(void)
{
	t_vec4 got;
	t_point	p1;
	t_point	p2;
	int		failed;

	failed = 0;
	printf("\n  -- point substraction --\n");
	p1 = set_point(2.0, 4.0, -3.0);
	p2 = set_point(6.0, 4.0, -2.0);
	got = sub_points(p1, p2);

	failed += test_float("x", got.x, -4.0);
	failed += test_float("y", got.y, 0.0);
	failed += test_float("z", got.z, -1.0);
	failed += test_float("w", got.w, 0.0);

	return (failed);
}

int	test_vector_substraction_from_point(void)
{
	t_point got;
	t_point	p;
	t_vec4	v;
	int		failed;

	failed = 0;
	printf("\n  -- point vector substraction from point --\n");
	p = set_point(2.0, 4.0, -3.0);
	v = set_vec4(6.0, 4.0, -2.0);
	got = sub_vector_from_point(v, p);

	failed += test_float("x", got.x, -4.0);
	failed += test_float("y", got.y, 0.0);
	failed += test_float("z", got.z, -1.0);
	failed += test_float("w", got.w, 1.0);

	return (failed);
}

int	run_point_tests(void)
{
	int failed;

	failed = 0;
	printf("[POINT TESTS]\n");

	failed += test_point_substraction();
	failed += test_vector_substraction_from_point();

	if (failed == 0)
		printf("\n  >>> ALL POINT TESTS PASSED <<<\n");
	else
		printf("\n  >>> %d POINT TEST(S) FAILED <<<\n", failed);

	return (failed);
}

int	test_transformation_translation(void)
{
	int	failed;
	t_m4	m;
	t_point	p;
	t_point	got;

	t_m4 translated_matrix4 = (t_m4){
		.d = {
			1.0, 0.0, 0.0, 2.0,
			0.0, 1.0, 0.0, 3.0,
			0.0, 0.0, 1.0, 4.0,
			0.0, 0.0, 0.0, 1.0
		}
	};
	failed = 0;
	printf("\n  -- translation transformation tests --\n");
	m = translation_matrix4((struct s_data){.x = 2.0, .y = 3.0, .z = 4.0});
	test_matrix("translation matrix 4x4", m.d, translated_matrix4.d, 16);
	p = set_point(-3, 4, 5);
	got = mul_translation_matrix(p, (struct s_data){.x = 5, .y = -3, .z = 2});
	printf("\n  -- translation transformation tests --\n");
	printf("multiplying by a translation matrix: \n");
	failed += test_float("x", got.x, 2.0);
	failed += test_float("y", got.y, 1.0);
	failed += test_float("z", got.z, 7.0);
	printf("multiplying by the inverse of a translation matrix: \n");
	got = mul_inv_translation_matrix(p, (struct s_data){.x = 5, .y = -3, .z = 2});
	failed += test_float("x", got.x, -8.0);
	failed += test_float("y", got.y, 7.0);
	failed += test_float("z", got.z, 3.0);
	return (failed);
}

int	test_transformation_scaling(void)
{
	t_m4	m;
	t_m4	scaled_matrix4;
	t_m4	inv;
	t_point	got_point;
	t_point	p;
	t_vec4	got_vector;
	t_vec4	v;
	int		failed;

	failed = 0;
	printf("\n  -- scaling transformation tests --\n");
	m = scaling_matrix4((struct s_data){.x = 2, .y = 3, .z = 4});
	scaled_matrix4 = (t_m4){
		.d = {
			2.0, 0.0, 0.0, 0.0,
			0.0, 3.0, 0.0, 0.0,
			0.0, 0.0, 4.0, 0.0,
			0.0, 0.0, 0.0, 1.0
		}
	};
	failed = test_matrix("scale matrix 4x4", m.d, scaled_matrix4.d, 16);

	printf("A scaling matrix applied to a point\n");
	p = set_point(-4, 6, 8);
	got_point =  mul_matrix4_by_point(p, m);
	failed += test_float("x", got_point.x, -8.0);
	failed += test_float("y", got_point.y, 18.0);
	failed += test_float("z", got_point.z, 32.0);

	printf("A scaling matrix applied to a vector\n");
	v = set_vec4(-4, 6, 8);
	got_vector = mul_matrix4_by_vector(v, m);
	failed += test_float("x", got_vector.x, -8.0);
	failed += test_float("y", got_vector.y, 18.0);
	failed += test_float("z", got_vector.z, 32.0);

	printf("Multiplying by the inverse of a scaling matrix\n");
	inv = invert_matrix4(m);
	got_vector =  mul_matrix4_by_vector(v, inv);
	failed += test_float("x", got_vector.x, -2.0);
	failed += test_float("y", got_vector.y, 2.0);
	failed += test_float("z", got_vector.z, 2.0);
	return (failed);
}

int	test_transformation_rotate_x(void)
{
	t_point	p;
	t_point	got_half_quarter;
	t_point	got_full_quarter;
	t_point	got_half_quarter_inv;
	t_m4	half_quarter;
	t_m4	full_quarter;
	t_m4	inv;

	int	failed;

	failed = 0;
	printf("\n  -- rotation x transformation tests --\n");
	p = set_point(0.0, 1.0, 0.0);
	half_quarter = rotation_x(M_PI / 4);
	full_quarter=rotation_x(M_PI / 2);
	got_half_quarter = mul_matrix4_by_point(p, half_quarter);
	got_full_quarter = mul_matrix4_by_point(p, full_quarter);
	inv = invert_matrix4(half_quarter);
	got_half_quarter_inv = mul_matrix4_by_point(p, inv);

	printf("\nrotating a point around the x axis with a half quarter\n");
	failed += test_float("x", got_half_quarter.x, 0.0);
	failed += test_float("y", got_half_quarter.y, sqrt(2) / 2);
	failed += test_float("z", got_half_quarter.z, sqrt(2) / 2);

	printf("\nrotating a point around the x axis with a full quarter\n");
	failed += test_float("x", got_full_quarter.x, 0.0);
	failed += test_float("y", got_full_quarter.y, 0.0);
	failed += test_float("z", got_full_quarter.z, 1.0);

	printf("\nThe inverse of an x-rotation rotates in the opposite direction with half quarter\n");
	failed += test_float("x", got_half_quarter_inv.x, 0.0);
	failed += test_float("y", got_half_quarter_inv.y, sqrt(2)/2);
	failed += test_float("z", got_half_quarter_inv.z, -(sqrt(2)/2));

	return (failed);
}

int	test_transformation_rotate_y(void)
{
	t_point	p;
	t_point	got_half_quarter;
	t_point	got_full_quarter;
	t_m4	half_quarter;
	t_m4	full_quarter;

	int	failed;

	failed = 0;
	printf("\n  -- rotation y transformation tests --\n");
	p = set_point(0.0, 0.0, 1.0);
	half_quarter = rotation_y(M_PI / 4);
	full_quarter = rotation_y(M_PI / 2);
	got_half_quarter = mul_matrix4_by_point(p, half_quarter);
	got_full_quarter = mul_matrix4_by_point(p, full_quarter);

	printf("\nrotating a point around the y axis with a half quarter\n");
	failed += test_float("x", got_half_quarter.x, fsqrt(2) / 2);
	failed += test_float("y", got_half_quarter.y, 0.0);
	failed += test_float("z", got_half_quarter.z, fsqrt(2) / 2);

	printf("\nrotating a point around the y axis with a full quarter\n");
	failed += test_float("x", got_full_quarter.x, 1.0);
	failed += test_float("y", got_full_quarter.y, 0.0);
	failed += test_float("z", got_full_quarter.z, 0.0);

	return (failed);
}

int	test_transformation_rotate_z(void)
{
	t_point	p;
	t_point	got_half_quarter;
	t_point	got_full_quarter;
	t_m4	half_quarter;
	t_m4	full_quarter;

	int	failed;

	failed = 0;
	printf("\n  -- rotation z transformation tests --\n");
	p = set_point(0.0, 1.0, 0.0);
	half_quarter = rotation_z(M_PI / 4);
	full_quarter = rotation_z(M_PI / 2);
	got_half_quarter = mul_matrix4_by_point(p, half_quarter);
	got_full_quarter = mul_matrix4_by_point(p, full_quarter);

	printf("\nrotating a point around the z axis with a half quarter\n");
	failed += test_float("x", got_half_quarter.x, -(sqrt(2) / 2));
	failed += test_float("y", got_half_quarter.y, sqrt(2) / 2);
	failed += test_float("z", got_half_quarter.z, 0.0);

	printf("\nrotating a point around the z axis with a full quarter\n");
	failed += test_float("x", got_full_quarter.x, -1.0);
	failed += test_float("y", got_full_quarter.y, 0.0);
	failed += test_float("z", got_full_quarter.z, 0.0);

	return (failed);
}

int	test_transformation_shearing(void)
{
	t_point	got;
	t_point	p;
	t_m4	m;
	int	failed;

	failed = 0;
	printf("\n  -- shearing transformation tests --\n");
	m = shearing_matrix4((struct s_data_shearing){.xy = 10.0, .xz = 11.0, .yx = 12.0, .yz = 13.0, .zx = 14.0, .zy = 15.0});
	t_m4 expected = (t_m4){
		.d = {
			1.0, 10.0, 11.0, 0.0,
			12.0, 1.0, 13.0, 0.0,
			14.0, 15.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0
		}
	};
	failed += test_matrix("shearing matrix 4x4", m.d, expected.d, 16);

	p = set_point(2.0, 3.0, 4.0);

	printf("\nA shearing transformation moves x in proportion to y\n");
	m = shearing_matrix4((struct s_data_shearing){.xy = 1.0, .xz = 0.0, .yx = 0.0, .yz = 0.0, .zx = 0.0, .zy = 0.0});
	got = mul_matrix4_by_point(p, m);
	failed += test_float("x", got.x, 5.0);
	failed += test_float("y", got.y, 3.0);
	failed += test_float("z", got.z, 4.0);

	printf("\nA shearing transformation moves x in proportion to z\n");
	m = shearing_matrix4((struct s_data_shearing){.xy = 0.0, .xz = 1.0, .yx = 0.0, .yz = 0.0, .zx = 0.0, .zy = 0.0});
	got = mul_matrix4_by_point(p, m);
	failed += test_float("x", got.x, 6.0);
	failed += test_float("y", got.y, 3.0);
	failed += test_float("z", got.z, 4.0);

	printf("\nA shearing transformation moves y in proportion to x\n");
	m = shearing_matrix4((struct s_data_shearing){.xy = 0.0, .xz = 0.0, .yx = 1.0, .yz = 0.0, .zx = 0.0, .zy = 0.0});
	got = mul_matrix4_by_point(p, m);
	failed += test_float("x", got.x, 2.0);
	failed += test_float("y", got.y, 5.0);
	failed += test_float("z", got.z, 4.0);

	printf("\nA shearing transformation moves y in proportion to z\n");
	m = shearing_matrix4((struct s_data_shearing){.xy = 0.0, .xz = 0.0, .yx = 0.0, .yz = 1.0, .zx = 0.0, .zy = 0.0});
	got = mul_matrix4_by_point(p, m);
	failed += test_float("x", got.x, 2.0);
	failed += test_float("y", got.y, 7.0);
	failed += test_float("z", got.z, 4.0);

	printf("\nA shearing transformation moves z in proportion to x\n");
	m = shearing_matrix4((struct s_data_shearing){.xy = 0.0, .xz = 0.0, .yx = 0.0, .yz = 0.0, .zx = 1.0, .zy = 0.0});
	got = mul_matrix4_by_point(p, m);
	failed += test_float("x", got.x, 2.0);
	failed += test_float("y", got.y, 3.0);
	failed += test_float("z", got.z, 6.0);

	printf("\nA shearing transformation moves z in proportion to y\n");
	m = shearing_matrix4((struct s_data_shearing){.xy = 0.0, .xz = 0.0, .yx = 0.0, .yz = 0.0, .zx = 0.0, .zy = 1.0});
	got = mul_matrix4_by_point(p, m);
	failed += test_float("x", got.x, 2.0);
	failed += test_float("y", got.y, 3.0);
	failed += test_float("z", got.z, 7.0);

	return (failed);
}

int	run_transformation_tests(void)
{
	int	failed;

	failed = 0;
	printf("[TRANSFORMATION TESTS]\n");

	failed += test_transformation_translation();
	failed += test_transformation_scaling();
	failed += test_transformation_rotate_x();
	failed += test_transformation_rotate_y();
	failed += test_transformation_rotate_z();
	failed += test_transformation_shearing();

	if (failed == 0)
		printf("\n  >>> ALL TRANSFORMATION TESTS PASSED <<<\n");
	else
		printf("\n  >>> %d TRANSFORMATION TEST(S) FAILED <<<\n", failed);

	return (failed);
}

int	main(void)
{
	int	vector_failed;
	int	point_failed;
	int	matrix_failed;
	int	transformations_failed;

	printf("\n");
	printf("========================================\n");
	printf("             miniRT MATH                \n");
	printf("========================================\n\n");

	vector_failed = run_vector_tests();
	point_failed = run_point_tests();
	matrix_failed = run_matrix_tests();
	transformations_failed = run_transformation_tests();

	printf("\n========================================\n");

	if (vector_failed == 0 && point_failed == 0 && matrix_failed == 0 && transformations_failed == 0)
		printf("             ALL TESTS PASSED           \n");
	else
		printf("             TESTS FAILED              \n");

	printf("========================================\n\n");

	return (vector_failed != 0
		|| point_failed != 0
		|| matrix_failed != 0
		|| transformations_failed != 0);
}