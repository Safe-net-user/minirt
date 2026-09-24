#include "minirt.h"
#include "ft_stack_alloc.h"
#include "macros.h"
#include "mlx.h"
#include "../../include/minirt.h"

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
	mlx_key_hook(mrt.mlx_win, key_hook, &mrt);
	mlx_hook(mrt.mlx_win, 17, 1L << 2, free_mlx_mrt, &mrt);
	mlx_loop(mrt.mlx);
	//free_mrt(&mrt);
	return (0);
}
