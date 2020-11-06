/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:16:58 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 20:52:24 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*src1;
	char	*dst1;

	if (dst == NULL && src == NULL)
		return (dst);
	dst1 = (char*)dst;
	src1 = (char*)src;
	if (src1 > dst1)
		while (n--)
			*dst1++ = *src1++;
	else if (src1 < dst1)
		while (n--)
			*(dst1 + n) = *(src1 + n);
	return (dst);
}
