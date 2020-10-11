/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:28:33 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 17:41:09 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		init_matrix(t_edge ***edge_matrix, int **last_edge_id, int size)
{
	int i;

	i = -1;
	if ((*edge_matrix = malloc(sizeof(t_edge*) * size)) == NULL)
		return (0);
	while (++i < size)
	{
		if (((*edge_matrix)[i] = malloc(sizeof(t_edge) * size)) == NULL)
			return (0);
		ft_bzero((*edge_matrix)[i], sizeof(t_edge) * size);
	}
	if (!(*last_edge_id = malloc(sizeof(int) * size)))
		exit(MALLOC_ERROR);
	ft_bzero(*last_edge_id, sizeof(int) * size);
	return (1);
}

static t_edge	init_edge(int a, int b, int cap, int flow)
{
	t_edge edge;

	edge.a = a;
	edge.b = b;
	edge.cap = cap;
	edge.flow = flow;
	return (edge);
}

void			add_edge(int v1, int v2, int **last_id, t_edge ***edge_matrix)
{
	t_edge	edge;
	int		i;

	i = 0;
	while (i < (*last_id)[v1])
	{
		if ((*edge_matrix)[v1][i].b == v2)
			return ;
		i++;
	}
	edge = init_edge(v1, v2, 1, 0);
	(*edge_matrix)[v1][(*last_id)[v1]++] = edge;
	edge = init_edge(v2, v1, 0, 0);
	(*edge_matrix)[v2][(*last_id)[v2]++] = edge;
}

int				fill_edge_matrix(t_room_data *room1,
						t_room_data *room2,
						t_data *data,
						int size)
{
	if (data->edges == NULL)
		init_matrix(&data->edges, &data->last_edge_id, size);
	if (room1->type != START && room1->type != END
			&& !data->last_edge_id[room1->input_id])
		add_edge(room1->input_id, room1->output_id,
				&data->last_edge_id, &data->edges);
	if (room2->type != START && room2->type != END
			&& !data->last_edge_id[room2->input_id])
		add_edge(room2->input_id, room2->output_id,
				&data->last_edge_id, &data->edges);
	if (room1->type != END && room2->type != START)
		add_edge(room1->output_id, room2->input_id,
				&data->last_edge_id, &data->edges);
	if (room2->type != END && room1->type != START)
		add_edge(room2->output_id, room1->input_id,
				&data->last_edge_id, &data->edges);
	return (1);
}
