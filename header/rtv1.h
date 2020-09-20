/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:42 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/18 21:09:26 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
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
	int 		bit_pp;
}					t_mlx;

typedef struct		s_viewport
{
	int			wid;
	int			hig;
	int			distanse;
}					t_viewport;

typedef struct		s_coord
{
	float		x;
	float		y;
	float		z;
}					t_coord;

typedef struct		s_vector
{
	t_coord		point;
	t_coord		distance;
}					t_vector;

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

typedef struct		s_object
{
	t_coord		camera;
	t_color		pix_color;
	t_sph		*sph_objs;
	int			num_sphs;
	t_cylindr	*cyln_objs;
	int			num_cylns;
}					t_object;

typedef struct		s_data
{
	t_mlx			*mlx_ptr;
	t_quadr_equation	*quadr_equation_ptr;
	t_viewport			*viewport_ptr;
	t_coord				*coord_ptr;
	t_vector			*vector_ptr;
	t_color				*color_ptr;
	t_sph				*sph_ptr;
	t_cylindr			*cylindr_ptr;
	t_object			*object_ptr;
}						t_data;


t_color				mult_colors(t_color v1, t_color v2, int minus);
void				brightness_change(t_color *color, float mult);
void				change_color(t_color *color, int r, int g, int b);

t_coord				win_to_viewport(int x, int y, t_viewport vp);

t_vector			creat_vector(t_coord first_point, t_coord second_point);
t_coord				diff(t_coord p1, t_coord p2);
float				dot(t_coord p1, t_coord p2);

t_color				find_tangent_to_object(t_vector _ov_, t_object my, float t_min);

float				quadr_equation(t_quadr_equation factor, float *t_1);
void				normal_rotation(t_coord *q);

int					key_press(int key);

int					allocation(t_data *data);
int					main(int ac, char **av);
void				param_validation(char *param_name);

void			free_all(t_data *data);
void			clear_image(t_mlx *mlx);
int		error_exit(char *text, int code);
void	free_error_exit(char *text, int code, t_data *data);

#endif
