/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:10:11 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:44:02 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t c)
{
	size_t i;

	i = 1;
	if (c == 0)
		return (0);
	while (((unsigned char *)buf1)[i - 1] == ((unsigned char *)buf2)[i - 1] &&
			i != c)
		i++;
	return (((unsigned char *)buf1)[i - 1] - ((unsigned char *)buf2)[i - 1]);
}
