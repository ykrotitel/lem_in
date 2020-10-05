/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:56:33 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/29 17:54:08 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room_data	*return_room(char *room_name, t_node *hash_table[HASH_TABLE_SIZE])
{
	t_node	*node;
	int		hash_value;

	hash_value = hasher(room_name);
	if (hash_table[hash_value] == NULL)
		return (NULL);
	node = hash_table[hash_value];
	while (node)
	{
		if (!ft_strcmp(node->room->name, room_name))
			return (node->room);
		node = node->next;
	}
	return (NULL);
}
