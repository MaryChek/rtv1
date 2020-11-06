/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:03:46 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/19 17:12:39 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				shadow_overlay(t_light *src, t_coord *l_vctr, t_obj_info near,
														t_scene objs)
{
	double			vct_size;
	t_ray_data		ray;

	if (src->type == POINT)
		*l_vctr = vctr_sub(near.point, src->pos_or_dir);
	else
		*l_vctr = vctr_normal(src->pos_or_dir);
	vct_size = src->type == POINT ? vctr_len(*l_vctr) : INFINITY;
	ray = creat_ray(vct_size, near.point, vctr_normal(*l_vctr));
	if (ray_trace(objs, ray, &near))
		return (1);
	return (0);
}

t_color			diffuse(t_light *src, t_coord l_vctr, t_coord normal,
														t_color color)
{
	double		light_pow;
	double		nor_dot_l;
	double		i;

	light_pow = 0.0;
	i = 0.0;
	if ((nor_dot_l = dot(normal, l_vctr)) > 0.0)
		light_pow = src->intensity * nor_dot_l / (vctr_len(l_vctr));
	color = color_scal(color, light_pow);
	return (color);
}

t_color			specular(t_light *src, t_coord l_vctr, t_obj_info near,
														t_coord begin_vec)
{
	double		light_pow;
	t_coord		reflected;
	t_coord		rev_begin;
	double		r_dot_v;
	t_color		color;

	light_pow = 0.0;
	if (near.specular != -1.0)
	{
		rev_begin = vctr_reverse(begin_vec);
		near.normal = vctr_mult(near.normal, 2 * dot(near.normal, l_vctr));
		reflected = vctr_sub(l_vctr, near.normal);
		r_dot_v = dot(reflected, rev_begin);
		if (r_dot_v > 0)
			light_pow = pow(r_dot_v / (vctr_len(reflected) *
										vctr_len(rev_begin)), near.specular);
	}
	color = color_scal(src->color, src->intensity * light_pow);
	return (color);
}

t_color			compute_lighting(t_light *src, int num_light_src,
										t_obj_info near, t_scene objs)
{
	int			i;
	t_color		color_pix;
	t_coord		l_vctr;

	i = -1;
	color_pix = (t_color){0, 0, 0};
	while (++i < num_light_src)
	{
		if (src[i].type == AMBIENT)
			color_pix = colors_sum(color_pix,
								color_scal(near.color_obj, src[i].intensity));
		else
		{
			if (!shadow_overlay(&(src[i]), &l_vctr, near, objs))
			{
				color_pix = colors_sum(color_pix, diffuse(&src[i],
							l_vctr, near.normal, near.color_obj));
				color_pix = colors_sum(color_pix, specular(&src[i],
							l_vctr, near, objs.camera.direct));
			}
		}
	}
	return (color_pix);
}

t_color			trace_to_light_src(t_obj_info near, t_scene objs)
{
	t_coord		d_t;

	d_t = vctr_mult(objs.camera.direct, near.t);
	near.point = vctr_sum(objs.camera.point, d_t);
	near.normal = normal_to_obj(objs, near);
	near.color_obj = get_obj_color(objs, near.type, near.index);
	near.specular = get_specul_obj(objs, near.type, near.index);
	return (compute_lighting(objs.light_srcs, objs.num_l_src, near, objs));
}
