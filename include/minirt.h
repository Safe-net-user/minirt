#ifndef MINIRT_H
#define MINIRT_H

#include "shape/sphere.h"
#include "shape/plane.h"
#include "shape/cylinder.h"
#include "physic/light.h"
#include "entity/camera.h"

typedef struct s_mrt
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				ll;
	int				bpp;
	int				endian;
	short			window_w;
	short			window_h;
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	t_cam			cam;
	t_amb_light		amb_light;
	t_light			light;
}	t_mrt;

int		parser(t_mrt *mrt, char *path);

#endif //MINIRT_H
