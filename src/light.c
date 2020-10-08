#include <rtv1.h>

static void		intensity(double *intensity, char *arr)
{
	if (arr)
	{
		*intensity = coordinate(arr);
		if (*intensity < 0.0 || *intensity >= 1.0)
			*intensity = DEFAULT_INTENSIVITY;
	}
}

void			light(t_data *data, t_object *object, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	printf("light %d\n", i);
	len = ft_arrlen(arr);
	if (!ft_strcmp(arr[1], "AMBIENT"))
		object->light_srcs[i - 1].type = AMBIENT;
	if (!ft_strcmp(arr[1], "POINT"))
		object->light_srcs[i - 1].type = POINT;
	if (!ft_strcmp(arr[1], "DIRECTIONAL"))
		object->light_srcs[i - 1].type = DIRECTIONAL;
	if (len > 2)
		intensity(&object->light_srcs[i - 1].intensity, arr[2]);
	else
		intensity(&object->light_srcs[i - 1].intensity, NULL);
	if (len > 3)
		position(&object->light_srcs[i - 1].pos_or_dir, arr[3], data);
	else
		position(&object->light_srcs[i - 1].pos_or_dir, NULL, data);
}