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
	{
		ft_putstr("usage: ./rtv1 [scene]\n");
		ft_putstr("\t\0scene:\0");
		ft_putstr("The following options are available:\n");
		ft_putstr("\t\tscene_1\t\tStage with plane\n");
		ft_putstr("\t\tscene_2\t\tStage with sphere\n");
		ft_putstr("\t\tscene_3\t\tStage with cylinder\n");
		ft_putstr("\t\tscene_4\t\tStage with cone\n");
	}
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
