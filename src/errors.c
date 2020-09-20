/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:48:32 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/19 16:50:25 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#todo нужно прописать юзаддж
int		error_exit(char *text, int code)
{
	if (code == 3)
	{
		ft_putstr("usage: ./rtv1 [scine]\n");
		ft_putstr("\t\0fractals:\0");
		ft_putstr(" use numbers or names:\n");
		ft_putstr("\t\t1 - Mandelbrot\n\t\t2 - Ship\n");
		ft_putstr("\t\t3 - Julia\n");
	}
	else
		ft_putstr(text);
	exit(code);
}

void	free_error_exit(char *text, int code, t_data *data)
{
	ft_putstr(text);
	free_all(graf);
	exit(code);
}
