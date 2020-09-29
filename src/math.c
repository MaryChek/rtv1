/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:25:44 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/29 20:02:10 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		is_domain_of_definition(float num, float min, float max)
{
	return ((num < min) ? 0.0 : num);
}

float		quadr_equation(t_quadr_equation factor, t_raytrace *value)
{
	float	dis;
	float	t_1;
	float	t_2;
	
	if (((dis = factor.b * factor.b - 4 * factor.a * factor.c) >= 0.0))
	{
		t_1 = (float)((-factor.b + (float)sqrt(dis)) / (2.0f * factor.a));
		t_2 = (float)((-factor.b - (float)sqrt(dis)) / (2.0f * factor.a));
		t_1 = is_domain_of_definition(t_1, value->t_min, value->t_max);
		t_2 = is_domain_of_definition(t_2, value->t_min, value->t_max);
		if (t_1 != 0.0 && t_1 < t_2)
		{
			value->t_near = t_1;
			return(1);
		}
		else if (t_2 != 0.0 && t_2 < t_1)
		{
			value->t_near = t_2;
			return(1);
		}
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