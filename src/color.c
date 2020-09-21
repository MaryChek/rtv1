//
// Created by Rusakova Veronika on 21.09.2020.
//

#include "rtv1.h"

void	put_color_into_pix(int *img_data, int x, int y, t_color color)
{
	(img_data)[((y * WIN_WID) + x)] = color.r << 16;
	(img_data)[((y * WIN_WID) + x)] += color.g << 8;
	(img_data)[((y * WIN_WID) + x)] += color.b;
}
