/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:25:44 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/30 17:38:30 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// float		is_domain_of_definition(float num, float min, float max)
// {
// 	return ((num > 0.0 && num < max) ? num : 0.0);
// }

float min(float a, float b)
{
	if (a < b && a >= 0.0f)
		return (a);
	else if (b >= 0.0f)
		return (b);
	return (0.00000f);
}

float		quadr_equation(t_quadr_equation factor, t_raytrace *value)
{
	float	dis;
	float	t_1;
	float	t_2;
	float	buf;
	
	if (((dis = factor.b * factor.b - 4 * factor.a * factor.c) >= 0.0))
	{
		t_1 = (float)((-factor.b + (float)sqrt(dis)) / (2.0f * factor.a));
		t_2 = (float)((-factor.b - (float)sqrt(dis)) / (2.0f * factor.a));
		buf = min(t_1, t_2);
		if (buf < value->t_max && buf > value->t_min)
			value->t_near = buf;
		else
			return (0);
		return (1);
	}
	return (0);
}

float		vector_len(t_coord vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y
									+ vector.z * vector.z));
}

t_coord		normal_vector(t_coord vector)
{
	float	vec_len;

	vec_len = vector_len(vector);
	vector.x /= vec_len;
	vector.y /= vec_len;
	vector.z /= vec_len;
	return (vector);
}