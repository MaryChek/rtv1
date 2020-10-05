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
static void allocate_figure(t_object *object, t_data *data)
{
	t_sph				*sph;
	t_cylindr			*cylindr;
	t_cone				*cone;
	t_plane				*plane;

	if (!(sph = (t_sph *)malloc(sizeof(t_sph)))
		|| !(cylindr = (t_cylindr *)malloc(sizeof(t_cylindr)))
		|| !(cone = (t_cone *)malloc(sizeof(t_cone)))
		|| !(plane = (t_plane *)malloc(sizeof(t_plane))))
		free_error_exit("Malloc error\n", 1, data);
	object->sph_objs = sph;
	object->cyln_objs = cylindr;
	object->cone_objs = cone;
	object->plane_objs = plane;
}

int	allocation(t_data *data)
{
	t_mlx				*mlx;

	t_light				*light;
	t_object			*object;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx)))
	|| !(light = (t_light *)malloc(sizeof(t_light)))
	|| !(object = (t_object *)malloc(sizeof(t_object))))
	{
		free_error_exit("Malloc error\n", 1, data);
		return (-1);
	}

	data->mlx_ptr = mlx;
	object->light_srcs = light;
	data->object_ptr = object;
	allocate_figure(object, data);
	return (0);
}
