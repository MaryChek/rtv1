/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:19 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/14 13:44:57 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 				draw(int **img_data, t_scene objs)
{
	int			x;
	int			y;
	t_ray_data	ray;
	t_obj_info	*near;
	double		dist;

	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			objs.camera.direct = get_direction(objs.camera, x, y);
			ray = creat_ray(INFINITY, objs.camera.point, objs.camera.direct);
			if ((near = ray_trace(objs, ray)))
			{
				objs.pix_color = trace_to_light_src(*near, objs);
				free(near);
			}
			else
				change_color(&objs.pix_color, (t_color){0, 0, 0});
			put_color_to_img(img_data, x, y, objs.pix_color);
		}
	}
}
