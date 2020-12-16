/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_to_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:45:41 by rtacos            #+#    #+#             */
/*   Updated: 2020/12/16 12:04:30 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_coord		cone_normal(t_coord rotation, t_obj_info near, float angle,
															t_coord direct)
{
	t_coord	normal;
	float	k;
	float	m;

	k = tanf(0.5f * (angle * M_PI / 180.0f));
	m = vctr_dot(direct, rotation) * near.t + vctr_dot(near.st_cent, rotation);
	k = (k * k + 1.0f) * m;
	normal = vctr_sub(near.center, near.point);
	normal = vctr_sub(vctr_mult(rotation, k), normal);
	return (normal);
}

static t_coord		cyln_normal(t_coord rotation, t_obj_info near,
													t_coord direct)
{
	float	m;
	t_coord	normal;

	m = vctr_dot(direct, rotation) * near.t + vctr_dot(near.st_cent, rotation);
	normal = vctr_sub(near.center, near.point);
	normal = vctr_sub(vctr_mult(rotation, m), normal);
	return (normal);
}

static t_coord		plane_normal(t_coord plane_direct, t_coord cam_direct)
{
	t_coord	normal;

	normal = plane_direct;
	if (vctr_dot(cam_direct, normal) > 0.0f)
		normal = vctr_reverse(normal);
	return (normal);
}

t_coord				normal_to_obj(t_scene objs, t_obj_info near)
{
	t_coord		normal;

	if (near.type == SPH)
		normal = vctr_sub(near.center, near.point);
	else if (near.type == CYLINDER)
		normal = cyln_normal(objs.cyln_objs[near.index].direction, near,
							objs.camera.direct);
	else if (near.type == CONE)
		normal = cone_normal(objs.cone_objs[near.index].direction, near,
							objs.cone_objs[near.index].angle,
							objs.camera.direct);
	else if (near.type == CAP_CYLN)
		normal = cyln_normal(objs.cyln_cap_objs[near.index].direction, near,
							objs.camera.direct);
	else
		normal = plane_normal(objs.plane_objs[near.index].direction,
							objs.camera.direct);
	return (vctr_normal(normal));
}
