/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:03:46 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/15 22:14:09 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "rtv1.h"

// static double	creat_vec_point_light(t_scene objs, t_coord point, int ind,
// 														t_coord *light_vct)
// {
// 	if (objs.light_srcs[ind].type == POINT)
// 	{
// 		*light_vct = vctr_sub(point, objs.light_srcs[ind].pos_or_dir);
// 		return(vctr_len(*light_vct));
// 	}
// 	*light_vct = vctr_normal(objs.light_srcs[ind].pos_or_dir);
// 	return (INFINITY);
// }

// static double	patch_of_reflected_light(double specular, t_coord normal,
// 										t_coord light_vct, t_coord begin_vec)
// {
// 	t_coord		reflected;
// 	t_coord		rev_begin;
// 	double		r_dot_v;
// 	double		i;

// 	i = 0.0;
// 	rev_begin = vctr_reverse(begin_vec);
// 	normal = vctr_mult(normal, 2 * dot(normal, light_vct));
// 	reflected = vctr_sub(light_vct, normal);
// 	r_dot_v = dot(reflected, rev_begin);
// 	if (r_dot_v > 0)
// 		i = pow(r_dot_v / (vctr_len(reflected) * vctr_len(rev_begin)),
// 											specular);
// 	return (i);
// }

// static double	shadow_overlay(t_ray_data ray, t_coord light_vct,
// 										t_scene objs, t_coord normal)
// {
// 	t_obj_info	near;
// 	double		nor_dot_l;
// 	double		i;
	
// 	i = 0.;
// 	if (!ray_trace(objs, ray, &near))
// 	{
// 		if ((nor_dot_l = dot(normal, light_vct)) > 0.0)
// 			i = nor_dot_l / (vctr_len(light_vct));
// 	}
// 	return (i);
// }

// double			compute_lighting(t_coord point, t_coord normal, t_scene objs,
// 														double specular)
// {
// 	t_coord		light_vct;
// 	double		light_pow;
// 	int			i;
// 	t_ray_data	ray;
// 	double		vct_size;

// 	light_pow = 0.0;
// 	i = -1;
// 	while (++i < objs.num_l_src)
// 	{
// 		if (objs.light_srcs[i].type == AMBIENT)
// 			light_pow += objs.light_srcs[i].intensity;
// 		else
// 		{
// 			vct_size = creat_vec_point_light(objs, point, i, &light_vct);
// 			ray = creat_ray(vct_size, point, vctr_normal(light_vct));
// 			light_pow += objs.light_srcs[i].intensity * shadow_overlay(ray,
// 													light_vct, objs, normal);
// 			if (specular != -1.0)
// 				light_pow += objs.light_srcs[i].intensity *
// 				patch_of_reflected_light(specular, normal,
// 				light_vct, objs.camera.direct);
// 		}
// 	}
// 	return (light_pow);
// }

// t_color		trace_to_light_src(t_obj_info near, t_scene objs)
// {
// 	t_coord		normal;
// 	t_color		color;
// 	double		light_pow;
// 	t_coord		d_t;

// 	d_t = vctr_mult(objs.camera.direct, near.t);
// 	near.point = vctr_sum(objs.camera.point, d_t);
// 	normal = normal_to_obj(objs, near);
// 	color = get_obj_color(objs, near.type, near.index);
// 	light_pow = compute_lighting(near.point, normal, objs,
// 				get_specul_obj(objs, near.type, near.index));
// 	return (color_scal(color, light_pow));
// }

#include "rtv1.h"

int			shadow_overlay(t_light *src, t_coord *l_vctr, t_obj_info near, t_scene objs)
{
	double		vct_size;
	t_ray_data 	ray;

	
	if (src->type == POINT)
		*l_vctr = vctr_sub(near.point, src->pos_or_dir);
	else
		*l_vctr = vctr_normal((src->pos_or_dir));
	vct_size = src->type == POINT ? vctr_len(*l_vctr) : INFINITY;
	ray = creat_ray(vct_size, near.point, vctr_normal(*l_vctr));
	if (ray_trace(objs, ray, &near))
		return (1);
	return (0);
}

t_color			diffuse(t_light *src, t_coord l_vctr, t_coord normal, t_color color)
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

t_color			specular(t_light *src, t_coord l_vctr, t_obj_info near, t_coord begin_vec)
{
	double		light_pow;
	t_coord		reflected;
	t_coord		rev_begin;
	double		r_dot_v;

	light_pow = 0.0;
	if (near.specular != -1.0)
	{
		
		rev_begin = vctr_reverse(begin_vec);
		near.normal = vctr_mult(near.normal, 2 * dot(near.normal, l_vctr));
		reflected = vctr_sub(l_vctr, near.normal);
		r_dot_v = dot(reflected, rev_begin);
		if (r_dot_v > 0)
		light_pow = pow(r_dot_v / (vctr_len(reflected) * vctr_len(rev_begin)),
											near.specular);
	}
	src->color = color_scal(src->color, src->intensity * light_pow);
	return (src->color);
}

t_color			compute_lighting(t_light *src, int num_light_src, t_obj_info near, t_scene objs)
{
	int			i;
	double		brightness_obj_col;
	t_color		color_pix;
	t_color		ambiant;
	t_coord		l_vctr;
	double light_pow;

	i = -1;
	color_pix = (t_color){0, 0, 0};
	ambiant = (t_color){0, 0, 0};
	while (++i < num_light_src)
	{
		if (src[i].type == AMBIENT)
			color_pix = color_scal(near.color_obj, src[i].intensity);
		else
		{
			if (!shadow_overlay(&(src[i]), &l_vctr, near, objs))
			{
				color_pix = colors_sum(color_pix, diffuse(&src[i], l_vctr, near.normal, near.color_obj));
				color_pix = colors_sum(color_pix, specular(&src[i], l_vctr, near, objs.camera.direct));
			}
		}
	}
	return (colors_sum(color_pix, ambiant));
}

t_color		trace_to_light_src(t_obj_info near, t_scene objs)
{
	t_coord		normal;
	t_color		color;
	double		light_pow;
	t_coord		d_t;
	double light;
	t_color color2;

	
	objs.light_srcs[0].color = (t_color){0,0,0};
	objs.light_srcs[1].color = (t_color){255,255,255};
	objs.light_srcs[2].color = (t_color){255,255,255};
	d_t = vctr_mult(objs.camera.direct, near.t);
	near.point = vctr_sum(objs.camera.point, d_t);
	near.normal = normal_to_obj(objs, near);
	near.color_obj = get_obj_color(objs, near.type, near.index);
	near.specular = get_specul_obj(objs, near.type, near.index);
	return (compute_lighting(objs.light_srcs, objs.num_l_src, near, objs));
}