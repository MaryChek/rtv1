#include <rtv1.h>

void	camera(t_object *object, char **arr)
{
	size_t		len;

	write(1, "camera\n", 7);
	len = ft_arrlen(arr);
	if (len > 1)
		position(&object->camera, arr[1], NULL);
	if (len > 2)
		position(&object->rot_cam.vec, arr[2], NULL);
//	object->rot_cam.w = DEFAULT_CAMERA_ANGLE;
}