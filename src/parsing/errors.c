/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:48:32 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/19 16:34:50 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		error_exit(char *text, int code)
{
	if (code == 3)
		ft_putstr("usage: ./rtv1 [file_name.rtv]\n");
	else
		ft_putstr(text);
	exit(code);
}

void	free_error_exit(char *text, int code, t_data *data)
{
	ft_putstr(text);
	free_all(data);
	exit(code);
}
