/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_parse_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:37:30 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 18:32:53 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void	add_link(char *line, t_map_data *data)
{
	char	**splitted_line;
	int		index1;
	int		index2;

	if ((splitted_line = ft_strsplit(line, '-')) == NULL)
	{
		write(1, "1\n", 2);
		ft_strdel(&line);
		free_data(data);
		exit(MALLOC_ERROR);
	}
	index1 = return_room_index(splitted_line[0], data->rooms);
	index2 = return_room_index(splitted_line[1], data->rooms);
	if ((index1 == -1) || (index2 == -1))
		free_delete_exit(&line, splitted_line, INVALID_LINKS, data);
	fill_adjacency_matrix(index1, index2, &(data->adjacency_matrix),
													data->rooms_number);
	delete_splitted_line(&splitted_line);
}

void	parse_links(t_map_data *data)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "ERROR") == 0)
			free_strdel_exit(3, data, line, INVALID_LINKS);
		if (line[0] == '\0')
			return (ft_strdel(&line));
		while (line && !ft_strncmp(line, "#", 1))
		{
			if (check_if_comment(&line, data) == PARSE_ERROR)
				free_strdel_exit(3, data, line, INVALID_ROOMS);
			if (!line)
				return ;
		}
		if (line[0] == '\0' || line[0] == '\n')
		{
			ft_strdel(&line);
			return ;
		}
		add_link(line, data);
		ft_strdel(&line);
	}
}
