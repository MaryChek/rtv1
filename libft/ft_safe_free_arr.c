/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:09:13 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/19 16:43:39 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_safe_free_arr(char **arr)
{
	char		**cpy;
	size_t		i;

	cpy = arr;
	i = 0;
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
