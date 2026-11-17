#ifndef SET_CAMERA_H
#define SET_CAMERA_H

#include "minirt.h"
#include "macros.h"
#include "entity/camera.h"

static inline void set_camera(t_mrt *mrt)
{
	mrt->cam.forward = compute_forward(mrt->cam);
	mrt->cam.right = compute_right(mrt->cam.forward);
	mrt->cam.up = compute_up(
		mrt->cam.forward,
		mrt->cam.right);
	mrt->cam.pixel_size = compute_pixel_size(
		&mrt->cam,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		mrt->cam.fov);
}

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
