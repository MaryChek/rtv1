/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:26:06 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/17 16:58:58 by rtacos           ###   ########.fr       */
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
		read_setups(data, av[1]); //там будем считывать файл из аргументов (название файла, и указатель на структурку куда вностить настройки)
		grafic_connection(data, data->mlx);
 		t_scene *object;
 		object = data->p_object;


 		// printf("------------------------\n");
 		// int i = 0;
 		// while (i <= (object->num_sphs - 1))
 		// {
 		// 	printf("sphere [%.2f, %.2f, %.2f] %.2f (%d %d %d) %.2f\n" ,
 		// 			object->sph_objs[i].center.x, object->sph_objs[i].center.y, object->sph_objs[i].center.z,
 		// 			object->sph_objs[i].rad,
 		// 			object->sph_objs[i].color.r, object->sph_objs[i].color.g, object->sph_objs[i].color.b,
		// 		   object->sph_objs[i].specular);
 		// 	i++;
 		// }


 		// i = 0;
 		// while (i <= (object->num_cylns - 1))
 		// {
 		// 	printf("cylinder [%.2f, %.2f, %.2f] %.2f (%d %d %d) [%.2f, %.2f, %.2f] %.2f\n",
 		// 			object->cyln_objs[i].center.x, object->cyln_objs[i].center.y, object->cyln_objs[i].center.z,
 		// 			object->cyln_objs[i].rad,
 		// 			object->cyln_objs[i].color.r, object->cyln_objs[i].color.g, object->cyln_objs[i].color.b,
 		// 			object->cyln_objs[i].direction.x, object->cyln_objs[i].direction.y, object->cyln_objs[i].direction.z,
		// 			object->cyln_objs[i].specular);
 		// 	i++;
 		// }

		// i = 0;
		// while (i <= (object->num_cons - 1))
		// {
		// 	printf("cone [%.2f, %.2f, %.2f] (%d %d %d) [%.2f, %.2f, %.2f] %.2f %.2f\n",
		// 			object->cone_objs[i].center.x, object->cone_objs[i].center.y, object->cone_objs[i].center.z,
		// 			object->cone_objs[i].color.r, object->cone_objs[i].color.g, object->cone_objs[i].color.b,
		// 			object->cone_objs[i].direction.x, object->cone_objs[i].direction.y, object->cone_objs[i].direction.z,
		// 			object->cone_objs[i].angle,
		// 			object->cone_objs[i].specular);
		// 	i++;
		// }



		// i = 0;
		// while (i <= (object->num_plans - 1))
		// {
		// 	printf("plane [%.2f, %.2f, %.2f] (%d %d %d) [%.2f, %.2f, %.2f] %.2f\n",
		// 			object->plane_objs[i].center.x, object->plane_objs[i].center.y, object->plane_objs[i].center.z,
		// 			object->plane_objs[i].color.r, object->plane_objs[i].color.g, object->plane_objs[i].color.b,
		// 			object->plane_objs[i].direction.x, object->plane_objs[i].direction.y, object->plane_objs[i].direction.z,
		// 			object->plane_objs[i].specular);
		// 	i++;
		// }
		// printf("------------------------\n");
		// printf("camera [%.2f, %.2f, %.2f] [%.2f, %.2f, %.2f] %.2f\n",
		// 		object->camera.point.x, object->camera.point.y, object->camera.point.z,
		// 		object->camera.roter.vec.x, object->camera.roter.vec.y, object->camera.roter.vec.z,
		// 		object->camera.roter.w);
		// i = 0;
		// while (i <= (object->num_l_src - 1))
		// {
		// printf("light %d %.2f [%.2f, %.2f, %.2f] (%d %d %d)\n",
		// 		object->light_srcs[i].type,
		// 		object->light_srcs[i].intensity,
		// 		object->light_srcs[i].pos_or_dir.x, object->light_srcs[i].pos_or_dir.y, object->light_srcs[i].pos_or_dir.z,
		// 		object->light_srcs[i].color.r, object->light_srcs[i].color.g, object->light_srcs[i].color.b);
		// i++;
		// }
		free_all(data);
	}
	else
		return (error_exit(NULL, 3));
	return (0);
}
