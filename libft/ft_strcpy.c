/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:30:43 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 20:43:52 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*src_cpy;
	int		i;

	i = 0;
	src_cpy = (char*)src;
	while (src_cpy[i] != '\0')
	{
		dest[i] = src_cpy[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
