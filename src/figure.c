#include <rtv1.h>

void			sphere(t_data *data, t_object *object, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	printf("sphere %d\n", i);
	len = ft_arrlen(arr);
	if (len > 1)
		position(&object->sph_objs[i - 1].center, arr[1], data);
	else
		position(&object->sph_objs[i - 1].center, NULL, data);
	object->sph_objs[i - 1].rad = (len > 2) ? coordinate(arr[2]): DEFAULT_R;
	if (len > 3)
		color(&object->sph_objs[i - 1].color, arr[3]);
	else
		color(&object->sph_objs[i - 1].color, NULL);

}

void			cylinder(t_data *data, t_object *object, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	printf("cylinder %d\n", i);
	len = ft_arrlen(arr);
	if (len > 1)
		position(&object->cyln_objs[i - 1].center, arr[1], data);
	else
		position(&object->cyln_objs[i - 1].center, NULL, data);
	object->cyln_objs[i - 1].rad = (len > 2)? coordinate(arr[2]): DEFAULT_R;
	if (len > 3)
		color(&object->cyln_objs[i - 1].color, arr[3]);
	else
		color(&object->cyln_objs[i - 1].color, NULL);
	if (len > 4)
		position(&object->cyln_objs[i - 1].rotation, arr[4], data);
	else
		position(&object->cyln_objs[i - 1].rotation, NULL, data);
}

void			cone(t_data *data, t_object *object, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	printf("cone %d\n", i);
	len = ft_arrlen(arr);
	if (len > 1)
		position(&object->cone_objs[i - 1].center, arr[1], data);
	else
		position(&object->cone_objs[i - 1].center, NULL, data);
	if (len > 2)
		color(&object->cone_objs[i - 1].color, arr[2]);
	else
		color(&object->cone_objs[i - 1].color, NULL);
	if (len > 3)
		position(&object->cone_objs[i - 1].rotation, arr[3], data);
	else
		position(&object->cone_objs[i - 1].rotation, NULL, data);
	object->cone_objs[i - 1].angle = (len > 3)? coordinate(arr[4]): DEFAULT_A;
}

void			plane(t_data *data, t_object *object, char **arr)
{
	static int	i;
	size_t		len;

	i += 1;
	printf("plane %d\n", i);
	len = ft_arrlen(arr);
	if (len > 1)
		position(&object->plane_objs[i - 1].center, arr[1], data);
	else
		position(&object->plane_objs[i - 1].center, NULL, data);
	if (len > 2)
		color(&object->plane_objs[i - 1].color, arr[2]);
	else
		color(&object->plane_objs[i - 1].color, NULL);
	if (len > 3)
		position(&object->plane_objs[i - 1].rotation, arr[3], data);
	else
		position(&object->plane_objs[i - 1].rotation, NULL, data);
}