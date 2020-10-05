/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ants_on_each_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:08:01 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/28 20:21:52 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_prev_paths(t_paths **path, t_paths **next_path, t_paths **paths)
{
	if ((*path)->prev && (*next_path)->prev)
	{
		*path = (*path)->prev;
		*next_path = (*next_path)->prev;
		return (1);
	}
	else if ((*next_path)->prev == NULL)
	{
		*path = *paths;
		*next_path = (*path)->next;
		return (1);
	}
	return (0);
}

void	new_paths_to_cmp(t_paths **path, t_paths **next_path, t_paths **paths)
{
	if ((*next_path)->next == NULL)
	{
		*next_path = *paths;
		*path = (*path)->next;
	}
	else if ((*path)->next == NULL)
	{
		*next_path = (*next_path)->next;
		*path = *paths;
	}
	else
	{
		*path = (*path)->next;
		*next_path = (*next_path)->next;
	}
}

int		compute_output_lines(t_paths **path, int *lines, int *ants, int to_add)
{
	(*ants)++;
	(*path)->ants_num += to_add;
	if (((*path)->path_len - 1) + ((*path)->ants_num - 1) > *lines)
		return (*lines = ((*path)->path_len - 1) + ((*path)->ants_num - 1));
	return (*lines);
}

void	init_paths(int *lines, t_paths **path, t_paths **next, t_paths **paths)
{
	*lines = 0;
	*path = *paths;
	*next = (*paths)->next;
}

int		count_ants_on_each_path(t_paths **paths, int ants_num)
{
	int			ants_on_path;
	t_paths		*path;
	t_paths		*next_path;
	int			lines;

	init_paths(&lines, &path, &next_path, paths);
	if ((*paths)->next == NULL)
		return (compute_output_lines(&path, &lines, &ants_on_path, ants_num));
	ants_on_path = 0;
	while (ants_on_path < ants_num)
	{
		if (path->path_len + path->ants_num
				<= next_path->path_len + next_path->ants_num)
		{
			if (check_prev_paths(&path, &next_path, paths))
				continue ;
			compute_output_lines(&path, &lines, &ants_on_path, 1);
		}
		else
		{
			compute_output_lines(&next_path, &lines, &ants_on_path, 1);
			new_paths_to_cmp(&path, &next_path, paths);
		}
	}
	return (lines);
}
