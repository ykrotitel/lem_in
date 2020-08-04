/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:55:19 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/25 22:17:45 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*a;
	char			*b;
	unsigned int	i;

	a = NULL;
	b = NULL;
	i = start;
	if (!s)
		return (NULL);
	if (!(a = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	b = a;
	while (i != (unsigned int)len + start)
	{
		*b++ = s[i];
		i++;
	}
	*b = '\0';
	return (a);
}
