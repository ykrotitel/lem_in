/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:25:14 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:44:56 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t c)
{
	size_t i;

	i = 0;
	while (i != c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i != c)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
