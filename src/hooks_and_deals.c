/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_deals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:22:07 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/21 00:20:49 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
int				close_window(t_data *data)
{
	free_all(data);
	exit(0);
}

//todo добавить ф-цию для кнопок, или не забыть удалить
int				buttons_press(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	else if (key == SPACE)
	{
		write(1,"SPACE\n", 6);
	}
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
	{
		write(1,"ARROW\n", 6);
	}
	return (0);
}
