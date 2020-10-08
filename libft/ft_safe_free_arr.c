/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:09:13 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/07 12:03:15 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_safe_free_arr(char **arr)
{
	char		**cpy;

	cpy = arr;
	size_t i = 0;
	if (arr)
	{
		while (*cpy != NULL)
		{
			i++;
			cpy++;
		}
		if (*arr)
			ft_free_arr(arr, i - 1);
	}
}
