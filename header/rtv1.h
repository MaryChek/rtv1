/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:42 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/25 19:58:22 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <mlx.h>
# include <OpenCL/cl.h>

# define WIN_WID 1920
# define WIN_HIG 1080

typedef struct		s_quadr_equation
{
	float		a;
	float		b;
	float		c;
}					t_quadr_equation;

typedef struct		s_mlx
{
	void		*ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
}					t_mlx;

typedef struct		s_viewport
{
	int			wid;
	int			hig;
	float		distanse;
}					t_viewport;

typedef struct		s_coord
{
	float		x;
	float		y;
	float		z;
}					t_coord;

typedef struct		s_color
{
	int			r;
	int			g;
	int			b;
}					t_color;

typedef struct		s_sph
{
	t_coord		center;
	t_color		color;
	float		rad;
}					t_sph;

typedef struct		s_cylindr
{
	t_coord		center;
	t_color		color;
	t_coord		rotation;
	float		hig;
	float		rad;
}					t_cylindr;

enum	type_of_light_src
{
	AMBIENT,
	POINT,
	DIRECTIONAL,
};

typedef struct		s_light
{
	int		type;
	float	intensity;
	t_coord	pos_or_dir;
}					t_light;

typedef struct		s_object
{
	t_coord		camera;
	t_color		pix_color;
	t_sph		*sph_objs;
	int			num_sphs;
	t_cylindr	*cyln_objs;
	int			num_cylns;
	t_light		*light_srcs;
	int			num_l_src;
}					t_object;

enum	type_obj
{
	SPH,
	CYLINDER,
};

typedef struct		s_obj_info
{
	int			type;
	int			index;
	t_coord		point;
	// t_coord		begin_vec;
	t_coord		center;
	float		t;
}					t_obj_info;

typedef struct		s_raytrace
{
	float		t_min;
	float		t_max;
	float		t_near;
	t_coord		begin_vec;
	t_coord		center;
	t_coord		camera;
}					t_raytrace;

t_color				mult_colors(t_color v1, t_color v2, int minus);
t_color				brightness_change(t_color color, float mult);
void				change_color(t_color *color, int r, int g, int b);

t_coord				win_to_viewport(int x, int y, t_viewport vp);

float				dot(t_coord v_1, t_coord v_2);

t_raytrace			fill_in_values_to_raytracing(float t_min, float t_max, float t_near,
																t_coord begin_vec);
t_color				find_color(t_object my, t_raytrace value, t_obj_info *near);

t_coord				sum_vectors(t_coord vec_1, t_coord vec_2);
t_coord				vec_scalar_mult(t_coord vector, float mult);
t_coord				vector_coord(t_coord begin_point, t_coord end_point);
float				quadr_equation(t_quadr_equation factor, float *t);
void				normal_vector(t_coord *q);
float				vector_len(t_coord q);

int					key_press(int key);

float				compute_lighting(t_coord p, t_coord normal, t_light *light_srcs, int num_light_src);

#endif