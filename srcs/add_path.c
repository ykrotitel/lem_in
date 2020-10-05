/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:16:52 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/30 16:31:50 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		init_path(t_paths **paths, t_path **path, int length)
{
	t_path *new_path;

	new_path = *path;
	if (!(*paths = malloc(sizeof(t_paths))))
		exit(MALLOC_ERROR);
	(*paths)->id_list = new_path;
	(*paths)->path_len = length;
	(*paths)->ants_num = 0;
	(*paths)->ants_by_id = NULL;
	(*paths)->last_ant_id = 0;
	*path = NULL;
}

static void		push_back_path(t_paths *path_before, t_path **path, int length)
{
	t_paths *path_to_add;

	path_to_add = NULL;
	init_path(&path_to_add, path, length);
	path_to_add->next = NULL;
	path_to_add->prev = path_before;
	path_before->next = path_to_add;
}

static void		push_front_path(t_paths **head, t_path **path, int length)
{
	t_paths *path_to_add;

	path_to_add = NULL;
	init_path(&path_to_add, path, length);
	path_to_add->prev = NULL;
	path_to_add->next = *head;
	(*head)->prev = path_to_add;
	*head = path_to_add;
}

static void		insert_before_path(t_paths *path_after, t_path **path, int len)
{
	t_paths *path_to_add;

	path_to_add = NULL;
	init_path(&path_to_add, path, len);
	path_to_add->next = path_after;
	path_to_add->prev = path_after->prev;
	path_after->prev->next = path_to_add;
	path_after->prev = path_to_add;
}

void			add_path(t_paths **paths, t_path **path, int path_length)
{
	t_paths *path_iter;
	t_paths *prev_iter;

	if (*paths == NULL)
	{
		init_path(paths, path, path_length);
		(*paths)->next = NULL;
		(*paths)->prev = NULL;
		return ;
	}
	path_iter = (*paths);
	while (path_iter && path_length > path_iter->path_len)
	{
		prev_iter = path_iter;
		path_iter = path_iter->next;
	}
	if (path_iter == NULL)
		push_back_path(prev_iter, path, path_length);
	else if (path_iter == (*paths))
		push_front_path(paths, path, path_length);
	else
		insert_before_path(path_iter, path, path_length);
}
