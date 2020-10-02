/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tear_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:45:27 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/01 10:52:43 by dtaisha          ###   ########lyon.fr   */
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

// todo когда появятся дополнительные фигуры нужно не забыть их пофришить
void			free_all(t_data *data)
{
	if (data)
	{
		ft_safe_free(data->mlx_ptr);
		ft_safe_free(data->object_ptr->sph_objs);
		ft_safe_free(data->object_ptr->cyln_objs);
//		ft_safe_free(data->object_ptr->cone_objs);
//		ft_safe_free(data->object_ptr->plane_objs);
		ft_safe_free(data->object_ptr->light_srcs);
		ft_safe_free(data->object_ptr);
		ft_safe_free(data);
	}
}
