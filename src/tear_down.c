/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tear_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:45:27 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/19 16:55:43 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			clear_image(t_mlx *mlx)
{
	if (mlx->img_data)
		ft_bzero((char *)mlx->img_data,
				(size_t)(WIN_WID * WIN_HIG * (mlx->bit_pp / 8)));
}

void			free_all(t_data *data)
{
	if (data)
	{
		ft_safe_free(data->mlx_ptr);
		ft_safe_free(data->quadr_equation_ptr);
		ft_safe_free(data->coord_ptr);
		ft_safe_free(data->vector_ptr);
		ft_safe_free(data->color_ptr);
		ft_safe_free(data->sph_ptr);
		ft_safe_free(data->cylindr_ptr);
		ft_safe_free(data->object_ptr);
		ft_safe_free(data);
	}
}
