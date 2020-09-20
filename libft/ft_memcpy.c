/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:02:42 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 20:58:32 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		tmp++;
		src1++;
		n--;
	}
	return (dest);
}
