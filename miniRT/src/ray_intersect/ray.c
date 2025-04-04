
#include "minirt.h"
#include "operation.h"

t_ray	create_ray(t_vect origin, t_vect direction)
{
	return ((t_ray){origin, direction});
}

t_vect	ray_pos(t_ray ray, double t)
{
	return (add_vectors(ray.origin, scale_vector(ray.direction, t)));
}
