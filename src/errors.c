/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:48:32 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/21 00:02:44 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
//todo нужно прописать юзаддж
int		error_exit(char *text, int code)
{
	if (code == 3)
	{
		ft_putstr("usage: ./rtv1 [scine]\n");
		ft_putstr("\t\0scine:\0");
		ft_putstr(" use numbers or names:\n");
		ft_putstr("\t\ttest\n\t\ttest\n");
		ft_putstr("\t\ttest\n");
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
