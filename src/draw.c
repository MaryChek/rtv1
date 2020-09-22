#include "rtv1.h"

void 				draw(t_data *data, t_mlx *mlx, t_object *object)
{
	t_viewport view_port;

	view_port.wid = WIN_WID;
	view_port.hig = WIN_HIG;
	view_port.distanse = 1;

	int x, y;
	t_color	color;

	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			t_vector _vo_;
//			change_color(&pix_color, 0, 0, 0);
			_vo_ = create_vector(object->camera, win_to_viewport(x, y, view_port)); // CanvasToViewPort почему так??
			color = find_color(_vo_,object, T_MIN);
			paint_the_pix(mlx->data_ptr, x, y, color);
		}
	}
	(void)data;
}
