/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:50:57 by rtacos            #+#    #+#             */
/*   Updated: 2020/10/11 15:41:41 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	mult_colors(t_color v1, t_color v2, int minus)
{
	if (!minus)
	{
		if (((v1.r += v2.r)) > 255)
			v1.r = 255;
		if (((v1.g += v2.g)) > 255)
			v1.g = 255;
		if (((v1.b += v2.b)) > 255)
			v1.b = 255;
	}
	else
	{
		if (((v1.r -= v2.r)) < 0)
			v1.r = 0;
		if (((v1.g -= v2.g)) < 0)
			v1.g = 0;
		if (((v1.b -= v2.b)) < 0)
			v1.b = 0;
	}
	return (v1);
}

t_color		brightness_change(t_color color, double mult)
{
	int	tmp;

	if (((tmp = (int)((double)color.r * mult))) > 255)
		color.r = 255;
	else if (tmp <= 0.0)
		color.r = 0;
	else
		color.r = tmp;
	if (((tmp = (int)((double)color.g * mult))) > 255)
		color.g = 255;
	else if (tmp <= 0.0)
		color.g = 0;
	else
		color.g = tmp;
	if (((tmp = (int)((double)color.b * mult))) > 255)
		color.b = 255;
	else if (tmp <= 0.0)
		color.b = 0;
	else
		color.b = tmp;
	return (color);
}

void	put_color_to_img(int **img_data, int x, int y, t_color color)
{
	(*img_data)[((y * WIN_WID) + x)] = color.r << 16;
	(*img_data)[((y * WIN_WID) + x)] += color.g << 8;
	(*img_data)[((y * WIN_WID) + x)] += color.b;
}

void		change_color(t_color *color, t_color rgb)
{
	color->r = rgb.r;
	color->g = rgb.g;
	color->b = rgb.b;
}

void	color(t_color *color, char *arr)
{
	change_color(color, (t_color){0, 0, 0});
	if (arr)
	{
		if (!ft_strcmp(arr, "red"))
			change_color(color, RED);
		else if (!ft_strcmp(arr, "green"))
			change_color(color, GREEN);
		else if (!ft_strcmp(arr, "blue"))
			change_color(color, BLUE);
		else if (!ft_strcmp(arr, "yellow"))
			change_color(color, YELLOW);
		else if (!ft_strcmp(arr, "white"))
			change_color(color, WHITE);
		else if (!ft_strcmp(arr, "orange"))
			change_color(color, ORANGE);
		else if (!ft_strcmp(arr, "sky-blue"))
			change_color(color, SKY_BLUE);
		else if (!ft_strcmp(arr, "violet"))
			change_color(color, VIOLET);
		else if (!ft_strcmp(arr, "pink"))
			change_color(color, PINK);
		else if (!ft_strcmp(arr, "metal"))
			change_color(color, METAL);
	}
}