#include "parser.h"

int	parse_cylinder(t_parser *p)
{
	float	diameter;
	float	height;

	p->index++;
	if (p->str[p->index] != 'y')
		return (1);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_norm_vec3(p))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_float(p, &diameter))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_float(p, &height))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_color(p))
		return (1);
	return (0);
}