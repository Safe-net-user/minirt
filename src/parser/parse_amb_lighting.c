#include "parser.h"

int	parse_amb_light(t_parser *p)
{
	if (p->is_amb_light)
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_ratio(p))
		return (1);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_color(p))
		return (1);
	p->is_amb_light = 1;
	return (0);
}