/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tangent_to_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:59:17 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/29 21:24:41 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

t_coord		cone_normal(t_coord rotation, t_obj_info near, float angle)
{
	t_coord	normal;
	float	k;

	k = tan(angle);
	k = k * k + 1;
	normal = vector_coord(near.center, near.point);//( P-C - (1+k*k)*V*m )
	normal = vector_coord(vec_scalar_mult(rotation, k), normal);
	return (normal_vector(normal));
}

t_coord		cyln_normal(t_coord rotation, t_obj_info near)
{
	float	m;
	t_coord	normal;

	m = dot(near.begin_vec, rotation) * near.t + dot(near.center, rotation);
	normal = vector_coord(near.center, near.point);/*(P - C - V*m)*/
	normal = vector_coord(vec_scalar_mult(rotation, m), normal);
	return (normal_vector(normal));
}

void		check_near_obj(t_raytrace value, t_obj_info **near, int type, int index)
{
	if (value.t_near > value.t_min && value.t_near <= value.t_max &&
						(!(*near) || value.t_near < (*near)->t))
	{
		if (!(*near))
			*near = (t_obj_info *)malloc(sizeof(t_obj_info));
		(*near)->center = value.center;
		(*near)->t = value.t_near;
		(*near)->type = type;
		(*near)->index = index;
		(*near)->begin_vec = value.begin_vec;
	}
}

t_raytrace	fill_in_values_to_raytracing(float t_min, float t_max, float t_near)
{
	t_raytrace	value;

	value.t_max = t_max;
	value.t_min = t_min;
	value.t_near = t_near;
	return (value);
}

int			tang_to_cone(t_raytrace *value, t_cone cone, t_coord st_point)
{
	t_quadr_equation	factor;
	t_coord				center;
	float				dot_ov_r;
	float				dot_co_r;
	float				k;

	center = vector_coord(cone.center, st_point);
	dot_co_r = dot(center, cone.rotation);
	dot_ov_r = dot(value->begin_vec, cone.rotation);
	k = tan(cone.angle);
	k = k * k + 1;
	factor.a = dot(value->begin_vec, value->begin_vec) - k * pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (dot(value->begin_vec, center) -
												k * dot_co_r * dot_ov_r);
	factor.c = dot(center, center) - k * pow(dot_co_r, 2.0);
	return (quadr_equation(factor, value));
}

int			tang_to_cyln(t_raytrace *value, t_cylindr cyln, t_coord st_point)
{
	t_quadr_equation	factor;
	float				dot_ov_r;
	float				dot_co_r;
	t_coord				center;

	value->center = cyln.center;
	center = vector_coord(cyln.center, st_point);
	dot_co_r = dot(center, cyln.rotation);
	dot_ov_r = dot(value->begin_vec, cyln.rotation);
	factor.a = dot(value->begin_vec, value->begin_vec) - pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (dot(value->begin_vec, center) -
												dot_co_r * dot_ov_r);
	factor.c = dot(center, center) -
							pow(dot_co_r, 2.0) - cyln.rad * cyln.rad;
	return (quadr_equation(factor, value));
}

int			tang_to_sph(t_raytrace *value, t_sph sph, t_coord st_point)
{
	t_quadr_equation	factor;
	t_coord				center;

	value->center = sph.center;
	center = vector_coord(sph.center, st_point);
	factor.a = dot(value->begin_vec, value->begin_vec);
	factor.b = 2.0 * dot(center, value->begin_vec);
	factor.c = dot(center, center) - sph.rad * sph.rad;
	return (quadr_equation(factor, value));
}

t_obj_info		*ray_tracing(t_object my, t_raytrace value, t_coord point)
{
	int			i;
	t_obj_info	*near;

	i = -1;
	near = NULL;
	while (my.sph_objs && ++i < my.num_sphs)
		if (tang_to_sph(&value, my.sph_objs[i], point))
			check_near_obj(value, &near, SPH, i);
	i = -1;
	while (my.cyln_objs && ++i < my.num_cylns)
		if (tang_to_cyln(&value, my.cyln_objs[i], point))
			check_near_obj(value, &near, CYLINDER, i);
	// i = -1;
	// while (my.cone_objs && ++i < my.num_cons)
	// 	if (tang_to_cone(&value, my.cone_objs[i], point))
	// 		check_near_obj(value, &near, CONE, i);
	return (near);
}
