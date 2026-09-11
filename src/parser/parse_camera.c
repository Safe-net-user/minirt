#include "parser.h"

int	parse_camera(t_parser *p)
{
	unsigned int	fov;

	if (p->is_camera)
		return (1);
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
	if (parse_uchar(p, &fov))
		return (1);
	p->is_camera = 1;
	return (0);
}