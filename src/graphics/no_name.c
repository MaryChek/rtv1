/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:45:41 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/11 14:56:31 by rtacos           ###   ########.fr       */
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
	t_coord		vector;

	point = (t_coord){x - (WIN_WID / 2), (WIN_HIG / 2) - y, WIN_DIST};
	point = vctr_rotation(point, camera.roter);
	vector = vctr_sub(camera.point, point);
	direction = vctr_normal(vector);
	return (direction);
}

void		fixing_the_near_obj(t_ray_data value, t_obj_info **near, int type, int index)
{
	if ((!(*near) || value.t_near < (*near)->t))
	{
		if (!(*near))
			*near = (t_obj_info *)malloc(sizeof(t_obj_info));
		(*near)->center = value.cent_obj;
		(*near)->st_cent = value.st_cent;
		(*near)->t = (value.t_near - 0.0001);
		(*near)->type = type;
		(*near)->index = index;
	}
}

t_ray_data	creat_ray(double max_len, t_coord point, t_coord direction)
{
	t_ray_data	ray;

	ray.t_max = max_len;
	ray.point = point;
	ray.direction = direction;
	return (ray);
}