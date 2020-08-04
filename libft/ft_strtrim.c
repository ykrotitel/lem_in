/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:59:34 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/25 22:23:39 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*ft_abort(void)
{
	char	*abort;

	abort = NULL;
	abort = (char*)malloc(sizeof(char) * 1);
	*abort = '\0';
	return (abort);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;
	unsigned int	i;

	start = 0;
	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_abort());
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	while (s[i] != '\0')
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i != 0)
		i--;
	i++;
	if (i <= start)
		return (ft_abort());
	len = i - start;
	return (ft_strsub(s, start, len));
}
