/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:53:20 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/01 19:15:57 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_algo_params(t_dinic_data *dinic_data, t_data *data)
{
	dinic_data->start = data->start;
	dinic_data->end = data->end;
	dinic_data->n = data->id_counter;
	if (!(dinic_data->queue = malloc(sizeof(int) * dinic_data->n)))
		exit(free_data_exit(data, MALLOC_ERROR));
	if (!(dinic_data->ptr = malloc(sizeof(int) * dinic_data->n)))
	{
		free(dinic_data->queue);
		exit(free_data_exit(data, MALLOC_ERROR));
	}
	if (!(dinic_data->distance = malloc(sizeof(int) * dinic_data->n)))
	{
		free(dinic_data->ptr);
		free(dinic_data->queue);
		exit(free_data_exit(data, MALLOC_ERROR));
	}
	if (!(init_matrix(&dinic_data->flow_matrix, dinic_data->n)))
	{
		free(dinic_data->ptr);
		free(dinic_data->queue);
		free(dinic_data->distance);
		exit(free_data_exit(data, MALLOC_ERROR));
	}
}

static int	bfs(t_dinic_data *data, int **capacity_matrix)
{
	int qh;
	int qt;
	int v;
	int to;

	qh = 0;
	qt = 0;
	data->queue[qt++] = data->start;
	ft_memset(data->distance, -1, sizeof(int) * data->n);
	data->distance[data->start] = 0;
	while (qh < qt && data->distance[data->end] == -1)
	{
		v = data->queue[qh++];
		to = -1;
		while (++to < data->n)
		{
			if (data->distance[to] == -1
				&& (data->flow_matrix[v][to] < capacity_matrix[v][to]))
			{
				data->queue[qt++] = to;
				data->distance[to] = data->distance[v] + 1;
			}
		}
	}
	return (data->distance[data->end] != -1);
}

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	dfs(int v, int flow, t_dinic_data *data, int **capacity_matrix)
{
	int pushed;
	int to;

	if (!flow || v == data->end)
		return ((!flow) ? 0 : flow);
	while ((to = data->ptr[v]) < data->n)
	{
		if (data->distance[to] != data->distance[v] + 1)
		{
			++data->ptr[v];
			continue ;
		}
		pushed = dfs(to,
				min(flow, capacity_matrix[v][to]
				- data->flow_matrix[v][to]), data, capacity_matrix);
		if (pushed)
		{
			data->flow_matrix[v][to] += pushed;
			data->flow_matrix[to][v] -= pushed;
			return (pushed);
		}
		++data->ptr[v];
	}
	return (0);
}

t_paths		*dinic(t_data *data)
{
	t_paths			*best_paths;
	t_dinic_data	dinic_data;

	init_algo_params(&dinic_data, data);
	best_paths = NULL;
	while (bfs(&dinic_data, data->adjacency_matrix))
	{
		ft_bzero(dinic_data.ptr, sizeof(int) * data->id_counter);
		while ((dfs(dinic_data.start,
						INF,
						&dinic_data,
						data->adjacency_matrix)))
			find_best_path(&best_paths,
						&dinic_data,
						data->ants_num,
						data->direction_id);
	}
	free(dinic_data.queue);
	free(dinic_data.ptr);
	free(dinic_data.distance);
	free_matrix(&dinic_data.flow_matrix, data->id_counter);
	return (best_paths);
}
