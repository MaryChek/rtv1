/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:53:34 by dtaisha           #+#    #+#             */
/*   Updated: 2019/09/22 00:02:51 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*start;
	t_list	*fresh;

	tmp = f(lst);
	if (((lst == NULL) ||
				(fresh = ft_lstnew(tmp->content, tmp->content_size)) == NULL))
		return (NULL);
	start = fresh;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if ((fresh->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		{
			ft_free_list(start);
			return (NULL);
		}
		fresh = fresh->next;
		lst = lst->next;
	}
	return (start);
}
