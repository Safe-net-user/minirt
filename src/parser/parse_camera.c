#include "parser.h"
#include "setter/set_camera.h"

int	parse_camera(t_parser *p)
{
	unsigned int	fov;
	float			x;
	float			y;
	float			z;

	if (p->is_camera)
		return (1);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p, &x, &y, &z))
		return (1);
	set_camera_coords(p->mrt, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_norm_vec3(p, &x, &y, &z))
		return (1);
	set_camera_direction(p->mrt, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_uchar(p, &fov))
		return (1);
	if (fov > 180)
		return (1);
	set_camera_fov(p->mrt, fov);
	p->is_camera = 1;
	return (0);
}