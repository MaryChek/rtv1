/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:57 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/11 20:09:28 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void			grafic_preset(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIN_WID, WIN_HIG, "RTv1");
	mlx->size_line = WIN_WID;
	mlx->bit_pp = 32;
	mlx->endian = 0;
	mlx->img_ptr = mlx_new_image(mlx, WIN_WID, WIN_HIG);
	mlx->img_data = (int *)mlx_get_data_addr(
			mlx->img_ptr, &mlx->bit_pp, &mlx->size_line, &mlx->endian);
}

void			preset_structures(t_scene *objects)
{
	objects->num_sphs = 0;
	objects->num_cylns = 0;
	objects->num_cons = 0;
	objects->num_plans = 0;
	objects->num_l_src = 0;
}