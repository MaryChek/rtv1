/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:02:25 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/07 01:22:49 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// тут аллоцируются еще нужные структуры и указатель на них хранится в
// основной структуре data / нужно будет их либо разнести либо почистить.
// пока так
//todo когда появятся еще фигуры нужно добавить их сюда

static int *count_figure(char *name, int fd, char *line, int *figs)
{

	fd = open(name, O_RDONLY);
	validate_fd(fd, NULL);
	while (get_next_line(fd, &line))
	{
		char **arr;
		arr = ft_strsplit(line, '\t');
		if(line[0] != '#' && ft_strlen(line) > 10)
		{
			if (!ft_strcmp(arr[0], "sphere"))
				figs[1] += 1;
			else if (!ft_strcmp(arr[0], "cylinder"))
				figs[2] += 1;
			else if (!ft_strcmp(arr[0], "cone"))
				figs[3] += 1;
			else if (!ft_strcmp(arr[0], "plane"))
				figs[4] += 1;
			else if (!ft_strcmp(arr[0], "light"))
				figs[0] += 1;
		}
		ft_safe_free_arr(arr);
		ft_safe_free(line);
	}
	close(fd);
	return (figs);
}

static void allocate_figure(t_object *object, t_data *data)
{
	t_sph				**sph;
	t_cylindr			**cylindr;
	t_cone				**cone;
	t_plane				**plane;

	if (!(sph = (t_sph **)malloc(sizeof(t_sph *) * (object->num_sphs) + 1))
		|| !(cylindr = (t_cylindr **)malloc(sizeof(t_cylindr *) * (object->num_cylns)+ 1))
		|| !(cone = (t_cone **)malloc(sizeof(t_cone *) * (object->num_cons) + 1))
		|| !(plane = (t_plane **)malloc(sizeof(t_plane *) * (object->num_plans) + 1)))
		free_error_exit("Malloc error\n", 1, data);
	object->sph_objs = sph;
	object->cyln_objs = cylindr;
	object->cone_objs = cone;
	object->plane_objs = plane;
	object->sph_objs[object->num_sphs] = NULL;
	object->cyln_objs[object->num_cylns] = NULL;
	object->cone_objs[object->num_cons] = NULL;
	object->plane_objs[object->num_plans] = NULL;
	object->light_srcs[object->num_l_src] = NULL;
}

int	allocation(t_data *data, char *param_name)
{
	t_mlx				*mlx;
	t_light				**light;
	t_object			*object;
	int 				*num_obj;
	int arr[] = {0, 0, 0, 0, 0};

	num_obj = (count_figure(param_name, 0, NULL, arr));
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx)))
	|| !(light = (t_light **)malloc(sizeof(t_light *) * (num_obj[0]) + 1))
	|| !(object = (t_object *)malloc(sizeof(t_object))))
	{
		free_error_exit("Malloc error\n", 1, data);
		return (-1);
	}
	data->mlx_ptr = mlx;
	data->p_object = object;
	object->light_srcs = light;
	object->num_l_src = num_obj[0];
	object->num_sphs = num_obj[1];
	object->num_cylns = num_obj[2];
	object->num_cons = num_obj[3];
	object->num_plans = num_obj[4];
	allocate_figure(object, data);
	return (0);
}
