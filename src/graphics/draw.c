/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:19 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/18 20:00:38 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw(int **img_data, t_scene objs)
{
	int			x;
	int			y;
	t_ray_data	ray;
	t_obj_info	near;

	y = -1;
	objs.camera.roter = quat_roter(objs.camera);
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			objs.camera.direct = get_direction(objs.camera, x, y);
			ray = creat_ray(INFINITY, objs.camera.point, objs.camera.direct);
			if ((ray_trace(objs, ray, &near)))
				objs.pix_color = trace_to_light_src(near, objs);
			else
				color_change(&objs.pix_color, (t_color){0, 0, 0});
			put_color_to_img(img_data, x, y, objs.pix_color);
		}
	}
}
