#ifndef INTERSECTION_H
#define INTERSECTION_H

# include <stddef.h>
# include "../shape/cylinder.h"
# include "../shape/plane.h"
# include "../shape/sphere.h"

typedef struct s_intersect
{
	size_t			id;
	union {
		t_sphere	*sp;
		t_cylinder	*cy;
		t_plane		*pl;
	} object;
	float			t[2];
	bool			is_hit;
}	t_intersect;

#endif //INTERSECTION_H
