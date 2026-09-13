#include "minirt.h"
#include "ft_stack_alloc.h"
#include "macros.h"
#include <stdlib.h>

static void	free_mrt(t_mrt *mrt)
{
	free_vector(mrt->sphere.st.x);
	free_vector(mrt->sphere.st.y);
	free_vector(mrt->sphere.st.z);
	free_vector(mrt->sphere.st.radius);
	free_vector(mrt->sphere.sr.r);
	free_vector(mrt->sphere.sr.g);
	free_vector(mrt->sphere.sr.b);
	free_vector(mrt->plane.pt.x);
	free_vector(mrt->plane.pt.y);
	free_vector(mrt->plane.pt.z);
	free_vector(mrt->plane.pt.dx);
	free_vector(mrt->plane.pt.dy);
	free_vector(mrt->plane.pt.dz);
	free_vector(mrt->plane.pr.r);
	free_vector(mrt->plane.pr.g);
	free_vector(mrt->plane.pr.b);
	free_vector(mrt->cylinder.ct.x);
	free_vector(mrt->cylinder.ct.y);
	free_vector(mrt->cylinder.ct.z);
	free_vector(mrt->cylinder.ct.dx);
	free_vector(mrt->cylinder.ct.dy);
	free_vector(mrt->cylinder.ct.dz);
	free_vector(mrt->cylinder.ct.radius);
	free_vector(mrt->cylinder.ct.height);
	free_vector(mrt->cylinder.cr.r);
	free_vector(mrt->cylinder.cr.g);
	free_vector(mrt->cylinder.cr.b);
}

static int	init_sphere(t_sphere *s)
{
	s->st.x = init_vector(sizeof(float), SIZE_VECTOR);
	s->st.y = init_vector(sizeof(float), SIZE_VECTOR);
	s->st.z = init_vector(sizeof(float), SIZE_VECTOR);
	s->st.radius = init_vector(sizeof(float), SIZE_VECTOR);
	s->sr.r = init_vector(sizeof(float), SIZE_VECTOR);
	s->sr.g = init_vector(sizeof(float), SIZE_VECTOR);
	s->sr.b = init_vector(sizeof(float), SIZE_VECTOR);
	if (!s->st.x || !s->st.y || !s->st.z || !s->st.radius || \
!s->sr.r || !s->sr.g || !s->sr.b)
		return (1);
	return (0);
}

static int	init_plane(t_plane *p)
{
	p->pt.x = init_vector(sizeof(float), SIZE_VECTOR);
	p->pt.y = init_vector(sizeof(float), SIZE_VECTOR);
	p->pt.z = init_vector(sizeof(float), SIZE_VECTOR);
	p->pt.dx = init_vector(sizeof(float), SIZE_VECTOR);
	p->pt.dy = init_vector(sizeof(float), SIZE_VECTOR);
	p->pt.dz = init_vector(sizeof(float), SIZE_VECTOR);
	p->pr.r = init_vector(sizeof(float), SIZE_VECTOR);
	p->pr.g = init_vector(sizeof(float), SIZE_VECTOR);
	p->pr.b = init_vector(sizeof(float), SIZE_VECTOR);
	if (!p->pt.x || !p->pt.y || !p->pt.z || \
!p->pr.r || !p->pr.g || !p->pr.b)
		return (1);
	return (0);
}

static int	init_cylinder(t_cylinder *c)
{
	c->ct.x = init_vector(sizeof(float), SIZE_VECTOR);
	c->ct.y = init_vector(sizeof(float), SIZE_VECTOR);
	c->ct.z = init_vector(sizeof(float), SIZE_VECTOR);
	c->ct.dx = init_vector(sizeof(float), SIZE_VECTOR);
	c->ct.dy = init_vector(sizeof(float), SIZE_VECTOR);
	c->ct.dz = init_vector(sizeof(float), SIZE_VECTOR);
	c->ct.radius = init_vector(sizeof(float), SIZE_VECTOR);
	c->ct.height = init_vector(sizeof(float), SIZE_VECTOR);
	c->cr.r = init_vector(sizeof(float), SIZE_VECTOR);
	c->cr.g = init_vector(sizeof(float), SIZE_VECTOR);
	c->cr.b = init_vector(sizeof(float), SIZE_VECTOR);
	if (!c->ct.x || !c->ct.y || !c->ct.z || !c->ct.radius || !c->ct.height || \
!c->cr.r || !c->cr.g || !c->cr.b)
		return (1);
	return (0);
}

static int	init_minirt(t_mrt *mrt)
{
	if (init_sphere(&mrt->sphere))
	{
		free_mrt(mrt);
		return (1);
	}
	if (init_plane(&mrt->plane))
	{
		free_mrt(mrt);
		return (1);
	}
	if (init_cylinder(&mrt->cylinder))
	{
		free_mrt(mrt);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mrt	mrt;

	if (!av || ac != 2 || !av[1])
		return (1);
	if (init_minirt(&mrt))
		return (1);
	parser(&mrt, av[1]);
	free_mrt(&mrt);
	return (0);
}