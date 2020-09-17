/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:25:42 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/17 22:00:45 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <mlx.h>
# include <OpenCL/cl.h>

# define WIN_WID 1920
# define WIN_HIG 1080

typedef struct		s_mlx
{
	void		*ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
}					t_mlx;

typedef struct		s_coord
{
	int			x;
	int			y;
	int			z;
}					t_coord;

typedef struct		s_vector
{
	t_coord		st;
	t_coord		end;
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

typedef struct		s_viewport
{
	int			wid;
	int			hig;
	int			distanse;
}					t_viewport;

typedef struct		s_object
{
	t_coord		camera;
	t_color		pix_color;
	t_sph		*sph_objs;
	int			num_sphs;
}					t_object;

t_color				mult_colors(t_color v1, t_color v2, int minus);
void				brightness_change(t_color *color, float mult);
void				change_color(t_color *color, int r, int g, int b);

t_coord				win_to_viewport(int x, int y, t_viewport vp);

t_vector			creat_vector(t_coord first_point, t_coord second_point);
t_coord				diff(t_coord p1, t_coord p2);
float				dot(t_coord p1, t_coord p2);

float				discrim(float a, float b, float c);

int					find_tangent_to_object(t_vector _ov_, t_object my, float *t_min);

#endif