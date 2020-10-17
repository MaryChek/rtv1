/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:45:41 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/17 19:57:30 by rtacos           ###   ########.fr       */
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

// void	iso(t_quat *com_quat, double x, double y, double z)
// {
// 	t_quat	ax_x;
// 	t_quat	ax_y;
// 	t_quat	ax_z;

// 	ax_x = creat_axis_of_rot((t_coord){1.0, 0.0, 0.0}, x);
// 	ax_y = creat_axis_of_rot((t_coord){0.0, 1.0, 0.0}, y);
// 	ax_z = creat_axis_of_rot((t_coord){0.0, 0.0, 1.0}, z);
// 	*com_quat = quat_mol(ax_y, ax_z);
// 	*com_quat = quat_mol(*com_quat, ax_x);
// }

t_coord		get_direction(t_vector camera, int x, int y)
{
	t_coord		direction;
	t_coord		point;
	t_coord		vector;
	t_quat		rotor;
	t_quat		asix;

	rotor = creat_axis_of_rot((t_coord){0, 0, 0}, 0.0);
	point = (t_coord){x - (WIN_WID / 2), (WIN_HIG / 2) - y, WIN_DIST};
	asix = creat_axis_of_rot((t_coord){1, 0, 0}, camera.angles.x);
	rotor = quat_mol(rotor, asix);
	quat_normal(&rotor);
	asix = creat_axis_of_rot((t_coord){0, 1, 0}, camera.angles.y);
	rotor = quat_mol(rotor, asix);
	quat_normal(&rotor);
	asix = creat_axis_of_rot((t_coord){0, 0, 1}, camera.angles.z);
	rotor = quat_mol(rotor, asix);
	quat_normal(&rotor);
	point = vctr_rotation(point, rotor);
	vector = vctr_sub(camera.point, point);
	direction = vctr_normal(vector);
	return (direction);
}

int			fixing_the_near_obj(t_ray_data value, t_obj_info *near,
												int type, int index)
{
	if ((near->t == -1 || value.t_near < near->t))
	{
		near->center = value.cent_obj;
		near->st_cent = value.st_cent;
		near->t = (value.t_near - 0.0001);
		near->type = type;
		near->index = index;
	}
	return (1);
}

t_ray_data	creat_ray(double max_len, t_coord point, t_coord direction)
{
	t_ray_data	ray;

	ray.t_max = max_len;
	ray.point = point;
	ray.direction = direction;
	return (ray);
}

double		ft_clampd(double num, double min, double max)
{
	num = num < min ? min : num;
	num = num > max ? max : num;
	return (num);
}
