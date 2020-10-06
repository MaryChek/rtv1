/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tear_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:45:27 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/07 02:04:29 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// todo в какой момент использовать clear image и использовать ли вообще
void			clear_image(t_mlx *mlx)
{
	if (mlx->data_ptr)
		ft_bzero((char *)mlx->data_ptr,
				(size_t)(WIN_WID * WIN_HIG * (mlx->bit_pp / 8)));
}

static void	free_struct_arr(void **arr, int n)
{
	n--;
	if (arr)
	{
		while (n >= 0)
		{
			if (arr[n])
				free(arr[n--]);
		}
		free(arr);
	}
}
void			free_all(t_data *data)
{
	if (data)
	{
		ft_safe_free(data->mlx_ptr);
		free_struct_arr((void **) data->p_object->sph_objs, data->p_object->num_sphs);
		free_struct_arr((void **) data->p_object->cyln_objs, data->p_object->num_cylns);
		free_struct_arr((void **) data->p_object->cone_objs, data->p_object->num_cons);
		free_struct_arr((void **) data->p_object->plane_objs, data->p_object->num_plans);
		free_struct_arr((void **) data->p_object->light_srcs, data->p_object->num_l_src);
		ft_safe_free(data->p_object);
		ft_safe_free(data);
	}
}
