/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:59:04 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 19:53:06 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	start;

	end = 0;
	start = 0;
	if (s == NULL)
		return (NULL);
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t') &&
			s[start])
		start++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end >= start)
		end--;
	return (ft_strsub(s, start, (end - start + 1)));
}
