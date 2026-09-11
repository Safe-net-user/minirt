#include "parser.h"

int	parse_plane(t_parser *p)
{
	p->index++;
	if (p->str[p->index] != 'l')
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
	if (parse_color(p))
		return (1);
	return (0);
}