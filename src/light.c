#include <rtv1.h>

static void	intensity(float *intensity, char *arr)
{
	*intensity = 0.2f;
	if (arr)
	{
		*intensity = coordinate(arr);
		if (*intensity < 0.0f)
			*intensity = 0.2f;
		else if (*intensity > 1.0f)
			*intensity = 1.0f;
	}
}

void	light(t_data *data, t_object *object, char **arr)
{
	static int i;
	i += 1;
	write(1, "light ", 6);
	write(1, &i, 1);
	write(1, "\n", 1);
	if (!(object->light_srcs[i - 1] = (t_light *)malloc(sizeof(t_light))))
		free_error_exit("Malloc error\n", 1, data);
	if (!ft_strcmp(arr[1], "AMBIENT"))
	{
		intensity(&object->light_srcs[i - 1]->intensity, arr[2]);
		object->light_srcs[i - 1]->type = AMBIENT;
	}
	if (!ft_strcmp(arr[1], "POINT"))
	{
		intensity(&object->light_srcs[i - 1]->intensity, arr[2]);
		position(&object->light_srcs[i - 1]->pos_or_dir, arr[3]);
		object->light_srcs[i - 1]->type = POINT;

	}
	if (!ft_strcmp(arr[1], "DIRECTIONAL"))
	{
		intensity(&object->light_srcs[i - 1]->intensity, arr[2]);
		position(&object->light_srcs[i - 1]->pos_or_dir, arr[3]);
		object->light_srcs[i - 1]->type = DIRECTIONAL;
	}
}