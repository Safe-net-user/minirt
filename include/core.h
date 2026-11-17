#ifndef CORE_H
#define CORE_H

#include "minirt.h"

void	launch_ray_tracer(t_mrt *mrt);
int is_shadowed(t_mrt *mrt, t_vec4 normal, t_point p);

#endif //CORE_H
