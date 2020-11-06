/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tear_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:45:27 by dtaisha           #+#    #+#             */
/*   Updated: 2020/10/11 20:12:36 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			free_all(t_data *data)
{
	if (data)
	{
		ft_safe_free(data->mlx);
		ft_safe_free(data->p_object->sph_objs);
		ft_safe_free(data->p_object->cone_objs);
		ft_safe_free(data->p_object->cyln_objs);
		ft_safe_free(data->p_object->plane_objs);
		ft_safe_free(data->p_object->light_srcs);
		ft_safe_free(data->p_object);
		ft_safe_free(data);
	}
}
