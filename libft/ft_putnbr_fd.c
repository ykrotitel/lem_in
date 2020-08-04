/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:13:22 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 18:39:10 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	a;
	int		b;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (nb < -2000000000)
		{
			ft_putchar_fd('2', fd);
			nb = nb + 2000000000;
		}
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	b = nb % 10;
	a = '0' + b;
	ft_putchar_fd(a, fd);
}
