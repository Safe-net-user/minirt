#ifndef SET_CAMERA_H
#define SET_CAMERA_H

#include "minirt.h"
#include "types.h"

static inline void	set_camera_coords(t_mrt *mrt, float x, float y, float z)
{
	mrt->cam.coords.x = x;
	mrt->cam.coords.y = y;
	mrt->cam.coords.z = z;
}

static inline void	set_camera_direction(t_mrt *mrt, float x, float y, float z)
{
	mrt->cam.direction.x = x;
	mrt->cam.direction.y = y;
	mrt->cam.direction.z = z;
}

static inline void	set_camera_fov(t_mrt *mrt, int fov)
{
	mrt->cam.fov = (uint8_t)fov;
}

#endif //SET_CAMERA_H
