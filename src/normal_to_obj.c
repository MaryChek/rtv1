/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_to_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:45:41 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/07 21:43:00 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
static t_coord		cone_normal(t_coord rotation, t_obj_info near, float angle)
{
	t_coord	normal;
	float	k;
	float	m;

	k = tanf(0.5f * (angle * PI / 180.0f));
	m = dot(near.begin_vec, rotation) * near.t + dot(near.st_cent, rotation);
	k = (k * k + 1.0f) * m;
	normal = vector_coord(near.center, near.point);
	normal = vector_coord(vec_scalar_mult(rotation, k), normal);
	return (normal);
}

static t_coord		cyln_normal(t_coord rotation, t_obj_info near)
{
	float	m;
	t_coord	normal;

	m = dot(near.begin_vec, rotation) * near.t + dot(near.st_cent, rotation);
	normal = vector_coord(near.center, near.point);
	normal = vector_coord(vec_scalar_mult(rotation, m), normal);
	return (normal);
}

t_coord				normal_to_obj(t_object my, t_obj_info near)
{
	t_coord		normal;
	
	if (near.type == SPH)
		normal = vector_coord(near.center, near.point);
	else if (near.type == CYLINDER)
		normal = cyln_normal(my.cyln_objs[near.index].rotation, near);
	else if (near.type == CONE)
		normal = cone_normal(my.cone_objs[near.index].rotation, near,
									my.cone_objs[near.index].angle);
	else if (near.type == PLANE)
	{
		normal = my.plane_objs[near.index].rotation;
		if (dot(near.begin_vec, normal) > 0.0f)
			normal = reverse_vector(normal);
	}
	return (normal_vector(normal));
}