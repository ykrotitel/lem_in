/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:28:33 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/24 18:28:30 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		init_matrix(int ***adjacency_matrix, int size)
{
	int i;

	i = -1;
	if ((*adjacency_matrix = malloc(sizeof(int*) * size)) == NULL)
		return (0);
	while (++i < size)
	{
		if (((*adjacency_matrix)[i] = malloc(sizeof(int) * size)) == NULL)
			return (0);
		ft_bzero((*adjacency_matrix)[i], sizeof(int) * size);
	}
	return (1);
}

int		fill_adjacency_matrix(t_room_data *room1,
							t_room_data *room2,
							int ***adjacency_matrix,
							int size)
{
	if (*adjacency_matrix == NULL)
		if (!init_matrix(adjacency_matrix, size))
			return (0);
	if (room1->type != END && room2->type != START)
		(*adjacency_matrix)[room1->output_id][room2->input_id] = 1;
	if (room2->type != END && room1->type != START)
		(*adjacency_matrix)[room2->output_id][room1->input_id] = 1;
	if (room1->type != START && room1->type != END)
		(*adjacency_matrix)[room1->input_id][room1->output_id] = 1;
	if (room2->type != START && room2->type != END)
		(*adjacency_matrix)[room2->input_id][room2->output_id] = 1;
	return (1);
}
