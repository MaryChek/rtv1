/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:53:46 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/23 21:32:38 by dtaisha          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int end_is_invalid(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		i = ft_strlen(str) - 1;
		if (str[i] && str[i] == 'v' && str[i - 1] == 't'
			&& str[i - 2] == 'r' && str[i - 3] == '.')
			return(0);
	}
	return(1);
}

void	param_validation(char *param_name)
{
	char	*p_name;
	int		flag;

	flag = 0;
	if (*param_name)
	{
		p_name = param_name;
		while(*p_name)
		{
			if(*p_name == '.')
				flag++;
			p_name++;
		}
		if (flag != 1 || end_is_invalid(param_name))
			error_exit("Error: Invalid file extension\n\tValid example: "
			  "some_name.rtv\n", 1);
	}
	else
		error_exit(NULL, 3);
}
