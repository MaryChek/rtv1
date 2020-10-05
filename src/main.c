/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:26:06 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/05 12:29:26 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		param_validation(av[1]); // защита от дурачков на вводимые параметры
		if (!(data = (t_data*)malloc(sizeof(t_data))) ||
				(allocation(data) != 0))
			free_error_exit("Malloc error\n", 1, data);
		preset_structures(data->object_ptr);
		read_setups(data, av[1]); //там будем считывать файл из аргументов (название файла, и указатель на структурку куда вностить настройки)

		t_object *object;
		object = data->object_ptr;
		printf("------------------------\n");
		printf("sphere [%.2f, %.2f, %.2f] %.2f (%d %d %d)\n" , object->sph_objs->center.x, object->sph_objs->center.y, object->sph_objs->center.z, object->sph_objs->rad, object->sph_objs->color.r, object->sph_objs->color.g, object->sph_objs->color.b);
		printf("cylinder [%.2f, %.2f, %.2f]  %.2f  (%d %d %d) [%.2f, %.2f, %.2f]\n", object->cyln_objs->center.x, object->cyln_objs->center.y, object->cyln_objs->center.z, object->cyln_objs->rad, object->cyln_objs->color.r, object->cyln_objs->color.g, object->cyln_objs->color.b, object->cyln_objs->rotation.x, object->cyln_objs->rotation.y, object->cyln_objs->rotation.z);
		printf("cone [%.2f, %.2f, %.2f] (%d %d %d) [%.2f, %.2f, %.2f] %.2f\n", object->cone_objs->center.x, object->cone_objs->center.y, object->cone_objs->center.z, object->cone_objs->color.r, object->cone_objs->color.g, object->cone_objs->color.b, object->cone_objs->rotation.x, object->cone_objs->rotation.y, object->cone_objs->rotation.z, object->cone_objs->angle);
		printf("plane [%.2f, %.2f, %.2f] (%d %d %d) [%.2f, %.2f, %.2f]\n", object->plane_objs->center.x, object->plane_objs->center.y, object->plane_objs->center.z, object->plane_objs->color.r, object->plane_objs->color.g, object->plane_objs->color.b, object->plane_objs->rotation.x, object->plane_objs->rotation.y, object->plane_objs->rotation.z);
		printf("------------------------\n");
		printf("camera [%.2f, %.2f, %.2f] [%.2f, %.2f, %.2f]\n", object->camera.x, object->camera.y, object->camera.z, object->rot_cam.x, object->rot_cam.y, object->rot_cam.z);
		printf("light %d %.2f [%.2f, %.2f, %.2f]\n", object->light_srcs->type, object->light_srcs->intensity, object->light_srcs->pos_or_dir.x, object->light_srcs->pos_or_dir.y, object->light_srcs->pos_or_dir.z);
		printf("light %d %.2f [%.2f, %.2f, %.2f]\n", object->light_srcs->type, object->light_srcs->intensity, object->light_srcs->pos_or_dir.x, object->light_srcs->pos_or_dir.y, object->light_srcs->pos_or_dir.z);
		printf("light %d %.2f [%.2f, %.2f, %.2f]\n", object->light_srcs->type, object->light_srcs->intensity, object->light_srcs->pos_or_dir.x, object->light_srcs->pos_or_dir.y, object->light_srcs->pos_or_dir.z);

		//		grafic_connection(data, data->mlx_ptr);
		free_all(data);
	}
	else
		return (error_exit(NULL, 3));
	return (0);
}
