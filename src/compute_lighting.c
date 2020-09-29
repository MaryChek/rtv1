/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:03:46 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/29 21:12:59 by rtacos           ###   ########.fr       */
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
				vec_l = normal_vector(vector_coord(point,
								my.light_srcs[i].pos_or_dir));
			else
				vec_l = normal_vector(my.light_srcs[i].pos_or_dir);
			value.begin_vec = vec_l;
			if (!ray_tracing(my, value, point)
				&& (nor_dot_l = dot(normal, vec_l)) > value.t_min)
				light_pow += my.light_srcs[i].intensity * nor_dot_l;
		}
	}
	return (light_pow);
}

t_color		light_and_shadow(t_obj_info *near, t_object my, t_raytrace value)
{
	t_coord		normal;
	t_color		color;

	near->point = sum_vectors(my.camera,
				vec_scalar_mult(near->begin_vec, near->t));
	if (near->type == SPH)
	{
		color = my.sph_objs[near->index].color;
		normal = normal_vector(vector_coord(near->center, near->point));
	}
	else if (near->type == CYLINDER)
	{
		color = my.cyln_objs[near->index].color;
		normal = cyln_normal(my.cyln_objs[near->index].rotation, *near);
	}
	else if (near->type == CONE)
	{
		color = my.cone_objs[near->index].color;
		normal = cone_normal(my.cone_objs[near->index].rotation, *near,
										my.cone_objs[near->index].angle);
	}
	value = fill_in_values_to_raytracing(0.00000001f, 1.0, -1.0);
	return (brightness_change(color,
		compute_lighting(near->point, normal, my, value)));
}
