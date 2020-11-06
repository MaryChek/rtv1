/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:50:10 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 19:49:58 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*src_cpy;
	int		i;

	i = 0;
	src_cpy = (char*)src;
	while (src_cpy[i] != '\0' && n--)
	{
		dest[i] = src_cpy[i];
		i++;
	}
	if (n > 0 && src_cpy[i] == '\0')
		while (n--)
			dest[i++] = '\0';
	return (dest);
}
