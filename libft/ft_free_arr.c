/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:09:13 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/19 16:44:12 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_arr(char **str, size_t n)
{
	while (n)
	{
		ft_safe_free(str[n]);
		n--;
	}
	ft_safe_free(str[n]);
	ft_safe_free(str);
	return (NULL);
}
