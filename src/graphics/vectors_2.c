/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:23:18 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/18 20:24:55 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vctr_len(t_coord vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y
									+ vector.z * vector.z));
}

t_coord		vctr_normal(t_coord vector)
{
	double	vec_len;

	vec_len = vctr_len(vector);
	vector.x /= vec_len;
	vector.y /= vec_len;
	vector.z /= vec_len;
	return (vector);
}

t_ray_data	creat_ray(double max_len, t_coord point, t_coord direction)
{
	t_ray_data	ray;

	ray.t_max = max_len;
	ray.point = point;
	ray.direction = direction;
	return (ray);
}
