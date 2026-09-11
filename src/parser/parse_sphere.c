#include "parser.h"

int	parse_sphere(t_parser *p)
{
	float	diameter;

	p->index++;
	if (p->str[p->index] != 'p')
		return (1);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_float(p, &diameter))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_color(p))
		return (1);
	return (0);
}