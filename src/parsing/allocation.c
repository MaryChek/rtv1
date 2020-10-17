/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:02:25 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/17 18:51:33 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_obj_null(t_scene *objs)
{
	objs->light_srcs = NULL;
	objs->plane_objs = NULL;
	objs->sph_objs = NULL;
	objs->cone_objs = NULL;
	objs->cyln_objs = NULL;
}

static void		set_default(t_scene *objs)
{
	objs->camera.point.x = DEFAULT_CAMERA;
	objs->camera.point.y = DEFAULT_CAMERA;
	objs->camera.point.z = DEFAULT_CAMERA;
	objs->light_srcs[0].pos_or_dir.x = DEFAULT_LIGHT;
	objs->light_srcs[0].pos_or_dir.y = DEFAULT_LIGHT;
	objs->light_srcs[0].pos_or_dir.z = DEFAULT_LIGHT;
	objs->light_srcs[0].type = AMBIENT;
	objs->light_srcs[0].intensity = DEFAULT_INTENSIVITY;
}

static void		check_cam_and_light(int *figs)
{
	if (figs[0] == 0)
		figs[0] = 1;
	if (figs[1] == 0 && figs[2] == 0 && figs[3] == 0 && figs[4] == 0)
		error_exit("SCENE ERROR: There is no figures in configuration file! "
				   "What did you expect, nah??\n", 1);
	if (figs[5] > 1)
		error_exit("SCENE ERROR: In configuration file should be only "
			 "1 camera! not less not more!\n", 1);
}

static int		*count_figure(char *name, int fd, char *line, int *figs)
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

int				allocation(t_data *data, char *param_name)
{
	t_scene		*objs;
	int			*num_obj;
	int			arr[6];

	ft_izero(arr, 6);
	if (!(objs = (t_scene *) malloc(sizeof(t_scene))))
		return (-1);
	ft_obj_null(objs);
	num_obj = (count_figure(param_name, 0, NULL, arr));
	if (!(data->mlx = (t_mlx *) malloc(sizeof(t_mlx)))
	|| (num_obj[0] && !(objs->light_srcs = (t_light *) malloc(sizeof(t_light) * ((num_obj[0])))))
	|| (num_obj[1] && !(objs->sph_objs = (t_sph *) malloc(sizeof(t_sph) * ((num_obj[1])))))
	|| (num_obj[2] && !(objs->cyln_objs = (t_cylindr *) malloc(sizeof(t_cylindr) * ((num_obj[2])))))
	|| (num_obj[3] && !(objs->cone_objs = (t_cone *) malloc(sizeof(t_cone) * ((num_obj[3])))))
	|| (num_obj[4] && !(objs->plane_objs = (t_plane *) malloc(sizeof(t_plane) * ((num_obj[4]))))))
		return (-1);
	data->p_object = objs;
	objs->num_l_src = num_obj[0];
	objs->num_sphs = num_obj[1];
	objs->num_cylns = num_obj[2];
	objs->num_cons = num_obj[3];
	objs->num_plans = num_obj[4];
	set_default(objs);
	return (0);
}
