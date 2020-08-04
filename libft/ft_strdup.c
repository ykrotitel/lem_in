/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:58:49 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:44:32 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*a;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	a = (char *)malloc(sizeof(char) * (i + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		a[i] = str[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
