#ifndef SET_AMB_LIGHT_H
#define SET_AMB_LIGHT_H

#include "minirt.h"
#include "types.h"

static inline void	set_amb_light_color(t_mrt *mrt, int r, int g, int b)
{
	mrt->amb_light.r = r;
	mrt->amb_light.g = g;
	mrt->amb_light.b = b;
}

static inline void	set_amb_light_ratio(t_mrt *mrt, float ratio)
{
	mrt->amb_light.ratio = ratio;
}

#endif
