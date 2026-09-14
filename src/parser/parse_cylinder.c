#include "parser.h"
#include "setter/set_cylinder.h"

static inline t_p_ret	parse_cylinder_end(t_parser *p)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	float			height;

	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_float(p, &height))
		return (HEIGHT);
	set_cylinder_height(&p->mrt->cylinder.ct, height);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_color(p, &r, &g, &b))
		return (COLOR);
	set_cylinder_color(&p->mrt->cylinder.cr, r, g, b);
	return (SUCCESS);
}

t_p_ret	parse_cylinder(t_parser *p)
{
	float	diam;
	float	x;
	float	y;
	float	z;

	p->index++;
	if (p->str[p->index] != 'y')
		return (BAD_IDENTIFIER);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p, &x, &y, &z))
		return (COORDS);
	set_cylinder_coords(&p->mrt->cylinder.ct, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_norm_vec3(p, &x, &y, &z))
		return (DIRECTION);
	set_cylinder_direction(&p->mrt->cylinder.ct, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_float(p, &diam))
		return (DIAMETER);
	set_cylinder_radius(&p->mrt->cylinder.ct, diam);
	return (parse_cylinder_end(p));
}