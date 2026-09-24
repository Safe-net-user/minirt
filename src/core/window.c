#include "macros.h"
#include "minirt.h"

int	key_hook(int keycode, void *param)
{
	t_mrt	*mrt;

	mrt = (t_mrt *)param;
	if (keycode == ESC_KEY)
		free_mlx_mrt(mrt);
	return (0);
}
