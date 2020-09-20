/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:02:34 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/29 02:43:10 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_read(const int fd, char **arr)
{
	char			buff[BUFF_SIZE + 1];
	int				was_read;
	char			*tmp;

	if ((was_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[was_read] = '\0';
		tmp = ft_strjoin(*arr, buff);
		ft_strdel(arr);
		*arr = tmp;
		return (1);
	}
	return (0);
}

static void			ft_write(char **line, char **arr)
{
	int				len;
	char			*tmp;

	len = 0;
	while ((*arr)[len] != '\n' && (*arr)[len] != '\0')
		len++;
	if ((*arr)[len] == '\n')
	{
		*line = ft_strsub(*arr, 0, len);
		tmp = ft_strdup(*arr + len + 1);
		ft_strdel(arr);
		*arr = tmp;
	}
	else
	{
		*line = ft_strsub(*arr, 0, len);
		ft_strdel(arr);
	}
}

int					get_next_line(const int fd, char **line)
{
	static char		*arr[256];
	int				was_read;
	char			buff[1];

	was_read = 1;
	if (fd < 0 || fd > 256 || !line || read(fd, buff, 0)
	|| BUFF_SIZE < 1)
		return (-1);
	if (!arr[fd])
		arr[fd] = ft_strnew(1);
	while (was_read > 0 && ((ft_strchr(arr[fd], '\n') == 0)))
		was_read = ft_read(fd, &arr[fd]);
	if (!arr[fd])
		return (-1);
	if (was_read == 0 && !*arr[fd])
	{
		ft_strdel(&arr[fd]);
		return (0);
	}
	ft_write(line, &arr[fd]);
	if (!*line || (!arr[fd] && was_read > 0))
		return (-1);
	return (1);
}
