#ifndef SET_LIGHT_H
# define SET_LIGHT_H

#include "minirt.h"
#include "types.h"

static inline void	set_light_coords(t_mrt *mrt, float x, float y, float z)
{
	mrt->light.coords.x = x;
	mrt->light.coords.y = y;
	mrt->light.coords.z = z;
}

static inline void	set_light_ratio(t_mrt *mrt, float ratio)
{
	mrt->light.ratio = ratio;
}

static inline void	set_light_color(t_mrt *mrt, unsigned int r, unsigned int g, unsigned int b)
{
	mrt->light.r = r;
	mrt->light.g = g;
	mrt->light.b = b;
}

#endif