#include "parser.h"
#include "setter/set_sphere.h"

static inline t_p_ret	parse_sphere_end(t_parser *p)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_color(p, &r, &g, &b))
		return (COLOR);
	set_sphere_color(&p->mrt->sphere.sr, r, g, b);
	return (SUCCESS);
}

t_p_ret	parse_sphere(t_parser *p)
{
	float	diam;
	float	x;
	float	y;
	float	z;

	p->index++;
	if (p->str[p->index] != 'p')
		return (BAD_IDENTIFIER);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p, &x, &y, &z))
		return (COORDS);
	set_sphere_coords(&p->mrt->sphere.st, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_float(p, &diam))
		return (DIAMETER);
	set_sphere_radius(&p->mrt->sphere.st, diam);
	return (parse_sphere_end(p));
}