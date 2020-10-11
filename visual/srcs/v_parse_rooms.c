/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_parse_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:27:31 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/06 16:03:20 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

t_room_data		*create_room(char *line, t_room_type room_type,
										t_map_data *for_free)
{
	char		**splitted_line;
	t_room_data	*room_data;
	t_point		point;

	if ((splitted_line = ft_strsplit(line, ' ')) == NULL)
	{
		ft_strdel(&line);
		free_data(for_free);
		exit(MALLOC_ERROR);
	}
	if (size_of_matrix_rows(splitted_line) != 3)
		free_strdel_exit(3, for_free, line, PARSE_ERROR);
	point.x = ft_atoi(splitted_line[1]);
	point.y = ft_atoi(splitted_line[2]);
	if (point.x < 0 || point.y < 0)
		free_delete_exit(&line, splitted_line, INVALID_ROOMS, for_free);
	if ((room_data = malloc(sizeof(t_room_data))) == NULL)
		free_delete_exit(&line, splitted_line, MALLOC_ERROR, for_free);
	if ((room_data->name = ft_strdup(splitted_line[0])) == NULL)
		free_delete_exit(&line, splitted_line, MALLOC_ERROR, for_free);
	room_data->coords = point;
	room_data->type = room_type;
	delete_splitted_line(&splitted_line);
	return (room_data);
}

void			parse_rooms(t_map_data *data)
{
	char		*line;
	t_room_type room_type;

	room_type = DEFAULT;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '\0' || (ft_strcmp(line, "ERROR") == 0))
			free_strdel_exit(1, data, line, INVALID_ROOMS);
		if (ft_strchr(line, '-') != NULL)
		{
			add_link(line, data);
			ft_strdel(&line);
			break ;
		}
		while (!ft_strncmp(line, "#", 1))
		{
			room_type = check_if_comment(&line, data);
			handle_room_type(data, room_type, line, INVALID_LINKS);
		}
		push_back_room(&data->rooms, create_room(line, room_type, data),
											data, &line);
		room_type = DEFAULT;
		ft_strdel(&line);
	}
}
