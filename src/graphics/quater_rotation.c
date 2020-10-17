/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quater_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:27:09 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/17 18:50:57 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		quat_normal(t_quat *q)
{
	double	quat_len;

	quat_len = sqrt(q->w * q->w
	+ q->vec.x * q->vec.x + q->vec.y * q->vec.y + q->vec.z * q->vec.z);
	q->w /= quat_len;
	q->vec.x /= quat_len;
	q->vec.y /= quat_len;
	q->vec.z /= quat_len;
}

t_quat		creat_axis_of_rot(t_coord vector, double alpha)
{
	t_quat	axis;
	double	a;

	a = alpha * M_PI / 180;
	axis.w = cos(a);
	axis.vec.x = vector.x * sin(a);
	axis.vec.y = vector.y * sin(a);
	axis.vec.z = vector.z * sin(a);
	quat_normal(&axis);
	return (axis);
}

t_quat		quat_mol(t_quat a, t_quat b)
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

	tmp = quat_mol(rotor, (t_quat){0.0, vector});
	rotor.vec = vctr_reverse(rotor.vec);
	quat_normal(&rotor);
	tmp = quat_mol((t_quat){0.0, vector}, rotor);
	vector.x = tmp.vec.x;
	vector.y = tmp.vec.y;
	vector.z = tmp.vec.z;
	return (vector);
}
