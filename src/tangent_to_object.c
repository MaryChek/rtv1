/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tangent_to_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:59:17 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/02 19:10:47 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

t_coord		cone_normal(t_coord rotation, t_obj_info near, int angle)
{
	t_coord	normal;
	float	k;
	float	m;

	k = (float)tan(0.5 * (angle * PI / 180));
	m = dot(near.begin_vec, rotation) * near.t + dot(near.st_cent, rotation);
	k = (k * k + 1.0f) * m;
	normal = vector_coord(near.center, near.point);
	normal = vector_coord(vec_scalar_mult(rotation, k), normal);
	return (normal);
}

t_coord		cyln_normal(t_coord rotation, t_obj_info near)
{
	float	m;
	t_coord	normal;

	m = dot(near.begin_vec, rotation) * near.t + dot(near.st_cent, rotation);
	normal = vector_coord(near.center, near.point);
	normal = vector_coord(vec_scalar_mult(rotation, m), normal);
	return (normal);
}

void		check_near_obj(t_raytrace value, t_obj_info **near, int type, int index)
{
	if ((!(*near) || value.t_near < (*near)->t))
	{
		if (!(*near))
			*near = (t_obj_info *)malloc(sizeof(t_obj_info));
		(*near)->center = value.center;
		(*near)->st_cent = value.st_cent;
		(*near)->t = value.t_near;
		(*near)->type = type;
		(*near)->index = index;
		(*near)->begin_vec = value.begin_vec;
	}
}

t_raytrace	min_and_max_to_raytracing(float t_min, float t_max)
{
	t_raytrace	value;

	value.t_max = t_max;
	value.t_min = t_min;
	return (value);
}

int			tang_to_plane(t_raytrace *value, t_plane plane, t_coord st_point)
{
	float		t;
	float		dot_ov_r;
	float		dot_co_r;

	value->center = plane.center;
	value->st_cent = vector_coord(plane.center, st_point);
	dot_co_r = dot(value->st_cent, plane.rotation);
	dot_ov_r = dot(value->begin_vec, plane.rotation);
	if (dot_ov_r > 0.0 || dot_ov_r < 0.0)
	{
		t = (float)(- dot_co_r / dot_ov_r);
		if ((t > (value->t_min) && t < value->t_max))
		{
			value->t_near = t;
			return (1);
		}
	}
	return (0);
}

int			tang_to_cone(t_raytrace *value, t_cone cone, t_coord st_point)
{
	t_quadr_equation	factor;
	float				dot_ov_r;
	float				dot_co_r;
	float				k;

	value->center = cone.center;
	value->st_cent = vector_coord(cone.center, st_point);
	dot_co_r = dot(value->st_cent, cone.rotation);
	dot_ov_r = dot(value->begin_vec, cone.rotation);
	k = (float)tan(0.5 * (cone.angle * PI / 180));
	k = k * k + 1.0;
	factor.a = dot(value->begin_vec, value->begin_vec) -
							k * (float)pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (dot(value->begin_vec, value->st_cent)
							- k * dot_co_r * dot_ov_r);
	factor.c = dot(value->st_cent, value->st_cent)
							- k * (float)pow(dot_co_r, 2.0);
	return (quadr_equation(factor, value));
}

int			tang_to_cyln(t_raytrace *value, t_cylindr cyln, t_coord st_point)
{
	t_quadr_equation	factor;
	float				dot_ov_r;
	float				dot_co_r;
	t_coord				center;

	value->center = cyln.center;
	value->st_cent = vector_coord(cyln.center, st_point);
	dot_co_r = dot(value->st_cent, cyln.rotation);
	dot_ov_r = dot(value->begin_vec, cyln.rotation);
	factor.a = dot(value->begin_vec, value->begin_vec) -
										(float)pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (dot(value->begin_vec, value->st_cent) -
												dot_co_r * dot_ov_r);
	factor.c = dot(value->st_cent, value->st_cent) -
							(float)pow(dot_co_r, 2.0) - cyln.rad * cyln.rad;
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
	i = -1;
	while (my.cone_objs && ++i < my.num_cons)
		if (tang_to_cone(&value, my.cone_objs[i], point))
			check_near_obj(value, &near, CONE, i);
	i = -1;
	while (my.plane_objs && ++i < my.num_plans)
		if (tang_to_plane(&value, my.plane_objs[i], point))
			check_near_obj(value, &near, PLANE, i);
	return (near);
}
