/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:39:55 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/17 20:53:10 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mlx	init_img()
{
	int		bpp;
	int		size_line;
	int		endian;
	t_mlx	mlx;

	bpp = 32;
	size_line = WIN_WID;
	endian = 0;
	mlx.ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.ptr, WIN_WID, WIN_HIG, "RTv1");
	mlx.img_ptr = mlx_new_image(mlx.ptr, WIN_WID, WIN_HIG);
	mlx.img_data = (int *)mlx_get_data_addr(mlx.img_ptr,
												&bpp, &size_line, &endian);
	return (mlx);
}

void	put_color_into_pix(int **img_data, int x, int y, t_color color)
{
	(*img_data)[((y * WIN_WID) + x)] = color.r << 16;
	(*img_data)[((y * WIN_WID) + x)] += color.g << 8;
	(*img_data)[((y * WIN_WID) + x)] += color.b;
}

int		main()
{
	t_mlx	mlx;

	mlx = init_img();

	t_object	my;

	my.num_sphs = 0;

// ----------------------------------------- PARSING(my_obj)

	t_sph		obj_sph;
	
	obj_sph.center.x = 0;
	obj_sph.center.y = 10;
	obj_sph.center.z = 2000;
	obj_sph.color.r = 255;
	obj_sph.color.g = 0;
	obj_sph.color.b = 0;
	obj_sph.rad = 200;

	my.num_sphs++;
	
	my.sph_objs = (t_sph *)malloc(sizeof(t_sph) * my.num_sphs);

	my.sph_objs[0] = obj_sph;

	my.camera.x = 0;
	my.camera.y = 0;
	my.camera.z = 0;
	
// ----------------------------------------- PARSING_END

	t_viewport view_port;

	view_port.wid = WIN_WID;
	view_port.hig = WIN_HIG;
	view_port.distanse = 1;

	int x, y;
	t_color	pix_color;

	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			t_vector	_vo_;
			float		t;

			change_color(&pix_color, 255, 255, 255);
			_vo_ = creat_vector(my.camera, win_to_viewport(x, y, view_port));
			if (find_tangent_to_object(_vo_, my, &t))
				change_color(&pix_color, 255, 0, 0);
			put_color_into_pix(&mlx.img_data, x, y, pix_color);
		}
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}