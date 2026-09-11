#include "parser.h"

void	set_lut(t_parser_fn *lut)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		lut[i] = handle_parser_error;
		i++;
	}
	lut['\n'] = parse_blanks;
	lut[' '] = parse_blanks;
	lut['A'] = parse_amb_light;
	lut['C'] = parse_camera;
	lut['L'] = parse_light;
	lut['s'] = parse_sphere;
	lut['p'] = parse_plane;
	lut['c'] = parse_cylinder;
}

void	set_parser(t_parser *p, unsigned char *str)
{
	p->str = str;
	p->index = 0;
	p->state = NORMAL;
	p->is_camera = 0;
	p->is_amb_light = 0;
	p->is_light = 0;
}
