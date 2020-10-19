/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:53:46 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/19 16:34:41 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	param_validation(char *param_name)
{
	if (!(ft_strcmp(param_name, "scene_1")) &&
		!(ft_strcmp(param_name, "scene_2")) &&
		!(ft_strcmp(param_name, "scene_3")) &&
		!(ft_strcmp(param_name, "scene_4")))
		error_exit(NULL, 3);
}
