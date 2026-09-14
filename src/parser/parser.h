#ifndef PARSER_H
#define PARSER_H

# include <stddef.h>
# include "../../include/minirt.h"

typedef enum e_parser_return_value
{
	SUCCESS,
	ERROR,
	BAD_IDENTIFIER,
	D_CAMERA,
	D_LIGHT,
	D_AMB_LIGHT,
	COLOR,
	FOV,
	RATIO,
	COORDS,
	DIRECTION,
	DIAMETER,
	HEIGHT
} __attribute__ ((__packed__)) t_p_ret;

typedef struct s_parser
{
	t_mrt			*mrt;
	unsigned char	*str;
	size_t			index;
	t_p_ret			code_status;
	bool			is_camera;
	bool			is_amb_light;
	bool			is_light;
	char			padding[1];
}	t_parser;

typedef t_p_ret	(*t_parser_fn)(t_parser *);

t_p_ret	handle_parser_error(t_parser *p);
void	set_lut(t_parser_fn *lut);
void	set_lut_msg(char **lut);
void	set_parser(t_parser *p, t_mrt *mrt, unsigned char *str);
int		parse_float(t_parser *p, float *value);
int		parse_uchar(t_parser *p, unsigned int *value);
t_p_ret	parse_amb_light(t_parser *p);
t_p_ret	parse_blanks(t_parser *p);
t_p_ret	parse_camera(t_parser *p);
t_p_ret	parse_cylinder(t_parser *p);
t_p_ret	parse_light(t_parser *p);
t_p_ret	parse_plane(t_parser *p);
t_p_ret	parse_sphere(t_parser *p);

static inline int	parser_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

static inline int	parse_color(t_parser *p, unsigned int *r, unsigned int *g, unsigned int *b)
{
	if (parse_uchar(p, r))
		return (1);
	if (p->str[p->index] != ',')
		return (1);
	p->index++;
	if (parse_uchar(p, g))
		return (1);
	if (p->str[p->index] != ',')
		return (1);
	p->index++;
	if (parse_uchar(p, b))
		return (1);
	return (0);
}

static inline int	parse_coordinates(t_parser *p, float *x, float *y, float *z)
{
	if (parse_float(p, x))
		return (1);
	if (p->str[p->index] != ',')
		return (1);
	p->index++;
	if (parse_float(p, y))
		return (1);
	if (p->str[p->index] != ',')
		return (1);
	p->index++;
	if (parse_float(p, z))
		return (1);
	return (0);
}

static inline int	parse_norm_vec3(t_parser *p, float *x, float *y, float *z)
{
	if (parse_float(p, x))
		return (1);
	if (p->str[p->index] != ',' && (*x >= -1.0 && *x <= 1.0))
		return (1);
	p->index++;
	if (parse_float(p, y))
		return (1);
	if (p->str[p->index] != ',' && (*x >= -1.0 && *x <= 1.0))
		return (1);
	p->index++;
	if (parse_float(p, z))
		return (1);
	if (*x < -1.0 && *x > 1.0)
		return (1);
	return (0);
}

static inline int	parse_ratio(t_parser *p, float *ratio)
{
	if (parse_float(p, ratio))
		return (1);
	return (*ratio > 1.0f);
}
#endif //PARSER_H
