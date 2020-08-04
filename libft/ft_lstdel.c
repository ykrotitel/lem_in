/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:05:21 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 18:13:19 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *a;
	t_list *b;

	if (!*alst || !alst || !del)
		return ;
	a = (*alst);
	while (a)
	{
		b = a->next;
		ft_lstdelone(&a, del);
		a = b;
	}
	*alst = NULL;
}
