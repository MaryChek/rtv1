/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:59:58 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/08 23:49:02 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_cnt_digits(long long int num)
{
	size_t	count;

	count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}
