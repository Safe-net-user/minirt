#ifndef PARSER_H
#define PARSER_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

# include <stddef.h>
# include <stdint.h>

typedef enum e_state
{
	NORMAL,
	AMBIENT_LIGHTNING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
} __attribute__ ((__packed__)) t_state;

typedef struct s_parser
{
	unsigned char	*str;
	size_t	index;
	t_state	state;
	bool	is_camera;
	bool	is_amb_light;
	bool	is_light;
	char	padding[1];
}	t_parser;

typedef int	(*t_parser_fn)(t_parser *);

int	parser(char *path);
int	handle_parser_error(t_parser *p);
void	set_lut(t_parser_fn *lut);
void	set_parser(t_parser *p, unsigned char *str);
int	parse_float(t_parser *p, float *value);
int	parse_uchar(t_parser *p, unsigned int *value);
int	parse_amb_light(t_parser *p);
int	parse_blanks(t_parser *p);
int	parse_camera(t_parser *p);
int	parse_cylinder(t_parser *p);
int	parse_light(t_parser *p);
int	parse_plane(t_parser *p);
int	parse_sphere(t_parser *p);

static inline int	parse_color(t_parser *p)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (parse_uchar(p, &r))
		return (1);
	if (p->str[p->index] != ',')
		return (1);
	p->index++;
	if (parse_uchar(p, &g))
		return (1);
	if (p->str[p->index] != ',')
		return (1);
	p->index++;
	if (parse_uchar(p, &b))
		return (1);
	return (0);
}

static inline int	parse_coordinates(t_parser *p)
{
	float	x;
	float	y;
	float	z;

	if (parse_float(p, &x))
		return (1);
	if (p->str[p->index] != ',')
		return (1);
	p->index++;
	if (parse_float(p, &y))
		return (1);
	if (p->str[p->index] != ',')
		return (1);
	p->index++;
	if (parse_float(p, &z))
		return (1);
	return (0);
}

static inline int	parse_norm_vec3(t_parser *p)
{
	float	x;
	float	y;
	float	z;

	if (parse_float(p, &x))
		return (1);
	if (p->str[p->index] != ',' && (x >= -1.0 && x <= 1.0))
		return (1);
	p->index++;
	if (parse_float(p, &y))
		return (1);
	if (p->str[p->index] != ',' && (x >= -1.0 && x <= 1.0))
		return (1);
	p->index++;
	if (parse_float(p, &z))
		return (1);
	if (x >= -1.0 && x <= 1.0)
		return (1);
	return (0);
}

static inline int	parse_ratio(t_parser *p)
{
	float	ratio;

	if (parse_float(p, &ratio))
		return (1);
	return (ratio > 1.0f);
}

#endif //PARSER_H
