/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 22:44:32 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (!*needle || needle == haystack)
		return ((char*)haystack);
	i = 0;
	while (*haystack)
	{
		while (haystack[i] == needle[i] && needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char*)haystack);
		i = 0;
		haystack++;
	}
	return (NULL);
}
