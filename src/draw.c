#include "rtv1.h"

void 				draw(t_data *data, t_mlx *mlx, t_object *object)
{
	t_viewport view_port;

	view_port.wid = WIN_WID;
	view_port.hig = WIN_HIG;
	view_port.distanse = 768.0;

	int x, y;
	t_raytrace	value;
	t_obj_info	*near;

	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			value.begin_vec = normal_vector(vector_coord(object->camera,
					vector_rotation(win_to_viewport(x, y, view_port), object->rot_cam)));
			min_and_max_to_raytrace(&value, 0.0, INFINITY);
			if ((near = ray_trace(object, value, object->camera)))
			{
				object->pix_color = trace_to_light_src(*near, object, value);
				free(near);
			}
			else
				change_color(&object->pix_color, 0, 0, 0);
			put_color_to_img(&mlx->data_ptr, x, y, object->pix_color);
		}
	}
}
