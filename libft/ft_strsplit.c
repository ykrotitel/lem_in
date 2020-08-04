/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:37:17 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/26 20:37:25 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		split(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char		**make_strsplit(char const *s, char **a, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (j < split(s, c) && s[i] != c && s[i] != '\0')
		{
			a[j][k] = s[i];
			i++;
			k++;
		}
		if (k != 0)
		{
			a[j][k] = '\0';
			j++;
		}
		i++;
	}
	a[j] = NULL;
	return (a);
}

static void		*ft_free(char **a, int i)
{
	while (i != 0)
		free(a[i--]);
	return (NULL);
}

static char		**ft_strsplit_two(char const *s, char **a, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
		}
		if (j != 0)
		{
			if (!(a[k] = (char*)malloc(sizeof(char) * (j + 1))))
				ft_free(a, k);
			k++;
		}
		j = 0;
		i++;
	}
	return (make_strsplit(s, a, c));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**a;

	if (!s)
		return (NULL);
	if (!(a = (char**)malloc(sizeof(char*) * (split(s, c) + 1))))
		return (NULL);
	return (ft_strsplit_two(s, a, c));
}
