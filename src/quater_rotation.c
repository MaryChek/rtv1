/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quater_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:27:09 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/09 16:43:10 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		normal_quat(t_quat *q)
{
	double	quat_len;

	quat_len = sqrt(q->w * q->w
	+ q->vec.x * q->vec.x + q->vec.y * q->vec.y + q->vec.z * q->vec.z);
	q->w /= quat_len;
	q->vec.x /= quat_len;
	q->vec.y /= quat_len;
	q->vec.z /= quat_len;
}

t_quat		creat_axis_of_rot(int x, int y, int z, double alpha)
{
	t_quat	axis;
	double	a;

	a = alpha * PI / 180;
	axis.w = cos(a / 2);
	axis.vec.x = x * sin(a / 2);
	axis.vec.y = y * sin(a / 2);
	axis.vec.z = z * sin(a / 2);
	normal_quat(&axis);
	return (axis);
}

t_quat		mol_quat(t_quat a, t_quat b)
{
	t_quat	res;

	res.w = a.w * b.w -
	(a.vec.x * b.vec.x + a.vec.y * b.vec.y + a.vec.z * b.vec.z);
	res.vec.x = a.w * b.vec.x + b.w * a.vec.x +
							a.vec.y * b.vec.z - b.vec.y * a.vec.z;
	res.vec.y = a.w * b.vec.y + b.w * a.vec.y +
							a.vec.z * b.vec.x - b.vec.z * a.vec.x;
	res.vec.z = a.w * b.vec.z + b.w * a.vec.z +
							a.vec.x * b.vec.y - b.vec.x * a.vec.y;
	return (res);
}

t_coord		vctr_rotation(t_coord vector, t_quat rotor)
{
	t_quat	tmp;

	tmp = mol_quat(rotor, (t_quat){0.0, vector});
	rotor.vec = vctr_reverse(rotor.vec);
	normal_quat(&rotor);
	tmp = mol_quat((t_quat){0.0, vector}, rotor);
	vector.x = tmp.vec.x;
	vector.y = tmp.vec.y;
	vector.z = tmp.vec.z;
	return (vector);
}
