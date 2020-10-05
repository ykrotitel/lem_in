/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:34:59 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/30 21:07:04 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				size_of_matrix_rows(char **matrix)
{
	int counter;

	counter = 0;
	while (matrix[counter] != NULL)
	{
		if (!matrix[counter][0])
			return (-1);
		counter++;
	}
	return (counter);
}

t_room_type		check_if_comment(char **line, t_data *data)
{
	t_room_type type;

	type = DEFAULT;
	if ((*line)[0] == '#')
	{
		if (!ft_strcmp(*line, "##start"))
			type = (data->start == -1) ? START : PARSE_ERROR;
		if (!ft_strcmp(*line, "##end"))
			type = (data->end == -1) ? END : PARSE_ERROR;
		ft_strdel(line);
		if (get_next_line(0, line) < 0)
			exit(free_data_exit(data, MALLOC_ERROR));
		if (*line)
		{
			ft_putstr(*line);
			ft_putchar('\n');
			if ((*line)[0] == '#' && (type == START || type == END))
				return (PARSE_ERROR);
		}
	}
	return (type);
}
