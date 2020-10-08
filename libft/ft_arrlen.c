/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:28:33 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/08 12:19:22 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		i = 1;
		while (*arr)
		{
			i++;
			arr++;
		}
		return (i - 1);
	}
	return (i);
}
