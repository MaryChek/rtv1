/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:54:06 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/18 20:50:40 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		get_obj_color(t_scene objs, int type, int index)
{
	if (type == SPH)
		return (objs.sph_objs[index].color);
	else if (type == CYLINDER)
		return (objs.cyln_objs[index].color);
	else if (type == CONE)
		return (objs.cone_objs[index].color);
	else
		return (objs.plane_objs[index].color);
}

int			get_specul_obj(t_scene objs, int type, int index)
{
	if (type == SPH)
		return (objs.sph_objs[index].specular);
	else if (type == CYLINDER)
		return (objs.cyln_objs[index].specular);
	else if (type == CONE)
		return (objs.cone_objs[index].specular);
	else
		return (objs.plane_objs[index].specular);
}

t_coord		get_direction(t_vector camera, int x, int y)
{
	t_coord		direction;
	t_coord		point;
	double		distanse;

	// distanse = (WIN_WID) / tan(FOV / 2);
	distanse = WIN_DIST;
	point = (t_coord){x - (WIN_WID / 2), (WIN_HIG / 2) - y, distanse};
	point = vctr_rotation(point, camera.roter);
	direction = vctr_normal(vctr_sub(camera.point, point));
	return (direction);
}
