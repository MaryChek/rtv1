/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:25:44 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/24 21:22:53 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		quadr_equation(t_quadr_equation factor, t_obj_info *near)
{
	float	dis;
	float	t_1;
	float	t_2;
	
	if (((dis = factor.b * factor.b - 4 * factor.a * factor.c) >= 0.0))
	{
		t_1 = (float)((- factor.b + (float)sqrt(dis)) / (2.0f * factor.a));
		t_2 = (float)((- factor.b - (float)sqrt(dis)) / (2.0f * factor.a));
		if (t_1 < 0.0 && t_2 < 0.0)
			return (0);
		else
			near->t = (t_1 >= 0.0 && (t_1 < t_2 || t_2 <= 0.0)) ? t_1 : t_2;
		return (1);
	}
	else
		return (0);
}

void		normal_rotation(t_coord *q)
{
	float	quat_len;

	quat_len = sqrt(q->x * q->x + q->y * q->y + q->z * q->z);
	q->x = q->x / quat_len;
	q->y = q->y / quat_len;
	q->z = q->z / quat_len;
}