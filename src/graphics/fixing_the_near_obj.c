/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixing_the_near_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:45:41 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/19 12:58:59 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			fixing_the_near_obj(t_ray_data value, t_obj_info *near,
												int type, int index)
{
	if ((near->t == -1 || value.t_near < near->t))
	{
		near->center = value.cent_obj;
		near->st_cent = value.st_cent;
		near->t = (value.t_near - 0.0001);
		near->type = type;
		near->index = index;
	}
	return (1);
}
