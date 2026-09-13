#include "parser.h"
#include "setter/set_light.h"

static inline int	parse_light_end(t_parser *p)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (parse_color(p, &r, &g, &b))
		return (1);
	set_light_color(p->mrt, r, g, b);
	p->is_light = 1;
	return (0);
}
int	parse_light(t_parser *p)
{
	float	x;
	float	y;
	float	z;
	float	ratio;

	p->index++;
	if (p->is_light)
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p, &x, &y, &z))
		return (1);
	set_light_coords(p->mrt, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_ratio(p, &ratio))
		return (1);
	set_light_ratio(p->mrt, ratio);
	while (p->str[p->index] == ' ')
		p->index++;
	return (parse_light_end(p));
}