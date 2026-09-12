#ifndef MINIRT_H
#define MINIRT_H

# include "ft_stack_alloc.h"
# include "shapes.h"
#include "types.h"

typedef struct s_mrt
{
	t_stack_alloc	*sa;
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	t_cam			cam;
	t_amb_light		amb_light;
	t_light			light;
}	t_mrt;

#endif //MINIRT_H
