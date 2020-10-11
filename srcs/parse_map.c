/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:58:16 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/04 20:17:11 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		fill_rooms_by_id(char ***rooms,
						t_node *(*hash_table)[HASH_TABLE_SIZE],
						int n)
{
	int				i;
	int				j;
	t_node			*node_iter;

	if (!(*rooms = malloc(sizeof(char*) * n)))
		return (0);
	i = 0;
	j = 0;
	while (i < HASH_TABLE_SIZE)
	{
		node_iter = (*hash_table)[i];
		while (node_iter != NULL)
		{
			if (!((*rooms)[j] = ft_strdup(node_iter->room->name)))
				return (0);
			node_iter->room->id = j++;
			node_iter = node_iter->next;
		}
		i++;
	}
	return (1);
}

static int		fill_direction_id(int **direction_id,
						t_node *(*hash_table)[HASH_TABLE_SIZE],
						int n)
{
	int				i;
	t_node			*node_iter;

	if (!(*direction_id = malloc(sizeof(int) * n)))
		return (0);
	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		node_iter = (*hash_table)[i];
		while (node_iter != NULL)
		{
			if (node_iter->room->type != START)
				(*direction_id)[node_iter->room->input_id] =
						node_iter->room->id;
			if (node_iter->room->type != END)
				(*direction_id)[node_iter->room->output_id] =
						node_iter->room->id;
			node_iter = node_iter->next;
		}
		i++;
	}
	return (1);
}

void			parse_map(t_data *data)
{
	data->ants_num = parse_ants_number();
	parse_rooms(data);
	if (!fill_rooms_by_id(&data->rooms_by_id,
			&data->hash_table, data->rooms_number))
		exit(free_data_exit(data, MALLOC_ERROR));
	if (!fill_direction_id(&data->direction_id,
			&data->hash_table, data->id_counter))
		exit(free_data_exit(data, MALLOC_ERROR));
	if (data->start == -1 || data->end == -1)
		exit(free_data_exit(data, INVALID_ROOMS));
	parse_links(data);
	if (!data->edges)
		exit(free_data_exit(data, INVALID_LINKS));
	ft_putchar('\n');
}
