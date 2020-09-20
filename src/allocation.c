/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:02:25 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/19 16:39:20 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// тут аллоцируются еще нужные структуры и указатель на них хранится в
// основной структуре data / нужно будет их либо разнести либо почистить.
// пока так
int	allocation(t_data *data)
{
	t_mlx				*mlx;
	t_quadr_equation	*quadr_equation;
	t_viewport			*viewport;
	t_coord				*coord;
	t_vector			*vector;
	t_color				*color;
	t_sph				*sph;
	t_cylindr			*cylindr;
	t_object			*object;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx)))
	|| !(quadr_equation = (t_quadr_equation *)malloc(sizeof(t_quadr_equation)))
	|| !(viewport = (t_viewport *)malloc(sizeof(t_viewport)))
	|| !(coord = (t_coord *)malloc(sizeof(t_coord)))
	|| !(vector = (t_vector *)malloc(sizeof(t_vector)))
	|| !(color = (t_color *)malloc(sizeof(t_color)))
	|| !(sph = (t_sph *)malloc(sizeof(t_sph)))
	|| !(cylindr = (t_cylindr *)malloc(sizeof(t_cylindr)))
	|| !(object = (t_object *)malloc(sizeof(t_object))))
	{
		free_error_exit("Malloc error\n", 1, data);
		return (-1);
	}
	data->mlx_ptr = mlx;
	data->quadr_equation_ptr = quadr_equation;
	data->viewport_ptr = viewport;
	data->coord_ptr = coord;
	data->vector_ptr = vector;
	data->color_ptr = color;
	data->sph_ptr = sph;
	data->cylindr_ptr = cylindr;
	data->object_ptr = object;
	return (0);
}
