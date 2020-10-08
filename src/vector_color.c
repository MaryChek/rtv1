/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:50:57 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/27 20:45:27 by rtacos           ###   ########.fr       */
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

t_color		brightness_change(t_color color,  double mult)
{
	int	tmp;

	if (((tmp = (int)(( double)color.r * mult))) > 255)
		color.r = 255;
	else if (tmp <= 0.0)
		color.r = 0;
	else
		color.r = tmp;
	if (((tmp = (int)(( double)color.g * mult))) > 255)
		color.g = 255;
	else if (tmp <= 0.0)
		color.g = 0;
	else
		color.g = tmp;
	if (((tmp = (int)(( double)color.b * mult))) > 255)
		color.b = 255;
	else if (tmp <= 0.0)
		color.b = 0;
	else
		color.b = tmp;
	return (color);
}

void		change_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}