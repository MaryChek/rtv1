/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:09:13 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/02 11:03:26 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_arr(char **str, size_t n)
{
	while (n)
	{
		free(str[n]);
		n--;
	}
	ft_strdel(str);
	if (str)
		free(str);
	return (NULL);
}
