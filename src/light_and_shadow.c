/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:03:46 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/09 18:46:06 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	creat_vec_point_light(t_object my, t_coord point, int ind,
															t_coord *light_vct)
{
	if (my.light_srcs[ind].type == POINT)
	{
		*light_vct = vctr_sub(point, my.light_srcs[ind].pos_or_dir);
		return(vctr_len(*light_vct));
	}
	*light_vct = vctr_normal(my.light_srcs[ind].pos_or_dir);
	return (INFINITY);
}

double			patch_of_reflected_light(double specular, t_coord normal,
										t_coord light_vct, t_coord begin_vec)
{
	t_coord		reflected;
	t_coord		rev_begin;
	double		r_dot_v;
	double		i;

	i = 0.0;
	rev_begin = vctr_reverse(begin_vec);
	reflected = vctr_sub(light_vct, vctr_mult(normal, 2 * dot(normal, light_vct)));
	r_dot_v = dot(reflected, rev_begin);
	if (r_dot_v > 0)
		i = pow(r_dot_v / (vctr_len(reflected) * vctr_len(rev_begin)), specular);
	return (i);
}

double			shadow_overlay(t_ray_data ray, t_coord light_vct, t_object my, t_coord normal)
{
	t_obj_info	*near;
	double		nor_dot_l;
	double		i;
	
	i = 0.;
	if (!(near = ray_trace(my, ray)))
	{
		if ((nor_dot_l = dot(normal, light_vct)) > 0.0)
			i = nor_dot_l / (vctr_len(light_vct));
	}
	else
		free(near);
	return (i);
}

double			compute_lighting(t_coord point, t_coord normal, t_object my,
																double specular)
{
	t_coord		light_vct;
	double		light_pow;
	int			i;
	t_ray_data	ray;
	double		vct_size;

	light_pow = 0.0;
	i = -1;
	while (++i < my.num_l_src)
	{
		if (my.light_srcs[i].type == AMBIENT)
			light_pow += my.light_srcs[i].intensity;
		else
		{
			vct_size = creat_vec_point_light(my, point, i, &light_vct);
			ray = creat_ray(vct_size, point, vctr_normal(light_vct));
			light_pow += my.light_srcs[i].intensity * shadow_overlay(ray,
													light_vct, my, normal);
			if (specular != -1.0)
				light_pow += my.light_srcs[i].intensity *
				patch_of_reflected_light(specular, normal,
				light_vct, my.camera.direct);
		}
	}
	return (light_pow);
}

t_color			trace_to_light_src(t_obj_info near, t_object my)
{
	t_coord		normal;
	t_color		color;
	double		light_pow;
	t_coord		d_t;

	d_t = vctr_mult(my.camera.direct, near.t);
	near.point = vctr_sum(my.camera.point, d_t);
	normal = normal_to_obj(my, near);
	color = get_obj_color(my, near.type, near.index);
	light_pow = compute_lighting(near.point, normal, my,
				get_specul_obj(my, near.type, near.index));
	return (brightness_change(color, light_pow));
}
