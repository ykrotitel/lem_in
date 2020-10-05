/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_best_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:54:50 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/30 18:10:59 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_room_to_path(t_path **path,
								int room_id,
								const int *dir_id,
								int *length)
{
	t_path *path_iter;

	if ((*path) == NULL)
	{
		if (!((*path) = malloc(sizeof(t_path))))
			exit(MALLOC_ERROR);
		(*path)->id = dir_id[room_id];
		(*path)->next = NULL;
		(*length)++;
		return ;
	}
	path_iter = (*path);
	while (path_iter->next)
		path_iter = path_iter->next;
	if (path_iter->id != dir_id[room_id])
	{
		if (!(path_iter->next = malloc(sizeof(t_path))))
			exit(MALLOC_ERROR);
		path_iter->next->id = dir_id[room_id];
		path_iter->next->next = NULL;
		(*length)++;
	}
}

static void		pathfinding(int v,
							t_dinic_data *data,
							t_paths **paths,
							const int *dir_id)
{
	int				to;
	static int		path_length = 0;
	static t_path	*path = NULL;

	if (v == data->end)
	{
		add_room_to_path(&path, v, dir_id, &path_length);
		add_path(paths, &path, path_length);
		path_length = 0;
		return ;
	}
	to = 0;
	while (to < data->n)
	{
		if (data->flow_matrix[v][to] == 1)
		{
			add_room_to_path(&path, v, dir_id, &path_length);
			pathfinding(to, data, paths, dir_id);
			if (v != data->start)
				return ;
		}
		to++;
	}
}

void			find_best_path(t_paths **best_paths,
								t_dinic_data *data,
								int ants_num,
								const int *dir_id)
{
	t_paths	*current_paths;
	int		output_lines;

	current_paths = NULL;
	pathfinding(data->start, data, &current_paths, dir_id);
	output_lines = count_ants_on_each_path(&current_paths, ants_num);
	current_paths->output_lines = output_lines;
	if (*best_paths == NULL)
		*best_paths = current_paths;
	else if (output_lines < (*best_paths)->output_lines)
	{
		free_paths(best_paths);
		*best_paths = current_paths;
	}
	else
		free_paths(&current_paths);
}
