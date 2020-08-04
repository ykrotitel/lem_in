/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:48:39 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:43:19 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int n, size_t s)
{
	size_t i;

	i = 0;
	while (i != s)
	{
		if (((unsigned char *)dest) == ((unsigned char *)src))
			break ;
		if (*((unsigned char *)src) == (unsigned char)n)
		{
			*((unsigned char *)dest++) = (unsigned char)n;
			return ((unsigned char *)dest);
		}
		*((unsigned char *)dest++) = *((unsigned char *)src++);
		i++;
	}
	return (NULL);
}
