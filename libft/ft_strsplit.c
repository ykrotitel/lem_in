/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:45:31 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(char **arr, size_t i)
{
	if (i == 0)
		return ;
	while (--i)
		ft_strdel(&arr[i]);
	free(arr);
	arr = NULL;
}

static size_t	ft_len(char const *s, char c, size_t *n)
{
	size_t	len;

	len = 0;
	while (*(s + *n) && *(s + *n) == c)
		*n = *n + 1;
	while (*(s + *n) && *(s + *n) != c)
	{
		len++;
		*n = *n + 1;
	}
	return (len);
}

static size_t	ft_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			if (*s == '\0' || *s == c)
				size++;
		}
	}
	return (size);
}

static void		ft_make_split(char const *s, char **arr, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			j = 0;
			while (*s && *s != c)
				arr[i][j++] = *s++;
			i++;
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	size;
	size_t	n;
	size_t	i;
	char	**arr;

	if (!s || !c)
		return (NULL);
	i = 0;
	size = ft_size(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	n = 0;
	while (i < size)
		if (!(arr[i] = ft_strnew(ft_len(s, c, &n))))
		{
			ft_free(arr, i);
			return (NULL);
		}
		else
			i++;
	arr[i] = NULL;
	ft_make_split(s, arr, c);
	return (arr);
}
