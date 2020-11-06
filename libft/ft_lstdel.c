/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:28:26 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/21 21:56:13 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*to_del;
	t_list	*next_to_del;

	to_del = *alst;
	while (to_del)
	{
		next_to_del = to_del->next;
		del(to_del->content, to_del->content_size);
		free(to_del);
		to_del = next_to_del;
	}
	*alst = NULL;
}
