/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:03:46 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/25 20:15:47 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	compute_lighting(t_coord point, t_coord normal, t_light *light_srcs, int num_light_src)
{
	float	light_pow;
	int		i;
	t_coord	vec_l;
	float	nor_dot_l;

	light_pow = 0.0;
	i = -1;
	while (++i < num_light_src)
	{
		if (light_srcs[i].type == AMBIENT)
			light_pow += light_srcs[i].intensity;
		else
		{
			if (light_srcs[i].type == POINT)
				vec_l = vector_coord(light_srcs[i].pos_or_dir, point);
			else
				vec_l = light_srcs[i].pos_or_dir;
			if ((nor_dot_l = dot(normal, vec_l)))
				light_pow += ((light_srcs[i].intensity * nor_dot_l )/
							(vector_len(normal) * vector_len(vec_l)));
		}
	}
	return (light_pow);
}