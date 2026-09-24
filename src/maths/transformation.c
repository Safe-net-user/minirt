# include "transformations.h"

void	mul_inv_translation_matrix(t_point *fp, const t_point p, const struct s_data xyz)
{
	t_m4	translation;
	t_m4	inv;

	translation_matrix4(&translation, xyz);
	invert_matrix4(&inv, translation);
	mul_matrix4_by_point(fp, p, inv);
}

void	mul_inv_scaling_matrix(t_vec4 *fv, const t_vec4 v, const struct s_data xyz)
{
	t_m4	scaling;
	t_m4	inv;

	scaling_matrix4(&scaling, xyz);
	invert_matrix4(&inv, scaling);
	mul_matrix4_by_vector(fv, v, inv);
}

void	rotation_x(t_m4 *mf, const double r)
{
	mf->d[0] = 1.0;
	mf->d[1] = 0.0;
	mf->d[2] = 0.0;
	mf->d[3] = 0.0;
	mf->d[4] = 0.0;
	mf->d[5] = cos(r);
	mf->d[6] = -sin(r);
	mf->d[7] = 0.0;
	mf->d[8] = 0.0;
	mf->d[9] = sin(r);
	mf->d[10] = cos(r);
	mf->d[11] = 0.0;
	mf->d[12] = 0.0;
	mf->d[13] = 0.0;
	mf->d[14] = 0.0;
	mf->d[15] = 1.0;
}

void	rotation_y(t_m4 *mf, const double r)
{
	mf->d[0] = cos(r);
	mf->d[1] = 0.0;
	mf->d[2] = sin(r);
	mf->d[3] = 0.0;
	mf->d[4] = 0.0;
	mf->d[5] = 1.0;
	mf->d[6] = 0.0;
	mf->d[7] = 0.0;
	mf->d[8] = -sin(r);
	mf->d[9] = 0.0;
	mf->d[10] = cos(r);
	mf->d[11] = 0.0;
	mf->d[12] = 0.0;
	mf->d[13] = 0.0;
	mf->d[14] = 0.0;
	mf->d[15] = 1.0;
}

void	rotation_z(t_m4 *mf, const double r)
{
	mf->d[0] = cos(r);
	mf->d[1] = -sin(r);
	mf->d[2] = 0.0;
	mf->d[3] = 0.0;
	mf->d[4] = sin(r);
	mf->d[5] = cos(r);
	mf->d[6] = 0.0;
	mf->d[7] = 0.0;
	mf->d[8] = 0.0;
	mf->d[9] = 0.0;
	mf->d[10] = 1.0;
	mf->d[11] = 0.0;
	mf->d[12] = 0.0;
	mf->d[13] = 0.0;
	mf->d[14] = 0.0;
	mf->d[15] = 1.0;
}
