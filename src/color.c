
#include "rtv1.h"

void		paint_the_pix(int *img_data, int x, int y, t_color color)
{
	(img_data)[((y * WIN_WID) + x)] = color.r << 16;
	(img_data)[((y * WIN_WID) + x)] += color.g << 8;
	(img_data)[((y * WIN_WID) + x)] += color.b;
}

void color(t_color *color, char *arr)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	if (arr)
	{
		if (!ft_strcmp(arr, "red"))
			color->r = 255;
		else if (!ft_strcmp(arr, "green"))
			color->g = 255;
		else if (!ft_strcmp(arr, "blue"))
			color->b = 255;
		else
			color->b = 60;
	}
	else
	{
		color->g = 128;
		color->b = 128;
	}
}