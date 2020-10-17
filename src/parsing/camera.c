/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:09 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/17 15:25:52 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	camera(t_scene *objects, char **arr)
{
	size_t		len;

	len = ft_arrlen(arr);
	if (len > 1)
		position(&objects->camera.point, arr[1], NULL);
	if (len > 2)
		position(&objects->camera.roter.vec, arr[2], NULL);
	if (len > 3)
		objects->camera.roter.w = coordinate(arr[3]);
	objects->camera.roter = creat_axis_of_rot(objects->camera.roter.vec,
												objects->camera.roter.w);
}