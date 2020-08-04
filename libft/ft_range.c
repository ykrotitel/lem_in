/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:13:56 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/26 18:14:45 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int r;
	int *b;
	int *a;

	r = max - min;
	a = malloc(sizeof(int *) * r);
	if (!a)
		return (0);
	b = a;
	while (r != 0)
	{
		*a = min;
		a++;
		min++;
		r--;
	}
	a = b;
	return (a);
}
