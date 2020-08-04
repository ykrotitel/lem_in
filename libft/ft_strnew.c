/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:08:34 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/26 17:46:14 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (size == __SIZE_T_MAXI__)
		return (NULL);
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str)
	{
		while (i != size + 1)
			str[i++] = '\0';
	}
	return (str);
}
