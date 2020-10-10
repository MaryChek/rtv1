/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:09 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/10 21:36:51 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	camera(t_object *objects, char **arr)
{
	size_t		len;

	write(1, "camera\n", 7);
	len = ft_arrlen(arr);
	if (len > 1)
		position(&objects->camera.point, arr[1], NULL);
	if (len > 2)
	{
		position(&objects->camera.roter.vec, arr[2], NULL);
		objects->camera.roter = creat_axis_of_rot(objects->camera.roter.vec,
												objects->camera.roter.w);
	}
//	objects->rot_cam.w = DEFAULT_CAMERA_ANGLE;
}