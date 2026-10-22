#include "color.h"
#include <math.h>

int	rgba_to_int(const t_rgba c)
{
	return ((int)fminf(255, (int)c.a) << 24 | (int)fminf(255, (int)c.r) << 16 | (int)fminf(255, (int)c.g) << 8 | (int)fminf(255, (int)c.b));
}
