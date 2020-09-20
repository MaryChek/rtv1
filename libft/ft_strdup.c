/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:47 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 20:47:22 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s1;
	char	*s_cpy;
	size_t	k;

	i = 0;
	s1 = (char*)s;
	k = ft_strlen(s1);
	s_cpy = (char *)malloc(sizeof(char) * (k + 1));
	if (s_cpy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s_cpy[i] = s1[i];
		i++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}
