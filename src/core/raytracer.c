#include <stddef.h>
#include "core.h"
#include "macros.h"
#include "minirt.h"
#include "mlx.h"
#include "physic/intersection.h"
#include "physic/light.h"
#include "physic/ray.h"

void    my_mlx_put(t_mrt *mrt, int x, int y, int color)
{
	char    *dst;

	dst = mrt->addr + (y * mrt->ll + x * (mrt->bpp / 8));
	*(unsigned int *)dst = color;
}

void	launch_ray_tracer(t_mrt *mrt)
{
	t_ray	r;
	size_t	x;
	size_t	y;
	size_t	sp_i;
	/*size_t	cy_i;
	size_t	pl_i;*/

	y = 0;
	sp_i = 0;
	/*cy_i = 0;
	pl_i = 0;*/
	t_point	ray_origin = set_point(150, 150, -5.5);
	t_point	p;
	int wall_z = 50;
	mrt->img = mlx_new_image(mrt->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mrt->addr = mlx_get_data_addr(mrt->img, &mrt->bpp, &mrt->ll, &mrt->endian);
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			p = set_point(x, y, wall_z);
			r = set_ray(ray_origin, normalize_vector(sub_points(p, ray_origin)));
			sp_i = 0;
			while (sp_i < mrt->sphere.st.x->size)
			{
				intersect(&mrt->sphere, sp_i, &r);
				if (r.intersect.is_hit)
					my_mlx_put(mrt, x, y,
						lighting_sphere(
							&mrt->sphere,
							mrt->amb_light,
							mrt->light,
							sp_i,
							position(r, r.intersect.t),
							normal_at(
								set_point(
									((float *)r.intersect.object.sp->st.x->buffer)[sp_i],
									((float *)r.intersect.object.sp->st.y->buffer)[sp_i],
									((float *)r.intersect.object.sp->st.z->buffer)[sp_i]), position(r, r.intersect.t)),
							negate_vector(r.direction)));
				sp_i++;
			}
			/*while (cy_i < mrt->cylinder.ct.x->size)
			{
				cy_i++;
			}
			while (pl_i < mrt->plane.pt.x->size)
			{
				pl_i++;
			}*/
			x++;
		}

		/*cy_i = 0;
		pl_i = 0;*/
		y++;
	}
	mlx_put_image_to_window(mrt->mlx, mrt->mlx_win, mrt->img, 0, 0);
}