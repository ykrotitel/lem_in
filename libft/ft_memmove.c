/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:20:44 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:43:43 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*sr;
	char	*ds;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	sr = (char*)src;
	ds = (char*)dst;
	if (sr < ds)
		while ((int)(--len) >= 0)
			*(ds + len) = *(sr + len);
	else
		while (i < len)
		{
			*(ds + i) = *(sr + i);
			i++;
		}
	return (dst);
}
