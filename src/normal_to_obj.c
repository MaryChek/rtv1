/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_to_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:45:41 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/09 16:55:36 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
static t_coord		cone_normal(t_coord rotation, t_obj_info near, float angle,
															t_coord direct)
{
	t_coord	normal;
	float	k;
	float	m;

	k = tanf(0.5f * (angle * PI / 180.0f));
	m = dot(direct, rotation) * near.t + dot(near.st_cent, rotation);
	k = (k * k + 1.0f) * m;
	normal = vctr_sub(near.center, near.point);
	normal = vctr_sub(vctr_mult(rotation, k), normal);
	return (normal);
}

static t_coord		cyln_normal(t_coord rotation, t_obj_info near, t_coord direct)
{
	float	m;
	t_coord	normal;

	m = dot(direct, rotation) * near.t + dot(near.st_cent, rotation);
	normal = vctr_sub(near.center, near.point);
	normal = vctr_sub(vctr_mult(rotation, m), normal);
	return (normal);
}

t_coord				normal_to_obj(t_object my, t_obj_info near)
{
	t_coord		normal;
	
	if (near.type == SPH)
		normal = vctr_sub(near.center, near.point);
	else if (near.type == CYLINDER)
		normal = cyln_normal(my.cyln_objs[near.index].rotation, near, my.camera.direct);
	else if (near.type == CONE)
		normal = cone_normal(my.cone_objs[near.index].rotation, near,
									my.cone_objs[near.index].angle, my.camera.direct);
	else if (near.type == PLANE)
	{
		normal = my.plane_objs[near.index].rotation;
		if (dot(my.camera.direct, normal) > 0.0f)
			normal = vctr_reverse(normal);
	}
	return (vctr_normal(normal));
}