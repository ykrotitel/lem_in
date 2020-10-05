/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:23:57 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/01 19:48:39 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		init_node(t_node **node, t_room_data *room_data)
{
	if (!(*node = malloc(sizeof(t_node))))
		return (0);
	(*node)->room = room_data;
	(*node)->next = NULL;
	return (1);
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
	t_node	*node;
	t_node	*node_iter;
	int		hash_value;

	set_room_id(room_data, id_counter);
	if (!init_node(&node, room_data))
		return (0);
	hash_value = hasher(room_data->name);
	if ((*hash_table)[hash_value] == NULL)
		(*hash_table)[hash_value] = node;
	else
	{
		node_iter = (*hash_table)[hash_value];
		if (!(ft_strcmp(node_iter->room->name, node->room->name)))
			return (0);
		while (node_iter->next)
		{
			if (!(ft_strcmp(node_iter->room->name, node->room->name)))
				return (0);
			node_iter = node_iter->next;
		}
		node_iter->next = node;
	}
	return (1);
}
