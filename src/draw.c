#include "rtv1.h"

void 				draw(t_data *data, t_mlx *mlx, t_object *object)
{
	t_viewport view_port;

	view_port.wid = WIN_WID;
	view_port.hig = WIN_HIG;
	view_port.distanse = 100;

	int x, y;
	t_color	pix_color;

	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			t_vector _vo_;
			float t_min;

			t_min = 0.0;
			change_color(&pix_color, 0, 0, 0);
			_vo_ = creat_vector(object->camera, win_to_viewport(x, y, view_port));
			pix_color = find_tangent_to_object(_vo_, object,
											   t_min); ////// вернуть int if(find) -> pix =... else pix(0,0,0);
			put_color_into_pix(mlx->data_ptr, x, y, pix_color);
		}
	}
	(void)data;
}
