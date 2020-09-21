/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:02:25 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/20 23:52:46 by dtaisha          ###   ########lyon.fr   */
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
	t_object			*object;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx)))
	|| !(sph = (t_sph *)malloc(sizeof(t_sph)))
	|| !(cylindr = (t_cylindr *)malloc(sizeof(t_cylindr)))
	|| !(object = (t_object *)malloc(sizeof(t_object))))
	{
		free_error_exit("Malloc error\n", 1, data);
		return (-1);
	}
	data->mlx_ptr = mlx;
	object->cyln_objs = cylindr;
	object->sph_objs = sph;
	data->object_ptr = object;
	return (0);
}
