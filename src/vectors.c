/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:37 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/21 23:47:46 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		win_to_viewport(int x, int y, t_viewport vp)
{
	t_coord		point;

	point.x = (x - (WIN_WID / 2));
	point.y = (y - (WIN_HIG / 2));
	if (x == (WIN_WID / 2) && y == 0)
		point.z = vp.distanse;
	point.z = vp.distanse;
	return (point);
}

t_coord		vector_dis(t_coord p1, t_coord p2)
{
	t_coord rez_point;

	rez_point.x = p1.x - p2.x;
	rez_point.y = p1.y - p2.y;
	rez_point.z = p1.z - p2.z;
	return (rez_point);
}

t_vector	create_vector(t_coord first_point, t_coord second_point)
{
	t_vector	vector;

	vector.point.x = second_point.x;
	vector.point.y = second_point.y;
	vector.point.z = second_point.z;

	vector.distance = vector_dis(first_point, second_point);
	return (vector);
}

float		dot(t_coord p1, t_coord p2)
{
	return ((float)(p1.x * p2.x + p1.y * p2.y + p1.z * p2.z));
}