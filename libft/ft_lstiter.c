/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:51:09 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 18:11:47 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *a;
	t_list *b;

	if (!lst || !f)
		return ;
	a = lst;
	while (a)
	{
		b = a->next;
		(*f)(a);
		a = b;
	}
}
