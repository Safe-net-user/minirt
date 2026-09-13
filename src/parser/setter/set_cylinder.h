#ifndef MINIRT_SET_CYLINDER_H
#define MINIRT_SET_CYLINDER_H

static inline void	set_cylinder_coords(t_ct *ct, float x, float y, float z)
{
	push_back_vector(ct->x, &x);
	push_back_vector(ct->y, &y);
	push_back_vector(ct->z, &z);
}

static inline void	set_cylinder_direction(t_ct *ct, float dx, float dy, float dz)
{
	push_back_vector(ct->dx, &dx);
	push_back_vector(ct->dy, &dy);
	push_back_vector(ct->dz, &dz);
}

static inline void	set_cylinder_radius(t_ct *ct, float diam)
{
	float	radius;

	radius = diam / 2;
	push_back_vector(ct->radius, &radius);
}

static inline void	set_cylinder_height(t_ct *ct, float height)
{
	push_back_vector(ct->height, &height);
}

static inline void	set_cylinder_color(t_cr *cr, unsigned int r, unsigned int g, unsigned int b)
{
	push_back_vector(cr->r, &r);
	push_back_vector(cr->g, &g);
	push_back_vector(cr->b, &b);
}

#endif //SET_CYLINDER_H
