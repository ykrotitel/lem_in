/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:23:57 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 20:56:28 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_node	*init_node(t_room_data *room_data)
{
	t_node *node;

	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	(node)->room = room_data;
	(node)->next = NULL;
	return (node);
}

static void		set_room_id(t_room_data *room_data, int *id_counter)
{
	if (room_data->type != START)
		room_data->input_id = (*id_counter)++;
	if (room_data->type != END)
		room_data->output_id = (*id_counter)++;
}

int				insert_room(t_node *(*hash_table)[HASH_TABLE_SIZE],
						t_room_data *room_data,
						int *id_counter)
{
	t_node	*node_iter;
	int		hash_value;

	set_room_id(room_data, id_counter);
	hash_value = hasher(room_data->name);
	if ((*hash_table)[hash_value] == NULL)
	{
		if (!((*hash_table)[hash_value] = init_node(room_data)))
			return (0);
	}
	else
	{
		node_iter = (*hash_table)[hash_value];
		if (!(ft_strcmp(node_iter->room->name, room_data->name)))
			return (0);
		while (node_iter->next)
		{
			if (!(ft_strcmp(node_iter->next->room->name, room_data->name)))
				return (0);
			node_iter = node_iter->next;
		}
		if (!(node_iter->next = init_node(room_data)))
			return (0);
	}
	return (1);
}
