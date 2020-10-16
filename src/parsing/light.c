/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:45 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/16 09:50:53 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		intensity(double *intensity, char *arr)
{
	if (arr)
	{
		*intensity = coordinate(arr);
		if (*intensity < 0.0 || *intensity >= 1.0)
			*intensity = DEFAULT_INTENSIVITY;
	}
}

void			light(t_data *data, t_scene *objects, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	len = ft_arrlen(arr);
	if (!ft_strcmp(arr[1], "AMBIENT"))
		objects->light_srcs[i - 1].type = AMBIENT;
	if (!ft_strcmp(arr[1], "POINT"))
		objects->light_srcs[i - 1].type = POINT;
	if (!ft_strcmp(arr[1], "DIRECTIONAL"))
		objects->light_srcs[i - 1].type = DIRECTIONAL;
	if (len > 2)
		intensity(&objects->light_srcs[i - 1].intensity, arr[2]);
	else
		intensity(&objects->light_srcs[i - 1].intensity, NULL);
	if (len > 3)
		position(&objects->light_srcs[i - 1].pos_or_dir, arr[3], data);
	else
		position(&objects->light_srcs[i - 1].pos_or_dir, NULL, data);
	if (len > 4 && ft_strcmp(arr[1], "AMBIENT"))
		color(&objects->light_srcs[i - 1].color, arr[4]);
}