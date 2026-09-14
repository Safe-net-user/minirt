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

void	set_lut_msg(char **lut)
{
	lut[BAD_IDENTIFIER] = "invalid identifier";
	lut[D_CAMERA] = "duplicate camera";
	lut[D_LIGHT] = "duplicate light";
	lut[D_AMB_LIGHT] = "duplicate ambient light";
	lut[COLOR] = "invalid color";
	lut[FOV] = "invalid field of view";
	lut[RATIO] = "invalid resolution ratio";
	lut[COORDS] = "invalid coordinates";
	lut[DIRECTION] = "invalid direction";
	lut[DIAMETER] = "invalid diameter";
	lut[HEIGHT] = "invalid height";
}

void	set_parser(t_parser *p, t_mrt *mrt,  unsigned char *str)
{
	p->mrt = mrt;
	p->str = str;
	p->index = 0;
	p->code_status = BAD_IDENTIFIER;
	p->is_camera = 0;
	p->is_amb_light = 0;
	p->is_light = 0;
}
