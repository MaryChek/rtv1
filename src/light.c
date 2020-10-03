#include <rtv1.h>

static void	intensity(t_object *object, char *arr)
{
	float intensity;
	intensity = 0.2f;
	if (arr)
	{
		intensity = coordinate(arr);
		if (intensity < 0.0f)
			intensity = 0.2f;
		else if (intensity > 1.0f)
			intensity = 1.0f;
	}
	printf("intens=%s -> %.2f\n",arr,intensity);
}

void	light(t_object *object, char **arr)
{
	write(1, "light\n", 6);
	if (!ft_strcmp(arr[1], "AMBIENT"))
	{
			intensity(object, arr[2]);
	}
	if (!ft_strcmp(arr[1], "POINT"))
	{
		intensity(object, arr[2]);
		position(object, arr[3]);
	}
	if (!ft_strcmp(arr[1], "DIRECTIONAL"))
	{
		intensity(object, arr[2]);
		position(object, arr[3]);

	}
//	if (s)
//	intensity(object, arr[2]);
//	(void) object;
//	(void) arr;
}