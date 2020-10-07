#include "rtv1.h"

void 				draw(t_data *data, t_mlx *mlx, t_object *object)
{
	t_viewport view_port;

	view_port.wid = WIN_WID;
	view_port.hig = WIN_HIG;
	view_port.distanse = 768.0f;

	int x, y;
	t_raytrace	value;
	t_obj_info	*near;

//	value = fill_in_values_to_raytracing(0.0, 100000.0, -1, object->camera);
//	t_color	color;

	y = -1;
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			value.t_near = -1;
			value = fill_in_values_to_raytracing(0.0f, INFINITY, 0.0);
			value.begin_vec = normal_vector(vector_coord(object->camera, win_to_viewport(x, y, view_port, object->rot_cam.vec)));
			if ((near = ray_tracing(object, value, object->camera)))
				object->pix_color = light_and_shadow(near, object, value);
			else
				change_color(&object->pix_color, 0, 0, 0);
			paint_the_pix(mlx->data_ptr, x, y, object->pix_color);
		}
	}
	(void)data;
//	ft_safe_free(near);
}
