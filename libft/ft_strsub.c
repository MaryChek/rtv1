/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:45:52 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 19:55:30 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*subs;

	i = 0;
	if (s != NULL)
		if ((subs = (char*)malloc(sizeof(char) * (len + 1))) != NULL)
		{
			while (len--)
			{
				subs[i] = s[start + i];
				i++;
			}
			subs[i] = '\0';
			return (subs);
		}
	return (NULL);
}
