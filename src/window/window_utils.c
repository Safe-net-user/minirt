#include "window.h"
#include "minirt.h"
#include "mlx.h"
#include <stdlib.h>


int	free_mlx_mrt(t_mrt *mrt)
{
	mlx_destroy_window(mrt->mlx, mrt->mlx_win);
	mlx_destroy_display(mrt->mlx);
	free(mrt->mlx);
	free_mrt(mrt);
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	t_mrt	*mrt;

	mrt = (t_mrt *)param;
	if (keycode == ESC_KEY)
		free_mlx_mrt(mrt);
	return (0);
}