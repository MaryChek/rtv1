/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:09:13 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/07 22:58:57 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_arr(char **str, size_t n)
{
	while (n)
	{
		ft_safe_free(str[n]);
		n--;
	}
	ft_safe_free(str[n]);
	ft_safe_free(str);
	return (NULL);
}
