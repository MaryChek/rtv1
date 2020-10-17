/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:59:17 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/17 18:50:25 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

int			tang_to_plane(t_ray_data *ray, t_plane plane)
{
	double		t;
	double		dot_ov_r;
	double		dot_co_r;

	ray->cent_obj = plane.center;
	ray->st_cent = vctr_sub(plane.center, ray->point);
	dot_co_r = dot(ray->st_cent, plane.direction);
	dot_ov_r = dot(ray->direction, plane.direction);
	t = (-dot_co_r) / dot_ov_r;
	if ((t > 0.00001 && t < ray->t_max))
	{
		ray->t_near = t;
		return (1);
	}
	return (0);
}

int			tang_to_cone(t_ray_data *ray, t_cone cone)
{
	t_quadr_equation	factor;
	double				dot_ov_r;
	double				dot_co_r;
	double				k;

	ray->cent_obj = cone.center;
	ray->st_cent = vctr_sub(cone.center, ray->point);
	dot_co_r = dot(ray->st_cent, cone.direction);
	dot_ov_r = dot(ray->direction, cone.direction);
	k = tan(0.5 * (cone.angle * M_PI / 180));
	k = k * k + 1.0;
	factor.a = dot(ray->direction, ray->direction) -
							k * pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (dot(ray->direction, ray->st_cent)
							- k * dot_co_r * dot_ov_r);
	factor.c = dot(ray->st_cent, ray->st_cent)
							- k * pow(dot_co_r, 2.0);
	return (quadr_equation(factor, ray));
}

int			tang_to_cyln(t_ray_data *ray, t_cylindr cyln)
{
	t_quadr_equation	factor;
	double				dot_ov_r;
	double				dot_co_r;

	ray->cent_obj = cyln.center;
	ray->st_cent = vctr_sub(cyln.center, ray->point);
	dot_co_r = dot(ray->st_cent, cyln.direction);
	dot_ov_r = dot(ray->direction, cyln.direction);
	factor.a = dot(ray->direction, ray->direction) -
										pow(dot_ov_r, 2.);
	factor.b = 2. * (dot(ray->direction, ray->st_cent) -
												dot_co_r * dot_ov_r);
	factor.c = dot(ray->st_cent, ray->st_cent) -
							pow(dot_co_r, 2.0) - cyln.rad * cyln.rad;
	return (quadr_equation(factor, ray));
}

int			tang_to_sph(t_ray_data *ray, t_sph sph)
{
	t_quadr_equation	factor;
	t_coord				center;

	ray->cent_obj = sph.center;
	center = vctr_sub(sph.center, ray->point);
	factor.a = dot(ray->direction, ray->direction);
	factor.b = 2. * dot(center, ray->direction);
	factor.c = dot(center, center) - sph.rad * sph.rad;
	return (quadr_equation(factor, ray));
}

int			ray_trace(t_scene objs, t_ray_data ray, t_obj_info *near)
{
	int			i;

	i = -1;
	near->t = -1.0;
	while (objs.plane_objs && ++i < objs.num_plans)
		if (tang_to_plane(&ray, objs.plane_objs[i]))
			fixing_the_near_obj(ray, near, PLANE, i);
	i = -1;
	while (objs.sph_objs && ++i < objs.num_sphs)
		if (tang_to_sph(&ray, objs.sph_objs[i]))
			fixing_the_near_obj(ray, near, SPH, i);
	i = -1;
	while (objs.cyln_objs && ++i < objs.num_cylns)
		if (tang_to_cyln(&ray, objs.cyln_objs[i]))
			fixing_the_near_obj(ray, near, CYLINDER, i);
	i = -1;
	while (objs.cone_objs && ++i < objs.num_cons)
		if (tang_to_cone(&ray, objs.cone_objs[i]))
			fixing_the_near_obj(ray, near, CONE, i);
	return (near->t > -1.0 ? 1 : 0);
}
