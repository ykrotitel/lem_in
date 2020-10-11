/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:53:20 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/05 16:51:09 by lmittie          ###   ########.fr       */
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
}

static int	bfs(t_dinic_data *data, t_edge **edges, const int *last_id)
{
	int qh;
	int qt;
	int v;
	int id;

	qh = 0;
	qt = 0;
	data->queue[qt++] = data->start;
	ft_memset(data->distance, -1, sizeof(int) * data->n);
	data->distance[data->start] = 0;
	while (qh < qt && data->distance[data->end] == -1)
	{
		v = data->queue[qh++];
		id = -1;
		while (++id < last_id[v])
		{
			if (data->distance[edges[v][id].b] == -1
			&& (edges[v][id].flow < edges[v][id].cap))
			{
				data->queue[qt++] = edges[v][id].b;
				data->distance[edges[v][id].b] = data->distance[v] + 1;
			}
		}
	}
	return (data->distance[data->end] != -1);
}

static int	push_flow(t_edge *edge, t_edge ***edges, int pushed)
{
	int id;

	edge->flow += pushed;
	id = 0;
	while ((*edges)[edge->b][id].b != edge->a)
		id++;
	(*edges)[edge->b][id].flow -= pushed;
	return (pushed);
}

static int	dfs(int v, int flow, t_dinic_data *data, t_data *alg_data)
{
	int pushed;
	int to;

	if (!flow || v == data->end)
		return ((!flow) ? 0 : flow);
	while ((to = data->ptr[v]) < alg_data->last_edge_id[v])
	{
		if (data->distance[alg_data->edges[v][to].b] != data->distance[v] + 1)
		{
			++data->ptr[v];
			continue ;
		}
		pushed = dfs(alg_data->edges[v][to].b,
				ft_min(flow, alg_data->edges[v][to].cap
				- alg_data->edges[v][to].flow), data, alg_data);
		if (pushed)
		{
			return (push_flow(&alg_data->edges[v][to],
							&alg_data->edges,
							pushed));
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
	while (bfs(&dinic_data, data->edges, data->last_edge_id))
	{
		ft_bzero(dinic_data.ptr, sizeof(int) * data->id_counter);
		while ((dfs(dinic_data.start,
						INF,
						&dinic_data,
						data)))
			find_best_path(&best_paths,
						data);
	}
	free(dinic_data.queue);
	free(dinic_data.ptr);
	free(dinic_data.distance);
	return (best_paths);
}
