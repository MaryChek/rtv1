/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:39:55 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/02 19:40:01 by rtacos           ###   ########.fr       */
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
	my.num_cons = 0;
	my.num_plans = 0;

// ----------------------------------------- PARSING(my_obj)
// ------------------------------------------ CONE

	t_cone		obj_cone;

	obj_cone.center.x = -1.0f;
	obj_cone.center.y = 0.0f;
	obj_cone.center.z = 5.0f;
	
	obj_cone.color.r = 255;
	obj_cone.color.g = 0;
	obj_cone.color.b = 255;

	obj_cone.rotation.x = 1.0f;
	obj_cone.rotation.y = 0.0f;
	obj_cone.rotation.z = 0.0f;
	obj_cone.rotation = normal_vector((t_coord){-1.0, 1.0, 0.0});

	obj_cone.angle = 30;// 0.523599;

	my.num_cons++;

	my.cone_objs = (t_cone *)malloc(sizeof(t_cone) * my.num_cons);

	my.cone_objs[0] = obj_cone;

// ------------------------------------------ PLANE

	// t_plane		obj_plane;

	// obj_plane.center.x = 0.0f;
	// obj_plane.center.y = -1.0f;
	// obj_plane.center.z = 1.0f;
	
	// obj_plane.color.r = 255;
	// obj_plane.color.g = 255;
	// obj_plane.color.b = 0;

	// obj_plane.rotation.x = 1.0f;
	// obj_plane.rotation.y = -1.0f;
	// obj_plane.rotation.z = 0.0f;
	// obj_plane.rotation = normal_vector((t_coord){0.0, -1.0, 0.0});

	// my.num_plans++;

	t_plane		obj_plane2;

	obj_plane2.center.x = 0.0f;
	obj_plane2.center.y = 0.0f;
	obj_plane2.center.z = 6.0f;
	
	obj_plane2.color.r = 255;
	obj_plane2.color.g = 255;
	obj_plane2.color.b = 0;

	obj_plane2.rotation.x = -1.0f;
	obj_plane2.rotation.y = 1.0f;
	obj_plane2.rotation.z = 1.0f;
	obj_plane2.rotation = normal_vector((t_coord){0.0, 0.0, 1.0});

	my.num_plans++;

	my.plane_objs = (t_plane *)malloc(sizeof(t_plane) * my.num_plans);

	// my.plane_objs[0] = obj_plane;
	my.plane_objs[0] = obj_plane2;


// ------------------------------------------ SPHERE
	t_sph		obj_sph;

	obj_sph.center.x = 0.0f;
	obj_sph.center.y = -1.0f;
	obj_sph.center.z = 3.0f;
	
	obj_sph.color.r = 255;
	obj_sph.color.g = 0;
	obj_sph.color.b = 0;
	
	obj_sph.rad = 1.0f;

	my.num_sphs++;

	t_sph		obj_sph2;

	obj_sph2.center.x = 2.0f;
	obj_sph2.center.y = 0.0f;
	obj_sph2.center.z = 4.0f;
	
	obj_sph2.color.r = 0;
	obj_sph2.color.g = 0;
	obj_sph2.color.b = 255;
	
	obj_sph2.rad = 1.0f;

	my.num_sphs++;

	t_sph		obj_sph3;

	obj_sph3.center.x = -2.0f;
	obj_sph3.center.y = 0.0f;
	obj_sph3.center.z = 4.0f;
	
	obj_sph3.color.r = 0;
	obj_sph3.color.g = 255;
	obj_sph3.color.b = 0;
	
	obj_sph3.rad = 1.0f;

	my.num_sphs++;
	
	my.sph_objs = (t_sph *)malloc(sizeof(t_sph) * my.num_sphs);

	my.sph_objs[0] = obj_sph;
	my.sph_objs[1] = obj_sph2;
	my.sph_objs[2] = obj_sph3;

// ------------------------------------------ CYLINDER

	t_cylindr	obj_cyln;

	obj_cyln.center.x = 0.0f;
	obj_cyln.center.y = 0.0f;
	obj_cyln.center.z = 4.1f;

	obj_cyln.color.r = 114;
	obj_cyln.color.g = 255;
	obj_cyln.color.b = 255;

	obj_cyln.rotation.x = 1.0f;
	obj_cyln.rotation.y = 1.0f;
	obj_cyln.rotation.z = 0.0f;
	obj_cyln.rotation = normal_vector((t_coord){1.0, 1.0, 0.0});
	

	obj_cyln.rad = 1.0f;

	my.num_cylns++;

	my.cyln_objs = (t_cylindr *)malloc(sizeof(t_cylindr) * my.num_cylns);

	my.cyln_objs[0] = obj_cyln;

// ------------------------------------------ CAMERA

	my.camera.x = 0.0f;
	my.camera.y = 0.0f;
	my.camera.z = 0.0f;

	my.rot_cam = creat_axis_of_rot(0, 0, 1, 60);
	
// ------------------------------------------ LIGHT SOURCES

	my.num_l_src = 0;
	
	t_light		light_1;

	light_1.type = AMBIENT;
	light_1.intensity = 0.2f;
	
	my.num_l_src++;
	
	t_light		light_2;

	light_2.type = POINT;
	light_2.intensity = 0.0f;
	light_2.pos_or_dir.x = 4.0;
	light_2.pos_or_dir.y = 1.0;
	light_2.pos_or_dir.z = -3.0;

	my.num_l_src++;

	t_light		light_3;

	light_3.type = DIRECTIONAL;
	light_3.intensity = 0.6f;
	light_3.pos_or_dir.x = 0.0;
	light_3.pos_or_dir.y = -1.0;
	light_3.pos_or_dir.z = 0.0;

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

	int x, y;
	t_raytrace	value;
	t_obj_info	*near;
	
	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			value = min_and_max_to_raytracing(0.0f, INFINITY); // ???????????????????????????????????????
			value.begin_vec = normal_vector(vector_coord(my.camera,
							win_to_viewport(x, y, view_port)));
			vector_rotation(&value.begin_vec, my.rot_cam);
			// value = min_and_max_to_raytracing(0.0f, INFINITY); ???????????????????????????????????????
			if ((near = ray_tracing(my, value, my.camera)))
				my.pix_color = light_and_shadow(*near, my, value);
			else
				change_color(&my.pix_color, 0, 0, 0);
			paint_the_pix(&mlx.img_data, x, y, my.pix_color);
		}
	}
	mlx_hook(mlx.win_ptr, 2, 1L << 0, key_press, 0);
	mlx_hook(mlx.win_ptr, 17, 0, clos_e, 0);
	mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}