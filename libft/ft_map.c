/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:21:17 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/26 18:21:56 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *result;
	int i;
	int *a;

	i = 0;
	result = (int *)malloc(sizeof(*result) * length);
	if (!(int *)malloc(sizeof(*result) * length))
		return (NULL);
	a = result;
	while (i < length)
	{
		*result = f(*tab);
		result++;
		i++;
		tab++;
	}
	return (a);
}
