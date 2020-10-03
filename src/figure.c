#include <rtv1.h>

void	sphere(t_object *object, char **arr)
{
	write(1, "sphere\n", 7);
	position(object, arr[1]);
	radius(object, arr[2]);
	color(object, arr[3]);

}

void	cylinder(t_object *object, char **arr)
{
	write(1, "cylinder\n", 9);
	position(object, arr[1]);
	radius(object, arr[2]);
	color(object, arr[3]);
	position(object, arr[4]);

}

void	cone(t_object *object, char **arr)
{
	write(1, "cone\n", 5);
	position(object, arr[1]);
	color(object, arr[2]);
	position(object, arr[3]);
	angle(object, arr[4]);


}

void	plane(t_object *object, char **arr)
{
	write(1, "plane\n", 6);
	position(object, arr[1]);
	color(object, arr[2]);
	position(object, arr[3]);
	angle(object, arr[4]);

}