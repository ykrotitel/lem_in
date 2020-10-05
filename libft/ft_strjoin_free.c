/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:11:52 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int fl1, int fl2)
{
	char *s;

	if (!s1)
	{
		s1 = ft_strnew(0);
		fl1 = 1;
	}
	if (!s2)
	{
		s2 = ft_strnew(0);
		fl2 = 1;
	}
	s = ft_strjoin(s1, s2);
	if (fl1)
		ft_strdel(&s1);
	if (fl2)
		ft_strdel(&s2);
	return (s);
}
