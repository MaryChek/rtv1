/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:02:25 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/01 10:45:34 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// тут аллоцируются еще нужные структуры и указатель на них хранится в
// основной структуре data / нужно будет их либо разнести либо почистить.
// пока так
//todo когда появятся еще фигуры нужно добавить их сюда

int	allocation(t_data *data)
{
	t_mlx				*mlx;
	t_sph				*sph;
	t_cylindr			*cylindr;
	t_cone				*cone;
	t_plane				*plane;
	t_light				*light;
	t_object			*object;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx)))
	|| !(sph = (t_sph *)malloc(sizeof(t_sph)))
	|| !(cylindr = (t_cylindr *)malloc(sizeof(t_cylindr)))
	|| !(cone = (t_cone *)malloc(sizeof(t_cone)))
	|| !(plane = (t_plane *)malloc(sizeof(t_plane)))
	|| !(light = (t_light *)malloc(sizeof(t_light) * 3))
	|| !(object = (t_object *)malloc(sizeof(t_object))))
	{
		free_error_exit("Malloc error\n", 1, data);
		return (-1);
	}
	data->mlx_ptr = mlx;
	object->sph_objs = sph;
	object->cyln_objs = cylindr;
	object->cone_objs = cone;
	object->plane_objs = plane;
	object->light_srcs = light;
	data->object_ptr = object;
	return (0);
}
