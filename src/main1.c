/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:39:55 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/25 20:38:57 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		clos_e(int num)
{
	exit(num);
	return (0);
}

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

void	paint_the_pix(int **img_data, int x, int y, t_color color)
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
	my.num_cylns = 0;

// ----------------------------------------- PARSING(my_obj)

// ------------------------------------------ SPHERE
	t_sph		obj_sph;

	obj_sph.center.x = 0.0f;
	obj_sph.center.y = 0.0f;
	obj_sph.center.z = 50.0f;
	
	obj_sph.color.r = 255;
	obj_sph.color.g = 0;
	obj_sph.color.b = 0;
	
	obj_sph.rad = 10.0f;

	my.num_sphs++;
	
	my.sph_objs = (t_sph *)malloc(sizeof(t_sph) * my.num_sphs);

	my.sph_objs[0] = obj_sph;

// ------------------------------------------ CYLINDER

	t_cylindr	obj_cyln;

	obj_cyln.center.x = 0.0f;
	obj_cyln.center.y = 5.0f;
	obj_cyln.center.z = 47.0f;

	obj_cyln.color.r = 0;
	obj_cyln.color.g = 255;
	obj_cyln.color.b = 0;

	obj_cyln.rotation.x = 1.0f;
	obj_cyln.rotation.y = 1.0f;
	obj_cyln.rotation.z = 0.0f;
	normal_vector(&obj_cyln.rotation);
	

	obj_cyln.rad = 5.0f;

	my.num_cylns++;

	my.cyln_objs = (t_cylindr *)malloc(sizeof(t_cylindr) * my.num_cylns);

	my.cyln_objs[0] = obj_cyln;

// ------------------------------------------ CAMERA

	my.camera.x = 0.0f;
	my.camera.y = 0.0f;
	my.camera.z = 0.0f;
	
// ------------------------------------------ LIGHT SOURCES

	my.num_l_src = 0;
	
	t_light		light_1;

	light_1.type = AMBIENT;
	light_1.intensity = 0.2f;
	
	my.num_l_src++;
	
	t_light		light_2;

	light_2.type = POINT;
	light_2.intensity = 0.3f;
	light_2.pos_or_dir.x = 15.0;
	light_2.pos_or_dir.y = 0.0;
	light_2.pos_or_dir.z = 40.0;

	my.num_l_src++;

	t_light		light_3;

	light_3.type = DIRECTIONAL;
	light_3.intensity = 0.0f;
	light_3.pos_or_dir.x = 0.0;
	light_3.pos_or_dir.y = 0.0;
	light_3.pos_or_dir.z = 50.0;

	my.num_l_src++;

	my.light_srcs = (t_light *)malloc(sizeof(t_light) * my.num_l_src);

	my.light_srcs[0] = light_1;
	my.light_srcs[1] = light_2;
	my.light_srcs[2] = light_3;

// ----------------------------------------- PARSING_END

	t_viewport view_port;

	view_port.wid = WIN_WID;
	view_port.hig = WIN_HIG;
	view_port.distanse = 1080.0f;

	t_obj_info	*near;

	near = NULL;

	int x, y;
	t_raytrace	value;
	
	value = fill_in_values_to_raytracing(0.0, 100000.0, -1, my.camera);
	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			t_coord		vec_ov;

			vec_ov = vector_coord(my.camera, win_to_viewport(x, y, view_port));
			value.begin_vec = vec_ov;
			paint_the_pix(&mlx.img_data, x, y, find_color(my, value, near));
		}
	}
	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_press, 0);
	mlx_hook(mlx.win_ptr, 17, 0, clos_e, 0);
	mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}