/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:45:58 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/21 15:46:55 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*s_1;
	unsigned const char	*s_2;

	s_1 = (unsigned const char *)s1;
	s_2 = (unsigned const char *)s2;
	if (n == 0)
		return (0);
	while (*s_1 && *s_2 && *s_1 == *s_2 && n - 1)
	{
		s_1++;
		s_2++;
		n--;
	}
	return (*s_1 - *s_2);
}
