/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:26:06 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/21 09:25:11 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		param_validation(av[1]); // защита от дурачков на вводимые параметры
		if (!(data = (t_data*)malloc(sizeof(t_data))) ||
				(allocation(data) != 0))
			free_error_exit("Malloc error\n", 1, data);
		read_setups(data->object_ptr, av[1]); //там будем считывать файл из аргументов (название файла, и указатель на структурку куда вностить настройки)
		grafic_connection(data, data->mlx_ptr);
		free_all(data);
	}
	else
		return (error_exit(NULL, 3));
	return (0);
}
