/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:37:30 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/30 18:51:15 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_link(char *line, t_data *data)
{
	char			**splitted_line;
	t_room_data		*room1;
	t_room_data		*room2;

	if ((splitted_line = ft_strsplit(line, '-')) == NULL)
		exit(free_line_exit(&line, data, MALLOC_ERROR));
	if (size_of_matrix_rows(splitted_line) != 2)
		exit(free_line_and_splitted_exit(&line,
				&splitted_line, data, INVALID_LINKS));
	room1 = return_room(splitted_line[0], data->hash_table);
	room2 = return_room(splitted_line[1], data->hash_table);
	if ((room1 == NULL) || (room2 == NULL))
		exit(free_line_and_splitted_exit(&line,
				&splitted_line, data, INVALID_LINKS));
	fill_adjacency_matrix(room1,
						room2,
						&(data->adjacency_matrix),
						data->id_counter);
	delete_splitted_line(&splitted_line);
}

void	parse_links(t_data *data)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		print_map_line(line);
		if (line[0] == '\0')
			exit(free_line_exit(&line, data, INVALID_LINKS));
		while (line && !ft_strncmp(line, "#", 1))
		{
			if (check_if_comment(&line, data) == PARSE_ERROR)
				exit(free_line_exit(&line, data, INVALID_LINKS));
			if (!line)
				return ;
		}
		add_link(line, data);
		ft_strdel(&line);
	}
}
