#include "minirt.h"
#include "macros.h"
#include "vector.h"
#include "types.h"
#include "shapes.h"
#include "mlx.h"
#include "../../include/macros.h"

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

int	init_minirt(t_mrt *mrt)
{
	mrt->mlx = mlx_init();
	mrt->mlx_win = mlx_new_window(mrt->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
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