/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:37 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/09 16:42:44 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// t_coord		win_to_viewport(int x, int y, t_viewport vp)
// {
// 	t_coord		point;

// 	point.x = (double)(x - (WIN_WID / 2));
// 	point.y = (double)((WIN_HIG / 2) - y);
// 	// if (point.x == 0.0 && point.y == 0.0) // для дебага
// 	// 	point.z = vp.distanse;
// 	point.z = vp.distanse;
// 	return (point);
// }

t_coord		vctr_reverse(t_coord vector)
{
	if (vector.x != 0.00)
		vector.x = -vector.x;
	if (vector.y != 0.00)
		vector.y = -vector.y;
	if (vector.z != 0.00)
		vector.z = -vector.z;
	return (vector);
}

t_coord		vctr_sub(t_coord begin_point, t_coord end_point)
{
	t_coord rez_point;

	rez_point.x = end_point.x - begin_point.x;
	rez_point.y = end_point.y - begin_point.y;
	rez_point.z = end_point.z - begin_point.z;
	return (rez_point);
}

double		dot(t_coord vec_1, t_coord vec_2)
{
	return ((vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z));
}

t_coord		vctr_sum(t_coord vec_1, t_coord vec_2)
{
	t_coord point;

	point.x = vec_1.x + vec_2.x;
	point.y = vec_1.y + vec_2.y;
	point.z = vec_1.z + vec_2.z;
	return (point);
}

t_coord		vctr_mult(t_coord vector, double mult)
{
	vector.x *= mult;
	vector.y *= mult;
	vector.z *= mult;
	return (vector);
}