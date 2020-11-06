/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:46:17 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 20:47:37 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*s_1;
	unsigned const char	*s_2;

	s_1 = (unsigned const char *)s1;
	s_2 = (unsigned const char *)s2;
	while (*s_1 && *s_2 && *s_1 == *s_2)
	{
		s_1++;
		s_2++;
	}
	return (*s_1 - *s_2);
}
