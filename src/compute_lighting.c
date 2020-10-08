/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:03:46 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/01 10:07:32 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

 double	compute_lighting(t_coord point, t_coord normal, t_object *object,
						  t_raytrace value)
{
	 double	light_pow;
	int		i;
	t_coord	vec_l;
	 double	nor_dot_l;

	light_pow = 0.0;
	i = -1;
	while (++i < object->num_l_src)
	{
		if (object->light_srcs[i].type == AMBIENT)
			light_pow += object->light_srcs[i].intensity;
		else
		{
			if (object->light_srcs[i].type == POINT)
				vec_l = normal_vector(vector_coord(point,
												   object->light_srcs[i].pos_or_dir));
			else
				vec_l = normal_vector(object->light_srcs[i].pos_or_dir);
			value.begin_vec = vec_l;
			if (!ray_tracing(object, value, point)
				&& (nor_dot_l = dot(normal, vec_l)) > T_MIN)
				light_pow += object->light_srcs[i].intensity * nor_dot_l;
		}
	}
//	ft_safe_free(near);
	return (light_pow);
}

t_color		color_near_obj(t_object *object, t_obj_info near)
{
	if (near.type == SPH)
		return (object->sph_objs[near.index].color);
	else if (near.type == CYLINDER)
		return (object->cyln_objs[near.index].color);
	else if (near.type == CONE)
		return (object->cone_objs[near.index].color);
	else
		return (object->plane_objs[near.index].color);
}


t_color		light_and_shadow(t_obj_info *near, t_object *object, t_raytrace value)
{
	t_coord		normal;
	t_color		color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	normal.x = 0;
	normal.y = 0;
	normal.z = 0;
	near->point = sum_vectors(object->camera,
							  vec_scalar_mult(near->begin_vec, near->t));
	if (near->type == SPH)
	{
		normal = normal_vector(vector_coord(near->center, near->point));
	}
	else if (near->type == CYLINDER)
	{
		normal = cyln_normal(object->cyln_objs[near->index].rotation, *near);
	}
	else if (near->type == CONE)
	{
		normal = cone_normal(object->cone_objs[near->index].rotation, *near,
							 object->cone_objs[near->index].angle);
	}
	else if (near->type == PLANE)
	{
		normal = object->plane_objs[near->index].rotation;
	}
	value = fill_in_values_to_raytracing(0.001f, 1.0, 0.0);
	 double tmp = compute_lighting(near->point, normal, object, value);
	return (brightness_change(color_near_obj(object, *near), tmp));
}