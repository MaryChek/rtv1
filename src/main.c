/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:26:06 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/08 22:31:55 by dtaisha          ###   ########lyon.fr   */
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
		int i = 0;
		while (i <= (object->num_sphs - 1))
		{
			printf("sphere [%.2f, %.2f, %.2f] %.2f (%d %d %d)\n" , object->sph_objs[i].center.x, object->sph_objs[i].center.y, object->sph_objs[i].center.z, object->sph_objs[i].rad, object->sph_objs[i].color.r, object->sph_objs[i].color.g, object->sph_objs[i].color.b);
			i++;
		}

		i = 0;
		while (i <= (object->num_cylns - 1))
		{
			printf("cylinder [%.2f, %.2f, %.2f]  %.2f  (%d %d %d) [%.2f, %.2f, %.2f]\n", object->cyln_objs[i].center.x, object->cyln_objs[i].center.y, object->cyln_objs[i].center.z, object->cyln_objs[i].rad, object->cyln_objs[i].color.r, object->cyln_objs[i].color.g, object->cyln_objs[i].color.b, object->cyln_objs[i].rotation.x, object->cyln_objs[i].rotation.y, object->cyln_objs[i].rotation.z);
			i++;
		}
		i = 0;
		while (i <= (object->num_cons - 1))
		{
			printf("cone [%.2f, %.2f, %.2f] (%d %d %d) [%.2f, %.2f, %.2f] %.2f\n", object->cone_objs[i].center.x, object->cone_objs[i].center.y, object->cone_objs[i].center.z, object->cone_objs[i].color.r, object->cone_objs[i].color.g, object->cone_objs[i].color.b, object->cone_objs[i].rotation.x, object->cone_objs[i].rotation.y, object->cone_objs[i].rotation.z, object->cone_objs[i].angle);
			i++;
		}
		i = 0;
		while (i <= (object->num_plans - 1))
		{
			printf("plane [%.2f, %.2f, %.2f] (%d %d %d) [%.2f, %.2f, %.2f]\n", object->plane_objs[i].center.x, object->plane_objs[i].center.y, object->plane_objs[i].center.z, object->plane_objs[i].color.r, object->plane_objs[i].color.g, object->plane_objs[i].color.b, object->plane_objs[i].rotation.x, object->plane_objs[i].rotation.y, object->plane_objs[i].rotation.z);
			i++;
		}
//
		printf("------------------------\n");
		printf("camera [%.2f, %.2f, %.2f] [%.2f, %.2f, %.2f]\n", object->camera.x, object->camera.y, object->camera.z, object->rot_cam.vec.x, object->rot_cam.vec.y, object->rot_cam.vec.z);
		i = 0;
		while (i <= (object->num_l_src - 1))
		{
			printf("light %d %.2f [%.2f, %.2f, %.2f]\n", object->light_srcs[i].type, object->light_srcs[i].intensity, object->light_srcs[i].pos_or_dir.x, object->light_srcs[i].pos_or_dir.y, object->light_srcs[i].pos_or_dir.z);
			i++;
		}

		//		grafic_connection(data, data->mlx_ptr);
		free_all(data);
	}

	else
		return (error_exit(NULL, 3));
	return (0);
}
