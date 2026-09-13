#include "parser.h"
#include "setter/set_plane.h"

static inline int parse_plane_end(t_parser *p)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_color(p, &r, &g, &b))
		return (1);
	set_plane_color(&p->mrt->plane.pr, r, g, b);
	return (0);
}

int	parse_plane(t_parser *p)
{
	float	x;
	float	y;
	float	z;

	p->index++;
	if (p->str[p->index] != 'l')
		return (1);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p, &x, &y, &z))
		return (1);
	set_plane_coords(&p->mrt->plane.pt, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_norm_vec3(p, &x, &y, &z))
		return (1);
	set_plane_direction(&p->mrt->plane.pt, x, y, z);
	return (parse_plane_end(p));
}