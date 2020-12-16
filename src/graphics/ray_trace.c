/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:59:17 by rtacos            #+#    #+#             */
/*   Updated: 2020/12/16 12:07:11 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			tang_to_plane(t_ray_data *ray, t_plane plane)
{
	double		t;
	double		dot_ov_r;
	double		dot_co_r;

	ray->cent_obj = plane.center;
	ray->st_cent = vctr_sub(plane.center, ray->point);
	dot_co_r = vctr_dot(ray->st_cent, plane.direction);
	dot_ov_r = vctr_dot(ray->direction, plane.direction);
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
	dot_co_r = vctr_dot(ray->st_cent, cone.direction);
	dot_ov_r = vctr_dot(ray->direction, cone.direction);
	k = tan(0.5 * (cone.angle * M_PI / 180));
	k = k * k + 1.0;
	factor.a = vctr_dot(ray->direction, ray->direction) -
							k * pow(dot_ov_r, 2.0);
	factor.b = 2.0 * (vctr_dot(ray->direction, ray->st_cent)
							- k * dot_co_r * dot_ov_r);
	factor.c = vctr_dot(ray->st_cent, ray->st_cent)
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
	dot_co_r = vctr_dot(ray->st_cent, cyln.direction);
	dot_ov_r = vctr_dot(ray->direction, cyln.direction);
	factor.a = vctr_dot(ray->direction, ray->direction) -
										pow(dot_ov_r, 2.);
	factor.b = 2. * (vctr_dot(ray->direction, ray->st_cent) -
												dot_co_r * dot_ov_r);
	factor.c = vctr_dot(ray->st_cent, ray->st_cent) -
							pow(dot_co_r, 2.0) - cyln.rad * cyln.rad;
	return (quadr_equation(factor, ray));
}

int			tang_to_sph(t_ray_data *ray, t_sph sph)
{
	t_quadr_equation	factor;
	t_coord				center;

	ray->cent_obj = sph.center;
	center = vctr_sub(sph.center, ray->point);
	factor.a = vctr_dot(ray->direction, ray->direction);
	factor.b = 2. * vctr_dot(center, ray->direction);
	factor.c = vctr_dot(center, center) - sph.rad * sph.rad;
	return (quadr_equation(factor, ray));
}

t_coord					cylinder_intersect(t_ray_data ray, t_cylinder_cap cyln, t_coord v)
{
	t_coord				x;
	float				a;
	float				b;
	float				c;
	float				d;

	x = vctr_sub(cyln.tail, ray.point);
	a = vctr_dot(ray.direction, ray.direction) - powf(vctr_dot(ray.direction, v), 2.0);
	b = (vctr_dot(ray.direction, x) - (vctr_dot(ray.direction, v) * vctr_dot(x, v))) * 2.0;
	c = vctr_dot(x, x) - powf(vctr_dot(x, v), 2.0) - powf(cyln.rad, 2.0);
	d = powf(b, 2.0) - 4.0 * a * c;
	if (d < 0.0000)
		return ((t_coord){INFINITY, INFINITY, INFINITY});
	d = sqrtf(d);
	return ((t_coord){(-b - d) / (2.0 * a), (-b + d) / (2.0 * a), 0.0});
}

int			tang_to_cyln_cap(t_ray_data *ray, t_cylinder_cap cyln)
{
	float				maxm;
	t_coord				points;
	t_coord				v;
	t_coord				m;
	float				x_dot_v;

	ray->st_cent = vctr_sub(cyln.tail, ray->point);
	v = cyln.direction;
	points = cylinder_intersect(*ray, cyln, v);
	maxm = (float)vctr_len(vctr_sub(cyln.head, cyln.tail));
	x_dot_v = vctr_dot(ray->st_cent, v);
	m.x = vctr_dot(ray->direction, vctr_mult(v, points.x)) + x_dot_v;
	m.y = vctr_dot(ray->direction, vctr_mult(v, points.y)) + x_dot_v;
	ray->t_near = INFINITY;
	if (points.x != INFINITY)
	{
		if (m.x >= 0.0 && m.x <= maxm && m.y >= 0.0 && m.y <= maxm)
		{
			if (points.x >= 0.0)
				ray->t_near = points.x;
			if (points.y >= 0.0 && points.y < ray->t_near)
				ray->t_near = points.y;
			ray->cent_obj = vctr_sum(
						cyln.tail, vctr_mult(v,
							vctr_dot(ray->direction, v) * ray->t_near + x_dot_v));
			return (ray->t_near == INFINITY ? 0 : 1);
		}
	}
	// if ((m.x < 0 && m.y < 0) || (m.x > maxm && m.y > maxm))
		return (0);
	// return (1);
}

// int			tang_to_cone_cap(t_ray_data *ray, t_cone_cap cone)
// {
// 	ray->fl = 1;
// }

int			ray_trace(t_scene objs, t_ray_data ray, t_obj_info *near)
{
	int			i;

	i = -1;
	near->t = -1.0;
	// while (objs.plane_objs && ++i < objs.num_plans)
	// 	if (tang_to_plane(&ray, objs.plane_objs[i]))
	// 		fixing_the_near_obj(ray, near, PLANE, i);
	// i = -1;
	// while (objs.sph_objs && ++i < objs.num_sphs)
	// 	if (tang_to_sph(&ray, objs.sph_objs[i]))
	// 		fixing_the_near_obj(ray, near, SPH, i);
	i = -1;
	while (objs.cyln_cap_objs && ++i < objs.num_cyln_cap)
		if (tang_to_cyln_cap(&ray, objs.cyln_cap_objs[i]))
			fixing_the_near_obj(ray, near, CAP_CYLN, i);
	// i = -1;
	// while (objs.cone_cap_objs && ++i < objs.num_cone_cap)
	// 	if (tang_to_cone_cap(&ray, objs.cone_cap_objs[i]))
	// 		fixing_the_near_obj(ray, near, CONE, i);
	return (near->t > -1.0 ? 1 : 0);
}
