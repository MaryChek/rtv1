/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:42 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/02 11:58:29 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <OpenCL/cl.h>
#include <stdio.h>

# define WIN_WID 1024
# define WIN_HIG 768

# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_BTTN 1
# define LEFT 123
# define RIGHT 124
# define UP 125
# define DOWN 126
# define SPACE 49

# define T_MIN 0.0


typedef struct		s_quadr_equation
{
	float		a;
	float		b;
	float		c;
}					t_quadr_equation;

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	int			*img_ptr;
	int			*data_ptr;
	int 		bit_pp;
	int 		endian;
	int 		size_line;
}					t_mlx;

typedef struct		s_viewport
{
	float			wid;
	float			hig;
	float			distanse;
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
	float		rad;
}					t_cylindr;

typedef struct		s_cone
{
	t_coord		center;
	t_color		color;
	t_coord		rotation;
	float		angle;
}					t_cone;

typedef struct		s_plane
{
	t_coord		center;
	t_color		color;
	t_coord		rotation;
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
	float	intensity;
	t_coord	pos_or_dir;
}					t_light;


typedef struct		s_object
{
	t_coord		rot_cam;
	t_coord		camera;
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
	PLANE
};

typedef struct		s_obj_info
{
	int			type;
	int			index;
	t_coord		point;
	t_coord		begin_vec;
	t_coord		center;
	t_coord		st_cent;
	float		t;
}					t_obj_info;

typedef struct		s_raytrace
{
	float		t_min;
	float		t_max;
	float		t_near;
	t_coord		begin_vec;
	t_coord		center;
	t_coord		st_cent;
}					t_raytrace;

typedef struct		s_data
{
	t_mlx				*mlx_ptr;
	t_object			*object_ptr;
}						t_data;


t_color				mult_colors(t_color v1, t_color v2, int minus);
//void				brightness_change(t_color *color, float mult);
void				change_color(t_color *color, int r, int g, int b);

t_coord				win_to_viewport(int x, int y, t_viewport vp, t_coord rot);

int					key_press(int key);

int					allocation(t_data *data);
int					main(int ac, char **av);
void				param_validation(char *param_name);

void				free_all(t_data *data);
void				clear_image(t_mlx *mlx);
int					error_exit(char *text, int code);
void				free_error_exit(char *text, int code, t_data *data);
void				grafic_connection(t_data *data, t_mlx *mlx);
void				grafic_preset(t_mlx *mlx);
int					close_window(t_data *data);
int					buttons_press(int key, t_data *data);
void				read_setups(t_data *data, char *name);
void 				draw(t_data *data, t_mlx *mlx, t_object *object);
void				paint_the_pix(int *img_data, int x, int y, t_color color);
//float				compute_lighting(t_coord p, t_coord normal, t_light *light_srcs, int num_light_src);
t_color				brightness_change(t_color color, float mult);
float				dot(t_coord v_1, t_coord v_2);

t_coord				sum_vectors(t_coord vec_1, t_coord vec_2);
t_coord				vec_scalar_mult(t_coord vector, float mult);
t_coord				vector_coord(t_coord begin_point, t_coord end_point);
//float				quadr_equation(t_quadr_equation factor, float *t);
//void				normal_vector(t_coord *q);
//float				vector_len(t_coord q);
t_color				light_and_shadow(t_obj_info *near, t_object *object, t_raytrace value);
float				compute_lighting(t_coord point, t_coord normal, t_object *object,
						  t_raytrace value);

float				quadr_equation(t_quadr_equation factor, t_raytrace *value);
t_coord				normal_vector(t_coord vector);
float				vector_len(t_coord q);

t_coord				cyln_normal(t_coord rotation, t_obj_info near);
t_coord				cone_normal(t_coord rotation, t_obj_info near, float angle);
t_raytrace			fill_in_values_to_raytracing(float t_min, float t_max, float t_near);
t_obj_info			*ray_tracing(t_object *object, t_raytrace value, t_coord point);

void				sphere(t_object *object, char **arr);
void				cylinder(t_object *object, char **arr);
void				cone(t_object *object, char **arr);
void				plane(t_object *object, char **arr);
void				camera(t_object *object, char **arr);
void				light(t_object *object, char **arr);


#endif
