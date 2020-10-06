#include <rtv1.h>

void	sphere(t_data *data, t_object *object, char **arr)
{
	static int i;

	i += 1;
	write(1, "sphere ", 7);
	write(1, &i, 1);
	write(1, "\n", 1);
	if (!(object->sph_objs[i - 1] = (t_sph *)malloc(sizeof(t_sph))))
		free_error_exit("Malloc error\n", 1, data);
	position(&(object->sph_objs[i - 1]->center), arr[1]);
	radius(&(object->sph_objs[i - 1]->rad), arr[2]);
	color(&(object->sph_objs[i - 1]->color), arr[3]);

}

void	cylinder(t_data *data, t_object *object, char **arr)
{
	static int i;
	i += 1;
	write(1, "cylinder ", 9);
	write(1, &i, 1);
	write(1, "\n", 1);
	if (!(object->cyln_objs[i - 1] = (t_cylindr *)malloc(sizeof(t_cylindr))))
		free_error_exit("Malloc error\n", 1, data);
	position(&object->cyln_objs[i - 1]->center, arr[1]);
	radius(&object->cyln_objs[i - 1]->rad, arr[2]);
	color(&object->cyln_objs[i - 1]->color, arr[3]);
	position(&object->cyln_objs[i - 1]->rotation, arr[4]);
}

void	cone(t_data *data, t_object *object, char **arr)
{
	static int i;
	i += 1;
	write(1, "cone ", 5);
	write(1, &i, 1);
	write(1, "\n", 1);
	if (!(object->cone_objs[i - 1] = (t_cone *)malloc(sizeof(t_cone))))
		free_error_exit("Malloc error\n", 1, data);
	position(&object->cone_objs[i - 1]->center, arr[1]);
	color(&object->cone_objs[i - 1]->color, arr[2]);
	position(&object->cone_objs[i - 1]->rotation, arr[3]);
	angle(object->cone_objs[i - 1]->angle, arr[4]);


}

void	plane(t_data *data, t_object *object, char **arr)
{
	static int i;
	i += 1;
	write(1, "plane ", 6);
	write(1, &i, 1);
	write(1, "\n", 1);
	if (!(object->plane_objs[i - 1] = (t_plane *)malloc(sizeof(t_plane))))
		free_error_exit("Malloc error\n", 1, data);
	position(&object->plane_objs[i - 1]->center, arr[1]);
	color(&object->plane_objs[i - 1]->color, arr[2]);
	position(&object->plane_objs[i - 1]->rotation, arr[3]);
//	angle(object->plane_objs[0]->, arr[4]);

}