/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:42 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/09 18:27:57 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <mlx.h>
# include <OpenCL/cl.h>

# define WIN_WID 1920
# define WIN_HIG 1080
# define WIN_DIST 1080
# define PI 3.14159265358979323846

typedef struct		s_quadr_equation
{
	double		a;
	double		b;
	double		c;
}					t_quadr_equation;

typedef struct		s_mlx
{
	void		*ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
}					t_mlx;

typedef struct		s_coord
{
	double		x;
	double		y;
	double		z;
}					t_coord;

typedef struct	s_quat
{
	double		w;
	t_coord		vec;
}				t_quat;

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
	double		rad;
	double		specular;
}					t_sph;

typedef struct		s_cylindr
{
	t_coord		center;
	t_color		color;
	t_coord		rotation;// direction
	double		rad;
	double		specular;
}					t_cylindr;

typedef struct		s_cone
{
	t_coord		center;
	t_color		color;
	t_coord		rotation; // direction
	double		angle;
	double		specular;
}					t_cone;

typedef struct		s_plane
{
	t_coord		center;
	t_color		color;
	t_coord		rotation;// direction
	double		specular;
}					t_plane;

enum	type_of_light_src
{
	AMBIENT,
	POINT,
	DIRECTIONAL,
};

typedef struct		s_light
{
	int		type;
	double	intensity;
	t_coord	pos_or_dir;
}					t_light;

typedef struct		s_cam
{
	t_coord		point;
	t_coord		direct;
	t_quat		roter;
}					t_cam;


typedef struct		s_object
{
	t_cam		camera;
	t_color		pix_color;
	t_sph		*sph_objs;
	int			num_sphs;
	t_cylindr	*cyln_objs;
	int			num_cylns;
	t_cone		*cone_objs;
	int			num_cons;
	t_plane		*plane_objs;
	int			num_plans;
	t_light		*light_srcs;
	int			num_l_src;
}					t_object;

enum	type_obj
{
	SPH,
	CYLINDER,
	CONE,
	PLANE,
};

typedef struct		s_obj_info
{
	int			type;
	int			index;
	t_coord		center;
	t_coord		st_cent;
	double		t;
	t_coord		point;
}					t_obj_info;

typedef struct		s_ray_data
{
	double		t_max;
	double		t_near;
	t_coord		diration;
	t_coord		cent_obj;
	t_coord		st_cent;
	t_coord		point;
}					t_ray_data;

t_color				trace_to_light_src(t_obj_info near, t_object my);
double				compute_lighting(t_coord point, t_coord normal,
												t_object my, double specular);

int					key_press(int key);

double				quadr_equation(t_quadr_equation factor, t_ray_data *ray);





t_coord				vctr_normal(t_coord vector);
double				vctr_len(t_coord q);
t_coord				vctr_rotation(t_coord vector, t_quat roter);
t_coord				vctr_sum(t_coord vec_1, t_coord vec_2);
t_coord				vctr_mult(t_coord vector, double mult);
t_coord				vctr_sub(t_coord begin_point, t_coord end_point);
t_coord				vctr_reverse(t_coord vector);
double				dot(t_coord v_1, t_coord v_2);



t_coord				get_direction(t_cam camera, int x, int y);


t_quat				creat_axis_of_rot(int x, int y, int z, double alpha);

void				min_and_max_to_raytrace(t_ray_data *ray, double t_min,
																double t_max);
t_obj_info			*ray_trace(t_object my, t_ray_data ray);

t_color				mult_colors(t_color v1, t_color v2, int minus);
t_color				brightness_change(t_color color, double mult);
void				change_color(t_color *color, int r, int g, int b);

// t_coord				win_to_viewport(int x, int y, t_viewport vp);

void				fixing_the_near_obj(t_ray_data ray, t_obj_info **near,
														int type, int index);
t_color				get_obj_color(t_object my, int type, int index);
int					get_specul_obj(t_object my, int type, int index);
t_coord				normal_to_obj(t_object my, t_obj_info near);
void				put_color_to_img(int **img_data, int x, int y,
														t_color color);
t_ray_data			creat_ray(double max_len, t_coord point,
													t_coord direction);

#endif