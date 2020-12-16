/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:53:19 by rtacos            #+#    #+#             */
/*   Updated: 2020/12/16 17:44:13 by rtacos           ###   ########.fr       */
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
	objs.cyln_cap_objs = malloc(sizeof(t_cylinder_cap));
	objs.num_cyln_cap = 1;
	objs.cyln_cap_objs[0].head = (t_coord){2,1,4};
	objs.cyln_cap_objs[0].tail = (t_coord){0,-1,4};
	objs.cyln_cap_objs[0].rad = 1;
	objs.cyln_cap_objs[0].color = BLUE;
	objs.cyln_cap_objs[0].specular = -1;
	objs.cyln_cap_objs[0].direction = vctr_normal(vctr_sub(objs.cyln_cap_objs[0].tail, objs.cyln_cap_objs[0].head));
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			if (x == 682 && y == 540)
				x = 682;
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
