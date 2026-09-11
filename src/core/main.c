#include "parser.h"

int	main(int ac, char **av)
{
	if (!av || ac != 2 || !av[1] || parser(av[1]))
		return (1);
	return (0);
}