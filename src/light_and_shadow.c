/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:03:46 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/08 20:11:04 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_coord		get_vec_point_light(t_object my, t_coord point, int ind, t_raytrace *value)
{
	t_coord	vec_l;

	if (my.light_srcs[ind].type == POINT)
	{
		vec_l = vector_coord(point,
						my.light_srcs[ind].pos_or_dir);
		min_and_max_to_raytrace(value, 0.00001f, vector_len(vec_l));
	}
	else
	{
		vec_l = normal_vector(my.light_srcs[ind].pos_or_dir);
		min_and_max_to_raytrace(value, 0.00001f, INFINITY);
	}
	return (vec_l);
}

int		shadow_overlay(t_raytrace value, t_coord vec_l, t_object my, t_coord point)
{
	t_obj_info	*near;
	
	value.begin_vec = normal_vector(vec_l);
	if (!(near = ray_trace(my, value, point)))
		return (1);
	free(near);
	return (0);
}

double	compute_lighting(t_coord point, t_coord normal, t_object my, int specular)
{
	t_coord		vec_l;
	double		light_pow;
	int			i;
	t_raytrace	value;
	double		nor_dot_l;

	light_pow = 0.0;
	i = -1;
	while (++i < my.num_l_src)
	{
		if (my.light_srcs[i].type == AMBIENT)
			light_pow += my.light_srcs[i].intensity;
		else
		{
			vec_l = get_vec_point_light(my, point, i, &value);
			if (shadow_overlay(value, vec_l, my, point)
			&& (nor_dot_l = dot(normal, vec_l)) > 0.0)
				light_pow += (my.light_srcs[i].intensity * nor_dot_l) / (vector_len(vec_l));
		}
	}
	return (light_pow);
}

t_color		trace_to_light_src(t_obj_info near, t_object my, t_raytrace value)
{
	t_coord		normal;
	t_color		color;

	near.point = sum_vectors(my.camera,
				vec_scalar_mult(near.begin_vec, near.t));
	normal = normal_to_obj(my, near);
	return (brightness_change(
		get_obj_color(my, near.type, near.index),
		compute_lighting(near.point, normal, my,
		get_specul_obj(my, near.type, near.index))));
}
