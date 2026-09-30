#ifndef MINIRT_H
#define MINIRT_H

#include "types.h"
#include "../src/shape/sphere.h"
#include "../src/shape/plane.h"
#include "../src/shape/cylinder.h"

typedef struct s_mrt
{
	void			*mlx;
	void			*mlx_win;
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	t_cam			cam;
	t_amb_light		amb_light;
	t_light			light;
}	t_mrt;

int		key_hook(int keycode, void *param);
int		parser(t_mrt *mrt, char *path);
void	free_mrt(t_mrt *mrt);

#endif //MINIRT_H
