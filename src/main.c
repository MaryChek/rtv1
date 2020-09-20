/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:26:06 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/19 16:51:38 by dtaisha          ###   ########.fr       */
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
//		read_setups(); там будем считывать файл из аргументов (название файла, и указатель на структурку куда вностить настройки)
		graf_connection(graf, av[1]);
		free_all(graf);
	}
	else
		return (error_exit(NULL, 3));
	return (0);
}
