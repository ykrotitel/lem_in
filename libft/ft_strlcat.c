/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:30:54 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:45:31 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t c)
{
	size_t i;
	size_t y;
	size_t j;

	i = 0;
	j = 0;
	y = 0;
	while (src[y] != '\0')
		y++;
	while (dst[i] != '\0')
		i++;
	if (c <= i)
		y = y + c;
	else
		y = y + i;
	while (src[j] && (i + 1) < c)
	{
		dst[i] = (char)src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (y);
}
