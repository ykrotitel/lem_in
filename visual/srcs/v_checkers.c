/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_checkers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:34:59 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 17:43:41 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

static void	create_room_list(t_room_list **list, t_room_data *room_data,
												char **line, t_map_data *data)
{
	if (((*list) = malloc(sizeof(t_room_list))) == NULL)
	{
		free_data(data);
		ft_strdel(line);
		exit(10);
	}
	(*list)->room_data = room_data;
	(*list)->next = NULL;
}

void		push_back_room(t_room_list **list, t_room_data *room_data,
							t_map_data *data, char **line)
{
	t_room_list *last;

	if (*list == NULL)
	{
		room_data->id = data->rooms_number;
		create_room_list(list, room_data, line, data);
		data->rooms_number++;
	}
	else
	{
		last = (*list);
		while (last->next)
			last = last->next;
		if (((last)->next = malloc(sizeof(t_room_list))) == NULL)
		{
			ft_strdel(line);
			free_data(data);
			exit(10);
		}
		room_data->id = data->rooms_number;
		(last)->next->room_data = room_data;
		data->rooms_number++;
		(last)->next->next = NULL;
	}
}

int			return_room_index(char *room_name, t_room_list *list)
{
	t_room_list *head;

	head = list;
	while (head)
	{
		if (!ft_strcmp(head->room_data->name, room_name))
			return (head->room_data->id);
		head = head->next;
	}
	return (-1);
}

int			size_of_matrix_rows(char **matrix)
{
	int counter;

	counter = 0;
	while (matrix[counter] != NULL)
	{
		if (!matrix[counter][0])
			return (INVALID_ROOMS);
		counter++;
	}
	return (counter);
}

t_room_type	check_if_comment(char **line, t_map_data *data)
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
			free_show_error(data);
		if (*line)
		{
			if ((*line)[0] == '#' && (type == START || type == END))
				return (PARSE_ERROR);
		}
	}
	return (type);
}
