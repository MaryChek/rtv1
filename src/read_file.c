#include "rtv1.h"
static void		validate_fd(int fd, t_data *data)
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
	while (*cpy != NULL)
	{
		i++;
		cpy++;
	}
	ft_free_arr(arr, i - 1);
}

void		read_line(t_object *object, char *line)
{
	char **arr;
	arr = ft_strsplit(line, '\t');
	if (!ft_strcmp(arr[0], "sphere"))
		sphere(object, arr);
	else if (!ft_strcmp(arr[0], "cylinder"))
		cylinder(object, arr);
	else if (!ft_strcmp(arr[0], "cone"))
		cone(object, arr);
	else if (!ft_strcmp(arr[0], "plane"))
		plane(object, arr);
	else if (!ft_strcmp(arr[0], "camera"))
		camera(object, arr);
	else if (!ft_strcmp(arr[0], "light"))
		light(object, arr);
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
			read_line(data->object_ptr, line);
		}
		ft_safe_free(line);
	}
	close(fd);
}