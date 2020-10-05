/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:57:36 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	beg;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	beg = 0;
	end = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		beg = ++i;
	end = beg;
	while (s[i++])
		if (s[i - 1] != ' ' && s[i - 1] != '\t' && s[i - 1] != '\n')
			end = i - 1;
	if (!(res = ft_strnew(end - beg + 1)))
		return (NULL);
	res = ft_strncpy(res, s + beg, end - beg + 1);
	return (res);
}
