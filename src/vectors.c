/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:37 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/25 12:13:56 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		win_to_viewport(int x, int y, t_viewport vp)
{
	t_coord		point;

	point.x = (float)(x - (WIN_WID / 2));
	point.y = (float)(y - (WIN_HIG / 2));
	if (point.x == 0.0 && point.y == 0.0) // для дебага
		point.z = vp.distanse;
	point.z = vp.distanse;
	return (point);
}

t_coord		vector_coord(t_coord begin_point, t_coord end_point)
{
	t_coord rez_point;

	rez_point.x = end_point.x - begin_point.x;
	rez_point.y = end_point.y - begin_point.y;
	rez_point.z = end_point.z - begin_point.z;
	return (rez_point);
}

float		dot(t_coord vec_1, t_coord vec_2)
{
	return ((vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z));
}

t_coord		sum_vectors(t_coord vec_1, t_coord vec_2)
{
	t_coord point;

	point.x = vec_1.x + vec_2.x;
	point.y = vec_1.y + vec_2.y;
	point.z = vec_1.z + vec_2.z;
	return (point);
}

t_coord		vec_scalar_mult(t_coord vector, float mult)
{
	vector.x *= mult;
	vector.y *= mult;
	vector.z *= mult;
	return (vector);
}