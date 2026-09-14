#include "parser.h"
#include "setter/set_camera.h"

t_p_ret	parse_camera(t_parser *p)
{
	unsigned int	fov;
	float			x;
	float			y;
	float			z;

	if (p->is_camera)
		return (D_CAMERA);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_coordinates(p, &x, &y, &z))
		return (COORDS);
	set_camera_coords(p->mrt, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_norm_vec3(p, &x, &y, &z))
		return (DIRECTION);
	set_camera_direction(p->mrt, x, y, z);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_uchar(p, &fov))
		return (FOV);
	if (fov > 180)
		return (FOV);
	set_camera_fov(p->mrt, fov);
	p->is_camera = 1;
	return (SUCCESS);
}