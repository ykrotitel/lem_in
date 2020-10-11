/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:27:31 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 18:32:09 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*handle_room(char **line, t_data *data)
{
	char		**splitted_line;
	char		*room_name;

	if ((splitted_line = ft_strsplit(*line, ' ')) == NULL)
		exit(free_line_exit(line, data, MALLOC_ERROR));
	if (size_of_matrix_rows(splitted_line) != 3
		|| splitted_line[0][0] == 'L'
		|| (ft_atoi(splitted_line[1]) < 0
			|| ft_atoi(splitted_line[2]) < 0))
		exit(free_line_and_splitted_exit(line,
				&splitted_line, data, INVALID_ROOMS));
	if ((room_name = ft_strdup(splitted_line[0])) == NULL)
		exit(free_line_and_splitted_exit(line,
				&splitted_line, data, INVALID_ROOMS));
	delete_splitted_line(&splitted_line);
	return (room_name);
}

t_room_data		*create_room(char **line, t_room_type room_type, t_data *data)
{
	t_room_data	*room_data;

	if ((room_data = malloc(sizeof(t_room_data))) == NULL)
		exit(free_line_exit(line,
				data, MALLOC_ERROR));
	room_data->name = handle_room(line, data);
	room_data->type = room_type;
	room_data->input_id = -1;
	room_data->output_id = -1;
	return (room_data);
}

static void		handle_comment(char **line, t_data *data, t_room_type *type)
{
	*type = check_if_comment(line, data);
	if (!(*line))
		exit(free_line_exit(line, data, INVALID_ROOMS));
	if (*type == PARSE_ERROR)
		exit(free_line_exit(line, data, INVALID_ROOMS));
	if (*type == START)
		data->start = data->id_counter;
	if (*type == END)
		data->end = data->id_counter;
}

void			parse_rooms(t_data *data)
{
	char		*line;
	t_room_type room_type;

	room_type = DEFAULT;
	while (get_next_line(0, &line) > 0)
	{
		print_map_line(line);
		if (line[0] == '\0')
			exit(free_line_exit(&line, data, INVALID_ROOMS));
		while (line[0] == '#')
			handle_comment(&line, data, &room_type);
		if (ft_strchr(line, '-') != NULL)
		{
			add_link(line, data);
			ft_strdel(&line);
			break ;
		}
		if (!insert_room(&data->hash_table,
				create_room(&line, room_type, data),
				&data->id_counter))
			exit(free_line_exit(&line, data, MALLOC_ERROR));
		data->rooms_number++;
		room_type = DEFAULT;
		ft_strdel(&line);
	}
}
