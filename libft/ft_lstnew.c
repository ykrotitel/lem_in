/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:22:34 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 18:15:10 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *a;

	if (!(a = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		a->content = NULL;
		a->content_size = 0;
	}
	else
	{
		if (!(a->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(a->content, (void*)content, content_size);
		a->content_size = content_size;
	}
	a->next = NULL;
	return (a);
}
