/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:59:50 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:01:19 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;

	i = -1;
	j = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[++i] != '\0' && i < n)
	{
		if (str1[i] == str2[0])
		{
			while ((str1[i] == str2[j]) && (str2[j] != '\0') && i < n)
			{
				i++;
				j++;
			}
			if (str2[j] == '\0')
				return ((char *)(&str1[i - j]));
		}
		i = i - j;
		j = 0;
	}
	return (0);
}
