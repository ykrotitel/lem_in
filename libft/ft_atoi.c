/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:31:14 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 19:46:27 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cherkes(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == '\n' ||
		str[i] == '\f')
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	return (i);
}

static int		ft_check_minus(const char *str, long i)
{
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (-1);
	return (1);
}

int				ft_atoi(const char *str)
{
	long i;
	long atoi;
	long m;

	i = -1;
	atoi = 0;
	i = cherkes(str);
	if ((m = ft_check_minus(str, i)) == -1)
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '\0'))
	{
		atoi *= 10;
		if ((atoi + (str[i] - '0')) < atoi && m == 1)
			return (-1);
		if ((atoi + (str[i] - '0')) < atoi && m == -1)
			return (0);
		atoi = atoi + (str[i] - '0');
		i++;
	}
	return ((int)(atoi *= m));
}
