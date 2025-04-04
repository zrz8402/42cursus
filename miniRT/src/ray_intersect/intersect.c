/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:41:35 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/04 18:10:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

void	calculate_quadratic(t_sphere sphere, t_ray ray, t_quadratic *q)
{
	t_vect			sphere_to_ray;

	sphere_to_ray = subtract_vectors(ray.origin, sphere.center);
	q->a = dot_product(ray.direction, ray.direction);
	q->b = 2 * dot_product(ray.direction, sphere_to_ray);
	q->c = dot_product(sphere_to_ray, sphere_to_ray) - (sphere.diameter / 2 * sphere.diameter / 2);
	q->discriminant = pow(q->b, 2) - 4 * q->a * q->c;
}

t_intersect	*append_intersect(t_sphere sphere, t_ray ray)
{
	t_intersect	*intersect;
	t_quadratic	q;
	double		t1;
	double		t2;

	intersect = NULL;
	calculate_quadratic(sphere, ray, &q);
	if (q.discriminant < 0)
		return (NULL);
	t1 = (-q.b - sqrt(q.discriminant)) / (2 * q.a);
	t2 = (-q.b + sqrt(q.discriminant)) / (2 * q.a);
	if (t1 > EPSILON)
		add_intersect(&intersect, sphere, ray, t1);
	if (t2 > EPSILON && !equal(t2, t1))
		add_intersect(&intersect, sphere, ray, t2);
	return (intersect);
}

t_intersect *create_intersect(t_sphere sphere, t_ray ray, double t)
{
	t_intersect *new;

	new = malloc(sizeof(t_intersect));
	if (new == NULL) {
		return NULL;
	}
	new->point = add_vectors(ray.origin, scale_vector(ray.direction, t));
	new->normal = normalize(subtract_vectors(new->point, sphere.center));
	new->distance = t;
	new->solid = (void *) &sphere;
	new->next = NULL;
	return (new);
}

void	add_intersect(t_intersect **intersect, t_sphere sphere, t_ray ray, double t)
{
	t_intersect	*new;
	t_intersect *current;

	new = create_intersect(sphere, ray, t);
	if (new == NULL)
		return;
	new->next = *intersect;
	*intersect = new;
}
