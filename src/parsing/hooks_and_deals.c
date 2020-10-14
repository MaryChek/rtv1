/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_deals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:22:07 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/10 21:04:07 by rtacos           ###   ########.fr       */
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
	return (0);
}
