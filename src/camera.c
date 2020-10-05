#include <rtv1.h>

void	camera(t_object *object, char **arr)
{
	write(1, "camera\n", 7);
	position(&object->camera, arr[1]);
	position(&object->rot_cam, arr[2]);
//	angle(object->, arr[3]);
}