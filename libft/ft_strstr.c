/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:38:57 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:46:00 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[0])
		{
			while ((str1[i] == str2[j]) && (str2[j] != '\0'))
			{
				i++;
				j++;
			}
			if (str2[j] == '\0')
				return ((char*)(&str1[i - j]));
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (0);
}
