#include "parser.h"

int	parse_light(t_parser *p)
{
	if (p->is_light)
		return (1);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_ratio(p))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_color(p))
		return (1);
	p->is_light = 1;
	return (0);
}