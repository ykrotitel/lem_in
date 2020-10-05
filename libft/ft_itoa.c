/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:21:23 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static int		ft_num(int n)
{
	int num;

	if (n < 0)
		num = n % 10 * -1 + 48;
	else
		num = n % 10 + 48;
	return (num);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_len(n) - 1;
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	while (n > 9 || n < -9)
	{
		str[len--] = ft_num(n);
		n = n / 10;
	}
	str[len] = ft_num(n);
	if (n < 0)
		str[len - 1] = '-';
	return (str);
}
