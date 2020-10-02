#include <rtv1.h>

void	sphere(t_object *object, char **arr)
{
	write(1, "sphere\n", 7);
	(void) object;
	(void) arr;
}

void	cylinder(t_object *object, char **arr)
{
	write(1, "cylinder\n", 9);
	(void) object;
	(void) arr;

}

void	cone(t_object *object, char **arr)
{
	write(1, "cone\n", 5);
	(void) object;
	(void) arr;

}

void	plane(t_object *object, char **arr)
{
	write(1, "plane\n", 6);
	(void) object;
	(void) arr;

}