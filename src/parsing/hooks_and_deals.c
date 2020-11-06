/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_deals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:22:07 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/19 16:31:52 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				close_window(t_data *data)
{
	free_all(data);
	exit(0);
}

int				buttons_press(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	return (0);
}
