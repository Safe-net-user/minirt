#include "minirt.h"
#include "macros.h"
#include "core.h"
#include "mlx.h"
#include "window/window.h"
#include "shape/shape.h"
#include <stdlib.h>

static int	close_window(void)
{
	exit(0);
	return (0);
}

static int	init_minirt(t_mrt *mrt)
{
	mrt->mlx = mlx_init();
	mrt->mlx_win = mlx_new_window(mrt->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	if (init_sphere(&mrt->sphere))
	{
		free_mlx(mrt);
		exit(1);
	}
	if (init_plane(&mrt->plane))
	{
		free_mlx(mrt);
		free_sphere(mrt);
		exit(1);
	}
	if (init_cylinder(&mrt->cylinder))
	{
		free_mlx(mrt);
		free_plane(mrt);
		free_sphere(mrt);
		exit(1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mrt	mrt;

	if (!av || ac != 2 || !av[1])
		return (1);
	if (init_minirt(&mrt))
		return (1);
	if (parser(&mrt, av[1]))
	{
		free_mlx_mrt((void *)&mrt);
		return (1);
	}
	launch_ray_tracer(&mrt);
	mlx_key_hook(mrt.mlx_win, key_hook, &mrt);
	mlx_hook(mrt.mlx_win, 17, 1L << 2, close_window, &mrt);
	mlx_loop(mrt.mlx);
	free_mlx_mrt(&mrt);
	return (0);
}
