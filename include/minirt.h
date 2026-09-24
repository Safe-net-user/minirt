#ifndef MINIRT_H
#define MINIRT_H

# include "ft_stack_alloc.h"
# include "shapes.h"
#include "types.h"

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
int		free_mlx_mrt(t_mrt *mrt);
int		parser(t_mrt *mrt, char *path);
int		init_minirt(t_mrt *mrt);
void	free_mrt(t_mrt *mrt);

#endif //MINIRT_H
