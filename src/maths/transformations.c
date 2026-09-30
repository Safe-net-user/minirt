# include "transformations.h"

t_point	mul_inv_translation_matrix(const t_point p, const struct s_data xyz)
{
	return (mul_matrix4_by_point(p, invert_matrix4(translation_matrix4(xyz))));
}

t_vec4	mul_inv_scaling_matrix(const t_vec4 v, const struct s_data xyz)
{
	return (mul_matrix4_by_vector(v,invert_matrix4(scaling_matrix4(xyz))));
}

t_m4	rotation_x(const float r)
{
	return ((t_m4){{

	1.0,
	0.0,
	0.0,
	0.0,
	0.0,
	cos(r),
	-sin(r),
	0.0,
	0.0,
	sin(r),
	cos(r),
	0.0,
	0.0,
	0.0,
	0.0,
	1.0}});
}

t_m4	rotation_y(const float r)
{
	return ((t_m4){
		{
			cos(r),
			0.0,
			sin(r),
			0.0,
			0.0,
			1.0,
			0.0,
			0.0,
			-sin(r),
			0.0,
			cos(r),
			0.0,
			0.0,
			0.0,
			0.0,
			1.0
		}});
}

t_m4	rotation_z(const float r)
{
	return ((t_m4){{
	cos(r),
	-sin(r),
	0.0,
	0.0,
	sin(r),
	cos(r),
	0.0,
	0.0,
	0.0,
	0.0,
	1.0,
	0.0,
	0.0,
	0.0,
	0.0,
	1.0}});
}
