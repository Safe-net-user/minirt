#ifndef SHAPES_H
#define SHAPES_H

#include "minirt.h"
#include "../src/shape/sphere.h"
#include "../src/shape/plane.h"
#include "../src/shape/cylinder.h"

int	init_sphere(t_sphere *s);
int	init_plane(t_plane *p);
int	init_cylinder(t_cylinder *c);
void	free_sphere(t_mrt *mrt);
void	free_cylinder(t_mrt *mrt);
void	free_plane(t_mrt *mrt);

#endif //SHAPES_H
