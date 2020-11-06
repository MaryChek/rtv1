/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:30:30 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 21:00:51 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src1;
	size_t	i;

	i = 0;
	src1 = (char*)s;
	while (i < n)
	{
		if (src1[i] == (char)c)
			return (&src1[i]);
		i++;
	}
	return (NULL);
}
