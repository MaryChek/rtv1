/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:02:25 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/08 00:25:08 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void check_cam_and_light(int *figs)
{
	if (figs[0] == 0)
		error_exit("SCENE ERROR: There is no light in configuration file! "
			 "Don't you wanna see the black window, nah??\n", 1);
	if (figs[1] == 0 && figs[2] == 0 && figs[3] == 0 && figs[4] == 0)
		error_exit("SCENE ERROR: There is no figures in configuration file! "
				   "What did you expect, nah??\n", 1);
	if (figs[5] != 1)
		error_exit("SCENE ERROR: In configuration file should be only "
			 "1 camera! not less not more!\n", 1);
}

static int *count_figure(char *name, int fd, char *line, int *figs)
{

	fd = open(name, O_RDONLY);
	validate_fd(fd, NULL);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#' && ft_strlen(line) > 10)
		{
			if (!ft_strncmp(line, "sphere\t", 7))
				figs[1] += 1;
			else if (!ft_strncmp(line, "cylinder\t", 9))
				figs[2] += 1;
			else if (!ft_strncmp(line, "cone\t", 5))
				figs[3] += 1;
			else if (!ft_strncmp(line, "plane\t", 6))
				figs[4] += 1;
			else if (!ft_strncmp(line, "light\t", 6))
				figs[0] += 1;
			else if (!ft_strncmp(line, "camera\t", 7))
				figs[5] += 1;
		}
		ft_safe_free(line);
	}
	close(fd);
	check_cam_and_light(figs);
	return (figs);
}

int allocation(t_data *data, char *param_name)
{
	t_object *object;
	int *num_obj;
	int arr[6];
	ft_izero(arr, 6);

	num_obj = (count_figure(param_name, 0, NULL, arr));
	if (!(data->mlx_ptr = (t_mlx *) malloc(sizeof(t_mlx)))
	|| !(object = (t_object *) malloc(sizeof(t_object)))
	|| !(object->light_srcs = (t_light *) malloc(sizeof(t_light) * ((num_obj[0]))))
	|| !(object->sph_objs = (t_sph *) malloc(sizeof(t_sph) * ((num_obj[1]))))
	|| !(object->cyln_objs = (t_cylindr *) malloc(sizeof(t_cylindr) * ((num_obj[2]))))
	|| !(object->cone_objs = (t_cone *) malloc(sizeof(t_cone) * ((num_obj[3]))))
	|| !(object->plane_objs = (t_plane *) malloc(sizeof(t_plane) * ((num_obj[4])))))
		return (-1);
	data->p_object = object;
	object->num_l_src = num_obj[0];
	object->num_sphs = num_obj[1];
	object->num_cylns = num_obj[2];
	object->num_cons = num_obj[3];
	object->num_plans = num_obj[4];
	return (0);
}
