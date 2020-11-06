/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_connection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:30 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/11 20:11:59 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			grafic_connection(t_data *data, t_mlx *mlx)
{
	grafic_preset(mlx);
	draw(&(mlx->img_data), *(data->p_object));
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win, 2, 0, buttons_press, data);
	mlx_hook(mlx->win, 17, (1L << 17), close_window, data);
	mlx_loop(mlx->ptr);
}
