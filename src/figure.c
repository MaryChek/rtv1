#include <rtv1.h>

void	sphere(t_object *object, char **arr)
{
	write(1, "sphere\n", 7);
	position(object, arr[1]);
}

void	cylinder(t_object *object, char **arr)
{
	write(1, "cylinder\n", 9);
	position(object, arr[1]);
}

void	cone(t_object *object, char **arr)
{
	write(1, "cone\n", 5);
	position(object, arr[1]);
}

void	plane(t_object *object, char **arr)
{
	write(1, "plane\n", 6);
	position(object, arr[1]);
}