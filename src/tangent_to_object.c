/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tangent_to_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:59:17 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/17 22:07:48 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

int		tangent_to_sph(t_vector _ov_, t_sph sph, float *t)
{
	float	a;
	float	b;
	float	c;
	float	dis;
	float	t_2;
	t_vector	_oc_;

	_oc_ = creat_vector(sph.center, _ov_.st);
	a = dot(_ov_.distance, _ov_.distance);
	b = 2.0 * dot(_oc_.distance, _ov_.distance);
	c = dot(_oc_.distance, _oc_.distance) - sph.rad * sph.rad;
	if (((dis = b * b - 4 * a * c) >= 0.0))
	{
		*t = (float)((- b + (float)sqrt(dis)) / (2.0 * a));
		t_2 = (float)((- b - (float)sqrt(dis)) / (2.0 * a));
		*t = *t < t_2 ? *t : t_2;
		return (1);
	}
	else
		return (0);
}

int		find_tangent_to_object(t_vector _ov_, t_object my, float *t_min) // t_max
{
	int			i;
	float		t_extr;
	int			find;

	i = 0;
	*t_min = 0.0;
	find = 0;
	while (i < my.num_sphs)
		if (tangent_to_sph(_ov_, my.sph_objs[i++], &t_extr))
		{
			*t_min = (t_extr < *t_min && t_extr > 0.0) ? t_extr : *t_min;
			find++;
		}
	return (find);
}