/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_parse_ants_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:22:52 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 17:32:24 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

int		parse_ants_number(void)
{
	char	*line;
	int		ants_number;

	if (get_next_line(0, &line) <= 0)
	{
		ft_putstr("negative size of ants or NULL, it`s impossible\n");
		exit(INVALID_ANTS);
	}
	if (ft_strcmp(line, "ERROR") == 0)
	{
		ft_putstr("SECOND ERROR\n");
		exit(0);
	}
	if ((ants_number = ft_atoi(line)) <= 0)
	{
		ft_putstr("you forget about ants :c\n");
		ft_strdel(&line);
		exit(INVALID_ANTS);
	}
	ft_strdel(&line);
	return (ants_number);
}
