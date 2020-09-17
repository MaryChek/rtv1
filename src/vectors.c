/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:37 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/17 21:22:38 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		win_to_viewport(int x, int y, t_viewport vp)
{
	t_coord		point;

	point.x = (x - (WIN_WID / 2));
	point.y = (y - (WIN_HIG / 2));
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

t_vector	creat_vector(t_coord first_point, t_coord second_point)
{
	t_vector	vector;
	
	vector.st.x = first_point.x;
	vector.st.y = first_point.y;
	vector.st.z = first_point.z;
	
	vector.end.x = second_point.x;
	vector.end.y = second_point.y;
	vector.end.z = second_point.z;

	vector.distance = vector_dis(vector.end, vector.st);
	return (vector);
}

float		dot(t_coord p1, t_coord p2)
{
	return ((float)(p1.x * p2.x + p1.y * p2.y + p1.z * p2.z));
}