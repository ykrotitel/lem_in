/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:40:41 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/26 17:48:05 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		getstring(int n)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = n;
	while (tmp / 10 != 0 && tmp % 10 != 0)
	{
		tmp = tmp / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i + 1);
}

static char		*backwards(char *temp, int n)
{
	int		tmp;

	tmp = n;
	*temp++ = '\0';
	while (n / 10 != 0 || n % 10 != 0)
	{
		if (n % 10 < 0)
			*temp++ = -1 * (n % 10) + '0';
		else
			*temp++ = (n % 10) + '0';
		n = n / 10;
	}
	--temp;
	if (tmp < 0)
		*(++temp) = '-';
	return (temp);
}

char			*ft_itoa(int n)
{
	char	*nbr;
	char	*temp;
	char	*temp2;
	int		tmp;

	nbr = NULL;
	temp = NULL;
	tmp = getstring(n);
	nbr = ft_strnew(tmp);
	temp = ft_strnew(tmp);
	temp2 = nbr;
	if (!nbr)
		return (NULL);
	if (n == 0)
		*nbr++ = '0';
	temp = backwards(temp, n);
	while (*temp != '\0')
		*nbr++ = *temp--;
	*nbr = '\0';
	return (temp2);
}
