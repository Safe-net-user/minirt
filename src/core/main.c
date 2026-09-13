#include "minirt.h"
#include "ft_stack_alloc.h"
#include "macros.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_mrt	mrt;

	if (!av || ac != 2 || !av[1])
		return (1);
	if (init_minirt(&mrt))
		return (1);
	parser(&mrt, av[1]);
	free_mrt(&mrt);
	return (0);
}