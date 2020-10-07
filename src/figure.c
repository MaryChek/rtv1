#include <rtv1.h>

void	sphere(t_data *data, t_object *object, char **arr)
{
	static int i;

	i += 1;
	printf("sphere %d\n", i);

	position(&object->sph_objs[i - 1].center, arr[1]);
	radius(&(object->sph_objs[i - 1].rad), arr[2]);
	color(&(object->sph_objs[i - 1].color), arr[3]);

}

void	cylinder(t_data *data, t_object *object, char **arr)
{
	static int i;
	i += 1;
	printf("cylinder %d\n", i);
	position(&object->cyln_objs[i - 1].center, arr[1]);
	radius(&object->cyln_objs[i - 1].rad, arr[2]);
	color(&object->cyln_objs[i - 1].color, arr[3]);
	position(&object->cyln_objs[i - 1].rotation, arr[4]);
}

void	cone(t_data *data, t_object *object, char **arr)
{
	static int i;

	i += 1;
	printf("cone %d\n", i);

	position(&object->cone_objs[i - 1].center, arr[1]);
	color(&object->cone_objs[i - 1].color, arr[2]);
	position(&object->cone_objs[i - 1].rotation, arr[3]);
	angle(&object->cone_objs[i - 1].angle, arr[4]);


}

void	plane(t_data *data, t_object *object, char **arr)
{
	static int i;

	i += 1;
	printf("plane %d\n", i);

	position(&object->plane_objs[i - 1].center, arr[1]);
	color(&object->plane_objs[i - 1].color, arr[2]);
	position(&object->plane_objs[i - 1].rotation, arr[3]);

}