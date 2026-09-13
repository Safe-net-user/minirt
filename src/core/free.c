#include "minirt.h"
#include "vector.h"

void	free_mrt(t_mrt *mrt)
{
	free_vector(mrt->sphere.st.x);
	free_vector(mrt->sphere.st.y);
	free_vector(mrt->sphere.st.z);
	free_vector(mrt->sphere.st.radius);
	free_vector(mrt->sphere.sr.r);
	free_vector(mrt->sphere.sr.g);
	free_vector(mrt->sphere.sr.b);
	free_vector(mrt->plane.pt.x);
	free_vector(mrt->plane.pt.y);
	free_vector(mrt->plane.pt.z);
	free_vector(mrt->plane.pt.dx);
	free_vector(mrt->plane.pt.dy);
	free_vector(mrt->plane.pt.dz);
	free_vector(mrt->plane.pr.r);
	free_vector(mrt->plane.pr.g);
	free_vector(mrt->plane.pr.b);
	free_vector(mrt->cylinder.ct.x);
	free_vector(mrt->cylinder.ct.y);
	free_vector(mrt->cylinder.ct.z);
	free_vector(mrt->cylinder.ct.dx);
	free_vector(mrt->cylinder.ct.dy);
	free_vector(mrt->cylinder.ct.dz);
	free_vector(mrt->cylinder.ct.radius);
	free_vector(mrt->cylinder.ct.height);
	free_vector(mrt->cylinder.cr.r);
	free_vector(mrt->cylinder.cr.g);
	free_vector(mrt->cylinder.cr.b);
}