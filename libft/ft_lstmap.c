/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:57:21 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list *lst)
{
	if (lst->next)
		ft_free(lst->next);
	free(lst->content);
	free(lst);
	lst = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*list;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	if (!(list = ft_lstnew(new->content, new->content_size)))
		return (NULL);
	begin_list = list;
	lst = lst->next;
	while (lst)
	{
		new = (*f)(lst);
		if (!(list->next = ft_lstnew(new->content, new->content_size)))
		{
			ft_free(begin_list);
			return (NULL);
		}
		lst = lst->next;
		list = list->next;
	}
	return (begin_list);
}
