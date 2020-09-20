/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:59:58 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/21 16:02:10 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_cnt_l(char const *s, char c, size_t len)
{
	size_t	count;

	count = 0;
	if (s != NULL)
	{
		while (s[len] && s[len] != c)
		{
			len++;
			count++;
		}
	}
	return (count);
}
