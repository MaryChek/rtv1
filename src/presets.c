#include "rtv1.h"


void			grafic_preset(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win =mlx_new_window(mlx->mlx, WIN_WID, WIN_HIG, "RTv1");
	mlx->size_line = WIN_WID;
	mlx->bit_pp = 32;
	mlx->endian = 0;
	mlx->img_ptr = mlx_new_image(mlx, WIN_WID, WIN_HIG);
	mlx->data_ptr = (int *)mlx_get_data_addr(
			mlx->img_ptr, &mlx->bit_pp, &mlx->size_line, &mlx->endian);
}

void			preset_structures(t_object *object)
{
	object->num_sphs = 0;
	object->num_cylns = 0;
	object->num_cons = 0;
	object->num_plans = 0;
	object->num_l_src = 0;
}