/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:55:51 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = -1;
	str = (char*)s;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			k = i;
		i++;
	}
	if (str[i] == c)
		k = i;
	if (k != -1)
		return (&str[k]);
	return (NULL);
}
