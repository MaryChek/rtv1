/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:03:46 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/01 19:38:03 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	compute_lighting(t_coord point, t_coord normal, t_object my,
													t_raytrace value)
{
	float	light_pow;
	int		i;
	t_coord	vec_l;
	float	nor_dot_l;

	light_pow = 0.0;
	i = -1;
	while (++i < my.num_l_src)
	{
		if (my.light_srcs[i].type == AMBIENT)
			light_pow += my.light_srcs[i].intensity;
		else
		{
			if (my.light_srcs[i].type == POINT)
				vec_l = vector_coord(point,
								my.light_srcs[i].pos_or_dir);
			else
				vec_l = my.light_srcs[i].pos_or_dir;
			// vec_l = normal_vector(vec_l);
			value.begin_vec = vec_l;
			if (!ray_tracing(my, value, point)
				&& (nor_dot_l = dot(normal, vec_l)) > 0.0)
				light_pow += (my.light_srcs[i].intensity * nor_dot_l) / (vector_len(vec_l));
		}
	}
	return (light_pow);
}

t_coord		normal_to_near_obj(t_object my, t_obj_info near)
{
	t_coord		normal;
	
	if (near.type == SPH)
		normal = normal_vector(vector_coord(near.center, near.point));
	else if (near.type == CYLINDER)
		normal = cyln_normal(my.cyln_objs[near.index].rotation, near);
	else if (near.type == CONE)
		normal = cone_normal(my.cone_objs[near.index].rotation, near,
									my.cone_objs[near.index].angle);
	else if (near.type == PLANE)
	{
		normal = my.plane_objs[near.index].rotation;
		if (dot(near.begin_vec, normal) > 0.0)
			reverse_vector(&normal);
	}
	return (normal);
}

t_color		color_near_obj(t_object my, int type, int index)
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

t_color		light_and_shadow(t_obj_info near, t_object my, t_raytrace value)
{
	t_coord		normal;
	t_color		color;

	near.point = sum_vectors(my.camera,
				vec_scalar_mult(near.begin_vec, near.t));
	normal = normal_to_near_obj(my, near);
	value = fill_in_values_to_raytracing(0.00001f, 1.0, 0.0);
	return (brightness_change(color_near_obj(my, near.type, near.index),
		compute_lighting(near.point, normal, my, value)));
}
