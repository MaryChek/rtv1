/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:09 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/19 16:34:25 by rtacos           ###   ########.fr       */
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
		position(&objects->camera.angles, arr[2], NULL);
}
