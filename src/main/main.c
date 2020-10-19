/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:26:06 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/19 13:01:01 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		param_validation(av[1]);
		if (!(data = (t_data*)malloc(sizeof(t_data))) ||
				(allocation(data, av[1]) != 0))
			free_error_exit("Malloc error\n", 1, data);
		read_setups(data, av[1]);
		grafic_connection(data, data->mlx);
		free_all(data);
	}
	else
		return (error_exit(NULL, 3));
	return (0);
}
