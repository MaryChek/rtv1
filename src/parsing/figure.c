/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:25 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/19 15:56:04 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			sphere(t_data *data, t_scene *objects, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	len = ft_arrlen(arr);
	if (len > 1)
		position(&objects->sph_objs[i - 1].center, arr[1], data);
	else
		position(&objects->sph_objs[i - 1].center, NULL, data);
	objects->sph_objs[i - 1].rad = (len > 2) ? coordinate(arr[2]) : DEFAULT_R;
	if (len > 3)
		color(&objects->sph_objs[i - 1].color, arr[3]);
	else
		color(&objects->sph_objs[i - 1].color, NULL);
	objects->sph_objs[i - 1].specular = (len > 4) ?
					coordinate(arr[4]) : DEFAULT_SPECULAR;
}

void			cylinder(t_data *data, t_scene *objects, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	len = ft_arrlen(arr);
	if (len > 1)
		position(&objects->cyln_objs[i - 1].center, arr[1], data);
	else
		position(&objects->cyln_objs[i - 1].center, NULL, data);
	objects->cyln_objs[i - 1].rad = (len > 2) ? coordinate(arr[2]) : DEFAULT_R;
	if (len > 3)
		color(&objects->cyln_objs[i - 1].color, arr[3]);
	else
		color(&objects->cyln_objs[i - 1].color, NULL);
	if (len > 4)
		position(&objects->cyln_objs[i - 1].direction, arr[4], data);
	else
		position(&objects->cyln_objs[i - 1].direction, NULL, data);
	objects->cyln_objs[i - 1].specular = (len > 5) ?
					coordinate(arr[5]) : DEFAULT_SPECULAR;
	objects->cyln_objs[i - 1].direction =
							vctr_normal(objects->cyln_objs[i - 1].direction);
}

void			cone(t_data *data, t_scene *objects, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	len = ft_arrlen(arr);
	if (len > 1)
		position(&objects->cone_objs[i - 1].center, arr[1], data);
	else
		position(&objects->cone_objs[i - 1].center, NULL, data);
	if (len > 2)
		color(&objects->cone_objs[i - 1].color, arr[2]);
	else
		color(&objects->cone_objs[i - 1].color, NULL);
	if (len > 3)
		position(&objects->cone_objs[i - 1].direction, arr[3], data);
	else
		position(&objects->cone_objs[i - 1].direction, NULL, data);
	objects->cone_objs[i - 1].angle = (len > 4) ?
									coordinate(arr[4]) : DEFAULT_A;
	objects->cone_objs[i - 1].specular = (len > 5) ?
									coordinate(arr[5]) : DEFAULT_SPECULAR;
	objects->cone_objs[i - 1].direction =
							vctr_normal(objects->cone_objs[i - 1].direction);
}

void			plane(t_data *data, t_scene *objects, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	len = ft_arrlen(arr);
	if (len > 1)
		position(&objects->plane_objs[i - 1].center, arr[1], data);
	else
		position(&objects->plane_objs[i - 1].center, NULL, data);
	if (len > 2)
		color(&objects->plane_objs[i - 1].color, arr[2]);
	else
		color(&objects->plane_objs[i - 1].color, NULL);
	if (len > 3)
		position(&objects->plane_objs[i - 1].direction, arr[3], data);
	else
		position(&objects->plane_objs[i - 1].direction, NULL, data);
	objects->plane_objs[i - 1].specular = (len > 4) ?
								coordinate(arr[4]) : DEFAULT_SPECULAR;
	objects->plane_objs[i - 1].direction =
							vctr_normal(objects->plane_objs[i - 1].direction);
}
