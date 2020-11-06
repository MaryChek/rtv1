/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:20:42 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/17 21:20:16 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_num(int num)
{
	int				len;

	if (num <= 0)
		len = 1;
	else
		len = 0;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	int				len;

	num = 0;
	len = ft_count_num(n);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	if (n < 0)
	{
		num = -n;
		str[0] = '-';
	}
	else if (n > 0)
		num = n;
	else if (n == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
