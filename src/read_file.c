#include "rtv1.h"
void		validate_fd(int fd, t_data *data)
{
	if (fd < 0)
		free_error_exit("Error: file doesn't exist\n", 1, data);
	if (fd == 0 || read(fd, NULL, 0) == -1)
		free_error_exit("Error: can't read file\n", 1, data);
}

void ft_safe_free_arr(char **arr)
{
	char **cpy;
	cpy = arr;
	size_t i = 0;
//
//	if(arr)
//	{
//		size_t i = 0;
//		while (arr[i])
//			free(arr[i]);
////		ft_strdel(arr);
//		free(arr);
//	}
	if (arr)
	{
		while (*cpy != NULL)
		{
			i++;
			cpy++;
		}
		if (*arr)
			ft_free_arr(arr, i - 1);
	}
}
//todo нужно проверить при разделении пробелами а не табами
//todo нужно подумать как реализовать подсчет и реаллокацию нескольких фигур

static void		read_line(t_data *data, t_object *object, char *line)
{
	char **arr;
	if (!(arr = ft_strsplit(line, '\t')))
		free_error_exit("Malloc", 1, data);
	if (!ft_strcmp(arr[0], "sphere"))
		sphere(data, object, arr);
	else if (!ft_strcmp(arr[0], "cylinder"))
		cylinder(data, object, arr);
	else if (!ft_strcmp(arr[0], "cone"))
		cone(data, object, arr);
	else if (!ft_strcmp(arr[0], "plane"))
		plane(data, object, arr);
	else if (!ft_strcmp(arr[0], "camera"))
		camera(object, arr);
	else if (!ft_strcmp(arr[0], "light"))
		if (!ft_strcmp(arr[1], "AMBIENT") || !ft_strcmp(arr[1], "POINT") ||
				!ft_strcmp(arr[1], "DIRECTIONAL"))
			light(data, object, arr);

	ft_safe_free_arr(arr);
	(void) object;
}

void		read_setups(t_data *data, char *name)
{
	int		fd = 0;
	char	*line;
	fd = open(name, O_RDONLY);
	validate_fd(fd, data);
	while (get_next_line(fd, &line))
	{
		if(line[0] != '#' && ft_strlen(line) > 10)
		{
			read_line(data, data->p_object, line);
		}
		ft_safe_free(line);
	}
	close(fd);
}