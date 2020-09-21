/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tangent_to_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:59:17 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/21 23:48:31 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

int		tang_to_cyln(t_vector v_ov_, t_cylindr cyln, float *t, t_coord camera)
{
	t_quadr_equation	factor;
	t_vector			v_co_;
	float				dot_ov_r;
	float				dot_co_r;

	v_co_ = creat_vector(cyln.center, camera);
	// normal_rotation(&v_co_);
	dot_co_r = dot(v_co_.distance, cyln.rotation);
	dot_ov_r = dot(v_ov_.distance, cyln.rotation);
	factor.a = dot(v_ov_.distance, v_ov_.distance) - pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (dot(v_ov_.distance, v_co_.distance) -
												dot_co_r * dot_ov_r);
	factor.c = dot(v_co_.distance, v_co_.distance) - pow(dot_co_r, 2.0) -
												cyln.rad * cyln.rad;
	return (quadr_equation(factor, t));
}

int		tang_to_sph(t_vector v_ov_, t_sph sph, float *t, t_coord camera)
{
	t_quadr_equation	factor;
	t_vector			v_co_;

	v_co_ = creat_vector(sph.center, camera);
	factor.a = dot(v_ov_.distance, v_ov_.distance);
	factor.b = 2.0 * dot(v_co_.distance, v_ov_.distance);
	factor.c = dot(v_co_.distance, v_co_.distance) - sph.rad * sph.rad;
	return (quadr_equation(factor, t));
}

void	put_color(t_color *pix_color, float t_min, float t_extr, float *t, t_color obj_color)
{
	if (t_extr > t_min && t_extr < 100000.0 && (*t == -1.0 || t_extr < *t))
	{
		*t = t_extr;
		change_color(pix_color, obj_color.r, obj_color.g, obj_color.b);
	}
}

t_color		find_color(t_vector _ov_, t_object *object, float t_min) // t_max
{
	int			i;
	float		t_extr;
	float		t;
	int			find;

	i = 0;
	t_min = 0.0;
	t = -1.0;
	find = 0;
	while (object->sph_objs && i < object->num_sphs)
		if ((find += tang_to_sph(_ov_, object->sph_objs[i++], &t_extr, object->camera)))
			put_color(&object->pix_color, t_min, t_extr, &t, object->sph_objs->color);

	i = 0;
	while (object->cyln_objs && i < object->num_cylns)
		if ((find += tang_to_cyln(_ov_, object->cyln_objs[i++], &t_extr, object->camera)))
			put_color(&object->pix_color, t_min, t_extr, &t, object->cyln_objs->color);
	if (!find)
		change_color(&object->pix_color, 0, 0, 0);
	return (object->pix_color);
}
