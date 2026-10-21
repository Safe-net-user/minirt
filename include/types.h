#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include "maths.h"

typedef struct s_cam
{
	t_point	direction;
	t_point	coords;
	uint8_t	fov;
	char	padding[7];
}	t_cam;

#endif //TYPES_H
