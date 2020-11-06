/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:58:37 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 21:01:25 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*tmp;
	char	*src1;

	if (dest == NULL && src == NULL)
		return (dest);
	src1 = (char*)src;
	tmp = (char*)dest;
	while (n)
	{
		*tmp = *src1;
		if (*src1 == (char)c)
			return (++tmp);
		tmp++;
		src1++;
		n--;
	}
	return (NULL);
}
