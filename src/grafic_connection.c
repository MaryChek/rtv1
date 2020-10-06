#include "rtv1.h"

void			grafic_connection(t_data *data, t_mlx *mlx)
{
	grafic_preset(mlx);

	draw(data, mlx, data->p_object);

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win, 2, 0, buttons_press, data);
	mlx_hook(mlx->win, 17, (1L << 17), close_window, data);
	mlx_loop(mlx->mlx);
	(void) data;
}
