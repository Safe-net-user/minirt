#include "minirt.h"
#include "macros.h"
#include "core.h"
#include "shapes.h"
#include "mlx.h"
#include "window.h"

void	free_mrt(t_mrt *mrt)
{
	free_cylinder(mrt);
	free_plane(mrt);
	free_sphere(mrt);
}

static int	init_minirt(t_mrt *mrt)
{
	mrt->mlx = mlx_init();
	mrt->mlx_win = mlx_new_window(mrt->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	if (init_sphere(&mrt->sphere))
	{
		free_mrt(mrt);
		return (1);
	}
	if (init_plane(&mrt->plane))
	{
		free_mrt(mrt);
		return (1);
	}
	if (init_cylinder(&mrt->cylinder))
	{
		free_mrt(mrt);
		return (1);
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
		free_mrt(&mrt);
		return (1);
	}
	launch_ray_tracer(&mrt);
	mlx_key_hook(mrt.mlx_win, key_hook, &mrt);
	mlx_hook(mrt.mlx_win, 17, 1L << 2, free_mlx_mrt, &mrt);
	mlx_loop(mrt.mlx);
	free_mrt(&mrt);
	return (0);
}
