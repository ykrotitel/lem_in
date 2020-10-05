/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_splitted_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:54:38 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/01 17:54:38 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		delete_splitted_line(char ***splitted_line)
{
	int i;

	i = 0;
	while ((*splitted_line)[i])
	{
		free((*splitted_line)[i]);
		(*splitted_line)[i] = NULL;
		i++;
	}
	free(*splitted_line);
	splitted_line = NULL;
}