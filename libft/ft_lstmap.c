/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:59:48 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 18:11:25 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *a;
	t_list *b;
	t_list *c;

	if (!lst || !f)
		return (NULL);
	a = lst;
	b = f(a);
	c = b;
	while (a->next)
	{
		a = a->next;
		b->next = f(a);
		b = b->next;
	}
	return (c);
}
