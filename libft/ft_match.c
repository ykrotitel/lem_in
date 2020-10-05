/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:15:54 by acarlett          #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_match(char *str, char *str_)
{
	if (*str_ != '\0' && *str == '*')
		return (ft_match(str + 1, str_) || ft_match(str, str_ + 1));
	if (*str == '\0' && *str_ == '*')
		return (ft_match(str, str_ + 1));
	if (*str == *str_ && *str != '\0' && *str_ != '\0')
		return (ft_match(str_ + 1, str + 1));
	if (*str == *str_ && *str == '\0' && *str_ == '\0')
		return (1);
	return (0);
}
