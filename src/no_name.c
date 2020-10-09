/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:45:41 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/09 17:02:34 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		get_obj_color(t_object my, int type, int index)
{
	if (type == SPH)
		return (my.sph_objs[index].color);
	else if (type == CYLINDER)
		return (my.cyln_objs[index].color);
	else if (type == CONE)
		return (my.cone_objs[index].color);
	else
		return (my.plane_objs[index].color);
}

int			get_specul_obj(t_object my, int type, int index)
{
	if (type == SPH)
		return (my.sph_objs[index].specular);
	else if (type == CYLINDER)
		return (my.cyln_objs[index].specular);
	else if (type == CONE)
		return (my.cone_objs[index].specular);
	else
		return (my.plane_objs[index].specular);
}

void		fixing_the_near_obj(t_ray_data ray, t_obj_info **near, int type, int index)
{
	if ((!(*near) || ray.t_near < (*near)->t))
	{
		if (!(*near))
		{
			*near = (t_obj_info *)malloc(sizeof(t_obj_info));
		}
		(*near)->center = ray.cent_obj;
		(*near)->st_cent = ray.st_cent;
		(*near)->t = (ray.t_near - 0.0001);
		(*near)->type = type;
		(*near)->index = index;
	}
}

t_ray_data	creat_ray(double max_len, t_coord point, t_coord direction)
{
	t_ray_data	ray;

	ray.t_max = max_len;
	ray.point = point;
	ray.diration = direction;
	return (ray);
}

t_coord		get_direction(t_cam camera, int x, int y)
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