/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tangent_to_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:59:17 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/25 20:28:26 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

t_coord		cyln_normal(t_raytrace value, t_coord rotation, t_obj_info near)
{
	float	m;
	t_coord	normal;

	m = dot(value.begin_vec, rotation) * near.t + dot(value.center, rotation);
	normal = vector_coord(near.center, near.point);/*(P - C - V*m)*/
	normal = vector_coord(vec_scalar_mult(rotation, m), normal);
	return (normal);
}

void		check_near_obj(t_raytrace value, t_obj_info **near, int type, int index)
{
	if (value.t_near > value.t_min && value.t_near <= value.t_max &&
						(!(*near) || value.t_near < (*near)->t))
	{
		if (!(*near))
			*near = (t_obj_info *)malloc(sizeof(t_obj_info));
		(*near)->center = value.center;
		// (*near)->begin_vec = value.begin_vec;
		// (*near)->point = sum_vectors(value.camera,
		// 		vec_scalar_mult(value.begin_vec, value.t_near));
		(*near)->t = value.t_near;
		(*near)->type = type;
		(*near)->index = index;
	}
}

t_raytrace	fill_in_values_to_raytracing(float t_min, float t_max, float t_near,
														t_coord camera)
{
	t_raytrace	value;

	value.camera.x = camera.x;
	value.camera.y = camera.y;
	value.camera.z = camera.z;
	value.t_max = t_max;
	value.t_min = t_min;
	value.t_near = t_near;
	return (value);
}

int			tang_to_cyln(t_raytrace *value, t_cylindr cyln)
{
	t_quadr_equation	factor;
	float				dot_ov_r;
	float				dot_co_r;

	value->center = vector_coord(cyln.center, value->camera);
	dot_co_r = dot(value->center, cyln.rotation);
	dot_ov_r = dot(value->begin_vec, cyln.rotation);
	factor.a = dot(value->begin_vec, value->begin_vec) - pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (dot(value->begin_vec, value->center) -
												dot_co_r * dot_ov_r);
	factor.c = dot(value->center, value->center) -
							pow(dot_co_r, 2.0) - cyln.rad * cyln.rad;
	return (quadr_equation(factor, &value->t_near));
}

int			tang_to_sph(t_raytrace *value, t_sph sph)
{
	t_quadr_equation	factor;

	value->center = vector_coord(sph.center, value->camera);
	factor.a = dot(value->begin_vec, value->begin_vec);
	factor.b = 2.0 * dot(value->center, value->begin_vec);
	factor.c = dot(value->center, value->center) - sph.rad * sph.rad;
	return (quadr_equation(factor, &value->t_near));
}


t_color		new_func(t_obj_info *near, t_object my, t_raytrace value)
{
	t_coord		begin_vec;
	t_coord		normal;
	t_color		color;
	
	begin_vec = value.begin_vec;
	near->point = sum_vectors(value.camera, vec_scalar_mult(begin_vec, near->t));
	if (near->type == SPH)
	{
		color = my.sph_objs[near->index].color;
		normal = vector_coord(near->center, near->point);
	}
	else if (near->type == CYLINDER)
	{
		color = my.cyln_objs[near->index].color;
		normal = cyln_normal(value, my.cyln_objs[near->index].rotation, *near);
	}
	normal_vector(&normal);
	return (brightness_change(color, compute_lighting(near->point, normal, my.light_srcs, my.num_l_src)));
}

t_color		find_color(t_object my, t_raytrace value, t_obj_info *near) // t_max
{
	int			i;
	int			find;

	i = -1;
	find = 0;
	while (my.sph_objs && ++i < my.num_sphs)
		if (tang_to_sph(&value, my.sph_objs[i]))
			check_near_obj(value, &near, SPH, i);
	i = -1;
	while (my.cyln_objs && ++i < my.num_cylns)
		if (tang_to_cyln(&value, my.cyln_objs[i]))
			check_near_obj(value, &near, CYLINDER, i);
	if (!near)
		change_color(&my.pix_color, 0, 0, 0);
	else
		my.pix_color = new_func(near, my, value);
		// change_color(&my.pix_color, (near->type == SPH) ? my.sph_objs[near->index].color.r : my.cyln_objs[near->index].color.r,
		// 							(near->type == SPH) ? my.sph_objs[near->index].color.g : my.cyln_objs[near->index].color.g,
		// 							(near->type == SPH) ? my.sph_objs[near->index].color.b : my.cyln_objs[near->index].color.b);
	return (my.pix_color);
}

// int			put_color(t_color *pix_color, float t_min, float t_extr, float *t, t_color obj_color)
// {
// 	if (t_extr > t_min && t_extr <= 100000.0 && (*t == -1.0 || t_extr < *t))
// 	{
// 		*t = t_extr;
// 		change_color(pix_color, obj_color.r, obj_color.g, obj_color.b);
// 		return (1);
// 	}
// 	return (0);
// }