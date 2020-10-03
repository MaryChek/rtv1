#include <rtv1.h>

void	camera(t_object *object, char **arr)
{
	write(1, "camera\n", 7);
	position(object, arr[1]);
	position(object, arr[2]);
	angle(object, arr[3]);

	(void) object;
	(void) arr;
}