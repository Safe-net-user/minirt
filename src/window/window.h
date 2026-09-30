#ifndef WINDOW_H
#define WINDOW_H

# define ESC_KEY 65307

# include "minirt.h"

int	free_mlx_mrt(t_mrt *mrt);
int	key_hook(int keycode, void *param);

#endif //WINDOW_H
