/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:26:06 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/07 00:24:04 by dtaisha          ###   ########lyon.fr   */
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
				(allocation(data, av[1]) != 0))
			free_error_exit("Malloc error\n", 1, data);
//		preset_structures(data->p_object);
		read_setups(data, av[1]); //там будем считывать файл из аргументов (название файла, и указатель на структурку куда вностить настройки)

		t_object *object;
		object = data->p_object;
		printf("------------------------\n");
		printf("sphere [%.2f, %.2f, %.2f] %.2f (%d %d %d)\n" , object->sph_objs[0]->center.x, object->sph_objs[0]->center.y, object->sph_objs[0]->center.z, object->sph_objs[0]->rad, object->sph_objs[0]->color.r, object->sph_objs[0]->color.g, object->sph_objs[0]->color.b);
		printf("cylinder [%.2f, %.2f, %.2f]  %.2f  (%d %d %d) [%.2f, %.2f, %.2f]\n", object->cyln_objs[0]->center.x, object->cyln_objs[0]->center.y, object->cyln_objs[0]->center.z, object->cyln_objs[0]->rad, object->cyln_objs[0]->color.r, object->cyln_objs[0]->color.g, object->cyln_objs[0]->color.b, object->cyln_objs[0]->rotation.x, object->cyln_objs[0]->rotation.y, object->cyln_objs[0]->rotation.z);
		printf("cone [%.2f, %.2f, %.2f] (%d %d %d) [%.2f, %.2f, %.2f] %.2f\n", object->cone_objs[0]->center.x, object->cone_objs[0]->center.y, object->cone_objs[0]->center.z, object->cone_objs[0]->color.r, object->cone_objs[0]->color.g, object->cone_objs[0]->color.b, object->cone_objs[0]->rotation.x, object->cone_objs[0]->rotation.y, object->cone_objs[0]->rotation.z, object->cone_objs[0]->angle);
		printf("plane [%.2f, %.2f, %.2f] (%d %d %d) [%.2f, %.2f, %.2f]\n", object->plane_objs[0]->center.x, object->plane_objs[0]->center.y, object->plane_objs[0]->center.z, object->plane_objs[0]->color.r, object->plane_objs[0]->color.g, object->plane_objs[0]->color.b, object->plane_objs[0]->rotation.x, object->plane_objs[0]->rotation.y, object->plane_objs[0]->rotation.z);
		printf("------------------------\n");
		printf("camera [%.2f, %.2f, %.2f] [%.2f, %.2f, %.2f]\n", object->camera.x, object->camera.y, object->camera.z, object->rot_cam.x, object->rot_cam.y, object->rot_cam.z);
		printf("light %d %.2f [%.2f, %.2f, %.2f]\n", object->light_srcs[0]->type, object->light_srcs[0]->intensity, object->light_srcs[0]->pos_or_dir.x, object->light_srcs[0]->pos_or_dir.y, object->light_srcs[0]->pos_or_dir.z);
		printf("light %d %.2f [%.2f, %.2f, %.2f]\n", object->light_srcs[1]->type, object->light_srcs[1]->intensity, object->light_srcs[1]->pos_or_dir.x, object->light_srcs[1]->pos_or_dir.y, object->light_srcs[1]->pos_or_dir.z);
		printf("light %d %.2f [%.2f, %.2f, %.2f]\n", object->light_srcs[2]->type, object->light_srcs[2]->intensity, object->light_srcs[2]->pos_or_dir.x, object->light_srcs[2]->pos_or_dir.y, object->light_srcs[2]->pos_or_dir.z);

		//		grafic_connection(data, data->mlx_ptr);
		free_all(data);
	}
	else
		return (error_exit(NULL, 3));
	return (0);
}
