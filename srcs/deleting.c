/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:54:10 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/01 17:56:44 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_hash_table(t_node *(*hash_table)[HASH_TABLE_SIZE])
{
	int		i;
	t_node	*tmp_node;
	t_node	*node;

	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		if ((*hash_table)[i] != NULL)
		{
			node = (*hash_table)[i];
			while (node)
			{
				tmp_node = node;
				node = node->next;
				ft_strdel(&tmp_node->room->name);
				free(tmp_node->room);
				tmp_node->next = NULL;
				free(tmp_node);
			}
		}
		i++;
	}
}

void		free_path(t_path **path)
{
	t_path	*tmp_id;

	while (*path != NULL)
	{
		tmp_id = *path;
		*path = (*path)->next;
		free(tmp_id);
		tmp_id = NULL;
	}
}

void		free_paths(t_paths **paths)
{
	t_paths *tmp_path;

	while ((*paths) != NULL)
	{
		tmp_path = *paths;
		(*paths) = (*paths)->next;
		free_path(&tmp_path->id_list);
		if (tmp_path->ants_by_id)
			free(tmp_path->ants_by_id);
		free(tmp_path);
		tmp_path = NULL;
	}
}

void		free_matrix(t_edge ***matrix, int size)
{
	int i;

	if (*matrix == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		if ((*matrix)[i])
			free((*matrix)[i]);
		(*matrix)[i] = NULL;
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

void		free_data(t_data *data)
{
	int i;

	if (data->direction_id)
		free(data->direction_id);
	if (data->last_edge_id)
		free(data->last_edge_id);
	if (data->rooms_by_id)
	{
		i = 0;
		while (i < data->rooms_number)
		{
			if (data->rooms_by_id[i])
				ft_strdel(&data->rooms_by_id[i]);
			i++;
		}
		free(data->rooms_by_id);
	}
	free_hash_table(&data->hash_table);
	free_paths(&data->paths);
	free_matrix(&data->edges, data->id_counter);
}
