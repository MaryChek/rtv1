/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:11:11 by dtaisha           #+#    #+#             */
/*   Updated: 2020/09/19 17:11:14 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	symb;
	size_t	i;
	size_t	start;
	char	**str;

	i = 0;
	start = 0;
	if (!s || !(str = (char**)malloc(sizeof(char*) * (ft_cnt_w(s, c) + 1))))
		return (NULL);
	while (s[start])
	{
		if (s[start] == c)
			start++;
		else
		{
			symb = ft_cnt_l(s, c, start);
			if (!(str[i] = ft_strsub(s, start, symb)))
				return (ft_free_arr(str, i - 1));
			i++;
			start = symb + start;
		}
	}
	str[i] = NULL;
	return (str);
}
