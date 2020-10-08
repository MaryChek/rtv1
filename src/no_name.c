/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:45:41 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/08 19:20:41 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		get_obj_color(t_object my, int type, int index)
{
	if (type == SPH)
		return (my.sph_objs[index].color);
	else if (type == CYLINDER)
		return (my.cyln_objs[index].color);
	else if (type == CONE)
		return (my.cone_objs[index].color);
	else
		return (my.plane_objs[index].color);
}

int			get_specul_obj(t_object my, int type, int index)
{
	if (type == SPH)
		return (my.sph_objs[index].specular);
	else if (type == CYLINDER)
		return (my.cyln_objs[index].specular);
	else if (type == CONE)
		return (my.cone_objs[index].specular);
	else
		return (my.plane_objs[index].specular);
}

void		fixing_the_near_obj(t_raytrace value, t_obj_info **near, int type, int index)
{
	if ((!(*near) || value.t_near < (*near)->t))
	{
		if (!(*near))
		{
			*near = (t_obj_info *)malloc(sizeof(t_obj_info));
		}
		(*near)->center = value.center;
		(*near)->st_cent = value.st_cent;
		(*near)->t = (value.t_near - 0.0001);
		(*near)->type = type;
		(*near)->index = index;
		(*near)->begin_vec = value.begin_vec;
	}
}

void		min_and_max_to_raytrace(t_raytrace *value, double t_min, double t_max)
{
	value->t_max = t_max;
	value->t_min = t_min;
}