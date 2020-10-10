/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:19 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/10 21:47:10 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 				draw(t_data *data, t_mlx *mlx, t_object objs)
{
	t_object	my;

	my.num_sphs = 0;
	my.num_cylns = 0;
	my.num_cons = 0;
	my.num_plans = 0;

// ----------------------------------------- PARSING(my_obj)
// ------------------------------------------ CONE

	t_cone		obj_cone;

	obj_cone.center.x = 0.0;
	obj_cone.center.y = 0.0;
	obj_cone.center.z = 50.0;
	
	obj_cone.color.r = 255;
	obj_cone.color.g = 0;
	obj_cone.color.b = 255;

	obj_cone.direction.x = 1.0;
	obj_cone.direction.y = 0.0;
	obj_cone.direction.z = 0.0;
	obj_cone.direction = vctr_normal((t_coord){-1.0, 0.0, 0.0});

	obj_cone.angle = 30.0;// 0.523599;

	obj_cone.specular = 10.0;

	my.num_cons++;

	my.cone_objs = (t_cone *)malloc(sizeof(t_cone) * my.num_cons);

	my.cone_objs[0] = obj_cone;

// ------------------------------------------ PLANE

	// t_plane		obj_plane;

	// obj_plane.center.x = 0.0;
	// obj_plane.center.y = -1.0;
	// obj_plane.center.z = 1.0;
	
	// obj_plane.color.r = 255;
	// obj_plane.color.g = 255;
	// obj_plane.color.b = 0;

	// obj_plane.direction.x = 1.0;
	// obj_plane.direction.y = -1.0;
	// obj_plane.direction.z = 0.0;
	// obj_plane.direction = vctr_normal((t_coord){0.0, -1.0, 0.0});

	// my.num_plans++;

	t_plane		obj_plane2;

	obj_plane2.center.x = 0.0;
	obj_plane2.center.y = 0.0;
	obj_plane2.center.z = 100.0;
	
	obj_plane2.color.r = 255;
	obj_plane2.color.g = 255;
	obj_plane2.color.b = 0;
	obj_plane2.specular = -1.0;

	// obj_plane2.direction.x = -1.0;
	// obj_plane2.direction.y = 1.0;
	// obj_plane2.direction.z = 1.0;
	obj_plane2.direction = vctr_normal((t_coord){1.0, 1.0, 1.0});

	my.num_plans++;

	my.plane_objs = (t_plane *)malloc(sizeof(t_plane) * my.num_plans);

	// my.plane_objs[0] = obj_plane;
	my.plane_objs[0] = obj_plane2;


// ------------------------------------------ SPHERE
	t_sph		obj_sph;

	obj_sph.center.x = 0.0;
	obj_sph.center.y = 0.0;
	obj_sph.center.z = 50.0;
	
	obj_sph.color.r = 255;
	obj_sph.color.g = 0;
	obj_sph.color.b = 0;
	
	obj_sph.rad = 20.0;

	my.num_sphs++;

	t_sph		obj_sph2;

	obj_sph2.center.x = 2.0;
	obj_sph2.center.y = 0.0;
	obj_sph2.center.z = 4.0;
	
	obj_sph2.color.r = 0;
	obj_sph2.color.g = 0;
	obj_sph2.color.b = 255;
	
	obj_sph2.rad = 1.0;

	// my.num_sphs++;

	t_sph		obj_sph3;

	obj_sph3.center.x = -2.0;
	obj_sph3.center.y = 0.0;
	obj_sph3.center.z = 4.0;
	
	obj_sph3.color.r = 0;
	obj_sph3.color.g = 255;
	obj_sph3.color.b = 0;
	
	obj_sph3.rad = 1.0;
	obj_sph.specular = 10.0;

	// my.num_sphs++;
	
	my.sph_objs = (t_sph *)malloc(sizeof(t_sph) * my.num_sphs);

	my.sph_objs[0] = obj_sph;
	// my.sph_objs[1] = obj_sph2;
	// my.sph_objs[2] = obj_sph3;

// ------------------------------------------ CYLINDER

	t_cylindr	obj_cyln;

	obj_cyln.center.x = 0.0;
	obj_cyln.center.y = 0.0;
	obj_cyln.center.z = 90.1;

	obj_cyln.color.r = 114;
	obj_cyln.color.g = 255;
	obj_cyln.color.b = 255;

	obj_cyln.direction.x = 1.0;
	obj_cyln.direction.y = 1.0;
	obj_cyln.direction.z = 0.0;
	obj_cyln.direction = vctr_normal((t_coord){1.0, 1.0, 0.0});
	obj_cyln.specular = 10;
	

	obj_cyln.rad = 50.0;

	my.num_cylns++;

	my.cyln_objs = (t_cylindr *)malloc(sizeof(t_cylindr) * my.num_cylns);

	my.cyln_objs[0] = obj_cyln;

// ------------------------------------------ CAMERA

	t_vector		camera;
	
	camera.point.x = 0.0;
	camera.point.y = 0.0;
	camera.point.z = -100.0;

	camera.roter = creat_axis_of_rot((t_coord){0.0, 0.0, 0.0}, 1.0);

	my.camera = camera;
	
// ------------------------------------------ LIGHT SOURCES

	my.num_l_src = 0;
	
	t_light		light_1;

	light_1.type = AMBIENT;
	light_1.intensity = 0.1;
	
	my.num_l_src++;
	
	t_light		light_2;

	light_2.type = POINT;
	light_2.intensity = 0.4;
	light_2.pos_or_dir.x = 0.0;
	light_2.pos_or_dir.y = -10.0;
	light_2.pos_or_dir.z = 0.0;

	my.num_l_src++;

	t_light		light_3;
///////////////////////////////////// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	light_3.type = DIRECTIONAL;
	light_3.intensity = 0.3;
	light_3.pos_or_dir.x = 0.0;
	light_3.pos_or_dir.y = 0.5;
	light_3.pos_or_dir.z = -0.8;

	my.num_l_src++;

	my.light_srcs = (t_light *)malloc(sizeof(t_light) * my.num_l_src);

	my.light_srcs[0] = light_1;
	my.light_srcs[1] = light_2;
	my.light_srcs[2] = light_3;
	int			x;
	int			y;
	t_ray_data	ray;
	t_obj_info	*near;
	double		dist;

	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			my.camera.direct = get_direction(my.camera, x, y);
			ray = creat_ray(INFINITY, my.camera.point, my.camera.direct);
			if ((near = ray_trace(my, ray)))
			{
				my.pix_color = trace_to_light_src(*near, my);
				free(near);
			}
			else
				change_color(&my.pix_color, 0, 0, 0);
			put_color_to_img(&mlx->data_ptr, x, y, my.pix_color);
		}
	}
}
