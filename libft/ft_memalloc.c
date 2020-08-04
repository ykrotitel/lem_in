/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:11:22 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/25 21:49:24 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *a;

	a = NULL;
	if (!(a = malloc(sizeof(void *) * size)))
		return (NULL);
	ft_bzero(a, size);
	return (a);
}
