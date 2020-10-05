#include <rtv1.h>

void	sphere(t_object *object, char **arr)
{
	write(1, "sphere\n", 7);
	position(&object->sph_objs->center, arr[1]);
	radius(&object->sph_objs->rad, arr[2]);
	color(&object->sph_objs->color, arr[3]);

}

void	cylinder(t_object *object, char **arr)
{
	write(1, "cylinder\n", 9);
	position(&object->cyln_objs->center, arr[1]);
	radius(&object->cyln_objs->rad, arr[2]);
	color(&object->cyln_objs->color, arr[3]);
	position(&object->cyln_objs->rotation, arr[4]);

}

void	cone(t_object *object, char **arr)
{
	write(1, "cone\n", 5);
	position(&object->cone_objs->center, arr[1]);
	color(&object->cone_objs->color, arr[2]);
	position(&object->cone_objs->rotation, arr[3]);
	angle(object->cone_objs->angle, arr[4]);


}

void	plane(t_object *object, char **arr)
{
	write(1, "plane\n", 6);
	position(&object->plane_objs->center, arr[1]);
	color(&object->plane_objs->color, arr[2]);
	position(&object->plane_objs->rotation, arr[3]);
//	angle(object->plane_objs->, arr[4]);

}