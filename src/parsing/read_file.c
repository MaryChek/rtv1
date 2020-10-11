/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:54:07 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/11 14:59:02 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
void		validate_fd(int fd, t_data *data)
{
	if (fd < 0)
		free_error_exit("Error: file doesn't exist\n", 1, data);
	if (fd == 0 || read(fd, NULL, 0) == -1)
		free_error_exit("Error: can't read file\n", 1, data);
}

static void		read_line(t_data *data, t_scene *objects, char *line)
{
	char		**arr;

	if (!(arr = ft_strsplit(line, '\t')))
		free_error_exit("Malloc error\n", 1, data);
	if (ft_arrlen(arr) > 0)
	{
		if (!ft_strcmp(arr[0], "sphere"))
			sphere(data, objects, arr);
		else if (!ft_strcmp(arr[0], "cylinder"))
			cylinder(data, objects, arr);
		else if (!ft_strcmp(arr[0], "cone"))
			cone(data, objects, arr);
		else if (!ft_strcmp(arr[0], "plane"))
			plane(data, objects, arr);
		else if (!ft_strcmp(arr[0], "camera"))
			camera(objects, arr);
		else if (!ft_strcmp(arr[0], "light"))
			if (!ft_strcmp(arr[1], "AMBIENT") || !ft_strcmp(arr[1], "POINT") ||
					!ft_strcmp(arr[1], "DIRECTIONAL"))
				light(data, objects, arr);
		ft_safe_free_arr(arr);
	}
}

void			read_setups(t_data *data, char *name)
{
	int			fd = 0;
	char		*line;

	fd = open(name, O_RDONLY);
	validate_fd(fd, data);
	while (get_next_line(fd, &line))
	{
		if(line[0] != '#' && ft_strlen(line) > 10)
			read_line(data, data->p_object, line);
		ft_safe_free(line);
	}
	close(fd);
}