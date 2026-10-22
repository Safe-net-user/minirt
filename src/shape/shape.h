#ifndef SHAPE_H
#define SHAPE_H

#include "sphere.h"
#include "cylinder.h"
#include "plane.h"
#include "minirt.h"

int	init_sphere(t_sphere *s);
int	init_plane(t_plane *p);
int	init_cylinder(t_cylinder *c);
void	free_sphere(t_mrt *mrt);
void	free_cylinder(t_mrt *mrt);
void	free_plane(t_mrt *mrt);

#endif //SHAPE_H
