/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:42 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/15 22:18:23 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <OpenCL/cl.h>
# include <stdio.h>

# define WIN_WID 1920
# define WIN_HIG 1080
# define WIN_DIST 1080

# define ESC 53

# define T_MIN 0.0

# define DEFAULT_COORDINATE 1.0
# define DEFAULT_R 1.0
# define DEFAULT_A 2.0
# define DEFAULT_CAMERA 0.0
# define DEFAULT_CAMERA_ANGLE 30.0
# define DEFAULT_LIGHT 0.0
# define DEFAULT_INTENSIVITY 0.3
# define DEFAULT_SPECULAR -1.0

# define RED (t_color){255, 0, 0}
# define ORANGE (t_color){255, 150, 0}
# define YELLOW (t_color){255, 255, 0}
# define GREEN (t_color){0, 255, 0}
# define SKY_BLUE (t_color){0, 255, 255}
# define BLUE (t_color){0, 0, 255}
# define VIOLET (t_color){150, 0, 255}
# define PINK (t_color){255, 0, 255}
# define METAL (t_color){154, 174, 196}
# define WHITE (t_color){255, 255, 255}


typedef struct		s_quadr_equation
{
	double		a;
	double		b;
	double		c;
}					t_quadr_equation;

typedef struct		s_mlx
{
	void		*ptr;
	void		*win;
	void		*img_ptr;
	int			*img_data;
	int 		bit_pp;
	int 		endian;
	int 		size_line;
}					t_mlx;

typedef struct		s_color
{
	int			r;
	int			g;
	int			b;
}					t_color;

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
	t_coord		direction;
	double		rad;
	double		specular;
}					t_cylindr;

typedef struct		s_cone
{
	t_coord		center;
	t_color		color;
	t_coord		direction;
	double		angle;
	double		specular;
}					t_cone;

typedef struct		s_plane
{
	t_coord		center;
	t_color		color;
	t_coord		direction;
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
	t_color	color;
}					t_light;

typedef struct		s_vector
{
	t_coord		point;
	t_coord		direct;
	t_quat		roter;
}					t_vector;

typedef struct		s_scene
{
	t_vector	camera;

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
}					t_scene;

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
	t_coord		center;
	t_coord		st_cent;
	t_coord		normal;
	t_color		color_obj;
	double		t;
	double		specular;
}					t_obj_info;

typedef struct		s_ray_data
{
	double		t_max;
	double		t_near;
	t_coord		direction;
	t_coord		cent_obj;
	t_coord		st_cent;
	t_coord		point;
}					t_ray_data;

typedef struct		s_data
{
	t_mlx		*mlx;
	t_scene		*p_object;
}					t_data;

int					allocation(t_data *data, char *param_name);
int					main(int ac, char **av);
void				param_validation(char *param_name);

void				free_all(t_data *data);
int					error_exit(char *text, int code);
void				free_error_exit(char *text, int code, t_data *data);
void				grafic_connection(t_data *data, t_mlx *mlx);
void				grafic_preset(t_mlx *mlx);
int					close_window(t_data *data);
int					buttons_press(int key, t_data *data);
void				read_setups(t_data *data, char *name);
void 				draw(int **img_data, t_scene object);

void				sphere(t_data *data, t_scene *object, char **arr);
void				cylinder(t_data *data, t_scene *object, char **arr);
void				cone(t_data *data, t_scene *object, char **arr);
void				plane(t_data *data, t_scene *object, char **arr);
void				camera(t_scene *object, char **arr);
void				light(t_data *data, t_scene *object, char **arr);
void				position(t_coord *p, char *arr, t_data *pData);
void 				color(t_color *color, char *arr);
void 				ft_safe_free_arr(char **arr);
double				coordinate(char *str);
void				preset_structures(t_scene *object);
void				validate_fd(int fd, t_data *data);

t_color				trace_to_light_src(t_obj_info near, t_scene objs);

// int					key_press(int key);

double				quadr_equation(t_quadr_equation factor, t_ray_data *ray);
t_coord				vctr_normal(t_coord vector);
double				vctr_len(t_coord q);
t_coord				vctr_rotation(t_coord vector, t_quat roter);

t_quat				creat_axis_of_rot(t_coord vector, double alpha);

void				min_and_max_to_raytrace(t_ray_data *ray, double t_min,
											double t_max);
int					ray_trace(t_scene objs, t_ray_data ray, t_obj_info *near);

t_color				colors_sum(t_color v1, t_color v2);
t_color				color_scal(t_color color, double mult);
void				color_change(t_color *color, t_color rgb);
t_color				colors_mult(t_color v1, t_color v2);

double				dot(t_coord v_1, t_coord v_2);
t_coord				vctr_sum(t_coord vec_1, t_coord vec_2);
t_coord				vctr_mult(t_coord vector, double mult);
t_coord				vctr_sub(t_coord begin_point, t_coord end_point);
t_coord				vctr_reverse(t_coord vector);

int					fixing_the_near_obj(t_ray_data ray, t_obj_info *near,
										int type, int index);
t_color				get_obj_color(t_scene objs, int type, int index);
int					get_specul_obj(t_scene objs, int type, int index);
t_coord				get_direction(t_vector camera, int x, int y);
t_ray_data			creat_ray(double max_len, t_coord point,
													t_coord direction);

t_coord				normal_to_obj(t_scene objs, t_obj_info near);

void				put_color_to_img(int **img_data, int x, int y,
									 t_color color);
double				ft_clampd(double num, double min, double max);

#endif
